/*
 * UART_Communication.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Hoang Tri
 */
#include "UART_Communication.h"
void sendDATA(){
	if(timer2_flag){
			if(!timer3_flag)
			{
				HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!7SEG:%d:LIGHT1#\r\n", timer3_counter/100), 1000);
			}
			else
			{
				HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!7SEG:DELAY:LIGHT1#\r\n"), 1000);
			}

			if(!timer4_flag)
			{
				HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!7SEG:%d:LIGHT2#\r\n", timer4_counter/100), 1000);
			}
			else
			{
				HAL_UART_Transmit(&huart2,(void *)buffer_TX, sprintf (buffer_TX,"!7SEG:DELAY:LIGHT2#\r\n"), 1000);
			}
			setTimer2(1000);  // 1s send data;
		}
}

void sendVALUE_SETTING(){
	HAL_UART_Transmit(&huart2, (void *)buffer_TX, sprintf (buffer_TX,"!RED:%d:YELLOW:%d:GREEN:%d#\r\n", time_led_red_1/1000, time_led_yellow_1/1000, time_led_green_1/1000), 1000);
}

void Buzzer_RUN(){
	if(timer5_flag){
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, time_frequency);
		setTimer6(time_buzzer/2);
		if(timer3_counter<4000){
			time_frequency *= 3;
			time_buzzer = (timer3_counter>0)? timer3_counter/6 : time_buzzer/5;
		}else{
		    time_frequency += 100;
			time_buzzer -= 100;
		}


		if(time_frequency >= 1000) time_frequency = 1000;
		if(time_buzzer <= 100)	time_buzzer = 100;
		setTimer5(time_buzzer);
	}
	if(timer6_flag){
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
	}
}

