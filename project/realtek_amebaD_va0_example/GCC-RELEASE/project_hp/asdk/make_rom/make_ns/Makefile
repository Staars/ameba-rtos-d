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
	$(MAKE) -C ../fwlib_ns all
	$(MAKE) -C ../crypto all
	$(MAKE) -C ../monitor all
	$(MAKE) -C ../string all
	$(MAKE) -C ../apple all
	$(MAKE) -C ../mbedtls all
	$(MAKE) -C ../dsp all

#*****************************************************************************#
#              CLEAN GENERATED FILES                                          #
#*****************************************************************************#
clean:
	$(MAKE) -C ../vector clean
	$(MAKE) -C ../fwlib_ns clean
	$(MAKE) -C ../crypto clean
	$(MAKE) -C ../monitor clean
	$(MAKE) -C ../string clean
	$(MAKE) -C ../apple clean
	$(MAKE) -C ../mbedtls clean
	$(MAKE) -C ../dsp clean

-include $(DEPS)
