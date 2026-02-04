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
#include "app_sha2.h"
#include "test_vectors/test_vector.h"
#include "test_vectors/sha2_test_vectors.h"
#include "wolfssl/wolfcrypt/sha256.h"
#include "wolfssl/wolfcrypt/sha512.h"
#include "wolfssl/wolfcrypt/error-crypt.h"
#include "timer/tmr1.h"

static uint32_t microsecondsToProcess = 0;
static void microsecondIncrement(void)
{
    microsecondsToProcess++;
}

static void SHA2_Digest(const TEST_VECTOR* vector)
{
    int status = WC_FAILURE;
    byte resultDigest[64];
    wc_Sha256 sha256;
    wc_Sha512 sha512;

    headerOutputPrint(vector->algorithm, vector->vectorInformation);

    Timer1.TimeoutCallbackRegister(microsecondIncrement);
    microsecondsToProcess = 0;

    if(vector->algorithm == SHA2_224_ALGO)
    {
        benchmarkingStart();

        status = wc_InitSha224_ex(&sha256, NULL, SESSION_ID);

        if(status == 0)
        {
            status = wc_Sha224Update(&sha256, vector->message, vector->messageSize);
        }

        if(status == 0)
        {
            status = wc_Sha224Final(&sha256, resultDigest);
        }

        benchmarkingEnd();
    }
    else if(vector->algorithm == SHA2_256_ALGO)
    {
        benchmarkingStart();

        status = wc_InitSha256_ex(&sha256, NULL, SESSION_ID);

        if(status == 0)
        {
            status = wc_Sha256Update(&sha256, vector->message, vector->messageSize);
        }

        if(status == 0)
        {
            status = wc_Sha256Final(&sha256, resultDigest);
        }

        benchmarkingEnd();
    }
    else if(vector->algorithm == SHA2_384_ALGO)
    {
        benchmarkingStart();

        status = wc_InitSha384_ex(&sha512, NULL, SESSION_ID);

        if(status == 0)
        {
            status = wc_Sha384Update(&sha512, vector->message, vector->messageSize);
        }

        if(status == 0)
        {
            status = wc_Sha384Final(&sha512, resultDigest);
        }

        benchmarkingEnd();
    }
    else if(vector->algorithm == SHA2_512_ALGO)
    {
        benchmarkingStart();

        status = wc_InitSha512_ex(&sha512, NULL, SESSION_ID);

        if(status == 0)
        {
            status = wc_Sha512Update(&sha512, vector->message, vector->messageSize);
        }

        if(status == 0)
        {
            status = wc_Sha512Final(&sha512, resultDigest);
        }

        benchmarkingEnd();
    }
    else
    {
        (void) printf(RED"\r\n Unsupported SHA2 Test Vector");
    }

    if((vector->algorithm == SHA2_224_ALGO) || (vector->algorithm == SHA2_256_ALGO)
            || (vector->algorithm == SHA2_384_ALGO) || (vector->algorithm == SHA2_512_ALGO))
    {
        printHexArray("Expected:      ", vector->digest, vector->digestSize);
        printHexArray("Result:        ", resultDigest, vector->digestSize);

        if(status == 0)
        {
            arrayEqualityCheck(vector->digest, resultDigest, vector->digestSize);
        }
        else
        {
            (void) printf(RED"\r\n wolfCrypt SHA2 - Error Code: %d"RESET_COLOR, status);
        }

        benchmarkingDataPrint(microsecondsToProcess);
    }
}

#ifdef SHA2_224_ENABLE

void SHA2_224_Digest(void)
{
#ifdef RUN_ALL_VECTORS
    const TEST_VECTOR* vectorArrayPtr = SHA2_224_TestVectorsGet();
    word32 vectorCount = SHA2_224_VectorCountGet();

    while(vectorArrayPtr < &SHA2_224_TestVectorsGet()[vectorCount])
    {
        SHA2_Digest(vectorArrayPtr);
        vectorArrayPtr++;
    }
#else
    SHA2_Digest(&SHA2_224_TestVectorsGet()[0]);
#endif
}

#endif

#ifdef SHA2_256_ENABLE

void SHA2_256_Digest(void)
{
#ifdef RUN_ALL_VECTORS
    const TEST_VECTOR* vectorArrayPtr = SHA2_256_TestVectorsGet();
    word32 vectorCount = SHA2_256_VectorCountGet();

    while(vectorArrayPtr < &SHA2_256_TestVectorsGet()[vectorCount])
    {
        SHA2_Digest(vectorArrayPtr);
        vectorArrayPtr++;
    }
#else
    SHA2_Digest(&SHA2_256_TestVectorsGet()[0]);
#endif
}

#endif

#ifdef SHA2_384_ENABLE

void SHA2_384_Digest(void)
{
#ifdef RUN_ALL_VECTORS
    const TEST_VECTOR* vectorArrayPtr = SHA2_384_TestVectorsGet();
    word32 vectorCount = SHA2_384_VectorCountGet();

    while(vectorArrayPtr < &SHA2_384_TestVectorsGet()[vectorCount])
    {
        SHA2_Digest(vectorArrayPtr);
        vectorArrayPtr++;
    }
#else
    SHA2_Digest(&SHA2_384_TestVectorsGet()[0]);
#endif
}

#endif

#ifdef SHA2_512_ENABLE

void SHA2_512_Digest(void)
{
#ifdef RUN_ALL_VECTORS
    const TEST_VECTOR* vectorArrayPtr = SHA2_512_TestVectorsGet();
    word32 vectorCount = SHA2_512_VectorCountGet();

    while(vectorArrayPtr < &SHA2_512_TestVectorsGet()[vectorCount])
    {
        SHA2_Digest(vectorArrayPtr);
        vectorArrayPtr++;
    }
#else
    SHA2_Digest(&SHA2_512_TestVectorsGet()[0]);
#endif
}

#endif
