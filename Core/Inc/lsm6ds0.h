/*
 * lsm6ds0.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Patricia
 */

#ifndef INC_LSM6DS0_H_
#define INC_LSM6DS0_H_

#include "main.h"
#include "i2c.h"


#define 	LSM6DS0_DEVICE_ADDRESS_0				0xD4
#define 	LSM6DS0_DEVICE_ADDRESS_1				0xD6

#define 	LSM6DS0_WHO_AM_I_VALUE					0x6C
#define 	LSM6DS0_WHO_AM_I_ADDRES					0x0F

#define 	LSM6DS0_ADDRESS_CTRL1					0x10

#define 	LSM6DS0_ADDRESS_ACCX					0x28
#define 	LSM6DS0_ADDRESS_ACCY					0x2A
#define 	LSM6DS0_ADDRESS_ACCZ					0x2C

#define 	LSM6DS0_ADDRESS_TEMP_L					0x20

uint8_t lsm6ds0_read(uint8_t reg_add);
void lsm6ds0_write(uint8_t reg_add, uint8_t value);
void lsm6ds0_array(uint8_t * data, uint8_t reg, uint8_t length);
int8_t lsm6ds0_get_temp();
uint8_t lsm6ds0_init(void);

#endif /* INC_LSM6DS0_H_ */
