/*
Copyright (C) [2025] Microchip Technology Inc. and its subsidiaries.

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
#include "app/app_sha2.h"
#include "app/app_config.h"

/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();

    #ifdef SHA2_224_ENABLE
    SHA2_224_Digest();
    #endif

    #ifdef SHA2_256_ENABLE
    SHA2_256_Digest();
    #endif

    #ifdef SHA2_384_ENABLE
    SHA2_384_Digest();
    #endif

    #ifdef SHA2_512_ENABLE
    SHA2_512_Digest();
    #endif

    #if !(defined(SHA2_224_ENABLE)       \
            || defined(SHA2_256_ENABLE)  \
            || defined(SHA2_384_ENABLE)  \
            || defined(SHA2_512_ENABLE))

    #error "Please enable an algorithm within the app_config.h file."

    #endif

    while(1)
    {
    }
}