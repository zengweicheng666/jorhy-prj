#include "JosMux.h"
extern "C"
{
#include "x_inet.h"
}

CJosMux::CJosMux()
{

}

CJosMux::~CJosMux()
{

}

int CJosMux::Init()
{
	m_nFrameSeq = 0;
	return J_OK;
}

void CJosMux::Deinit()
{

}

int CJosMux::Convert(const char *pInputData, J_StreamHeader &streamHeader, char *pOutputData, int &nOutLen, void *pExtdata)
{
	nOutLen = 0;
	J_DataHead *pDataHead = (J_DataHead *)pOutputData;
	memcpy(pDataHead->start_code, "JOAV", 4);
	pDataHead->data_len = htons(streamHeader.dataLen);
	pDataHead->frame_type = htons(streamHeader.frameType);
	pDataHead->time_stamp = htonll(streamHeader.timeStamp);
	pDataHead->frame_seq = htonl(m_nFrameSeq++);
	
	memcpy(pOutputData + sizeof(J_DataHead), pInputData, streamHeader.dataLen);
	nOutLen = streamHeader.dataLen + sizeof(J_DataHead);
	
	//J_OS::LOGINFO("data_len = %d", streamHeader.dataLen);

	return J_OK;
}
