/*
 * display7seg.h
 *
 *  Created on: Nov 3, 2023
 *      Author: M S I
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

#include "global.h"
#include "fsm_manual.h"

void display7SEG(int num);
void update7SEG(int index);
void clearAllLed7seg(void);
void TurnAllLed(void);

void led_init();
void led_red1green2();
void led_red1yellow2();
void led_red2green1();
void led_red2yellow1();

extern int index_led;
extern int led_buffer[4];
extern int countRed1, countRed2, countYellow1, countYellow2, countGreen1, countGreen2;
#endif /* INC_DISPLAY7SEG_H_ */
