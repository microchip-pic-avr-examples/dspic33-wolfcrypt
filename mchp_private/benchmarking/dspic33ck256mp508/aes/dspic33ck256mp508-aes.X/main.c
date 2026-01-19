/*
© [2025] Microchip Technology Inc. and its subsidiaries.

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
#include "app/app_config.h"
#include "wolfssl/wolfcrypt/aes.h"

/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();

    #ifdef AES_ECB
        #ifdef AES_ENCRYPT
            wc_AesInit((Aes*) NULL, NULL, 0);

            wc_AesSetKey((Aes*) NULL, (const byte*) NULL, 0, (const byte*) NULL, AES_ENCRYPTION);

            wc_AesEcbEncrypt((Aes*) NULL, (byte*) NULL, (const byte*) NULL, 0);
        #endif

        #ifdef AES_DECRYPT
            wc_AesInit((Aes*) NULL, NULL, 0);

            wc_AesSetKey((Aes*) NULL, (const byte*) NULL, 0, (const byte*) NULL, AES_DECRYPTION);

            wc_AesEcbDecrypt((Aes*) NULL, (byte*) NULL, (const byte*) NULL, 0);
        #endif
    #endif

    #ifdef AES_CBC
        #ifdef AES_ENCRYPT
            wc_AesInit((Aes*) NULL, NULL, 0);

            wc_AesSetKey((Aes*) NULL, (const byte*) NULL, 0, (const byte*) NULL, AES_ENCRYPTION);

            wc_AesCbcEncrypt((Aes*) NULL, (byte*) NULL, (const byte*) NULL, 0);
        #endif

        #ifdef AES_DECRYPT
            wc_AesInit((Aes*) NULL, NULL, 0);

            wc_AesSetKey((Aes*) NULL, (const byte*) NULL, 0, (const byte*) NULL, AES_DECRYPTION);

            wc_AesCbcDecrypt((Aes*) NULL, (byte*) NULL, (const byte*) NULL, 0);
        #endif
    #endif

    while(1)
    {
    }
}