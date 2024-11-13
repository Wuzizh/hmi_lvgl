#ifndef _FUNC_SEM_SHM_MOUDLE_
#define _FUNC_SEM_SHM_MOUDLE_
#ifndef _WIN32
#define RTCOMM_COMM104_SEM_KEY 0x4501
#define RTCOMM_COMM104_SHM_KEY 0x4501
#define RC_SEM_NO 0
#define RC_SHM_SIZE 100

typedef struct
{
    int index;
    unsigned short cmd; //
    unsigned short type;//
    unsigned int  direct;
} RC_YK_INFO;

typedef struct 
{
    int iread_ptr;
    int iwrite_ptr;
    RC_YK_INFO rc_msg[RC_SHM_SIZE];
} RC_YK_DATA;

#ifdef _cplusplus
extern "C" {
#endif
    extern int rc_sem_init();
    extern RC_YK_DATA* rc_shmdat_init(int sem_id);
    extern void rc_shm_write(int sem_id, RC_YK_DATA* rcdat_ptr, RC_YK_INFO* yk_info);
    extern int rc_shm_read(int sem_id, RC_YK_DATA* rcdat_ptr, RC_YK_INFO* yk_info_ptr);
#ifdef _cplusplus
}
#endif
#endif

#endif
