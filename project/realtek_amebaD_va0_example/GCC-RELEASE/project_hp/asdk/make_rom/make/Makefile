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
	$(MAKE) -C ../vector all
	$(MAKE) -C ../fwlib all
	$(MAKE) -C ../crypto all
	$(MAKE) -C ../monitor all
	$(MAKE) -C ../string all
	#$(MAKE) -C ../apple all
	#$(MAKE) -C ../mbedtls all

#*****************************************************************************#
#              CLEAN GENERATED FILES                                          #
#*****************************************************************************#
clean:
	$(MAKE) -C ../vector clean
	$(MAKE) -C ../fwlib clean
	$(MAKE) -C ../crypto clean
	$(MAKE) -C ../monitor clean
	$(MAKE) -C ../string clean
	$(MAKE) -C ../apple clean
	$(MAKE) -C ../mbedtls clean

-include $(DEPS)
