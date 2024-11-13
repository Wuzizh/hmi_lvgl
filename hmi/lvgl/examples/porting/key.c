#include "key.h"
#include "sys.h"

#include <stdio.h>
#include <linux/input.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



static void* task_key_read(void *ctx)
{
    if(ctx == NULL) return;
    struct input_event t;
    hmi_key_t *me = (hmi_key_t *)ctx;

    while(1)
	{
		if(read(me->fd, &t, sizeof(t)) == sizeof(t))
		{
			if(t.type==EV_KEY)
            {
                if(t.value==0 || t.value==1)
				{
					TRANCE_DEBUG("key %d %s\n", t.code, (t.value == 0) ? "Pressed" : "Released");
                    if(t.value == 0)
                    {
                        me->val = 0;
                    }
                    else
                    {
                        me->val = 1;
                    }
                    
                    switch (t.code)
                    {
                    case HMI_KEY_UP:
                        if(t.value == 0)
                        {me->code = HMI_KEY_UP;}
                        else
                        {me->code =0;}
                        break;
                    case HMI_KEY_DOWN:
                        if(t.value == 0)
                        {me->code = HMI_KEY_DOWN;}
                        else
                        {me->code =0;}
                        break;
                    case HMI_KEY_ESC:
                        if(t.value == 0)
                        {me->code = HMI_KEY_ESC;}
                        else
                        {me->code =0;}
                        break;
                    case HMI_KEY_ENTER:
                        if(t.value == 0)
                        {me->code = HMI_KEY_ENTER;}
                        else
                        {me->code =0;}
                        break;
                    case HMI_KEY_OTHER:
                        if(t.value == 0)
                        {me->code = HMI_KEY_OTHER;}
                        else
                        {me->code =0;}
                        break;
                    default:
                        break;
                    }
				}
            }
		}
	}
	close(me->fd); 
    pthread_join(me->tid, NULL);
    return 0;
}


int key_init(hmi_key_t *me, const char *dev)
{
    if((me == NULL) || (dev == NULL)) return -1;

    system("sudo chmod 777 /dev/fb0");
    system("sudo chmod 777 /dev/input/event0");

    me->fd = open(DEV_PATH, O_RDONLY);
	if(me->fd <= 0)
	{
		TRANCE_DEBUG("open /dev/input/event0 device error!\n");
		return -1;
	}
    int ret = pthread_create(&me->tid, NULL, task_key_read, me);
    if(ret < 0)
    {
        TRANCE_DEBUG("create key read task fail \n");
    }
    TRANCE_DEBUG("create key read task success \n");
    return 0;
}
