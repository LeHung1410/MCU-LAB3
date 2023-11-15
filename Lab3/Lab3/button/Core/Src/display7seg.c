/*
 * display7seg.c
 *
 *  Created on: Nov 3, 2023
 *      Author: M S I
 */

#include "display7seg.h"

int led_buffer [4] = {0,5,0,3};
int index_led = 0;
int countRed1 = 5, countYellow1 = 2, countGreen1 = 3, countRed2 = 5, countYellow2 = 2, countGreen2 = 3;

void display7SEG(int num) {
	char segNumber[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
    for (int i = 0; i < 7; ++i) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 << i, (segNumber[num] >> i) & 1);
    }
}

void clearAllLed7seg(void){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
}
void TurnAllLed(void){
	HAL_GPIO_WritePin(red1_GPIO_Port,red1_Pin,RESET);
	HAL_GPIO_WritePin(yellow1_GPIO_Port,yellow1_Pin,RESET);
	HAL_GPIO_WritePin(green1_GPIO_Port,green1_Pin,RESET);
	HAL_GPIO_WritePin(red2_GPIO_Port,red2_Pin,RESET);
	HAL_GPIO_WritePin(yellow2_GPIO_Port,yellow2_Pin,RESET);
	HAL_GPIO_WritePin(green2_GPIO_Port,green2_Pin,RESET);
}

void update7SEG(int index_led){
	clearAllLed7seg();
	if (timer3_flag == 1){
	  	led_buffer[0] = countRed1 / 10;
	  	led_buffer[1] = countRed1 % 10;
	  	countRed1--;
	  	if (countRed1 < 0){
	  	led_buffer[0] = countGreen1 / 10;
	  	led_buffer[1] = countGreen1 % 10;
	  	countGreen1--;
	  	}
	  	if (countGreen1 < 0){
	  	led_buffer[0] = countYellow1 / 10;
	  	led_buffer[1] = countYellow1 % 10;
	  	countYellow1--;
	  	}
	  	if (countYellow1 == 0){
	  		countRed1 = countRED;
	  		countGreen1 = countGREEN;
	  		countYellow1 = countYELLOW;
	  	}
	  	setTimer3(100);
	  	}
	if (timer4_flag == 1){
	  	led_buffer[2] = countGreen2 / 10;
	  	led_buffer[3] = countGreen2 % 10;
	  	countGreen2--;
	  	if (countGreen2 < 0){
	  	led_buffer[2] = countYellow2 / 10;
	  	led_buffer[3] = countYellow2 % 10;
	  	countYellow2--;
	  	}
	  	if (countYellow2 < 0){
	  	led_buffer[2] = countRed2 / 10;
	  	led_buffer[3] = countRed2 % 10;
		countRed2--;
	  	}
	  	if (countRed2 == 0){
	  		countRed2 = countRED;
	  		countGreen2 = countGREEN;
	  		countYellow2= countYELLOW;
	  	}
	  	setTimer4(100);
	  	}
	switch (index_led){
  	  	  case 0:
  	  		  display7SEG(led_buffer[0]);
  	  		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
  	  		  break;
  	  	  case 1:
  	  		  display7SEG(led_buffer[1]);
  	  		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
  	  		  break;
  	  	  case 2:
  	  		  display7SEG(led_buffer[2]);
  	  	      HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
  	  		  break;
  	  	  case 3:
  	  		  display7SEG(led_buffer[3]);
  	  		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
  	  		  break;
  	  	  default:
  	  		  break;
  	  }
    }

void led_init(){
	HAL_GPIO_WritePin(red1_GPIO_Port,red1_Pin,SET);
	HAL_GPIO_WritePin(yellow1_GPIO_Port,yellow1_Pin,SET);
	HAL_GPIO_WritePin(green1_GPIO_Port,green1_Pin,SET);
	HAL_GPIO_WritePin(red2_GPIO_Port,red2_Pin,SET);
	HAL_GPIO_WritePin(yellow2_GPIO_Port,yellow2_Pin,SET);
	HAL_GPIO_WritePin(green2_GPIO_Port,green2_Pin,SET);
}
void led_red1green2(){
	HAL_GPIO_WritePin(red1_GPIO_Port,red1_Pin,RESET);
	HAL_GPIO_WritePin(yellow1_GPIO_Port,yellow1_Pin,SET);
	HAL_GPIO_WritePin(green1_GPIO_Port,green1_Pin,SET);
	HAL_GPIO_WritePin(red2_GPIO_Port,red2_Pin,SET);
	HAL_GPIO_WritePin(yellow2_GPIO_Port,yellow2_Pin,SET);
	HAL_GPIO_WritePin(green2_GPIO_Port,green2_Pin,RESET);
}
void led_red1yellow2(){
	HAL_GPIO_WritePin(red1_GPIO_Port,red1_Pin,RESET);
	HAL_GPIO_WritePin(yellow1_GPIO_Port,yellow1_Pin,SET);
	HAL_GPIO_WritePin(green1_GPIO_Port,green1_Pin,SET);
	HAL_GPIO_WritePin(red2_GPIO_Port,red2_Pin,SET);
	HAL_GPIO_WritePin(yellow2_GPIO_Port,yellow2_Pin,RESET);
	HAL_GPIO_WritePin(green2_GPIO_Port,green2_Pin,SET);
}
void led_red2green1(){
	HAL_GPIO_WritePin(red1_GPIO_Port,red1_Pin,SET);
	HAL_GPIO_WritePin(yellow1_GPIO_Port,yellow1_Pin,SET);
	HAL_GPIO_WritePin(green1_GPIO_Port,green1_Pin,RESET);
	HAL_GPIO_WritePin(red2_GPIO_Port,red2_Pin,RESET);
	HAL_GPIO_WritePin(yellow2_GPIO_Port,yellow2_Pin,SET);
	HAL_GPIO_WritePin(green2_GPIO_Port,green2_Pin,SET);
}
void led_red2yellow1(){
	HAL_GPIO_WritePin(red1_GPIO_Port,red1_Pin,SET);
	HAL_GPIO_WritePin(yellow1_GPIO_Port,yellow1_Pin,RESET);
	HAL_GPIO_WritePin(green1_GPIO_Port,green1_Pin,SET);
	HAL_GPIO_WritePin(red2_GPIO_Port,red2_Pin,RESET);
	HAL_GPIO_WritePin(yellow2_GPIO_Port,yellow2_Pin,SET);
	HAL_GPIO_WritePin(green2_GPIO_Port,green2_Pin,SET);
}
