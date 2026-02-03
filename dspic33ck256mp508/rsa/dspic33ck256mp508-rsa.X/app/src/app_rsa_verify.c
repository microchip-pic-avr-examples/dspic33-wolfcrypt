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
#include "wolfssl/wolfcrypt/sha256.h"
#include "wolfssl/wolfcrypt/sp_int.h"
#include "wolfssl/wolfcrypt/rsa.h"
#include "wolfssl/wolfcrypt/error-crypt.h"
#include "test_vectors/test_vector.h"
#include "app_rsa_verify.h"
#include "app_utils.h"
#include "app_config.h"
#include "timer/tmr1.h"

#if defined(RSA_SIGNATURE_VERIFICATION) && defined(RSA_PKCS_PADDING)

#define ASN1_ENCODING_SIZE   (19U)
#define SHA256_ENCODED_SIZE  (WC_SHA256_DIGEST_SIZE + ASN1_ENCODING_SIZE)

static uint32_t microsecondsToProcess = 0;
static void microsecondIncrement(void)
{
    microsecondsToProcess++;
}

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

static void RSA_PkcsVerify(RSA_TEST_VECTOR *testVector)
{
    int status = WC_FAILURE;
    wc_Sha256 sha256;
    RsaKey rsaKey;

    /* cppcheck-suppress misra-c2012-18.8
    *
    *  (Rule 18.8) REQUIRED: Variable-length array types shall not be used
    *
    *  Reasoning: The result array size must be the same as the input signature array size.
    *                Using a variable-length array allows the demo test vectors to be
    *                adjusted independent of the application code.
    */
    byte decryptedSignature[testVector->signatureSize];
    int decryptedSignatureSize = -1;
    byte encodedSignature[51] = {
        0x30, 0x31, 0x30, 0x0D, 0x06, 0x09, 0x60, 0x86,
        0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05,
        0x00, 0x04, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00
    };

    headerInformationPrint(testVector);

    Timer1.TimeoutCallbackRegister(microsecondIncrement);
    microsecondsToProcess = 0;

    benchmarkingStart();

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
        decryptedSignatureSize = wc_RsaSSL_Verify(testVector->signature, testVector->signatureSize,
                decryptedSignature, SHA256_ENCODED_SIZE, &rsaKey);
    }

    benchmarkingEnd();

    // If there is no error during processing, the result length is returned.
    // Otherwise, the wc_RsaSSL_Verify API returns an error code.
    if(decryptedSignatureSize != SHA256_ENCODED_SIZE)
    {
        status = decryptedSignatureSize;
    }

    if(status == 0)
    {
        resultVerify(encodedSignature, decryptedSignature, SHA256_ENCODED_SIZE);
    }
    else
    {
        (void) printf(RED"\r\n wolfCrypt RSA - Error Code: %d"RESET_COLOR, status);
    }

    benchmarkingDataPrint(microsecondsToProcess);
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

#endif