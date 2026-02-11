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

#include <stdint.h>
#include "test_vectors/test_vector.h"
#include "test_vectors/sha3_test_vectors.h"
#include "app_config.h"
#include "user_settings.h"

#ifdef SHA3_224_ENABLE

static const uint8_t sha3_224_16_bytes_message[] __attribute__((space(prog))) = {
    0x22, 0xB6, 0xB9, 0x5E, 0xB8, 0x31, 0x63, 0xD1,
    0xFB, 0xD0, 0x3F, 0x2B, 0xB1, 0x6C, 0xCB, 0xAA
};

static const uint8_t sha3_224_16_bytes_digest[] __attribute__((space(prog))) = {
    0x81, 0xBC, 0x69, 0x95, 0xDD, 0xA7, 0xC9, 0xE0,
    0x86, 0x6F, 0x0A, 0xD9, 0xBB, 0x81, 0xCE, 0x64,
    0x6B, 0x54, 0x33, 0x40, 0x0A, 0x0C, 0xAB, 0x10,
    0x46, 0x2D, 0xD3, 0x29
};

static const TEST_VECTOR sha3_224_16_bytes_vector = {
    SHA3_224_ALGO,
    sha3_224_16_bytes_message,
    sizeof(sha3_224_16_bytes_message),
    sha3_224_16_bytes_digest,
    sizeof(sha3_224_16_bytes_digest),
};

static const TEST_VECTOR sha3_224_test_vectors[] = {
    sha3_224_16_bytes_vector,
};

const TEST_VECTOR* SHA3_224_TestVectorsGet(void)
{
    return sha3_224_test_vectors;
}

word32 SHA3_224_VectorCountGet(void)
{
    return sizeof(sha3_224_test_vectors) / sizeof(sha3_224_test_vectors[0]);
}

#endif
