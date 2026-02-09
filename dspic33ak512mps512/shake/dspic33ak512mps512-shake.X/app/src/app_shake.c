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
#include "app_config.h"
#include "app_shake.h"
#include "test_vectors/test_vector.h"
#include "test_vectors/shake_test_vectors.h"
#include "wolfssl/wolfcrypt/sha3.h"
#include "wolfssl/wolfcrypt/error-crypt.h"

static void SHAKE_Digest(const TEST_VECTOR* vector)
{
    int ticksToProcess = 0;
    int status = WC_FAILURE;

    /* cppcheck-suppress misra-c2012-18.8
    *
    *  (Rule 28.8) Required: Variable-length array types shall not be used
    *
    *  Reasoning: SHAKE can provide an output of any desired length. Using a variable-length array
    *               allows the application code to dynamically support vectors of varying sizes.
    */
    byte resultDigest[vector->digestSize];
    wc_Sha3 shake;

    headerOutputPrint(vector->algorithm, vector->vectorInformation);

    if(vector->algorithm == SHAKE128_ALGO)
    {
        benchmarkingStart();

        status = wc_InitShake128(&shake, NULL, SESSION_ID);

        if(status == 0)
        {
            status = wc_Shake128_Update(&shake, vector->message, vector->messageSize);
        }

        if(status == 0)
        {
            status = wc_Shake128_Final(&shake, resultDigest, vector->digestSize);
        }

        benchmarkingEnd(&ticksToProcess);
    }
    else if(vector->algorithm == SHAKE256_ALGO)
    {
        benchmarkingStart();

        status = wc_InitShake256(&shake, NULL, SESSION_ID);

        if(status == 0)
        {
            status = wc_Shake256_Update(&shake, vector->message, vector->messageSize);
        }

        if(status == 0)
        {
            status = wc_Shake256_Final(&shake, resultDigest, vector->digestSize);
        }

        benchmarkingEnd(&ticksToProcess);
    }
    else
    {
        (void) printf(RED"\r\n Unsupported SHAKE Test Vector");
    }

    if((vector->algorithm == SHAKE128_ALGO) || (vector->algorithm == SHAKE256_ALGO))
    {
        printHexArray("Expected:      ", vector->digest, vector->digestSize);
        printHexArray("Result:        ", resultDigest, vector->digestSize);

        if(status == 0)
        {
            arrayEqualityCheck(vector->digest, resultDigest, vector->digestSize);
        }
        else
        {
            (void) printf(RED"\r\n wolfCrypt SHAKE - Error Code: %d"RESET_COLOR, status);
            ledFailSet();
        }

        benchmarkingDataPrint(ticksToProcess);
    }
}

#ifdef SHAKE128_ENABLE

void SHAKE128_Digest(void)
{
#ifdef RUN_ALL_VECTORS
    const TEST_VECTOR* vectorArrayPtr = SHAKE128_TestVectorsGet();
    word32 vectorCount = SHAKE128_VectorCountGet();

    while(vectorArrayPtr < &SHAKE128_TestVectorsGet()[vectorCount])
    {
        SHAKE_Digest(vectorArrayPtr);
        vectorArrayPtr++;
    }
#else
    SHAKE_Digest(&SHAKE128_TestVectorsGet()[0]);
#endif
}

#endif

#ifdef SHAKE256_ENABLE

void SHAKE256_Digest(void)
{
#ifdef RUN_ALL_VECTORS
    const TEST_VECTOR* vectorArrayPtr = SHAKE256_TestVectorsGet();
    word32 vectorCount = SHAKE256_VectorCountGet();

    while(vectorArrayPtr < &SHAKE256_TestVectorsGet()[vectorCount])
    {
        SHAKE_Digest(vectorArrayPtr);
        vectorArrayPtr++;
    }
#else
    SHAKE_Digest(&SHAKE256_TestVectorsGet()[0]);
#endif
}

#endif


