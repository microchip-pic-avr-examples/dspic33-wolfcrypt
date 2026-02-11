/*
Copyright (C) [2026] Microchip Technology Inc. and its subsidiaries.

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
#include "test_vectors/test_vector.h"
#include "wolfssl/wolfcrypt/lms.h"

void benchmarkingStart(void)
{
    TMR1 = 0;
    BENCHMARKING_P28_SetHigh();
}

void benchmarkingEnd(int* ticksToProcess)
{
    BENCHMARKING_P28_SetLow();
    *ticksToProcess = TMR1;
}

void benchmarkingDataPrint(int ticksToProcess)
{
    double seconds = (double) ticksToProcess / (double) 100000000;
    uint32_t cycles = seconds * CLOCK_InstructionFrequencyGet();

    (void) printf("\r\n Cycles spent: %lu", cycles);
    (void) printf("\r\n Seconds spent: %lf", seconds);
}


void headerInformationPrint(LMS_TEST_VECTOR *testVector)
{
    const char* paddingBefore = "";
    const char* paddingAfter = "";

    if(testVector->lmsKey->params->hash_len == 24)
    {
        paddingAfter = (testVector->lmsKey->params->height == 5) ? "******" : "*****";
    }
    else
    {
        paddingBefore = "**";
        paddingAfter = (testVector->lmsKey->params->height == 5) ? "********" : "*******";
    }

    (void) printf(MAG"\r\n\r\n *************************************************************************************");
    (void) printf(CYAN"\r\n %s***************** LMS TEST - %s ************%s",
            paddingBefore, testVector->vectorInformation, paddingAfter);
    (void) printf(MAG"\r\n *************************************************************************************"RESET_COLOR);
}

void parametersPrint(LMS_TEST_VECTOR *testVector)
{
    (void) printf("\r\n Parameters:");
    (void) printf("\r\n Levels: %d", testVector->lmsKey->params->levels);
    (void) printf("\r\n Height: %d", testVector->lmsKey->params->height);
    (void) printf("\r\n Width: %d", testVector->lmsKey->params->width);
    (void) printf("\r\n Ls: %d", testVector->lmsKey->params->ls);
    (void) printf("\r\n P: %d", testVector->lmsKey->params->p);
    (void) printf("\r\n LmsType: %d", testVector->lmsKey->params->lmsType);
    (void) printf("\r\n LmOtsType: %d", testVector->lmsKey->params->lmOtsType);
    (void) printf("\r\n Signature Length: %d", testVector->lmsKey->params->sig_len);
    (void) printf("\r\n Hash Length: %d", testVector->lmsKey->params->hash_len);
}