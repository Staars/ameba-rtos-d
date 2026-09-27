
include $(MAKE_INCLUDE_GEN)

.PHONY: lib clean

#*****************************************************************************#
#                               VARIABLES	                                  #
#*****************************************************************************#

#*****************************************************************************#
#                        RULES TO GENERATE TARGETS                            #
#*****************************************************************************#

# Define the Rules to build the core targets

lib:
	$(MAKE) -C utils all
	$(MAKE) -C common all
	$(MAKE) -C source all
	$(MAKE) -C demux all
	$(MAKE) -C codec all
	$(MAKE) -C core all
	$(MAKE) -C libmedia all

#*****************************************************************************#
#                        RULES TO CLEAN TARGETS                               #
#*****************************************************************************#
clean:
	$(MAKE) -C utils clean
	$(MAKE) -C common clean
	$(MAKE) -C source clean
	$(MAKE) -C demux clean
	$(MAKE) -C codec clean
	$(MAKE) -C core clean
	$(MAKE) -C libmedia clean


-include $(DEPS)
