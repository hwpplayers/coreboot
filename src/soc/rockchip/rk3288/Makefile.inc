## SPDX-License-Identifier: GPL-2.0-only

ifeq ($(CONFIG_SOC_ROCKCHIP_RK3288),y)

IDBTOOL = util/rockchip/make_idb.py

bootblock-y += bootblock.c
bootblock-y += ../common/uart.c
bootblock-y += timer.c
bootblock-y += clock.c
bootblock-y += ../common/spi.c
bootblock-y += ../common/gpio.c
bootblock-y += gpio.c
bootblock-y += ../common/i2c.c
bootblock-$(CONFIG_SOFTWARE_I2C) += software_i2c.c
bootblock-y += ../common/rk808.c

verstage-y += ../common/spi.c
verstage-y += timer.c
verstage-y += ../common/uart.c
verstage-y += ../common/gpio.c
verstage-y += gpio.c
verstage-y += clock.c
verstage-y += crypto.c
verstage-y += ../common/i2c.c
verstage-$(CONFIG_SOFTWARE_I2C) += software_i2c.c

romstage-y += ../common/cbmem.c
romstage-y += timer.c
romstage-y += ../common/uart.c
romstage-y += ../common/i2c.c
romstage-$(CONFIG_SOFTWARE_I2C) += software_i2c.c
romstage-y += clock.c
romstage-y += ../common/gpio.c
romstage-y += gpio.c
romstage-y += ../common/spi.c
romstage-y += sdram.c
romstage-y += ../common/rk808.c
romstage-y += ../common/pwm.c
romstage-y += tsadc.c
romstage-y += ../common/i2c.c

ramstage-y += soc.c
ramstage-y += timer.c
ramstage-y += ../common/i2c.c
ramstage-$(CONFIG_SOFTWARE_I2C) += software_i2c.c
ramstage-y += clock.c
ramstage-y += ../common/spi.c
ramstage-y += sdram.c
ramstage-y += ../common/gpio.c
ramstage-y += gpio.c
ramstage-y += ../common/rk808.c
ramstage-y += ../common/pwm.c
ramstage-y += ../common/vop.c
ramstage-y += ../common/edp.c
ramstage-y += hdmi.c
ramstage-y += display.c
ramstage-y += ../common/uart.c

CPPFLAGS_common += -Isrc/soc/rockchip/rk3288/include
CPPFLAGS_common += -Isrc/soc/rockchip/common/include

$(objcbfs)/bootblock.bin: $(objcbfs)/bootblock.raw.bin
	@printf "Generating: $(subst $(obj)/,,$(@))\n"
	@mkdir -p $(dir $@)
	@$(IDBTOOL) --from=$< --to=$@ --enable-align --chip=RK32

endif
