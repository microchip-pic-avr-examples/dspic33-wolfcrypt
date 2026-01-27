/*
© [2025] Microchip Technology Inc. and its subsidiaries.

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

#ifndef APP_UTILS_H
#define	APP_UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "test_vectors/test_vector.h"
    
#define RESET_COLOR "\x1B""[0m"
#define RED "\x1B""[1;31m"
#define GREEN "\x1B""[1;32m"
#define YELLOW "\x1B""[1;33m"
#define BLUE "\x1B""[1;34m"
#define MAG "\x1B""[1;35m"
#define CYAN "\x1B""[1;36m"

void hexArrayPrint(const char* label, uint8_t* data, uint32_t size);

bool arrayEqualityCheck(const uint8_t *a, const uint8_t *b, size_t size);

void benchmarkingDataPrint(int ticksToProcess);

void benchmarkingStart(void);

void benchmarkingEnd(int* ticksToProcess);

void headerInformationPrint(LMS_TEST_VECTOR *testVector);

void parametersPrint(LMS_TEST_VECTOR *testVector);
#ifdef	__cplusplus
}
#endif

#endif	/* APP_UTILS_H */

