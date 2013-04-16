#include "StdAfx.h"
#include "pl_ctrl.h"
#include "pl_type.h"
#include "pl_factory.h"
#include "pl_factory_wnd.h"
#include "pl_json_parser.h"
#include "pl_wnd.h"
#include <cmath>
using namespace std;

CPlCtrl::CPlCtrl(void)
{
	m_hParent	= NULL;
	m_pUser		= NULL;
	memset(&m_layoutInfo, 0, sizeof(PL_LayoutInfo));
}

CPlCtrl::~CPlCtrl(void)
{
	m_layoutInfo.bInit = FALSE;
	DestroyWindows();
}

BOOL CPlCtrl::InitDisPlay(HWND hParent, char* pJsUrl)
{
	if(m_hParent != NULL)
		return TRUE;

	if (!PlJsonParser::Instance()->ParserLayout(pJsUrl, m_layoutInfo))
		return FALSE;

	m_hParent = hParent;
	CreateWindows(m_layoutInfo);
	m_layoutInfo.bInit = TRUE;
	SetLayout(m_layoutInfo);
	
	return TRUE;
}

int CPlCtrl::CalcWndNum(const PL_LayoutInfo &layoutInfo)
{
	int nWndNum = 1;
	if(3 == layoutInfo.nLayout)
	{
		nWndNum = (layoutInfo.nWindows + 1) * (layoutInfo.nWindows + 1);
	}
	return nWndNum;
}

BOOL CPlCtrl::SetLayout(char *pJsUrl)
{
	PL_LayoutInfo layoutInfo;
	if (!PlJsonParser::Instance()->ParserLayout2(pJsUrl, layoutInfo))
		return FALSE;
	
	CreateWindows(layoutInfo);
	if(SetLayout(layoutInfo))
	{
		m_layoutInfo.nLayout = layoutInfo.nLayout;
		m_layoutInfo.nWindows = layoutInfo.nWindows;
		m_layoutInfo.nMax = layoutInfo.nMax;
		return TRUE;
	}
	return FALSE;
}

BOOL CPlCtrl::SetLayout(const PL_LayoutInfo &layoutInfo)
{
	int nWindowNum = CalcWndNum(layoutInfo);
	CRect rect;
	GetClientRect(m_hParent, &rect);
	switch(layoutInfo.nLayout)
	{
	case 1:
		for(int i=0; i<nWindowNum; ++i)
		{
			((CWnd*)m_playWndMap[i])->MoveWindow(rect.left+i*rect.Width() / nWindowNum,
										rect.top,
										rect.Width() / nWindowNum,					
										rect.Height());
		}
		break;
	case 2:
		for(int i=0; i<nWindowNum; i++)
		{
			((CWnd*)m_playWndMap[i])->MoveWindow(rect.left,		
										rect.top+i*rect.Height() / nWindowNum,
										rect.Width(),	
										rect.Height() / nWindowNum);
		}
		break;
	case 3:
		GridWindow(layoutInfo.nWindows+1);
		break;
	}
	m_playWndMap[0]->SetNowShowWindow(nWindowNum);
	return TRUE;
}

void CPlCtrl::GridWindow(int nWndNum)
{
	CRect rect;
	GetClientRect(m_hParent,&rect);
	for(int i=0; i<nWndNum; ++i)
	{
		for(int j=0; j<nWndNum; ++j)
		{
			((CWnd*)m_playWndMap[i*nWndNum+j])->MoveWindow(rect.left + j*rect.Width() / nWndNum,
											rect.top + i*rect.Height() / nWndNum,
											rect.Width() / nWndNum,
											rect.Height() / nWndNum);
			((CWnd*)m_playWndMap[i*nWndNum+j])->Invalidate(TRUE);
		}
	}
}

HWND CPlCtrl::GetFocusWnd()
{
	return m_playWndMap[0]->GetFocusWnd(); 
}

BOOL CPlCtrl::RegisterCallBack(NpnNotifyFunc funcAddr, void *pUser)
{
	m_pUser = pUser;
	return PlManager::Instance()->RegisterCallBack(funcAddr);
}

BOOL CPlCtrl::StopAll()
{
	PlayWndMap::iterator it = m_playWndMap.begin();
	for(; it!=m_playWndMap.end(); ++it)
		PlManager::Instance()->Stop(it->second->m_hWnd);

	return TRUE;
}

BOOL CPlCtrl::VodStreamJump(char *js_time)
{
	if(m_layoutInfo.nMod == STREAME_REALTIME) 
		return FALSE;

	PL_PlayInfo playInfo = {0};
	PlJsonParser::Instance()->ParserDrag(js_time, playInfo);

	return PlManager::Instance()->VodStreamJump(GetFocusWnd(), playInfo);
}

BOOL CPlCtrl::GetPath(char *psz_dest,UINT nType)
{
	if(nType == IMAGEPATH)
	{
		strncpy(psz_dest, m_layoutInfo.imgPath, PATH_LENGTH);
	}
	else if(nType == VIDEOPATH)
	{
		strncpy(psz_dest, m_layoutInfo.mediaPath, PATH_LENGTH);
	}

	return TRUE;
}

