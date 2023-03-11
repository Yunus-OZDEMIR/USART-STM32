/*
 * USART.h
 *
 *  Created on: 5 Mar 2023
 *      Author: yunus
 */

#ifndef USART_USART_H_
#define USART_USART_H_




typedef union {
	uint32_t USART_SR;
	struct{

		uint32_t PE			: 1;
		uint32_t FE 		: 1;
		uint32_t NF 		: 1;
		uint32_t ORE 		: 1;
		uint32_t IDLE		: 1;
		uint32_t RXNE		: 1;
		uint32_t TC			: 1;
		uint32_t TXE		: 1;
		uint32_t LBD		: 1;
		uint32_t CTS		: 1;
		uint32_t Reserved	: 22;
	};
}USART_SR_t;


typedef union {
	uint32_t USART_BRR;
	struct{
		uint32_t DIV_Fraction	: 4;
		uint32_t DIV_Mantissa	: 12;
		uint32_t Reserved		: 16;
	};
}USART_BRR_t;

typedef union {
	uint32_t USART_CR1;
	struct{
		uint32_t SBK			: 1;
		uint32_t RWU			: 1;
		uint32_t RE				: 1;
		uint32_t TE				: 1;
		uint32_t IDLEIE			: 1;
		uint32_t RXNEIE			: 1;
		uint32_t TCIE			: 1;
		uint32_t TXEIE			: 1;
		uint32_t PEIE			: 1;
		uint32_t PS				: 1;
		uint32_t PCE			: 1;
		uint32_t WAKE			: 1;
		uint32_t M				: 1;
		uint32_t UE				: 1;
		uint32_t Reserved		: 1;
		uint32_t OVER8			: 1;
		uint32_t Reserved2		: 16;
	};

}USART_CR1_t;


typedef union {
	uint32_t USART_CR2;
	struct{
		uint32_t ADD			: 4;
		uint32_t Reserved		: 1;
		uint32_t LBDL			: 1;
		uint32_t LBDIE			: 1;
		uint32_t Reserved2		: 1;
		uint32_t LBCL			: 1;
		uint32_t CPHA			: 1;
		uint32_t CPOL			: 1;
		uint32_t CLKEN			: 1;
		uint32_t STOP			: 2;
		uint32_t LINEN			: 1;
		uint32_t Reserved3		: 17;
	};

}USART_CR2_t;

typedef union {
	uint32_t USART_CR3;
	struct{
		uint32_t EIE			: 1;
		uint32_t IREN			: 1;
		uint32_t IRLP			: 1;
		uint32_t HDSEL			: 1;
		uint32_t NACK			: 1;
		uint32_t SCEN			: 1;
		uint32_t DMAR			: 1;
		uint32_t DMAT			: 1;
		uint32_t RTSE			: 1;
		uint32_t CTSE			: 1;
		uint32_t CTSIE			: 1;
		uint32_t ONEBIT			: 1;
		uint32_t Reserved		: 20;
	};

}USART_CR3_t;

typedef union {
	uint32_t USART_GTPR;
	struct{
		uint32_t PSC			: 8;
		uint32_t GT				: 8;
		uint32_t Reserved		: 16;
	};
}USART_GTPR_t;


void UartTransmitData(USART_TypeDef *USARTx, uint8_t *TxBuffer, uint8_t Size);
void UartReceivedData(USART_TypeDef *USARTx, uint8_t  *RxBuffer, uint8_t Size);

#endif /* USART_USART_H_ */
