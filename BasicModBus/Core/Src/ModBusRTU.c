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
	hModbus->T15TimeOutFlag = 1;
}

void modbus_3t5_Timeout(TIM_HandleTypeDef *htim)
{
	//return package flag set
	hModbus->T35TimeOutFlag = 1;
}
void modbus_UART_Recived(UART_HandleTypeDef *huart)
{

	//restart timer / start timer of counting time with modbus RTU
	__HAL_TIM_SET_COUNTER(hModbus->htim,0);
	if(hModbus->htim->State == HAL_TIM_STATE_READY)
	{
		HAL_TIM_OnePulse_Start_it(&hModbus, TIM_CHANNEL_1);
	}
}
void Modbus_init(ModbusHandleTypedef* hmodbus,uint16_t* RegisterStartAddress)
{
	hModbus = hmodbus;
	HAL_TIM_RegisterCallback(hModbus->htim,HAL_TIM_OC_DELAY_ELAPSED_CB_ID,(void*)modbus_1t5_Timeout);
	HAL_TIM_RegisterCallback(hModbus->htim,HAL_TIM_PERIOD_ELAPSED_CB_ID ,(void*)modbus_3t5_Timeout);
	hModbus->RegisterAddress = RegisterStartAddress;
    HAL_UART_RegisterCallback(hModbus->huart,HAL_UART_RX_COMPLETE_CB_ID,(void*)modbus_UART_Recived);

}

void Modbus_Protocal_Worker()
{

}

void Modbus_Return_Massage()
{

}
