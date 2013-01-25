#ifndef __DAHUASTREAM_H_
#define __DAHUASTREAM_H_
#include "DahuaParser.h"
#include "x_time.h"
#include "dhnetsdk.h"

class CDahuaStreamBase : public J_MediaStream
{};

class CDahuaStream : public J_BaseVideoStream<CDahuaStreamBase>
{
	friend class CDahuaChannel;
public:
	CDahuaStream(std::string resid, int nChannel);
	~CDahuaStream();

public:
	///J_VideoStream
	virtual int Startup();
	virtual int Shutdown();

protected:
	static void OnStreamCallBack(LONG hHandle, DWORD dwDayaType, BYTE *pBuffer, DWORD dwBufsize, DWORD dwUser)
	{
		CDahuaStream *pThis = reinterpret_cast<CDahuaStream *>(dwUser);
		if (pThis != NULL)
			pThis->OnRecv(hHandle, dwDayaType, pBuffer, dwBufsize);
	}

private:
	void OnRecv(LONG hHandle, DWORD dwDayaType, BYTE *pBuffer, DWORD dwBufsize);

private:
	bool m_bStartup;
	char *m_pRecvBuff;
	CDahuaParser m_parser;
};

#endif //~__DAHUASTREAM_H_
