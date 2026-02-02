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

#ifdef SHA2_384_ENABLE

static const uint8_t sha2_384_16_bytes_message[] __attribute__((space(prog))) = {
    0x9D, 0x25, 0x73, 0xCF, 0xDF, 0x1B, 0x91, 0x6D,
    0x5D, 0x69, 0xF4, 0xC5, 0xF7, 0xA7, 0x01, 0x5B
};

static const uint8_t sha2_384_16_bytes_digest[] __attribute__((space(prog))) = {
    0xA1, 0x77, 0x2F, 0xBD, 0xCA, 0x99, 0x37, 0xFF,
    0xFC, 0x07, 0x0F, 0x17, 0x75, 0x40, 0x1A, 0x2B,
    0x84, 0x24, 0x1C, 0xA2, 0x40, 0x9B, 0x8F, 0x2E,
    0x70, 0x56, 0xCE, 0xC0, 0xE5, 0x9C, 0x82, 0x6D,
    0x75, 0xE5, 0x9B, 0x87, 0xB4, 0x5C, 0x5A, 0x8B,
    0x05, 0x4D, 0x62, 0xD0, 0x22, 0x4C, 0xF8, 0x98
};

static const TEST_VECTOR sha2_384_16_bytes_vector = {
    SHA2_384_ALGO,
    (const byte*)sha2_384_16_bytes_message,
    sizeof(sha2_384_16_bytes_message),
    (const byte*)sha2_384_16_bytes_digest,
    sizeof(sha2_384_16_bytes_digest),
};

static const TEST_VECTOR sha2_384_test_vectors[] = {
    sha2_384_16_bytes_vector,
};

const TEST_VECTOR* SHA2_384_TestVectorsGet(void)
{
    return sha2_384_test_vectors;
}

word32 SHA2_384_VectorCountGet(void)
{
    return sizeof(sha2_384_test_vectors) / sizeof(sha2_384_test_vectors[0]);
}

#endif


