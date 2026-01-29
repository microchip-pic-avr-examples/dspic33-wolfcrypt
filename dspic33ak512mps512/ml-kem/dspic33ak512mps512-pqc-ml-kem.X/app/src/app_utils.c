/*
Copyright (c) [2026] Microchip Technology Inc. and its subsidiaries.

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

void hexArrayPrint(const char* label, uint8_t* data, uint32_t size)
{
    const uint8_t *ldata = data;

    (void) printf(BLUE"\r\n -----------------------------------------------------------------------"RESET_COLOR);
    (void) printf("\r\n %s  : ", label);

    for (uint32_t index = 0U; index < size; index++)
    {
        if (((index % 8U) == 0U) && (index != 0U))
        {
            (void) printf("\r\n             ");
        }
        (void) printf(" 0x%02X", ldata[index]);
    }
}

bool arrayEqualityCheck(const uint8_t *a, const uint8_t *b, size_t size)
{
	const uint8_t *tempa = a;
	const uint8_t *tempb = b;
	uint8_t result = 0;

	for (unsigned int index = 0; index < size; index++)
    {
		result |= tempa[index] ^ tempb[index];
	}

    return result == 0U;
}

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

void headerInformationPrint(const ML_KEM_TEST_VECTOR *testVector)
{
    const char* paddingAfter = "";

    if(testVector->keyType == WC_ML_KEM_1024)
    {
        paddingAfter = "*";
    }
    else
    {
        paddingAfter = "**";
    }
    (void) printf(MAG"\r\n\r\n *************************************************************************************");
    (void) printf(CYAN"\r\n ************** ML-KEM TEST - %s ***************%s",
            testVector->vectorInformation, paddingAfter);
    (void) printf(MAG"\r\n *************************************************************************************"RESET_COLOR);
}
