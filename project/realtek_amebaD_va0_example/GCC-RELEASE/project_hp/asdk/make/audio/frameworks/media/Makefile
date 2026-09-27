
include $(MAKE_INCLUDE_GEN)

.PHONY: all audiolib playerlib clean


#*****************************************************************************#
#                               Object FILE LIST                              #
#*****************************************************************************#
OBJS =

#*****************************************************************************#
#                        RULES TO GENERATE TARGETS                            #
#*****************************************************************************#

# Define the Rules to build the core targets
audiolib: CORE_TARGETS
	$(MAKE) -C audio lib

playerlib: CORE_TARGETS
	$(MAKE) -C playback lib

#*****************************************************************************#
#              GENERATE OBJECT FILE                                           #
#*****************************************************************************#
CORE_TARGETS: $(OBJS)




#*****************************************************************************#
#                        RULES TO CLEAN TARGETS                               #
#*****************************************************************************#
clean:
	$(MAKE) -C audio clean
	$(MAKE) -C playback clean
-include $(DEPS)
