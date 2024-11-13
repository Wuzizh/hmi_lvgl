GEN_CSRCS += $(notdir $(wildcard $(LVGL_DIR)/generated/guider_customer_fonts/*.c))

DEPPATH += --dep-path $(LVGL_DIR)/generated/guider_customer_fonts
VPATH += :$(LVGL_DIR)/generated/guider_customer_fonts

CFLAGS += "-I$(LVGL_DIR)/generated/guider_customer_fonts"