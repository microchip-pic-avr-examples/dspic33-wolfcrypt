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
    #define WOLFSSL_OLD_OID_SUM       // Use smaller OID sum values for 16-bit device
    #define NO_FILESYSTEM             // Specify device does not use a filesystem
    #define WOLFSSL_IGNORE_FILE_WARN  // Disable warning regarding inlined misc.c functions
    #define WC_NO_RNG                 // Disable RNG related APIs
    #define WOLFCRYPT_ONLY            // Specify using wolfCrypt APIs only

    // wolfCrypt AES Configuration Options
    #define HAVE_AES_ECB              // Enable AES ECB APIs
    #define HAVE_AES_CBC              // Enable AES CBC APIs

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