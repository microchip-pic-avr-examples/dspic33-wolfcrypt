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

#include "mcc_generated_files/system/system.h"
#include "app/app_sha3.h"
#include "app/app_shake.h"
#include "app/app_config.h"

/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();

    #ifdef SHA3_224_ENABLE
    SHA3_224_Digest();
    #endif

    #ifdef SHA3_256_ENABLE
    SHA3_256_Digest();
    #endif

    #ifdef SHA3_384_ENABLE
    SHA3_384_Digest();
    #endif

    #ifdef SHA3_512_ENABLE
    SHA3_512_Digest();
    #endif

    #ifdef SHAKE128_ENABLE
    SHAKE128_Digest();
    #endif

    #ifdef SHAKE256_ENABLE
    SHAKE256_Digest();
    #endif

    #if !(defined(SHA3_224_ENABLE) \
        || defined(SHA3_256_ENABLE) \
        || defined(SHA3_384_ENABLE) \
        || defined(SHA3_512_ENABLE) \
        || defined(SHA3_224_ENABLE) \
        || defined(SHAKE128_ENABLE) \
        || defined(SHAKE256_ENABLE))

    #error "Please enable an algorithm within the app_config.h file."

    #endif

    while(1)
    {
    }
}