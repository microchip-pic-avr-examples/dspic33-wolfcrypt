/**************************************************************************
  Crypto Framework Library Source

  Company:
    Microchip Technology Inc.

  File Name:
    crypto_digisign_cam06048_wrapper.c

  Summary:
    Crypto Framework Library wrapper file for the digital signature in the
    hardware cryptographic library.

  Description:
    This source file contains the wrapper interface to access the hardware
    cryptographic library in Microchip microcontrollers for digital signature.
**************************************************************************/

//DOM-IGNORE-BEGIN
/*
Copyright (C) 2025, Microchip Technology Inc., and its subsidiaries. All rights reserved.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
*/
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <xc.h>
#include "crypto/drivers/wrapper/crypto_digisign_cam06048_wrapper.h"
#include "crypto/drivers/library/cam_ecdsa.h"

static volatile crypto_DigiSignState_E currentState = CRYPTO_PROCESS_COMPLETE;

// *****************************************************************************
// *****************************************************************************
// Section: File Scope Function Implementations
// *****************************************************************************
// *****************************************************************************

static crypto_DigiSign_Status_E lCrypto_DigSign_Ecdsa_Hw_Status(void)
{    
    crypto_DigiSign_Status_E status = CRYPTO_DIGISIGN_ERROR_FAIL;

    return status;
}

crypto_operation_Id Crypto_DigSign_Ecdsa_Operation(void)
{    
    crypto_operation_Id output = UNKNOWN_OPERATION;

    return output;
}

// *****************************************************************************
// *****************************************************************************
// Section: DigSign Common Interface Implementation
// *****************************************************************************
// *****************************************************************************

crypto_DigiSign_Status_E Crypto_DigiSign_Ecdsa_Hw_Sign(uint8_t *inputHash,
    uint32_t hashLen, uint8_t *outSig, uint32_t sigLen, uint8_t *privKey,
    uint32_t privKeyLen, crypto_EccCurveType_E eccCurveType_En)
{
    return CRYPTO_DIGISIGN_ERROR_FAIL;
}

crypto_DigiSign_Status_E Crypto_DigiSign_Ecdsa_Hw_Verify(uint8_t *inputHash,
    uint32_t hashLen, uint8_t *inputSig, uint32_t sigLen, uint8_t *pubKey,
    uint32_t pubKeyLen, int8_t *hashVerifyStatus,
    crypto_EccCurveType_E eccCurveType_En)
{
    return CRYPTO_DIGISIGN_ERROR_FAIL;
}

// *****************************************************************************
// *****************************************************************************
// Section: DigSign Non-Blocking Interface Implementation
// *****************************************************************************
// ********************************* ********************************************

crypto_DigiSign_Status_E Crypto_DigiSign_Ecdsa_Hw_Sign_Start(uint8_t *inputHash, 
    uint32_t hashLen, uint8_t *privKey, uint32_t privKeyLen, 
    crypto_EccCurveType_E eccCurveType_En)
{
    return CRYPTO_DIGISIGN_ERROR_FAIL;
}

crypto_DigiSign_Status_E Crypto_DigiSign_Ecdsa_Hw_Verify_Start(uint8_t * inputHash, uint32_t hashLen, 
    uint8_t *inputSig, uint32_t sigLen, uint8_t *pubKey, uint32_t pubKeyLen, 
    crypto_EccCurveType_E eccCurveType_En)
{
  
    return CRYPTO_DIGISIGN_ERROR_FAIL;
    
}

crypto_DigiSign_Status_E Crypto_DigiSign_Ecdsa_Hw_Sign_GetStatus(void)
{
    return lCrypto_DigSign_Ecdsa_Hw_Status();
}

crypto_DigiSign_Status_E Crypto_DigiSign_Ecdsa_Hw_Verify_GetStatus(void)
{
    return lCrypto_DigSign_Ecdsa_Hw_Status();
}

crypto_DigiSign_Status_E Crypto_DigiSign_Ecdsa_Hw_Sign_GetResult(uint8_t *outputSig, uint32_t sigLen)
{
    return CRYPTO_DIGISIGN_ERROR_FAIL;
}

crypto_DigiSign_Status_E Crypto_DigiSign_Ecdsa_Hw_Verify_GetResult(void)
{
    return CRYPTO_DIGISIGN_ERROR_FAIL;
}

crypto_DigiSignState_E Crypto_DigiSign_Ecdsa_Hw_GetState(void)
{
    return CRYPTO_DIGISIGN_ERROR_FAIL;
}

void Crypto_DigiSign_Ecdsa_Hw_SetState(crypto_DigiSignState_E state)
{
    currentState = CRYPTO_DIGISIGN_ERROR_FAIL;
}

crypto_DigiSign_Status_E Crypto_DigiSign_Ecdsa_Hw_ClearMemory_GetStatus(void)
{
    return CRYPTO_DIGISIGN_ERROR_FAIL;
}

void Crypto_DigiSign_Ecdsa_Hw_ClearMemory(void)
{

}
