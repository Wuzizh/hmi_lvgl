/****************************************************************
 * FileName :softbus.h
 * Description:
 *
 * Modify Log:
 * 
 ****************************************************************/
#ifndef	_SOFTBUS_H_
#define	_SOFTBUS_H_

#include "sys/types.h"
#include "fbufcircle.h"
#include "data_types.h"

#define		SB_NOUSE_TYPE		0
#define		SB_MSGQ_TYPE		1
#define		SB_PIPE_TYPE		2
#define		SB_MSGPOLLING_TYPE	3
#define		SB_MSGQ_BRF_TYPE	4
#define		SB_PIPE_BRF_TYPE	5

#define		MAX_TASKNAME_LEN    32

/***********�����ߴ���Ӧ�����**********************************/

#define	SB_OTHER_ERR				1   /*��������*/
#define	SB_MEM_ERR				2   /*�������ڴ����*/
#define	SB_APPID_REGISTER_IS_EXIST		3   /*��APP_ID�Ѿ�ע���*/
#define	SB_SEND_BUF_OVERFLOW			4   /*�������������*/
#define	SB_RECV_BUF_OVERFLOW			5   /*�������������*/
#define	SB_SOURCE_APPID_NOT_REGISTER		6   /*������ԴAPP_IDû��ע��*/
#define	SB_DESTINATION_APPID_NOT_REGISTER	7   /*������Ŀ��APP_IDû��ע��*/
#define	SB_DESTINATION_APPID_IS_REGISTER	8   /*������Ŀ��APP_ID�Ѿ�ע��*/
#define SB_SOURCE_TASKID_NOT_REGISTER		9   /*������ԴTASKIDû��ע��*/
#define SB_SOURCE_TASKID_IS_REGISTER		10  /*������ԴTASKID�Ѿ�ע��*/
#define	SB_TIMEOUT				11  /*��ʱ*/
#define	SB_RECV_TYPE_ERR			12  /*�������ʹ���*/
#define	SB_SEMAPHORE_ERR			13   /*������������*/
#define	SB_NOT_ACTIVE				14   /*�����߲��*/
#define	SB_NO_RECV_DATA				15   /*û�н�������*/
#define	SB_SERVERCE_TYPE_ERR			16
#define SB_GATEWAY_NOT_ACTIVE			18
#define SB_SENDDATALENGTH_OVERFLOW		19
#define SB_MSG_TYPE_ERR				20
#define SB_MSG_ID_ERR				21

#define	SOFT_BUS_HEAD_LENGTH	12
#pragma pack(push,1)	
struct  SOFT_BUS_HEAD
{
	u_int   	first_tag; /*0x68686868*/
	u_int       length;    /*second_tag��������ݳ���(������second_tag)*/
	u_int     	second_tag;/*0x68686868*/
	u_int       service_type;
    				/*
    					service_type <=255��ʾ�������ͣ�
    					1=�Ǻ������õ�Ե㱨�Ĵ��䣬�����invoke_id��Ч��
    					2=�Ǻ������ù㲥���Ĵ��� �������invoke_id��Ч��
    					3=�Ǻ��������鲥���Ĵ��䣬�����invoke_id��Ч��					
    					4= ��ʹ��SB_send_recv()����ʱ��service_type=4,invoke_id��Ч
    					5:��service_type�ķ��ر�����service_type=5,invoke_id��Ч
    					
    					255< service_type<=512 :������ʹ��
    					service_type>512 :����
    				*/
	u_int     	source_app_id;   /*Դ�����ID*/
	u_int     	source_task_id;   /*����Դ����ID*/
	u_int     	invoke_id;       /*���ر�ʶ����service_type=4ʱ��ÿ���������һ��invoke_id��ÿ�η���ʱ��1*/
	union {
		u_int   app_id;	 /*Ŀ�������ID���㲥ʱΪ0xffff*/
		u_int   group_id;    /*Ŀ�����ID*/
	}destination;
	u_int       destination_task_id;    /*Ŀ������ID*/	
	u_int       event_id;  	/*�¼���,���λ��ʾ�¼����Ƿ���Ч��0����Ч��1����Ч*/
	u_short     frame_num;  	/*���ĵ�����������������д*/	
	u_short		frame_no;    	/*���������, ��������д������������߽��ձ���ʱ������������������ƿ����޷�һ�ζ���һ�������ı��ģ����磺�������ע��ķ�ʽ��������Ϣ���߹ܵ��ĳ��Ȼ������� ��������ͨ���˱�־�����*/
	u_int       user_id;	/*�û����ã����ڷ��ر�����ԭ������*/	
	u_int       reserval;       /*����,����ʹ��*/	
};
#pragma pack(pop)
/*
    frame_no �� frame_numʹ�ø��ģ�
	frame_no����8λ��ʾ��֡������8λ��ʾ�ڼ�֡������֡Ϊ0��
	frame_num����8λ��ʾ���кţ�ÿ���忨������¼����bit15��������־��bit14��13��12��11��9798��ַ����λ��
	bit10��9��8��ʾ�忨��ַ��
*/

extern	void    SB_init_soft_bus(u_int interface_ip);
extern	int	    SB_register(u_int  app_id,u_int   group_id,int *error_no);
//extern	int	    SB_recv_register(u_int  app_id,u_int  task_id,int  msg_type,int  msg_id,int pipe_num,int  max_msg_length,int	*error_no);
extern	int	    SB_recv_register(u_int  app_id,u_int  task_id,int  msg_type, FBufCircle *msg_id,char *taskName,int	*error_no);
extern	int     SBA_send(struct  SOFT_BUS_HEAD  *send_data,int  *error_no);
extern	int     SBA_send_repeat(struct  SOFT_BUS_HEAD  *send_data,int  *error_no);
extern  void 	SB_print_error(int error_no);

#endif

