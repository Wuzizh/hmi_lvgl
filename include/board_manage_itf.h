/****************************************************************
 * FileName :mdl_board_manage_itf.h
 * Description:板卡管理组件
 *
 * Modify Log:
 * 
 ****************************************************************/

#ifndef	_MDL_BOARD_MANAGE_ITF_H_
#define	_MDL_BOARD_MANAGE_ITF_H_

#include "sys_define.h"
#include "softbus.h"

#define  	MDL_BOARD_MANAGE_APPID						(sys_appid_segment+sys_board_addr*256+2*64+1)
#define  	MDL_BOARD_MANAGE_TASKID						1
#define  	MDL_FIRST_BOARD_MANAGE_APPID				(sys_appid_segment+256+2*64+1)
#define  	MODULE_BOARD_MANAGE_MAX_MSG_LENGTH			200	//11000
#define		BOARD_GET_PORT_INF_ID					((u_int)1)
#define		BOARD_FORM_CONSOLE_CMD_ID				((u_int)2)
#define		BOARD_PROTOCOL_SET_TIME_ID				((u_int)3)
#define		BOARD_PROTOCOL_GET_TIME_ID				((u_int)4)
#define		BOARD_FILE_TRANS_ID						((u_int)5)
#define		BOARD_SET_TIME_ID						((u_int)6)
#define		BOARD_GET_MDL_STATE_ID					((u_int)7)
#define		BOARD_GET_VARIABLE_ID					((u_int)8)
#define		CONSOLE_BROADCAST_BOARD_INF				((u_int)9)
#define		BOARD_GET_PORT_DECS_ID					((u_int)10)

#define		SYS_CCU_RUNNING_ID						((u_int)0)
#define		SYS_CONSOLE_PROTOCOL_RUNNING_ID			((u_int)1)
#define		SYS_DEVICE_PROTOCOL_RUNNING_ID			((u_int)2)
#define		SYS_DEVPROT_WAVE_RUNNING_ID				((u_int)3)
#define		SYS_SET_TIME_DISABLE_ID					((u_int)4)
#define        SYS_REMOTE_LOCAL_ID                          ((u_int)5)
#define        SYS_WAVE_NEED_FLAG_ID                        ((u_int)6)

extern	int 	mdl_boardcard_get_port_inf(u_int source_app_id,u_int source_task_id,u_int destination_app_id,u_int destination_task_id,u_char boardcard_addr,u_int  *len,u_char *buf);
extern 	int 	mdl_boardcard_get_port_decs(u_int source_app_id,u_int source_task_id,u_int destination_app_id,u_int destination_task_id,u_char boardcard_addr,u_int  *len,u_char *buf);
extern	int		mdl_board_manage_itf_a_send_data(u_int source_app_id,u_int source_task_id,u_int destination_app_id,u_int destination_task_id,u_int return_id,u_char  *data,int length);
extern	int		mdl_board_manage_itf_send_file_data(u_int source_app_id,u_int source_task_id,u_int destination_app_id,u_int destination_task_id,u_int return_id,u_int return_id_1,u_char  *data,int length);
extern 	int 	sys_reset_all_board();
extern  int 	sys_reset_appoint_board(u_short board_addr);
extern 	int 	mdl_boardcard_set_time(u_int source_app_id,u_int source_task_id,	u_int destination_app_id,u_int destination_task_id,u_int   appid,struct SYS_TIME *t,int  period);
extern	int 	board_resp_softbus_head(struct SOFT_BUS_HEAD *sendp,struct SOFT_BUS_HEAD *recvp);

