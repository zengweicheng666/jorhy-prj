#include "TsMux.h"
#include "x_crc32.h"

#define PES_MAX_LEN	60000

JO_IMPLEMENT_INTERFACE(Mux, "ts", CTsMux::Maker)

CTsMux::CTsMux()
{
	m_nPATCounter = 0;
	m_nPMTCounter = 0;
	m_nPCRCounter = 0;
	m_nVideoCounter = 0;
	m_nAudioCounter = 0;
	m_nFrameNum = 0;

	m_videoStamp = 0;
	m_audioStamp = 0;
}

CTsMux::~CTsMux()
{

}

j_result_t CTsMux::Init()
{
	return J_OK;
}

void CTsMux::Deinit()
{

}

j_result_t CTsMux::Convert(const char *pInputData, J_StreamHeader &streamHeader, char *pOutputData, int &nOutLen, void *pExtdata)
{
	int i_offset_out = 0;
	int i_offset_in = 0;
	int i_data_len = streamHeader.dataLen;		//总数据长度
	bool b_isAudio = (streamHeader.frameType == jo_audio_frame);

	nOutLen = 0;
	char c_ts_data[TS_DATA_LEN];
	if (!(m_nFrameNum % PAT_INTERVAL))
	{
		MakePAT(c_ts_data);
		memcpy(pOutputData + i_offset_out, c_ts_data, TS_DATA_LEN);
		i_offset_out += TS_DATA_LEN;
		++m_nPATCounter;
		MakePMT(c_ts_data);
		memcpy(pOutputData + i_offset_out, c_ts_data, TS_DATA_LEN);
		i_offset_out += TS_DATA_LEN;
		++m_nPMTCounter;
	}
	if (!(m_nFrameNum % PCR_INTERVAL))
	{
		MakePCR(c_ts_data, streamHeader.timeStamp);
		memcpy(pOutputData + i_offset_out, c_ts_data, TS_DATA_LEN);
		i_offset_out += TS_DATA_LEN;
		++m_nPCRCounter;
	}
	++m_nFrameNum;

	while (i_data_len > 0)
	{
		int i_pes_data_len = 0;
		if (i_data_len > PES_MAX_LEN)
			i_pes_data_len = PES_MAX_LEN;
		else
			i_pes_data_len = i_data_len;
		i_data_len -= i_pes_data_len;

		char c_pes_head[20];
		int nPESHeadLen = 0;
		bool b_start = true;
		nPESHeadLen = MakePESHead(c_pes_head, i_pes_data_len, streamHeader.timeStamp, b_isAudio);
		MakePacket(c_ts_data, c_pes_head, nPESHeadLen, b_isAudio, b_start);
		memcpy(pOutputData + i_offset_out, c_ts_data, TS_DATA_LEN);
		i_offset_out += TS_DATA_LEN;
		b_start = false;
		if (b_isAudio)
			++m_nAudioCounter;
		else
			++m_nVideoCounter;

		while (i_pes_data_len > 0)
		{
			if (i_pes_data_len >= TS_MAX_PAYLOAD_LEN)
			{
				MakePacket(c_ts_data, pInputData + i_offset_in, TS_MAX_PAYLOAD_LEN, b_isAudio, b_start);
				memcpy(pOutputData + i_offset_out, c_ts_data, TS_DATA_LEN);
				i_offset_out += TS_DATA_LEN;
				i_offset_in += TS_MAX_PAYLOAD_LEN;
				i_pes_data_len -= TS_MAX_PAYLOAD_LEN;
			}
			else if (i_pes_data_len == TS_NEED_CUT_LEN)
			{
				MakePacket(c_ts_data, pInputData + i_offset_in, TS_PAYLOAD_CUT_LEN, b_isAudio, b_start);
				memcpy(pOutputData + i_offset_out, c_ts_data, TS_DATA_LEN);
				i_offset_out += TS_DATA_LEN;
				i_offset_in += TS_PAYLOAD_CUT_LEN;
				i_pes_data_len -= TS_PAYLOAD_CUT_LEN;
			}
			else
			{
				MakePacket(c_ts_data, pInputData + i_offset_in, i_pes_data_len, b_isAudio, b_start);
				memcpy(pOutputData + i_offset_out, c_ts_data, TS_DATA_LEN);
				i_offset_out += TS_DATA_LEN;
				i_offset_in += i_pes_data_len;
				i_pes_data_len = 0;
			}

			if (b_isAudio)
				++m_nAudioCounter;
			else
				++m_nVideoCounter;
		}
	}
	nOutLen = i_offset_out;

	return J_OK;
}

