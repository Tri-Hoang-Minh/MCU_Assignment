/*
 * button.h
 *
 *  Created on: Dec 13, 2022
 *      Author: Hoang Tri
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"


void getKeyInput();
unsigned char is_button_pressed(unsigned char button_number);   // Nhan tha
unsigned char is_button_pressed_1s(unsigned char button_number);  // hold button 1s. (Nhan de)


#endif /* INC_BUTTON_H_ */
