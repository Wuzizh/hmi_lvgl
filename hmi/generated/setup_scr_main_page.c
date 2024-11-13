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
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_main_page(lv_ui *ui)
{
	//Write codes main_page
	ui->main_page = lv_obj_create(NULL);
	lv_obj_set_size(ui->main_page, 320, 240);
	lv_obj_set_scrollbar_mode(ui->main_page, LV_SCROLLBAR_MODE_OFF);

	//Write style for main_page, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->main_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_page, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->main_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_time
	ui->main_page_time = lv_label_create(ui->main_page);
	lv_label_set_text(ui->main_page_time, "2024-09-18\n");
	lv_label_set_long_mode(ui->main_page_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_page_time, -12, 1);
	lv_obj_set_size(ui->main_page_time, 122, 17);

	//Write style for main_page_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_page_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_time, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->main_page_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_page_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_page_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_page_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_page_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_page_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_page_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_page_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_warning
	ui->main_page_warning = lv_label_create(ui->main_page);
	lv_label_set_text(ui->main_page_warning, "告警");
	lv_label_set_long_mode(ui->main_page_warning, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_page_warning, 238, 1);
	lv_obj_set_size(ui->main_page_warning, 100, 32);

	//Write style for main_page_warning, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_page_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_warning, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_warning, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->main_page_warning, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_page_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_page_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_warning, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_page_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_page_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_page_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_page_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_page_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_state
	ui->main_page_state = lv_label_create(ui->main_page);
	lv_label_set_text(ui->main_page_state, "通讯状态");
	lv_label_set_long_mode(ui->main_page_state, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_page_state, 168, 1);
	lv_obj_set_size(ui->main_page_state, 100, 32);

	//Write style for main_page_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_page_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_state, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_state, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->main_page_state, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_page_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_page_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_state, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_page_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_page_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_page_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_page_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_page_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_model
	ui->main_page_model = lv_label_create(ui->main_page);
	lv_label_set_text(ui->main_page_model, "并网模式");
	lv_label_set_long_mode(ui->main_page_model, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_page_model, 88, 1);
	lv_obj_set_size(ui->main_page_model, 100, 32);

	//Write style for main_page_model, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_page_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_model, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_model, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->main_page_model, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_page_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_page_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_model, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_page_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_page_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_page_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_page_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_page_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_label_5
	ui->main_page_label_5 = lv_label_create(ui->main_page);
	lv_label_set_text(ui->main_page_label_5, "遥测");
	lv_label_set_long_mode(ui->main_page_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_page_label_5, 9, 115);
	lv_obj_set_size(ui->main_page_label_5, 100, 32);

	//Write style for main_page_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_page_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_label_5, &lv_font_A65_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->main_page_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_page_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_page_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_page_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_page_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_page_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_page_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_page_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_label_6
	ui->main_page_label_6 = lv_label_create(ui->main_page);
	lv_label_set_text(ui->main_page_label_6, "遥信");
	lv_label_set_long_mode(ui->main_page_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_page_label_6, 110, 115);
	lv_obj_set_size(ui->main_page_label_6, 100, 32);

	//Write style for main_page_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_page_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_label_6, &lv_font_A65_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->main_page_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_page_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_page_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_page_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_page_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_page_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_page_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_page_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_label_7
	ui->main_page_label_7 = lv_label_create(ui->main_page);
	lv_label_set_text(ui->main_page_label_7, "遥控");
	lv_label_set_long_mode(ui->main_page_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_page_label_7, 210, 115);
	lv_obj_set_size(ui->main_page_label_7, 100, 32);

	//Write style for main_page_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_page_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_label_7, &lv_font_A65_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->main_page_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_page_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_page_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_page_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_page_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_page_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_page_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_page_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_label_10
	ui->main_page_label_10 = lv_label_create(ui->main_page);
	lv_label_set_text(ui->main_page_label_10, "系统");
	lv_label_set_long_mode(ui->main_page_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_page_label_10, 210, 218);
	lv_obj_set_size(ui->main_page_label_10, 100, 32);

	//Write style for main_page_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_page_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_label_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_label_10, &lv_font_A65_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->main_page_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_page_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_page_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_page_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_page_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_page_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_page_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_page_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_label_9
	ui->main_page_label_9 = lv_label_create(ui->main_page);
	lv_label_set_text(ui->main_page_label_9, "定值");
	lv_label_set_long_mode(ui->main_page_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_page_label_9, 110, 218);
	lv_obj_set_size(ui->main_page_label_9, 100, 32);

	//Write style for main_page_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_page_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_label_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_label_9, &lv_font_A65_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->main_page_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_page_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_page_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_page_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_page_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_page_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_page_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_page_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_label_8
	ui->main_page_label_8 = lv_label_create(ui->main_page);
	lv_label_set_text(ui->main_page_label_8, "遥调");
	lv_label_set_long_mode(ui->main_page_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_page_label_8, 9, 218);
	lv_obj_set_size(ui->main_page_label_8, 100, 32);

	//Write style for main_page_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_page_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_label_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_label_8, &lv_font_A65_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->main_page_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_page_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_page_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_page_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_page_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_page_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_page_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_page_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_img_6
	ui->main_page_img_6 = lv_img_create(ui->main_page);
	lv_obj_add_flag(ui->main_page_img_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_page_img_6, &_xt_alpha_55x55);
	lv_img_set_pivot(ui->main_page_img_6, 50,50);
	lv_img_set_angle(ui->main_page_img_6, 0);
	lv_obj_set_pos(ui->main_page_img_6, 233, 156);
	lv_obj_set_size(ui->main_page_img_6, 55, 55);

	//Write style for main_page_img_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->main_page_img_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->main_page_img_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_img_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->main_page_img_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_img_5
	ui->main_page_img_5 = lv_img_create(ui->main_page);
	lv_obj_add_flag(ui->main_page_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_page_img_5, &_dz_alpha_60x60);
	lv_img_set_pivot(ui->main_page_img_5, 50,50);
	lv_img_set_angle(ui->main_page_img_5, 0);
	lv_obj_set_pos(ui->main_page_img_5, 133, 154);
	lv_obj_set_size(ui->main_page_img_5, 60, 60);

	//Write style for main_page_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->main_page_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->main_page_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->main_page_img_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_img_4
	ui->main_page_img_4 = lv_img_create(ui->main_page);
	lv_obj_add_flag(ui->main_page_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_page_img_4, &_telemetry_alpha_55x55);
	lv_img_set_pivot(ui->main_page_img_4, 50,50);
	lv_img_set_angle(ui->main_page_img_4, 0);
	lv_obj_set_pos(ui->main_page_img_4, 29, 159);
	lv_obj_set_size(ui->main_page_img_4, 55, 55);

	//Write style for main_page_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->main_page_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->main_page_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->main_page_img_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_img_3
	ui->main_page_img_3 = lv_img_create(ui->main_page);
	lv_obj_add_flag(ui->main_page_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_page_img_3, &_yk_alpha_60x60);
	lv_img_set_pivot(ui->main_page_img_3, 50,50);
	lv_img_set_angle(ui->main_page_img_3, 0);
	lv_obj_set_pos(ui->main_page_img_3, 228, 55);
	lv_obj_set_size(ui->main_page_img_3, 60, 60);

	//Write style for main_page_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->main_page_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->main_page_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->main_page_img_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_img_2
	ui->main_page_img_2 = lv_img_create(ui->main_page);
	lv_obj_add_flag(ui->main_page_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_page_img_2, &_yx_alpha_55x55);
	lv_img_set_pivot(ui->main_page_img_2, 50,50);
	lv_img_set_angle(ui->main_page_img_2, 0);
	lv_obj_set_pos(ui->main_page_img_2, 134, 57);
	lv_obj_set_size(ui->main_page_img_2, 55, 55);

	//Write style for main_page_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->main_page_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->main_page_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->main_page_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_img_1
	ui->main_page_img_1 = lv_img_create(ui->main_page);
	lv_obj_add_flag(ui->main_page_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_page_img_1, &_yc_alpha_60x60);
	lv_img_set_pivot(ui->main_page_img_1, 50,50);
	lv_img_set_angle(ui->main_page_img_1, 0);
	lv_obj_set_pos(ui->main_page_img_1, 31, 53);
	lv_obj_set_size(ui->main_page_img_1, 60, 60);

	//Write style for main_page_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->main_page_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->main_page_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->main_page_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_btn_6
	ui->main_page_btn_6 = lv_btn_create(ui->main_page);
	ui->main_page_btn_6_label = lv_label_create(ui->main_page_btn_6);
	lv_label_set_text(ui->main_page_btn_6_label, "");
	lv_label_set_long_mode(ui->main_page_btn_6_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->main_page_btn_6_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->main_page_btn_6, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->main_page_btn_6_label, LV_PCT(100));
	lv_obj_set_pos(ui->main_page_btn_6, 231, 154);
	lv_obj_set_size(ui->main_page_btn_6, 60, 60);

	//Write style for main_page_btn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->main_page_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->main_page_btn_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_page_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_page_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_page_btn_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_btn_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_btn_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->main_page_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_btn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_btn_5
	ui->main_page_btn_5 = lv_btn_create(ui->main_page);
	ui->main_page_btn_5_label = lv_label_create(ui->main_page_btn_5);
	lv_label_set_text(ui->main_page_btn_5_label, "");
	lv_label_set_long_mode(ui->main_page_btn_5_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->main_page_btn_5_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->main_page_btn_5, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->main_page_btn_5_label, LV_PCT(100));
	lv_obj_set_pos(ui->main_page_btn_5, 133, 154);
	lv_obj_set_size(ui->main_page_btn_5, 60, 60);

	//Write style for main_page_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->main_page_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->main_page_btn_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_page_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_page_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_page_btn_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_btn_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_btn_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->main_page_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_btn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_btn_4
	ui->main_page_btn_4 = lv_btn_create(ui->main_page);
	ui->main_page_btn_4_label = lv_label_create(ui->main_page_btn_4);
	lv_label_set_text(ui->main_page_btn_4_label, "");
	lv_label_set_long_mode(ui->main_page_btn_4_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->main_page_btn_4_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->main_page_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->main_page_btn_4_label, LV_PCT(100));
	lv_obj_set_pos(ui->main_page_btn_4, 27, 157);
	lv_obj_set_size(ui->main_page_btn_4, 60, 60);

	//Write style for main_page_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->main_page_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->main_page_btn_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_page_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_page_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_page_btn_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_btn_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_btn_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->main_page_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_btn_3
	ui->main_page_btn_3 = lv_btn_create(ui->main_page);
	ui->main_page_btn_3_label = lv_label_create(ui->main_page_btn_3);
	lv_label_set_text(ui->main_page_btn_3_label, "");
	lv_label_set_long_mode(ui->main_page_btn_3_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->main_page_btn_3_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->main_page_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->main_page_btn_3_label, LV_PCT(100));
	lv_obj_set_pos(ui->main_page_btn_3, 228, 55);
	lv_obj_set_size(ui->main_page_btn_3, 60, 60);

	//Write style for main_page_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->main_page_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->main_page_btn_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_page_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_page_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_page_btn_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->main_page_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_btn_2
	ui->main_page_btn_2 = lv_btn_create(ui->main_page);
	ui->main_page_btn_2_label = lv_label_create(ui->main_page_btn_2);
	lv_label_set_text(ui->main_page_btn_2_label, "");
	lv_label_set_long_mode(ui->main_page_btn_2_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->main_page_btn_2_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->main_page_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->main_page_btn_2_label, LV_PCT(100));
	lv_obj_set_pos(ui->main_page_btn_2, 133, 55);
	lv_obj_set_size(ui->main_page_btn_2, 60, 60);

	//Write style for main_page_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->main_page_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->main_page_btn_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_page_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_page_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_page_btn_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->main_page_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_btn_1
	ui->main_page_btn_1 = lv_btn_create(ui->main_page);
	ui->main_page_btn_1_label = lv_label_create(ui->main_page_btn_1);
	lv_label_set_text(ui->main_page_btn_1_label, "");
	lv_label_set_long_mode(ui->main_page_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->main_page_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->main_page_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->main_page_btn_1_label, LV_PCT(100));
	lv_obj_set_pos(ui->main_page_btn_1, 31, 53);
	lv_obj_set_size(ui->main_page_btn_1, 60, 60);

	//Write style for main_page_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->main_page_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->main_page_btn_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_page_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_page_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_page_btn_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_page_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->main_page_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of main_page.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->main_page);

	//Init events for screen.
	events_init_main_page(ui);
}
