/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "main.h"
#include "app/inc/MainApp.h"
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
static uint16_t gu16MainTimeOut=0U;

int main ( void )
{
    /* Initialize all modules */
    //SYS_Initialize ( NULL ); /*Microchip initial function*/

    while ( gu16MainTimeOut <= 0xFF00U )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        /* Main App Task*/
        if (MainApp_Task() == FALSE)
        {
            gu16MainTimeOut+=1U;
        }
		else
		{
			gu16MainTimeOut=0U;
		}
//        static uint8_t u8TimeBuffer[30] = {0};
//        sprintf((char *)u8TimeBuffer,"TimerCount = %ld \n",timercount);
//        SERCOM1_USART_Write(u8TimeBuffer,strlen((const char*)u8TimeBuffer));
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}

/*******************************************************************************
 End of File
*/

