#pragma once

/**
 * �����ı���Ϣ
 * @param wchar_t* wxid, string content
 * @return void
 */
void SendTextMsg(wchar_t* wxid, wchar_t* msg);

/**
 * ����ͼƬ�ļ�
 * @param wchar_t* wxid, string content
 * @return void
 */
void SendImageMsg(wchar_t* wxid, wchar_t* filepath);

/**
 * ���͸����ļ�
 * @param wchar_t* wxid, string content
 * @return void
 */
void SendAttachMsg(wchar_t* wxid, wchar_t* filepath);


/**
 * ���ͺ�����Ƭ
 * @param wchar_t* wxid, wchar_t* xmlData
 * @return void
 */
void SendXmlCard(wchar_t* RecverWxid, wchar_t* xml);

/**
 * ������������
 * @param wchar_t* RecverWxid, wchar_t* FromWxid, wchar_t* xmlData
 * @return void
 */
void SendXmlArticle(wchar_t* RecverWxid, wchar_t* FromWxid, wchar_t* xmlData);