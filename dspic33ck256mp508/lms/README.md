<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33C wolfCrypt Leighton-Micali Hash-Based Signatures (LMS) Verification Example Application

## Description

This MPLAB® X project demonstrates LMS processing by using wolfCrypt APIs on a dsPIC33CK256MP508 device.
    
## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ck256mp508-aes.X/crypto/wolfssl/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt).

## Project Setup

See the [dsPIC33CK256MP508 README](../README.md) for software tools and hardware setup.

### wolfCrypt Source

The wolfCrypt files in this project use wolfssl v5.8.4-stable release with edits to support the dsPIC33C device.

### Edits that were required for dsPIC33C support

1. `crypto\wolfssl\wolfcrypt\src\sha256.c`

    Line 1863: Call the dsPIC33C assembly hash routine. 
    ```
    Before:
    ret = XTRANSFORM(sha256, data);

    After:
    #ifdef MICROCHIP_DSPIC33C_LMS_HASH
        dsPIC33C_SHA256_ProcessBlock(sha256, data);
        ret = 0;
    #else
        ret = XTRANSFORM(sha256, data);
    #endif
    ```

    Line 1843: Add an extern for the dsPIC33C hash assembly routine. This block will go below the WOLFSSL_HAVE_LMS and !WOLFSSL_LMS_FULL_HASH checks and above the "One block will be used from data..." comment.
    ```
    #if defined(MICROCHIP_DSPIC33C_LMS_HASH)
        extern void dsPIC33C_SHA256_ProcessBlock(wc_Sha256* sha256, const byte* data);
    #endif
    ```

### Project Configuration

The `app_config.h` file is used to configure the project. Due to device memory constraints, use caution when enabling more than one configuration at a time. The following options are available:

| Hash             | Width         | Height               |
| ----             | -----         | ------               |
|SHA-256_192 (N24) | 1, 2, 4, or 8 | 5, 10, 15, 20, or 25 |
|SHA-256 (N32)     | 1, 2, 4, or 8 | 5, 10, 15, 20, or 25 |

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

## Benchmarking

### Performance Benchmarking
|Hash|Width|Height|Verification time (Seconds)|
|---|---|---|---|
|SHA-256_192 (N24)|8|25|1.005986|
|SHA-256 (N32)|8|25|1.203449|

### Memory Size Benchmarking
|Hash|Width|Height|Flash (bytes)|RAM Static (bytes)|RAM Stack (bytes)|
|---|---|---|---|---|---|
|SHA-256_192 (N24)|8|25|4,761|798|1,442|
|SHA-256 (N32)|8|25|5,097|798|1,442|