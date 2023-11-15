/*
 * fsm_manual.c
 *
 *  Created on: Nov 2, 2023
 *      Author: M S I
 */

#include "fsm_manual.h"
#include "display7seg.h"

int countRED = 05, countYELLOW = 02, countGREEN = 03;
void fsm_manual_run(){
	switch(status){
		case MAN_RED:
			if (timer1_flag == 1){
				setTimer1(25);
				HAL_GPIO_TogglePin(red1_GPIO_Port, red1_Pin);
				HAL_GPIO_TogglePin(red2_GPIO_Port, red2_Pin);
			}
			HAL_GPIO_WritePin(yellow1_GPIO_Port,yellow1_Pin,SET);
			HAL_GPIO_WritePin(green1_GPIO_Port,green1_Pin,SET);
			HAL_GPIO_WritePin(yellow2_GPIO_Port,yellow2_Pin,SET);
			HAL_GPIO_WritePin(green2_GPIO_Port,green2_Pin,SET);
			if (isButton1Pressed() == 1){
				status = MAN_YELLOW;
				setTimer1(01);
				setTimer2(01);
				setTimer3(00);
				setTimer4(00);
				led_buffer[0] = 0;
				led_buffer[1] = 3;
				led_buffer[2] = countYELLOW / 10;
				led_buffer[3] = countYELLOW % 10;
				index_led = 0;
			}
			if (isButton2Pressed() == 1){
				countRED++;
				led_buffer[2] = countRED / 10;
				led_buffer[3] = countRED % 10;
				if (countRED >= 99) countRED = 00;
			}
			if (isButton3Pressed() == 1){
				countRed1 = countRed2 = countRED;
			}
			break;
		case MAN_YELLOW:
			if (timer1_flag == 1){
				setTimer1(25);
				HAL_GPIO_TogglePin(yellow1_GPIO_Port, yellow1_Pin);
				HAL_GPIO_TogglePin(yellow2_GPIO_Port, yellow2_Pin);
			}
			HAL_GPIO_WritePin(red1_GPIO_Port,red1_Pin,SET);
			HAL_GPIO_WritePin(green1_GPIO_Port,green1_Pin,SET);
			HAL_GPIO_WritePin(red2_GPIO_Port,red2_Pin,SET);
			HAL_GPIO_WritePin(green2_GPIO_Port,green2_Pin,SET);
			if (isButton1Pressed() == 1){
				status = MAN_GREEN;
				setTimer1(01);
				setTimer2(01);
				setTimer3(00);
				setTimer4(00);
				led_buffer[0] = 0;
				led_buffer[1] = 4;
				led_buffer[2] = countGREEN / 10;
				led_buffer[3] = countGREEN % 10;
				index_led = 0;
			}
			if (isButton2Pressed() == 1){
				countYELLOW++;
				led_buffer[2] = countYELLOW / 10;
				led_buffer[3] = countYELLOW % 10;
				if(countYELLOW >= 99) countYELLOW = 00;
			}
			if (isButton3Pressed() == 1){
				countYellow1 = countYellow2 = countYELLOW;
			}
			break;
		case MAN_GREEN:
			if (timer1_flag == 1){
				setTimer1(25);
				HAL_GPIO_TogglePin(green1_GPIO_Port, green1_Pin);
				HAL_GPIO_TogglePin(green2_GPIO_Port, green2_Pin);
			}
			HAL_GPIO_WritePin(red1_GPIO_Port,red1_Pin,SET);
			HAL_GPIO_WritePin(yellow1_GPIO_Port,yellow1_Pin,SET);
			HAL_GPIO_WritePin(red2_GPIO_Port,red2_Pin,SET);
			HAL_GPIO_WritePin(yellow2_GPIO_Port,yellow2_Pin,SET);
			if (isButton1Pressed() == 1){
				status = INIT;
				setTimer2(01);
				setTimer3(01);
				setTimer4(01);
				index_led = 0;
			}
			if (isButton2Pressed() == 1){
				countGREEN++;
				led_buffer[2] = countGREEN / 10;
				led_buffer[3] = countGREEN % 10;
				if(countGREEN >= 99) countGREEN = 00;
			}
			if (isButton3Pressed() == 1){
				countGreen1 = countGreen2 = countGREEN;
			}
			break;
		default:
			break;
	}
}