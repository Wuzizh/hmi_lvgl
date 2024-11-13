/***********************************************************************************
* Copyright (C), DIGIT POWER,2017-2020,All Right Reserved
***********************************************************************************/

#include "../include/rdb_dispatch.h"
#include "../include/rdb_init.h"
#include "../include/rdb_define.h"
#include "sys_func.h"
#include "sys_protocol_interface.h"

#include "hmi_updata.h"

static HMI_MODBUS_UP_STRUCT* dp;
static HMI_MU_INDEX_ELEMENT* pElement;
static hmi_updata_struct* hmi_data;
extern int hmi_up_init_success;
int init_success = 0;

//void* hmi_updata_init(struct SYS_STRSTREAM* strp, int type, u_int  app_id, u_int group_id);
static int HMI_MU_createYclist(HMI_MODBUS_UP_STRUCT* dp, struct SYS_STRSTREAM* strp, int event_type);
static int HMI_MU_createYxlist(HMI_MODBUS_UP_STRUCT* dp, struct SYS_STRSTREAM* strp, int event_type);
static int HMI_MU_createYtlist(HMI_MODBUS_UP_STRUCT* dp, struct SYS_STRSTREAM* strp, int event_type);
static int HMI_MU_createYklist(HMI_MODBUS_UP_STRUCT* dp, struct SYS_STRSTREAM* strp, int event_type);
static int HMI_MU_createIndexlist(HMI_MODBUS_UP_STRUCT* dp, struct SYS_STRSTREAM* strp, int event_type);
static void HMI_readSoftBus(HMI_MODBUS_UP_STRUCT* dp);
static void HMI_linkProcess(HMI_MODBUS_UP_STRUCT* dp);
static void HMI_timetask(void);
static int HMI_selectMax(int* p_fd, int num);
struct HMI_LBC* HMI_createListBuf(enum HMI_LBTYPE type, int max_buf);
int HMI_addListBuf(struct HMI_LBC* lbcp, void* bufp, int key, int size);
void HMI_delListBuf(struct HMI_LBC* lbcp);
void HMI_delListBufByPtr(struct HMI_LBC* lbcp, struct HMI_LBNODE* ptr);
void HMI_delListBuflAll(struct HMI_LBC* lbcp);
struct HMI_LBNODE* HMI_searchNode(struct HMI_LBC* lbcp, unsigned int key);
static void HMI_updateFd103Set();
static int HMI_addFd103Node(int fd, void (*func)(void*), void* arg, int is_active_now);
static int HMI_delFd103Node(int fd);
static inline unsigned char HMI_getChar(char* data, int* offset);
static void HMI_fd103Select();
static void HMI_getUpData(HMI_MODBUS_UP_STRUCT* dp);
static u_char HMI_MU_YkYtCmdToSBus(HMI_MODBUS_UP_STRUCT* dp, HMI_MU_INDEX_ELEMENT* pControl, u_char iTbid, u_short iSqno);
static void HMI_readUartData(HMI_FD103* dp);
void HMI_processUartData(HMI_FD103* dp, struct HMI_UART* p_uart);
static void HMI_newUart(HMI_MODBUS_UP_STRUCT* dp);
static int HMI_uartSet(struct HMI_UART* dp);
static void HMI_uartSetTimeTask();
static void select_Y(hmi_updata_struct* hmi_data);
static void data_cpy(hmi_updata_struct* hmi_data);

hmi_updata_struct* get_hmi_data();


