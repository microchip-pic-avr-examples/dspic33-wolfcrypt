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

#ifndef SHA3_TEST_VECTORS_H
#define	SHA3_TEST_VECTORS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "wolfssl/wolfcrypt/types.h"

const TEST_VECTOR* SHA3_224_TestVectorsGet(void);

word32 SHA3_224_VectorCountGet(void);

const TEST_VECTOR* SHA3_256_TestVectorsGet(void);

word32 SHA3_256_VectorCountGet(void);

const TEST_VECTOR* SHA3_384_TestVectorsGet(void);

word32 SHA3_384_VectorCountGet(void);

const TEST_VECTOR* SHA3_512_TestVectorsGet(void);

word32 SHA3_512_VectorCountGet(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SHA3_TEST_VECTORS_H */

