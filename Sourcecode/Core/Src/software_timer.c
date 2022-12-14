/*
 * software_timer.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Hoang Tri
 */

#include "software_timer.h"
#define CYCLE 10;
int timer1_counter=0;
int timer1_flag= 0;
int timer2_counter=0;
int timer2_flag= 0;
int timer3_counter=0;
int timer3_flag= 0;
int timer4_counter=0;
int timer4_flag= 0;
int timer5_counter=0;
int timer5_flag= 0;
int timer6_counter=0;
int timer6_flag= 0;
int timer7_counter=0;
int timer7_flag= 0;
int timer8_counter=0;
int timer8_flag= 0;
int timer9_counter=0;
int timer9_flag= 0;
void setTimer1(int duration)
{
	timer1_counter = duration/CYCLE;
	timer1_flag = 0;
}
void setTimer2(int duration)
{
	timer2_counter = duration/CYCLE;
	timer2_flag = 0;
}
void setTimer3(int duration)
{
	timer3_counter = duration/CYCLE;
	timer3_flag = 0;
}
void setTimer4(int duration)
{
	timer4_counter = duration/CYCLE;
	timer4_flag = 0;
}
void setTimer5(int duration)
{
	timer5_counter = duration/CYCLE;
	timer5_flag = 0;
}
void setTimer6(int duration)
{
	timer6_counter = duration/CYCLE;
	timer6_flag = 0;
}
void setTimer7(int duration)
{
	timer7_counter = duration/CYCLE;
	timer7_flag = 0;
}
void setTimer8(int duration)
{
	timer8_counter = duration/CYCLE;
	timer8_flag = 0;
}
void setTimer9(int duration)
{
	timer9_counter = duration/CYCLE;
	timer9_flag = 0;
}
void TimerRun()
{
	if(timer1_counter > 0)
	{
		timer1_counter --;
		if(timer1_counter <= 0)
		{
			timer1_flag=1;
		}
	}
	if(timer2_counter > 0)
	{
		timer2_counter --;
		if(timer2_counter <= 0)
		{
			timer2_flag=1;
		}
	}
	if(timer3_counter > 0)
	{
		timer3_counter --;
		if(timer3_counter <= 0)
		{
			timer3_flag=1;
		}
	}
	if(timer4_counter > 0)
	{
		timer4_counter --;
		if(timer4_counter <= 0)
		{
			timer4_flag=1;
		}
	}
	if(timer5_counter > 0)
	{
		timer5_counter --;
		if(timer5_counter <= 0)
		{
			timer5_flag=1;
		}
	}
	if(timer6_counter > 0)
	{
		timer6_counter --;
		if(timer6_counter <= 0)
		{
			timer6_flag=1;
		}
	}
	if(timer7_counter > 0)
	{
		timer7_counter --;
		if(timer7_counter <= 0)
		{
			timer7_flag=1;
		}
	}
	if(timer8_counter > 0)
	{
		timer8_counter --;
		if(timer8_counter <= 0)
		{
			timer8_flag=1;
		}
	}
	if(timer9_counter > 0)
	{
		timer9_counter --;
		if(timer9_counter <= 0)
		{
			timer9_flag=1;
		}
	}
}
//   Clear Timer of system.
void clearTimer1(){
	timer1_counter = 0;
	timer1_flag = 0;
}

void clearTimer2(){
	timer2_counter = 0;
	timer2_flag = 0;
}

void clearTimer3(){
	timer3_counter = 0;
	timer3_flag = 0;
}

void clearTimer4(){
	timer4_counter = 0;
	timer4_flag = 0;
}

void clearTimer5(){
	timer5_counter = 0;
	timer5_flag = 0;
}

void clearTimer6(){
	timer6_counter = 0;
	timer6_flag = 0;
}

void clearTimer7(){
	timer7_counter = 0;
	timer7_flag = 0;
}

void clearTimer8(){
	timer8_counter = 0;
	timer8_flag = 0;
}

void clearTimer9(){
	timer9_counter = 0;
	timer9_flag = 0;
}


