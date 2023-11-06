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

