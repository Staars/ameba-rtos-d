include $(MAKE_INCLUDE_GEN)

.PHONY: all clean

#*****************************************************************************#
#                               VARIABLES	                              #
#*****************************************************************************#

#*****************************************************************************#
#                        RULES TO GENERATE TARGETS                            #
#*****************************************************************************#
all:
	@$(MAKE) -C test all
	@$(MAKE) -C os all
	@$(MAKE) -C monitor all
	@$(MAKE) -C target all
	@$(MAKE) -C cmsis all
	@$(MAKE) -C project all
ifeq ($(CONFIG_APP_DEMO),y)
	#@$(MAKE) -C example all
endif

#*****************************************************************************#
#              CLEAN GENERATED FILES                                          #
#*****************************************************************************#
clean:
	@$(MAKE) -C test clean
	@$(MAKE) -C os clean
	@$(MAKE) -C monitor clean
	@$(MAKE) -C bootloader clean
	@$(MAKE) -C target clean
	@$(MAKE) -C cmsis clean
	@$(MAKE) -C RT_xmodem clean
	#@$(MAKE) -C example clean
	@$(MAKE) -C project clean

-include $(DEPS)