void* hmi_updata_init(struct SYS_STRSTREAM* strp, int type, u_int  app_id, u_int group_id)
{
    HMI_MODBUS_UP_STRUCT* ndp;
    hmi_updata_struct* hmi_datai;
    //hmi_updata_struct* hmi_data;
    int ret, errorno, ptr, i;
    int iTmp = 0;
    int num;

    int num_yc;
    int item_num;


    printf("---------HMI_UPDATA_INIT----------\n");
    ndp = (HMI_MODBUS_UP_STRUCT*)malloc(sizeof(HMI_MODBUS_UP_STRUCT));
    hmi_datai = (hmi_updata_struct*)malloc(sizeof(hmi_updata_struct));
    if (NULL == ndp) {
        mdl_pro_printf("[HMI UP]: dp Memery allocate error, program exit");
        sys_exitpro();
    }

    dp = ndp;
    hmi_data = hmi_datai;
    memset(dp, 0, sizeof(HMI_MODBUS_UP_STRUCT));
    dp->board_no = 1;
    dp->app_id = app_id;
    dp->group_id = group_id;
    dp->task_id = 1;
    dp->sh.source_app_id = app_id;
    dp->sh.source_task_id = 1;
    FBInitCircle(&dp->msg_cc, 128);

    ret = SB_register(dp->app_id, dp->group_id, &errorno);
    if (ret < 0)
    {
        printf("[HMI_ UP]:\tSB_register FAIL！\n");
        sys_exitpro();
    }
    ret = SB_recv_register(dp->app_id, dp->task_id, SYS_PIPE_TYPE, &dp->msg_cc, "fastfrequency", &errorno);
    if (ret < 0)
    {
        printf("[HMI_ UP]:\tSB_recv_register FAIL！\n");
        sys_exitpro();
    }


    HMI_newUart(dp);

    char buf_tmp[64];
    while (sys_strfind(strp, &strp->buf[strp->pos], "规约=377") != CM_OK)
    {
        sys_strseeknext(strp);
    }

    sys_strseeknext(strp);
    sys_strseeknext(strp);
    sys_strseeknext(strp);
    sys_strseeknext(strp);

    /*/
    sys_checkRBrkt(strp);
    sys_checkRBrkt(strp);

    sys_strseeknext(strp);//规约
    sys_strseeknext(strp);//端口号
    sys_strseeknext(strp);//IP地址
    sys_strseeknext(strp);//装置数目
    sys_strseeknext(strp);
    */
    sscanf(&(strp->buf[strp->pos]), "引用表数目=%d", &iTmp);

    for (i = 0; i < iTmp; i++)
    {
        u_int list_no = 0;
        sys_strseeknext(strp);
        sscanf(&(strp->buf[strp->pos]), "引用表库号=%d", &list_no);
        switch (list_no)
        {
        case 0:
            HMI_MU_createYclist(dp, strp, COS_TYPE); //遥测
            break;
        case 1:
            HMI_MU_createYxlist(dp, strp, COS_DATA_TYPE); //遥信
            break;
        case 2:
            HMI_MU_createIndexlist(dp, strp, COS_TYPE); //遥脉
            break;
        case 3:
            HMI_MU_createYklist(dp, strp, ASK_TYPE); //遥控
            break;
        case 4:
            HMI_MU_createYtlist(dp, strp, ASK_TYPE); //遥调
            break;
        default:
            break;
        }
    }
    dp->modbus_tcp_port_number = 502;
    dp->language_type = 0;




    hmi_data->num_Yc = dp->iYcNums;
    hmi_data->num_Yx = dp->iYxNums;
    hmi_data->num_Yx_S = dp->iYcNums;
    hmi_data->num_Yk = dp->iYkNums;
    hmi_data->num_Yt = dp->iYtNums;
    //hmi_data->num_Yx_S = 0;
    //hmi_data->num_Yxx = hmi_data->num_Yx - hmi_data->num_Yt - hmi_data->num_Yx_S;

    if (hmi_data->num_Yk != 0)
    {
        hmi_data->coe_Yk = (float*)calloc(hmi_data->num_Yk, sizeof(float));
        hmi_data->buf_Yk = (float*)calloc(hmi_data->num_Yk, sizeof(float));
        hmi_data->desc_Yk = (char*)calloc(hmi_data->num_Yk * 64, sizeof(char));
        hmi_data->unit_Yk = (char*)calloc(hmi_data->num_Yk * 64, sizeof(char));
        hmi_data->name_Yk = (char*)calloc(hmi_data->num_Yk * 64, sizeof(char));
    }
    if (hmi_data->num_Yc != 0)
    {
        hmi_data->coe_Yc = (float*)calloc(hmi_data->num_Yc, sizeof(float));
        hmi_data->buf_Yc = (float*)calloc(hmi_data->num_Yc, sizeof(float));
        hmi_data->desc_Yc = (char*)calloc(hmi_data->num_Yc * 64, sizeof(char));
        hmi_data->unit_Yc = (char*)calloc(hmi_data->num_Yc * 64, sizeof(char));
        hmi_data->name_Yc = (char*)calloc(hmi_data->num_Yc * 64, sizeof(char));
        hmi_data->coe_Ycc = (float*)calloc(hmi_data->num_Yc, sizeof(float));
        hmi_data->buf_Ycc = (float*)calloc(hmi_data->num_Yc, sizeof(float));
        hmi_data->desc_Ycc = (char*)calloc(hmi_data->num_Yc * 64, sizeof(char));
        hmi_data->unit_Ycc = (char*)calloc(hmi_data->num_Yc * 64, sizeof(char));
        hmi_data->name_Ycc = (char*)calloc(hmi_data->num_Yc * 64, sizeof(char));
            }
    if (hmi_data->num_Yx != 0)
    {
        hmi_data->coe_Yx = (float*)calloc(hmi_data->num_Yx, sizeof(float));
        hmi_data->buf_Yx = (float*)calloc(hmi_data->num_Yx, sizeof(float));
        hmi_data->desc_Yx = (char*)calloc(hmi_data->num_Yx * 64, sizeof(char));
        hmi_data->unit_Yx = (char*)calloc(hmi_data->num_Yx * 64, sizeof(char));
        hmi_data->name_Yx = (char*)calloc(hmi_data->num_Yx * 64, sizeof(char));
    }
    if (hmi_data->num_Yx_S != 0)
    {
        hmi_data->coe_Yx_S = (float*)calloc(hmi_data->num_Yx_S, sizeof(float));
        hmi_data->buf_Yx_S = (float*)calloc(hmi_data->num_Yx_S, sizeof(float));
        hmi_data->desc_Yx_S = (char*)calloc(hmi_data->num_Yx_S * 64, sizeof(char));
        hmi_data->name_Yx_S = (char*)calloc(hmi_data->num_Yx_S * 64, sizeof(char));
        hmi_data->unit_Yx_S = (char*)calloc(hmi_data->num_Yx_S * 64, sizeof(char));
    }
    if (hmi_data->num_Yt != 0)
    {
        hmi_data->coe_Yt = (float*)calloc(hmi_data->num_Yt, sizeof(float));
        hmi_data->buf_Yt = (float*)calloc(hmi_data->num_Yt, sizeof(float));
        hmi_data->desc_Yt = (char*)calloc(hmi_data->num_Yt * 64, sizeof(char));
        hmi_data->unit_Yt = (char*)calloc(hmi_data->num_Yt * 64, sizeof(char));
        hmi_data->name_Yt = (char*)calloc(hmi_data->num_Yt * 64, sizeof(char));
    }


    data_cpy(hmi_data);



    memset(dp->fdt_103, 0x00, MAX_FD103 * sizeof(HMI_FD103));

    rdb_proc_set_con_sta(&dp->sh, dp->board_no, dp->net_no, RDB_RET_NORMAL);

    //create thread
    ret = sys_thread_creat((void*)&HMI_linkProcess, dp, 200000, PTHREAD_PRIORITY);
    if (ret < 0)
    {
        mdl_pro_printf("[HMI_ 对上]: sys_thread_creat  linkProcess failed.");
        sys_exitpro();
    }

    //create thread
    ret = sys_thread_creat((void*)&HMI_readSoftBus, dp, 200000, PTHREAD_PRIORITY);
    if (ret < 0)
    {
        mdl_pro_printf("[HMI_ 对上]: readSoftBus  linkProcess failed.");
        sys_exitpro();
    }

    ret = sys_thread_creat((void*)&HMI_timetask, NULL, 200000, PTHREAD_PRIORITY);
    if (ret < 0)
    {
        mdl_pro_printf("[HMI_ 对上]: sys_thread_creat  timetask failed.");
        sys_exitpro();
    }
    printf("HMI__UPDATA_INIT_SUCCRSSFUL\n");
    hmi_up_init_success=1;
    init_success = 1;
    return dp;
}

