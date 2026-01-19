/*
? [2025] Microchip Technology Inc. and its subsidiaries.

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
#include "wolfssl/wolfcrypt/aes.h"
#include "wolfssl/wolfcrypt/error-crypt.h"
#include "test_vectors/test_vector.h"
#include "app_aes_ecb.h"
#include "app_utils.h"
#include "app_config.h"
#include "timer/tmr1.h"

#ifdef AES_ECB

static uint32_t microsecondsToProcess = 0;
static void microsecondIncrement(void)
{
    microsecondsToProcess++;
}

#ifdef AES_ENCRYPT

    static void AES_EcbEncrypt(AES_TEST_VECTOR *testVector)
    {
        headerInformationPrint(testVector);

        Timer1.TimeoutCallbackRegister(microsecondIncrement);
        microsecondsToProcess = 0;

        /* cppcheck-suppress misra-c2012-18.8
        *
        *  (Rule 18.8) REQUIRED: Variable-length array types shall not be used
        *
        *  Reasoning: The result array size must be the same as the input data array size.
        *                Using a variable-length array allows the demo test vectors to be
        *                adjusted independent of the application code.
        */
        uint8_t ciphertextResult[testVector->ciphertextSize];
        Aes aes;
        int status = WC_FAILURE;

        benchmarkingStart();

        status = wc_AesInit((Aes*) &aes, NULL, 0);

        if(status == 0)
        {
            status = wc_AesSetKey((Aes*) &aes, testVector->key, testVector->keySize,
                    NULL, testVector->direction);
        }

        if(status == 0)
        {
            status = wc_AesEcbEncrypt((Aes*) &aes, (uint8_t*) &ciphertextResult,
                    testVector->plaintext, testVector->plaintextSize);
        }

        benchmarkingEnd();

        if(status == 0)
        {
            resultVerify(AES_ENCRYPTION, testVector, (uint8_t*) &ciphertextResult);
        }
        else
        {
            (void) printf(RED"\r\n wolfCrypt AES - Error Code: %d"RESET_COLOR, status);
        }

        benchmarkingDataPrint(microsecondsToProcess);
    }

    #ifdef AES_128
    extern AES_TEST_VECTOR aes_128_ecb_encrypt_vector;
    static void AES128_EcbEncrypt(void)
    {
        AES_EcbEncrypt((AES_TEST_VECTOR*) &aes_128_ecb_encrypt_vector);
    }
    #endif

    #ifdef AES_192
    extern AES_TEST_VECTOR aes_192_ecb_encrypt_vector;
    static void AES192_EcbEncrypt(void)
    {
        AES_EcbEncrypt((AES_TEST_VECTOR*) &aes_192_ecb_encrypt_vector);
    }
    #endif

    #ifdef AES_256
    extern AES_TEST_VECTOR aes_256_ecb_encrypt_vector;
    static void AES256_EcbEncrypt(void)
    {
        AES_EcbEncrypt((AES_TEST_VECTOR*) &aes_256_ecb_encrypt_vector);
    }
    #endif

#endif

#ifdef AES_DECRYPT

    static void AES_EcbDecrypt(AES_TEST_VECTOR *testVector)
    {
        headerInformationPrint(testVector);

        Timer1.TimeoutCallbackRegister(microsecondIncrement);
        microsecondsToProcess = 0;

        /* cppcheck-suppress misra-c2012-18.8
        *
        *  (Rule 18.8) REQUIRED: Variable-length array types shall not be used
        *
        *  Reasoning: The result array size must be the same as the input data array size.
        *                Using a variable-length array allows the demo test vectors to be
        *                adjusted independent of the application code.
        */
        uint8_t plaintextResult[testVector->ciphertextSize];
        Aes aes;
        int status = WC_FAILURE;

        benchmarkingStart();

        status = wc_AesInit((Aes*) &aes, NULL, 0);

        if(status == 0)
        {
            status = wc_AesSetKey((Aes*) &aes, testVector->key, testVector->keySize,
                    NULL, testVector->direction);
        }

        if(status == 0)
        {
            status = wc_AesEcbDecrypt((Aes*) &aes, (uint8_t*) &plaintextResult,
                    testVector->ciphertext, testVector->ciphertextSize);
        }

        benchmarkingEnd();

        if(status == 0)
        {
            resultVerify(AES_DECRYPTION, testVector, (uint8_t*) &plaintextResult);
        }
        else
        {
            (void) printf(RED"\r\n wolfCrypt AES - Error Code: %d"RESET_COLOR, status);
        }

        benchmarkingDataPrint(microsecondsToProcess);
    }

    #ifdef AES_128
    extern AES_TEST_VECTOR aes_128_ecb_decrypt_vector;
    static void AES128_EcbDecrypt(void)
    {
        AES_EcbDecrypt((AES_TEST_VECTOR*) &aes_128_ecb_decrypt_vector);
    }
    #endif

    #ifdef AES_192
    extern AES_TEST_VECTOR aes_192_ecb_decrypt_vector;
    static void AES192_EcbDecrypt(void)
    {
        AES_EcbDecrypt((AES_TEST_VECTOR*) &aes_192_ecb_decrypt_vector);
    }
    #endif

    #ifdef AES_256
    extern AES_TEST_VECTOR aes_256_ecb_decrypt_vector;
    static void AES256_EcbDecrypt(void)
    {
        AES_EcbDecrypt((AES_TEST_VECTOR*) &aes_256_ecb_decrypt_vector);
    }
    #endif

#endif

void AES_EcbExample(void)
{
    #ifdef AES_ENCRYPT
        #ifdef AES_128
        AES128_EcbEncrypt();
        #endif

        #ifdef AES_192
        AES192_EcbEncrypt();
        #endif

        #ifdef AES_256
        AES256_EcbEncrypt();
        #endif
    #endif

    #ifdef AES_DECRYPT
        #ifdef AES_128
        AES128_EcbDecrypt();
        #endif

        #ifdef AES_192
        AES192_EcbDecrypt();
        #endif

        #ifdef AES_256
        AES256_EcbDecrypt();
        #endif
    #endif
}

#endif
