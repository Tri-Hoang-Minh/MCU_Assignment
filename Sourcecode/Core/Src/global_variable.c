/*
 * global_variable.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Hoang Tri
 */
#include "global_variable.h"

int counter=0;

int status_light = AUTO_INIT;  //0
int status_pedes = PEDES_OUTOFSTATE; //-1

// time of led red, green, yellow in 2 traffic light and time of buzzer
int time_buzzer=0;
int time_frequency=0;

int time_led_red_1=TIME_RED;
int time_led_yellow_1=TIME_YELLOW;
int time_led_green_1=TIME_GREEN;


int time_led_red_2=TIME_RED;
int time_led_yellow_2=TIME_YELLOW;
int time_led_green_2=TIME_GREEN;

// UART buffer
char buffer_RX[MAX_SIZE_FOR_UART]={0,0,0,0,0,0,0,0,0,0};  // receive data
char buffer_TX[MAX_SIZE_FOR_UART]={0,0,0,0,0,0,0,0,0,0};  // trans data/


