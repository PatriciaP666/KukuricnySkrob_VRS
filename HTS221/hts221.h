/*
 * hts221.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Patricia
 */

#ifndef HTS221_H_
#define HTS221_H_

#define HTS221_DEVICE_ADDRESS			0xBE
#define HTS221_WHO_AM_I_ADDRESS			0x0F
#define HTS221_WHO_AM_I_VALUE			0xBC
#define HTS221_AVG_CONFIG				0x10
#define HTS221_CONTROL_REG				0x20
#define HTS221_HUMIDITY_OUT_L			0x28
#define HTS221_HUMIDITY_OUT_H			0x29
#define HTS221_TEMPERATURE_OUT_L		0x2A
#define HTS221_TEMPERATURE_OUT_H		0x2B
#define HTS221_CALIBRATION_REG1			0x30
#define HTS221_CALIBRATiON_REG2			0x3F
#define HTS221_T0_DEG_C_x8				0x32
#define HTS221_T1_DEG_C_x8				0x33
#define HTS221_T1_T0_MSB				0x35
#define HTS221_T0_OUT_L					0x3C
#define HTS221_T0_OUT_H					0x3D
#define HTS221_T1_OUT_L					0x3E
#define HTS221_T1_OUT_H					0x3F
#define HTS221_H0_RH_x2					0x30
#define HTS221_H1_RH_x2					0x31
#define HTS221_H0_T0_OUT_L				0x36
#define HTS221_H0_T0_OUT_H				0x37
#define HTS221_H1_T0_OUT_L				0x3A
#define HTS221_H1_T0_OUT_H				0x3B

uint8_t HTS221_read(uint8_t reg_add);
void HTS221_write(uint8_t data, uint8_t reg_add, uint8_t slave_add);
void HTS221_array(uint8_t *data, uint8_t reg, uint8_t length);

#endif /* HTS221_H_ */
