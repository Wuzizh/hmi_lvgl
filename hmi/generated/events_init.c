

/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "gui_guider.h"
#include "custom.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif
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
extern int key_event;

lv_indev_t *indev_keypad;
lv_group_t *g;
lv_timer_t *t;


lv_ui *ui;

static void main_page_btn_6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{	
		lv_group_remove_all_objs(g);
		ui_load_scr_animation(&guider_ui, &guider_ui.sys, guider_ui.sys_del, &guider_ui.main_page_del, setup_scr_sys, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		cur_page=0;
		break;
	}
    default:
        break;
    }
}

static void main_page_btn_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		ui_load_scr_animation(&guider_ui, &guider_ui.cons_1, guider_ui.cons_1_del, &guider_ui.main_page_del, setup_scr_cons_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		cur_page=0;
		break;
	}
    default:
        break;
    }
}

static void main_page_btn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		ui_load_scr_animation(&guider_ui, &guider_ui.yt_1, guider_ui.yt_1_del, &guider_ui.main_page_del, setup_scr_yt_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		cur_page=0;
		break;
	}
    default:
        break;
    }
}

static void main_page_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		ui_load_scr_animation(&guider_ui, &guider_ui.yk_1, guider_ui.yk_1_del, &guider_ui.main_page_del, setup_scr_yk_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		cur_page=0;
		break;
	}
    default:
        break;
    }
}

static void main_page_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		ui_load_scr_animation(&guider_ui, &guider_ui.yx_1, guider_ui.yx_1_del, &guider_ui.main_page_del, setup_scr_yx_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		cur_page=0;
		break;
	}
    default:
        break;
    }
}

static void main_page_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		ui_load_scr_animation(&guider_ui, &guider_ui.yc_1, guider_ui.yc_1_del, &guider_ui.main_page_del, setup_scr_yc_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		cur_page=0;
		break;
	}
    default:
        break;
    }
}

void events_init_main_page (lv_ui *ui)
{
	lv_group_remove_all_objs(g);

	lv_obj_add_event_cb(ui->main_page_btn_1, main_page_btn_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->main_page_btn_2, main_page_btn_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->main_page_btn_3, main_page_btn_3_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->main_page_btn_4, main_page_btn_4_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->main_page_btn_5, main_page_btn_5_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->main_page_btn_6, main_page_btn_6_event_handler, LV_EVENT_ALL, ui);

	lv_group_add_obj(g, ui->main_page_btn_1);
	lv_group_add_obj(g, ui->main_page_btn_2);
	lv_group_add_obj(g, ui->main_page_btn_3);
	lv_group_add_obj(g, ui->main_page_btn_4);
	lv_group_add_obj(g, ui->main_page_btn_5);
	lv_group_add_obj(g, ui->main_page_btn_6);
	lv_indev_set_group(indev_keypad,g);	
}

static void yc_1_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		if(cur_page==yc_page)
		{
			cur_page=0;
		}
		else
		{
			cur_page++;
		}
		ui_load_scr_animation(&guider_ui, &guider_ui.yc_1, guider_ui.yc_1_del, &guider_ui.yc_1_del, setup_scr_yc_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);		break;
	}
    default:
        break;
    }
}

static void yc_1_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		if(cur_page==0)
		{
			cur_page=yc_page;
		}
		else
		{
			cur_page--;
		}
		ui_load_scr_animation(&guider_ui, &guider_ui.yc_1, guider_ui.yc_1_del, &guider_ui.yc_1_del, setup_scr_yc_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);		break;
	}
    default:
        break;
    }
}

static void yc_1_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		ui_load_scr_animation(&guider_ui, &guider_ui.main_page, guider_ui.main_page_del, &guider_ui.yc_1_del, setup_scr_main_page, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);

	}
    default:
        break;
    }
}

void events_init_yc_1 (lv_ui *ui)
{
	lv_group_remove_all_objs(g);
	lv_obj_add_event_cb(ui->yc_1_btn_3, yc_1_btn_3_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->yc_1_btn_2, yc_1_btn_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->yc_1_btn_1, yc_1_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void yx_1_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		if(cur_page==yx_page)
		{
			cur_page=0;
		}
		else
		{
			cur_page++;
		}
		ui_load_scr_animation(&guider_ui, &guider_ui.yx_1, guider_ui.yx_1_del, &guider_ui.yx_1_del, setup_scr_yx_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
	}
    default:
        break;
    }
}

static void yx_1_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		if(cur_page==0)
		{
			cur_page=yx_page;
		}
		else
		{
			cur_page--;
		}
		ui_load_scr_animation(&guider_ui, &guider_ui.yx_1, guider_ui.yx_1_del, &guider_ui.yx_1_del, setup_scr_yx_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
	}
    default:
        break;
    }
}

static void yx_1_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{

		lv_group_remove_all_objs(g);
		ui_load_scr_animation(&guider_ui, &guider_ui.main_page, guider_ui.main_page_del, &guider_ui.yx_1_del, setup_scr_main_page, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);

	}
    default:
        break;
    }
}

