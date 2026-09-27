# Resolve Newmota's global log policy to AmebaD's native severity threshold.
# Direct AmebaD builds retain their existing CONFIG_DEBUG_LOG behavior.
AMEBAD_SDK_LOG_LEVELS := none error warn info debug verbose

ifeq ($(strip $(SDK_LOG_LEVEL)),)
ifeq ($(CONFIG_DEBUG_LOG),y)
AMEBAD_SDK_LOG_LEVEL := verbose
else
AMEBAD_SDK_LOG_LEVEL := warn
endif
else
AMEBAD_SDK_LOG_LEVEL := $(strip $(SDK_LOG_LEVEL))
endif

ifneq ($(words $(AMEBAD_SDK_LOG_LEVEL)),1)
$(error SDK_LOG_LEVEL must be one of: $(AMEBAD_SDK_LOG_LEVELS))
endif
ifeq ($(filter $(AMEBAD_SDK_LOG_LEVEL),$(AMEBAD_SDK_LOG_LEVELS)),)
$(error SDK_LOG_LEVEL must be one of: $(AMEBAD_SDK_LOG_LEVELS); received '$(AMEBAD_SDK_LOG_LEVEL)')
endif

ifeq ($(AMEBAD_SDK_LOG_LEVEL),none)
AMEBAD_LOG_LEVEL_MAX := -1
else ifeq ($(AMEBAD_SDK_LOG_LEVEL),error)
AMEBAD_LOG_LEVEL_MAX := 0
else ifeq ($(AMEBAD_SDK_LOG_LEVEL),warn)
AMEBAD_LOG_LEVEL_MAX := 1
else ifeq ($(AMEBAD_SDK_LOG_LEVEL),info)
AMEBAD_LOG_LEVEL_MAX := 2
else
AMEBAD_LOG_LEVEL_MAX := 3
endif

# Safeboot uses the fixed-slot recovery image and should omit SDK logs.
ifneq ($(findstring -DNEWMOTA_IMAGE_SAFEBOOT=1,$(CPPFLAGS_EXTRA)),)
AMEBAD_LOG_LEVEL_MAX := -1
endif

# The application and Safeboot bootloader binaries must remain identical.
# Their top-level makefiles build these shared targets with this override.
ifneq ($(strip $(AMEBAD_LOG_LEVEL_MAX_OVERRIDE)),)
AMEBAD_LOG_LEVEL_MAX := $(AMEBAD_LOG_LEVEL_MAX_OVERRIDE)
endif

AMEBAD_LOG_LEVEL_HEADER := $(ABS_ROOTDIR)/build/amebad_log_level.h
AMEBAD_LOG_LEVEL_CFLAGS := -include $(AMEBAD_LOG_LEVEL_HEADER)

.PHONY: amebad_log_level_force
amebad_log_level_force:

$(AMEBAD_LOG_LEVEL_HEADER): amebad_log_level_force
	@mkdir -p "$(dir $@)"
	@printf '#ifndef AMEBAD_LOG_LEVEL_CONFIG_H\n#define AMEBAD_LOG_LEVEL_CONFIG_H\n#define AMEBAD_LOG_LEVEL_MAX $(AMEBAD_LOG_LEVEL_MAX)\n#endif\n' | cmp -s - "$@" || printf '#ifndef AMEBAD_LOG_LEVEL_CONFIG_H\n#define AMEBAD_LOG_LEVEL_CONFIG_H\n#define AMEBAD_LOG_LEVEL_MAX $(AMEBAD_LOG_LEVEL_MAX)\n#endif\n' > "$@"
