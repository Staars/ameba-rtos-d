
include $(MAKE_INCLUDE_GEN)

.PHONY: all lib clean test


#*****************************************************************************#
#                               Object FILE LIST                              #
#*****************************************************************************#
OBJS = 

#*****************************************************************************#
#                        RULES TO GENERATE TARGETS                            #
#*****************************************************************************#

# Define the Rules to build the core targets
all: CORE_TARGETS
ifeq ($(CONFIG_BAIDU_DUER),y)
	$(MAKE) -C mp3 all
endif
ifeq ($(CONFIG_MEDIA_PLAYER),y)
	$(MAKE) -C frameworks/media/playback/standard/config
endif

ifeq ($(CONFIG_AUDIO_FWK),y)
	$(MAKE) -C hal/config all
endif

test:
ifeq ($(CONFIG_AUDIO_FWK),y)
	#$(MAKE) -C frameworks/media/audio test
	#$(MAKE) -C hal test
endif
ifeq ($(CONFIG_MEDIA_PLAYER),y)
	#$(MAKE) -C frameworks/media/playback tests
endif

lib:
ifeq ($(CONFIG_AUDIO_FWK),y)
	$(MAKE) -C hal lib
	$(MAKE) -C base lib
	$(MAKE) -C frameworks audiolib
endif
ifeq ($(CONFIG_MEDIA_PLAYER),y)
	$(MAKE) -C base lib
	$(MAKE) -C frameworks playerlib
	$(MAKE) -C 3rdparty lib
	$(MAKE) -C third_party lib
endif

#*****************************************************************************#
#              GENERATE OBJECT FILE                                           #
#*****************************************************************************#
CORE_TARGETS: $(OBJS)




#*****************************************************************************#
#                        RULES TO CLEAN TARGETS                               #
#*****************************************************************************#
clean: 
	$(MAKE) -C mp3 clean
	$(MAKE) -C hal clean
	$(MAKE) -C base clean
	$(MAKE) -C frameworks clean
	$(MAKE) -C 3rdparty clean
	$(MAKE) -C third_party clean
	$(MAKE) -C frameworks/media/playback/standard/config clean
	$(MAKE) -C hal/config clean

-include $(DEPS)
