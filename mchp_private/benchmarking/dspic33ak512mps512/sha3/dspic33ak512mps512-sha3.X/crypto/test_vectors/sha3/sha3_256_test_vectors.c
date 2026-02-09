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

#ifdef SHA3_256_ENABLE

static const uint8_t sha3_256_16_bytes_message[] __attribute__((space(prog))) = {
    0xB3, 0x83, 0x38, 0x85, 0xE8, 0x33, 0x2B, 0x3C,
    0x62, 0x4D, 0xD0, 0x07, 0x95, 0xEC, 0xF9, 0x46
};

static const uint8_t sha3_256_16_bytes_digest[] __attribute__((space(prog))) = {
    0x3D, 0xD0, 0xE8, 0x20, 0xDC, 0x42, 0x3D, 0xBC,
    0xBA, 0xE4, 0xF5, 0x1E, 0x4A, 0x95, 0xEC, 0xC5,
    0xBD, 0xD2, 0xDE, 0x66, 0xF5, 0xBC, 0x37, 0xD7,
    0xDE, 0x51, 0x1E, 0x04, 0xB2, 0x44, 0xA2, 0xA9
};

static const TEST_VECTOR sha3_256_16_bytes_vector = {
    SHA3_256_ALGO,
    sha3_256_16_bytes_message,
    sizeof(sha3_256_16_bytes_message),
    sha3_256_16_bytes_digest,
    sizeof(sha3_256_16_bytes_digest),
};

static const TEST_VECTOR sha3_256_test_vectors[] = {
    sha3_256_16_bytes_vector,
};

const TEST_VECTOR* SHA3_256_TestVectorsGet(void)
{
    return sha3_256_test_vectors;
}

word32 SHA3_256_VectorCountGet(void)
{
    return sizeof(sha3_256_test_vectors) / sizeof(sha3_256_test_vectors[0]);
}

#endif

