/*
 * functions.h
 *
 *  Created on: Dec 13, 2022
 *      Author: cleme
 */

#ifndef INC_FUNCTIONS_H_
#define INC_FUNCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include "stm32g4xx_hal.h"

void Init(I2C_HandleTypeDef*);
void Measure_T(I2C_HandleTypeDef*, double*);

#endif /* INC_FUNCTIONS_H_ */
