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

/***********软总线错误应答代码**********************************/

#define	SB_OTHER_ERR				1   /*其他错误*/
#define	SB_MEM_ERR				2   /*软总线内存错误*/
#define	SB_APPID_REGISTER_IS_EXIST		3   /*此APP_ID已经注册过*/
#define	SB_SEND_BUF_OVERFLOW			4   /*发送数据区溢出*/
#define	SB_RECV_BUF_OVERFLOW			5   /*接收数据区溢出*/
#define	SB_SOURCE_APPID_NOT_REGISTER		6   /*软总线源APP_ID没有注册*/
#define	SB_DESTINATION_APPID_NOT_REGISTER	7   /*软总线目标APP_ID没有注册*/
#define	SB_DESTINATION_APPID_IS_REGISTER	8   /*软总线目标APP_ID已经注册*/
#define SB_SOURCE_TASKID_NOT_REGISTER		9   /*软总线源TASKID没有注册*/
#define SB_SOURCE_TASKID_IS_REGISTER		10  /*软总线源TASKID已经注册*/
#define	SB_TIMEOUT				11  /*超时*/
#define	SB_RECV_TYPE_ERR			12  /*接收类型错误*/
#define	SB_SEMAPHORE_ERR			13   /*软总线锁错误*/
#define	SB_NOT_ACTIVE				14   /*软总线不活动*/
#define	SB_NO_RECV_DATA				15   /*没有接收数据*/
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
	u_int       length;    /*second_tag下面的数据长度(不包括second_tag)*/
	u_int     	second_tag;/*0x68686868*/
	u_int       service_type;
    				/*
    					service_type <=255表示服务类型：
    					1=非函数调用点对点报文传输，下面的invoke_id无效。
    					2=非函数调用广播报文传输 ，下面的invoke_id无效。
    					3=非函数调用组播报文传输，下面的invoke_id无效。					
    					4= 当使用SB_send_recv()函数时，service_type=4,invoke_id有效
    					5:对service_type的返回报文中service_type=5,invoke_id有效
    					
    					255< service_type<=512 :软总线使用
    					service_type>512 :保留
    				*/
	u_int     	source_app_id;   /*源组件的ID*/
	u_int     	source_task_id;   /*数据源任务ID*/
	u_int     	invoke_id;       /*返回标识，当service_type=4时，每个组件保留一个invoke_id，每次发送时加1*/
	union {
		u_int   app_id;	 /*目的组件的ID，广播时为0xffff*/
		u_int   group_id;    /*目的组的ID*/
	}destination;
	u_int       destination_task_id;    /*目的任务ID*/	
	u_int       event_id;  	/*事件号,最高位表示事件号是否有效，0：无效；1：有效*/
	u_short     frame_num;  	/*报文的总桢数，软总线填写*/	
	u_short		frame_no;    	/*报文桢序号, 软总线填写。组件从软总线接收报文时，往往由于自身的限制可能无法一次读出一个完整的报文（例如：如果按照注册的方式来读，消息或者管道的长度会有限制 ），可以通过此标志来组包*/
	u_int       user_id;	/*用户自用，会在返回报文中原样返回*/	
	u_int       reserval;       /*保留,将来使用*/	
};
#pragma pack(pop)
/*
    frame_no 和 frame_num使用更改：
	frame_no：高8位表示总帧数。低8位表示第几帧。不分帧为0。
	frame_num：低8位表示序列号（每个板卡单独记录）。bit15：主备标志，bit14，13，12，11，9798地址低四位，
	bit10，9，8表示板卡地址。
*/

extern	void    SB_init_soft_bus(u_int interface_ip);
extern	int	    SB_register(u_int  app_id,u_int   group_id,int *error_no);
//extern	int	    SB_recv_register(u_int  app_id,u_int  task_id,int  msg_type,int  msg_id,int pipe_num,int  max_msg_length,int	*error_no);
extern	int	    SB_recv_register(u_int  app_id,u_int  task_id,int  msg_type, FBufCircle *msg_id,char *taskName,int	*error_no);
extern	int     SBA_send(struct  SOFT_BUS_HEAD  *send_data,int  *error_no);
extern	int     SBA_send_repeat(struct  SOFT_BUS_HEAD  *send_data,int  *error_no);
extern  void 	SB_print_error(int error_no);

#endif

