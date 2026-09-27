
include $(MAKE_INCLUDE_GEN)

.PHONY: all test lib clean


#*****************************************************************************#
#                               Object FILE LIST                              #
#*****************************************************************************#
OBJS =

#*****************************************************************************#
#                        RULES TO GENERATE TARGETS                            #
#*****************************************************************************#

# Define the Rules to build the core targets
test: CORE_TARGETS
ifeq ($(CONFIG_AUDIO_MIXER),y)
	$(MAKE) -C lite/audio_stream/tests all
else ifeq ($(CONFIG_AUDIO_PASSTHROUGH),y)
	$(MAKE) -C passthrough/tests all
endif

lib: CORE_TARGETS
	$(MAKE) -C algorithms lib
	$(MAKE) -C lite lib
	$(MAKE) -C passthrough lib
	$(MAKE) -C xip lib
#*****************************************************************************#
#              GENERATE OBJECT FILE                                           #
#*****************************************************************************#
CORE_TARGETS: $(OBJS)




#*****************************************************************************#
#                        RULES TO CLEAN TARGETS                               #
#*****************************************************************************#
clean:
	$(MAKE) -C algorithms clean
	$(MAKE) -C lite clean
	$(MAKE) -C passthrough clean
	$(MAKE) -C lite/audio_stream/tests clean
	$(MAKE) -C passthrough/tests clean
	$(MAKE) -C xip clean
-include $(DEPS)
