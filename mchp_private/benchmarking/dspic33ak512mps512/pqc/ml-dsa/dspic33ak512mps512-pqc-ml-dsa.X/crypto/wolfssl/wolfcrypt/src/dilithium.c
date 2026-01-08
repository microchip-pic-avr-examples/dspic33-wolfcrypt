/*
 * This file is intentionally cleared. To obtain the original source, refer to the wolfSSL GitHub and copy the contents to this file.
 *
 * The source for this file can be found at the following link: https://github.com/wolfSSL/wolfssl/blob/v5.8.2-stable/wolfcrypt/src/dilithium.c
 */

#include <wolfssl/wolfcrypt/dilithium.h>

int wc_dilithium_import_public(const byte* in, word32 inLen, dilithium_key* key)
{
    return WC_FAILURE;
}

int wc_dilithium_verify_msg(const byte* sig, word32 sigLen, const byte* msg,
    word32 msgLen, int* res, dilithium_key* key)
{
    return WC_FAILURE;
}

int wc_dilithium_set_level(dilithium_key* key, byte level)
{
    return WC_FAILURE;
}
