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
#include "system/clock.h"
#include "system/pins.h"

void hexArrayPrint(const char* label, uint8_t* data, uint32_t size)
{
    const uint8_t *ldata = data;

    (void) printf(BLUE"\r\n -------------------------------------------------------------------------------------"RESET_COLOR);
    (void) printf("\r\n %s  : ", label);

    for (uint32_t index = 0U; index < size; index++)
    {
        if (((index % 8U) == 0U) && (index != 0U))
        {
            (void) printf("\r\n                          ");
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
    T1CONbits.TON = 1;
    BENCHMARKING_RE6_SetHigh();
}

void benchmarkingEnd(void)
{
    BENCHMARKING_RE6_SetLow();
    T1CONbits.TON = 0;
}

void benchmarkingDataPrint(uint32_t microseconds)
{
    uint32_t cycles = microseconds * (CLOCK_InstructionFrequencyGet() / (uint32_t) 1000000);
    double seconds = (double) microseconds / (double) 1000000;

    (void) printf("\r\n Cycles spent: %lu", cycles);
    (void) printf("\r\n Seconds spent: %lf", seconds);
}

void headerInformationPrint(const RSA_TEST_VECTOR *testVector)
{
    (void) printf(MAG"\r\n\r\n *************************************************************************************");
    (void) printf(CYAN"\r\n ************** RSA TEST - %s ***************", testVector->vectorInformation);
    (void) printf(MAG"\r\n *************************************************************************************"RESET_COLOR);
}

void resultVerify(uint8_t* hashedMessage, uint8_t *result, int resultSize)
{
    bool areArraysEqual = false;

    hexArrayPrint("Expected (decrypted) ", hashedMessage, resultSize);
    hexArrayPrint("Result (decrypted)   ", result, resultSize);

    areArraysEqual = arrayEqualityCheck(hashedMessage, result, resultSize);

    if(areArraysEqual)
    {
        (void) printf(GREEN" \r\n\r\n wolfCrypt RSA Signature Verify Success "RESET_COLOR);
    }
    else
    {
        (void) printf(RED"\r\n\r\n wolfCrypt RSA Signature Verify Failure"RESET_COLOR);
    }
}