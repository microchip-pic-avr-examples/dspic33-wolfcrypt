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

    // wolfCrypt Configuration Options
    #define NO_MD5                          // Disable MD5 related APIs
    #define NO_SHA                          // Disable SHA related APIs
    #define NO_SHA256                       // Disable SHA256 related APIs
    #define NO_MD4                          // Disable MD4 related APIs
    #define NO_RSA                          // Disable RSA related APIs
    #define NO_DSA                          // Disable DSA related APIs
    #define NO_AES                          // Disable AES related APIs
    #define NO_DES3                         // Disable DES3 related APIs
    #define NO_ASN                          // Disable ASN related APIs
    #define WOLFSSL_SHA3                    // Enable SHA3 APIs              
    #define WOLFSSL_SHAKE128                // Enable SHAKE128 APIs
    #define WOLFSSL_SHAKE256                // Enable SHAKE256 APIs
    #define NO_FILESYSTEM                   // Specify device does not use a filesystem
    #define WOLFSSL_IGNORE_FILE_WARN        // Disable warning regarding inlined misc.c functions
    #define WC_NO_HASHDRBG                  // Disable HASH DRBG usage
    #define WC_NO_RNG                       // Disable RNG usage
    #define WOLFSSL_NO_MALLOC               // Disable usage of dynamic memory allocation
    #define WOLFCRYPT_ONLY                  // Specify using wolfCrypt APIs only

    // wolfCrypt ML-KEM Configuration Options
    #define WOLFSSL_HAVE_MLKEM              // Enable ML-KEM specific APIs
    #define WOLFSSL_WC_MLKEM                // Enable ML-KEM specific WC APIs
    #define WOLFSSL_MLKEM_NO_LARGE_CODE     // Reduce the code size and increase speed
    #define WOLFSSL_MLKEM_NO_MAKE_KEY       // Disable key creation APIs
    #define WOLFSSL_MLKEM_NO_ENCAPSULATE    // Disable Encapsulate APIs

    #define WOLFSSL_WC_ML_KEM_512           // Enable ML-KEM-512 security level
    #define WOLFSSL_WC_ML_KEM_768           // Enable ML-KEM-768 security level 
    #define WOLFSSL_WC_ML_KEM_1024          // Enable ML-KEM-1024 security level 

    // dsPIC33A Support
    #ifdef __dsPIC33A__
        #define SIZEOF_LONG_LONG 8          // Define long long value size as 8 bytes
        #define SINGLE_THREADED             // Specify device is single threaded
    #endif

#endif /* WOLFCRYPT_USER_SETTINGS_H */
