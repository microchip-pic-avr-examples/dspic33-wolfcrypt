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
#include "wolfssl/wolfcrypt/ecc.h"
#include "wolfssl/wolfcrypt/error-crypt.h"
#include "test_vectors/test_vector.h"
#include "app_ecdsa.h"
#include "app_utils.h"
#include "app_config.h"
#include "timer/tmr1.h"

static uint32_t microsecondsToProcess = 0;

static void microsecondIncrement(void)
{
    microsecondsToProcess++;
}

#if defined(ECDSA_SIGNATURE_VERIFICATION)

    static void ECDSA_Verify(ECDSA_TEST_VECTOR *testVector)
    {
        headerInformationPrint(testVector);

        ecc_key keyData;
        int status = WC_FAILURE;
        int result = 0;

        Timer1.TimeoutCallbackRegister(microsecondIncrement);
        microsecondsToProcess = 0;

        benchmarkingStart();
        status = wc_ecc_init(&keyData);

        if(status == 0)
        {
            status = wc_ecc_import_unsigned(
                &keyData, 
                testVector->publicKey, 
                testVector->publicKey + testVector->curveSize,   
                NULL, testVector->curveId
            );
        }

        if(status == 0)
        {
            status = wc_ecc_verify_hash(testVector->signature, 
                    testVector->signatureLength, testVector->hash,
                    testVector->hashLength, &result, &keyData
            );    
        }

        benchmarkingEnd();

        if(status == 0)
        {
            hexArrayPrint("Signature ", testVector->signature, testVector->signatureLength);
            if(result)
            {
                (void) printf(GREEN"\r\n\r\n wolfCrypt ECDSA Signature Verify Success"RESET_COLOR);
            }
            else
            {
                (void) printf(RED"\r\n\r\n wolfCrypt ECDSA Signature Verify Failure"RESET_COLOR);
            }
            benchmarkingDataPrint(microsecondsToProcess);
        }
        else
        {
            printf("\r\nError Occured: %s", wc_GetErrorString(status));
        }
    }

    #ifdef ECDSA_P256
        extern ECDSA_TEST_VECTOR ecdsa_p256_sig_ver_vector;
        static void ECDSAP256_Verify(void)
        {
            ECDSA_Verify(&ecdsa_p256_sig_ver_vector);   
        }
    #endif    

    #ifdef ECDSA_P384
        extern ECDSA_TEST_VECTOR ecdsa_p384_sig_ver_vector;
        static void ECDSAP384_Verify(void)
        {
            ECDSA_Verify(&ecdsa_p384_sig_ver_vector);   
        }
    #endif    

    void ECDSA_VerifyExample(void)
    {
        #ifdef ECDSA_P256
            ECDSAP256_Verify();
        #endif
        #ifdef ECDSA_P384
            ECDSAP384_Verify();
        #endif
    }
#endif