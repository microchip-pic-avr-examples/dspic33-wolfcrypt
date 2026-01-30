/*
� [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip
    software and any derivatives exclusively with Microchip products.
    You are responsible for complying with 3rd party license terms
    applicable to your use of 3rd party software (including open source
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.?
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR
    THIS SOFTWARE.
*/

/* cppcheck-suppress misra-c2012-21.6
*
*  (Rule 21.6) REQUIRED: The standard library input/output functions shall not be used
*
*  Reasoning: This demo uses printf to print out information to a terminal.
*/
#include <stdio.h>
#include "app_utils.h"
#include "timer/tmr1.h"
#include "system/clock.h"
#include "system/pins.h"

static uint32_t microSeconds = 0;

static void microSecondIncrement(void)
{
    microSeconds++;
}

void benchmarkingStart(void)
{
    BENCHMARKING_RE6_SetHigh();
    Timer1.TimeoutCallbackRegister(microSecondIncrement);
    microSeconds = 0;
    T1CONbits.TON = 1;
}

void benchmarkingEnd(void)
{
    T1CONbits.TON = 0;
    BENCHMARKING_RE6_SetLow();
    double seconds = (double) microSeconds / (double) 1000000;
    uint32_t cycles = seconds * CLOCK_InstructionFrequencyGet();

    (void) printf("\r\n Cycles spent: %lu", cycles);
    (void) printf("\r\n Seconds spent: %lf", seconds);
}

void outputMessagePrint(int status, dilithium_key* key)
{
    (void) printf("\r\n Parameters:");
    (void) printf("\r\n Level: %d", key->params->level);
    (void) printf("\r\n Public key size: %d", key->params->pkSz);
    (void) printf("\r\n Signature Length: %d", key->params->sigSz);

    if(status == 1)
    {
        (void) printf(GREEN"\r\n Message Verified Successfully"RESET_COLOR);
        PASS_setHigh();
    }
    else
    {
        (void) printf(RED"\r\n Message Verification Failed"RESET_COLOR);
        FAIL_setHigh();
    }
}

void headerOutputPrint(const char* vectorInformation)
{
    (void) printf(MAG"\r\n\r\n *************************************************************************************");
    (void) printf(CYAN"\r\n ****************** ML-DSA TEST %s ******************", vectorInformation);
    (void) printf(MAG"\r\n *************************************************************************************"RESET_COLOR);
}
