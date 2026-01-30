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

#include "common_crypto/crypto_hash.h"
#include "wolfssl/wolfssl/wolfcrypt/error-crypt.h"
#include "wolfssl/wolfssl/wolfcrypt/sha256.h"
#include "wolfssl/wolfssl/wolfcrypt/types.h"

#if defined(dsPIC33A_CAM_ENABLE)

int wc_InitSha256_ex(wc_Sha256* sha256, void* heap, int devId)
{
    int status = BAD_FUNC_ARG;

    if (sha256 != NULL)
    {
        (void) heap;
        (void) devId;

        status = Crypto_Hash_Sha_Init(&sha256->context, CRYPTO_HASH_SHA2_256, CRYPTO_HANDLER_HW_INTERNAL, 1);

        if(status != CRYPTO_HASH_SUCCESS)
        {
            status = WC_HW_E;
        }
    }

    return status;
}

int wc_Sha256Update(wc_Sha256* sha256, const byte* data, word32 len)
{
    int status = BAD_FUNC_ARG;

    if ((sha256 != NULL) && (data != NULL) && (len > 0U))
    {
        byte* localData = (byte*) data;

        status = Crypto_Hash_Sha_Update(&sha256->context, localData, len);

        if(status != CRYPTO_HASH_SUCCESS)
        {
            status = WC_HW_E;
        }
    }

    return status;
}

int wc_Sha256Final(wc_Sha256* sha256, byte* hash)
{
    int status = BAD_FUNC_ARG;

    if ((sha256 != NULL) && (hash != NULL))
    {
        status = Crypto_Hash_Sha_Final(&sha256->context, hash);

        if(status == CRYPTO_HASH_SUCCESS)
        {
            status = wc_InitSha256_ex(sha256, sha256->heap, INVALID_DEVID); /* reset state */

            if(status != CRYPTO_HASH_SUCCESS)
            {
                status = WC_HW_E;
            }
        }
        else
        {
            status = WC_HW_E;
        }
    }

    return status;
}

#endif