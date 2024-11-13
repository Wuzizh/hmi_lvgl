LVGL_DIR_NAME ?= lvgl
LVGL_DIR ?= ${shell pwd}/hmi

include $(LVGL_DIR)/lvgl/lvgl.mk

include $(LVGL_DIR)/lv_drivers/lv_drivers.mk

include $(LVGL_DIR)/generated/generated.mk

CSRCS += $(notdir $(wildcard $(LVGL_DIR)/*.c))

DEPPATH += --dep-path $(LVGL_DIR)

VPATH += $(LVGL_DIR)

CFLAGS += -I$(LVGL_DIR) -I../updata