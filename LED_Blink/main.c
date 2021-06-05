
/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32.h"
#include "ht32_board.h"
#include "ht32_board_config.h"

/* Private function prototypes -----------------------------------------------------------------------------*/
//CLK n GPIO
void CKCU_Configuration(void);
void GPIO_IN_Configuration(void);
void GPIO_OUT_Configuration(void);
//Timers
void BFTM_Config_point2(void);
void BFTM_Config_point5(void);
//External Interrupt
void EXTI_KEY2_Configuration(void);
//Function for LED
void BLINK_LINE_SOL(uint8_t compas);
void KEY1_SOL(void);
void BlankInp(void);
//Global Variables
uint8_t Key2_STATUS = 0;
uint8_t Key3_STATUS = 0;
uint8_t switchLEDval = 0, i = 0;
//uint8_t BlankChecker1 = 0;
vu32 edge_STATE;

																					int main(void)
																					{
																						CKCU_Configuration();                                                 
																																			                                             
																						GPIO_IN_Configuration();																					                                                   
																						GPIO_OUT_Configuration();
																						
																						BFTM_Config_point2();
																						BFTM_Config_point5();
																																												
																						HT32F_DVB_LEDInit(HT_LED1);
																						HT32F_DVB_LEDInit(HT_LED2);
																						HT32F_DVB_LEDInit(HT_LED3);
																																																												 
																						EXTI_KEY2_Configuration();													 
																						while (1)
																						{//BlankInp();
																							Key2_STATUS = GPIO_ReadInBit(HTCFG_KEY1, HTCFG_INPUT_KEY1_GPIO_PIN);
																							Key3_STATUS = GPIO_ReadInBit(HTCFG_WAKE, HTCFG_INPUT_WAKE_GPIO_PIN);
																							}
																					}
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////																					

//void BlankInp(void)
//{
//	if(Key2_STATUS == 0)
//		GPIO_WriteOutBits(HTCFG_LED1, HTCFG_OUTPUT_LED1_GPIO_PIN, SET);
//	if(Key2_STATUS == 0 && edge_STATE == FALSE && Key2_STATUS == 0){
//		GPIO_WriteOutBits(HTCFG_LED0, HTCFG_OUTPUT_LED0_GPIO_PIN, SET);
//		GPIO_WriteOutBits(HTCFG_LED1, HTCFG_OUTPUT_LED1_GPIO_PIN, SET);
//		GPIO_WriteOutBits(HTCFG_LED2, HTCFG_OUTPUT_LED2_GPIO_PIN, SET);}
//	else if(Key2_STATUS == 0 && edge_STATE == TRUE && Key2_STATUS == 0){
//		GPIO_WriteOutBits(HTCFG_LED0, HTCFG_OUTPUT_LED0_GPIO_PIN, SET);
//		GPIO_WriteOutBits(HTCFG_LED1, HTCFG_OUTPUT_LED1_GPIO_PIN, SET);
//		}
//	else if(Key2_STATUS == 0 && edge_STATE == TRUE && Key2_STATUS == 1){
//		GPIO_WriteOutBits(HTCFG_LED0, HTCFG_OUTPUT_LED0_GPIO_PIN, SET);
//		}
//}
																					
void CKCU_Configuration(void)
{
#if 1
  CKCU_PeripClockConfig_TypeDef CKCUClock = {{0}};
  HTCFG_OUTPUT_LED0_CLK(CKCUClock) = 1;
  HTCFG_OUTPUT_LED1_CLK(CKCUClock) = 1;
  HTCFG_OUTPUT_LED2_CLK(CKCUClock) = 1;
  HTCFG_INPUT_WAKE_CLK(CKCUClock)  = 1;
  HTCFG_INPUT_KEY1_CLK(CKCUClock)  = 1;
  HTCFG_INPUT_KEY2_CLK(CKCUClock)  = 1;
  CKCUClock.Bit.AFIO       = 1;
  CKCU_PeripClockConfig(CKCUClock, ENABLE);
#endif
}

void KEY1_SOL(void)
{
  if (edge_STATE == TRUE)
  {
		GPIO_WriteOutBits(HTCFG_LED2, HTCFG_OUTPUT_LED2_GPIO_PIN, RESET);
  }
	else if (edge_STATE == FALSE)
	{
		GPIO_WriteOutBits(HTCFG_LED2, HTCFG_OUTPUT_LED2_GPIO_PIN, SET);
	}

}

