/****************************************************************
 * FileName :sys_public.h
 * Description:
 *
 * Modify Log:
 * 
 ****************************************************************/
#ifndef	_SYS_PUBLIC_H_
#define	_SYS_PUBLIC_H_

#include	"sys_define.h"

char	sys_ccu_ini_path[60];
char	sys_pctcp_ini[60];
char	sys_pctcp_ini_bak[60];
char	sys_factoryaddr_ini[60];
char	sys_factoryaddr_ini_bak[60];

u_int   sys_ethnet1_ip;
u_int	sys_ethnet1_mask;
u_int   sys_ethnet2_ip;
u_int	sys_ethnet2_mask;
u_int   sys_ethnet3_ip;
u_int	sys_ethnet3_mask;
u_int   sys_ethnet4_ip;
u_int	sys_ethnet4_mask;

u_int	sys_interface_ip;	/*背板IP地址*/

u_char	sys_board_addr;
u_char	sys_board_type;
u_short sys_factory_addr=0;

int	sys_single;
int	sys_master_slave;
int	sys_gps_state;
int	sys_gps_state_count;
int sys_msecond_count_flag;

int	sys_ccu_running;
int	sys_run_precept; 		/*0:远动装置 1:一体化装置 2:增强型远动装置 3:规约转换装置*/
int	sys_run_precept_temp;
int	sys_settime_disable;
int	sys_settime_disable_temp;
int	sys_dccu_precept; 		/*0:单机运行 1:对上双主对下双主 2:对上双主对下主备 3:对上主备对下主备*/
int	sys_dccu_precept_temp;
int	sys_console_protocol_running; /*对上规约是否运行*/
int	sys_device_protocol_running;  /*对下规约是否运行*/
int	sys_devprot_wave_running;     /*对下规约是否召唤波形*/
u_char sys_language_flag;/*中英文菜单标志*/
u_char sys_language_flag_tmp;/*中英文菜单临时标志*/
u_char dev_state_not;  /*0 装置状态按正常上送  1 装置状态按取反上送*/
u_char sys_wave_need_flag;/*是否召唤波形*/
struct	SYS_SYSTEM_INF sys_system_inf;

u_int     sys_9798_addr;              /*管理机地址*/

u_int     	sys_appid_segment;
u_int     	sys_appid_segment_b;

int		sys_yk_rmotelocal_state;

u_char	sys_irig_b_flag;	/*=YES  irig_b对时;	=NO  远动对时*/
u_char	sys_yd_setime_flag;	/*=YES	收到远动对时报文;	=NO	没有收到远动对时报文*/

u_char  sys_ip_success_flg;	//ip是否获取成功标志							
struct    	SYS_CONFIG_DATA   sys_config_data[SYS_BOARD_NUM];
struct		SYS_COM_INIT  	com_init_p[SYS_COM_NUM];
struct		SYS_CON_INIT  	con_init_p[SYS_CON_NUM];

u_char	sys_9798_yx[SYS_9798_YX_NUM];
int		sys_9798_yx_on[SYS_9798_YX_NUM]={0,0,0,0};	
int		sys_9798_yx_off[SYS_9798_YX_NUM]={0,0,0,0};	
struct	SYS_CONSOLE_INDEX_LIST_DATA	sys_console_list_data;

int		sys_ccub_valid_flag;
time_t	sys_soft_timer_second;
int		sys_soft_timer_msecond;

//struct	PRINT_CHAIN_BUF	*sys_send_buf_head;
//int	  	sys_unsend_bytes_count;
//SEM_ID	sys_debug_printf_SEM;
//u_char	sys_print_level;
u_char	sys_print_console_ready;

int		sys_ccub_hardware_state;	/*added by wwl:5/27/2006 4:12PM*/
int	  sys_nas_valid=0;     /*网络存储器投入*/
int	  sys_task_watchdog_start=0;     /*任务监视启动标志*/
int	  sys_task_watchdog_count=0;     /*任务监视超时计数*/
int   iec61850sDebug;

struct SYS_GD_JHQX_STRUCT sys_gd_jhqx;

struct SYS_RLL_STRUCT sysrll[SYS_RLL_MAX];

#endif

