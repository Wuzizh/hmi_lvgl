/****************************************************************
 * FileName :sys_extern.h
 * Description:
 *
 * Modify Log:
 * 
 ****************************************************************/
#ifndef	_SYS_EXTERN_H_
#define	_SYS_EXTERN_H_

#include  "sys_define.h"

//extern	char 	sys_my_doc_name[];
extern	char	sys_ccu_ini_path[60];
extern	char	sys_pctcp_ini[60];
extern	char	sys_pctcp_ini_bak[60];
extern	char	sys_factoryaddr_ini[60];
extern  char	sys_factoryaddr_ini_bak[60];

extern	u_int   sys_ethnet1_ip;
extern	u_int	sys_ethnet1_mask;
extern	u_int   sys_ethnet2_ip;
extern	u_int	sys_ethnet2_mask;
extern	u_int   sys_ethnet3_ip;
extern	u_int	sys_ethnet3_mask;
extern	u_int   sys_ethnet4_ip;
extern	u_int	sys_ethnet4_mask;

extern	u_int	sys_interface_ip;	/*背板IP地址*/

extern	u_char	sys_board_addr;
extern	u_char	sys_board_type;

extern	u_short sys_factory_addr;
extern	u_int	sys_9798_addr;

extern u_char sys_ip_success_flg;								 
extern	int	sys_single;
extern	int	sys_master_slave;
extern	int	sys_gps_state;
extern	int	sys_gps_state_count;
extern  int sys_msecond_count_flag;

extern	int	sys_ccu_running;
extern	int	sys_run_precept; 		/*0:远动装置 1:一体化装置 2:增强型远动装置 3:规约转换装置*/
extern	int	sys_run_precept_temp;
extern	int	sys_settime_disable;
extern	int	sys_settime_disable_temp;
extern	int	sys_dccu_precept;
extern	int	sys_dccu_precept_temp;
extern	int	sys_console_protocol_running;
extern	int	sys_device_protocol_running;
extern	int	sys_devprot_wave_running;
extern	struct	SYS_SYSTEM_INF sys_system_inf;

extern	u_int   sys_appid_segment;
extern  u_int   sys_appid_segment_b;

extern	int	sys_yk_rmotelocal_state;
extern	u_char	sys_irig_b_flag;	/*=YES  irig_b对时;	=NO  远动对时*/
extern	u_char	sys_yd_setime_flag;	/*=YES	收到远动对时报文;	=NO	没有收到远动对时报文*/
extern  u_char sys_language_flag;/*中英文菜单标志*/
extern  u_char sys_language_flag_tmp;/*中英文菜单临时标志*/
extern  u_char dev_state_not;  /*0 装置状态按正常上送  1 装置状态按取反上送*/
extern  u_char sys_wave_need_flag;/*是否召唤波形*/
extern	struct 	SYS_CONFIG_DATA   sys_config_data[SYS_BOARD_NUM];
extern	struct	SYS_COM_INIT  com_init_p[SYS_COM_NUM];
extern	struct	SYS_CON_INIT  con_init_p[SYS_CON_NUM];
extern	int	  	sys_msecond;
extern  u_char	sys_9798_yx[SYS_9798_YX_NUM];
extern  int		sys_9798_yx_on[SYS_9798_YX_NUM];	
extern  int		sys_9798_yx_off[SYS_9798_YX_NUM];	
extern	struct	SYS_CONSOLE_INDEX_LIST_DATA		sys_console_list_data;

extern	int	sys_ccub_valid_flag;

//extern	time_t	sys_soft_timer_second;
extern	int		sys_soft_timer_msecond;
extern	int 	debug_printf_pipe_id;
//extern	struct	PRINT_CHAIN_BUF	*sys_send_buf_head;
//extern	int	  	sys_unsend_bytes_count;
////extern	SEM_ID	sys_debug_printf_SEM;
//extern	u_char	sys_print_level;
extern	u_char	sys_print_console_ready;

extern	int		sys_ccub_hardware_state;	
extern  int    	sys_com_num[SYS_BOARD_NUM];
extern  int	  sys_nas_valid;     /*网络存储器投入*/
extern  int	  sys_task_watchdog_start;     /*任务监视启动标志*/
extern  int	  sys_task_watchdog_count;     /*任务监视超时计数*/
extern int   iec61850sDebug;


extern struct SYS_GD_JHQX_STRUCT sys_gd_jhqx;
extern struct SYS_RLL_STRUCT sysrll[SYS_RLL_MAX];

#endif

