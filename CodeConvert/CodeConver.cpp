#include "CodeConver.h"
#include "LibiconvCode.h"
#ifdef WIN32
#include <Windows.h>
#endif // WIN32

using namespace std;

const int nkLne = 512;

std::wstring CodeConvert::ANSIToUnicode(const std::string &str)
{
#ifdef WIN32
	int			nLen = 0;
	int			nUnicodeLen = 0;
	wchar_t*	pszUnicode = NULL;
	wstring		rt;

	nLen = str.length();
	nUnicodeLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
	pszUnicode = new wchar_t[nUnicodeLen + 1];
	memset(pszUnicode, 0, (nUnicodeLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, (LPWSTR)pszUnicode, nUnicodeLen);
	rt = (wchar_t*)pszUnicode;
	if (pszUnicode != NULL)
	{
		delete pszUnicode;
		pszUnicode = NULL;
	}
	return rt;
#else
	wstring rt;
	return rt;
#endif // WIN32
}

std::string CodeConvert::UnicodeToUTF8(const std::wstring &str)
{
#ifdef WIN32
	char*	pszElementText = NULL;
	int		nTextLen = 0;
	string	strText;

	nTextLen = WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, NULL, 0, NULL, NULL);
	pszElementText = new char[nTextLen + 1];
	memset((void*)pszElementText, 0, (nTextLen + 1) * sizeof(char));
	::WideCharToMultiByte(CP_UTF8, 0, str.c_str(), -1, pszElementText, nTextLen, NULL, NULL);
	strText = pszElementText;
	if (pszElementText != NULL)
	{
		delete[]pszElementText;
		pszElementText = NULL;
	}
	return strText;
#else
	string	strText;
	return strText;
#endif // WIN32
}

std::wstring CodeConvert::UTF8ToUnicode(const std::string &str)
{
#ifdef WIN32
	wchar_t*	pszUnicode = NULL;
	int			nLen = 0;
	int			nUnicodeLen = 0;
	wstring		rt;

	nLen = str.length();
	nUnicodeLen = ::MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
	pszUnicode = new wchar_t[nUnicodeLen + 1];
	memset(pszUnicode, 0, (nUnicodeLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, (LPWSTR)pszUnicode, nUnicodeLen);
	rt = (wchar_t*)pszUnicode;
	if (pszUnicode != NULL)
	{
		delete pszUnicode;
		pszUnicode = NULL;
	}
	return rt;
#else
	wstring	rt;
	return rt;
#endif // WIN32
}

std::string CodeConvert::UnicodeToANSI(const std::wstring &str)
{
#ifdef WIN32
	char*	pszElementText = NULL;
	int		nTextLen = 0;
	string	strText;

	nTextLen = WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, NULL, 0, NULL, NULL);
	pszElementText = new char[nTextLen + 1];
	memset((void*)pszElementText, 0, (nTextLen + 1) * sizeof(char));
	::WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, pszElementText, nTextLen, NULL, NULL);
	strText = pszElementText;
	if (pszElementText != NULL)
	{
		delete[]pszElementText;
		pszElementText = NULL;
	}
	return strText;
#else
	string	strText;
	return strText;
#endif // WIN32
}

std::string CodeConvert::UTF8ToANSI(const std::string &str)
{
#ifdef WIN32
	return UnicodeToANSI(UTF8ToUnicode(str));
#else
	static char szOut[nkLne] = { 0 };
	memset(szOut, 0, nkLne);
	LibiconvCode lc("utf-8", "gb2312");
	lc.Convert((char*)str.c_str(), str.length(), szOut, nkLne);
	::string strTmp(szOut, strlen(szOut));
	return strTmp;	
#endif // WIN32
}

std::string CodeConvert::ANSIToUFT8(const std::string &str)
{
#ifdef WIN32
	return UnicodeToUTF8(ANSIToUnicode(str));
#else
	static char szOut[nkLne] = { 0 };
	memset(szOut, 0, nkLne);
	LibiconvCode lc("gb2312", "utf-8");
	lc.Convert((char*)str.c_str(), str.length(), szOut, nkLne);
	::string strTmp(szOut, strlen(szOut));
	return strTmp;
#endif // WIN32
}
