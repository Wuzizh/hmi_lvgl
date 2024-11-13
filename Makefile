CC = arm-linux-gnueabihf-gcc
CFLAGS = -I./include -I./hmi -I./updata
LDFLAGS ?= ./lib/librtcomm.a ./lib/libcomm_lib.a -lm -lpthread
BIN = demo
MAINSRC = ./main.c
HMI_UPDATA_SRC = ./updata/hmi_updata.c
include ./hmi/lvgll.mk
#include ./updata/up.mk
OBJEXT ?= .o
AOBJS = $(ASRCS:.S=$(OBJEXT))
COBJS = $(CSRCS:.c=$(OBJEXT)) $(HMI_UPDATA_SRC:.c=$(OBJEXT))
MAINOBJ = $(MAINSRC:.c=$(OBJEXT))
SRCS = $(ASRCS) $(CSRCS) $(MAINSRC)
OBJS = $(AOBJS) $(COBJS)
%.o: %.c
	@$(CC)  $(CFLAGS) -c $< -o $@
	@echo "CC $<"  
default:$(AOBJS) $(COBJS) $(MAINOBJ)
	$(CC) -o $(BIN) $(MAINOBJ) $(AOBJS) $(COBJS) $(LDFLAGS)
clean: 
	rm -f $(BIN) $(AOBJS) $(COBJS) $(MAINOBJ)