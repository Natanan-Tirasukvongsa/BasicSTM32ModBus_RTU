/*
 * ModBusRTU.h
 *
 *  Created on: Feb 28, 2023
 *      Author: AlphaP-Tuf
 */

#ifndef INC_MODBUSRTU_H_
#define INC_MODBUSRTU_H_
#include "stm32f4xx_hal.h"
#include "string.h"
#define MODBUS_MESSAGEBUFFER_SIZE 300
#define MODBUS_SLAVE_ID 1

typedef enum _ModbusState
{
	Modbus_state_Init,
	Modbus_state_Idle,
	Modbus_state_Emission,
	Modbus_state_Reception,
	Modbus_state_ControlAndWaiting
}ModbusStateTypedef;

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

typedef enum _modbusRecvFrameStatus
{
	Modbus_RecvFrame_Null = -2,
	Modbus_RecvFrame_FrameError = -1,
	Modbus_RecvFrame_Normal = 0,
	Modbus_RecvFrame_IllegalFunction,
	Modbus_RecvFrame_IllegalDataAddress,
	Modbus_RecvFrame_IllegalDataValue,
	Modbus_RecvFrame_SlaveDeviceFailure,
	Modbus_RecvFrame_Acknowlage,
	Modbus_RecvFrame_SlaveDeviceBusy,
	Modbus_RecvFrame_NegativeAcknowage,
	Modbus_RecvFrame_MemoryParityError,
	Modbus_RecvFrame_GatewayTargetDeviceFailedToRespon
}modbusRecvFrameStatus;

//Modbus Handle structure
typedef struct _ModbusHandleTypedef
{
	uint8_t slaveAddress;

	uint16_t *RegisterAddress;
	UART_HandleTypeDef* huart;
	TIM_HandleTypeDef* htim;

	uint8_t Flag_T15TimeOut;
	uint8_t Flag_T35TimeOut;
	uint8_t Flag_URev;
	uint8_t Flag_ETx;

	modbusRecvFrameStatus RecvStatus;


	ModbusStateTypedef Mstatus;

	uint8_t Rxframe[256];
	uint8_t Txframe[256];

	struct _modbusUartStructure
	{
	uint8_t MessageBufferRx[MODBUS_MESSAGEBUFFER_SIZE];
	uint16_t RxTail;


	uint8_t MessageBufferTx[MODBUS_MESSAGEBUFFER_SIZE];
	uint16_t TxTail;
	} modbusUartStructure;


}ModbusHandleTypedef;

#endif /* INC_MODBUSRTU_H_ */