void BLINK_LINE_SOL(uint8_t compas)
{
	switch(compas){
		default:
		GPIO_WriteOutBits(HTCFG_LED0, HTCFG_OUTPUT_LED0_GPIO_PIN, SET);
		GPIO_WriteOutBits(HTCFG_LED1, HTCFG_OUTPUT_LED1_GPIO_PIN, SET);
		GPIO_WriteOutBits(HTCFG_LED2, HTCFG_OUTPUT_LED2_GPIO_PIN, SET);
	  break;
		
		case 1:
		GPIO_WriteOutBits(HTCFG_LED0, HTCFG_OUTPUT_LED0_GPIO_PIN, RESET);
		GPIO_WriteOutBits(HTCFG_LED1, HTCFG_OUTPUT_LED1_GPIO_PIN, SET);
		GPIO_WriteOutBits(HTCFG_LED2, HTCFG_OUTPUT_LED2_GPIO_PIN, SET);
		break;
		
		case 2:
		GPIO_WriteOutBits(HTCFG_LED1, HTCFG_OUTPUT_LED1_GPIO_PIN, RESET);
		GPIO_WriteOutBits(HTCFG_LED0, HTCFG_OUTPUT_LED0_GPIO_PIN, SET);
		GPIO_WriteOutBits(HTCFG_LED2, HTCFG_OUTPUT_LED2_GPIO_PIN, SET);
		break;
		
		case 3:
		GPIO_WriteOutBits(HTCFG_LED2, HTCFG_OUTPUT_LED2_GPIO_PIN, RESET);
		GPIO_WriteOutBits(HTCFG_LED1, HTCFG_OUTPUT_LED1_GPIO_PIN, SET);
		GPIO_WriteOutBits(HTCFG_LED0, HTCFG_OUTPUT_LED0_GPIO_PIN, SET);
		break;	
}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//TMConfiguration for 0.2s interupt
void BFTM_Config_point2(void)
{
  { 
    CKCU_PeripClockConfig_TypeDef CKCUClock = {{ 0 }};
    CKCUClock.Bit.BFTM0 = 1;
    CKCU_PeripClockConfig(CKCUClock, ENABLE);
  }
  BFTM_SetCompare(HT_BFTM0, SystemCoreClock / 10);
  BFTM_SetCounter(HT_BFTM0, 0);
  BFTM_IntConfig(HT_BFTM0, ENABLE);
  BFTM_EnaCmd(HT_BFTM0, ENABLE);

  NVIC_EnableIRQ(BFTM0_IRQn);
}

//TMConfiguration for 0.5s interupt
void BFTM_Config_point5(void)
{
  { 
    CKCU_PeripClockConfig_TypeDef CKCUClock = {{ 0 }};
    CKCUClock.Bit.BFTM1 = 1;
    CKCU_PeripClockConfig(CKCUClock, ENABLE);
  }
  BFTM_SetCompare(HT_BFTM1, SystemCoreClock / 4);
  BFTM_SetCounter(HT_BFTM1, 0);
  BFTM_IntConfig(HT_BFTM1, ENABLE);
  BFTM_EnaCmd(HT_BFTM1, ENABLE);

  NVIC_EnableIRQ(BFTM1_IRQn);
}


void GPIO_IN_Configuration(void)
{
  /* Configure WAKEUP, KEY1, KEY2 pins as the input function                                                */
  /* Configure AFIO mode of input pins                                                                      */
 
	AFIO_GPxConfig(HTCFG_INPUT_WAKE_ID, HTCFG_INPUT_WAKE_AFIO_PIN, AFIO_FUN_GPIO);
  AFIO_GPxConfig(HTCFG_INPUT_KEY1_ID, HTCFG_INPUT_KEY1_AFIO_PIN, AFIO_FUN_GPIO);
  AFIO_GPxConfig(HTCFG_INPUT_KEY2_ID, HTCFG_INPUT_KEY2_AFIO_PIN, AFIO_FUN_GPIO);

  /* Configure GPIO direction of input pins                                                                 */
  GPIO_DirectionConfig(HTCFG_WAKE, HTCFG_INPUT_WAKE_GPIO_PIN, GPIO_DIR_IN);
  GPIO_DirectionConfig(HTCFG_KEY1, HTCFG_INPUT_KEY1_GPIO_PIN, GPIO_DIR_IN);
  GPIO_DirectionConfig(HTCFG_KEY2, HTCFG_INPUT_KEY2_GPIO_PIN, GPIO_DIR_IN);
	

  /* Configure GPIO pull resistor of input pins                                                             */
  GPIO_PullResistorConfig(HTCFG_WAKE, HTCFG_INPUT_WAKE_GPIO_PIN, GPIO_PR_DISABLE);
  GPIO_PullResistorConfig(HTCFG_KEY1, HTCFG_INPUT_KEY1_GPIO_PIN, GPIO_PR_DISABLE);
  GPIO_PullResistorConfig(HTCFG_KEY2, HTCFG_INPUT_KEY2_GPIO_PIN, GPIO_PR_DISABLE);
	
  
	
	GPIO_InputConfig(HTCFG_WAKE, HTCFG_INPUT_WAKE_GPIO_PIN, ENABLE);
  GPIO_InputConfig(HTCFG_KEY1, HTCFG_INPUT_KEY1_GPIO_PIN, ENABLE);
  GPIO_InputConfig(HTCFG_KEY2, HTCFG_INPUT_KEY2_GPIO_PIN, ENABLE);
}


void GPIO_OUT_Configuration(void)
{
	
  AFIO_GPxConfig(HTCFG_OUTPUT_LED0_ID, HTCFG_OUTPUT_LED0_AFIO_PIN, AFIO_FUN_GPIO);
  AFIO_GPxConfig(HTCFG_OUTPUT_LED1_ID, HTCFG_OUTPUT_LED1_AFIO_PIN, AFIO_FUN_GPIO);
  AFIO_GPxConfig(HTCFG_OUTPUT_LED2_ID, HTCFG_OUTPUT_LED2_AFIO_PIN, AFIO_FUN_GPIO);

  GPIO_DirectionConfig(HTCFG_LED0, HTCFG_OUTPUT_LED0_GPIO_PIN, GPIO_DIR_OUT);
  GPIO_DirectionConfig(HTCFG_LED1, HTCFG_OUTPUT_LED1_GPIO_PIN, GPIO_DIR_OUT);
  GPIO_DirectionConfig(HTCFG_LED2, HTCFG_OUTPUT_LED2_GPIO_PIN, GPIO_DIR_OUT);
}

//Config external interupt for key1 
//From example code
void EXTI_KEY2_Configuration(void)
{
  { /* Enable peripheral clock                                                                              */
    CKCU_PeripClockConfig_TypeDef CKCUClock = {{ 0 }};
    CKCUClock.Bit.AFIO       = 1;
    CKCUClock.Bit.EXTI       = 1;
    CKCUClock.Bit.HTCFG_KEY2_GPIO_CK = 1;
    CKCU_PeripClockConfig(CKCUClock, ENABLE);
  }

  /* Configure AFIO mode of input pins                                                                      */
  AFIO_GPxConfig(HTCFG_KEY2_GPIO_ID, HTCFG_KEY2_AFIO_PIN, AFIO_FUN_GPIO);

  /* Enable GPIO Input Function                                                                             */
  GPIO_InputConfig(HTCFG_KEY2_GPIO_PORT, HTCFG_KEY2_GPIO_PIN, ENABLE);

  /* Configure GPIO pull resistor of input pins                                                             */
  GPIO_PullResistorConfig(HTCFG_KEY2_GPIO_PORT, HTCFG_KEY2_GPIO_PIN, GPIO_PR_DISABLE);

  /* Select Port as EXTI Trigger Source                                                                     */
  AFIO_EXTISourceConfig(HTCFG_KEY2_AFIO_EXTI_CH, HTCFG_KEY2_AFIO_ESS);

  { 
    EXTI_InitTypeDef EXTI_InitStruct;

    EXTI_InitStruct.EXTI_Channel = HTCFG_KEY2_EXTI_CH;
    EXTI_InitStruct.EXTI_Debounce = EXTI_DEBOUNCE_DISABLE;
    EXTI_InitStruct.EXTI_DebounceCnt = 0;
    EXTI_InitStruct.EXTI_IntType = EXTI_BOTH_EDGE;
    EXTI_Init(&EXTI_InitStruct);
  }

  /* Enable EXTI & NVIC line Interrupt                                                                      */
  EXTI_IntConfig(HTCFG_KEY2_EXTI_CH, ENABLE);
  NVIC_EnableIRQ(HTCFG_KEY2_EXTI_IRQn);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Handler for Blink Led 2
void BFTM0_IRQHandler(void)
{
	
  BFTM_ClearFlag(HT_BFTM0);
	if (Key2_STATUS == 0)
	{
  HT32F_DVB_LEDToggle(HT_LED2);
	}
	else 
	{
		GPIO_WriteOutBits(HTCFG_LED1, HTCFG_OUTPUT_LED1_GPIO_PIN, SET);
	}

}

//Function for blink line LED(key3)
void BFTM1_IRQHandler(void)
{
  BFTM_ClearFlag(HT_BFTM1);

	
	if (Key3_STATUS == 1)
	{
		if (switchLEDval <4)
		{
		switchLEDval++;
		}
		else
		switchLEDval = 0;
		BLINK_LINE_SOL(switchLEDval);
	}
//	else
//	{
//		GPIO_WriteOutBits(HTCFG_LED0, HTCFG_OUTPUT_LED0_GPIO_PIN, SET);
//	}
}

//Handler for external interupt from key1
//From manual sample code
void EXTI2_3_IRQHandler(void)
{
  if (EXTI_GetEdgeStatus(HTCFG_KEY2_EXTI_CH, EXTI_EDGE_NEGATIVE))
  {
    EXTI_ClearEdgeFlag(HTCFG_KEY2_EXTI_CH);
    edge_STATE = TRUE;
  }
  else if (EXTI_GetEdgeStatus(HTCFG_KEY2_EXTI_CH, EXTI_EDGE_POSITIVE))
  {
    EXTI_ClearEdgeFlag(HTCFG_KEY2_EXTI_CH);
		edge_STATE = FALSE;
  }
	KEY1_SOL();
}


#if (HT32_LIB_DEBUG == 1)

void assert_error(u8* filename, u32 uline)
{


  while (1)
  {
  }
}
#endif


