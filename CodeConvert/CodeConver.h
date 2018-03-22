// Author£º		xiongw
// Date£º		2018-03-22
// filename:	CodeConver.h

#ifndef _CODECONVERT_H_
#define _CODECONVERT_H_

#include <string>

class CodeConvert
{
public:
	static std::wstring ANSIToUnicode(const std::string&);
	static std::string UnicodeToUTF8(const std::wstring&);

	static std::wstring UTF8ToUnicode(const std::string&);
	static std::string UnicodeToANSI(const std::wstring&);

	static std::string UTF8ToANSI(const std::string&);
	static std::string ANSIToUFT8(const std::string&);
};


#endif // !_CODECONVERT_H_


