/*
 * global.h
 *
 *  Created on: Nov 2, 2023
 *      Author: M S I
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT    		1
#define RED1GREEN2  	2
#define RED1YELLOW2  	3
#define RED2GREEN1		4
#define RED2YELLOW1		5

#define MAN_INIT 	11
#define MAN_RED     12
#define MAN_YELLOW  13
#define MAN_GREEN   14

#include "software_timer.h"
#include "button.h"
#include "main.h"

extern int status;

#endif /* INC_GLOBAL_H_ */
