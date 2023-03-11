/*
 * USART.c
 *
 *  Created on: 5 Mar 2023
*/


#include "stm32f401xe.h"
#include "USART.h"



void UartTransmitData(USART_TypeDef *USARTx, uint8_t *TxBuffer, uint8_t Size){

		for(int i=Size ; i>0 ; i--){
			while (!((USARTx->SR) & (1<<7))){};
			USARTx->DR  = *TxBuffer & (0xFF);
			TxBuffer++;
		}

}

void UartReceivedData(USART_TypeDef *USARTx, uint8_t *RxBuffer, uint8_t Size){
		for (int i=0 ; i<Size; i++){
			while(!(USARTx->SR & 1<<5)){};
				*(RxBuffer + i) = USARTx->DR & (0xFF);

		}


}
