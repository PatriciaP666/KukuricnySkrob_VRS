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

void lsm6ds0_get_acc(float* x, float* y, float* z)
{
	uint8_t data[6];
	int16_t xx, yy, zz;

	uint8_t temp;

	//get current scale and use it for final calculation
    temp = lsm6ds0_read(LSM6DS0_ADDRESS_CTRL1);

	temp = temp >> 2;
    temp &= 0x03;			//full scale bits exctracted

	lsm6ds0_array(data, LSM6DS0_ADDRESS_ACCX, 6);

	xx = ((uint16_t)data[1]) << 8 | data[0];
	yy = ((uint16_t)data[3]) << 8 | data[2];
	zz = ((uint16_t)data[5]) << 8 | data[4];

	*x = (xx >> 4) / 1000.0f;
	*y = (yy >> 4) / 1000.0f;
	*z = (zz >> 4) / 1000.0f;
}

