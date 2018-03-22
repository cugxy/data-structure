// Author£º		xiongw
// Date£º		2018-3-22
// filename:	LibiconvCode.h

#ifndef _LIBICONVCODE_H_
#define _LIBICONVCODE_H_

#include <iconv.h>

#ifndef WIN32

class LibiconvCode
{
private:
	iconv_t m_cd;
public:
	LibiconvCode(const char* pszFromCharset, const char* pszToCharset);
	
	~LibiconvCode();

	int Convert(const char* pszInBuf, int nInLen, char* pszOutBuf, int nOutLen);

};





#endif // !WIN32
#endif // !_LIBICONVCODE_H_


