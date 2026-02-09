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

#ifdef SHA3_512_ENABLE

static const uint8_t sha3_512_16_bytes_message[] __attribute__((space(prog))) = {
    0xAE, 0x1F, 0xB3, 0x8A, 0xCF, 0x4C, 0xA5, 0x45,
    0xC7, 0x7B, 0xA5, 0xA9, 0x1F, 0xBF, 0x3E, 0xCE
};

static const uint8_t sha3_512_16_bytes_digest[] __attribute__((space(prog))) = {
    0x20, 0x41, 0xB8, 0x11, 0xDD, 0x71, 0x40, 0xFE,
    0xFB, 0xD0, 0x09, 0x97, 0xEC, 0x3F, 0xD1, 0x2C,
    0x5B, 0x7E, 0xC8, 0x1C, 0x7E, 0x65, 0xD0, 0x97,
    0x7E, 0x3C, 0x4F, 0xB4, 0xE8, 0xB1, 0xEC, 0x84,
    0xD0, 0x16, 0x5F, 0xEC, 0xC9, 0x51, 0x58, 0x5A,
    0xC5, 0x88, 0xBA, 0x46, 0xB0, 0xBE, 0xAF, 0x3B,
    0xD8, 0x1A, 0x65, 0xBA, 0xEE, 0xC7, 0xAA, 0xC2,
    0x22, 0x0C, 0xFE, 0x06, 0xD2, 0xBD, 0xA2, 0xAD
};

static const TEST_VECTOR sha3_512_16_bytes_vector = {
    SHA3_512_ALGO,
    sha3_512_16_bytes_message,
    sizeof(sha3_512_16_bytes_message),
    sha3_512_16_bytes_digest,
    sizeof(sha3_512_16_bytes_digest),
};

static const TEST_VECTOR sha3_512_test_vectors[] = {
    sha3_512_16_bytes_vector,
};

const TEST_VECTOR* SHA3_512_TestVectorsGet(void)
{
    return sha3_512_test_vectors;
}

word32 SHA3_512_VectorCountGet(void)
{
    return sizeof(sha3_512_test_vectors) / sizeof(sha3_512_test_vectors[0]);
}

#endif


