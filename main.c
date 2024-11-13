#include <stdio.h>
#include <unistd.h>
#include "updata/hmi_updata.h"
#include "hmi/lvgl/lvgl.h"

#include "include/rdb_dispatch.h"
#include "include/rdb_init.h"
#include "include/sys_define.h"
#include "include/sys_func.h"
#include "include/sys_can.h"
#include "include/sys_protocol_interface.h"
#include "hmi/main_lvgl.h"

extern	void *(*protocol_init[SYS_PROT_NUM])(struct SYS_STRSTREAM *strp,int type,u_int	app_id,u_int group_id);
extern void* hmi_updata_init(struct SYS_STRSTREAM* strp, int type, u_int  app_id, u_int group_id);
int main_lvgl(int argc, char* argv);
//static void HMI_timetask(void);

lv_timer_t *t;
//extern void* mdl_gw_DispachP_ext_init(struct SYS_STRSTREAM* strp, int type, u_int  app_id, u_int group_id);

extern int rtcomm_main_in(int argc, char* argv);


void extern_protocol_no_init()
{
	protocol_init[377] = hmi_updata_init;
}

int main(int argc, char* argv)
{
    main_lvgl(argc,argv);
	rtcomm_main_in(argc, argv);

	while(1)
	{
		sleep(1);
	}
	return 0;

}
