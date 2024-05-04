/*
 * Init.c
 *
 *  Created on: Jun 17, 2023
 *      Author: giuli
 */

#include "stdio.h"
#include "TaskCLI.h"
//#include "TaskSint.h"
#include "main.h"
#include "cmsis_os.h"

void InitGPIO(void);

void Initialization(void)
{
	InitGPIO();
	InitCLITask();
}

void InitGPIO(void)
{

}


