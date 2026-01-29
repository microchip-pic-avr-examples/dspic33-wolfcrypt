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
#include "mcc_generated_files/system/system.h"
#include "app/app_config.h"
#include "crypto/wolfssl/wolfssl/wolfcrypt/error-crypt.h"
#include "crypto/wolfssl/wolfssl/wolfcrypt/mlkem.h"
#include "crypto/test_vectors/test_vector.h"

/*
    Main application
*/

    uint8_t sharedSecretResult[32];
    
    static void MLKEM_Decapsulate(ML_KEM_TEST_VECTOR *testVector)
    {
        int status = WC_FAILURE;

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
        MLKEM_Decapsulate(&ml_kem_1024_decapsulate);
    }
    #endif

int main(void)
{
    SYSTEM_Initialize();

    #ifdef MLKEM_512
    MLKEM_512Decapsulate();
    #endif

    #ifdef MLKEM_768
    MLKEM_768Decapsulate();
    #endif

    #ifdef MLKEM_1024
    MLKEM_1024Decapsulate();
    #endif

    while(1)
    {
    }
}