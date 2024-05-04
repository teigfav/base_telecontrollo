/*
 * TaskShell.c
 *
 *  Created on: Jul 16, 2023
 *      Author: giuli
 */

#include "cmsis_os.h"
#include "TaskCLI.h"
#include "stdio.h"
#include "Util.h"
#include "stdlib.h"


#include "lwip/api.h"
#include "lwip/sys.h"
#include "string.h"
#include <ctype.h>
#include "lwip.h"

//#include "embedded_cli.h"
#include "stm32h7xx_hal.h"

osThreadId_t CLITaskHandle;
osMutexId_t PrintMutexHandle;
const osMutexAttr_t PrintMutexHandle_attributes = {
  .name = "SPI2Mutex"
};

extern char fw_version[];
extern char hw_rf_version[];
extern char hw_ctrl_version[];

EmbeddedCli *cli;
extern UART_HandleTypeDef huart1;
// prototype declaration
void StartCLITask(void *argument);

void InitCLITask(void)
{

const osThreadAttr_t CLITask_attributes = {
  .name = "CLITask",
  .stack_size = CLIStackSize,
  .priority = (osPriority_t) osPriorityNormal,
};
PrintMutexHandle = osMutexNew(&PrintMutexHandle_attributes);
CLITaskHandle = osThreadNew(StartCLITask, NULL, &CLITask_attributes);
};

void StartCLITask(void *argument)
{
  /* USER CODE BEGIN 5 */
	EmbeddedCliConfig *config = embeddedCliDefaultConfig();
 	config->cliBufferSize = CLI_BUFFER_SIZE;
	config->rxBufferSize = CLI_RX_BUFFER_SIZE;
	config->cmdBufferSize = CLI_CMD_BUFFER_SIZE;
	config->historyBufferSize = CLI_HISTORY_SIZE;
	config->maxBindingCount = CLI_BINDING_COUNT;
	cli = embeddedCliNew(config);


	  CliCommandBinding on_read_version={
	              "version",
	              "Read Hardware and Firmware Version",
	              true,
	              NULL,
	              onReadVersion
	      };
	  embeddedCliAddBinding(cli,on_read_version);

	  CliCommandBinding on_tasklist={
	              "tasklist",
	              "print tasklist",
	              false,
	              NULL,
	              ontasklist
	      };
	  embeddedCliAddBinding(cli,on_tasklist);


	cli->onCommand = onCommand;
	cli->writeChar = writeChar;
  /* Infinite loop */
  for(;;)
  {
	  embeddedCliProcess(cli);
  }
  /* USER CODE END 5 */
}

void writeChar(EmbeddedCli *embeddedCli, char c)
{
//	*pETH_data=c;
//	if(c!='\n' && c!='\r')
//	{
//		pETH_data++;
//	}
//	else
//	{
//		pETH_data=&ETH_data[0];
//		size_t len_ETH=strlen(ETH_data);
//		if (newconn!=NULL)
//		{
//			   netconn_write(newconn, pETH_data, len_ETH, NETCONN_COPY);  //serve per scrivere su tcpip
//		}
//		pETH_data=&ETH_data[0];
//	}
HAL_UART_Transmit(&huart1,(uint8_t*)&c,1,100);


}

void onCommand(EmbeddedCli *embeddedCli, CliCommand *command)
{
//	print_k("Received command:");
//	print_k("command name %s",command->name);
//	print_k("\n");
    embeddedCliTokenizeArgs(command->args);
    for (int i = 1; i <= embeddedCliGetTokenCount(command->args); ++i)
    {
    	print_k("arg ");
    	print_k("%d",i);
    	print_k(": ");
    	print_k("arg: %s",embeddedCliGetToken(command->args, i));
    	//print_k("\n");
    }
}


void ontasklist(EmbeddedCli *cli, char *args, void *context)
{
	print_task_list();
}


void onReadVersion(EmbeddedCli *cli, char *args, void *context)
{
	print_k("FW : %s",fw_version);
	print_k("CTRL HW : %s",hw_ctrl_version);
	print_k("RF HW : %s",hw_rf_version);
}



bool isHexadecimal(const char *s)
{
   int n = strlen(s);
   char ch;

   for (int i = 0; i < n; i++)
   {
	  ch=s[i];
      if (!isxdigit(ch)) {
    	  if (ch!='x' && ch!='X')
    	        {
    		  	  return false;
    	        }
      }
   }
   return true;
}

bool isdecimal(const char *s)
{
   int n = strlen(s);
   char ch;
   for (int i = 0; i < n; i++) {
	  ch=s[i];
      if (!isdigit(ch))
      {
    	  if (!ispunct(ch))
    	        {
    		  	  return false;
    	        }
      }
   }
   return true;
}

