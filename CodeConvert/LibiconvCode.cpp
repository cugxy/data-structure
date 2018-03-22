#include "LibiconvCode.h"

#ifndef WIN32

LibiconvCode::LibiconvCode(const char * pszFromCharset, const char * pszToCharset)
{
	m_cd = iconv_open(pszToCharset, pszFromCharset);
}

LibiconvCode::~LibiconvCode()
{
	iconv_close(m_cd);
}

int LibiconvCode::Convert(const char * pszInBuf, int nInLen, char * pszOutBuf, int nOutLen)
{
	const char** pIn = &pszInBuf;
	char** pOut = &pszOutBuf;
	return iconv(m_cd, pIn, (size_t*)&nInLen, pOut, (size_t*)&nOutLen);
}
#endif
