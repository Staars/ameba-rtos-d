
include $(MAKE_INCLUDE_GEN)

.PHONY: all lib clean


#*****************************************************************************#
#                               Object FILE LIST                              #
#*****************************************************************************#
OBJS =

#*****************************************************************************#
#                        RULES TO GENERATE TARGETS                            #
#*****************************************************************************#

# Define the Rules to build the core targets
lib: CORE_TARGETS
	$(MAKE) -C libs lib
	$(MAKE) -C log lib
	$(MAKE) -C osal lib
	$(MAKE) -C media lib
	$(MAKE) -C xip lib

#*****************************************************************************#
#              GENERATE OBJECT FILE                                           #
#*****************************************************************************#
CORE_TARGETS: $(OBJS)




#*****************************************************************************#
#                        RULES TO CLEAN TARGETS                               #
#*****************************************************************************#
clean:
	$(MAKE) -C libs clean
	$(MAKE) -C log clean
	$(MAKE) -C osal clean
	$(MAKE) -C media clean
	$(MAKE) -C xip clean
-include $(DEPS)
