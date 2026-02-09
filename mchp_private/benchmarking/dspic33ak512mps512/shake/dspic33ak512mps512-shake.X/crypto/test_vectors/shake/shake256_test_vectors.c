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

#ifdef SHAKE256_ENABLE

static const uint8_t shake256_16_bytes_message[] __attribute__((space(prog))) = {
    0xF0, 0xF3, 0x91, 0xF0, 0x1B, 0xA4, 0xD5, 0x40,
    0x5C, 0x29, 0xE2, 0x1C, 0x77, 0x13, 0x9C, 0x4C
};

static const uint8_t shake256_16_bytes_digest[] __attribute__((space(prog))) = {
    0xB4, 0x86, 0x69, 0xB2, 0x83, 0x06, 0xDA, 0x22,
    0xAC, 0xDC, 0xE1, 0xE4, 0x9A, 0xEB, 0x18, 0x84,
    0x2F, 0xDF, 0xAF, 0x6A, 0xE7, 0xF9, 0x07, 0x8C,
    0xC4, 0x7F, 0x92, 0xE2, 0x36, 0x8D, 0x05, 0x7C
};

static const TEST_VECTOR shake256_16_bytes_vector = {
    SHAKE256_ALGO,
    shake256_16_bytes_message,
    sizeof(shake256_16_bytes_message),
    shake256_16_bytes_digest,
    sizeof(shake256_16_bytes_digest),
};

TEST_VECTOR shake256_test_vectors[] = {
    shake256_16_bytes_vector,
};

const TEST_VECTOR* SHAKE256_TestVectorsGet(void)
{
    return shake256_test_vectors;
}

word32 SHAKE256_VectorCountGet(void)
{
    return sizeof(shake256_test_vectors) / sizeof(shake256_test_vectors[0]);
}

#endif