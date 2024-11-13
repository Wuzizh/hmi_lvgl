

#ifndef	_RDB_DISPATCH_H_
#define	_RDB_DISPATCH_H_
//
//#include "../sys_function/sys_define.h"
//#include "../sys_function/sys_extern.h"
//#include "../mdl_softbus/softbus.h"
//#include "../sys_function/sys_asdu.h"
//#include "../sys_function/sys_function.h"
//#include "mdl_rdb_define.h"  
//#include "mdl_rdb_extern.h"  
//#include "mdl_rdb.h"


#include "sys_extern.h"
#include "sys_asdu.h"
#include "rdb_itf.h"
#include "softbus.h"
#include "sys_func.h"
#include "os_func.h"

//#include "rdb_define.h"
#include "rdb_extern.h"


#undef _DISPATCH_DEBBUG_

#define  TIMETOLIVE         20        /*命令超时时间*/

enum  {GENERICFUNC=1,REMOTECTRL,REMOTETUNE,ORDINARYCMD,REMOTETRY};

struct  SOCKET_CHAIN
{
    struct  SOCKET_CHAIN * prev;
    struct  SOCKET_CHAIN * next;
    u_int   app_id;                         
    u_int   task_id;
    u_int   object_id;
    u_short factory_addr;
    u_short dev_addr;
    u_char  cpu_no;
    u_char  sec_no;
    u_char  cpu_old;
    u_char  asdu_type;
    u_char  address;
    //u_char  fun;
    //u_char  inf;
	u_char  GIN[2];
    u_char  rii;
    u_char  type;
    u_char  GDD[3];
    u_char  GID[20];
    time_t  timeout;
    time_t  pre_time;
};

struct  DEV_MSG_CHAIN               /*装置消息结构*/
{
    struct  DEV_MSG_CHAIN * next;
    u_int app_id;
    u_int task_id;
    u_short dev_addr;
    u_char type;                      /*接受遥控类型 0:asdu10   1:asdu64 */
    u_char group_map;									/*修改定值的映射组号*/
};

struct SET_TIME_CHAIN
{
    struct  SET_TIME_CHAIN *next;
    u_int   app_id;
    u_int   task_id;
    int     msg_type;
    int     msg_id;
    int     pipe_num;
    int     max_msg_length;
};
//
//struct RDB_DISPATCH_STR
//{
//    int     dispatch_top_id;
//    int     dispatch_bottom_id;
//    int     dispatch_other_id;
//    
//    sem_t   *p_local_socket_lock_id;
//    int     period_hook_timer;
//    int     socket_check_timer;
//    int     exp_cal_timer;
//    int     set_check_timer;
//    
//    int     update_flag;
//    int     update_set_fig;
//    int     rdb_update_set_value_dev_no;
//    int     rdb_update_set_value_group_no;
//    
//    struct  DEV_MSG_CHAIN *dev_msg_head;
//    struct  SET_TIME_CHAIN  *set_time_head;
//    struct  SOCKET_CHAIN *socket_first;
//    
//    int     (*disp_table_top[256])(u_int appid,u_int taskid,u_int object_id,u_short length,u_char *buf);
//    void    (*disp_table_bottom[256])(u_short length,u_char *buf);
//};

extern struct  RDB_DISPATCH_STR    *Rdb_dispatch_p;

void  rdb_init_dispatch(void);
void  check_hooks(struct ELEMENT *item,struct GDD_GID *datap,u_char type);
void  yx_soe(u_short dev_addr,u_char group,u_char entry,u_char state,int time);
int   send_SB_msg(u_int app_id,u_int task_id,u_short len,u_char *buf);
int send_SB_YKmsg(u_short dev_addr,u_char *buf,u_char type);
void regiseter_set_time_msg(u_int app_id,u_int task_id,int  msg_type,int  msg_id,int pipe_num,int  max_msg_length);
void send_time_to_all_protocol(void);
void  hook_set_change_data(struct ELEMENT *item,struct GDD_GID *datap,u_char type);
u_char  compare_time(int last_time, int current_time, int compare_value);
int send_msg_to_dev(u_short dev_addr, u_char *buf, u_int  length);
void  rdb_proc_registerDevMsg(SB_HEAD *sb_head, u_int app_id, u_int task_id, u_short dev_addr, u_char type);


#endif
