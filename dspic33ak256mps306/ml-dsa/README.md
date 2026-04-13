<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33A Module-Lattice-Based Digital Signature (ML-DSA) Verification Example Application

## Description

This MPLAB® X project demonstrates ML-DSA Verify using wolfCrypt APIs on a dsPIC33AK256MPS306 device utilizing SHAKE128 and SHAKE256 hardware acceleration.

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ak256MPS306-ml-dsa.X/crypto/wolfssl/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt).

## Project Setup

See the [dsPIC33AK256MPS306 README](../README.md) for software tools and hardware setup.

**The following files and folders are required to enable CAM hardware usage within wolfCrypt**
- `crypto/dspic33a_cam_hash.h`
- `crypto/dspic33a_cam_hash.c`
- `crypto/common_crypto/**`
- `crypto/drivers/**`

### wolfCrypt Source Edits to support dsPIC33A

1. `crypto\wolfssl\wolfssl\wolfcrypt\sha3.h`

    Line 118: Insert a new `#ifdef` check for the dsPIC33A_CAM_ENABLE macro. This will add the Common Crypto hash include.
    ``` 
    #ifdef dsPIC33A_CAM_ENABLE
        #include "common_crypto/crypto_hash.h"
    #endif
    ```

    Line 138: Insert a new `#if defined` check for the dsPIC33A_CAM_ENABLE macro. This will add the Common Crypto hash context and other supporting buffers within the struct.
    ``` 
    #if defined(dsPIC33A_CAM_ENABLE)
        st_Crypto_Hash_Shake_Ctx context;
        byte*  squeezeBuffer;       // Pre-computed squeeze output
        word32 squeezeBufferLength; // Total bytes available in squeezeBuffer
        word32 squeezeBufferOffset; // Current read offset into squeezeBuffer
        byte   absorbData[68];      // Max seed: 66 bytes, rounded up
        word32 absorbDataLength;    // Length of stored absorb data
        byte   absorbReady;         // 1 if Absorb was called, awaiting squeeze
        word32 digestLength;
    #endif
    ```

2. `crypto\wolfssl\wolfcrypt\src\sha3.c`

    Line 25-26: Add `&& !defined(dsPIC33A_CAM_ENABLE)` to the specified `#if defined` checks. This will allow for the disabling and enabling of the wolfcrypt software APIs.
    ``` 
    Before:
    #if defined(WOLFSSL_SHA3) && !defined(WOLFSSL_XILINX_CRYPT) && \
    !defined(WOLFSSL_AFALG_XILINX_SHA3)

    After:
    #if defined(WOLFSSL_SHA3) && !defined(WOLFSSL_XILINX_CRYPT) && \
    !defined(WOLFSSL_AFALG_XILINX_SHA3) && !defined(dsPIC33A_CAM_ENABLE)
    ```


3. `crypto\wolfssl\wolfcrypt\src\dilithium.c`

    Line 454: Insert the following before `ret = wc_InitShake256(shake256, NULL, INVALID_DEVID);` is called in order to pass the digest length into the Common crypto APIs
    ```
    #ifdef dsPIC33A_CAM_ENABLE
    shake256->digestLength = hashLen;
    #endif` 
    ```

    Line 581: Insert the following before `ret = wc_InitShake256(shake256, NULL, INVALID_DEVID);` is called in order to pass the digest length into the Common crypto APIs
    ```
    #ifdef dsPIC33A_CAM_ENABLE
    shake256->digestLength = hashLen;
    #endif` 
    ```

### Input Vector FIPS-204

Openssl is used to generate a public key, private key and signature following [FIPS-204](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.204.pdf)

The following wolfCrypt verification API is used to handle signature verification with FIPS-204 encoding:

    ```c
    int wc_dilithium_verify_ctx_msg(
        const byte* sig, 
        word32 sigLen,
        const byte* ctx, // Set to NULL (unless additional encoding is required)
        word32 ctxLen,   // Set to 0 (or length of the ctx)
        const byte* msg, 
        word32 msgLen, 
        int* res,
        dilithium_key* key
    );
    ```

### Project Configuration

**The ML-DSA project requres specific project configurations within MPLAB® X.** To check these configurations right click the project and select "Properties".

Under the XC-DSC subsection the following must be configured in order to get ML-DSA to build and run:
- Isolate each function in a section: `enabled`
- Removed unused sections: `enabled`
- Define common macros
    - `WOLFSSL_USER_SETTINGS`
    - `GENERIC_TARGET_CAM_06048`
    - `ENABLE_CAM_06048_SHAKE`

The `app_config.h` file is used to configure the project. Due to device memory constraints, use caution when enabling more than one configuration at a time. The following options using Dilithium are available:

- ML_DSA_44 
- ML_DSA_65
- ML_DSA_87

This project also allows for swapping the CAM Hardware drivers SHAKE implementation with the wolfCrypt software implementation. 
- Within the `user_settings.h` file on line : `57` commenting out `#define dsPIC33A_CAM_ENABLE` will disable the CAM hardware Driver usage and re-enable the wolfCrypt software implementation:

## Running the Application

Open the project in MPLAB® X IDE. Build the project and program the device.

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
The test vectors used for this benchmarking data is generated using Openssl to generate a public key, private key and signature following [FIPS-204](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.204.pdf)

### Performance Benchmarking
Software + Hardware (CAM 06048) takes at least 75% less time than Software alone. 

Note: The larger the data being verified, the larger the benefit with Software + Hardware (CAM 06048).

#### ML-DSA Verification Time

| ML-DSA Type   | SW + HW (CAM 06048) (s)  | SW (s)     |
| ------------- | ------------------------ | ---------- |
| Dilithium 44  | 0.004853                 | 0.017728   |
| Dilithium 65  | 0.007473                 | 0.028071   |
| Dilithium 87  | 0.011683                 | 0.046378   |

### Memory Size Benchmarking

| ML-DSA Type  | Message Size (bytes) | Signature Size (bytes) | Key Size (bytes)  | Flash (bytes) | RAM Static (bytes)  | RAM Stack (bytes) |
| ------------ | -------------------- | ---------------------- | ----------------- | ------------- | ------------------- | ----------------- |
| Dilithium 44 | 3200                 | 2420                   | 1312              | 24,636        | 2,718               | 13,200            |
| Dilithium 65 | 3200                 | 3309                   | 1952              | 26,168        | 2,718               | 13,200            |
| Dilithium 87 | 3200                 | 4627                   | 2592              | 28,124        | 2,718               | 13,200            |