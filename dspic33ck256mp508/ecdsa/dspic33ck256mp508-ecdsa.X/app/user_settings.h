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

#ifndef WOLFCRYPT_USER_SETTINGS_H
#define WOLFCRYPT_USER_SETTINGS_H

#ifdef	__cplusplus
extern "C" {
#endif

    // wolfCrypt Configuration Options
    #define NO_MD4                    // Disable MD4 related APIs
    #define NO_MD5                    // Disable MD5 related APIs
    #define NO_SHA                    // Disable SHA1 related APIs
    #define NO_DSA                    // Disable DSA related APIs
    #define NO_RSA                    // Disable RSA related APIs
    #define NO_DH                     // Disable DH related APIs
    #define NO_AES                    // Disable AES related APIs
    #define NO_ASN                    // Disable ASN related APIs
    #define NO_DES3                   // Disable DES3 related APIs
    #define NO_64BIT                  // Disable 64-bit data types
    #define NO_FILESYSTEM             // Specify device does not use a filesystem
    #define WOLFSSL_NO_MALLOC         // Disable usage of dynamic memory allocation
    #define WOLFSSL_OLD_OID_SUM       // Use smaller OID sum values for 16-bit device
    #define WOLFSSL_IGNORE_FILE_WARN  // Disable warning regarding inlined misc.c functions
    #define WOLFCRYPT_ONLY            // Specify using wolfCrypt APIs only
    #define WOLF_C89                  // Specify strcmp function types
    #define WOLF_CRYPTO_CB            // Enable cryptocb functions for use by ECC APIs


    // wolfCrypt Random Configuration Options
    #define NO_DEV_RANDOM             // Disable the inclusion of wolfCrypt's RNG header file (verify APIs do not need it)

    // wolfCrypt SP Configuration Options
    #define WOLFSSL_SP_SMALL          // Reduce SP library code size
    #define WOLFSSL_SP_LOW_MEM        // Reduce memory usage of SP algorithms
    #define WOLFSSL_SP_NO_DYN_STACK   // Dynamic arrays instead of dynamic stack usage

    // wolfCrypt ECDSA Configuration Options
    #define HAVE_ECC_VERIFY           // Enable ECC verify
    #define HAVE_ECC                  // Enable ECC curves
    #define HAVE_ECC384               // Ensures ECC P384 is available
    #define ECC_TIMING_RESISTANT      // Required for ECC operations

    // dsPIC33C Support
    #ifdef __dsPIC33C__
        #define WC_16BIT_CPU          // Specify 16-bit integer sizes
        #define SIZEOF_LONG_LONG 4    // Define long long value size as 4 bytes
        #define SINGLE_THREADED       // Specify device is single threaded
    #endif

#ifdef	__cplusplus
}
#endif

#endif /* WOLFCRYPT_USER_SETTINGS_H */