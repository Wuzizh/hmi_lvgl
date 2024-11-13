/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iconv.h>
#include "lvgl/lvgl.h"
#include "../../updata/hmi_updata.h"
#include "custom.h"
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "key.h"
#include "../lvgl/examples/porting/lv_port_indev.h"

hmi_key_t hmi_key; 
lv_font_t lv_font_A85_16;
uint32_t act_key;
uint32_t last_key;
char* yc_Tmp;
char* yc_buf;
char* yx_Tmp;
char* yx_buf;
char* yk_Tmp;
char* yk_buf;
char* yt_Tmp;
char* yt_buf;
char* dz_Tmp;
char* dz_buf;
extern char* tmp_yc1;
extern char* tmp_yc2;
extern char* tmp_yk1;
extern char* tmp_yk2;
extern char* tmp_yt1;
extern char* tmp_yt2;
extern char* tmp_yx1;
extern char* tmp_yx2;
extern char* tmp_dz1;
extern char* tmp_dz2;
extern int cur_page;
extern int yc_page;
extern int yc_last;
extern int yk_page;
extern int yk_last;
extern int yt_page;
extern int yt_last;
extern int yx_page;
extern int yx_last;
extern int dz_page;
extern int dz_last;
lv_timer_t *t;
lv_timer_t * t1;
extern int hmi_up_init_success;
extern hmi_updata_struct* updata;
hmi_updata_struct *hmi_up;
lv_ui *ui;
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
	dz_Tmp=(char*)calloc(7 * 64, sizeof(char));
	dz_buf=(char*)calloc(7 * 64, sizeof(char));
	yc_Tmp=(char*)calloc(7 * 64, sizeof(char));
	yc_buf=(char*)calloc(7 * 64, sizeof(char));
	yk_Tmp=(char*)calloc(7 * 64, sizeof(char));
	yk_buf=(char*)calloc(7 * 64, sizeof(char));
	yt_Tmp=(char*)calloc(7 * 64, sizeof(char));
	yt_buf=(char*)calloc(7 * 64, sizeof(char));
	yx_Tmp=(char*)calloc(7 * 64, sizeof(char));
	yx_buf=(char*)calloc(7 * 64, sizeof(char));

}




