/*
 * ModBusRTU.c
 *
 *  Created on: Feb 28, 2023
 *      Author: AlphaP-Tuf
 */
#include "ModBusRTU.h"

ModbusHandleTypedef* hModbus;
//end of packet
void modbus_1t5_Timeout(TIM_HandleTypeDef *htim)
{
	//end of package flag set
}

void modbus_3t5_Timeout(TIM_HandleTypeDef *htim)
{
	//return package flag set
}
void modbus_UART_Recived(UART_HandleTypeDef *huart)
{

}
void Modbus_init(ModbusHandleTypedef* hmodbus,uint16_t* RegisterStartAddress)
{
	hModbus = hmodbus;
	HAL_TIM_RegisterCallback(hModbus->htim,HAL_TIM_OC_DELAY_ELAPSED_CB_ID,(void*)modbus_1t5_Timeout);
	HAL_TIM_RegisterCallback(hModbus->htim,HAL_TIM_PERIOD_ELAPSED_CB_ID ,(void*)modbus_3t5_Timeout);
	hModbus->RegisterAddress = RegisterStartAddress;

}


