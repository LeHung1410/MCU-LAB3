/*
 * fsm_trafficlight.c
 *
 *  Created on: Nov 2, 2023
 *      Author: M S I
 */

#include "fsm_trafficlight.h"
#include "display7seg.h"
#include "global.h"
#include "fsm_manual.h"

void fsm_trafficlight_run(){
	if (timer2_flag == 1){
		setTimer2(25);
		update7SEG(index_led++);
		if (index_led >=4) index_led = 0;
	}
	switch(status){
	case INIT:
		if(countRED == countYELLOW + countGREEN){
			led_init();
			status = RED1GREEN2;
			setTimer1(countGREEN*100);
		}
		else{
			TurnAllLed();
			led_buffer[0] = 0;
			led_buffer[1] = 0;
			led_buffer[2] = 0;
			led_buffer[3] = 0;
		}
		break;
	case RED1GREEN2:
		led_red1green2();
		if(timer1_flag == 1){
			status = RED1YELLOW2;
			setTimer1(countYELLOW*100);
		}
		if(isButton1Pressed() == 1){
			status = MAN_RED;
			countRed1 = 5;
			HAL_GPIO_WritePin(red2_GPIO_Port,red2_Pin,RESET);
			setTimer1(01);
			setTimer2(01);
			setTimer3(00);
			setTimer4(00);
			led_buffer[0] = 0;
			led_buffer[1] = 2;
			led_buffer[2] = countRED / 10;
			led_buffer[3] = countRED % 10;
			index_led = 0;
		}
		if (isButton2Pressed() == 1)  countRED = countRED;
		break;

	case RED1YELLOW2:
		led_red1yellow2();
		if(timer1_flag == 1){
			status = RED2GREEN1;
			setTimer1(countGREEN*100);
		}
		if(isButton1Pressed() == 1){
			status = MAN_RED;
			HAL_GPIO_WritePin(red2_GPIO_Port,red2_Pin,RESET);
			setTimer1(01);
			setTimer2(01);
			setTimer3(00);
			setTimer4(00);
			led_buffer[0] = 0;
			led_buffer[1] = 2;
			led_buffer[2] = countRED / 10;
			led_buffer[3] = countRED % 10;
			index_led = 0;
		}
		if (isButton2Pressed() == 1)  countRED = countRED;
		break;
	case RED2GREEN1:
		led_red2green1();
		if(timer1_flag == 1){
			status = RED2YELLOW1;
			setTimer1(countYELLOW*100);
		}
		if(isButton1Pressed() == 1){
			status = MAN_RED;
			HAL_GPIO_WritePin(red1_GPIO_Port,red1_Pin,RESET);
			setTimer1(01);
			setTimer2(01);
			setTimer3(00);
			setTimer4(00);
			led_buffer[0] = 0;
			led_buffer[1] = 2;
			led_buffer[2] = countRED / 10;
			led_buffer[3] = countRED % 10;
			index_led = 0;
		}
		if (isButton2Pressed() == 1)  countRED = countRED;
		break;
	case RED2YELLOW1:
		led_red2yellow1();
		if(timer1_flag ==1){
			status = RED1GREEN2;
			setTimer1(countGREEN*100);
		}
		if(isButton1Pressed() == 1){
			status = MAN_RED;
			HAL_GPIO_WritePin(red1_GPIO_Port,red1_Pin,RESET);
			setTimer1(01);
			setTimer2(01);
			setTimer3(00);
			setTimer4(00);
			led_buffer[0] = 0;
			led_buffer[1] = 2;
			led_buffer[2] = countRED / 10;
			led_buffer[3] = countRED % 10;
			index_led = 0;
		}
		if (isButton2Pressed() == 1)  countRED = countRED;
		break;
	default:
		break;
	}
}
