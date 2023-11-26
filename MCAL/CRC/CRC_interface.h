

#ifndef  CRC_INTERFACE_H
#define  CRC_INTERFACE_H

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

/*************************************************************************************************************************************/
/********************************************************* Functions Prototype *******************************************************/
/*************************************************************************************************************************************/

uint32_t MCRC_u32Accumulate ( uint32_t Copy_pu32Buffer[], uint32_t Copy_u32BufferLength );

uint32_t MCRC_Calculate(uint32_t Copy_pu32Buffer[], uint32_t Copy_u32BufferLength);

void MCRC_voidDRreset(void);

/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
#endif