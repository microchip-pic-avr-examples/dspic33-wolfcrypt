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
#include "test_vectors/shake_test_vectors.h"
#include "app_config.h"
#include "user_settings.h"

#ifdef SHAKE128_ENABLE

static const uint8_t shake128_16_bytes_message[] = {
    0x34, 0x55, 0xAC, 0x86, 0xC8, 0xC7, 0x4E, 0x90,
    0x58, 0x77, 0x1F, 0x72, 0x09, 0x6B, 0xC0, 0x14
};

static const uint8_t shake128_16_bytes_digest[] = {
    0x62, 0xCD, 0xCA, 0x1D, 0x3A, 0x2E, 0x8B, 0x65,
    0x42, 0x3F, 0x89, 0xA2, 0xE2, 0x1B, 0x42, 0x33
};

static const TEST_VECTOR shake128_16_bytes_vector = {
    SHAKE128_ALGO,
    "16 Byte Message",
    shake128_16_bytes_message,
    sizeof(shake128_16_bytes_message),
    shake128_16_bytes_digest,
    sizeof(shake128_16_bytes_digest),
};

static const TEST_VECTOR shake128_test_vectors[] = {
    shake128_16_bytes_vector,
};

const TEST_VECTOR* SHAKE128_TestVectorsGet(void)
{
    return shake128_test_vectors;
}

word32 SHAKE128_VectorCountGet(void)
{
    return sizeof(shake128_test_vectors) / sizeof(shake128_test_vectors[0]);
}

#endif