/*
 * FSM_SETTINGMODE.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Hoang Tri
 */

#include "FSM_SETTINGMODE.h"
void fsm_tunning_mode()
{
	// time value of all led in traffic light 1 and traffic light 2 is as same.
	/* VALUE_TIME_LED_RED_1 = VALUE_TIME_LED_RED_2
	 * VALUE_TIME_LED_GREEN_1 = VALUE_TIME_LED_GREEN_2
	 * VALUE_TIME_LED_YELLOW_1 = VALUE_TIME_LED_YELLOW_2
	 * */

	/* STATE OF BUTTON IN TUNING MODE:
	 *  Inscrese value of led.
	 *  Descrease value of led.
	 *  change tunning mode.
	 *  Out tuning mode to AUTO_INIT state.
	 * */
     switch(status_light)
     {
         case SETTING_LED_RED:
              if(is_button_pressed_1s(2))
              {
            	  time_led_red_1=time_led_red_1+1000;
            	  sendVALUE_SETTING();
              }
              if(is_button_pressed_1s(3))
              {
            	  time_led_red_1=time_led_red_1-1000;
            	  sendVALUE_SETTING();
              }
              time_led_red_2=time_led_red_1;
              if(timer8_flag==1)
              {
            	  ToggleLEDRed(0);
            	  ToggleLEDRed(1);
            	  setTimer7(500); //0.5s
            	  setTimer8(1000);//1s
              }
              if(timer7_flag==1)
              {
            	  ToggleLEDRed(2);  // default case
              }
              if(is_button_pressed(1))
              {
            	  status_light=SETTING_LED_GREEN;
            	  setTimer8(12);
              }
              if(is_button_pressed(3))
              {
            	  status_light=AUTO_INIT;
              }
         break;


         case SETTING_LED_GREEN:
             if(is_button_pressed_1s(2))
             {
           	  time_led_green_1=time_led_green_1+1000;
           	  sendVALUE_SETTING();
             }
             if(is_button_pressed_1s(3))
             {
           	  time_led_green_1=time_led_green_1-1000;
           	  sendVALUE_SETTING();
             }
             time_led_green_2=time_led_green_1;
             if(timer8_flag==1)
             {
           	  ToggleLEDGreen(0);
           	  ToggleLEDGreen(1);
           	  setTimer7(500); //0.5s
           	  setTimer8(1000);//1s
             }
             if(timer7_flag==1)
             {
           	  ToggleLEDGreen(2);  // default case
             }
             if(is_button_pressed(1))
             {
           	  status_light=SETTING_LED_YELLOW;
           	  setTimer8(12);
             }
             if(is_button_pressed(3))
             {
           	  status_light=AUTO_INIT;
             }
         break;



         case SETTING_LED_YELLOW:

             if(is_button_pressed_1s(2))
             {
           	  time_led_yellow_1=time_led_yellow_1+1000;
           	  sendVALUE_SETTING();
             }
             if(is_button_pressed_1s(3))
             {
           	  time_led_yellow_1=time_led_yellow_1-1000;
           	  sendVALUE_SETTING();
             }
             time_led_yellow_2=time_led_yellow_1;
             if(timer8_flag==1)
             {
           	  ToggleLEDYellow(0);
           	  ToggleLEDYellow(1);
           	  setTimer7(500); //0.5s
           	  setTimer8(1000);//1s
             }
             if(timer7_flag==1)
             {
           	  ToggleLEDYellow(2);  // default case
             }
             if(is_button_pressed(1))
             {
           	  status_light=SETTING_LED_RED;
           	  setTimer8(12);
             }
             if(is_button_pressed(3))
             {
           	  status_light=AUTO_INIT;
             }

            break;

         default:
        	 break;
     }
}
