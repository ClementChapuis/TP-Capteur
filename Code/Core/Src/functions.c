/**
  ******************************************************************************
  * @file           : functions.c
  * @brief          : Functions used in the main program body
  ******************************************************************************
*/
#include "functions.h"
#include "Const.h"

#define SIZE 32

/**
  * @brief  	This functions is used for I2C initialization.
  * @param[in] 	hi2c	I2C from the board choosed by the user
  * @retval 	void
*/
void Init(I2C_HandleTypeDef* hi2c)
{
	uint8_t data[SIZE] ;
	//hardware reset
	data[0] = 0x80;
	HAL_I2C_Mem_Write(hi2c, MPU_ADD, PWR_MGMT_1, 1, data, 1, HAL_MAX_DELAY);

	data[0] = 0xB6;
	HAL_I2C_Mem_Write(hi2c, MPU_ADD, 0xE0, 1, data, 1, HAL_MAX_DELAY);

	HAL_Delay(100);
	//clock selection
	data[0] = 0x01;
	HAL_I2C_Mem_Write(hi2c, MPU_ADD, PWR_MGMT_1, 1, data, 1, HAL_MAX_DELAY);
}

/**
  * @brief  	This function gives the temperature from the BMP module.
  * @param[in]	hi2c	I2C from the board choosed by the user
  * @param[in]	temp	Temperature variable used to store the measure
  * @retval 	void but print the mesured temperature in the shell
*/
void Measure_T(I2C_HandleTypeDef* hi2c, double* temp)
{
	uint8_t temp_out_h[SIZE];
	uint8_t temp_out_l[SIZE];
	HAL_I2C_Mem_Read(hi2c, MPU_ADD, 0x41, 1, temp_out_h, 1, HAL_MAX_DELAY);
	HAL_I2C_Mem_Read(hi2c, MPU_ADD, 0x42, 1, temp_out_l, 1, HAL_MAX_DELAY);
	*temp = (double)(((temp_out_h[0]<<8) + temp_out_l[0] - ROOM_TEMP_OFFSET)/TEMP_SENS + 21);
	printf("Température : %1.2f\r\n", *temp);
}
