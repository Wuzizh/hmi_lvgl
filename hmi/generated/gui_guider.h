/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

typedef struct
{
  
	lv_obj_t *main_page;
	bool main_page_del;
	lv_obj_t *main_page_time;
	lv_obj_t *main_page_warning;
	lv_obj_t *main_page_state;
	lv_obj_t *main_page_model;
	lv_obj_t *main_page_label_5;
	lv_obj_t *main_page_label_6;
	lv_obj_t *main_page_label_7;
	lv_obj_t *main_page_label_10;
	lv_obj_t *main_page_label_9;
	lv_obj_t *main_page_label_8;
	lv_obj_t *main_page_img_6;
	lv_obj_t *main_page_img_5;
	lv_obj_t *main_page_img_4;
	lv_obj_t *main_page_img_3;
	lv_obj_t *main_page_img_2;
	lv_obj_t *main_page_img_1;
	lv_obj_t *main_page_btn_6;
	lv_obj_t *main_page_btn_6_label;
	lv_obj_t *main_page_btn_5;
	lv_obj_t *main_page_btn_5_label;
	lv_obj_t *main_page_btn_4;
	lv_obj_t *main_page_btn_4_label;
	lv_obj_t *main_page_btn_3;
	lv_obj_t *main_page_btn_3_label;
	lv_obj_t *main_page_btn_2;
	lv_obj_t *main_page_btn_2_label;
	lv_obj_t *main_page_btn_1;
	lv_obj_t *main_page_btn_1_label;
	lv_obj_t *yc_1;
	bool yc_1_del;
	lv_obj_t *yc_1_data_7;
	lv_obj_t *yc_1_data_6;
	lv_obj_t *yc_1_data_5;
	lv_obj_t *yc_1_data_4;
	lv_obj_t *yc_1_data_3;
	lv_obj_t *yc_1_data_2;
	lv_obj_t *yc_1_data_1;
	lv_obj_t *yc_1_label_7;
	lv_obj_t *yc_1_label_6;
	lv_obj_t *yc_1_label_5;
	lv_obj_t *yc_1_label_4;
	lv_obj_t *yc_1_label_3;
	lv_obj_t *yc_1_label_2;
	lv_obj_t *yc_1_label_1;
	lv_obj_t *yc_1_btn_3;
	lv_obj_t *yc_1_btn_3_label;
	lv_obj_t *yc_1_btn_2;
	lv_obj_t *yc_1_btn_2_label;
	lv_obj_t *yc_1_btn_1;
	lv_obj_t *yc_1_btn_1_label;
	lv_obj_t *yc_1_warning;
	lv_obj_t *yc_1_state;
	lv_obj_t *yc_1_model;
	lv_obj_t *yc_1_time;
	lv_obj_t *yx_1;
	bool yx_1_del;
	lv_obj_t *yx_1_data_7;
	lv_obj_t *yx_1_data_6;
	lv_obj_t *yx_1_data_5;
	lv_obj_t *yx_1_data_4;
	lv_obj_t *yx_1_data_3;
	lv_obj_t *yx_1_data_2;
	lv_obj_t *yx_1_data_1;
	lv_obj_t *yx_1_label_7;
	lv_obj_t *yx_1_label_6;
	lv_obj_t *yx_1_label_5;
	lv_obj_t *yx_1_label_4;
	lv_obj_t *yx_1_label_3;
	lv_obj_t *yx_1_label_2;
	lv_obj_t *yx_1_label_1;
	lv_obj_t *yx_1_btn_3;
	lv_obj_t *yx_1_btn_3_label;
	lv_obj_t *yx_1_btn_2;
	lv_obj_t *yx_1_btn_2_label;
	lv_obj_t *yx_1_btn_1;
	lv_obj_t *yx_1_btn_1_label;
	lv_obj_t *yx_1_warning;
	lv_obj_t *yx_1_state;
	lv_obj_t *yx_1_model;
	lv_obj_t *yx_1_time;
	lv_obj_t *yk_1;
	bool yk_1_del;
	lv_obj_t *yk_1_data_7;
	lv_obj_t *yk_1_data_6;
	lv_obj_t *yk_1_data_5;
	lv_obj_t *yk_1_data_4;
	lv_obj_t *yk_1_data_3;
	lv_obj_t *yk_1_data_2;
	lv_obj_t *yk_1_data_1;
	lv_obj_t *yk_1_label_7;
	lv_obj_t *yk_1_label_6;
	lv_obj_t *yk_1_label_5;
	lv_obj_t *yk_1_label_4;
	lv_obj_t *yk_1_label_3;
	lv_obj_t *yk_1_label_2;
	lv_obj_t *yk_1_label_1;
	lv_obj_t *yk_1_btn_3;
	lv_obj_t *yk_1_btn_3_label;
	lv_obj_t *yk_1_btn_2;
	lv_obj_t *yk_1_btn_2_label;
	lv_obj_t *yk_1_btn_1;
	lv_obj_t *yk_1_btn_1_label;
	lv_obj_t *yk_1_warning;
	lv_obj_t *yk_1_state;
	lv_obj_t *yk_1_model;
	lv_obj_t *yk_1_time;
	lv_obj_t *yt_1;
	bool yt_1_del;
	lv_obj_t *yt_1_data_7;
	lv_obj_t *yt_1_data_6;
	lv_obj_t *yt_1_data_5;
	lv_obj_t *yt_1_data_4;
	lv_obj_t *yt_1_data_3;
	lv_obj_t *yt_1_data_2;
	lv_obj_t *yt_1_data_1;
	lv_obj_t *yt_1_label_7;
	lv_obj_t *yt_1_label_6;
	lv_obj_t *yt_1_label_5;
	lv_obj_t *yt_1_label_4;
	lv_obj_t *yt_1_label_3;
	lv_obj_t *yt_1_label_2;
	lv_obj_t *yt_1_label_1;
	lv_obj_t *yt_1_btn_3;
	lv_obj_t *yt_1_btn_3_label;
	lv_obj_t *yt_1_btn_2;
	lv_obj_t *yt_1_btn_2_label;
	lv_obj_t *yt_1_btn_1;
	lv_obj_t *yt_1_btn_1_label;
	lv_obj_t *yt_1_warning;
	lv_obj_t *yt_1_state;
	lv_obj_t *yt_1_model;
	lv_obj_t *yt_1_time;
	lv_obj_t *cons_1;
	bool cons_1_del;
	lv_obj_t *cons_1_data_7;
	lv_obj_t *cons_1_data_6;
	lv_obj_t *cons_1_data_5;
	lv_obj_t *cons_1_data_4;
	lv_obj_t *cons_1_data_3;
	lv_obj_t *cons_1_data_2;
	lv_obj_t *cons_1_data_1;
	lv_obj_t *cons_1_label_7;
	lv_obj_t *cons_1_label_6;
	lv_obj_t *cons_1_label_5;
	lv_obj_t *cons_1_label_4;
	lv_obj_t *cons_1_label_3;
	lv_obj_t *cons_1_label_2;
	lv_obj_t *cons_1_label_1;
	lv_obj_t *cons_1_btn_3;
	lv_obj_t *cons_1_btn_3_label;
	lv_obj_t *cons_1_btn_2;
	lv_obj_t *cons_1_btn_2_label;
	lv_obj_t *cons_1_btn_1;
	lv_obj_t *cons_1_btn_1_label;
	lv_obj_t *cons_1_warning;
	lv_obj_t *cons_1_state;
	lv_obj_t *cons_1_model;
	lv_obj_t *cons_1_time;
	lv_obj_t *sys;
	bool sys_del;
	lv_obj_t *sys_data_7;
	lv_obj_t *sys_data_6;
	lv_obj_t *sys_data_5;
	lv_obj_t *sys_data_4;
	lv_obj_t *sys_data_3;
	lv_obj_t *sys_data_2;
	lv_obj_t *sys_data_1;
	lv_obj_t *sys_label_7;
	lv_obj_t *sys_label_6;
	lv_obj_t *sys_label_5;
	lv_obj_t *sys_label_4;
	lv_obj_t *sys_label_3;
	lv_obj_t *sys_label_2;
	lv_obj_t *sys_label_1;
	lv_obj_t *sys_btn_3;
	lv_obj_t *sys_btn_3_label;
	lv_obj_t *sys_btn_2;
	lv_obj_t *sys_btn_2_label;
	lv_obj_t *sys_btn_1;
	lv_obj_t *sys_btn_1_label;
	lv_obj_t *sys_warning;
	lv_obj_t *sys_state;
	lv_obj_t *sys_model;
	lv_obj_t *sys_time;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_main_page(lv_ui *ui);
void setup_scr_yc_1(lv_ui *ui);
void setup_scr_yx_1(lv_ui *ui);
void setup_scr_yk_1(lv_ui *ui);
void setup_scr_yt_1(lv_ui *ui);
void setup_scr_cons_1(lv_ui *ui);
void setup_scr_sys(lv_ui *ui);
LV_IMG_DECLARE(_xt_alpha_55x55);
LV_IMG_DECLARE(_dz_alpha_60x60);
LV_IMG_DECLARE(_telemetry_alpha_55x55);
LV_IMG_DECLARE(_yk_alpha_60x60);
LV_IMG_DECLARE(_yx_alpha_55x55);
LV_IMG_DECLARE(_yc_alpha_60x60);

LV_FONT_DECLARE(lv_font_A65_16)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_A65_14)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_black_16)


#ifdef __cplusplus
}
#endif
#endif
