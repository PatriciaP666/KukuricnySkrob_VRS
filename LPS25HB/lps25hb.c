/*
 * lps25hb.c
 *
 *  Created on: Nov 6, 2023
 *      Author: Patricia
 */

#include "lps25hb.h"

uint8_t lps25hb_add = LPS25HB_DEVICE_ADDRESS0;

uint8_t LPS25HB_read(uint8_t reg_add)
{
	uint8_t data = 0;
	return *(i2c_read(&data, 1, reg_add, lps25hb_add, 0));
}

void LPS25HB_write(uint8_t data, uint8_t reg_add, uint8_t slave_add)
{
	i2c_write(data, reg_add, slave_add, 0);
}

uint8_t LPS25HB_Init()
{
	uint8_t state = 1;
	LL_mDelay(100);
	uint8_t a = LPS25HB_read(LPS25HB_WHO_AM_I_ADDRESS);
	if(a == LPS25HB_WHO_AM_I_VALUE)
	{
		state = 1;
	}
	else
	{
		lps25hb_add = LPS25HB_DEVICE_ADDRESS1;
		a = LPS25HB_read(LPS25HB_WHO_AM_I_ADDRESS);
		if(a == LPS25HB_WHO_AM_I_VALUE)
		{
			state = 1;
		}
		else
		{
			state = 0;
		}
	}
	// Set power-down mode to turn ON -> set PD to 1 to power on
	uint8_t reg_setup = LPS25HB_read(LPS25HB_CONTROL_REG1);
	reg_setup |= (1 << 7);
	LPS25HB_write(reg_setup, LPS25HB_CONTROL_REG1, lps25hb_add);
	// Set up continuous update
	reg_setup = LPS25HB_read(LPS25HB_CONTROL_REG1);
	reg_setup &= ~(1 << 2);
	LPS25HB_write(reg_setup, LPS25HB_CONTROL_REG1, lps25hb_add);
	// Set Output data rate register to 25 Hz -> 0b100
	reg_setup = LPS25HB_read(LPS25HB_CONTROL_REG1);
	reg_setup &= ~(0x07 << 4);
	reg_setup |= (0x04 << 4);
	LPS25HB_write(reg_setup, LPS25HB_CONTROL_REG1, lps25hb_add);
	reg_setup = LPS25HB_read(LPS25HB_CONTROL_REG1);
	return state;
}

void LPS25HB_array(uint8_t *data, uint8_t reg, uint8_t length)
{
	i2c_read(data, length, reg, lps25hb_add, 1);
}

float LPS25HB_pressure()
{
	uint8_t pressure[3] = {0};
	LPS25HB_array(pressure, LPS25HB_PRESSURE_OUT_XL, 3);
	float pressure_real = ((pressure[2] * 65536) + (pressure[1] * 256) + pressure[0]) / 4096.0;
	return pressure_real;
}

