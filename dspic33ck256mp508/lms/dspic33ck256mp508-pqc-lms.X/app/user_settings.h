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

#ifndef USER_SETTINGS_H
#define USER_SETTINGS_H

#ifdef	__cplusplus
extern "C" {
#endif

    // wolfCrypt Configuration Options
    #define NO_MD5
    #define NO_SHA
    #define NO_MD4
    #define NO_DSA
    #define NO_OLD_TLS
    #define NO_ASN
    #define WOLFSSL_OLD_OID_SUM
    #define WC_NO_HARDEN
    #define NO_FILESYSTEM
    #define WOLFSSL_IGNORE_FILE_WARN

    // wolfCrypt LMS Configuration Options
    #define WOLFSSL_HAVE_LMS
    #define WOLFSSL_WC_LMS
    #define WOLFSSL_LMS_SHA256_192
    #define WOLFSSL_LMS_VERIFY_ONLY
    #define WOLFSSL_WC_LMS_SMALL

    // dsPIC33C Support
    #ifdef __dsPIC33C__
        #define WC_16BIT_CPU
        #define SIZEOF_LONG_LONG 4
        #define SINGLE_THREADED
        #define WOLFSSL_GENERAL_ALIGNMENT 0
        #define WOLFSSL_USE_ALIGN
        #define FAST_ROTATE
        #define MICROCHIP_DSPIC33C_LMS_HASH
    #endif

#ifdef	__cplusplus
}
#endif

#endif /* USER_SETTINGS_H */