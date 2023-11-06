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
	//uint8_t data = 0;
	//return *(i2c_read(&data, 1, reg_add, lps25hb_add, 0));
}

void LPS25HB_write(uint8_t data, uint8_t reg_add, uint8_t slave_add)
{
	i2c_write(data, reg_add, slave_add, 0);
}

uint8_t LPS25HB_Init()
{
	uint8_t state = 0;
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

	return state;
}


