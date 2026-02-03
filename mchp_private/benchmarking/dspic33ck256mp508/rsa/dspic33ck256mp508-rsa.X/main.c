/*
© [2026] Microchip Technology Inc. and its subsidiaries.

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
#include "wolfssl/wolfcrypt/sha256.h"
#include "wolfssl/wolfcrypt/sp_int.h"
#include "wolfssl/wolfcrypt/rsa.h"
#include "crypto/test_vectors/test_vector.h"
#include "app_config.h"

/*
    Main application
*/

#define ASN1_ENCODING_SIZE   (19U)
#define SHA256_ENCODED_SIZE  (WC_SHA256_DIGEST_SIZE + ASN1_ENCODING_SIZE)
#define MAX_SIGNATURE_SIZE 384

static int RSA_EncodedSignatureGet(RSA_TEST_VECTOR *testVector, wc_Sha256* sha256,
        byte* encodedSignature)
{
    int status = WC_FAILURE;

    status = wc_InitSha256(sha256);

    if (status == 0)
    {
        status = wc_Sha256Update(sha256, testVector->message, testVector->messageSize);
    }

    if (status == 0)
    {
        status = wc_Sha256Final(sha256, &encodedSignature[ASN1_ENCODING_SIZE]);
    }

    return status;
}

byte decryptedSignature[MAX_SIGNATURE_SIZE] __attribute__((space(prog)));

byte encodedSignature[51] __attribute__((space(prog))) = {
    0x30, 0x31, 0x30, 0x0D, 0x06, 0x09, 0x60, 0x86,
    0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05,
    0x00, 0x04, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00
};

wc_Sha256 sha256 __attribute__((space(prog)));

RsaKey rsaKey __attribute__((space(prog)));

static void RSA_PkcsVerify(RSA_TEST_VECTOR *testVector)
{
    int status = WC_FAILURE;

    status = RSA_EncodedSignatureGet(testVector, &sha256, encodedSignature);

    if (status == 0)
    {
        status = wc_InitRsaKey(&rsaKey, NULL);
    }

    if (status == 0)
    {
        status = mp_read_unsigned_bin(&rsaKey.n, testVector->n, testVector->nSize);
    }

    if (status == 0)
    {
        status = mp_set_int(&rsaKey.e, *testVector->e);
    }

    if (status == 0)
    {
        wc_RsaSSL_Verify(testVector->signature, testVector->signatureSize,
                decryptedSignature, SHA256_ENCODED_SIZE, &rsaKey);
    }
}

#ifdef RSA_3072
extern RSA_TEST_VECTOR rsa_3072_pkcs_sig_ver_vector;
static void RSA3072_PkcsVerify(void)
{
    RSA_PkcsVerify(&rsa_3072_pkcs_sig_ver_vector);
}
#endif

void RSA_PkcsVerifyExample(void)
{
    #ifdef RSA_3072
    RSA3072_PkcsVerify();
    #endif
}

int main(void)
{
    SYSTEM_Initialize();

    #ifdef RSA_SIGNATURE_VERIFICATION

        #ifdef RSA_PKCS_PADDING

            RSA_PkcsVerifyExample();

        #endif

    #endif

    while(1)
    {
    }
}