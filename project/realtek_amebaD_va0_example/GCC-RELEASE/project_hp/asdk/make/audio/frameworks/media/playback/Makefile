
include $(MAKE_INCLUDE_GEN)

.PHONY: clean lib tests

#*****************************************************************************#
#                               VARIABLES	                                  #
#*****************************************************************************#

#*****************************************************************************#
#                        RULES TO GENERATE TARGETS                            #
#*****************************************************************************#

# Define the Rules to build the core targets

tests:
ifeq ($(CONFIG_MEDIA_PLAYER),y)
	$(MAKE) -C standard/tests all
endif

lib:
ifeq ($(CONFIG_MEDIA_PLAYER),y)
	$(MAKE) -C standard lib
	$(MAKE) -C xip lib
endif
#*****************************************************************************#
#                        RULES TO CLEAN TARGETS                               #
#*****************************************************************************#
clean:
ifeq ($(CONFIG_MEDIA_PLAYER),y)
	$(MAKE) -C standard clean
	$(MAKE) -C xip clean
	$(MAKE) -C standard/tests clean
endif

-include $(DEPS)
