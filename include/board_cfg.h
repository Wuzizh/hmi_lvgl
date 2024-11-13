/********************************************************************
	created:	2017/10/11
	created:	11:10:2017   22:31
	filename: 	\\192.168.213.129\prog\lv_pb_plat\lv_pb_plat\inc\check_code.h
	file path:	\\192.168.213.129\prog\lv_pb_plat\lv_pb_plat\inc
	file base:	check_code
	file ext:	h
	author:		zhouxf
	purpose:	board config
*********************************************************************/
#ifndef _BOARD_CFG_H_
#define _BOARD_CFG_H_

/* CPU�ӿ� */
#define NET_NUM				4	/* ������ */
#define UART_NUM			7	/* ������ */

/* ��չ���� */
#define EX_UART_NUM			9	/* ��չ������ */

/* ��IP�������� */
enum ip_x_e {
	ip1_prot = 0,
	ip2_comm,
	ip3_comm,

	IP_NUM_PER_IF			/* ÿ������ӿڵ�IP�� */
};

enum gw_x_e {
	gw1_prot = 0,
	gw2_comm,
	gw3_comm,

	GW_NUM_PER_IF			/* ÿ�����ڽӿڵ������� */
};

#define BASE_DIR			"../"

#define PROTECT_DIR			BASE_DIR"/protect"
#define COMM_DIR			BASE_DIR"/comm"
#define GENERAL_DIR			BASE_DIR"/general"
#define KO_DIR				BASE_DIR"/ko"

#define BOARD_CFG			BASE_DIR"/.bc.cfg"

/* OUI: zit */
#define OUI_ZD_0			0x7a
#define OUI_ZD_1			0x69
#define OUI_ZD_2			0x74
#define MAC_ZD_STR1			"7a:69:74:00:20:00"
#define MAC_ZD_STR2			"7a:69:74:01:20:00"
#define MAC_ZD_STR3			"7a:69:74:02:20:00"
#define MAC_ZD_STR4			"7a:69:74:03:20:00"
#define MAC_ZD_ADDR1		"\x7a\x69\x74\x00\x20\x00"
#define MAC_ZD_ADDR2		"\x7a\x69\x74\x01\x20\x00"
#define MAC_ZD_ADDR3		"\x7a\x69\x74\x02\x20\x00"
#define MAC_ZD_ADDR4		"\x7a\x69\x74\x03\x20\x00"

typedef unsigned char mac_addr_t1 [6];		/* another name for mac_addr_t */

typedef struct board_config_s {
	mac_addr_t1		if_mac_addr [NET_NUM];
	unsigned int	prot_uart_distrbt;
	unsigned int	comm_uart_distrbt;
	unsigned int	prot_eth_distrbt;
	unsigned int	comm_eth_distrbt;
	unsigned int	ip_addr [NET_NUM][IP_NUM_PER_IF];
	unsigned int	subnet_mask [NET_NUM][IP_NUM_PER_IF];
	unsigned int	dst_net [NET_NUM][GW_NUM_PER_IF];
	unsigned int	gw_mask [NET_NUM][GW_NUM_PER_IF];
	unsigned int	gateway [NET_NUM][GW_NUM_PER_IF];
	unsigned int	ring_mask;
	unsigned int	fiber_mask;
} board_config_t;

/********************************************************************/
/*                         board cfg                                */
/********************************************************************/

#define ETH_MAC_ADDR			"MAC_ADDR_%d"
#define PROT_UART_DISTRBT_CN	"�������ڷ���"
#define COMM_UART_DISTRBT_CN	"ͨ�Ŵ��ڷ���"
#define PROT_ETH_DISTRBT_CN		"�������ڷ���"
#define COMM_ETH_DISTRBT_CN		"ͨ�����ڷ���"
#define IFx_IPx_CN				"����%dIP%d"
#define IFx_MASKx_CN			"����%d����%d"
#define IFx_DSTNETx_CN			"����%dĿ������%d"
#define IFx_GWMASKx_CN			"����%d��������%d"
#define IFx_GWx_CN				"����%d����%d"
#define RING_MASK_CN			"��������"
#define FIBER_MASK_CN			"���˿�����"

/********************************************************************/

extern board_config_t g_para;

/* g_para����ΪĬ�� */
int reset_board_cfg ();

/* ��ȡg_para���� */
int open_board_cfg ();

/* ����g_para���� */
int save_board_cfg ();

/* g_paraУ�� */
int check_board_cfg ();

/* ��ӡg_para */
int show_board_cfg ();

#endif /* _BOARD_CFG_H_ */
