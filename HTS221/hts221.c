/*
 * hts221.c
 *
 *  Created on: Nov 6, 2023
 *      Author: Patricia
 */

#include "hts221.h"

uint8_t hts221_add = HTS221_DEVICE_ADDRESS;

// HTS221_read_byte implementation
uint8_t HTS221_read(uint8_t reg_add)
{
	uint8_t data = 0;
	return *(i2c_read(&data, 1, reg_add, hts221_add, 0));
}

// HTS221_write_byte implementation
void HTS221_write(uint8_t data, uint8_t reg_add, uint8_t slave_add)
{
	i2c_write(data, reg_add, slave_add, 0);
}

void HTS221_array(uint8_t *data, uint8_t reg, uint8_t length)
{
	i2c_read(data, length, reg, hts221_add, 1);
}

uint8_t HTS221_Init()
{
	uint8_t state = 1;
	uint8_t a = HTS221_read(HTS221_WHO_AM_I_ADDRESS);
	if (a != HTS221_WHO_AM_I_VALUE)
	{
		state = 0;
		return state;
	}

	uint8_t reg_status = HTS221_read(HTS221_CONTROL_REG);
	// PD mode ON (power on)
	reg_status |= (1 << 7);
	HTS221_write(reg_status, HTS221_CONTROL_REG, hts221_add);
	// Output data rate setup
	reg_status = HTS221_read(HTS221_CONTROL_REG);
	reg_status |= (1 << 0);
	HTS221_write(reg_status, HTS221_CONTROL_REG, hts221_add);
	reg_status = HTS221_read(HTS221_CONTROL_REG);
	return state;
}
