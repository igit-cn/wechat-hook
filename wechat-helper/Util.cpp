#include "stdafx.h"
#include "Util.h"
#include <Windows.h>
#include <string>
#include <vector>
#include "offset.h"
#include <strstream>
#include <corecrt_io.h>
#include <direct.h>
#include "offset.h"
#pragma comment(lib,"Version.lib")

DWORD weChatWinAddress = 0;

/**
 * ��ȡWeChatWin.dll��ַ
 * @param
 * @return DWORD
 */
DWORD GetWeChatWinBase()
{
	if (weChatWinAddress == 0)
	{
		weChatWinAddress = (DWORD)LoadLibrary(L"WeChatWin.dll");
	}
	return weChatWinAddress;
}



/**
 * ���΢�Ű汾�Ƿ�ƥ��
 * @param
 * @return BOOL
*/
BOOL IsWxVersionValid()
{
	DWORD wxBaseAddress = GetWeChatWinBase();
	const string wxVersoin = "2.8.0.112";

	WCHAR VersionFilePath[MAX_PATH];
	if (GetModuleFileName((HMODULE)wxBaseAddress, VersionFilePath, MAX_PATH) == 0)
	{
		return FALSE;
	}

	string asVer = "";
	VS_FIXEDFILEINFO* pVsInfo;
	unsigned int iFileInfoSize = sizeof(VS_FIXEDFILEINFO);
	int iVerInfoSize = GetFileVersionInfoSize(VersionFilePath, NULL);
	if (iVerInfoSize != 0) {
		char* pBuf = new char[iVerInfoSize];
		if (GetFileVersionInfo(VersionFilePath, 0, iVerInfoSize, pBuf)) {
			if (VerQueryValue(pBuf, TEXT("\\"), (void**)&pVsInfo, &iFileInfoSize)) {

				int s_major_ver = (pVsInfo->dwFileVersionMS >> 16) & 0x0000FFFF;

				int s_minor_ver = pVsInfo->dwFileVersionMS & 0x0000FFFF;

				int s_build_num = (pVsInfo->dwFileVersionLS >> 16) & 0x0000FFFF;

				int s_revision_num = pVsInfo->dwFileVersionLS & 0x0000FFFF;

				//�Ѱ汾����ַ���
				strstream wxVer;
				wxVer << s_major_ver << "." << s_minor_ver << "." << s_build_num << "." << s_revision_num;
				wxVer >> asVer;
			}
		}
		delete[] pBuf;
	}

	//�汾ƥ��
	if (asVer == wxVersoin)
	{
		return TRUE;
	}

	//�汾��ƥ��
	return FALSE;
}


/**
 * ����ת��
 * @param const wchar_t* unicode
 * @return char*
 */
char* UnicodeToUtf8(const wchar_t* unicode)
{
	int len;
	len = WideCharToMultiByte(CP_UTF8, 0, unicode, -1, NULL, 0, NULL, NULL);
	char* szUtf8 = (char*)malloc(len + 1);
	if (szUtf8 != 0) {
		memset(szUtf8, 0, len + 1);
	}
	WideCharToMultiByte(CP_UTF8, 0, unicode, -1, szUtf8, len, NULL, NULL);
	return szUtf8;
}

/**
 * ����ת��
 * @param const char* str
 * @return wchar_t*
*/
wchar_t* UTF8ToUnicode(const char* str)
{
	int textlen = 0;
	wchar_t* result;
	textlen = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	result = (wchar_t*)malloc((textlen + 1) * sizeof(wchar_t));
	memset(result, 0, (textlen + 1) * sizeof(wchar_t));
	MultiByteToWideChar(CP_UTF8, 0, str, -1, (LPWSTR)result, textlen);
	return result;
}


/**
 * ����ת��
 * @param std::string sInfo, INT sourceEncode, INT targetEncode
 * @return std::string
 */
std::string EncodeConvert(std::string sInfo, INT sourceEncode, INT targetEncode)
{
	const char* buf = sInfo.c_str();
	int len = MultiByteToWideChar(sourceEncode, 0, buf, -1, NULL, 0);
	std::vector<wchar_t> unicode(len);
	MultiByteToWideChar(sourceEncode, 0, buf, -1, &unicode[0], len);
	std::wstring wstr(&unicode[0]);

	const wchar_t* wbuf = wstr.c_str();
	len = WideCharToMultiByte(targetEncode, 0, wbuf, -1, NULL, 0, NULL, NULL);
	std::vector<char> multi(len);
	WideCharToMultiByte(targetEncode, 0, wbuf, -1, &multi[0], len, NULL, NULL);
	std::string sMulti(&multi[0]);
	return sMulti;
}

/**
 * ����ת��
 * @param std::string str
 * @return wchar_t*
 */
wchar_t* StrToWchar(std::string str)
{
	int strSize = (int)(str.length() + 1);
	wchar_t* wStr = new wchar_t[strSize];
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, wStr, strSize);
	return wStr;
	delete[] wStr;
}


/**
 * ����Ŀ¼
 * @param const char* dir
 * @return void
*/
void CreateDir(const char* dir)
{
	int m = 0, n;
	string str1, str2;

	str1 = dir;
	str2 = str1.substr(0, 2);
	str1 = str1.substr(3, str1.size());

	while (m >= 0)
	{
		m = str1.find('\\');
		str2 += '\\' + str1.substr(0, m);
		n = _access(str2.c_str(), 0); //�жϸ�Ŀ¼�Ƿ����
		if (n == -1)
		{
			_mkdir(str2.c_str());     //����Ŀ¼
		}
		str1 = str1.substr(m + 1, str1.size());
	}
}