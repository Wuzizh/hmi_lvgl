#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include "generated/gui_guider.h"
#include "generated/events_init.h"
#include "generated/widgets_init.h"
#include "generated/custom.h"
#include "../include/rdb_dispatch.h"
#include "../include/rdb_init.h"
#include "../include/sys_define.h"
#include "../include/sys_func.h"
#include "../include/sys_protocol_interface.h"
#include "../include/os_func.h"
#include "../updata/hmi_updata.h"

//#include "sys.h"
char* tmp_yc1;
char* tmp_yc2;
char* tmp_yx1;
char* tmp_yx2;
char* tmp_yk1;
char* tmp_yk2;
char* tmp_yt1;
char* tmp_yt2;
char* tmp_dz1;
char* tmp_dz2;


int hmi_up_init_success;
hmi_updata_struct* updata;
static void HMI_timetask(void);
int main_lvgl(int argc, char* argv);

int cur_page=0;
int yc_page=0;
int yc_last=0;
int yx_page=0;
int yx_last=0;
int yt_page=0;
int yt_last=0;
int yk_page=0;
int yk_last=0;
int dz_page=0;
int dz_last=0;




//hmi_updata_struct* data;
lv_ui guider_ui;
lv_timer_t *t;
//lv_color_t black_color = LV_COLOR_HEX(0x000000);
#define DISP_BUF_SIZE (320 * 240)



int main_lvgl(int argc, char* argv)
{
    hmi_up_init_success=-1;
    tmp_yc1=(char*)calloc(7 * 64, sizeof(char));
	tmp_yc2=(char*)calloc(7 * 64, sizeof(char));
    tmp_yc1="";
    tmp_yc2="";
    tmp_yx1=(char*)calloc(7 * 64, sizeof(char));
	tmp_yx2=(char*)calloc(7 * 64, sizeof(char));
    tmp_yx1="";
    tmp_yx2="";
    tmp_yk1=(char*)calloc(7 * 64, sizeof(char));
	tmp_yk2=(char*)calloc(7 * 64, sizeof(char));
    tmp_yk1="";
    tmp_yk2="";
    tmp_yt1=(char*)calloc(7 * 64, sizeof(char));
	tmp_yt2=(char*)calloc(7 * 64, sizeof(char));
    tmp_yt1="";
    tmp_yt2="";
    tmp_dz1=(char*)calloc(7 * 64, sizeof(char));
	tmp_dz2=(char*)calloc(7 * 64, sizeof(char));
    tmp_dz1="";
    tmp_dz2="";
    int ret;
    lv_init();

    /*Linux frame buffer device init*/
    fbdev_init();


    /*A small buffer for LittlevGL to draw the screen's content*/
    static lv_color_t buf[DISP_BUF_SIZE];

    /*Initialize a descriptor for the buffer*/
    static lv_disp_draw_buf_t disp_buf;
    lv_disp_draw_buf_init(&disp_buf, buf, NULL, DISP_BUF_SIZE);

    /*Initialize and register a display driver*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf   = &disp_buf;
    disp_drv.flush_cb   = fbdev_flush;
    disp_drv.hor_res    = 320;
    disp_drv.ver_res    = 240;
    lv_disp_drv_register(&disp_drv);

    lv_port_indev_init();
    printf("port_indev_init success\n");
    lv_obj_set_style_bg_color(lv_scr_act(),lv_color_hex(0x000000), LV_PART_MAIN);  
    printf("obj_set_style_bg_color success\n");
    evdev_init();
    printf("evdev_init success\n");
    static lv_indev_drv_t indev_drv_1;
    lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
    printf("indev_drv_init success\n");
    indev_drv_1.type = LV_INDEV_TYPE_POINTER;

    setup_ui(&guider_ui);
    printf("setup_ui success\n");
    custom_init(&guider_ui);
    printf("custom init success\n");
    events_init(&guider_ui);
    printf("events_init success\n");
    custom_init(&guider_ui);

    ret = sys_thread_creat((void*)&HMI_timetask, t, 200000, PTHREAD_PRIORITY);
    if (ret < 0)
    {
        printf("[HMI对上]:CREAT THREAD failed\n");
        sys_exitpro();
    }
    else{
        printf("[HMI对上]:CREAT THREAD SUCCESSFUL\n.");
    }

    return 0;
}
int re=0;
static void HMI_timetask(void)
{
    while (1)
    {
        lv_timer_handler(); 
        if(hmi_up_init_success==1)
        {
            updata = get_hmi_data();
            yc_page=updata->num_Ycc/7;
            {
                if(updata->num_Ycc%7!=0)
                {
                    yc_last=updata->num_Ycc%7;
                }
                else
                {
                    yc_page--;
                }
            }
            yk_page=updata->num_Yk/7;
            {
                if(updata->num_Yk%7!=0)
                {
                    yk_last=updata->num_Yk%7;
                }
                else
                {
                    yk_page--;
                }
            }
            yx_page=updata->num_Yx/7;
            {
                if(updata->num_Yx%7!=0)
                {
                    yx_last=updata->num_Yx%7;
                }
                else
                {
                    yx_page--;
                }
            }
            yt_page=updata->num_Yt/7;
            {
                if(updata->num_Yt%7!=0)
                {
                    yt_last=updata->num_Yt%7;
                }
                else
                {
                    yt_page--;
                }
            }
            dz_page=updata->num_Yx_S/7;
            {
                if(updata->num_Yx_S%7!=0)
                {
                    dz_page=updata->num_Yx_S%7;
                }
                else
                {
                    dz_page--;
                }
            }
        } 
        
        usleep(5000);
    }
}   


/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`*/
uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}


