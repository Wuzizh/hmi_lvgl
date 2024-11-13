/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"


void custom_init(lv_ui *ui);
void dis_name_unit_yc(lv_timer_t *t);
void dis_name_unit_yx(lv_timer_t *t);
void dis_name_unit_yk(lv_timer_t *t);
void dis_name_unit_yt(lv_timer_t *t);
void dis_name_unit_dz(lv_timer_t *t);
void key_event_key_yc(lv_timer_t * t1);
void key_event_key_yx(lv_timer_t * t1);
void key_event_key_yk(lv_timer_t * t1);
void key_event_key_yt(lv_timer_t * t1);
void key_event_key_dz(lv_timer_t * t1);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */