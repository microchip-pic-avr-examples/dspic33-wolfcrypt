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
    #define NO_MD5
    #define NO_SHA
    #define NO_SHA256
    #define NO_MD4
    #define NO_RSA
    #define NO_DSA
    #define NO_DES3
    #define NO_ASN
    #define WOLFSSL_SHA3
    #define WOLFSSL_SHAKE128
    #define WOLFSSL_SHAKE256
    #define NO_FILESYSTEM
    #define WOLFSSL_IGNORE_FILE_WARN
    #define WC_NO_HASHDRBG
    #define WC_NO_RNG
    #define WOLFSSL_NO_MALLOC
    #define WOLFCRYPT_ONLY

    // wolfCrypt MAC Configuration Options
    #define WOLFSSL_CMAC              // Enable AES CMAC APIs
    #define WOLFSSL_AES_DIRECT        // Enable AES-related operations

    // dsPIC33C Support
    #ifdef __dsPIC33C__
        #define WC_16BIT_CPU          // Specify 16-bit integer sizes
        #define SIZEOF_LONG_LONG 4    // Define long long value size as 4 bytes
        #define SINGLE_THREADED       // Specify device is single threaded
    #endif

#ifdef	__cplusplus
}
#endif

#endif /* USER_SETTINGS_H */