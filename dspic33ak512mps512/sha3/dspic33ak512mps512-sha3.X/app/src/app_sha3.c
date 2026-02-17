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
#include "app_sha3.h"
#include "test_vectors/test_vector.h"
#include "test_vectors/sha3_test_vectors.h"
#include "wolfssl/wolfcrypt/sha3.h"
#include "wolfssl/wolfcrypt/error-crypt.h"

static void SHA3_Digest(const TEST_VECTOR* vector)
{
    int ticksToProcess = 0;
    int status = WC_FAILURE;
    byte resultDigest[64];
    wc_Sha3 sha3;

    headerOutputPrint(vector->algorithm, vector->vectorInformation);

    if(vector->algorithm == (int)SHA3_224_ALGO)
    {
        benchmarkingStart();

        status = wc_InitSha3_224(&sha3, NULL, SESSION_ID);

        if(status == 0)
        {
            status = wc_Sha3_224_Update(&sha3, vector->message, vector->messageSize);
        }

        if(status == 0)
        {
            status = wc_Sha3_224_Final(&sha3, resultDigest);
        }

        benchmarkingEnd(&ticksToProcess);
    }
    else if(vector->algorithm == (int)SHA3_256_ALGO)
    {
        benchmarkingStart();

        status = wc_InitSha3_256(&sha3, NULL, SESSION_ID);

        if(status == 0)
        {
            status = wc_Sha3_256_Update(&sha3, vector->message, vector->messageSize);
        }

        if(status == 0)
        {
            status = wc_Sha3_256_Final(&sha3, resultDigest);
        }

        benchmarkingEnd(&ticksToProcess);
    }
    else if(vector->algorithm == (int)SHA3_384_ALGO)
    {
        benchmarkingStart();

        status = wc_InitSha3_384(&sha3, NULL, SESSION_ID);

        if(status == 0)
        {
            status = wc_Sha3_384_Update(&sha3, vector->message, vector->messageSize);
        }

        if(status == 0)
        {
            status = wc_Sha3_384_Final(&sha3, resultDigest);
        }

        benchmarkingEnd(&ticksToProcess);
    }
    else if(vector->algorithm == (int)SHA3_512_ALGO)
    {
        benchmarkingStart();

        status = wc_InitSha3_512(&sha3, NULL, SESSION_ID);

        if(status == 0)
        {
            status = wc_Sha3_512_Update(&sha3, vector->message, vector->messageSize);
        }

        if(status == 0)
        {
            status = wc_Sha3_512_Final(&sha3, resultDigest);
        }

        benchmarkingEnd(&ticksToProcess);
    }
    else
    {
        (void) printf(RED"\r\n Unsupported SHA3 Test Vector");
    }

    if((vector->algorithm == (int)SHA3_224_ALGO) || (vector->algorithm == (int)SHA3_256_ALGO)
            || (vector->algorithm == (int)SHA3_384_ALGO) || (vector->algorithm == (int)SHA3_512_ALGO))
    {
        printHexArray("Expected:      ", vector->digest, vector->digestSize);
        printHexArray("Result:        ", resultDigest, vector->digestSize);

        if(status == 0)
        {
            arrayEqualityCheck(vector->digest, resultDigest, vector->digestSize);
        }
        else
        {
            (void) printf(RED"\r\n wolfCrypt SHA3 - Error Code: %d"RESET_COLOR, status);
            ledFailSet();
        }

        benchmarkingDataPrint(ticksToProcess);
    }
}

#ifdef SHA3_224_ENABLE

void SHA3_224_Digest(void)
{
#ifdef RUN_ALL_VECTORS
    const TEST_VECTOR* vectorArrayPtr = SHA3_224_TestVectorsGet();
    word32 vectorCount = SHA3_224_VectorCountGet();

    while(vectorArrayPtr < &SHA3_224_TestVectorsGet()[vectorCount])
    {
        SHA3_Digest(vectorArrayPtr);
        vectorArrayPtr++;
    }
#else
    SHA3_Digest(&SHA3_224_TestVectorsGet()[0]);
#endif
}

#endif

#ifdef SHA3_256_ENABLE

void SHA3_256_Digest(void)
{
#ifdef RUN_ALL_VECTORS
    const TEST_VECTOR* vectorArrayPtr = SHA3_256_TestVectorsGet();
    word32 vectorCount = SHA3_256_VectorCountGet();

    while(vectorArrayPtr < &SHA3_256_TestVectorsGet()[vectorCount])
    {
        SHA3_Digest(vectorArrayPtr);
        vectorArrayPtr++;
    }
#else
    SHA3_Digest(&SHA3_256_TestVectorsGet()[0]);
#endif
}

#endif

#ifdef SHA3_384_ENABLE

void SHA3_384_Digest(void)
{
#ifdef RUN_ALL_VECTORS
    const TEST_VECTOR* vectorArrayPtr = SHA3_384_TestVectorsGet();
    word32 vectorCount = SHA3_384_VectorCountGet();

    while(vectorArrayPtr < &SHA3_384_TestVectorsGet()[vectorCount])
    {
        SHA3_Digest(vectorArrayPtr);
        vectorArrayPtr++;
    }
#else
    SHA3_Digest(&SHA3_384_TestVectorsGet()[0]);
#endif
}

#endif

#ifdef SHA3_512_ENABLE

void SHA3_512_Digest(void)
{
#ifdef RUN_ALL_VECTORS
    const TEST_VECTOR* vectorArrayPtr = SHA3_512_TestVectorsGet();
    word32 vectorCount = SHA3_512_VectorCountGet();

    while(vectorArrayPtr < &SHA3_512_TestVectorsGet()[vectorCount])
    {
        SHA3_Digest(vectorArrayPtr);
        vectorArrayPtr++;
    }
#else
    SHA3_Digest(&SHA3_512_TestVectorsGet()[0]);
#endif
}

#endif
