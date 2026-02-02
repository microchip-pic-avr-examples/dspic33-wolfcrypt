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

#ifdef SHA2_512_ENABLE

static const uint8_t sha2_512_16_bytes_message[] __attribute__((space(prog))) = {
    0xD6, 0x64, 0x4A, 0x6D, 0x7E, 0x3E, 0x4F, 0x3B,
    0xEB, 0x66, 0x60, 0x8E, 0x8B, 0xA2, 0xE3, 0x53
};

static const uint8_t sha2_512_16_bytes_digest[] __attribute__((space(prog))) = {
    0x32, 0xC6, 0x5E, 0x4C, 0x30, 0xF6, 0xC4, 0x87,
    0xA6, 0xCE, 0x18, 0x06, 0xE5, 0xA7, 0x71, 0x6A,
    0xA7, 0xE1, 0x34, 0x66, 0x04, 0xE7, 0x92, 0xEC,
    0xF7, 0xF1, 0x42, 0xC7, 0x3A, 0x97, 0x24, 0x07,
    0xCD, 0xAC, 0xB4, 0xCB, 0x80, 0x9C, 0x68, 0xBC,
    0xB9, 0x09, 0x81, 0xD0, 0x1B, 0x4E, 0x42, 0x85,
    0xA5, 0xA4, 0x7C, 0xA7, 0xE7, 0xDF, 0x86, 0x66,
    0xB8, 0x30, 0xBD, 0x12, 0x84, 0x5C, 0x3D, 0x4F
};

static const TEST_VECTOR sha2_512_16_bytes_vector = {
    SHA2_512_ALGO,
    (const byte*)sha2_512_16_bytes_message,
    sizeof(sha2_512_16_bytes_message),
    (const byte*)sha2_512_16_bytes_digest,
    sizeof(sha2_512_16_bytes_digest),
};

static const TEST_VECTOR sha2_512_test_vectors[] = {
    sha2_512_16_bytes_vector,
};

const TEST_VECTOR* SHA2_512_TestVectorsGet(void)
{
    return sha2_512_test_vectors;
}

word32 SHA2_512_VectorCountGet(void)
{
    return sizeof(sha2_512_test_vectors) / sizeof(sha2_512_test_vectors[0]);
}

#endif


