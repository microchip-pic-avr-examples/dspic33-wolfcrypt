<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33A PQC LMS (Leighton-Micali Hash-Based Signatures) Verification

## Summary

This MPLAB® X project demonstrates LMS signature verification by using wolfCrypt APIs and the pre-compiled Crypto Accelerator Module (CAM) Hardware Driver.

## Software Used

- dsPIC33AK-MP_DFP v1.2.135
- MPLAB® X IDE **v6.30** (https://www.microchip.com/mplabx)
- MPLAB® XC-DSC Compiler **v3.30** (https://www.microchip.com/xcdsc)

## Hardware Used

- dsPIC33AK512MPS512 Curiosity GP DIM (https://www.microchip.com/en-us/development-tool/EV80L65A)
- Curiosity Platform Development Board (https://www.microchip.com/EV74H48A)

## Set up

### Hardware Set up

1. Insert the dsPIC33AK512MPS512 DIM into the DIM J1 slot on the Curiosity Platform Development Board.
2. Connect the board from the J24 USB-C PKoB4 (PICKit™ On-Board 4) to the computer.

    <img src="../../images/hardware_setup.jpg" height="400" alt="Hardware Setup"/>

### Project Set Up

#### wolfCrypt Source

The wolfCrypt files in this project use wolfssl v5.8.4-stable release with edits to support the dsPIC33A device.

#### Edits that were required for dsPIC33A support

1. `crypto\wolfssl\wolfssl\wolfcrypt\sha256.h`

    Line 179: Insert a new `#elif defined` check for the dsPIC33A_CAM_ENABLE macro. This will add the Common Crypto hash context within the struct.
    ``` 
    #elif defined(dsPIC33A_CAM_ENABLE)
        st_Crypto_Hash_Sha_Ctx context;
    ```

    Line 160: Insert a new `#ifdef` dsPIC33A_CAM_ENABLE check. This will add the include for the Common Crypto hash header file.
    ``` 
    #ifdef dsPIC33A_CAM_ENABLE
        #include "wolfssl/wolfcrypt/port/microchip/dspic33a/common_crypto/crypto_hash.h"
    #endif
    ```

2. `crypto\wolfssl\wolfcrypt\src\sha256.c`

    Line 220: Add a `!defined` check for the dsPIC33A_CAM_ENABLE macro. This will disable the software hash functions.
    ``` 
    Before:
    !defined(WOLFSSL_RENESAS_RX64_HASH) 

    After:
    !defined(WOLFSSL_RENESAS_RX64_HASH) && !defined(dsPIC33A_CAM_ENABLE)
    ```

    Line 1132: Replace line with new `#elif defined` check for the dsPIC33A_CAM_ENABLE macro. This will disable the software hash functions.
    ```
    #elif defined(dsPIC33A_CAM_ENABLE)

        /* implemented in wolfcrypt/src/port/microchip/dspic33a/dspic33a_cam_hash.c */

    #else
    ```

    2. `crypto\wolfssl\wolfcrypt\src\wc_lms_impl.c`

    Line 518: Replace the specified code. This will initialize the Common Crypto hash context within the wc_lms_hash_sha256_192 function.
    ``` 
    Before:
    #else
        ret = wc_Sha256Update(sha256, data, len);
        if (ret == 0) {
            ret = wc_Sha256Final(sha256, output);
            if (ret == 0) {
                XMEMCPY(hash, output, WC_SHA256_192_DIGEST_SIZE);
            }
        }
    #endif /* !WC_LMS_FULL_HASH */

    After:
    #else
        ret = wc_InitSha256_ex(sha256, NULL, 0);

        if(ret == 0) {
            ret = wc_Sha256Update(sha256, data, len);
        }

        if (ret == 0) {
            ret = wc_Sha256Final(sha256, output);
            if (ret == 0) {
                XMEMCPY(hash, output, WC_SHA256_192_DIGEST_SIZE);
            }
        }
    #endif /* !WC_LMS_FULL_HASH */
    ```

    Line 267: Replace the specified code. This will initialize the Common Crypto hash context within the wc_lms_hash function.
    ``` 
    Before:
    #else
        ret = wc_Sha256Update(sha256, data, len);
        if (ret == 0) {
            ret = wc_Sha256Final(sha256, hash);
        }
    #endif /* !WC_LMS_FULL_HASH */

    After:
    #else
        ret = wc_InitSha256_ex(sha256, NULL, 0);

        if(ret == 0) {
            ret = wc_Sha256Update(sha256, data, len);
        }

        if (ret == 0) {
            ret = wc_Sha256Final(sha256, hash);
        }
    #endif /* !WC_LMS_FULL_HASH */
    ```

## Running the Demo

### Demo Configuration

The `app_config.h` file is used to configure the project. Due to device memory constraints, use caution when enabling more than one configuration at a time. The following options are available:

| Hash             | Width         | Height               |
| ----             | -----         | ------               |
|SHA-256_192 (N24) | 1, 2, 4, or 8 | 5, 10, 15, 20, or 25 |
|SHA-256 (N32)     | 1, 2, 4, or 8 | 5, 10, 15, 20, or 25 |

#### Input Vector Alignment
The input vector signatures are aligned to 4-byte boundaries. This is required to function. Alternatively, the wolfCrypt library can be configured to handle memory alignment. More information can be found within the FAQ README at the top level of this directory.

### Demo Output

The device will process the configured test vector using the wolfCrypt `wc_LmsKey_Verify` API. The test parameters and verification status will be printed to the terminal listening at a baud rate of 115200.

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found at the root folder of dspic33-wolfCrypt repo. 

## Benchmarking for LMS Verification

### Verification Time
|Hash|Width|Height|Verfication time (Seconds)|
|---|---|---|---|
|SHA-256_192 (N24)|8|25|0.049388|
|SHA-256 (N32)|8|25|0.057216|

### Verification Size
|Hash|Width|Height|Flash (bytes)|RAM Static (bytes)|RAM Stack (bytes)|
|---|---|---|---|---|---|
|SHA-256_192 (N24)|8|25|13,124|292|1660|
|SHA-256 (N32)|8|25|13,796|292|1660|