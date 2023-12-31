/**
 ******************************************************************************
 * @file           : CRC_program.c
 * @author         : Diea Abdeltwab
 * @layer          : MCAL
 * @brief          : Version 1 For STM32F411RE Drivers
 * @date           : 27/10/2023
 ******************************************************************************
 * @attention
 *
 *
 ******************************************************************************
 */
/******************************************************************************/
/************************ LIB Layer *******************************************/
/******************************************************************************/
#include <stdint.h>
#include "../../LIB/Stm32F466xx.h"
#include "../../LIB/ErrorType.h"
#include "../../LIB/Utils.h"

/******************************************************************************/
/************************ MCAL Layer ******************************************/
/******************************************************************************/
#include "CRC_interface.h"
#include "CRC_config.h"
#include "CRC_private.h"
/******************************************************************************/
/************************ Global **********************************************/
/******************************************************************************/

/*************************************************************************************************************************************/
/********************************************************* Functions implementations *************************************************/
/*************************************************************************************************************************************/

uint32_t MCRC_u32Accumulate ( uint32_t Copy_pu32Buffer[], uint32_t Copy_u32BufferLength )
{
  uint32_t Local_u32Temp = 0U;
  for (uint32_t Local_u32Index = 0U ; Local_u32Index < Copy_u32BufferLength ; Local_u32Index++ )
  {
      CRC->DR = Copy_pu32Buffer[Local_u32Index];
  }
  Local_u32Temp = CRC->DR;
  return Local_u32Temp;
}

uint32_t MCRC_Calculate(uint32_t Copy_pu32Buffer[], uint32_t Copy_u32BufferLength)
{
    /* Reset CRC unit */
    CRC->CR |= (1 << CRC_CR_RESET);

    for(uint32_t i = 0; i < Copy_u32BufferLength; i++){
        CRC->DR = Copy_pu32Buffer[i];
    }

    return CRC->DR;
}
void MCRC_voidDRreset(void)
{
	CRC->CR |= CRC_CR_RESET_MASK << CRC_CR_RESET ;
}
/*************************************************************************************************************************************/
/********************************************************* Static Functions implementations ******************************************/
/*************************************************************************************************************************************/

/*************************************************************************************************************************************/
/********************************************************* Handlers implementations **************************************************/
/*************************************************************************************************************************************/

/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
