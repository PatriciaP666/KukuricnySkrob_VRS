/*
 * lsm6ds0.c
 *
 *  Created on: Nov 6, 2023
 *      Author: Patricia
 */

#include "lsm6ds0.h"

uint8_t add = LSM6DS0_DEVICE_ADDRESS_0;

uint8_t lsm6ds0_read(uint8_t reg_add)
{
	uint8_t data = 0;
	return *(i2c_read(&data, 1, reg_add, add, 0));
}


void lsm6ds0_write(uint8_t reg_add, uint8_t value)
{
	i2c_write(value, reg_add, add, 0);
}


void lsm6ds0_array(uint8_t * data, uint8_t reg, uint8_t length)
{
	i2c_read(data, length, reg, add, 1);
}


int8_t lsm6ds0_get_temp()
{
	uint8_t temp[2];
	lsm6ds0_array(temp, LSM6DS0_ADDRESS_TEMP_L, 2);

	return (((int16_t)((temp[1] << 8) | temp[0])) >> 3)  + 25;
}

uint8_t lsm6ds0_init(void)
{

	uint8_t state = 1;
	LL_mDelay(100);

	uint8_t a = lsm6ds0_read(LSM6DS0_WHO_AM_I_ADDRES);

	if(a == LSM6DS0_WHO_AM_I_VALUE)
	{
		state = 1;
	}
	else			//if the device is not found on one address, try another one
	{
		add = LSM6DS0_DEVICE_ADDRESS_1;
		a = lsm6ds0_read(LSM6DS0_WHO_AM_I_ADDRES);
		if(a == LSM6DS0_WHO_AM_I_VALUE)
		{
			state = 1;
		}
		else
		{
			state = 0;
		}
	}

	//acc device init

	uint8_t ctrl1 = 8 << 4; // +-2g res
	lsm6ds0_write(LSM6DS0_ADDRESS_CTRL1, ctrl1);

	return state;
}

