/*
 * FSM_PEDESTRIANMODE.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Hoang Tri
 */

#include "FSM_PEDESTRIANMODE.h"
//void ToggleLEDPedestrian(int state)
//{
///*
// * state 0: khong cho nguoi di bo di.
// * state 1: cho nguoi di bo di.
// * LED RED: khong cho nguoi di bo di.
// * LED GREEN: cho nguoi di bo di qua duong.
// * */
//	switch(state)
//	{
//	    case 0:
//	    HAL_GPIO_WritePin(D6_Pedes_Light_GPIO_Port,D6_Pedes_Light_Pin, GPIO_PIN_SET);  //1
//	    HAL_GPIO_WritePin(D7_Pedes_Light_GPIO_Port,D7_Pedes_Light_Pin, GPIO_PIN_RESET);  //0
//	    break;
//	    case 1:
//	    HAL_GPIO_WritePin(D6_Pedes_Light_GPIO_Port,D6_Pedes_Light_Pin, GPIO_PIN_RESET);  //0
//	    HAL_GPIO_WritePin(D7_Pedes_Light_GPIO_Port,D7_Pedes_Light_Pin, GPIO_PIN_SET);  //1
//	    break;
//	    default:
//		HAL_GPIO_WritePin(D6_Pedes_Light_GPIO_Port,D6_Pedes_Light_Pin, GPIO_PIN_RESET);  //0
//		HAL_GPIO_WritePin(D7_Pedes_Light_GPIO_Port,D7_Pedes_Light_Pin, GPIO_PIN_RESET);  //0
//		break;
//	}
//
//}
void fsm_pedes_mode()
{

	// Pedestrian light is located in traffic light 2
	switch(status_pedes)
	{
	   case PEDES_GO:
		   ToggleLEDPedestrian(1);
		   Buzzer_RUN();
		 /*
		  * Nguoi di bo se duoc di khi den giao thong la den do.
		  * Traffic Light 1: LED GREEN/YELLOW ON.
		  * Traffic Light 2: LED RED ON.
		  * */
		   // TODO: implementation function to turn off pedestrian light.
		   if(timer1_flag==1)  // count to exit pedes mode.
		   {
			   status_pedes=PEDES_OUTOFSTATE;
			   ToggleLEDPedestrian(2);  // default state.
			   time_buzzer=0;
			   time_frequency=0;
			   __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
		   }
		  if(status_light==AUTO_GREEN_2||status_light==AUTO_YELLOW_2)
		  {
			  /*
			   * AUTO_GREEN_2: RED1 ON, GREEN 2 ON.
			   * AUTO_YELLOW_2: RED1 ON, YELLOW 2 ON.
			   * Pedes light in traffic light 2 => pedestrian can't through road
			   */
			  status_pedes=PEDES_STOP;
			   __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
		  }
	   break;


	   case PEDES_STOP:
		   ToggleLEDPedestrian(0); // LED RED ON
		  if(status_light==AUTO_GREEN_1||status_light==AUTO_YELLOW_1)
			  {
				  /*
				   * AUTO_GREEN_1: GREEN1 ON, RED 2 ON.
				   * AUTO_YELLOW_1: YELLOW1 ON, RED 2 ON.
				   *  Pedes light in traffic light 2 => pedestrian can through road.
				   */
			    status_pedes=PEDES_GO;
			    setTimer5(BUZZER_DUTY_CYCLE);  // counter to turn on buzzer.
			  }
		   // TODO: implementation function to turn off pedestrian light and out pedes mode.
		   if(timer1_flag==1)
		   {
			   status_pedes=PEDES_OUTOFSTATE;
			   ToggleLEDPedestrian(2);  // default state.
			   time_frequency=0;
			   time_buzzer=0;
			   __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,0);
		   }
		   // TODO: Implementation for function of fsm_button to out pedes mode.

	   break;

	   default:
		   //status_pedes=-1; // PEDES_OUTOFSTATE
		   ToggleLEDPedestrian(2);  // default state.
		   time_buzzer=0;
		   time_frequency=0;
		   __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
	   break;
	}
}
