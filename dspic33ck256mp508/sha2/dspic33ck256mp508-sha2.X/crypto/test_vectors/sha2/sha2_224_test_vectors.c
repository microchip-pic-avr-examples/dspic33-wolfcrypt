/*
Copyright (C) [2025] Microchip Technology Inc. and its subsidiaries.

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

#include <stdint.h>
#include "test_vectors/test_vector.h"
#include "test_vectors/sha2_test_vectors.h"
#include "app_config.h"
#include "user_settings.h"

#ifdef SHA2_224_ENABLE

static const uint8_t sha2_224_16_bytes_message[] = {
    0xFA, 0xDE, 0xE3, 0xDC, 0x64, 0x16, 0x42, 0xC3,
    0x26, 0x82, 0x3A, 0xF3, 0x2F, 0xDE, 0x38, 0x62
};

static const uint8_t sha2_224_16_bytes_digest[] = {
    0xEE, 0x4E, 0x3F, 0xD0, 0x01, 0xDC, 0x75, 0xE0,
    0xD2, 0x7A, 0x90, 0x48, 0xFC, 0x8A, 0x2E, 0x76,
    0x9D, 0x93, 0x55, 0xA7, 0x7A, 0x30, 0x8F, 0x6E,
    0xF1, 0xD5, 0xC8, 0x5A
};

static const TEST_VECTOR sha2_224_16_bytes_vector = {
    SHA2_224_ALGO,
    "16 Byte Message",
    sha2_224_16_bytes_message,
    sizeof(sha2_224_16_bytes_message),
    sha2_224_16_bytes_digest,
    sizeof(sha2_224_16_bytes_digest),
};

static const TEST_VECTOR sha2_224_test_vectors[] = {
    sha2_224_16_bytes_vector,
};

const TEST_VECTOR* SHA2_224_TestVectorsGet(void)
{
    return sha2_224_test_vectors;
}

word32 SHA2_224_VectorCountGet(void)
{
    return sizeof(sha2_224_test_vectors) / sizeof(sha2_224_test_vectors[0]);
}

#endif
