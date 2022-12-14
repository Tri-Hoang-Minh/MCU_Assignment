/*
 * displayalLED.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Hoang Tri
 */
/*=================================================================
 * Traffic Light 1: D2 and D3
 * Traffic Light 2: D4 and D5
 * Pedestrian Light: D6 and D7.
 * RED: 1 0
 * GREEN: 0 1
 * YELLOW: 1 1
 * LED OFF: 0 0
 * We have assume if "light" = 0 => Traffic Light 1 and "Light"=1 => Traffic light 2.
 */
#include "displayallLED.h"
void ToggleLEDRed(int light)
{
	switch(light)     //if "light" = 0 => LED RED of Traffic Light 1 on
	{
	      case 0:
	    	  HAL_GPIO_WritePin(D2_TFL1_GPIO_Port,D2_TFL1_Pin, GPIO_PIN_SET);
	    	  HAL_GPIO_WritePin(D3_TFL1_GPIO_Port,D3_TFL1_Pin, GPIO_PIN_RESET);
	    	  break;
	      case 1:  //if "light" = 1 => LED RED of Traffic Light 2 on
	    	  HAL_GPIO_WritePin(D4_TFL2_GPIO_Port,D4_TFL2_Pin, GPIO_PIN_SET);
	    	  HAL_GPIO_WritePin(D5_TFL2_GPIO_Port,D5_TFL2_Pin, GPIO_PIN_RESET);
	    	  break;
	      default:  // clear all led RED in 2 traffic light.
				HAL_GPIO_WritePin(D2_TFL1_GPIO_Port,D2_TFL1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(D3_TFL1_GPIO_Port,D3_TFL1_Pin, GPIO_PIN_RESET);
		    	HAL_GPIO_WritePin(D4_TFL2_GPIO_Port,D4_TFL2_Pin, GPIO_PIN_RESET);
		    	HAL_GPIO_WritePin(D5_TFL2_GPIO_Port,D5_TFL2_Pin, GPIO_PIN_RESET);
				break;
	}
}
void ToggleLEDYellow(int light)
{
	switch(light)     //if "light" = 0 => LED YELLOW of Traffic Light 1 on
	{
	      case 0:
	    	  HAL_GPIO_WritePin(D2_TFL1_GPIO_Port,D2_TFL1_Pin, GPIO_PIN_SET);
	    	  HAL_GPIO_WritePin(D3_TFL1_GPIO_Port,D3_TFL1_Pin, GPIO_PIN_SET);
	    	  break;
	      case 1:  //if "light" = 1 => LED YELLOW of Traffic Light 2 on
	    	  HAL_GPIO_WritePin(D4_TFL2_GPIO_Port,D4_TFL2_Pin, GPIO_PIN_SET);
	    	  HAL_GPIO_WritePin(D5_TFL2_GPIO_Port,D5_TFL2_Pin, GPIO_PIN_SET);
	    	  break;
	      default:  // clear all led YELLOW in 2 traffic light.
				HAL_GPIO_WritePin(D2_TFL1_GPIO_Port,D2_TFL1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(D3_TFL1_GPIO_Port,D3_TFL1_Pin, GPIO_PIN_RESET);
		    	HAL_GPIO_WritePin(D4_TFL2_GPIO_Port,D4_TFL2_Pin, GPIO_PIN_RESET);
		    	HAL_GPIO_WritePin(D5_TFL2_GPIO_Port,D5_TFL2_Pin, GPIO_PIN_RESET);
				break;
	}
}
void ToggleLEDGreen(int light)
{
	switch(light)     //if "light" = 0 => LED YELLOW of Traffic Light 1 on
	{
	      case 0:
	    	  HAL_GPIO_WritePin(D2_TFL1_GPIO_Port,D2_TFL1_Pin, GPIO_PIN_RESET);
	    	  HAL_GPIO_WritePin(D3_TFL1_GPIO_Port,D3_TFL1_Pin, GPIO_PIN_SET);
	      break;
	      case 1:  //if "light" = 1 => LED YELLOW of Traffic Light 2 on
	    	  HAL_GPIO_WritePin(D4_TFL2_GPIO_Port,D4_TFL2_Pin, GPIO_PIN_RESET);
	    	  HAL_GPIO_WritePin(D5_TFL2_GPIO_Port,D5_TFL2_Pin, GPIO_PIN_SET);
	      break;
	      default:  // clear all led YELLOW in 2 traffic light.
				HAL_GPIO_WritePin(D2_TFL1_GPIO_Port,D2_TFL1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(D3_TFL1_GPIO_Port,D3_TFL1_Pin, GPIO_PIN_RESET);
		    	HAL_GPIO_WritePin(D4_TFL2_GPIO_Port,D4_TFL2_Pin, GPIO_PIN_RESET);
		    	HAL_GPIO_WritePin(D5_TFL2_GPIO_Port,D5_TFL2_Pin, GPIO_PIN_RESET);
		  break;
	}
}
void ToggleLEDPedestrian(int state)
{
/*
 * state 0: khong cho nguoi di bo di.
 * state 1: cho nguoi di bo di.
 * LED RED: khong cho nguoi di bo di.
 * LED GREEN: cho nguoi di bo di qua duong.
 * */
	switch(state)
	{
	    case 0:  // LED RED
	    HAL_GPIO_WritePin(D6_Pedes_Light_GPIO_Port,D6_Pedes_Light_Pin, GPIO_PIN_SET);  //1
	    HAL_GPIO_WritePin(D7_Pedes_Light_GPIO_Port,D7_Pedes_Light_Pin, GPIO_PIN_RESET);  //0
	    break;  // LED GREEN
	    case 1:
	    HAL_GPIO_WritePin(D6_Pedes_Light_GPIO_Port,D6_Pedes_Light_Pin, GPIO_PIN_RESET);  //0
	    HAL_GPIO_WritePin(D7_Pedes_Light_GPIO_Port,D7_Pedes_Light_Pin, GPIO_PIN_SET);  //1
	    break;
	    default:
		HAL_GPIO_WritePin(D6_Pedes_Light_GPIO_Port,D6_Pedes_Light_Pin, GPIO_PIN_RESET);  //0
		HAL_GPIO_WritePin(D7_Pedes_Light_GPIO_Port,D7_Pedes_Light_Pin, GPIO_PIN_RESET);  //0
		break;
	}

}
void clearLED(int index_light)
{
	/*
	 * Tat tat ca cac den LED
	 * index_light = 0  => Traffic light 1.
	 * index_light=1 => Traffic light 2.
	 *   */
	switch(index_light){
		case 0:
			HAL_GPIO_WritePin(D2_TFL1_GPIO_Port, D2_TFL1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D3_TFL1_GPIO_Port, D3_TFL1_Pin, GPIO_PIN_RESET);
			break;
		case 1:
            HAL_GPIO_WritePin(D4_TFL2_GPIO_Port, D4_TFL2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(D5_TFL2_GPIO_Port, D5_TFL2_Pin, GPIO_PIN_RESET);
			break;
		default:
			HAL_GPIO_WritePin(D2_TFL1_GPIO_Port, D2_TFL1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D3_TFL1_GPIO_Port, D3_TFL1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(D4_TFL2_GPIO_Port, D4_TFL2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(D5_TFL2_GPIO_Port, D5_TFL2_Pin, GPIO_PIN_RESET);
			break;
	}
}
