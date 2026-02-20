<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33A Module-Lattice-Based Digital Signature (ML-DSA) Verification Example Application

## Description

This MPLAB® X project demonstrates ML-DSA Verify using dilithium wolfCrypt APIs on a dsPIC33AK512MPS512 device.

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ak512mps512-ml-dsa.X/crypto/wolfssl/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt).

## Project Setup

See the [dsPIC33AK512MPS512 README](../README.md) for software tools and hardware setup.

### wolfCrypt Source

The wolfCrypt files in this project use wolfssl v5.8.4-stable release to support the dsPIC33A device.

### Project Configuration

The `app_config.h` file is used to configure the project. Due to device memory constraints, use caution when enabling more than one configuration at a time. The following options using Dilithium are available:

- ML_DSA_44 
- ML_DSA_65
- ML_DSA_87

## Running the Application

### Application Output

The resulting operations are then printed to the terminal using UART with the following settings:

| Setting           | Value  
| -------           | -----  |
| Baudrate          | 115200 |
| Parity            | None   |
| Data Size         | 8      |
| Stop Bits         | 1      |
| Flow Control Mode | None   |

### Input Data Usage
The test vectors in this demo come from the NIST defined public keys, messages and signature values.
- These values are raw data inputs with no encoding. 

If another tool is used to generate a signature it may encode the message by default following [FIPS-204](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.204.pdf) (Algorithm 2 Step 10)
- If this is the case the following wolfcrypt verification api can be used to handle signatures generated with FIPS-204 encoding:

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

## Benchmarking

### Performance Benchmarking
|ML-DSA type |Verification time (Seconds)|
|------------|------|
|Dilithium 44|0.027528|
|Dilithium 65|0.046473|
|Dilithium 87|0.069983|

### Memory Size Benchmarking
|ML-DSA type|Message Size (bytes)|Flash (bytes)|RAM Static (bytes)|RAM Stack (bytes)|
|---|---|---|---|---|
|Dilithium 44|4,553|2,420|1,312|36,988|56|1,192|
|Dilithium 65|7,465|3,309|1,952|41,432|56|1,192|
|Dilithium 87|4,616|4,627|2,592|40,536|56|1,192|