/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1


#include "lv_port_indev.h"
#include "lvgl/lvgl.h"
#include "key.h"
#include "sys.h"

hmi_key_t hmi_key;  

static void keypad_init(void);
static void keypad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
uint32_t keypad_get_key(void);


lv_indev_t * indev_keypad;



void lv_port_indev_init(void)
{
    static lv_indev_drv_t indev_drv;
    keypad_init();
    /*Register a keypad input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_KEYPAD;
    indev_drv.read_cb = keypad_read;
    indev_keypad = lv_indev_drv_register(&indev_drv);

}

static void keypad_init(void)
{
    key_init(&hmi_key, DEV_PATH);
}

/*Will be called by the library to read the mouse*/
static void keypad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint32_t last_key = 0;
    uint32_t act_key = keypad_get_key();
    
    if(act_key != 0) {
        if(hmi_key.val == 0)
        {
            data->state = LV_INDEV_STATE_PR;
        }
        else
        {
            data->state = LV_INDEV_STATE_REL;
        }


        /*Translate the keys to LVGL control characters according to your key definitions*/
        switch(act_key) {
        case HMI_KEY_UP:
            act_key = LV_KEY_PREV;
            break;
        case HMI_KEY_DOWN:
            act_key = LV_KEY_NEXT;
            break;
        case HMI_KEY_ESC:
            act_key = LV_KEY_ESC;
            break;
        case HMI_KEY_ENTER:
            act_key = LV_KEY_ENTER;
            break;
        case HMI_KEY_OTHER:
            act_key = LV_KEY_END;
        }

        last_key = act_key;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }

    data->key = last_key;
    return false;
}


uint32_t keypad_get_key(void)
{
    /*Your code comes here*/

    return hmi_key.code;
}


#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
