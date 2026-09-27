include $(MAKE_INCLUDE_GEN)

.PHONY: all clean

#*****************************************************************************#
#                               VARIABLES	                              #
#*****************************************************************************#

#*****************************************************************************#
#                        RULES TO GENERATE TARGETS                            #
#*****************************************************************************#
all:
ifeq ($(CONFIG_BT_EN),y)
	@$(MAKE) -C rtl_bluetooth all
endif
ifeq ($(CONFIG_WIFI_EN),y)
	@$(MAKE) -C network all
	@$(MAKE) -C api all
	@$(MAKE) -C wlan all
endif
ifeq ($(CONFIG_USB_OTG_EN),y)
	@$(MAKE) -C usb_otg all
endif

	@$(MAKE) -C utilities all
	@$(MAKE) -C test all
	@$(MAKE) -C os all

ifeq ($(CONFIG_MBED_TLS_ENABLED),y)
	@$(MAKE) -C mbedtls all
endif

ifeq ($(CONFIG_GUI_EN),y)
	@$(MAKE) -C ui all
endif

ifeq ($(CONFIG_LINKKIT_AWSS),y)
	@$(MAKE) -C linkkit all
endif
	#@$(MAKE) -C bootloader all
	@$(MAKE) -C app all
	@$(MAKE) -C target all
	@$(MAKE) -C drivers all
	@$(MAKE) -C cmsis all
	@$(MAKE) -C mbed all
	@$(MAKE) -C audio all
	#@$(MAKE) -C audio test
	@$(MAKE) -C graphic all
	#@$(MAKE) -C media all
	@$(MAKE) -C utilities_example all
	@$(MAKE) -C file_system all
	@$(MAKE) -C project all
	@$(MAKE) -C application all
	#@$(MAKE) -C cmsis-dsp all
#*****************************************************************************#
#              CLEAN GENERATED FILES                                          #
#*****************************************************************************#
clean:
	@$(MAKE) -C application clean
	@$(MAKE) -C wlan clean
	@$(MAKE) -C wps clean
	@$(MAKE) -C network clean
	@$(MAKE) -C api clean
	@$(MAKE) -C utilities clean
	@$(MAKE) -C test clean
	@$(MAKE) -C os clean
	@$(MAKE) -C ssl clean
	@$(MAKE) -C mbedtls clean
	@$(MAKE) -C mbed clean
	@$(MAKE) -C app clean
	@$(MAKE) -C bootloader clean
	@$(MAKE) -C drivers clean
	@$(MAKE) -C target clean
	@$(MAKE) -C rtl_bluetooth clean
	@$(MAKE) -C cmsis clean
	@$(MAKE) -C cmsis-dsp clean
	@$(MAKE) -C mbed clean
	@$(MAKE) -C audio clean
	@$(MAKE) -C graphic clean
	@$(MAKE) -C utilities_example clean
	@$(MAKE) -C file_system clean
	@$(MAKE) -C project clean
	@$(MAKE) -C ui clean
	@$(MAKE) -C media clean
	@$(MAKE) -C video clean
	@$(MAKE) -C usb_otg clean
-include $(DEPS)