/****************************************************/
extern	int 	mdl_board_manage_init();
extern 	int 	board_send_net_watch_data(u_char *send_buf,int length,int type,int direction,int con_no,u_int destiantion_ip,u_int source_ip,u_short dev_addr);
extern 	int 	board_send_com_watch_data(u_char *send_buf,int length,int direction,u_char com_no,u_short src_devaddr,u_short des_devaddr);
extern	void	protocol_printf(u_char watch_type,u_char watch_no,const char *format,...);
extern	u_char can_protocol_printf(u_char watch_type, u_char watch_no) ;
extern	void	my_printf(const char *format,...);
extern  int 	board_proc_set_time2(u_int   appid,struct SYS_TIME *t,int period);
extern 	int 	board_proc_get_time2(struct SYS_TIME *t);
/****************************************************/

enum     	TRANS_TYPE{RX_ONLY,TX_ONLY,RX_TX};																											
enum     	PORT_TYPE{UDP_ONLY=1,TCP_ONLY,TCP_UDP};																											
enum     	RAWDATA_DIR{RX_DIR,TX_DIR};
enum     	RAWDATA_TYPE{UDP_DATA=1,TCP_DATA};	
enum		PORT_TYPE_DATA{COM_DATA,CON_DATA};																										

#pragma pack(push,1)	
struct	MANAGE_BOARD_ADDR
{
	u_short	boardcard_addr;
};

struct	BOARD_CMD_DATA
{
	u_int	 return_id;
	int	 length;
	u_char   data[1]; 						/*DCDU数据*/
};

struct SET_TIME_DATA                       	/*获取当前时间输入参数*/  
{
	u_int   appid;                      	/*时间源的appid*/
	u_char  time[4];
	struct 	SYS_TIME t;
	int  	period;                        	/*对时周期*/
};

struct	BOARD_FILE_DATA
{
	u_short	boardcard_addr;
	u_int	return_id;
	u_int	return_id_1;
	int		length;
	u_char	data[1]; /*DCDU数据*/
};

struct  GET_GLOBOA_VARIABLE
{
	int variable_id;
	int return_variable;
};

struct	MDL_BOARD_MANAGE_REQ_DATA
{		
	int	interface_id; /*
				interface_id：
    				1：向板卡管理组件要端口信息
    				2: 向板卡发命令
    				3: 设置系统时间
    				4: 获取系统时间
    				5: 文件传输报文
    				6: 第一块板卡广播对时
    				7: 取得板卡管理组件状态
    				8: 取得第一块板卡全局变量
    				9: 组态向板卡广播当前板卡地址
    				*/  
	union
	{
		struct  MANAGE_BOARD_ADDR  	board;		/*1,9*/
		struct  BOARD_CMD_DATA 		data;		/*2:各组件向板卡管理组件发的命令dsdu*/
		struct 	SET_TIME_DATA		set_time;	/*3,6:规约对时*/
		struct  BOARD_FILE_DATA		file_data;	/*5: 文件传输报文*/
		struct  GET_GLOBOA_VARIABLE		global_variable;/*8: 取得第一块板卡全局变量*/			
	}req;
};	

struct	MANAGE_PORT_INF_DATA
{
	u_int	 return_id;
	u_short board_addr;
	int	 length;
	u_char   data[1]; /*DCDU数据*/
};
struct GET_TIME_DATA                      	/*获取当前时间输出参数*/        
{
	struct SYS_TIME t;
};
struct	BOARD_STATE
{
	u_char state;
};

struct	MDL_BOARD_MANAGE_RESP_DATA/*应答数据结构*/
{	
	int	interface_id; /* 
				interface_id：
    				1：板卡管理组件回应的端口信息    				
     				3: 设置系统时间响应
    				4: 获取系统时间响应
    				7: 板卡组件状态响应
    				8: 获取全局变量响应 				
    				*/  
	int	result;		/*0:正常	1：错误*/	
	union
	{		
		struct	MANAGE_PORT_INF_DATA	port_data; 	/*interface_id=1 */	
		struct  GET_TIME_DATA			get_time;	/*4: 获取系统时间响应*/		
		struct	BOARD_STATE				board_state;
		struct  GET_GLOBOA_VARIABLE		global_variable;			
	}resp;
};
#pragma pack(pop)

#endif
