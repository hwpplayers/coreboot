# SPDX-License-Identifier: GPL-2.0-only

bootblock-y += bootblock.c
bootblock-y += early_gpio.c

ramstage-y += gpio.c

# APCB_mandolin.bin
APCB_SOURCES = mandolin

PHONY+=add_mchp_fw
INTERMEDIATE+=add_mchp_fw

ifeq ($(CONFIG_MANDOLIN_HAVE_MCHP_FW),y)

MANDOLIN_MICROCHIP_FW_OFFSET=0
add_mchp_fw: $(obj)/coreboot.pre
	$(CBFSTOOL) $(obj)/coreboot.pre write -r EC -f $(CONFIG_MANDOLIN_MCHP_FW_FILE) --fill-upward

else
files_added:: warn_no_mchp
endif # CONFIG_MANDOLIN_HAVE_MCHP_FW

PHONY+=warn_no_mchp
warn_no_mchp:
	printf "\n\t** WARNING **\n"
	printf "coreboot has been built without an the Microchip EC.\n"
	printf "Do not flash this image.  Your Mandolin's power button\n"
	printf "will not respond when you press it.\n\n"

CPPFLAGS_common += -I$(src)/mainboard/$(MAINBOARDDIR)/acpi
