/*
 * lps25hb.c
 *
 *  Created on: Nov 6, 2023
 *      Author: Patricia
 */

#include "lps25hb.h"

uint8_t lps25hb_add = LPS25HB_DEVICE_ADDRESS0;

uint8t_t LPS25HB_read()
{
	uint8_t data = 0;
	return *(i2c_read(&data, 1, reg_add, lps25hb_add, 0));
}

uint8_t LPS25HB_write()
{

}

uint8_t LPS25HB_Init()
{

}
