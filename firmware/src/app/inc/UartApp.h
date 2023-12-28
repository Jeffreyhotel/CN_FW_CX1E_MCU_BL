#ifndef __UartApp_H__
#define __UartApp_H__

void UartApp_WriteCPUCounter(uint8_t TaskNumber,uint8_t QueneNumber);
void UartApp_Global_Read(void);
void UartApp_TxWriteString(uint8_t* u8TxBuffer);

#endif