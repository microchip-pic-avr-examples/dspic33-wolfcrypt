<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33A wolfCrypt Leighton-Micali Hash-Based Signatures (LMS) Verification Example Application

## Description

This MPLAB® X project demonstrates LMS signature verification using wolfCrypt APIs and the pre-compiled Crypto Accelerator Module (CAM) Hardware Driver on a dsPIC33AK512MPS512 device.

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ak512mps512-lms.X/crypto/wolfssl/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt).

## Project Setup

See the [dsPIC33AK512MPS512 README](../README.md) for software tools and hardware setup.

### wolfCrypt Source

The wolfCrypt files in this project use wolfssl v5.8.4-stable release with edits to support the dsPIC33A device.

### Edits that were required for dsPIC33A support

1. `crypto\wolfssl\wolfssl\wolfcrypt\sha256.h`

    Line 179: Insert a new `#elif defined` check for the dsPIC33A_CAM_ENABLE macro. This will add the Common Crypto hash context within the struct.
    ``` 
    #elif defined(dsPIC33A_CAM_ENABLE)
        st_Crypto_Hash_Sha_Ctx context;
    ```

    Line 160: Insert a new `#ifdef` dsPIC33A_CAM_ENABLE check. This will add the include for the Common Crypto hash header file.
    ``` 
    #ifdef dsPIC33A_CAM_ENABLE
        #include "common_crypto/crypto_hash.h"
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

### Project Configuration

The `app_config.h` file is used to configure the project. Due to device memory constraints, use caution when enabling more than one configuration at a time. The following options are available:

| Hash             | Width         | Height               |
| ----             | -----         | ------               |
|SHA-256_192 (N24) | 1, 2, 4, or 8 | 5, 10, 15, 20, or 25 |
|SHA-256 (N32)     | 1, 2, 4, or 8 | 5, 10, 15, 20, or 25 |

## Running the Application

### Input Vector Alignment
The input vector signatures are aligned to 4-byte boundaries. This is required to function. Alternatively, the wolfCrypt library can be configured to handle memory alignment. More information can be found within the FAQ README at the top level of this directory.

### Application Output

The resulting operations are then printed to the terminal using UART with the following settings:

| Setting           | Value  
| -------           | -----  |
| Baudrate          | 115200 |
| Parity            | None   |
| Data Size         | 8      |
| Stop Bits         | 1      |
| Flow Control Mode | None   |

## Benchmarking

### Performance Benchmarking
|Hash|Width|Height|Verification time (Seconds)|
|---|---|---|---|
|SHA-256_192 (N24)|8|25|0.068221|
|SHA-256 (N32)|8|25|0.081927|

### Memory Size Benchmarking
|Hash|Width|Height|Flash (bytes)|RAM Static (bytes)|RAM Stack (bytes)|
|---|---|---|---|---|---|
|SHA-256_192 (N24)|8|25|14,016|78|1,852|
|SHA-256 (N32)|8|25|14,688|78|1,852|