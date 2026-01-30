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


#include <stdio.h>
#include "app_config.h"
#include "test_vectors/test_vector.h"
#include <wolfssl/wolfcrypt/dilithium.h>
#include <wolfssl/wolfcrypt/error-crypt.h>

dilithium_key key __attribute__((space(prog)));
static void MLDSA_Verify(ML_DSA_SIG_VER_TEST_VECTOR* vector, byte level)
{
    int status = 0;
    int error = WC_FAILURE;

    wc_MlDsaKey_SetParams(&key, level);
    wc_MlDsaKey_ImportPubRaw(&key, vector->publicKey, vector->publicKeyLength);  

    error = wc_MlDsaKey_Verify(
            &key,
            (const byte*)vector->signature,
            vector->signatureSize,
            (const byte*) vector->message,
            vector->messageSize,
            &status
        );
}

#ifdef MLDSA_44
extern ML_DSA_SIG_VER_TEST_VECTOR ml_dsa_dilithium_44;
#endif

#ifdef MLDSA_65
extern ML_DSA_SIG_VER_TEST_VECTOR ml_dsa_dilithium_65;
#endif

#ifdef MLDSA_87
extern ML_DSA_SIG_VER_TEST_VECTOR ml_dsa_dilithium_87;
#endif

int main(void)
{
    #ifdef MLDSA_44
    MLDSA_Verify(&ml_dsa_dilithium_44, WC_ML_DSA_44);
    #endif

    #ifdef MLDSA_65
    MLDSA_Verify(&ml_dsa_dilithium_65, WC_ML_DSA_65);
    #endif

    #ifdef MLDSA_87
    MLDSA_Verify(&ml_dsa_dilithium_87, WC_ML_DSA_87);
    #endif
    
    return 0;
}