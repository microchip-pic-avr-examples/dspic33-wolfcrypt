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
#include "test_vectors/sha2_test_vectors.h"
#include "app_config.h"
#include "user_settings.h"

#ifdef SHA2_256_ENABLE

static const uint8_t sha2_256_16_bytes_message[] = {
    0x5C, 0x6D, 0xC4, 0xE5, 0x0D, 0xB0, 0xC4, 0xB6,
    0x5B, 0xD0, 0x8F, 0xBC, 0x66, 0xE9, 0xAC, 0xEA
};

static const uint8_t sha2_256_16_bytes_digest[] = {
    0x76, 0x22, 0xA7, 0x9B, 0x48, 0x92, 0xC9, 0xEC,
    0x02, 0x1B, 0x66, 0xA8, 0x4C, 0xDC, 0x41, 0xEE,
    0xB4, 0xEE, 0xA9, 0xAE, 0x80, 0xF2, 0x12, 0x4F,
    0x4F, 0x8F, 0xD9, 0x11, 0x53, 0xAA, 0x5B, 0x95
};

static const TEST_VECTOR sha2_256_16_bytes_vector = {
    SHA2_256_ALGO,
    "16 Byte Message",
    sha2_256_16_bytes_message,
    sizeof(sha2_256_16_bytes_message),
    sha2_256_16_bytes_digest,
    sizeof(sha2_256_16_bytes_digest),
};

static const TEST_VECTOR sha2_256_test_vectors[] = {
    sha2_256_16_bytes_vector,
};

const TEST_VECTOR* SHA2_256_TestVectorsGet(void)
{
    return sha2_256_test_vectors;
}

word32 SHA2_256_VectorCountGet(void)
{
    return sizeof(sha2_256_test_vectors) / sizeof(sha2_256_test_vectors[0]);
}

#endif

