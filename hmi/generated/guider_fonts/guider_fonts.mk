-include $(LVGL_DIR)/generated/guider_fonts/fonts_list.mk

DEPPATH += --dep-path $(LVGL_DIR)/generated/guider_fonts
VPATH += :$(LVGL_DIR)/generated/guider_fonts

CFLAGS += "-I$(LVGL_DIR)/generated/guider_fonts"