int CTsMux::MakePESHead(char *pHead, int nDataLen, j_uint64_t timeStamp, j_boolean_t isAudio)
{
		memset(pHead, 0, 20);
		int nLen = nDataLen + 14;
		j_uint64_t uPts = timeStamp * 90;//CTime::Instance()->GetLocalTime(0) * 90;
		//uint64_t uPts = CTime::Instance()->GetLocalTime(0) * 90;
		//uint64_t uPts = 0;
		///封装PES头
		pHead[0] = 0x00; pHead[1] = 0x00; pHead[2] = 0x01; pHead[3] = 0xE0;//Packetized Elementary Stream Header
		if (isAudio)
		{
			pHead[3] = 0xC0;
			//uPts = m_audioStamp;
			//m_audioStamp += 5760;
			//uPts -= 90;
		}
		//else
		//{
		//	uPts = m_videoStamp;
		//	m_videoStamp += 3600;
		//}

		pHead[4] = (nLen >> 8) & 0xFF;
		pHead[5] = nLen & 0xFF;

		pHead[6] = 0x8C; pHead[7] = 0x80;


		pHead[8] = 0x0B;
		pHead[9] = (0x01 << 5) | (((uPts >> 30) & 0x07) << 1) | 0x01;
		pHead[10] =  ((uPts >> 22) & 0xFF);
		pHead[11] =  (((uPts >> 15) & 0x7F) << 1) | 0x01;
		pHead[12] = ((uPts >> 7) & 0xFF);;
		pHead[13] = ((uPts & 0x7F) << 1) | 0x01;;
		pHead[14] = 0xFF; pHead[15] = 0xFF; pHead[16] = 0xFF;
		pHead[17] = 0xFF; pHead[18] = 0xFF; pHead[19] = 0xF8;

		return 20;
}

int CTsMux::MakePAT(char *pHead)
{
	memset(pHead, 0, 188);
	pHead[0] = 0x47;		//sync_byte
	pHead[1] = (0x00 << 7) | (0x01 << 6) | (0x00 << 5) | 0x00;
	pHead[2] = 0x00;
	pHead[3] = (0x00 << 6) | (0x01 << 4) | (m_nPATCounter % 16);

	pHead[4] = 0x00;
	pHead[5] = 0x00;		//table_id

	pHead[6] = 0xB0;
	pHead[7] = 0x0D;		//section_length

	pHead[8] = 0x00;		//transport_stream_id
	pHead[9] = 0x01;

	pHead[10] = (0x00 << 6) | 0x01;
	pHead[11] = 0x00;		//section_number
	pHead[12] = 0x00; 	//last_section_number

	pHead[13] = 0x00;
	pHead[14] = 0x01;		//program_number
	pHead[15] = 0x01;
	pHead[16] = 0x00;		//PMT

	unsigned long i_crc = get_crc32(pHead + 5, 12);
	pHead[17] = (i_crc >> 24) & 0xff;		//CRC_32
	pHead[18] = (i_crc >> 16) & 0xff;
	pHead[19] = (i_crc >> 8) & 0xff;
	pHead[20] = i_crc & 0xff;

	for (int n=0, i=21; n<167; n++, i++)
	{
		pHead[i] = 0xFF;
	}

	return J_OK;
}

