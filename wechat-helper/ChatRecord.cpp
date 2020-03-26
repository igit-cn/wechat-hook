#include "ChatRecord.h"
#include <Windows.h>
#include <string>
#include "Util.h"
#include "offset.h"
#include "struct.h"
#include "WSClient.h"
#include "EVString.h"
#include "Command.h"
#include "Loger.h"

DWORD recieveMsgCall, recieveMsgJmpAddr;


string Wstr2Str(wstring wstr)
{
	if (wstr.length() == 0)
		return "";

	std::string str;
	str.assign(wstr.begin(), wstr.end());
	return str;
}

void ReceiveMsgProc(LPVOID Context)
{
	recieveMsgStruct* msg = (recieveMsgStruct*)Context;
	//WriteInfo("�յ���Ϣ1");
	//todo:�����Զ�����(�Զ��տ�Զ�����Ƭ��)
	neb::CJsonObject data;
	//todo:fromWxid��senderWxidĳЩ������Ϣ���쳣

	//WriteInfo("�յ���Ϣ2");
	data.Add("Type", msg->type);
	data.Add("IsSelf", msg->isSelf);
	if (msg->fromWxid != NULL) { data.Add("FromWxid", EVString::w2a(msg->fromWxid)); }
	if (msg->senderWxid != NULL) { data.Add("SendWxid", EVString::w2a(msg->senderWxid)); }
	if (msg->content != NULL) { data.Add("Content", EVString::w2a(msg->content)); }
	if (msg->unkonwStr != NULL) { data.Add("Other", EVString::w2a(msg->unkonwStr)); }
	delete msg;
	//WriteInfo("�յ���Ϣ3");
	Send(Cmd_ReceiveMessage, data);
}

/**
 * �������ص�����Ϣ����
 * @param DWORD esp
 * @return VOID
 */
VOID RecieveMessageJump(DWORD esp)
{
	//WriteInfo("�յ���Ϣ");
	DWORD* msgAddress = (DWORD*)(esp + 0x20);
	recieveMsgStruct* msg = new recieveMsgStruct;
	msg->type = (int)(*((DWORD*)(*msgAddress + 0x128)));
	msg->isSelf = (int)(*((DWORD*)(*msgAddress + 0x12C)));
	msg->fromWxid = (wchar_t*)(*((LPVOID*)(*msgAddress + 0x138)));
	msg->content = (wchar_t*)(*((LPVOID*)(*msgAddress + 0x160)));
	msg->senderWxid = (wchar_t*)(*((LPVOID*)(*msgAddress + 0x210)));
	msg->unkonwStr = (wchar_t*)(*((LPVOID*)(*msgAddress + 0x224)));
	//HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ReceiveMsgProc, msg, 0, NULL);
	ReceiveMsgProc(msg);// �˴��ݲ�ʹ�ö��߳� ��ֹ��ַ���ݱ��ͷ�
}


/**
 * ��д�뵽hook��Ľ�����Ϣ�㺯��
 */
__declspec(naked) void RecieveMsgDeclspec()
{
	__asm
	{
		pushad
		push esp
		call RecieveMessageJump
		add esp, 4
		popad
		call recieveMsgCall
		jmp recieveMsgJmpAddr
	}
}

void HookChatRecord() {
	//HOOK������Ϣ
	DWORD recieveMsgHookAddr = GetWeChatWinBase() + RECIEVEHOOKADDR;
	recieveMsgCall = GetWeChatWinBase() + RECIEVEHOOKCALL;
	recieveMsgJmpAddr = recieveMsgHookAddr + 5;
	BYTE msgJmpCode[5] = { 0xE9 };
	*(DWORD*)&msgJmpCode[1] = (DWORD)RecieveMsgDeclspec - recieveMsgHookAddr - 5;
	WriteProcessMemory(GetCurrentProcess(), (LPVOID)recieveMsgHookAddr, msgJmpCode, 5, NULL);
}