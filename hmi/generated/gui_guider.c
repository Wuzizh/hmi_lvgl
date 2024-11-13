/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl/lvgl.h"
#include <stdio.h>
#include <stdlib.h>
#include "gui_guider.h"
#include "custom.h"
#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "gg_external_data.h"
#endif

lv_indev_t *indev_keypad;
lv_group_t *g;
lv_timer_t *t;

void ui_init_style(lv_style_t * style)
{
	if (style->prop_cnt > 1)
		lv_style_reset(style);
	else
		lv_style_init(style);
}

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del)
{
	lv_obj_t * act_scr = lv_scr_act();
	if (auto_del && is_clean) {
		lv_obj_clean(act_scr);
	}
	usleep(1000);
	if (new_scr_del) {
		setup_scr(ui);
	}
	lv_scr_load_anim(*new_scr, anim_type, time, delay, auto_del);
	if(new_scr==ui->main_page)
	{
		lv_event_send(act_scr, LV_EVENT_SCREEN_UNLOAD_START, NULL);
		printf("main_page");
	}
	//*old_scr_del = auto_del;
}

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb)
{
	lv_anim_t anim;
	lv_anim_init(&anim);
	lv_anim_set_var(&anim, var);
	lv_anim_set_exec_cb(&anim, exec_cb);
	lv_anim_set_values(&anim, start_value, end_value);
	lv_anim_set_time(&anim, duration);
	lv_anim_set_delay(&anim, delay);
	lv_anim_set_path_cb(&anim, path_cb);
	lv_anim_set_repeat_count(&anim, repeat_cnt);
	lv_anim_set_repeat_delay(&anim, repeat_delay);
	lv_anim_set_playback_time(&anim, playback_time);
	lv_anim_set_playback_delay(&anim, playback_delay);
	lv_anim_start(&anim);
}

void init_scr_del_flag(lv_ui *ui)
{
  
	ui->main_page_del = true;
	ui->yc_1_del = true;
	ui->yx_1_del = true;
	ui->yk_1_del = true;
	ui->yt_1_del = true;
	ui->cons_1_del = true;
	ui->sys_del = true;
}

void setup_ui(lv_ui *ui)
{
	g=lv_group_create();
	printf("group_create success\n");
	init_scr_del_flag(ui);
	printf("init_sct success\n");
	setup_scr_main_page(ui);
	printf("setup_scr success\n");
	lv_scr_load(ui->main_page);
	printf("lv_scr_load success\n");

	lv_group_add_obj(g,ui->main_page_btn_1);
	lv_group_add_obj(g,ui->main_page_btn_2);
	lv_group_add_obj(g,ui->main_page_btn_3);
	lv_group_add_obj(g,ui->main_page_btn_4);
	lv_group_add_obj(g,ui->main_page_btn_5);
	lv_group_add_obj(g,ui->main_page_btn_6);

}
