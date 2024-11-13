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
extern uint32_t act_key;
lv_timer_t *t;
lv_timer_t *t1;
extern	char* tmp_yc1;
extern	char* tmp_yc2;


void setup_scr_yc_1(lv_ui *ui)
{
	//Write codes yc_1
	act_key=0;
	ui->yc_1 = lv_obj_create(NULL);
	lv_obj_set_size(ui->yc_1, 320, 240);
	lv_obj_set_scrollbar_mode(ui->yc_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for yc_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->yc_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->yc_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->yc_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_data_7
	ui->yc_1_data_7 = lv_label_create(ui->yc_1);
	//sprintf("numbers", "%d", buf_tmp[6]);
	lv_label_set_text(ui->yc_1_data_7, tmp_yc2);
	lv_label_set_long_mode(ui->yc_1_data_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_data_7, 176, 183);
	lv_obj_set_size(ui->yc_1_data_7, 200, 32);

	//Write style for yc_1_data_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_data_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_data_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_data_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_data_7, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_data_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_data_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_data_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_data_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_data_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_data_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_data_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_data_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_data_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_data_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_data_6
	ui->yc_1_data_6 = lv_label_create(ui->yc_1);
	//sprintf("numbers", "%d", buf_tmp[5]);
	lv_label_set_text(ui->yc_1_data_6, tmp_yc2);
	lv_label_set_long_mode(ui->yc_1_data_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_data_6, 176, 158);
	lv_obj_set_size(ui->yc_1_data_6, 200, 32);

	//Write style for yc_1_data_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_data_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_data_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_data_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_data_6, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_data_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_data_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_data_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_data_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_data_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_data_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_data_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_data_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_data_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_data_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_data_5
	ui->yc_1_data_5 = lv_label_create(ui->yc_1);
	//sprintf("numbers", "%d", buf_tmp[4]);
	lv_label_set_text(ui->yc_1_data_5, tmp_yc2);
	lv_label_set_long_mode(ui->yc_1_data_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_data_5, 176, 133);
	lv_obj_set_size(ui->yc_1_data_5, 200, 32);

	//Write style for yc_1_data_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_data_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_data_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_data_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_data_5, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_data_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_data_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_data_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_data_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_data_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_data_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_data_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_data_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_data_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_data_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_data_4
	ui->yc_1_data_4 = lv_label_create(ui->yc_1);
	//sprintf("numbers", "%d", buf_tmp[3]);
	lv_label_set_text(ui->yc_1_data_4, tmp_yc2);
	lv_label_set_long_mode(ui->yc_1_data_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_data_4, 176, 108);
	lv_obj_set_size(ui->yc_1_data_4, 200, 32);

	//Write style for yc_1_data_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_data_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_data_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_data_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_data_4, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_data_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_data_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_data_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_data_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_data_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_data_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_data_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_data_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_data_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_data_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_data_3
	ui->yc_1_data_3 = lv_label_create(ui->yc_1);
	//sprintf("numbers", "%d", buf_tmp[2]);
	lv_label_set_text(ui->yc_1_data_3, tmp_yc2);
	lv_label_set_long_mode(ui->yc_1_data_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_data_3, 176, 83);
	lv_obj_set_size(ui->yc_1_data_3, 200, 32);

	//Write style for yc_1_data_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_data_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_data_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_data_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_data_3, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_data_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_data_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_data_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_data_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_data_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_data_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_data_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_data_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_data_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_data_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_data_2
	ui->yc_1_data_2 = lv_label_create(ui->yc_1);
	//("numbers", "%d", buf_tmp[1]);
	lv_label_set_text(ui->yc_1_data_2, tmp_yc2);
	lv_label_set_long_mode(ui->yc_1_data_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_data_2, 176, 58);
	lv_obj_set_size(ui->yc_1_data_2, 200, 32);

	//Write style for yc_1_data_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_data_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_data_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_data_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_data_2, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_data_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_data_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_data_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_data_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_data_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_data_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_data_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_data_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_data_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_data_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_data_1
	ui->yc_1_data_1 = lv_label_create(ui->yc_1);
	//sprintf("numbers", "%d", buf_tmp[0]);
	lv_label_set_text(ui->yc_1_data_1, tmp_yc2);

	lv_label_set_long_mode(ui->yc_1_data_1, LV_LABEL_LONG_WRAP); 
	lv_obj_set_pos(ui->yc_1_data_1, 176, 33);
	lv_obj_set_size(ui->yc_1_data_1, 200, 32);

	//Write style for yc_1_data_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_data_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_data_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_data_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_data_1, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_data_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_data_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_data_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_data_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_data_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_data_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_data_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_data_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_data_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_data_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	/*/
	while(lv_obj_is_valid(ui->yc_1_data_1))
	{
		printf("lv_data_1:0 is vaild\n");
		t=lv_timer_create(update_data, 1000, NULL);
		while(lv_obj_is_valid(ui->yc_1_data_1))
		{
			printf("lv_data_1:1 is vaild\n");
			break;
		}
		break;
	}
	*/
	//Write codes yc_1_label_7
	ui->yc_1_label_7 = lv_label_create(ui->yc_1);
	lv_label_set_text(ui->yc_1_label_7, tmp_yc1);
	lv_label_set_long_mode(ui->yc_1_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_label_7, 25, 183);
	lv_obj_set_size(ui->yc_1_label_7, 200, 32);

	//Write style for yc_1_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_label_7, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_label_7, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_label_6
	ui->yc_1_label_6 = lv_label_create(ui->yc_1);
	lv_label_set_text(ui->yc_1_label_6, tmp_yc1);
	lv_label_set_long_mode(ui->yc_1_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_label_6, 25, 158);
	lv_obj_set_size(ui->yc_1_label_6, 200, 32);

	//Write style for yc_1_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_label_6, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_label_6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_label_5
	ui->yc_1_label_5 = lv_label_create(ui->yc_1);
	lv_label_set_text(ui->yc_1_label_5, tmp_yc1);
	lv_label_set_long_mode(ui->yc_1_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_label_5, 25, 133);
	lv_obj_set_size(ui->yc_1_label_5, 200, 32);

	//Write style for yc_1_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_label_5, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_label_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_label_4
	ui->yc_1_label_4 = lv_label_create(ui->yc_1);
	lv_label_set_text(ui->yc_1_label_4, tmp_yc1);
	lv_label_set_long_mode(ui->yc_1_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_label_4, 25, 108);
	lv_obj_set_size(ui->yc_1_label_4, 200, 32);

	//Write style for yc_1_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_label_4, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_label_3
	ui->yc_1_label_3 = lv_label_create(ui->yc_1);
	lv_label_set_text(ui->yc_1_label_3, tmp_yc1);
	lv_label_set_long_mode(ui->yc_1_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_label_3, 25, 83);
	lv_obj_set_size(ui->yc_1_label_3, 200, 32);

	//Write style for yc_1_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_label_3, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_label_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_label_2
	ui->yc_1_label_2 = lv_label_create(ui->yc_1);
	lv_label_set_text(ui->yc_1_label_2, tmp_yc1);
	lv_label_set_long_mode(ui->yc_1_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_label_2, 25, 58);
	lv_obj_set_size(ui->yc_1_label_2, 200, 32);

	//Write style for yc_1_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_label_2, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_label_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_label_1
	ui->yc_1_label_1 = lv_label_create(ui->yc_1);
	lv_label_set_text(ui->yc_1_label_1, tmp_yc1);
	lv_label_set_long_mode(ui->yc_1_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_label_1, 25, 33);
	lv_obj_set_size(ui->yc_1_label_1, 200, 32);

	//Write style for yc_1_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->yc_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->yc_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_label_1, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_btn_3
	ui->yc_1_btn_3 = lv_btn_create(ui->yc_1);
	ui->yc_1_btn_3_label = lv_label_create(ui->yc_1_btn_3);
	lv_label_set_text(ui->yc_1_btn_3_label, "" LV_SYMBOL_RIGHT " ");
	lv_label_set_long_mode(ui->yc_1_btn_3_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->yc_1_btn_3_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->yc_1_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->yc_1_btn_3_label, LV_PCT(100));
	lv_obj_set_pos(ui->yc_1_btn_3, 287, 217);
	lv_obj_set_size(ui->yc_1_btn_3, 31, 22);

	//Write style for yc_1_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->yc_1_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->yc_1_btn_3, lv_color_hex(0x160003), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->yc_1_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->yc_1_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_btn_2
	ui->yc_1_btn_2 = lv_btn_create(ui->yc_1);
	ui->yc_1_btn_2_label = lv_label_create(ui->yc_1_btn_2);
	lv_label_set_text(ui->yc_1_btn_2_label, "" LV_SYMBOL_LEFT "");
	lv_label_set_long_mode(ui->yc_1_btn_2_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->yc_1_btn_2_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->yc_1_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->yc_1_btn_2_label, LV_PCT(100));
	lv_obj_set_pos(ui->yc_1_btn_2, 238, 217);
	lv_obj_set_size(ui->yc_1_btn_2, 31, 22);

	//Write style for yc_1_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->yc_1_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->yc_1_btn_2, lv_color_hex(0x160003), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->yc_1_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->yc_1_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_btn_1
	ui->yc_1_btn_1 = lv_btn_create(ui->yc_1);
	ui->yc_1_btn_1_label = lv_label_create(ui->yc_1_btn_1);
	lv_label_set_text(ui->yc_1_btn_1_label, "" LV_SYMBOL_BACKSPACE " ");
	lv_label_set_long_mode(ui->yc_1_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->yc_1_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->yc_1_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->yc_1_btn_1_label, LV_PCT(100));
	lv_obj_set_pos(ui->yc_1_btn_1, 1, 213);
	lv_obj_set_size(ui->yc_1_btn_1, 33, 26);

	//Write style for yc_1_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_btn_1, &lv_font_black_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->yc_1_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->yc_1_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_warning
	ui->yc_1_warning = lv_label_create(ui->yc_1);
	lv_label_set_text(ui->yc_1_warning, "告警");
	lv_label_set_long_mode(ui->yc_1_warning, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_warning, 238, 1);
	lv_obj_set_size(ui->yc_1_warning, 100, 32);

	//Write style for yc_1_warning, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_warning, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_warning, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_warning, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_warning, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_state
	ui->yc_1_state = lv_label_create(ui->yc_1);
	lv_label_set_text(ui->yc_1_state, "通讯状态");
	lv_label_set_long_mode(ui->yc_1_state, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_state, 169, 1);
	lv_obj_set_size(ui->yc_1_state, 100, 32);

	//Write style for yc_1_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_state, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_state, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_state, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_state, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_model
	ui->yc_1_model = lv_label_create(ui->yc_1);
	lv_label_set_text(ui->yc_1_model, "并网模式");
	lv_label_set_long_mode(ui->yc_1_model, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_model, 88, 1);
	lv_obj_set_size(ui->yc_1_model, 100, 32);

	//Write style for yc_1_model, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->yc_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_model, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_model, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_model, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_model, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->yc_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_model, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes yc_1_time
	ui->yc_1_time = lv_label_create(ui->yc_1);
	lv_label_set_text(ui->yc_1_time, "2024-09-18\n");
	lv_label_set_long_mode(ui->yc_1_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->yc_1_time, -12, 1);
	lv_obj_set_size(ui->yc_1_time, 122, 17);

	//Write style for yc_1_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->yc_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->yc_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->yc_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->yc_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->yc_1_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->yc_1_time, &lv_font_A65_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->yc_1_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->yc_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->yc_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->yc_1_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->yc_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->yc_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->yc_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->yc_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of yc_1.

	//Update current screen layout.
	lv_obj_update_layout(ui->yc_1);

	//Init events for screen.
	events_init_yc_1(ui);


	if(lv_obj_is_valid(ui->yc_1))
	{
		t=lv_timer_create(dis_name_unit_yc,100,&guider_ui);

		t1=lv_timer_create(key_event_key_yc,150,&guider_ui);

	}

}