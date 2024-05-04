/*
 * Util.c
 *
 *  Created on: Jul 16, 2023
 *      Author: giuli
 */

#include "Util.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"
#include "cmsis_os.h"
#include "stm32h7xx_hal.h"
#include "main.h"

#include "lwipopts.h"
#include "cmsis_os.h"
#include "lwip/opt.h"
#include "stdio.h"
#include "lwip/api.h"
#include "lwip/sys.h"
#include "string.h"
#include "embedded_cli.h"
#include "lwip.h"
#include "lwip/netif.h"
#include "lwip/dhcp.h"
#include "task.h"
#include "cmsis_os2.h"


#define VREFDAC 2.5
#define OS_THREAD_MAX 30

extern SPI_HandleTypeDef hspi3;
extern osMutexId_t SPI3MutexHandle;
extern osMutexId_t PrintMutexHandle;
extern struct netconn *newconn;
extern struct netconn *conn;
extern EmbeddedCli *cli;

void LOG_DBG(char *format, ...) {
   va_list args;
   uint32_t time_ms=osKernelGetTickCount();
   uint32_t h,sec,min,ms;
   char stringa[200];
   char timestamp[200];
//   stringa[0]='p';
//   stringa[1]='i';
//   memcpy(stringa,'pippo',5);
   memset(timestamp,0,200);
   memset(stringa,0,200);
   h=time_ms/3600000;
   min=(time_ms-(h*3600000))/60000;
   sec=(time_ms-(h*3600000)-(min*60000))/1000;
   ms=(time_ms-(h*3600000)-(min*60000)-sec*1000);

//   printf("[%ld:%ld:%ld:%.3ld] ",h,min,sec,ms);   //con printf non esce mai sulla rete
   va_start(args, format);
   if(osMutexAcquire(PrintMutexHandle,osWaitForever)==osOK)
      {
   	  snprintf(timestamp,40,"[%ld:%ld:%ld:%.3ld] ",h,min,sec,ms);   //con printf non esce mai sulla rete
   	  vsprintf(stringa,format, args);
   	  strcat(timestamp,stringa);
      embeddedCliPrint(cli, timestamp);
      osMutexRelease(PrintMutexHandle);
      }

   va_end(args);
}
/**
  * @brief  per ora scrive sia su uart che su tcp se connesso.
  * @param  None
  * @retval None
  */
void print_k(char *format, ...) {
	char msg_ETH[512];
	va_list args;
   va_start(args, format);
   if(osMutexAcquire(PrintMutexHandle,osWaitForever)==osOK)
      {
	   vsprintf(msg_ETH,format, args);
//   	   size_t len = strlen(msg_ETH);
//   	   if (newconn!=NULL)
//   	   {
//   	   netconn_write(newconn, msg_ETH, len, NETCONN_COPY);  //serve per scrivere su tcpip
//   	   netconn_write(newconn, "\n", 1, NETCONN_COPY);  //serve per scrivere su tcpip
//   	   }
   	   embeddedCliPrint(cli, msg_ETH);
      osMutexRelease(PrintMutexHandle);
      }

   va_end(args);
}

void print_task_list(void)
{
    char buffer[512]; // Buffer to store the task list output
    vTaskList(buffer); // Generate the task list
    print_k("%s", buffer); // Print the task list
}

// Stack overflow hook function
void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName ) {
    print_k("Stack overflow detected in task: %s", pcTaskName);
}
