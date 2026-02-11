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
*  Reasoning: printf is required for printing to the terminal in this code example
*/
#include <stdio.h>
#include "app_utils.h"
#include "app_config.h"
#include "app_ml_dsa.h"
#include "test_vectors/test_vector.h"
#include <wolfssl/wolfcrypt/dilithium.h>
#include <wolfssl/wolfcrypt/error-crypt.h>

#ifdef MLDSA_SIGNATURE_VERIFICATION

    static void MLDSA_Verify(ML_DSA_SIG_VER_TEST_VECTOR* vector, byte level)
    {
        headerOutputPrint(vector->vectorInformation);

        int status = 0;
        int error = WC_FAILURE;

        dilithium_key key;

        wc_MlDsaKey_SetParams(&key, level);
        wc_MlDsaKey_ImportPubRaw(&key, vector->publicKey, vector->publicKeyLength);  
                
        benchmarkingStart();

        error = wc_MlDsaKey_Verify(
                &key,
                (const byte*)vector->signature,
                vector->signatureSize,
                (const byte*) vector->message,
                vector->messageSize,
                &status
            );

        benchmarkingEnd();

        
        if(error == 0)
        {
            outputMessagePrint(status, &key);
        }
        else
        {
            (void) printf(RED"\r\n wolfCrypt ML-DSA - Error Code: %d"RESET_COLOR, error);
        }
    }

    #ifdef MLDSA_44
    extern ML_DSA_SIG_VER_TEST_VECTOR ml_dsa_dilithium_44;

    void MLDSA_44Verify(void)
    {
        MLDSA_Verify(&ml_dsa_dilithium_44, WC_ML_DSA_44);
    }
    #endif

    #ifdef MLDSA_65
    extern ML_DSA_SIG_VER_TEST_VECTOR ml_dsa_dilithium_65;
    
    void MLDSA_65Verify(void)
    {
        MLDSA_Verify(&ml_dsa_dilithium_65, WC_ML_DSA_65);
    }
    #endif

    #ifdef MLDSA_87
    extern ML_DSA_SIG_VER_TEST_VECTOR ml_dsa_dilithium_87;

    void MLDSA_87Verify(void)
    {
        MLDSA_Verify(&ml_dsa_dilithium_87, WC_ML_DSA_87);
    }
    #endif
#endif
