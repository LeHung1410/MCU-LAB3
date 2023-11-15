/*
 * software_timer.h
 *
 *  Created on: Oct 15, 2023
 *      Author: M S I
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TIMER_CYLCE 10;

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer4_flag;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);

void timerRun();
void BlinkyTimer(int duration);

#endif /* INC_SOFTWARE_TIMER_H_ */
