/*
 * ModBusRTU.h
 *
 *  Created on: Feb 28, 2023
 *      Author: AlphaP-Tuf
 */

#ifndef INC_MODBUSRTU_H_
#define INC_MODBUSRTU_H_
#include "stm32f4xx_hal.h"
//Modbus Handle structure
typedef struct _ModbusHandleTypedef
{
	uint16_t *RegisterAddress;
	UART_HandleTypeDef* huart;
	TIM_HandleTypeDef* htim;

}ModbusHandleTypedef;


typedef enum _modbusFunctioncode
{

	Modbus_function_Read_Coil =1,
	Modbus_function_Read_DiscreteInput,
	Modbus_function_Read_Holding_Register,
	Modbus_function_Read_Input_Registor,
	Modbus_function_Write_SingleCoil,
	Modbus_function_Write_SingleRegister,
	Modbus_function_Diagnostics =8,
	Modbus_function_GetCommEventCounter = 11,
	Modbus_function_Write_MultipleCoil =15,
	Modbus_function_Write_MultipleRegistor

}ModbusFunctionCode;


#endif /* INC_MODBUSRTU_H_ */