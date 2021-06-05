/*********************************************************************************************************//**
 * @file    GPIO/InputOutput/ht32_board_config.h
 * @version $Rev:: 5067         $
 * @date    $Date:: 2020-11-07#$
 * @brief   The header file of board configuration.
 *************************************************************************************************************
 * @attention
 *
 * Firmware Disclaimer Information
 *
 * 1. The customer hereby acknowledges and agrees that the program technical documentation, including the
 *    code, which is supplied by Holtek Semiconductor Inc., (hereinafter referred to as "HOLTEK") is the
 *    proprietary and confidential intellectual property of HOLTEK, and is protected by copyright law and
 *    other intellectual property laws.
 *
 * 2. The customer hereby acknowledges and agrees that the program technical documentation, including the
 *    code, is confidential information belonging to HOLTEK, and must not be disclosed to any third parties
 *    other than HOLTEK and the customer.
 *
 * 3. The program technical documentation, including the code, is provided "as is" and for customer reference
 *    only. After delivery by HOLTEK, the customer shall use the program technical documentation, including
 *    the code, at their own risk. HOLTEK disclaims any expressed, implied or statutory warranties, including
 *    the warranties of merchantability, satisfactory quality and fitness for a particular purpose.
 *
 * <h2><center>Copyright (C) Holtek Semiconductor Inc. All rights reserved</center></h2>
 ************************************************************************************************************/
/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __HT32_BOARD_CONFIG_H
#define __HT32_BOARD_CONFIG_H


#define HTCFG_ADC_IPN                           ADC0
#define  HTCFG_PWM_TM_PCLK                       (LIBCFG_MAX_SPEED)
#define PWM_CH0                                   STRCAT2(TM_CH_,    HTCFG_PWM0_CHN)
#define PWM_CH1                                   STRCAT2(TM_CH_,    HTCFG_PWM1_CHN)
#define HTCFG_PWM_TM_PORT                         STRCAT2(HT_,       HTCFG_PWM_TM_IPN)