int CTsMux::MakePMT(char *pHead)
{
	memset(pHead, 0, 188);
	pHead[0] = 0x47;		//sync_byte
	pHead[1] = (0x00 << 7) | (0x01 << 6) | (0x00 << 5) | 0x01;
	pHead[2] = 0x00;
	pHead[3] = (0x00 << 6) | (0x01 << 4) | (m_nPMTCounter % 16);

	pHead[4] = 0x00;
	pHead[5] = 0x02;		//table_id

	pHead[6] = (0x01 << 7) | 0x00;
	pHead[7] = 0x17;		//section_length

	pHead[8] = 0x00;
	pHead[9] = 0x01;		//program_number

	pHead[10] = (0x00 << 2) | (0x00 << 5) | 0x01;

	pHead[11] = 0x00;		//section_number
	pHead[12] = 0x00;		//last_section_number

	pHead[13] = 0x10;
	pHead[14] = 0x01;		//PCR_PID

	pHead[15] = 0x00;
	pHead[16] = 0x00;		//program_info_length

	pHead[17] = 0x1B;		//stream_type
	pHead[18] = 0x10;		//elementary_PID
	pHead[19] = 0x11;
	pHead[20] = 0x00;		//es_info_length
	pHead[21] = 0x00;

	pHead[22] = 0x0F;		//stream_type
	pHead[23] = 0x11;		//elementary_PID
	pHead[24] = 0x00;
	pHead[25] = 0x00;		//es_info_length
	pHead[26] = 0x00;

	unsigned long i_crc = get_crc32(pHead + 5, 22);
	pHead[27] = (i_crc >> 24) & 0xff;		//CRC_32
	pHead[28] = (i_crc >> 16) & 0xff;
	pHead[29] = (i_crc >> 8) & 0xff;
	pHead[30] = i_crc & 0xff;

	for (int n=0, i=31; n<157; n++, i++)
	{
		pHead[i] = 0xFF;
	}

	return J_OK;
}

int CTsMux::MakePCR(char *pHead, j_uint64_t timeStamp)
{
	memset(pHead, 0, 188);
	pHead[0] = 0x47;		//sync_byte
	pHead[1] = (0x00 << 7) | (0x00 << 6) | (0x00 << 5) | 0x10;
	pHead[2] = 0x01;
	pHead[3] = (0x00 << 6) | (0x02 << 4) | 0/*(m_nPCRCounter % 16)*/;

	pHead[4] = 0xB7;		//adaptation_fileld_length
	pHead[5] = 0x10;

	j_uint64_t uPcr = timeStamp * 90;
	//uint64_t uPcr = CTime::Instance()->GetLocalTime(0) * 90;
	//uint64_t uPcr = m_videoStamp;
	pHead[6] = (uPcr >> 25) & 0xFF;
	pHead[7] = (uPcr >> 17) & 0xFF;
	pHead[8] = (uPcr >> 9) & 0xFF;
	pHead[9] = (uPcr >> 1) & 0xFF;
	pHead[10] = ((uPcr & 0x01) << 7) | (0x3f << 1) | 0x00;
	pHead[11] = 0x00;

	for (int n=0, i=12; n < 176; n++, i++)
	{
		pHead[i] = 0xFF;
	}

	return J_OK;
}

int CTsMux::MakePacket(char *pHead, const char *pInputData, int nLen, bool bIsAudio, bool bIsStart)
{
	memset(pHead, 0, 188);
	pHead[0] = 0x47;		//sync_byte
	pHead[1] = (0x00 << 7) | ((bIsStart ? 0x01 : 0x00) << 6) | (0x00 << 5) | (bIsAudio ? 0x11 : 0x10);
	pHead[2] = (bIsAudio ? 0x00 : 0x11);
	if (nLen == 184)
	{
		pHead[3] = (0x00 << 6) | (0x01 << 4) | ((bIsAudio ? m_nAudioCounter : m_nVideoCounter) % 16);
		memcpy(pHead + 4, pInputData, nLen);
	}
	else
	{
		pHead[3] = (0x00 << 6) | (0x03 << 4) | ((bIsAudio ? m_nAudioCounter : m_nVideoCounter) % 16);
		int field_len = 183 - nLen;
		pHead[4] = field_len;
		pHead[5] = 0x00;
		for (int n=1, i=6; n<field_len; n++, i++)
		{
			pHead[i] = 0xFF;
		}
		memcpy(pHead + field_len + 5, pInputData, nLen);
	}

	return J_OK;
}