BOOL CPlCtrl::SetLayout()
{
	if(!m_layoutInfo.nLayout) 
		return FALSE;

	return SetLayout(m_layoutInfo);
}

BOOL CPlCtrl::Play(char *js_mrl)
{
	BOOL bRet = FALSE;
	HWND hWnd = NULL;
	PL_PlayInfo playInfo = {0};
	PlJsonParser::Instance()->ParserPlay(js_mrl, playInfo);
	if(0 == playInfo.nId)
	{
		hWnd = GetNextPlayWnd();
	}
	else
	{
		int nSize = m_playWndMap.size();
		if(playInfo.nId > nSize || playInfo.nId < 0) 
			return FALSE;

		hWnd = m_playWndMap[playInfo.nId]->m_hWnd;
	}

	if(!PlManager::Instance()->SetUserData(hWnd, m_pUser))
		return FALSE;

	::SendMessage(hWnd, WM_OWN_SETFOCUS, 0, 0);
	bRet = PlManager::Instance()->Play(hWnd, playInfo);

	return bRet;
}

HWND CPlCtrl::GetNextPlayWnd()
{
	PlayWndMap::iterator it = m_playWndMap.begin();
	for(; it!=m_playWndMap.end(); ++it)
	{
		if(!PlManager::Instance()->IsPlaying(it->second->m_hWnd))
			return it->second->m_hWnd;
	}
	return GetFocusWnd();
}

BOOL CPlCtrl::GetWndParm(char *pRet, int nType)
{
	BOOL bRet = FALSE;
	char wndinfo[2048] = {0};
	if(nType == FOCUS_WINDOW)
	{
		int nId = GetWindowLong(GetFocusWnd(), GWL_ID);
		bRet = PlManager::Instance()->GetWndPlayParm(m_playWndMap[nId]->m_hWnd, wndinfo);
	}
	else if(nType == ALL_WINDOW)
	{
		char ppWndInfo[64][64];
		int nWndNum = m_playWndMap.size();
		int nRealNum = 0;
		for (int i=0; i<nWndNum; ++i)
		{
			memset(ppWndInfo[i], 0, 64);
			bRet = PlManager::Instance()->GetWndPlayParm(m_playWndMap[i]->m_hWnd, ppWndInfo[i]);
			if (bRet)
			{
				++nRealNum;
			}
		}
		PlJsonParser::Instance()->MakeAllWndParam((char **)ppWndInfo, nRealNum, wndinfo);
	}
	strcat(pRet, wndinfo);

	return bRet;
}

void CPlCtrl::SleepPlayer(bool bSleep)
{
	PlayWndMap::iterator it = m_playWndMap.begin();
	for(; it!=m_playWndMap.end(); ++it)
		PlManager::Instance()->SleepPlayer(it->second->m_hWnd, bSleep);
}

BOOL CPlCtrl::CreateWindows(const PL_LayoutInfo &layoutInfo)
{
	int nOldWnds = m_playWndMap.size();//CalcWndNum(m_layoutInfo);
	int nWindows = CalcWndNum(layoutInfo);
	//if (!m_layoutInfo.bInit)
	//	nOldWnds = 0;
	if (nOldWnds < nWindows)
	{
		switch(m_layoutInfo.nMod)
		{
		case STREAME_REALTIME:		//real
			for(int i=nOldWnds; i<nWindows; ++i)
			{
				CPlWnd *r_tmp = dynamic_cast<CPlWnd *>(CPlFactoryWnd::Instance()->GetWindow("r_play", m_hParent, i));
				::ShowWindow(((CWnd*)r_tmp)->m_hWnd, SW_SHOW);
				r_tmp->SetFullModel(m_layoutInfo.nMax);
				PlManager::Instance()->SetUserData(r_tmp->m_hWnd, m_pUser);
				m_playWndMap[i] = r_tmp;
			}
			break;
		case STREAME_FILE:				//vod
			for(int i=nOldWnds; i<nWindows; ++i)
			{
				CPlWnd *v_tmp = dynamic_cast<CPlWnd *>(CPlFactoryWnd::Instance()->GetWindow("v_play", m_hParent, i));
				::ShowWindow(((CWnd*)v_tmp)->m_hWnd, SW_SHOW);
				v_tmp->SetFullModel(m_layoutInfo.nMax);
				PlManager::Instance()->SetUserData(v_tmp->m_hWnd, m_pUser);
				m_playWndMap[i] = v_tmp;
			}
			break;
		default:
			return FALSE;
		}
	}

	return TRUE;
}

void CPlCtrl::DestroyWindows()
{
	PlayWndMap::iterator it = m_playWndMap.begin();
	for(; it!=m_playWndMap.end(); ++it)
	{
		CPlFactoryWnd::Instance()->DelWindow(it->first);
	}
	m_playWndMap.clear();
}