#ifdef __cplusplus
 extern "C" {
#endif

/* Settings ------------------------------------------------------------------------------------------------*/
#if defined(USE_HT32F52352_SK)
  #define HTCFG_OUTPUT_LED0_ID                                  (GPIO_PC)
  #define HTCFG_OUTPUT_LED1_ID                                  (GPIO_PC)
  #define HTCFG_OUTPUT_LED2_ID                                  (GPIO_PC)
  #define HTCFG_INPUT_WAKE_ID                                   (GPIO_PB)
  #define HTCFG_INPUT_KEY1_ID                                   (GPIO_PD)
  #define HTCFG_INPUT_KEY2_ID                                   (GPIO_PD)

  #define HTCFG_OUTPUT_LED0_CLK(CK)                             (CK.Bit.PC)
  #define HTCFG_OUTPUT_LED1_CLK(CK)                             (CK.Bit.PC)
  #define HTCFG_OUTPUT_LED2_CLK(CK)                             (CK.Bit.PC)
  #define HTCFG_INPUT_WAKE_CLK(CK)                              (CK.Bit.PB)
  #define HTCFG_INPUT_KEY1_CLK(CK)                              (CK.Bit.PD)
  #define HTCFG_INPUT_KEY2_CLK(CK)                              (CK.Bit.PD)

  #define HTCFG_LED0                                            (HT_GPIOC)
  #define HTCFG_LED1                                            (HT_GPIOC)
  #define HTCFG_LED2                                            (HT_GPIOC)
  #define HTCFG_WAKE                                            (HT_GPIOB)
  #define HTCFG_KEY1                                            (HT_GPIOD)
  #define HTCFG_KEY2                                            (HT_GPIOD)

  #define HTCFG_OUTPUT_LED0_AFIO_PIN                            (AFIO_PIN_14)
  #define HTCFG_OUTPUT_LED1_AFIO_PIN                            (AFIO_PIN_15)
  #define HTCFG_OUTPUT_LED2_AFIO_PIN                            (AFIO_PIN_1)
  #define HTCFG_INPUT_WAKE_AFIO_PIN                             (AFIO_PIN_12)
  #define HTCFG_INPUT_KEY1_AFIO_PIN                             (AFIO_PIN_1)
  #define HTCFG_INPUT_KEY2_AFIO_PIN                             (AFIO_PIN_2)

  #define HTCFG_OUTPUT_LED0_GPIO_PIN                            (GPIO_PIN_14)
  #define HTCFG_OUTPUT_LED1_GPIO_PIN                            (GPIO_PIN_15)
  #define HTCFG_OUTPUT_LED2_GPIO_PIN                            (GPIO_PIN_1)
  #define HTCFG_INPUT_WAKE_GPIO_PIN                             (GPIO_PIN_12)
  #define HTCFG_INPUT_KEY1_GPIO_PIN                             (GPIO_PIN_1)
  #define HTCFG_INPUT_KEY2_GPIO_PIN                             (GPIO_PIN_2)
	
	#define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          USART1
	
	
	#define _HTCFG_VR_GPIOX                         A
  #define _HTCFG_VR_GPION                         6
  #define _HTCFG_VR_ADC_CHN                       6
	
	#define HTCFG_VR_GPIO_ID                          STRCAT2(GPIO_P,         _HTCFG_VR_GPIOX)
	#define HTCFG_VR_AFIO_PIN                         STRCAT2(AFIO_PIN_,      _HTCFG_VR_GPION)
	#define HTCFG_VR_ADC_CH                           STRCAT2(ADC_CH_,        _HTCFG_VR_ADC_CHN)

	#define HTCFG_ADC_PORT                            STRCAT2(HT_,            HTCFG_ADC_IPN)
	#define HTCFG_ADC_AFIO_MODE                       STRCAT2(AFIO_FUN_,      HTCFG_ADC_IPN)
	#define HTCFG_ADC_CKCU_ADCPRE                     STRCAT2(CKCU_ADCPRE_,   HTCFG_ADC_IPN)
	#define HTCFG_ADC_IRQn                            STRCAT2(HTCFG_ADC_IPN, _IRQn)
	
	
	#define _HTCFG_WAKE_GPIOX                       B
  #define _HTCFG_WAKE_GPION                       12
  #define  HTCFG_WAKE_EXTI_IRQn                   EXTI12_IRQn

  #define _HTCFG_KEY1_GPIOX                       D
  #define _HTCFG_KEY1_GPION                       1
  #define  HTCFG_KEY1_EXTI_IRQn                   EXTI1_IRQn

  #define _HTCFG_KEY2_GPIOX                       D
  #define _HTCFG_KEY2_GPION                       2
  #define  HTCFG_KEY2_EXTI_IRQn                   EXTI2_IRQn
	
	 #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       C
  #define  HTCFG_PWM0_GPION                       4

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       C
  #define  HTCFG_PWM1_GPION                       5

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       C
  #define  HTCFG_PWM2_GPION                       8

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       C
  #define  HTCFG_PWM3_GPION                       9
	
#if defined(USE_HT32F65240_DVB) || defined(USE_HT32F65240_SK)
  #define HTCFG_ADC_IRQHandler                    STRCAT2(HTCFG_ADC_IPN, _IRQHandler)
#else
  #define HTCFG_ADC_IRQHandler                    ADC_IRQHandler
#endif
	

#endif

#define HTCFG_UART_TX_GPIO_ID                     STRCAT2(GPIO_P,         _HTCFG_UART_TX_GPIOX)
#define HTCFG_UART_RX_GPIO_ID                     STRCAT2(GPIO_P,         _HTCFG_UART_RX_GPIOX)
#define HTCFG_UART_TX_AFIO_PIN                    STRCAT2(AFIO_PIN_,      _HTCFG_UART_TX_GPION)
#define HTCFG_UART_RX_AFIO_PIN                    STRCAT2(AFIO_PIN_,      _HTCFG_UART_RX_GPION)
#define HTCFG_UART_PORT                           STRCAT2(HT_,             HTCFG_UART_IPN)
#define HTCFG_UART_IRQn                           STRCAT2(HTCFG_UART_IPN, _IRQn)
#define HTCFG_UART_IRQHandler                     STRCAT2(HTCFG_UART_IPN, _IRQHandler)

#define HTCFG_UART_RX_GPIO_CLK                    STRCAT2(P,              _HTCFG_UART_RX_GPIOX)
#define HTCFG_UART_RX_GPIO_PORT                   STRCAT2(HT_GPIO,        _HTCFG_UART_RX_GPIOX)
#define HTCFG_UART_RX_GPIO_PIN                    STRCAT2(GPIO_PIN_,      _HTCFG_UART_RX_GPION)


#define HTCFG_WAKE_GPIO_CK                        STRCAT2(P,              _HTCFG_WAKE_GPIOX)
#define HTCFG_WAKE_GPIO_ID                        STRCAT2(GPIO_P,         _HTCFG_WAKE_GPIOX)
#define HTCFG_WAKE_AFIO_PIN                       STRCAT2(AFIO_PIN_,      _HTCFG_WAKE_GPION)
#define HTCFG_WAKE_GPIO_PORT                      STRCAT2(HT_GPIO,        _HTCFG_WAKE_GPIOX)
#define HTCFG_WAKE_GPIO_PIN                       STRCAT2(GPIO_PIN_,      _HTCFG_WAKE_GPION)
#define HTCFG_WAKE_AFIO_EXTI_CH                   STRCAT2(AFIO_EXTI_CH_,  _HTCFG_WAKE_GPION)
#define HTCFG_WAKE_AFIO_ESS                       STRCAT2(AFIO_ESS_P,     _HTCFG_WAKE_GPIOX)
#define HTCFG_WAKE_EXTI_CH                        STRCAT2(EXTI_CHANNEL_,  _HTCFG_WAKE_GPION)

#define HTCFG_KEY1_GPIO_CK                        STRCAT2(P,              _HTCFG_KEY1_GPIOX)
#define HTCFG_KEY1_GPIO_ID                        STRCAT2(GPIO_P,         _HTCFG_KEY1_GPIOX)
#define HTCFG_KEY1_AFIO_PIN                       STRCAT2(AFIO_PIN_,      _HTCFG_KEY1_GPION)
#define HTCFG_KEY1_GPIO_PORT                      STRCAT2(HT_GPIO,        _HTCFG_KEY1_GPIOX)
#define HTCFG_KEY1_GPIO_PIN                       STRCAT2(GPIO_PIN_,      _HTCFG_KEY1_GPION)
#define HTCFG_KEY1_AFIO_EXTI_CH                   STRCAT2(AFIO_EXTI_CH_,  _HTCFG_KEY1_GPION)
#define HTCFG_KEY1_AFIO_ESS                       STRCAT2(AFIO_ESS_P,     _HTCFG_KEY1_GPIOX)
#define HTCFG_KEY1_EXTI_CH                        STRCAT2(EXTI_CHANNEL_,  _HTCFG_KEY1_GPION)

#define HTCFG_KEY2_GPIO_CK                        STRCAT2(P,              _HTCFG_KEY2_GPIOX)
#define HTCFG_KEY2_GPIO_ID                        STRCAT2(GPIO_P,         _HTCFG_KEY2_GPIOX)
#define HTCFG_KEY2_AFIO_PIN                       STRCAT2(AFIO_PIN_,      _HTCFG_KEY2_GPION)
#define HTCFG_KEY2_GPIO_PORT                      STRCAT2(HT_GPIO,        _HTCFG_KEY2_GPIOX)
#define HTCFG_KEY2_GPIO_PIN                       STRCAT2(GPIO_PIN_,      _HTCFG_KEY2_GPION)
#define HTCFG_KEY2_AFIO_EXTI_CH                   STRCAT2(AFIO_EXTI_CH_,  _HTCFG_KEY2_GPION)
#define HTCFG_KEY2_AFIO_ESS                       STRCAT2(AFIO_ESS_P,     _HTCFG_KEY2_GPIOX)
#define HTCFG_KEY2_EXTI_CH                        STRCAT2(EXTI_CHANNEL_,  _HTCFG_KEY2_GPION)



#ifdef __cplusplus
}
#endif
#endif
