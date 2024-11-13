# images
include $(LVGL_DIR)/generated/images/images.mk

# GUI Guider fonts
include $(LVGL_DIR)/generated/guider_fonts/guider_fonts.mk

# GUI Guider customer fonts
include $(LVGL_DIR)/generated/guider_customer_fonts/guider_customer_fonts.mk


CSRCS += $(notdir $(wildcard $(LVGL_DIR)/generated/*.c))

DEPPATH += --dep-path $(LVGL_DIR)/generated
VPATH += :$(LVGL_DIR)/generated

CFLAGS += "-I$(LVGL_DIR)/generated" -I./updata