void events_init_yx_1 (lv_ui *ui)
{
	lv_group_remove_all_objs(g);
	
	lv_obj_add_event_cb(ui->yx_1_btn_3, yx_1_btn_3_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->yx_1_btn_2, yx_1_btn_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->yx_1_btn_1, yx_1_btn_1_event_handler, LV_EVENT_ALL, ui);

}

static void yk_1_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		if(cur_page==yk_page)
		{
			cur_page=0;
		}
		else
		{
			cur_page++;
		}
		ui_load_scr_animation(&guider_ui, &guider_ui.yk_1, guider_ui.yk_1_del, &guider_ui.yk_1_del, setup_scr_yk_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
	}
    default:
        break;
    }
}

static void yk_1_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		lv_group_remove_all_objs(g);
		if(cur_page==0)
		{
			cur_page=yk_page;
		}
		else
		{
			cur_page--;
		}		
		ui_load_scr_animation(&guider_ui, &guider_ui.yk_1, guider_ui.yk_1_del, &guider_ui.yk_1_del, setup_scr_yk_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);

	}
    default:
        break;
    }
}

static void yk_1_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		ui_load_scr_animation(&guider_ui, &guider_ui.main_page, guider_ui.main_page_del, &guider_ui.yk_1_del, setup_scr_main_page, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);

	}
    default:
        break;
    }
}

void events_init_yk_1 (lv_ui *ui)
{
	lv_group_remove_all_objs(g);

	lv_obj_add_event_cb(ui->yk_1_btn_3, yk_1_btn_3_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->yk_1_btn_2, yk_1_btn_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->yk_1_btn_1, yk_1_btn_1_event_handler, LV_EVENT_ALL, ui);

}


static void yt_1_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		if(cur_page==yt_page)
		{
			cur_page=0;
		}
		else
		{
			cur_page++;
		}
		ui_load_scr_animation(&guider_ui, &guider_ui.yt_1, guider_ui.yt_1_del, &guider_ui.yt_1_del, setup_scr_yt_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);

	}
    default:
        break;
    }
}

static void yt_1_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		if(cur_page==0)
		{
			cur_page=yt_page;
		}
		else
		{
			cur_page++;
		}
		ui_load_scr_animation(&guider_ui, &guider_ui.yt_1, guider_ui.yt_1_del, &guider_ui.yt_1_del, setup_scr_yt_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
	}
    default:
        break;
    }
}

static void yt_1_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		ui_load_scr_animation(&guider_ui, &guider_ui.main_page, guider_ui.main_page_del, &guider_ui.yt_1_del, setup_scr_main_page, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		
	}
    default:
        break;
    }
}

void events_init_yt_1 (lv_ui *ui)
{
	lv_group_remove_all_objs(g);

	lv_obj_add_event_cb(ui->yt_1_btn_3, yt_1_btn_3_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->yt_1_btn_2, yt_1_btn_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->yt_1_btn_1, yt_1_btn_1_event_handler, LV_EVENT_ALL, ui);

}


static void cons_1_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		if(cur_page==dz_page)
		{
			cur_page=0;
		}
		else
		{
			cur_page++;
		}
		ui_load_scr_animation(&guider_ui, &guider_ui.cons_1, guider_ui.cons_1_del, &guider_ui.cons_1_del, setup_scr_cons_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
	}
    default:
        break;
    }
}

static void cons_1_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		if(cur_page==0)
		{
			cur_page=dz_page;
		}
		else
		{
			cur_page++;
		}
		ui_load_scr_animation(&guider_ui, &guider_ui.cons_1, guider_ui.cons_1_del, &guider_ui.cons_1_del, setup_scr_cons_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
	}
    default:
        break;
    }
}

static void cons_1_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		//lv_timer_del(t);
		lv_group_remove_all_objs(g);
		ui_load_scr_animation(&guider_ui, &guider_ui.main_page, guider_ui.main_page_del, &guider_ui.cons_1_del, setup_scr_main_page, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
	}
    default:
        break;
    }

}

void events_init_cons_1 (lv_ui *ui)
{
	lv_group_remove_all_objs(g);

	lv_obj_add_event_cb(ui->cons_1_btn_3, cons_1_btn_3_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->cons_1_btn_2, cons_1_btn_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->cons_1_btn_1, cons_1_btn_1_event_handler, LV_EVENT_ALL, ui);

}


static void sys_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_group_remove_all_objs(g);
		ui_load_scr_animation(&guider_ui, &guider_ui.main_page, guider_ui.main_page_del, &guider_ui.sys_del, setup_scr_main_page, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
	}
    default:
        break;
    }
}

void events_init_sys (lv_ui *ui)
{
	lv_group_remove_all_objs(g);
	lv_obj_add_event_cb(ui->sys_btn_1, sys_btn_1_event_handler, LV_EVENT_ALL, ui);
	lv_group_add_obj(g, ui->sys_btn_1);
	lv_indev_set_group(indev_keypad, g);
}


void events_init(lv_ui *ui)
{

}
