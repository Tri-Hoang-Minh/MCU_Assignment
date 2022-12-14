/*
 * displayallLED.h
 *
 *  Created on: Dec 13, 2022
 *      Author: Hoang Tri
 */

#ifndef INC_DISPLAYALLLED_H_
#define INC_DISPLAYALLLED_H_
#include "main.h"

void ToggleLEDRed(int light);
void ToggleLEDYellow(int light);
void ToggleLEDGreen(int light);
void ToggleLEDPedestrian(int state);
void clearLED(int index_light);


#endif /* INC_DISPLAYALLLED_H_ */
