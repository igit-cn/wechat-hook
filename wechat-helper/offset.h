#pragma once
//----------������Ϣ��� Start----------
#define MY_CONFIG				0x1618740	//΢��ID
#define MY_WXID					0x1618774	//΢��ID
#define MY_ACCOUNT				0x1618950	//΢�ź�
#define MY_ACCOUNT2				0x1618BD8	//΢�ź�
#define MY_NICKNAME				0x16187EC	//�ǳ�
#define MY_EMAIL				0x1618808	//����
#define MY_MOBILE				0x1618820	//�ֻ���
#define MY_PROVINCE				0x16188F0	//ʡ��
#define MY_CITY					0x16188D8	//����
#define MY_NATION				0x16189C8	//����
#define MY_DEVICE				0x1618C28	//�豸
#define MY_BIGHEAD				0x1618AB4	//��ͷ��
#define MY_SMALLHEAD			0x1618ACC	//Сͷ��
#define MY_SEX					0x16188D4	//�Ա�
#define MY_SIGNNAME				0x1618908	//����ǩ��
#define MY_RANDOM_STR			0x1618998	//����ַ���
#define MY_PUBLIC_KEY			0x1618C44	//��Կ
#define MY_PRIVATE_KEY			0x1618C5C	//˽Կ
//----------������Ϣ��� Over----------

#define ISLOGIN					0x16188C4	//�Ƿ��¼��ʶ��0-δ��¼|1-�ѵ�¼

#define LOGOUT					0x43DB70	//�˳���¼

#define LOGINQRCODESTR			0x1631A88	//��¼��ά���ַ�����http://weixin.qq.com/x/ ���ϸ�ֵ�����ɵĶ�ά���ǵ�¼��ά��

#define GOTOQRCODE1				0x20F490	//��ת����ά�����
#define GOTOQRCODE2				0x31F490	//��ת����ά�����

#define RECIEVEHOOKADDR			0x34F4A7	//������Ϣ
#define RECIEVEHOOKCALL			0x1D0980	//������Ϣ

#define SENDTEXTADDR			0x327A20	//�����ı���Ϣecx����ƫ��

#define SENDIMGADDR1			0x4E4F0		//����ͼƬ�ļ�call��ַƫ��
#define SENDIMGADDR2			0x327410	//����ͼƬ�ļ�call��ַƫ��
#define SENDIMGADDR3			0x6DDF0		//��΢�ŷ���ͼƬ��ռ��ͼƬ����ƫ����Ϊ���ͷ�ͼƬռ��

#define SENDATTACHADDR1			0x4DC8F0	//���͸���
#define SENDATTACHADDR2			0x4DC930	//���͸���
#define SENDATTACHADDR3			0x543F0		//���͸���
#define SENDATTACHADDR4			0x25D7B0	//���͸���
#define SENDATTACHPARAM			0x13658A8	//���͸�������

#define SENDXMLCARD				0x327A20	//����xml��Ƭ
#define SENDXMLARTICLE			0x25D4B0	//����xml����

#define DATABASEHOOKADDR		0x47F903	//���ݿ�hook
#define DATABASERUNCALL			0x8C4430	//���ݿ�ִ��call

#define COLLECTMONEYCALL1		0x7A7A90	//�տ�CALL1
#define COLLECTMONEYCALL2		0x7A7B10	//�տ�CALL2

#define ADDCARDUSERPARAM		0x1366C34	//��Ӻ���
#define ADDCARDUSERCALL1		0x52260		//��Ӻ���
#define ADDCARDUSERCALL2		0x6E620		//��Ӻ���
#define ADDCARDUSERCALL3		0x4DC8F0	//��Ӻ���
#define ADDCARDUSERCALL4		0x4DC930	//��Ӻ���
#define ADDCARDUSERCALL5		0x2A9F80	//��Ӻ���

#define AGREEUSERREQUESTPARAM	0x1618E48	//ͬ���������
#define AGREEUSERREQUESTCALL1	0x1A4230	//ͬ���������
#define AGREEUSERREQUESTCALL2	0x482D0		//ͬ���������
#define AGREEUSERREQUESTCALL3	0xE4CC0		//ͬ���������
#define AGREEUSERREQUESTCALL4	0x188BD0	//ͬ���������

#define ADDUSERFROMWXIDPARAM	0x1366C34	//ͨ��wxid��Ӻ���
#define ADDUSERFROMWXIDCALL1	0x52260		//ͨ��wxid��Ӻ���
#define ADDUSERFROMWXIDCALL2	0x6E620		//ͨ��wxid��Ӻ���
#define ADDUSERFROMWXIDCALL3	0x4DC8F0	//ͨ��wxid��Ӻ���
#define ADDUSERFROMWXIDCALL4	0x4DC930	//ͨ��wxid��Ӻ���
#define ADDUSERFROMWXIDCALL5	0x2A9F80	//ͨ��wxid��Ӻ���

#define SETCHATROOMANNOUNCEMENT 0x2A1450	//����Ⱥ����
#define SETCHATROOMNAME			0x29DC00	//����Ⱥ����

#define QUITCHATROOM			0x29E730	//�˳�Ⱥ��

#define DELETECHATROOMMEMBER1	0x4DC930	//ɾ��Ⱥ��Ա
#define DELETECHATROOMMEMBER2	0x66050		//ɾ��Ⱥ��Ա
#define DELETECHATROOMMEMBER3	0x29950		//ɾ��Ⱥ��Ա

#define ADDCHATROOMMEMBER1		0x91F60004	//���Ⱥ��Ա
#define ADDCHATROOMMEMBER2		0x4DCA40	//���Ⱥ��Ա
#define ADDCHATROOMMEMBER3		0x91F60004	//���Ⱥ��Ա
#define ADDCHATROOMMEMBER4		0x2992E0	//���Ⱥ��Ա
#define ADDCHATROOMPARAM1		0x1618774	//���Ⱥ��Ա
#define ADDCHATROOMPARAM2		0x91F60000	//���Ⱥ��Ա

#define GETCHATROOMUSERCALL1	0x465D10	//��ȡȺ��Աwxid
#define GETCHATROOMUSERCALL2	0x2F7530	//��ȡȺ��Աwxid
#define GETCHATROOMUSERCALL3	0x46C650	//��ȡȺ��Աwxid
#define GETCHATROOMUSERCALL4	0x466800	//��ȡȺ��Աwxid

#define DELETEFRIEND			0x2ACF70	//ɾ������

#define FRIENDHOOKADDR			0x477A78	//�����б�call
#define FRIENDHOOKCALL			0x4DCF50	//�����б�call

#define WxUpdateMemberDetails1 0x4DC930  //����������ݸ��� 482330
#define WxUpdateMemberDetails2 0x4E430  //����������ݸ���	4FFF0
#define WxUpdateMemberDetails3 0x2ABA90 //����������ݸ���	273820
#define WxUpdateMemberDetails4 0xF9B20  //����������ݸ���	E27E0
#define WxUpdateMemberDetails5 0x224C80  //����������ݸ���	2042A0
#define WxUpdateMemberDetails6 0x13C91C0 //����������ݸ���