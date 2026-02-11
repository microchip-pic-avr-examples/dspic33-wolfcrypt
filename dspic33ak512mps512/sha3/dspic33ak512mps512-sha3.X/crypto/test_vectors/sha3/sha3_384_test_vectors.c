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
#include "app_config.h"
#include "user_settings.h"

#ifdef SHA3_384_ENABLE

static const uint8_t sha3_384_16_bytes_message[] = {
    0x77, 0x79, 0xC4, 0xD9, 0x96, 0x18, 0xB9, 0x56,
    0xC9, 0x2E, 0x51, 0x33, 0x6C, 0xF8, 0x50, 0x62
};

static const uint8_t sha3_384_16_bytes_digest[] = {
    0xA2, 0x4E, 0x84, 0xB8, 0x03, 0x9F, 0x54, 0x28,
    0x28, 0x12, 0x47, 0x55, 0x0E, 0x09, 0x7E, 0x8B,
    0x36, 0x3F, 0x7E, 0xD0, 0xD0, 0xB3, 0x96, 0x2D,
    0x25, 0xE7, 0xF1, 0x77, 0x63, 0x06, 0xD9, 0xB3,
    0x71, 0x9B, 0x8F, 0xE9, 0xAB, 0x0E, 0xDD, 0x38,
    0x26, 0x5F, 0x81, 0x65, 0x23, 0x66, 0x73, 0x8D
};

static const TEST_VECTOR sha3_384_16_bytes_vector = {
    SHA3_384_ALGO,
    "16 Byte Message",
    sha3_384_16_bytes_message,
    sizeof(sha3_384_16_bytes_message),
    sha3_384_16_bytes_digest,
    sizeof(sha3_384_16_bytes_digest),
};

static const TEST_VECTOR sha3_384_test_vectors[] = {
    sha3_384_16_bytes_vector,
};

const TEST_VECTOR* SHA3_384_TestVectorsGet(void)
{
    return sha3_384_test_vectors;
}

word32 SHA3_384_VectorCountGet(void)
{
    return sizeof(sha3_384_test_vectors) / sizeof(sha3_384_test_vectors[0]);
}

#endif


