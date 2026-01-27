/*
© [2026] Microchip Technology Inc. and its subsidiaries.

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

#include "wolfssl/wolfcrypt/lms.h"
#include "app_lms.h"
#include "app_config.h"
#include "app_lms_sha256.h"

#if defined(LMS_N32) && defined(LMS_WIDTH_1)
    #ifdef LMS_HEIGHT_5
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w1_h5_vector;
    static void LMS_N32W1H5Verify(void)
    {
        wc_LmsKey_SetLmsParm(lms_nspk0_sha256_n32_w1_h5_vector.lmsKey, WC_LMS_PARM_L1_H5_W1);

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w1_h5_vector);
    }
    #endif

    #ifdef LMS_HEIGHT_10
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w1_h10_vector;
    static void LMS_N32W1H10Verify(void)
    {
        // Parameters are hard coded in the vector.

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w1_h10_vector);
    }
    #endif

    #ifdef LMS_HEIGHT_15
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w1_h15_vector;
    static void LMS_N32W1H15Verify(void)
    {
        // Parameters are hard coded in the vector.

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w1_h15_vector);
    }
    #endif

    #ifdef LMS_HEIGHT_20
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w1_h20_vector;
    static void LMS_N32W1H20Verify(void)
    {
        // Parameters are hard coded in the vector.

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w1_h20_vector);
    }
    #endif

    #ifdef LMS_HEIGHT_25
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w1_h25_vector;
    static void LMS_N32W1H25Verify(void)
    {
        // Parameters are hard coded in the vector.

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w1_h25_vector);
    }
    #endif
#endif

#if defined(LMS_N32) && defined(LMS_WIDTH_2)
    #ifdef LMS_HEIGHT_5
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w2_h5_vector;
    static void LMS_N32W2H5Verify(void)
    {
        wc_LmsKey_SetLmsParm(lms_nspk0_sha256_n32_w2_h5_vector.lmsKey, WC_LMS_PARM_L1_H5_W2);

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w2_h5_vector);
    }
    #endif


    #ifdef LMS_HEIGHT_10
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w2_h10_vector;
    static void LMS_N32W2H10Verify(void)
    {
        wc_LmsKey_SetLmsParm(lms_nspk0_sha256_n32_w2_h10_vector.lmsKey, WC_LMS_PARM_L1_H10_W2);

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w2_h10_vector);
    }
    #endif


    #ifdef LMS_HEIGHT_15
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w2_h15_vector;
    static void LMS_N32W2H15Verify(void)
    {
        wc_LmsKey_SetLmsParm(lms_nspk0_sha256_n32_w2_h15_vector.lmsKey, WC_LMS_PARM_L1_H15_W2);

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w2_h15_vector);
    }
    #endif


    #ifdef LMS_HEIGHT_20
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w2_h20_vector;
    static void LMS_N32W2H20Verify(void)
    {
        wc_LmsKey_SetLmsParm(lms_nspk0_sha256_n32_w2_h20_vector.lmsKey, WC_LMS_PARM_L1_H20_W2);

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w2_h20_vector);
    }
    #endif

    #ifdef LMS_HEIGHT_25
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w2_h25_vector;
    static void LMS_N32W2H25Verify(void)
    {
        // Parameters are hard coded in the vector.

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w2_h25_vector);
    }
    #endif
#endif

#if defined(LMS_N32) && defined(LMS_WIDTH_4)
    #ifdef LMS_HEIGHT_5
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w4_h5_vector;
    static void LMS_N32W4H5Verify(void)
    {
        wc_LmsKey_SetLmsParm(lms_nspk0_sha256_n32_w4_h5_vector.lmsKey, WC_LMS_PARM_L1_H5_W4);

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w4_h5_vector);
    }
    #endif

    #ifdef LMS_HEIGHT_10
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w4_h10_vector;
    static void LMS_N32W4H10Verify(void)
    {
        wc_LmsKey_SetLmsParm(lms_nspk0_sha256_n32_w4_h10_vector.lmsKey, WC_LMS_PARM_L1_H10_W4);

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w4_h10_vector);
    }
    #endif

    #ifdef LMS_HEIGHT_15
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w4_h15_vector;
    static void LMS_N32W4H15Verify(void)
    {
        wc_LmsKey_SetLmsParm(lms_nspk0_sha256_n32_w4_h15_vector.lmsKey, WC_LMS_PARM_L1_H15_W4);

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w4_h15_vector);
    }
    #endif

    #ifdef LMS_HEIGHT_20
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w4_h20_vector;
    static void LMS_N32W4H20Verify(void)
    {
        wc_LmsKey_SetLmsParm(lms_nspk0_sha256_n32_w4_h20_vector.lmsKey, WC_LMS_PARM_L1_H20_W4);

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w4_h20_vector);
    }
    #endif

    #ifdef LMS_HEIGHT_25
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w4_h25_vector;
    static void LMS_N32W4H25Verify(void)
    {
        // Parameters are hard coded in the vector.

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w4_h25_vector);
    }
    #endif
#endif

#if defined(LMS_N32) && defined(LMS_WIDTH_8)
    #ifdef LMS_HEIGHT_5
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w8_h5_vector;
    static void LMS_N32W8H5Verify(void)
    {
        wc_LmsKey_SetLmsParm(lms_nspk0_sha256_n32_w8_h5_vector.lmsKey, WC_LMS_PARM_L1_H5_W8);

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w8_h5_vector);
    }
    #endif

    #ifdef LMS_HEIGHT_10
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w8_h10_vector;
    static void LMS_N32W8H10Verify(void)
    {
        wc_LmsKey_SetLmsParm(lms_nspk0_sha256_n32_w8_h10_vector.lmsKey, WC_LMS_PARM_L1_H10_W8);

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w8_h10_vector);
    }
    #endif

    #ifdef LMS_HEIGHT_15
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w8_h15_vector;
    static void LMS_N32W8H15Verify(void)
    {
        wc_LmsKey_SetLmsParm(lms_nspk0_sha256_n32_w8_h15_vector.lmsKey, WC_LMS_PARM_L1_H15_W8);

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w8_h15_vector);
    }
    #endif

    #ifdef LMS_HEIGHT_20
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w8_h20_vector;
    static void LMS_N32W8H20Verify(void)
    {
        wc_LmsKey_SetLmsParm(lms_nspk0_sha256_n32_w8_h20_vector.lmsKey, WC_LMS_PARM_L1_H20_W8);

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w8_h20_vector);
    }
    #endif

    #ifdef LMS_HEIGHT_25
    extern LMS_TEST_VECTOR lms_nspk0_sha256_n32_w8_h25_vector;
    static void LMS_N32W8H25Verify(void)
    {
        // Parameters are hard coded in the vector.

        LMS_Verify((LMS_TEST_VECTOR*) &lms_nspk0_sha256_n32_w8_h25_vector);
    }
    #endif
#endif

void LMS_N32Verify(void)
{
    #if defined(LMS_N32) && defined(LMS_WIDTH_1)
        #ifdef LMS_HEIGHT_5
        LMS_N32W1H5Verify();
        #endif

        #ifdef LMS_HEIGHT_10
        LMS_N32W1H10Verify();
        #endif

        #ifdef LMS_HEIGHT_15
        LMS_N32W1H15Verify();
        #endif

        #ifdef LMS_HEIGHT_20
        LMS_N32W1H20Verify();
        #endif

        #ifdef LMS_HEIGHT_25
        LMS_N32W1H25Verify();
        #endif
    #endif

    #if defined(LMS_N32) && defined(LMS_WIDTH_2)
        #ifdef LMS_HEIGHT_5
        LMS_N32W2H5Verify();
        #endif

        #ifdef LMS_HEIGHT_10
        LMS_N32W2H10Verify();
        #endif

        #ifdef LMS_HEIGHT_15
        LMS_N32W2H15Verify();
        #endif

        #ifdef LMS_HEIGHT_20
        LMS_N32W2H20Verify();
        #endif

        #ifdef LMS_HEIGHT_25
        LMS_N32W2H25Verify();
        #endif
    #endif

    #if defined(LMS_N32) && defined(LMS_WIDTH_4)
        #ifdef LMS_HEIGHT_5
        LMS_N32W4H5Verify();
        #endif

        #ifdef LMS_HEIGHT_10
        LMS_N32W4H10Verify();
        #endif

        #ifdef LMS_HEIGHT_15
        LMS_N32W4H15Verify();
        #endif

        #ifdef LMS_HEIGHT_20
        LMS_N32W4H20Verify();
        #endif

        #ifdef LMS_HEIGHT_25
        LMS_N32W4H25Verify();
        #endif
    #endif

    #if defined(LMS_N32) && defined(LMS_WIDTH_8)
        #ifdef LMS_HEIGHT_5
        LMS_N32W8H5Verify();
        #endif

        #ifdef LMS_HEIGHT_10
        LMS_N32W8H10Verify();
        #endif

        #ifdef LMS_HEIGHT_15
        LMS_N32W8H15Verify();
        #endif

        #ifdef LMS_HEIGHT_20
        LMS_N32W8H20Verify();
        #endif

        #ifdef LMS_HEIGHT_25
        LMS_N32W8H25Verify();
        #endif
    #endif
}