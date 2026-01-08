/*
 * This file is intentionally cleared. To obtain the original source, refer to the wolfSSL GitHub and copy the contents to this file.
 *
 * The source for this file can be found at the following link: https://github.com/wolfSSL/wolfssl/blob/v5.8.2-stable/wolfssl/wolfcrypt/dilithium.h
 */

#ifndef WOLF_CRYPT_DILITHIUM_H
#define WOLF_CRYPT_DILITHIUM_H

typedef unsigned char  byte;
typedef unsigned short word16;
typedef unsigned int   word32;

typedef struct wc_dilithium_params {
    byte level;
    word16 pkSz;
    word16 sigSz;
} wc_dilithium_params;

struct dilithium_key {
    const byte* p;
    const wc_dilithium_params* params;
};

#define WC_FAILURE -1;

typedef struct dilithium_key dilithium_key;
 
#define WC_ML_DSA_44            2
#define WC_ML_DSA_65            3
#define WC_ML_DSA_87            5

int wc_dilithium_verify_msg(const byte* sig, word32 sigLen, const byte* msg,
    word32 msgLen, int* res, dilithium_key* key);

int wc_dilithium_set_level(dilithium_key* key, byte level);

int wc_dilithium_import_public(const byte* in, word32 inLen, dilithium_key* key);

#define wc_MlDsaKey_SetParams(key, id)                          \
    wc_dilithium_set_level(key, id)
#define wc_MlDsaKey_ImportPubRaw(key, in, inLen)                \
    wc_dilithium_import_public(in, inLen, key)
#define wc_MlDsaKey_Verify(key, sig, sigSz, msg, msgSz, res)    \
    wc_dilithium_verify_msg(sig, sigSz, msg, msgSz, res, key)


#ifdef __cplusplus
    }    /* extern "C" */
#endif

#endif
