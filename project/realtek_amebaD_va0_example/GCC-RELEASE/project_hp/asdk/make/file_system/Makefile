
include $(MAKE_INCLUDE_GEN)

.PHONY: all clean


#*****************************************************************************#
#                               Object FILE LIST                              #
#*****************************************************************************#
OBJS = 

#*****************************************************************************#
#                        RULES TO GENERATE TARGETS                            #
#*****************************************************************************#

# Define the Rules to build the core targets
all: CORE_TARGETS
#	$(MAKE) -C dct all
	$(MAKE) -C fatfs all
	$(MAKE) -C littlefs all
	$(MAKE) -C kv all
ifeq ($(CONFIG_BT_EN), y)
	$(MAKE) -C ftl all
endif

#*****************************************************************************#
#              GENERATE OBJECT FILE 
#*****************************************************************************#
CORE_TARGETS: $(OBJS)

	


#*****************************************************************************#
#                        RULES TO CLEAN TARGETS                               #
#*****************************************************************************#
clean: 
	$(MAKE) -C dct clean
	$(MAKE) -C fatfs clean
	$(MAKE) -C ftl clean
	$(MAKE) -C littlefs clean
	$(MAKE) -C kv clean
