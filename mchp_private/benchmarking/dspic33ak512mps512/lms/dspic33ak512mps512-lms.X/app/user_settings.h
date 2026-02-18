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

#ifndef _USER_SETTINGS_H
#define _USER_SETTINGS_H

    // wolfCrypt Configuration Options
    #define NO_MD5                      // Disable MD5 related APIs
    #define NO_SHA                      // Disable SHA related APIs
    #define NO_MD4                      // Disable MD4 related APIs
    #define NO_DSA                      // Disable DSA related APIs
    #define NO_OLD_TLS                  // Disable settings for TLS protocol versions less than 1.2
    #define NO_ASN                      // Disable ASN related APIs
    #define WC_NO_HARDEN                // Disable security countermeasures in wolfCrypt related to protecting against side-channel attacks
    #define NO_FILESYSTEM               // Specify device does not use a filesystem
    #define WOLFSSL_IGNORE_FILE_WARN    // Disable warning regarding inlined misc.c functions

    // wolfCrypt LMS Configuration Options
    #define WOLFSSL_HAVE_LMS            // Enable LMS specific APIs
    #define WOLFSSL_WC_LMS              // Enable LMS WC specific APIs
    #define WOLFSSL_LMS_SHA256_192      // Enable SHA-256_192 (N24) processing for LMS operations
    #define WOLFSSL_LMS_VERIFY_ONLY     // Enable LMS verify only
    #define WOLFSSL_WC_LMS_SMALL        // Reduce the code size
    #define WC_LMS_FULL_HASH            // Configure LMS to process the full hash during operation

    // dsPIC33A Support
    #ifdef __dsPIC33A__
        #define SIZEOF_LONG_LONG 8      // Define long long value size as 8 bytes
        #define SINGLE_THREADED         // Specify device is single threaded
        #define dsPIC33A_CAM_ENABLE     // Enable CAM Hardware usage with the dsPIC33A
    #endif

#endif
