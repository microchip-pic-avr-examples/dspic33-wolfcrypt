/*
� [2025] Microchip Technology Inc. and its subsidiaries.

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
#include "app_utils.h"
#include "app_lms.h"
#include "test_vectors/test_vector.h"
#include "wolfssl/wolfcrypt/lms.h"

static void headerInformationPrint(LMS_TEST_VECTOR *testVector)
{
    const char* paddingBefore = "";
    const char* paddingAfter = "";

    if(testVector->lmsKey->params->hash_len == 24)
    {
        paddingAfter = (testVector->lmsKey->params->height == 5) ? "******" : "*****";
    }
    else
    {
        paddingBefore = "**";
        paddingAfter = (testVector->lmsKey->params->height == 5) ? "********" : "*******";
    }

    (void) printf(CYAN"\r\n %s***************** LMS TEST - %s ************%s",
            paddingBefore, testVector->vectorInformation, paddingAfter);
}

static void parametersPrint(LMS_TEST_VECTOR *testVector)
{
    (void) printf("\r\n Parameters:");
    (void) printf("\r\n Levels: %d", testVector->lmsKey->params->levels);
    (void) printf("\r\n Height: %d", testVector->lmsKey->params->height);
    (void) printf("\r\n Width: %d", testVector->lmsKey->params->width);
    (void) printf("\r\n Ls: %d", testVector->lmsKey->params->ls);
    (void) printf("\r\n P: %d", testVector->lmsKey->params->p);
    (void) printf("\r\n LmsType: %d", testVector->lmsKey->params->lmsType);
    (void) printf("\r\n LmOtsType: %d", testVector->lmsKey->params->lmOtsType);
    (void) printf("\r\n Signature Length: %d", testVector->lmsKey->params->sig_len);
    (void) printf("\r\n Hash Length: %d", testVector->lmsKey->params->hash_len);
}

void LMS_Verify(LMS_TEST_VECTOR *testVector)
{
    int ticksToProcess = 0;

    (void) printf(MAG"\r\n\r\n *************************************************************************************");
    headerInformationPrint(testVector);
    (void) printf(MAG"\r\n *************************************************************************************"RESET_COLOR);

    parametersPrint(testVector);

    testVector->lmsKey->state = WC_LMS_STATE_VERIFYONLY;

    benchmarkingStart();

    int status = wc_LmsKey_Verify(testVector->lmsKey, testVector->signature, testVector->signatureLen,
            testVector->message, testVector->messageLen);

    benchmarkingEnd(&ticksToProcess);

    if(status == 0)
    {
        (void) printf(GREEN" \r\n LMS Signature Successfully Verified "RESET_COLOR);
    }
    else
    {
        (void) printf(RED"\r\n wolfCrypt LMS - Error Code: %d"RESET_COLOR, status);
    }

    benchmarkingDataPrint(ticksToProcess);
}