void dis_name_unit_yc(lv_timer_t *t)
{
	if(hmi_up_init_success==1)
	{
		if(lv_obj_is_valid(guider_ui.yc_1_data_1))
		{
			if(cur_page!=yc_page)
			{			
				for(int kk=0;kk<7;kk++)
				{
					strcpy(kk*64+yc_Tmp,updata->name_Ycc+64*(kk+cur_page*7));
					snprintf(yc_buf+kk*64, 64, "%.2f", updata->buf_Ycc[kk+cur_page*7]);
					strcat(yc_buf+kk*64, updata->unit_Ycc+64*(kk+cur_page*7));
				}
			}
			else
			{
				for(int kk=0;kk<7;kk++)
				{
					if(kk<yc_last)
					{
						strcpy(kk*64+yc_Tmp,updata->name_Ycc+64*(kk+cur_page*7));
						snprintf(yc_buf+kk*64, 64, "%.2f", updata->buf_Ycc[kk+cur_page*7]);
						strcat(yc_buf+kk*64, updata->unit_Ycc+64*(kk+cur_page*7));
					}
					else
					{
						strcpy(kk*64+yc_Tmp," ");	
						strcpy(kk*64+yc_buf," ");
					}
				}
			}
			char utf[64];
			convert_gb2312_to_utf8(yc_Tmp,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yc_1_label_1,utf);
			lv_obj_set_style_text_font(guider_ui.yc_1_label_1, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yc_Tmp+64,utf,sizeof(utf));			
			lv_label_set_text(guider_ui.yc_1_label_2,utf);
			lv_obj_set_style_text_font(guider_ui.yc_1_label_2, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yc_Tmp+64*2,utf,sizeof(utf));	
			lv_label_set_text(guider_ui.yc_1_label_3,utf);
			lv_obj_set_style_text_font(guider_ui.yc_1_label_3, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yc_Tmp+64*3,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yc_1_label_4,utf);
			lv_obj_set_style_text_font(guider_ui.yc_1_label_4, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yc_Tmp+64*4,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yc_1_label_5,utf);
			lv_obj_set_style_text_font(guider_ui.yc_1_label_5, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yc_Tmp+64*5,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yc_1_label_6,utf);
			lv_obj_set_style_text_font(guider_ui.yc_1_label_6, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yc_Tmp+64*6,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yc_1_label_7,utf);
			lv_obj_set_style_text_font(guider_ui.yc_1_label_7, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);


			convert_gb2312_to_utf8(yc_buf,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yc_1_data_1,utf);
			lv_obj_set_style_text_font(guider_ui.yc_1_data_1, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yc_buf+64,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yc_1_data_2,utf);
			lv_obj_set_style_text_font(guider_ui.yc_1_data_2, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yc_buf+64*2,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yc_1_data_3,utf);
			lv_obj_set_style_text_font(guider_ui.yc_1_data_3, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yc_buf+64*3,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yc_1_data_4,utf);
			lv_obj_set_style_text_font(guider_ui.yc_1_data_4, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yc_buf+64*4,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yc_1_data_5,utf);
			lv_obj_set_style_text_font(guider_ui.yc_1_data_5, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yc_buf+64*5,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yc_1_data_6,utf);
			lv_obj_set_style_text_font(guider_ui.yc_1_data_6, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yc_buf+64*6,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yc_1_data_7,utf);
			lv_obj_set_style_text_font(guider_ui.yc_1_data_7, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			strcpy(yc_Tmp,tmp_yc1);	
			strcpy(yc_buf,tmp_yc2);

		}
	}
}
void dis_name_unit_yk(lv_timer_t *t)
{

	if(hmi_up_init_success==1)
	{
		if(lv_obj_is_valid(guider_ui.yk_1_data_1))
		{
			if(cur_page!=yk_page)
			{			
				for(int kk=0;kk<7;kk++)
				{

					strcpy(kk*64+yk_Tmp,updata->name_Yk+64*(kk+cur_page*7));
					if(updata->buf_Yk[kk+cur_page*7]==1.0)
					{
						strcpy(yk_buf+kk*64,"ON");
					}
					else
					{
						strcpy(yk_buf+kk*64,"OFF");	
					}
				}
			}
			else
			{
				for(int kk=0;kk<7;kk++)
				{
					if(kk<yk_last)
					{
						strcpy(kk*64+yk_Tmp,updata->name_Yk+64*(kk+cur_page*7));
						if(updata->buf_Yk[kk+cur_page*7]==1.0)
						{
							strcpy(yk_buf+kk*64,"ON");
						}
						else
						{
							strcpy(yk_buf+kk*64,"OFF");	
						}
					}
					else
					{
						strcpy(kk*64+yk_Tmp," ");	
						strcpy(kk*64+yk_buf," ");
					}
				}
			}
			char utf[64];
			convert_gb2312_to_utf8(yk_Tmp,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yk_1_label_1,utf);
			lv_obj_set_style_text_font(guider_ui.yk_1_label_1, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yk_Tmp+64,utf,sizeof(utf));			
			lv_label_set_text(guider_ui.yk_1_label_2,utf);
			lv_obj_set_style_text_font(guider_ui.yk_1_label_2, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yk_Tmp+64*2,utf,sizeof(utf));	
			lv_label_set_text(guider_ui.yk_1_label_3,utf);
			lv_obj_set_style_text_font(guider_ui.yk_1_label_3, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yk_Tmp+64*3,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yk_1_label_4,utf);
			lv_obj_set_style_text_font(guider_ui.yk_1_label_4, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yk_Tmp+64*4,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yk_1_label_5,utf);
			lv_obj_set_style_text_font(guider_ui.yk_1_label_5, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yk_Tmp+64*5,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yk_1_label_6,utf);
			lv_obj_set_style_text_font(guider_ui.yk_1_label_6, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yk_Tmp+64*6,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yk_1_label_7,utf);
			lv_obj_set_style_text_font(guider_ui.yk_1_label_7, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);


			convert_gb2312_to_utf8(yk_buf,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yk_1_data_1,utf);
			lv_obj_set_style_text_font(guider_ui.yk_1_data_1, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yk_buf+64,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yk_1_data_2,utf);
			lv_obj_set_style_text_font(guider_ui.yk_1_data_2, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yk_buf+64*2,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yk_1_data_3,utf);
			lv_obj_set_style_text_font(guider_ui.yk_1_data_3, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yk_buf+64*3,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yk_1_data_4,utf);
			lv_obj_set_style_text_font(guider_ui.yk_1_data_4, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yk_buf+64*4,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yk_1_data_5,utf);
			lv_obj_set_style_text_font(guider_ui.yk_1_data_5, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yk_buf+64*5,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yk_1_data_6,utf);
			lv_obj_set_style_text_font(guider_ui.yk_1_data_6, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yk_buf+64*6,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yk_1_data_7,utf);
			lv_obj_set_style_text_font(guider_ui.yk_1_data_7, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			strcpy(yk_Tmp,tmp_yk1);	
			strcpy(yk_buf,tmp_yk2);

		}
	}

}
void dis_name_unit_yt(lv_timer_t *t)
{
	if(hmi_up_init_success==1)
	{
		if(lv_obj_is_valid(guider_ui.yt_1_data_1))
		{
			if(cur_page!=yt_page)
			{			
				for(int kk=0;kk<7;kk++)
				{
					strcpy(kk*64+yt_Tmp,updata->name_Yt+64*(kk+cur_page*7));
					snprintf(yt_buf+kk*64, 64, "%.2f", updata->buf_Yt[kk+cur_page*7]);
					strcat(yt_buf+kk*64, updata->unit_Yt+64*(kk+cur_page*7));
				}
			}
			else
			{
				for(int kk=0;kk<7;kk++)
				{
					if(kk<yt_last)
					{
						strcpy(kk*64+yt_Tmp,updata->name_Yt+64*(kk+cur_page*7));
						snprintf(yt_buf+kk*64, 64, "%.2f", updata->buf_Yt[kk+cur_page*7]);
						strcat(yt_buf+kk*64, updata->unit_Yt+64*(kk+cur_page*7));
					}
					else
					{
						strcpy(kk*64+yt_Tmp," ");	
						strcpy(kk*64+yt_buf," ");
					}
				}
			}
			char utf[64];
			convert_gb2312_to_utf8(yt_Tmp,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yt_1_label_1,utf);
			lv_obj_set_style_text_font(guider_ui.yt_1_label_1, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yt_Tmp+64,utf,sizeof(utf));			
			lv_label_set_text(guider_ui.yt_1_label_2,utf);
			lv_obj_set_style_text_font(guider_ui.yt_1_label_2, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yt_Tmp+64*2,utf,sizeof(utf));	
			lv_label_set_text(guider_ui.yt_1_label_3,utf);
			lv_obj_set_style_text_font(guider_ui.yt_1_label_3, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yt_Tmp+64*3,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yt_1_label_4,utf);
			lv_obj_set_style_text_font(guider_ui.yt_1_label_4, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yt_Tmp+64*4,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yt_1_label_5,utf);
			lv_obj_set_style_text_font(guider_ui.yt_1_label_5, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yt_Tmp+64*5,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yt_1_label_6,utf);
			lv_obj_set_style_text_font(guider_ui.yt_1_label_6, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yt_Tmp+64*6,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yt_1_label_7,utf);
			lv_obj_set_style_text_font(guider_ui.yt_1_label_7, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);


			convert_gb2312_to_utf8(yt_buf,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yt_1_data_1,utf);
			lv_obj_set_style_text_font(guider_ui.yt_1_data_1, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yt_buf+64,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yt_1_data_2,utf);
			lv_obj_set_style_text_font(guider_ui.yt_1_data_2, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yt_buf+64*2,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yt_1_data_3,utf);
			lv_obj_set_style_text_font(guider_ui.yt_1_data_3, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yt_buf+64*3,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yt_1_data_4,utf);
			lv_obj_set_style_text_font(guider_ui.yt_1_data_4, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yt_buf+64*4,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yt_1_data_5,utf);
			lv_obj_set_style_text_font(guider_ui.yt_1_data_5, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yt_buf+64*5,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yt_1_data_6,utf);
			lv_obj_set_style_text_font(guider_ui.yt_1_data_6, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yt_buf+64*6,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yt_1_data_7,utf);
			lv_obj_set_style_text_font(guider_ui.yt_1_data_7, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			strcpy(yt_Tmp,tmp_yt1);	
			strcpy(yt_buf,tmp_yt2);

		}
	}

}
void dis_name_unit_yx(lv_timer_t *t)
{
	if(hmi_up_init_success==1)
	{
		if(lv_obj_is_valid(guider_ui.yx_1_data_1))
		{
			printf("create page\n");
			if(cur_page!=yx_page)
			{			
				for(int kk=0;kk<7;kk++)
				{
					printf("kk=%d\n",kk);
					printf("cur_page=%d\n",cur_page);
					strcpy(kk*64+yx_Tmp,updata->name_Yx+64*(kk+cur_page*7));
					printf("strcpy\n");
					if(updata->buf_Yx[kk+cur_page*7]==1.0)
					{
						printf("ON\n");
						strcpy(yx_buf+kk*64,"ON");
						printf("ON1\n");
					}
					else
					{
						printf("OFF\n");
						strcpy(yx_buf+kk*64,"OFF");
						printf("OFF1\n");
					}
					
				}
			}
			else
			{
				for(int kk=0;kk<7;kk++)
				{
					if(kk<yx_last)
					{
						strcpy(kk*64+yx_Tmp,updata->name_Yx+64*(kk+cur_page*7));
						if(updata->buf_Yx[kk+cur_page*7]==1.0)
						{
							strcpy(yx_buf+kk*64,"ON");
						}
						else
						{
							strcpy(yx_buf+kk*64,"OFF");
						}
					}
					else
					{
						strcpy(kk*64+yx_Tmp," ");	
						strcpy(kk*64+yx_buf," ");
					}
				}
			}
			printf("data is ready\n");
			char utf[64];
			convert_gb2312_to_utf8(yx_Tmp,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yx_1_label_1,utf);
			lv_obj_set_style_text_font(guider_ui.yx_1_label_1, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yx_Tmp+64,utf,sizeof(utf));			
			lv_label_set_text(guider_ui.yx_1_label_2,utf);
			lv_obj_set_style_text_font(guider_ui.yx_1_label_2, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yx_Tmp+64*2,utf,sizeof(utf));	
			lv_label_set_text(guider_ui.yx_1_label_3,utf);
			lv_obj_set_style_text_font(guider_ui.yx_1_label_3, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yx_Tmp+64*3,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yx_1_label_4,utf);
			lv_obj_set_style_text_font(guider_ui.yx_1_label_4, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yx_Tmp+64*4,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yx_1_label_5,utf);
			lv_obj_set_style_text_font(guider_ui.yx_1_label_5, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yx_Tmp+64*5,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yx_1_label_6,utf);
			lv_obj_set_style_text_font(guider_ui.yx_1_label_6, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yx_Tmp+64*6,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yx_1_label_7,utf);
			lv_obj_set_style_text_font(guider_ui.yx_1_label_7, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);



			convert_gb2312_to_utf8(yx_buf,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yx_1_data_1,utf);
			lv_obj_set_style_text_font(guider_ui.yx_1_data_1, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yx_buf+64,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yx_1_data_2,utf);
			lv_obj_set_style_text_font(guider_ui.yx_1_data_2, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yx_buf+64*2,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yx_1_data_3,utf);
			lv_obj_set_style_text_font(guider_ui.yx_1_data_3, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yx_buf+64*3,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yx_1_data_4,utf);
			lv_obj_set_style_text_font(guider_ui.yx_1_data_4, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yx_buf+64*4,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yx_1_data_5,utf);
			lv_obj_set_style_text_font(guider_ui.yx_1_data_5, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yx_buf+64*5,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yx_1_data_6,utf);
			lv_obj_set_style_text_font(guider_ui.yx_1_data_6, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(yx_buf+64*6,utf,sizeof(utf));
			lv_label_set_text(guider_ui.yx_1_data_7,utf);
			lv_obj_set_style_text_font(guider_ui.yx_1_data_7, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);

			strcpy(yx_Tmp,tmp_yx1);	
			strcpy(yx_buf,tmp_yx2);

		}
	}

}
void dis_name_unit_dz(lv_timer_t *t)
{
	if(hmi_up_init_success==1)
	{
		if(lv_obj_is_valid(guider_ui.cons_1_data_1))
		{
			if(cur_page!=dz_page)
			{			
				for(int kk=0;kk<7;kk++)
				{
					strcpy(kk*64+dz_Tmp,updata->name_Yx_S+64*(kk+cur_page*7));
					snprintf(dz_buf+kk*64, 64, "%.2f", updata->buf_Yx_S[kk+cur_page*7]);
					strcat(dz_buf+kk*64, updata->unit_Yx_S+64*(kk+cur_page*7));
				}
			}
			else
			{
				for(int kk=0;kk<7;kk++)
				{
					if(kk<dz_last)
					{
						strcpy(kk*64+dz_Tmp,updata->name_Yx_S+64*(kk+cur_page*7));
						snprintf(dz_buf+kk*64, 64, "%.2f", updata->buf_Yx_S[kk+cur_page*7]);
						strcat(dz_buf+kk*64, updata->unit_Yx_S+64*(kk+cur_page*7));
					}
					else
					{
						strcpy(kk*64+dz_Tmp," ");	
						strcpy(kk*64+dz_buf," ");
					}
				}
			}
			char utf[64];
			convert_gb2312_to_utf8(dz_Tmp,utf,sizeof(utf));
			lv_label_set_text(guider_ui.cons_1_label_1,utf);
			lv_obj_set_style_text_font(guider_ui.cons_1_label_1, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(dz_Tmp+64,utf,sizeof(utf));			
			lv_label_set_text(guider_ui.cons_1_label_2,utf);
			lv_obj_set_style_text_font(guider_ui.cons_1_label_2, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(dz_Tmp+64*2,utf,sizeof(utf));	
			lv_label_set_text(guider_ui.cons_1_label_3,utf);
			lv_obj_set_style_text_font(guider_ui.cons_1_label_3, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(dz_Tmp+64*3,utf,sizeof(utf));
			lv_label_set_text(guider_ui.cons_1_label_4,utf);
			lv_obj_set_style_text_font(guider_ui.cons_1_label_4, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(dz_Tmp+64*4,utf,sizeof(utf));
			lv_label_set_text(guider_ui.cons_1_label_5,utf);
			lv_obj_set_style_text_font(guider_ui.cons_1_label_5, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(dz_Tmp+64*5,utf,sizeof(utf));
			lv_label_set_text(guider_ui.cons_1_label_6,utf);
			lv_obj_set_style_text_font(guider_ui.cons_1_label_6, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			convert_gb2312_to_utf8(dz_Tmp+64*6,utf,sizeof(utf));
			lv_label_set_text(guider_ui.cons_1_label_7,utf);
			lv_obj_set_style_text_font(guider_ui.cons_1_label_7, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
		}
	}

}

void convert_gb2312_to_utf8(const char *input, char *output, size_t output_size) {
    iconv_t cd = iconv_open("UTF-8", "GB2312");
    if (cd == (iconv_t)-1) {
        perror("iconv_open");
        return;
    }

    char *inbuf = (char *)input;
    size_t inbytesleft = strlen(input);
    char *outbuf = output;
    size_t outbytesleft = output_size;

    // 清空输出缓冲区
    memset(output, 0, output_size);

    size_t result = iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);
    if (result == (size_t)-1) {
        perror("iconv");
    }

    iconv_close(cd);
}
void key_event_key_yc(lv_timer_t * t1)
{
	act_key = keypad_get_key();
	if(act_key!=last_key){
	switch(act_key) {
    case HMI_KEY_OTHER:
		printf("HMI_KEY_OTHER\n");
        if(lv_obj_is_valid(guider_ui.yc_1))
		{
			lv_event_send(guider_ui.yc_1_btn_1, LV_EVENT_CLICKED, NULL);
			last_key=act_key;
		}
		else {
        	printf("Button object is invalid or NULL\n");
        }
		act_key=0;
		break;
	case HMI_KEY_UP:
		printf("HMI_KEY_UP\n");
	    if(lv_obj_is_valid(guider_ui.yc_1))
		{
			last_key=act_key;
			lv_event_send(guider_ui.yc_1_btn_2, LV_EVENT_CLICKED, NULL);
			lv_timer_del(t1);
			t1=NULL;	
		}
		else {
        	printf("Button object is invalid or NULL\n");
        }
		act_key=0;
		break;
	case HMI_KEY_DOWN:
		printf("HMI_KEY_DOWN\n");
	    if(lv_obj_is_valid(guider_ui.yc_1))
		{
			last_key=act_key;
			lv_event_send(guider_ui.yc_1_btn_3, LV_EVENT_CLICKED, NULL);
			lv_timer_del(t1);
			t1=NULL;
			
		}
		else {
        	printf("Button object is invalid or NULL\n");
        }
		act_key=0;
		break;
	default:
		printf("NO input\n");
		last_key=0;
		break;
	}
	}
	else{
		if(last_key==260)
		{
			last_key=0;
		}
		printf("No act\n");
	}
}

void key_event_key_yk(lv_timer_t * t1)
{
	act_key = keypad_get_key();
	if(act_key!=last_key){
	switch(act_key) {
    case HMI_KEY_OTHER:
		printf("HMI_KEY_OTHER\n");
        if(lv_obj_is_valid(guider_ui.yk_1))
		{
			lv_event_send(guider_ui.yk_1_btn_1, LV_EVENT_CLICKED, NULL);
			last_key=act_key;
		}
		else {
        	printf("Button object is invalid or NULL\n");
        }
		act_key=0;
		break;
	case HMI_KEY_UP:
		printf("HMI_KEY_UP\n");
	    if(lv_obj_is_valid(guider_ui.yk_1))
		{
			last_key=act_key;
			lv_event_send(guider_ui.yk_1_btn_2, LV_EVENT_CLICKED, NULL);
			lv_timer_del(t1);
			t1=NULL;	
		}
		else {
        	printf("Button object is invalid or NULL\n");
        }
		act_key=0;
		break;
	case HMI_KEY_DOWN:
		printf("HMI_KEY_DOWN\n");
	    if(lv_obj_is_valid(guider_ui.yk_1))
		{
			last_key=act_key;
			lv_event_send(guider_ui.yk_1_btn_3, LV_EVENT_CLICKED, NULL);
			lv_timer_del(t1);
			t1=NULL;
			
		}
		else {
        	printf("Button object is invalid or NULL\n");
        }
		act_key=0;
		break;
	default:
		printf("NO input\n");
		last_key=0;
		break;
	}
	}
	else{
		if(last_key==260)
		{
			last_key=0;
		}
		printf("No act\n");
	}
}

void key_event_key_yt(lv_timer_t * t1)
{
	act_key = keypad_get_key();
	if(act_key!=last_key){
	switch(act_key) {
    case HMI_KEY_OTHER:
		printf("HMI_KEY_OTHER\n");
        if(lv_obj_is_valid(guider_ui.yt_1))
		{
			lv_event_send(guider_ui.yt_1_btn_1, LV_EVENT_CLICKED, NULL);
			printf("guider_ui.yt_1_btn_1\n");

			last_key=act_key;
		}
		else {
        	printf("Button object is invalid or NULL\n");
        }
		act_key=0;
		break;
	case HMI_KEY_UP:
		printf("HMI_KEY_UP\n");
	    if(lv_obj_is_valid(guider_ui.yt_1))
		{
			last_key=act_key;
			lv_event_send(guider_ui.yt_1_btn_2, LV_EVENT_CLICKED, NULL);
			lv_timer_del(t1);
			t1=NULL;	
		}
		else {
        	printf("Button object is invalid or NULL\n");
        }
		act_key=0;
		break;
	case HMI_KEY_DOWN:
		printf("HMI_KEY_DOWN\n");
	    if(lv_obj_is_valid(guider_ui.yt_1))
		{
			last_key=act_key;
			lv_event_send(guider_ui.yt_1_btn_3, LV_EVENT_CLICKED, NULL);
			lv_timer_del(t1);
			t1=NULL;
			
		}
		else {
        	printf("Button object is invalid or NULL\n");
        }
		act_key=0;
		break;
	default:
		printf("NO input\n");
		last_key=0;
		break;
	}
	}
	else{
		if(last_key==260)
		{
			last_key=0;
		}
		printf("No act\n");
	}
}

void key_event_key_yx(lv_timer_t * t1)
{
	act_key = keypad_get_key();
	if(act_key!=last_key){
	switch(act_key) {
    case HMI_KEY_OTHER:
		printf("HMI_KEY_OTHER\n");
        if(lv_obj_is_valid(guider_ui.yx_1))
		{
			lv_event_send(guider_ui.yx_1_btn_1, LV_EVENT_CLICKED, NULL);
			printf("guider_ui.yx_1_btn_1\n");
			last_key=act_key;
		}
		else {
        	printf("Button object is invalid or NULL\n");
        }
		act_key=0;
		break;
	case HMI_KEY_UP:
		printf("HMI_KEY_UP\n");
	    if(lv_obj_is_valid(guider_ui.yx_1))
		{
			last_key=act_key;
			lv_event_send(guider_ui.yx_1_btn_2, LV_EVENT_CLICKED, NULL);
			lv_timer_del(t1);
			t1=NULL;	
		}
		else {
        	printf("Button object is invalid or NULL\n");
        }
		act_key=0;
		break;
	case HMI_KEY_DOWN:
		printf("HMI_KEY_DOWN\n");
	    if(lv_obj_is_valid(guider_ui.yx_1))
		{
			last_key=act_key;
			lv_event_send(guider_ui.yx_1_btn_3, LV_EVENT_CLICKED, NULL);
			lv_timer_del(t1);
			t1=NULL;
			
		}
		else {
        	printf("Button object is invalid or NULL\n");
        }
		act_key=0;
		break;
	default:
		printf("NO input\n");
		last_key=0;
		break;
	}
	}
	else{
		if(last_key==260)
		{
			last_key=0;
		}
		printf("No act\n");
	}
}

void key_event_key_dz(lv_timer_t * t1)
{
	act_key = keypad_get_key();
	if(act_key!=last_key){
	switch(act_key) {
    case HMI_KEY_OTHER:
		printf("HMI_KEY_OTHER\n");
        if(lv_obj_is_valid(guider_ui.cons_1))
		{
			lv_event_send(guider_ui.cons_1_btn_1, LV_EVENT_CLICKED, NULL);
			last_key=act_key;
		}
		else {
        	printf("Button object is invalid or NULL\n");
        }
		act_key=0;
		break;
	case HMI_KEY_UP:
		printf("HMI_KEY_UP\n");
	    if(lv_obj_is_valid(guider_ui.cons_1))
		{
			last_key=act_key;
			lv_event_send(guider_ui.cons_1_btn_2, LV_EVENT_CLICKED, NULL);
			lv_timer_del(t1);
			t1=NULL;	
		}
		else {
        	printf("Button object is invalid or NULL\n");
        }
		act_key=0;
		break;
	case HMI_KEY_DOWN:
		printf("HMI_KEY_DOWN\n");
	    if(lv_obj_is_valid(guider_ui.cons_1))
		{
			last_key=act_key;
			lv_event_send(guider_ui.cons_1_btn_3, LV_EVENT_CLICKED, NULL);
			lv_timer_del(t1);
			t1=NULL;
			
		}
		else {
        	printf("Button object is invalid or NULL\n");
        }
		act_key=0;
		break;
	default:
		printf("NO input\n");
		last_key=0;
		break;
	}
	}
	else{
		if(last_key==260)
		{
			last_key=0;
		}
		printf("No act\n");
	}
}