//创建列表
//创建遥测列表
static int HMI_MU_createIndexlist(HMI_MODBUS_UP_STRUCT* dp, struct SYS_STRSTREAM* strp, int event_type)
{
    int	 item_num, i, list_no, ret, tmp[8];
    float afReadVal[2] = { 0,0 };
    char acTmp[64];
    struct SB_HEAD sh;
    HMI_MU_INDEX_ELEMENT* paElement;
    u_int fig = 0;
    list_no = 0;

    sh.source_app_id = dp->app_id;
    sh.source_task_id = dp->task_id;
    sh.destination_app_id = RDB_APP_ID;
    sh.destination_task_id = 1;

    {
        sys_strseeknext(strp);
        sscanf(&(strp->buf[strp->pos]), "引用表类型=%d", &fig);
        sys_strseeknext(strp);
        if (fig > 4)
            return -1;
        sys_strseeknext(strp);
        sscanf(&(strp->buf[strp->pos]), "表元素数目=%d", &item_num);
    }
    if (item_num > MAX_ITEM_NUM || item_num <= 0)
        return -1;
    paElement = calloc(item_num, sizeof(HMI_MU_INDEX_ELEMENT));
    switch (fig)
    {
    case 1:
        dp->paYxList = paElement;
        dp->iYxNums = item_num;
        break;
    case 2:
        dp->paYmList = paElement;
        dp->iYmNums = item_num;
        break;
    case 3:
        dp->paYkList = paElement;
        dp->iYkNums = item_num;
        break;
    case 4:
        dp->paYtList = paElement;
        dp->iYtNums = item_num;
        break;
    default:
        dp->paYcList = paElement;
        dp->iYcNums = item_num;
        break;
    }
    for (i = 0; i < item_num; i++) {
        sys_strseeknext(strp);
        if (fig == 0 || fig == 2 || fig == 4) {
            sscanf(&(strp->buf[strp->pos]), "引用=%d,%d,%d,%d,%d,%f,%f,%s", &tmp[0], &tmp[1], &tmp[2], &tmp[3], &tmp[4], &afReadVal[0], &afReadVal[1], acTmp);
            paElement[i].iValType = 7;
        }
        else {
            sscanf(&(strp->buf[strp->pos]), "引用=%d,%d,%d,%d,%d,%s", &tmp[0], &tmp[1], &tmp[2], &tmp[3], &tmp[4], acTmp);
            paElement[i].iValType = 9;
        }
        paElement[i].iDevAddr = tmp[0];
        paElement[i].iGroup = tmp[1];
        paElement[i].iItemNo = tmp[2];
        paElement[i].iYb = tmp[3];
        paElement[i].fOffset = afReadVal[0];
        paElement[i].fCeo = afReadVal[1];
        paElement[i].uVal.float_val = 0;
        paElement[i].uVal.pp = paElement[i].uVal.avalue; //调试用
    }
    if (event_type != -1) {
        ret = rdb_proc_register_list_hook(&sh, dp->app_id, dp->task_id, 0, dp->app_id, list_no, event_type, 0, 0, NULL);
        if (ret != 0) {
            mdl_pro_printf("\n sys_createIndexlist err,the prog will exit ");
            sys_exitpro();
        }
    }
    return 0;
}
//创建遥测列表
static int HMI_MU_createYclist(HMI_MODBUS_UP_STRUCT* dp, struct SYS_STRSTREAM* strp, int event_type)
{
    int	 item_num, i, list_no, ret, tmp[8];
    float afReadVal[2] = { 0,0 };
    char acTmp[64];
    char up_unit[64];
    char name[64];
    //char firstline[128];
    struct SB_HEAD sh;
    HMI_MU_INDEX_ELEMENT* paElement;

    u_int fig = 0;
    list_no = 0;

    sh.source_app_id = dp->app_id;
    sh.source_task_id = dp->task_id;
    sh.destination_app_id = RDB_APP_ID;
    sh.destination_task_id = 1;

    sys_strseeknext(strp);
    sscanf(&(strp->buf[strp->pos]), "引用表类型=%d", &fig);
    sys_strseeknext(strp);
    //sscanf(&(strp->buf[strp->pos]), "引用表描述=%s", acTmp);
    if (fig > 4)
        return -1;
    sys_strseeknext(strp);
    sscanf(&(strp->buf[strp->pos]), "表元素数目=%d", &item_num);

    if (item_num > MAX_ITEM_NUM || item_num <= 0)
        return -1;
    paElement = calloc(item_num, sizeof(HMI_MU_INDEX_ELEMENT));

    dp->paYcList = paElement;
    dp->iYcNums = item_num;

    for (i = 0; i < item_num; i++)
    {
        sys_strseeknext(strp);

        sscanf(&(strp->buf[strp->pos]), "引用=%d,%d,%d,%d,%d,%f,%f,%[^,],%[^,],%s", &tmp[0], &tmp[1], &tmp[2], &tmp[3], &tmp[4], &afReadVal[0], &afReadVal[1], acTmp, up_unit, name);
        paElement[i].iValType = 7;
        paElement[i].iDevAddr = tmp[0];
        paElement[i].iGroup = tmp[1];
        paElement[i].iItemNo = tmp[2];
        paElement[i].iYb = tmp[3];
        paElement[i].fOffset = afReadVal[0];
        //paElement[i].fCeo = afReadVal[1];
        paElement[i].uVal.float_val = 0;
        paElement[i].uVal.pp = paElement[i].uVal.avalue; //调试用
        paElement[i].iFirstTrigFlg = 0;
        paElement[i].coe = afReadVal[1];
        sprintf(paElement[i].desc, acTmp);
        sprintf(paElement[i].name, name);
        sprintf(paElement[i].updata_unit, up_unit);


    }
    dp->paYxList = paElement;
    dp->iYcNums = item_num;
    return 0;
}
//创建遥信列表
static int HMI_MU_createYxlist(HMI_MODBUS_UP_STRUCT* dp, struct SYS_STRSTREAM* strp, int event_type)
{
    int	 item_num, i, list_no, ret, tmp[8];
    int item_num_yx, item_num_yk, item_num_yt, item_num_yx_s;
    //int item_num_yx = 0;
    //int item_num_yk=0, item_num_yt, item_num_yx_s;
    //int item_num_yt = 0;
    //int item_num_yx_s=0;
    int coe;
    char name[64];
    char firstline[128];

    float afReadVal[2] = { 0,0 };
    char acTmp[64];
    char up_unit[64];
    struct SB_HEAD sh;
    HMI_MU_INDEX_ELEMENT* paElement_Yx;
    //HMI_MU_INDEX_ELEMENT* paElement_Yk;
    //HMI_MU_INDEX_ELEMENT* paElement_Yt;
    //HMI_MU_INDEX_ELEMENT* paElement_Yx_S;
    u_int fig = 0;
    list_no = 1;

    sh.source_app_id = dp->app_id;
    sh.source_task_id = dp->task_id;
    sh.destination_app_id = RDB_APP_ID;
    sh.destination_task_id = 1;

    sys_strseeknext(strp);
    sscanf(&(strp->buf[strp->pos]), "引用表类型=%d", &fig);
    sys_strseeknext(strp);
    //sscanf(&(strp->buf[strp->pos]), "引用表描述=%s", acTmp);
    if (fig > 4)
        return -1;
    sys_strseeknext(strp);
    sscanf(&(strp->buf[strp->pos]), "表元素数目=%d", &item_num);

    if (item_num > MAX_ITEM_NUM || item_num <= 0)
        return -1;
    paElement_Yx = calloc(item_num, sizeof(HMI_MU_INDEX_ELEMENT));

    dp->paYxList = paElement_Yx;
    dp->iYxNums = item_num;

    if (item_num > MAX_ITEM_NUM || item_num <= 0)
        return -1;
    for (i = 0; i < item_num; i++)
    {
        sys_strseeknext(strp);
        sscanf(&(strp->buf[strp->pos]), "引用=%d,%d,%d,%d,%d,%[^,],%f,%[^,],%s", &tmp[0], &tmp[1], &tmp[2], &tmp[3], &tmp[4], acTmp, &coe, up_unit, name);
        paElement_Yx[i].iValType = 9;
        paElement_Yx[i].iDevAddr = tmp[0];
        paElement_Yx[i].iGroup = tmp[1];
        paElement_Yx[i].iItemNo = tmp[2];
        paElement_Yx[i].iYb = tmp[3];
        paElement_Yx[i].fOffset = afReadVal[0];
        paElement_Yx[i].fCeo = afReadVal[1];
        paElement_Yx[i].uVal.float_val = 0;
        paElement_Yx[i].uVal.pp = paElement_Yx[i].uVal.avalue; //调试用
        paElement_Yx[i].coe = coe;
        sprintf(paElement_Yx[i].desc, acTmp);
        sprintf(paElement_Yx[i].updata_unit, up_unit);
        sprintf(paElement_Yx[i].name, name);
        //printf("desc is %s\nname is %s\n",acTmp, name);
        /*/
        hmi_data->coe_Yx[i] = paElement_Yx[i].coe;
        strncpy(hmi_data->desc_Yx + i * 64, paElement_Yx[i].desc, 64);
        strncpy(hmi_data->unit_Yx + i * 64, paElement_Yx[i].updata_unit, 64);
        strncpy(hmi_data->name_Yx + i * 64, paElement_Yx[i].name, 64);
    }*/
    }
    if (event_type != -1)
    {
        ret = rdb_proc_register_list_hook(&sh, dp->app_id, dp->task_id, 0, dp->app_id, list_no, event_type, 0, 0, NULL);
        if (ret != 0)
        {
            mdl_pro_printf("\n sys_createIndexlist err,the prog will exit ");
            sys_exitpro();
        }
    }
    return 0;
}
//创建遥调列表
static int HMI_MU_createYtlist(HMI_MODBUS_UP_STRUCT* dp, struct SYS_STRSTREAM* strp, int event_type)
{
    int	 item_num, i, list_no, ret, tmp[8];
    float afReadVal[2] = { 0,0 };
    char acTmp[64];
    char up_unit[64];
    char name[64];
    struct SB_HEAD sh;
    HMI_MU_INDEX_ELEMENT* paElement;
    u_int fig = 0;
    list_no = 4;

    sh.source_app_id = dp->app_id;
    sh.source_task_id = dp->task_id;
    sh.destination_app_id = RDB_APP_ID;
    sh.destination_task_id = 1;

    sys_strseeknext(strp);
    sscanf(&(strp->buf[strp->pos]), "引用表类型=%d", &fig);
    sys_strseeknext(strp);
    //sscanf(&(strp->buf[strp->pos]), "引用表描述=%s", acTmp);
    if (fig > 4)
        return -1;
    sys_strseeknext(strp);
    sscanf(&(strp->buf[strp->pos]), "表元素数目=%d", &item_num);

    if (item_num > MAX_ITEM_NUM || item_num <= 0)
        return -1;
    paElement = calloc(item_num, sizeof(HMI_MU_INDEX_ELEMENT));

    dp->paYtList = paElement;
    dp->iYtNums = item_num;

    for (i = 0; i < item_num; i++) {
        sys_strseeknext(strp);

        sscanf(&(strp->buf[strp->pos]), "引用=%d,%d,%d,%d,%d,%f,%f,%[^,],%[^,],%s", &tmp[0], &tmp[1], &tmp[2], &tmp[3], &tmp[4], &afReadVal[0], &afReadVal[1], acTmp, up_unit, name);
        paElement[i].iValType = 7;

        paElement[i].iDevAddr = tmp[0];
        paElement[i].iGroup = tmp[1];
        paElement[i].iItemNo = tmp[2];
        paElement[i].iYb = tmp[3];
        paElement[i].fOffset = afReadVal[0];
        paElement[i].fCeo = afReadVal[1];
        paElement[i].uVal.float_val = 0;
        paElement[i].uVal.pp = paElement[i].uVal.avalue; //调试用
        paElement[i].iFirstTrigFlg = 0;
        paElement[i].coe = afReadVal[1];
        sprintf(paElement[i].name, name);
        sprintf(paElement[i].desc, acTmp);
        sprintf(paElement[i].updata_unit, up_unit);
    }
    if (event_type != -1) {
        ret = rdb_proc_register_list_hook(&sh, dp->app_id, dp->task_id, 0, dp->app_id, list_no, event_type, 0, 0, NULL);
        if (ret != 0) {
            mdl_pro_printf("\n sys_createIndexlist err,the prog will exit ");
            sys_exitpro();
        }
    }
    return 0;
}
//创建遥控列表
static int HMI_MU_createYklist(HMI_MODBUS_UP_STRUCT* dp, struct SYS_STRSTREAM* strp, int event_type)
{
    int	 item_num, i, list_no, ret, tmp[8];
    float afReadVal[2] = { 0,0 };
    char acTmp[64];
    char up_unit[64];
    char name[64];
    struct SB_HEAD sh;
    HMI_MU_INDEX_ELEMENT* paElement;
    u_int fig = 0;
    list_no = 3;

    sh.source_app_id = dp->app_id;
    sh.source_task_id = dp->task_id;
    sh.destination_app_id = RDB_APP_ID;
    sh.destination_task_id = 1;

    sys_strseeknext(strp);
    sscanf(&(strp->buf[strp->pos]), "引用表类型=%d", &fig);
    sys_strseeknext(strp);
    //sscanf(&(strp->buf[strp->pos]), "引用表描述=%s", acTmp);
    if (fig > 4)
        return -1;
    sys_strseeknext(strp);
    sscanf(&(strp->buf[strp->pos]), "表元素数目=%d", &item_num);

    if (item_num > MAX_ITEM_NUM || item_num <= 0)
        return -1;
    paElement = calloc(item_num, sizeof(HMI_MU_INDEX_ELEMENT));

    dp->paYkList = paElement;
    dp->iYkNums = item_num;

    for (i = 0; i < item_num; i++) {
        sys_strseeknext(strp);

        sscanf(&(strp->buf[strp->pos]), "引用=%d,%d,%d,%d,%d,%[^,],%[^,],%s", &tmp[0], &tmp[1], &tmp[2], &tmp[3], &tmp[4], acTmp, up_unit ,name);
        paElement[i].iValType = 9;
        paElement[i].iDevAddr = tmp[0];
        paElement[i].iGroup = tmp[1];
        paElement[i].iItemNo = tmp[2];
        paElement[i].iYb = tmp[3];
        paElement[i].fOffset = afReadVal[0];
        paElement[i].fCeo = afReadVal[1];
        paElement[i].uVal.float_val = 0;
        paElement[i].uVal.pp = paElement[i].uVal.avalue; //调试用
        sprintf(paElement[i].name, name);
        sprintf(paElement[i].desc, acTmp);
    }
    if (event_type != -1) {
        ret = rdb_proc_register_list_hook(&sh, dp->app_id, dp->task_id, 0, dp->app_id, list_no, event_type, 0, 0, NULL);
        if (ret != 0) {
            mdl_pro_printf("\n FF_createYklist err,the prog will exit ");
            sys_exitpro();
        }
    }
    return 0;
}
//读软总线
static void HMI_readSoftBus(HMI_MODBUS_UP_STRUCT* dp)
{
    while (1)
    {
        //printf("%d\n", &hmi_data.buf_Yc[1]);
        int len;
        int     msg_head_id;
        u_short	data_len, addr;
        struct  RDB_RESP_DATA* rdb_resp_data_p;
        struct  SOFT_BUS_HEAD* sb_head;
        struct	EXT_HEAD* ext_head_p;
        while (1)
        {
            HMI_getUpData(dp);
            //printf("%f\n", hmi_data->buf_Yc[0]);
            //printf("%f\n", hmi_data->buf_Yc)+sizeof(float);
            len = FBReadElement(&dp->msg_cc, dp->msg_buf, MAX_MSG_LEN);
            for (; len > 0; len = FBReadElement(&dp->msg_cc, dp->msg_buf, MAX_MSG_LEN))
            {
                dp->msg_len = len;
                msg_head_id = dp->msg_buf[0] * 0x1000000 + dp->msg_buf[1] * 0x10000 + dp->msg_buf[2] * 0x100 + dp->msg_buf[3];
                switch (msg_head_id)
                {
                case   	0x68686868:
                    sb_head = (struct  SOFT_BUS_HEAD*)dp->msg_buf;
                    if (sb_head->source_app_id == RDB_APP_ID)
                    {
                        rdb_resp_data_p = (struct RDB_RESP_DATA*)&dp->msg_buf[sizeof(struct SOFT_BUS_HEAD)];
                        switch (NTOHL(rdb_resp_data_p->interface_id))
                        {
                        case RDB_PROC_DISPATCH_TOP:
                        case RDB_PROC_REGISTER_DEVMSG:
                            data_len = NTOHS(rdb_resp_data_p->resp.dev_msg.len);
                            ext_head_p = (struct EXT_HEAD*)rdb_resp_data_p->resp.dev_msg.buf;
                            addr = (ext_head_p->destination_dev_addr[0] << 8) | (ext_head_p->destination_dev_addr[1]);
                            //暂时不处理
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                default:
                    break;
                }
            }
            usleep(10000);
        }

        return;
    }
}

static void HMI_linkProcess(HMI_MODBUS_UP_STRUCT* dp)
{
    while (1)
    {
        HMI_fd103Select(dp);
    }
}

static void HMI_timetask(void)
{
    while (1)
    {
        HMI_uartSetTimeTask();              // 防止修改串口规约时，一个进程没有关掉串口，另外一个进程打开串口失败，造成无法通讯 
        usleep(500000);
    }
}

static int HMI_selectMax(int* p_fd, int num)
{
    int i, select_max_num;

    select_max_num = *p_fd;
    for (i = 1; i < num; i++)
    {
        if (select_max_num < *(p_fd + i))
            select_max_num = *(p_fd + i);
    }

    return (select_max_num + 1);
}

struct HMI_LBC* HMI_createListBuf(enum HMI_LBTYPE type, int max_buf)
{
    struct HMI_LBC* lbcp;
    lbcp = (struct HMI_LBC*)calloc(1, sizeof(struct HMI_LBC));
    if (lbcp == NULL)
    {
        perror("");
        return lbcp;
    }
    lbcp->head = NULL;
    lbcp->end = NULL;
    lbcp->type = type;
    lbcp->max_buf = max_buf;
    lbcp->buf_num = 0;
    return lbcp;
}

int HMI_addListBuf(struct HMI_LBC* lbcp, void* bufp, int key, int size)
{
    struct HMI_LBNODE* lbp;
    char* buf = (char*)bufp;
    int            i;

    if (lbcp->type == REPLACE)
    {
        lbp = lbcp->head;
        while (lbp != NULL)
        {
            if (lbp->key != key)
            {
                lbp = lbp->next;
            }
            else
            {
                for (i = 0; i < lbp->size; i++) lbp->data[i] = buf[i];
                return 0;
            }
        }
    }
    if ((lbcp->buf_num + 1) >= lbcp->max_buf)
        return -1;

    lbp = (struct HMI_LBNODE*)malloc(sizeof(struct HMI_LBNODE) + size);// 此处相当于将lbp->data[1]扩充为size+1
    if (lbp == NULL)   return -1;
    lbp->prev = lbcp->end;
    lbp->next = NULL;
    lbp->size = size;
    lbp->key = key;
    for (i = 0; i < size; i++) lbp->data[i] = buf[i];
    if (lbcp->head == NULL)
    {
        lbcp->head = lbp;
        lbcp->end = lbp;
    }
    else
    {
        lbcp->end->next = lbp;
        lbcp->end = lbp;
    }
    lbcp->buf_num++;
    return 1;
}

void HMI_delListBuf(struct HMI_LBC* lbcp)
{
    struct HMI_LBNODE* lbp;
    if (!lbcp->head) return;

    lbp = lbcp->head;
    if (lbcp->head == lbcp->end)  //buf_num==1 or 0
    {
        lbcp->head = NULL;
        lbcp->end = NULL;
    }
    else
    {
        lbcp->head = lbcp->head->next;
        lbcp->head->prev = NULL;
    }
    lbcp->buf_num--;
    free(lbp);
    lbcp = 0;
}

void HMI_delListBufByPtr(struct HMI_LBC* lbcp, struct HMI_LBNODE* ptr)
{
    if (!lbcp || !ptr) return;

    if (!ptr->prev)
    {
        HMI_delListBuf(lbcp);
        return;
    }
    if (lbcp->end == ptr)lbcp->end = ptr->prev;
    ptr->prev->next = ptr->next;
    lbcp->buf_num--;
    free(ptr);
}

void HMI_delListBuflAll(struct HMI_LBC* lbcp)
{
    //    int cnt=0;
    //
    //    if(!lbcp->head) return;
    //
    //    while(lbcp->head && cnt<lbcp->max_buf)
    //    {
    //        delListBuf(lbcp);
    //        cnt++;
    //    }
    //
    //    if(lbcp->head || lbcp->buf_num)
    //        printf("ERROR: delListBuflAll\n");

    if (!lbcp->head) return;
    while (lbcp->head)
    {
        HMI_delListBuf(lbcp);
    }

    return;
}

struct HMI_LBNODE* HMI_searchNode(struct HMI_LBC* lbcp, unsigned int key)
{
    struct HMI_LBNODE* lbp;

    lbp = lbcp->head;
    while (lbp != NULL)
    {
        if (lbp->key == key)return lbp;
        lbp = lbp->next;
    }
    return NULL;
}

static void HMI_updateFd103Set()
{
    int i;

    dp->max_fd_103 = -1;
    FD_ZERO(&dp->read_set_save_103);

    for (i = 0; i < MAX_FD103; i++)
    {
        if ((dp->fdt_103[i].active == ACTIVE_NOW) && (dp->fdt_103[i].fd > 0))
        {
            FD_SET(dp->fdt_103[i].fd, &dp->read_set_save_103);
            if (dp->fdt_103[i].fd > dp->max_fd_103) dp->max_fd_103 = dp->fdt_103[i].fd;
        }
        else
        {
            dp->fdt_103[i].active = ACTIVE_LATER;
            dp->fdt_103[i].fd = -1;
        }
    }
}

static int HMI_addFd103Node(int fd, void (*func)(void*), void* arg, int is_active_now)
{
    int i;
    for (i = 0; i < MAX_FD103; i++)
    {
        if (dp->fdt_103[i].fd <= 0 && dp->fdt_103[i].active == ACTIVE_LATER)
        {
            dp->fdt_103[i].fd = fd;
            dp->fdt_103[i].read = func;
            dp->fdt_103[i].arg = arg;
            dp->fdt_103[i].last_active_time = sys_get_soft_timer();
            dp->fdt_103[i].rd_cursor = 0;
            dp->fdt_103[i].active = is_active_now;
            HMI_updateFd103Set(dp);
            return 1;
        }
    }
    if (i == MAX_FD103)
    {
        printf("[HMI_ up] ERROR: fd=%d over max\n", fd);
        return 0;
    }
}

static int HMI_delFd103Node(int fd)
{
    int i;
    for (i = 0; i < MAX_FD103; i++)
    {
        if (dp->fdt_103[i].fd == fd)
        {
            dp->fdt_103[i].fd = -1;
            dp->fdt_103[i].active = ACTIVE_LATER;
        }
    }
    HMI_updateFd103Set();

    return 1;
}

static inline unsigned char HMI_getChar(char* data, int* offset)
{
    unsigned char value;

    value = *(unsigned char*)(data + *offset);
    (*offset)++;

    return value;
}

static void HMI_fd103Select()
{
    int i, fd_num;
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 100000;

    dp->read_set_103 = dp->read_set_save_103;
    fd_num = select(dp->max_fd_103 + 1, &dp->read_set_103, NULL, NULL, &tv);

    for (i = 0; i < MAX_FD103; i++)
    {
        if ((dp->fdt_103[i].active == ACTIVE_NOW) && (dp->fdt_103[i].fd > 0) && (dp->fdt_103[i].read == dp->modbus_rtu_readUartData_fun))
        {
            //modbus_rtu_check_timer(&dp->fdt_103[i]);
        }
    }

    if (fd_num <= 0) return;

    for (i = 0; i < MAX_FD103; i++)
    {
        if ((dp->fdt_103[i].active == ACTIVE_NOW) && (dp->fdt_103[i].fd > 0))
        {
            if (FD_ISSET(dp->fdt_103[i].fd, &dp->read_set_103))
            {
                dp->fdt_103[i].read(&dp->fdt_103[i]);
                fd_num--;
                if (fd_num == 0) break;
            }
        }
    }
}

static void HMI_getUpData(HMI_MODBUS_UP_STRUCT* dp)
{
    if (init_success == 0)
    {
        return;
    }
    int i, j;
    double unit, tmp;
    uint32_t bnum, iStNum = 0;
    float fdatap[256];
    uint8_t cdatap[256];
    uint8_t quality[256];
    int count_Yx, count_Yk, count_Yt, count_Dz;
    int ret = -1;

    bnum = (dp->iYcNums - iStNum);
    while (bnum > 0)
    {
        bnum = (bnum > 256) ? 256 : bnum;
        ret = rdb_proc_readYC_float(&(dp->sh), dp->app_id, 0,
            iStNum, bnum, &bnum, fdatap, quality);
        if (ret < 0)
            break;
        for (i = 0; i < bnum; i++)
        {
            HMI_MU_INDEX_ELEMENT* pElement = &(dp->paYcList[i + iStNum]);
            pElement->uVal.float_val = fdatap[i]; //fdatap[i] * pElement->fCeo + pElement->fOffset;
            hmi_data->buf_Yc[i] = pElement->uVal.float_val;  //可能需要修改
            //printf("name:%s,type:%s,NO:%d,buf:%f\n",hmi_data->name_Yc+i*64,hmi_data->desc_Yc+i*64,pElement->iItemNo,pElement->uVal.float_val);
        }

        iStNum += bnum;
        bnum = (dp->iYcNums - iStNum);
    }

    iStNum = 0;
    bnum = (dp->iYxNums - iStNum);


    while (bnum > 0)
    {
        bnum = (bnum > 256) ? 256 : bnum;
        ret = rdb_proc_readYX(&(dp->sh), dp->app_id, 1,
            iStNum, bnum, &bnum, cdatap);
        if (ret < 0)
            break;
        for (i = 0; i < bnum; i++)
        {
            HMI_MU_INDEX_ELEMENT* pElement = &(dp->paYxList[i + iStNum]);
            pElement->uVal.cuVal = cdatap[i]; //fdatap[i] * pElement->fCeo + pElement->fOffset;
            hmi_data->buf_Yx[i] = pElement->uVal.cuVal;  //可能需要修改
            //printf("hmi_data->buf_Yx[%d]=%f\n",i,hmi_data->buf_Yx[i]);
        }


        iStNum += bnum;
        bnum = (dp->iYxNums - iStNum);
    }


    select_Y(hmi_data);
    //printf("select success\n");
    //for (i = 0; i < 6; i++)
    {
        //printf("%s is %f\n", hmi_data->name_Yc + i * 64, hmi_data->buf_Yx[i]);
    }

}

void select_Y(hmi_updata_struct* hmi_data)
{
    int count=hmi_data->num_Yc;
    int count_yc=0;
    int count_dz=0;
    int count_yt=0;
    for(int i=0;i<count;i++)
    {
        if(strcmp(hmi_data->desc_Yc + i * 64, "YC") == 0)
        {
            hmi_data->buf_Ycc[count_yc] = (hmi_data->buf_Yc[i]);
            //strncpy(hmi_data->desc_Ycc + count_yc * 64, hmi_data->desc_Yc + i * 64, 64);
            //strncpy(hmi_data->unit_Ycc + count_yc * 64, hmi_data->unit_Yc + i * 64, 64);
            //hmi_data->coe_Ycc[count_yc] = (hmi_data->coe_Yc[i]);
            //strncpy(hmi_data->name_Ycc + count_yc * 64, hmi_data->name_Yc + i * 64, 64);
            count_yc++;
        }
        else if(strcmp(hmi_data->desc_Yc + i * 64, "DZ") == 0)
        {
            //hmi_data->buf_Yx_S[count_dz] = (hmi_data->buf_Yc[i]);
            //strncpy(hmi_data->desc_Yx_S + count_dz * 64, hmi_data->desc_Yc + i * 64, 64);
            //strncpy(hmi_data->unit_Yx_S + count_dz * 64, hmi_data->unit_Yc + i * 64, 64);
            //hmi_data->coe_Yx_S[count_dz] = (hmi_data->coe_Yc[i]);
            //strncpy(hmi_data->name_Yx_S + count_dz * 64, hmi_data->name_Yc + i * 64, 64);
            count_dz++;
        }
        else if(strcmp(hmi_data->desc_Yc + i * 64, "YT") == 0)
        {
            hmi_data->buf_Yt[count_yt] = (hmi_data->buf_Yc[i]);
            count_yt++;

        }
    }
    //hmi_data->num_Ycc=count_yc;
    //hmi_data->num_Yx_S=count_dz;
    int cou=hmi_data->num_Yx;
    int count_yk=0;
    for(int i=0;i<cou;i++)
    {
        if(strcmp(hmi_data->desc_Yc + i * 64, "YK") == 0)
        {
            hmi_data->buf_Yk[count_yk] = (hmi_data->buf_Yx[i]);
            //strncpy(hmi_data->desc_Ycc + count_yc * 64, hmi_data->desc_Yc + i * 64, 64);
            //strncpy(hmi_data->unit_Ycc + count_yc * 64, hmi_data->unit_Yc + i * 64, 64);
            //hmi_data->coe_Ycc[count_yc] = (hmi_data->coe_Yc[i]);
            //strncpy(hmi_data->name_Ycc + count_yc * 64, hmi_data->name_Yc + i * 64, 64);
            count_yk++;
        }
    }
}
static u_char HMI_MU_YkYtCmdToSBus(HMI_MODBUS_UP_STRUCT* dp, HMI_MU_INDEX_ELEMENT* pControl, u_char iTbid, u_short iSqno)
{
    u_char send_buf[300];
    int ret, length;
    struct  EXT_ASDU10* asdu10_p;
    asdu10_p = (struct EXT_ASDU10*)send_buf;
    asdu10_p->head.source_factory_addr[0] = MSB(sys_factory_addr);
    asdu10_p->head.source_factory_addr[1] = LSB(sys_factory_addr);
    asdu10_p->head.source_dev_addr[0] = 0;
    asdu10_p->head.source_dev_addr[1] = iTbid;  //表号
    asdu10_p->head.destination_factory_addr[0] = MSB(sys_factory_addr);
    asdu10_p->head.destination_factory_addr[1] = LSB(sys_factory_addr);
    asdu10_p->head.cpu_no = 0x80;
    asdu10_p->head.sec_no = 0xfe;
    asdu10_p->head.reserve[0] = 0x01; //直控
    asdu10_p->head.reserve[1] = LSB(iSqno);
    asdu10_p->head.destination_dev_addr[0] = MSB(pControl->iDevAddr);
    asdu10_p->head.destination_dev_addr[1] = LSB(pControl->iDevAddr);
    asdu10_p->asdu_type = 10;
    asdu10_p->vsq = 0x81;
    asdu10_p->cot = 40;
    asdu10_p->address = LSB(pControl->iDevAddr);
    if (pControl->iStatus == 1) {
        asdu10_p->fun = 254;
        asdu10_p->inf = 249;
    }
    else if (pControl->iStatus == 3) {
        asdu10_p->fun = 254;
        asdu10_p->inf = 250;
    }
    else if (pControl->iStatus == 5) {
        asdu10_p->fun = 254;
        asdu10_p->inf = 251;
    }
    else
    {
    }
    asdu10_p->RII = 0x00;
    asdu10_p->NGD = 1;
    asdu10_p->GIN[0] = pControl->iGroup;
    asdu10_p->GIN[1] = pControl->iItemNo;
    asdu10_p->KOD = 1;
    asdu10_p->GDD0 = pControl->iValType;  //数据类型
    asdu10_p->GDD2 = 1;   //数据个数

    float flt_val;
    flt_val = *((float*)pControl->uVal.pp);
    flt_val = flt_val * pControl->fCeo + pControl->fOffset;
    memcpy(pControl->uVal.pp, &flt_val, 4);

    if (pControl->iValType == 3)  //无符号整数 整数
    {
        asdu10_p->GDD1 = 2;   //数据宽度
        memcpy(&(asdu10_p->GID[0]), pControl->uVal.pp, 2);
    }
    else if (pControl->iValType == 7)  //浮点数
    {
        asdu10_p->GDD1 = 4;
        //memcpy(&(asdu10_p->GID[0]), pControl->uVal.pp, 4);
        memcpy(&(asdu10_p->GID[0]), pControl->uVal.pp, 4);
    }
    else if (pControl->iValType == 9) //单点，双点
    {
        asdu10_p->GDD1 = 1;
        memcpy(&(asdu10_p->GID[0]), pControl->uVal.avalue, 1);
    }
    else
    {
        asdu10_p->GDD0 = 0;
        asdu10_p->GDD1 = 0;
        printf("NNNNNNNNNNNo support fast frequency data type! \n");
    }
    //printf("dev info =%d group=%d item=%d \n", asdu10_p->address, asdu10_p->GIN[0], asdu10_p->GIN[1]);
    length = sizeof(struct EXT_ASDU10) + asdu10_p->GDD1 - 1;

    ret = rdb_proc_dispatch_top(&(dp->sh), 0, length, send_buf);
    if (ret < 0) {
        return(CM_NO);
    }
    else {
        return(CM_YES);
    }
}

static void HMI_readUartData(HMI_FD103* dp)
{
    int length;
    struct HMI_UART* p_uart;

    p_uart = (struct HMI_UART*)(dp->arg);
    length = read(dp->fd, dp->buf + dp->rd_cursor, sizeof(dp->buf) - dp->rd_cursor);
    if (length <= 0)
    {
        perror("HMI SYS: uart read");
        return;
    }

    p_uart->recv_data++;

    dp->rd_cursor += length;

    if (p_uart->protocol == RS485_MODBUS)
    {
        HMI_processUartData(dp, p_uart);
    }
    else         // 不支持的通讯协议
        dp->rd_cursor = 0;

    return;
}

void HMI_processUartData(HMI_FD103* dp, struct HMI_UART* p_uart)
{
    int i;

    Uint16 crc_sum;
    Uint8 fun_code;
    Uint8 crc_pos;

    while (dp->rd_cursor >= 8)
    {
        if (dp->buf[0] == p_uart->com_addr)
        {
            if (p_uart->wait_recvall_flag == 0)
            {
                p_uart->wait_recvall_flag = 1;
                sys_get_tval(&p_uart->check_time);
                p_uart->check_time = sys_add_tvalUs(&p_uart->check_time, 300000);
            }

            fun_code = dp->buf[1];
            if (fun_code == 0x10)
            {
                crc_pos = 7 + dp->buf[6];
                if ((crc_pos + 2) > dp->rd_cursor)
                {
                    break;
                }
            }
            else
            {
                crc_pos = 6;
            }

            if (dp->rd_cursor >= crc_pos + 2)
            {
                p_uart->wait_recvall_flag = 0;

                p_uart->app_modbus->received_frame++;
                crc_sum = 0xFFFF;
                for (i = 0; i < crc_pos; i++)
                    crc_sum = CRC16(dp->buf[i], crc_sum);
                if ((LSB(crc_sum) == dp->buf[crc_pos])
                    && (MSB(crc_sum) == dp->buf[crc_pos + 1]))
                {
                    //HMI_procModbusFrame(p_uart, (Uint8*)(dp->buf + 1));  //跳过slave_addr
                    dp->rd_cursor -= (crc_pos + 2);
                    memmove(dp->buf, dp->buf + crc_pos + 2, dp->rd_cursor);
                }
                else
                {
                    dp->buf[0] = 0xFF;
                    p_uart->app_modbus->crc_error_frame++;
                    goto Error_Modbus;
                }
            }
            else
            {
                break;
            }
        }
        else
        {
        Error_Modbus:

            for (i = 0; i < dp->rd_cursor; i++)
            {
                if (dp->buf[i] == p_uart->com_addr)
                {
                    memmove(dp->buf, dp->buf + i, dp->rd_cursor - i);
                    break;
                }
            }

            if (i >= dp->rd_cursor) dp->rd_cursor = 0;
            else dp->rd_cursor -= i;
        }
    }
}

static void HMI_newUart(HMI_MODBUS_UP_STRUCT* dp)
{
    int i;

    for (i = 0; i < MAX_RS485 - 1; i++)
    {
        dp->uart[i].com_id = -1;
        dp->uart[i].protocol = RS485_MODBUS;
        dp->uart[i].app_modbus = &dp->modbus[i];
        dp->uart[i].com_fd = -1;
        dp->uart[i].last_baudrate = 0xFFFFFFFF;
        dp->uart[i].last_protocol = 0xFFFFFFFF;
        dp->uart[i].com_addr = 0;
        dp->uart[i].delay_time = 10000;

        dp->uart[i].wait_recvall_flag = 0;
    }

    //增加modbus配置参数初始化

    dp->uart[0].com_fd = -1;
    dp->uart[1].com_fd = -1;

    dp->modbus_rtu_readUartData_fun = HMI_readUartData;

    return;
}

static int HMI_uartSet(struct HMI_UART* dp)
{
    struct	SYS_COM_INIT com_info;

    if (dp->com_id < 0)
        return -1;

    if (dp->protocol != RS485_MODBUS)
    {
        if (dp->com_fd > 0)
        {
            HMI_delFd103Node(dp->com_fd);
            close(dp->com_fd);
            dp->com_fd = -1;
        }
        dp->last_baudrate = dp->baudrate;
        dp->last_protocol = dp->protocol;
        return 0;
    }

    dp->last_baudrate = dp->baudrate;
    dp->last_protocol = dp->protocol;

    // 等待500ms后打开
    usleep(500000);

    if (dp->com_fd > 0) return 0;

    com_info.bps = dp->last_baudrate;
    com_info.parity = 0;
    com_info.data = 8;
    com_info.stop = 1;
    dp->com_fd = init_uart(dp->com_id, &com_info);
    dp->wr_fd = dp->com_fd;// 对于RS485A,RS485B而言,读写fd为相同的
    if (dp->com_fd < 0)
    {
        perror("HMI_ SYS: uart open()");
        return -1;
    }

    HMI_addFd103Node(dp->com_fd, (void*)HMI_readUartData, dp, ACTIVE_NOW);

    return 0;
}

static void HMI_uartSetTimeTask()
{
    int i;
    for (i = 0; i < MAX_RS485 - 1; i++)
    {
        if (dp->uart[i].protocol == RS485_MODBUS)
        {
            if (dp->uart[i].com_fd < 0)
            {
                HMI_uartSet(&dp->uart[i]);
            }
        }
    }

    return;
}

void data_cpy(hmi_updata_struct* hmi_data)
{
    int countYc, countYx, countYk ,countYt;
    //if (init_success == 0)return;
    countYc = hmi_data->num_Yc;
    countYx = hmi_data->num_Yx;
    countYk = hmi_data->num_Yk;
    countYt = hmi_data->num_Yt;
    int count_yc=0;
    int count_dz=0;
    for (int i = 0; i < countYc; i++)
    {
        hmi_data->coe_Yc[i] = dp->paYcList[i].coe;
        strncpy(hmi_data->desc_Yc + i * 64, dp->paYcList[i].desc, 64);
        strncpy(hmi_data->unit_Yc + i * 64, dp->paYcList[i].updata_unit, 64);
        strncpy(hmi_data->name_Yc + i * 64, dp->paYcList[i].name, 64);
    }
    for (int ii = 0; ii < countYc; ii++)
    {
        if(strcmp(hmi_data->desc_Yc + ii * 64, "YC") == 0)
        {
            //hmi_data->buf_Ycc[count_yc] = (hmi_data->buf_Yc[i]);
            strncpy(hmi_data->desc_Ycc + count_yc * 64, hmi_data->desc_Yc + ii * 64, 64);
            strncpy(hmi_data->unit_Ycc + count_yc * 64, hmi_data->unit_Yc + ii * 64, 64);
            hmi_data->coe_Ycc[count_yc] = (hmi_data->coe_Yc[ii]);
            strncpy(hmi_data->name_Ycc + count_yc * 64, hmi_data->name_Yc + ii * 64, 64);
            count_yc++;
        }
        else if(strcmp(hmi_data->desc_Yc + ii * 64, "DZ") == 0)
        {
            //hmi_data->buf_Yx_S[count_dz] = (hmi_data->buf_Yc[i]);
            strncpy(hmi_data->desc_Yx_S + count_dz * 64, hmi_data->desc_Yc + ii * 64, 64);
            strncpy(hmi_data->unit_Yx_S + count_dz * 64, hmi_data->unit_Yc + ii * 64, 64);
            hmi_data->coe_Yx_S[count_dz] = (hmi_data->coe_Yc[ii]);
            strncpy(hmi_data->name_Yx_S + count_dz * 64, hmi_data->name_Yc + ii * 64, 64);
            count_dz++;
        }
        hmi_data->num_Ycc=count_yc;
        hmi_data->num_Yx_S=count_dz;
    }
    for (int j = 0; j < countYx; j++)
    {
        hmi_data->coe_Yx[j] = dp->paYxList[j].coe;
        strncpy(hmi_data->desc_Yx + j * 64, dp->paYxList[j].desc, 64);
        strncpy(hmi_data->unit_Yx + j * 64, dp->paYxList[j].updata_unit, 64);
        strncpy(hmi_data->name_Yx + j * 64, dp->paYxList[j].name, 64);

    }
        printf("cpy_yx_success\n");
    for (int m = 0; m < countYk; m++)
    {
        hmi_data->coe_Yk[m] = dp->paYkList[m].coe;
        strncpy(hmi_data->desc_Yk + m * 64, dp->paYkList[m].desc, 64);
        strncpy(hmi_data->unit_Yk + m * 64, dp->paYkList[m].updata_unit, 64);
        strncpy(hmi_data->name_Yk + m * 64, dp->paYkList[m].name, 64);
        printf("%s\n",dp->paYkList[m].name);

    }
    printf("cpy_yk_success\n");
    for (int n = 0; n < countYt; n++)
    {
        hmi_data->coe_Yt[n] = dp->paYtList[n].coe;
        strncpy(hmi_data->desc_Yt + n * 64, dp->paYtList[n].desc, 64);
        strncpy(hmi_data->unit_Yt + n * 64, dp->paYtList[n].updata_unit, 64);
        strncpy(hmi_data->name_Yt + n * 64, dp->paYtList[n].name, 64);

    }
    printf("cpy_yt_success\n");
    return hmi_data;
    }

hmi_updata_struct* get_hmi_data() 
{
    return hmi_data;
}
