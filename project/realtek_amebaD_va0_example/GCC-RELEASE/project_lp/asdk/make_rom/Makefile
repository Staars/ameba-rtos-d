include $(MAKE_INCLUDE_GEN)

.PHONY: all clean

#*****************************************************************************#
#                               VARIABLES	                              #
#*****************************************************************************#
GLOBAL_CFLAGS += -DCONFIG_BUILD_ROM

#*****************************************************************************#
#                        RULES TO GENERATE TARGETS                            #
#*****************************************************************************#
all:
	$(MAKE) -C vector all
	$(MAKE) -C fwlib all
	$(MAKE) -C monitor all
	$(MAKE) -C xmodem all
	$(MAKE) -C string all
	$(MAKE) -C wifi_fw all

#*****************************************************************************#
#              CLEAN GENERATED FILES                                          #
#*****************************************************************************#
clean:
	$(MAKE) -C vector clean
	$(MAKE) -C fwlib clean
	$(MAKE) -C monitor clean
	$(MAKE) -C xmodem clean
	$(MAKE) -C string clean
	$(MAKE) -C wifi_fw clean

-include $(DEPS)
