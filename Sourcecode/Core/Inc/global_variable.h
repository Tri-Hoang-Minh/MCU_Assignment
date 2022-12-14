/*
 * global_variable.h
 *
 *  Created on: Dec 13, 2022
 *      Author: Hoang Tri
 */

#ifndef INC_GLOBAL_VARIABLE_H_
#define INC_GLOBAL_VARIABLE_H_
#include <stdio.h>
#include "software_timer.h"
#include "button.h"
#include "displayallLED.h"
#include "UART_Communication.h"
#include "FSM_AUTOMODE.h"
#include "FSM_MANUALMODE.h"
#include "FSM_PEDESTRIANMODE.h"
#include "FSM_SETTINGMODE.h"
#include "scheduler.h"
#include "main.h"


extern int status_light;
extern int status_pedes;
extern int counter;

//UART_HandleTypeDef huart2;
//TIM_HandleTypeDef htim3;
// AUTO MODE:

#define AUTO_INIT			    0

#define AUTO_GREEN_1			1
#define AUTO_YELLOW_1 		    2

#define AUTO_GREEN_2			3
#define AUTO_YELLOW_2 		    4

// MANUAL MODE:
#define MAN_GREEN_1			    5
#define MAN_YELLOW_1			6

#define MAN_GREEN_2			    7
#define MAN_YELLOW_2			8
// PEDESTRIAN STATE:
#define PEDES_STOP              9
#define PEDES_GO                10
#define PEDES_OUTOFSTATE        -1

// TUNING MODE:
#define SETTING_LED_RED         11
#define SETTING_LED_YELLOW      12
#define SETTING_LED_GREEN       13
// UART SETTING
#define MAX_SIZE_FOR_UART	     30
// TIME VALUE OF TRAFFIC LIGHT:
#define TIME_RED			10000
#define TIME_YELLOW			3000
#define TIME_GREEN			7000

#define TIME_MANUAL_MODE			10000
#define TIME_TUNING_MODE			10000
#define TIME_PEDESTRIAN_LIGHT	    20000
#define BUZZER_DUTY_CYCLE		    1300
#define BUZZER_FREQUENCY_START	    50

// time value will save this variable.
extern int time_led_red_1;
extern int time_led_yellow_1;
extern int time_led_green_1;


extern int time_led_red_2;
extern int time_led_yellow_2;
extern int time_led_green_2;

// Buzzer

extern int time_buzzer;
extern int time_frequency;

// UART setting buffer char

extern char buffer_RX[MAX_SIZE_FOR_UART];  // receive data
extern char buffer_TX[MAX_SIZE_FOR_UART];  // trans data/
#endif /* INC_GLOBAL_VARIABLE_H_ */
