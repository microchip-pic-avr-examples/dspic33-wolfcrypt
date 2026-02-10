<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33C ML-DSA (Module-Lattice-Based Digital Signature) Verification

## Summary

This MPLAB® X project demonstrates ML-DSA Verify using dilithium wolfCrypt APIs to verify an input signature and message.

## Software Used 
- dsPIC33CK-MP_DFP **1.15.423**
- MPLAB® X IDE **v6.30** (https://www.microchip.com/mplabx)
- MPLAB® XC-DSC Compiler **v3.21** (https://www.microchip.com/xcdsc)

## Hardware Used

- dsPIC33CK Curiosity Development Board (https://www.microchip.com/dm330030)
- dsPIC33CK256MP508 High-Performance DSC (https://www.microchip.com/dspic33ck256mp508)

## Set Up

### Hardware Set up

1. Connect the board to the computer using a USB cable, connecting to the Serial port.

    <img src="../../../images/hardware_setup_curiosity.jpg" height="400" alt="Hardware Setup"/>

### Project Set Up

#### wolfCrypt Source

The wolfCrypt files in this project use wolfssl v5.8.4-stable release with edits to support the dsPIC33C device.

##### Edits that were required for dsPIC33C support
1. `crypto\wolfssl\wolfssl\wolfcrypt\dilithium.h`

    Line 212: Cast the 1 literal to be of type sword32.
    ``` c
    //Before:
    #define DILITHIUM_GAMMA1_17             (1 << 17)

    //After:
    #define DILITHIUM_GAMMA1_17             ((sword32)1 << 17)
    ```
2. `crypto\wolfssl\wolfssl\wolfcrypt\dilithium.h`

    Line 2129 Cast the 1 literal to be of type sword32.
    ``` c
    //Before:
    #define DILITHIUM_GAMMA1_19             (1 << 19)

    //After:
    #define DILITHIUM_GAMMA1_19             ((sword32)1 << 19)
    ```

3. `crypto\wolfssl\wolfcrypt\src\dilithium.c`

    Line 9527 Cast the 1 literal to be of type sword32.
    ```c
    //Before:
    hi = (1 << params->gamma1_bits) - params->beta;

    //After:
    hi = ((sword32)1 << params->gamma1_bits) - params->beta;
    ```

4. `crypto\wolfssl\wolfcrypt\src\dilithium.c`

    Line 1886 through 1897 fix casts to sword32.
    ```c 
    //Before:
    z[i+0] = DILITHIUM_GAMMA1_17 -
                ( s[ 0]       | ((sword32)(s[ 1] << 8) |
                (sword32)(s[ 2] & 0x03) << 16));
    z[i+1] = DILITHIUM_GAMMA1_17 -
                ((s[ 2] >> 2) | ((sword32)(s[ 3] << 6) |
                (sword32)(s[ 4] & 0x0f) << 14));
    z[i+2] = DILITHIUM_GAMMA1_17 -
                ((s[ 4] >> 4) | ((sword32)(s[ 5] << 4) |
                (sword32)(s[ 6] & 0x3f) << 12));
    z[i+3] = DILITHIUM_GAMMA1_17 -
                ((s[ 6] >> 6) | ((sword32)(s[ 7] << 2) |
                (sword32)(s[ 8]       ) << 10));

    //After:
    z[i+0] = DILITHIUM_GAMMA1_17 - ((sword32)s[ 0]        | (((sword32)s[ 1] << 8) |
                                   ((sword32)s[ 2] & 0x03) << 16));
    z[i+1] = DILITHIUM_GAMMA1_17 - (((sword32)s[ 2] >> 2) | (((sword32)s[ 3] << 6) |
                                   ((sword32)s[ 4] & 0x0f) << 14));           
    z[i+2] = DILITHIUM_GAMMA1_17 - (((sword32)s[ 4] >> 4) | (((sword32)s[ 5] << 4) |
                                   ((sword32)s[ 6] & 0x3f) << 12));           
    z[i+3] = DILITHIUM_GAMMA1_17 - (((sword32)s[ 6] >> 6) | (((sword32)s[ 7] << 2) |
                                   ((sword32)s[ 8]       ) << 10));                    
    ```

5. `crypto\wolfssl\wolfcrypt\src\dilithium.c`

    Line 2008 through 2015 fix casts to sword32.
    ```c 
    //Before:
    z[i+0] = DILITHIUM_GAMMA1_19 - ( s[0]       | ((sword32)s[1] << 8) |
                                    ((sword32)(s[2] & 0x0f) << 16));
    z[i+1] = DILITHIUM_GAMMA1_19 - ((s[2] >> 4) | ((sword32)s[3] << 4) |
                                    ((sword32)(s[4]       ) << 12));
    z[i+2] = DILITHIUM_GAMMA1_19 - ( s[5]       | ((sword32)s[6] << 8) |
                                    ((sword32)(s[7] & 0x0f) << 16));
    z[i+3] = DILITHIUM_GAMMA1_19 - ((s[7] >> 4) | ((sword32)s[8] << 4) |
                                    ((sword32)(s[9]       ) << 12));

    //After:
    z[i+0] = DILITHIUM_GAMMA1_19 - ((sword32)s[0]        | ((sword32)s[1] << 8) |
                                   (((sword32)s[2] & (sword32)0x0f) << 16));
    z[i+1] = DILITHIUM_GAMMA1_19 - (((sword32)s[2] >> 4) | ((sword32)s[3] << 4) |
                                   ((sword32)s[4] << 12));
    z[i+2] = DILITHIUM_GAMMA1_19 - ((sword32)s[5]       |  ((sword32)s[6] << 8) |
                                   (((sword32)s[7] & (sword32)0x0f) << 16));
    z[i+3] = DILITHIUM_GAMMA1_19 - (((sword32)s[7] >> 4) | ((sword32)s[8] << 4) |
                                   ((sword32)s[9] << 12));
    ```

## Running the Demo

### Demo Configuration

The `app_config.h` file is used to configure the project. Due to device memory constraints, use caution when enabling more than one configuration at a time. The following options using Dilithium are available:

- ML_DSA_44 
- ML_DSA_65
- ML_DSA_87

### Demo Output

The device will process the configured test vector using the wolfCrypt `wc_MlDsaKey_Verify` API. The test parameters and verification status will be printed to the terminal listening at a baud rate of 115200.

## Input Data Usage
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
    
## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found at the root folder of dspic33-wolfCrypt repo. 

### Benchmarking for ML-DSA Verification

#### Verification Time
|ML-DSA type |Verfication time (Seconds)|
|------------|------|
|Dilithium 44|0.2602|
|Dilithium 65|0.4250|
|Dilithium 87|0.6349|

#### Verification Size
|ML-DSA type|Message Size (bytes)|Signature Size (bytes)|Key Size (bytes)|Flash (bytes)|RAM Static (bytes)|RAM Stack (bytes)|
|---|---|---|---|---|---|---|
|Dilithium 44|4,553|2,420|1,312|18,047|58|964|
|Dilithium 65|7,465|3,309|1,952|20,268|58|964|
|Dilithium 87|4,616|4,627|2,592|19,822|58|964|
