/*
? [2026] Microchip Technology Inc. and its subsidiaries.

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

/* cppcheck-suppress misra-c2012-21.6
*
*  (Rule 21.6) REQUIRED: The standard library input/output functions shall not be used
*
*  Reasoning: This demo uses printf to print out information to a terminal.
*/
#include <stdio.h>
#include "wolfssl/wolfcrypt/cmac.h"
#include "wolfssl/wolfcrypt/error-crypt.h"
#include "test_vectors/test_vector.h"
#include "app_mac_cmac.h"
#include "app_utils.h"
#include "app_config.h"
#include "timer/tmr1.h"

static uint32_t microsecondsToProcess = 0;
static void microsecondIncrement(void)
{
    microsecondsToProcess++;
}

static void MAC_CmacGenerate(MAC_TEST_VECTOR *testVector)
{
    headerInformationPrint(testVector);
    
    Timer1.TimeoutCallbackRegister(microsecondIncrement);
    microsecondsToProcess = 0;
    
    /* cppcheck-suppress misra-c2012-18.8
    *
    *  (Rule 18.8) REQUIRED: Variable-length array types shall not be used
    *
    *  Reasoning: The result array size must be the same as the input data array size.
    *                Using a variable-length array allows the demo test vectors to be
    *                adjusted independent of the application code.
    */
    uint8_t macResult[testVector->macSize];
    Cmac cmac;
    int status = WC_FAILURE;
    
    benchmarkingStart();
}

void MAC_CmacExample(void)
{
#ifdef AES_CMAC
    #ifdef AES_128
    AES128_CmacGenerate();
    #endif

    #ifdef AES_192
    AES192_CmacGenerate();
    #endif

    #ifdef AES_256
    AES256_CmacGenerate();
    #endif
#endif
}