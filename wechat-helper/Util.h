#pragma once  
#include "stdafx.h" 
#include <Windows.h>
#include <string>

using namespace std;

/**
 * ��ȡWeChatWin.dll��ַ
 * @param
 * @return DWORD
 */
DWORD GetWeChatWinBase();

/**
 * ���΢�Ű汾�Ƿ�ƥ��
 * @param
 * @return BOOL
*/
BOOL IsWxVersionValid();

/**
 * ����ת��
 * @param const wchar_t* unicode
 * @return char*
 */
char* UnicodeToUtf8(const wchar_t* unicode);


/**
 * ����ת��
 * @param const char* str
 * @return wchar_t*
*/
wchar_t* UTF8ToUnicode(const char* str);


/**
 * ����ת��
 * @param std::string sInfo, INT sourceEncode, INT targetEncode
 * @return std::string
 */
string EncodeConvert(std::string sInfo, INT sourceEncode, INT targetEncode);


/**
 * ����ת��
 * @param std::string str
 * @return wchar_t*
 */
wchar_t* StrToWchar(std::string str);


/**
 * ����Ŀ¼
 * @param const char* dir
 * @return void
*/
void CreateDir(const char* dir);