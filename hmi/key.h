#ifndef _HMI_KEY_H
#define _HMI_KEY_H

#include <pthread.h>

#define DEV_PATH "/dev/input/event0"   //difference is possible

/**
 * @brief   HMI按键代码定义
 */
enum HMI_KEY
{
    HMI_KEY_UP = 256,
    HMI_KEY_DOWN,
    HMI_KEY_ESC,
    HMI_KEY_ENTER,
    HMI_KEY_OTHER
};


typedef struct hmi_key_t
{
    int fd;
    pthread_t   tid;
    int code;
    int val;
}hmi_key_t;


/**
 * @brief   hmi key initialization
 * @return  success return 0, faliuer return -1
 */
int key_init_i(hmi_key_t *me, const char *dev);





















#endif
