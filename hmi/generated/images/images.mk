-include $(LVGL_DIR)/generated/images/images_list.mk
-include $(LVGL_DIR)/generated/images/lottie_list.mk

DEPPATH += --dep-path $(LVGL_DIR)/generated/images
VPATH += :$(LVGL_DIR)/generated/images

CFLAGS += "-I$(LVGL_DIR)/generated/images"