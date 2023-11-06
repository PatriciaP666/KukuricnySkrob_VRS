/*
 * lps25hb.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Patricia
 */

#ifndef LPS25HB_H_
#define LPS25HB_H_

#include "main.h"
#include "i2c.h"

#define LPS25HB_WHO_AM_I_ADDRESS			0x0f
#define LPS25HB_WHO_AM_I_VALUE				0xBD
#define LPS25HB_RESOLUTION_REG				0x10
#define LPS25HB_CONTROL_REG1				0x20
#define LPS25HB_CONTROL_REG2				0x21
#define LPS25HB_PRESSURE_OUT_XL				0x28
#define LPS25HB_PRESSURE_OUT_L				0x29
#define LPS25HB_PRESSURE_OUT_H				0x2A
#define LPS25HB_TEMPERATURE_OUT_L			0x2B
#define	LPS25HB_TEMPERATURE_OUT_H			0x2C
#define LPS25HB_DEVICE_ADDRESS0				0xB8
#define LPS25HB_DEVICE_ADDRESS1				0xBA
#define LPS25HB_REFERENCE_PRESSURE_XL		0x08
#define LPS25HB_REFERENCE_PRESSURE_L		0x09
#define LPS25HB_REFERENCE_PRESSURE_H		0x0A

uint8_t LPS25HB_read(uint8_t reg_add);
void LPS25HB_write(uint8_t data, uint8_t reg_add, uint8_t slave_add);
uint8_t LPS25HB_Init();

#endif /* LPS25HB_H_ */
