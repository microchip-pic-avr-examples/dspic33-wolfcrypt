/*
© [2025] Microchip Technology Inc. and its subsidiaries.

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
#include "wolfssl/wolfcrypt/ecc.h"
#include "wolfssl/wolfcrypt/error-crypt.h"
#include "app/app_config.h"
#include "crypto/test_vectors/test_vector.h"

ecc_key keyData __attribute__((space(prog)));
static void ECDSA_Verify(ECDSA_TEST_VECTOR *testVector)
{
    int status = WC_FAILURE;
    int result = 0;

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
}

#ifdef ECDSA_P256
    extern ECDSA_TEST_VECTOR ecdsa_p256_sig_ver_vector;
#endif    

#ifdef ECDSA_P384
    extern ECDSA_TEST_VECTOR ecdsa_p384_sig_ver_vector;
#endif  
    
/*
    Main application
*/
int main(void)
{
    SYSTEM_Initialize();
    #ifdef ECDSA_P256
        ECDSA_Verify(&ecdsa_p256_sig_ver_vector);   
    #endif    

    #ifdef ECDSA_P384
        ECDSA_Verify(&ecdsa_p384_sig_ver_vector);   
    #endif  
    
    while(1)
    {
    }
}