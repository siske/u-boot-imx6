/*
 *  Copyright (C) 2012 Samsung Electronics
 *  Lukasz Majewski <l.majewski@samsung.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <i2c.h>

/* Handle multiple I2C buses instances */
int get_multi_scl_pin(void)
{
	unsigned int bus = i2c_get_bus_num();

	switch (bus) {
	case I2C_0:
		return CONFIG_SOFT_I2C_I2C5_SCL;
	case I2C_1:
		return CONFIG_SOFT_I2C_I2C9_SCL;
	default:
		printf("I2C_%d not supported!\n", bus);
	};

	return 0;
}

int get_multi_sda_pin(void)
{
	unsigned int bus = i2c_get_bus_num();

	switch (bus) {
	case I2C_0:
		return CONFIG_SOFT_I2C_I2C5_SDA;
	case I2C_1:
		return CONFIG_SOFT_I2C_I2C9_SDA;
	default:
		printf("I2C_%d not supported!\n", bus);
	};

	return 0;
}

int multi_i2c_init(void)
{
	return 0;
}
