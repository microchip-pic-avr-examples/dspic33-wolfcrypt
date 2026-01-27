/*
? [2026] Microchip Technology Inc. and its subsidiaries.

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
#include "test_vectors/test_vector.h"
#include "app_utils.h"
#include "wolfssl/wolfcrypt/wc_mlkem.h"
#include "wolfssl/wolfcrypt/error-crypt.h"
#include "app_config.h"

#if defined(MLKEM_DECAPSULATE)

    static void MLKEM_Decapsulate(ML_KEM_TEST_VECTOR *testVector)
    {
        uint8_t sharedSecretResult[32];

        int ticksToProcess = 0;
        int status = WC_FAILURE;
        bool areArraysEqual = false;

        headerInformationPrint(testVector);

        benchmarkingStart();

        status = wc_MlKemKey_Init(testVector->mlKemKey, testVector->keyType, NULL, 1);

        if(status == 0)
        {
            status = wc_MlKemKey_DecodePrivateKey(testVector->mlKemKey, testVector->decapsulationKey, testVector->decapsulationKeyLength);
        }

        if(status == 0)
        {
            status = wc_MlKemKey_Decapsulate(testVector->mlKemKey, (unsigned char*) &sharedSecretResult, testVector->ciphertext, testVector->ciphertextLength);
        }

        if(status == 0)
        {
            status = wc_MlKemKey_Free(testVector->mlKemKey);
        }

        benchmarkingEnd(&ticksToProcess);

        if(status == 0)
        {
            hexArrayPrint("Expected", testVector->expectedSharedSecret, WC_ML_KEM_SS_SZ);
            hexArrayPrint("Result  ", sharedSecretResult, WC_ML_KEM_SS_SZ);

            areArraysEqual = arrayEqualityCheck(testVector->expectedSharedSecret, sharedSecretResult, WC_ML_KEM_SS_SZ);
        }

        if((status == 0) && areArraysEqual)
        {
            (void) printf(GREEN" \r\n\r\n wolfCrypt ML-KEM Decapsulation Valid "RESET_COLOR);
        }
        else if (status != 0)
        {
            (void) printf(RED"\r\n wolfCrypt ML-KEM - Error Code: %d"RESET_COLOR, status);
        }
        else
        {
            (void) printf(RED"\r\n wolfCrypt ML-KEM Decapsulation Invalid"RESET_COLOR);
        }

        benchmarkingDataPrint(ticksToProcess);
    }

    #ifdef MLKEM_512
    extern ML_KEM_TEST_VECTOR ml_kem_512_decapsulate;
    void MLKEM_512Decapsulate(void)
    {
        MLKEM_Decapsulate((ML_KEM_TEST_VECTOR*) &ml_kem_512_decapsulate);
    }
    #endif

    #ifdef MLKEM_768
    extern ML_KEM_TEST_VECTOR ml_kem_768_decapsulate;
    void MLKEM_768Decapsulate(void)
    {
        MLKEM_Decapsulate((ML_KEM_TEST_VECTOR*) &ml_kem_768_decapsulate);
    }
    #endif

    #ifdef MLKEM_1024
    extern ML_KEM_TEST_VECTOR ml_kem_1024_decapsulate;
    void MLKEM_1024Decapsulate(void)
    {
        MLKEM_Decapsulate((ML_KEM_TEST_VECTOR*) &ml_kem_1024_decapsulate);
    }
    #endif

#endif