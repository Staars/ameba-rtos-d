include $(MAKE_INCLUDE_GEN)

.PHONY: all clean

#*****************************************************************************#
#                               VARIABLES	                              #
#*****************************************************************************#

#*****************************************************************************#
#                        RULES TO GENERATE TARGETS                            #
#*****************************************************************************#
all:
ifeq ($(CONFIG_TRUSTZONE), y)
	@$(MAKE) -C img3 all
	@$(MAKE) -C test all
	@$(MAKE) -C crypto all
	@$(MAKE) -C os all
ifeq ($(CONFIG_MATTER_SECURE_EN),y)
	@$(MAKE) -C $(MATTER_BUILDDIR)/make/mbedtls_secure all
else
	#@$(MAKE) -C mbedtls all
endif
endif

#*****************************************************************************#
#              CLEAN GENERATED FILES                                          #
#*****************************************************************************#
clean:
	@$(MAKE) -C img3 clean
	@$(MAKE) -C test clean
	@$(MAKE) -C crypto clean
	@$(MAKE) -C os clean
ifeq ($(CONFIG_MATTER_SECURE_EN),y)
	@$(MAKE) -C $(MATTER_BUILDDIR)/make/mbedtls_secure clean
endif
	@$(MAKE) -C mbedtls clean

-include $(DEPS)
