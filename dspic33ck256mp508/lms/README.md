<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33C PQC LMS (Leighton-Micali Hash-Based Signatures) Verification

## Summary

This MPLAB® X project demonstrates LMS processing by using wolfCrypt APIs and an optimized assembly hash routine.

## Software Used 
- dsPIC33CK-MP_DFP **1.15.423**
- MPLAB® X IDE **v6.30** (https://www.microchip.com/mplabx)
- MPLAB® XC-DSC Compiler **v3.30**(https://www.microchip.com/xcdsc)

## Hardware Used

- dsPIC33CK Curiosity Development Board (https://www.microchip.com/dm330030)
- dsPIC33CK256MP508 High-Performance DSC (https://www.microchip.com/dspic33ck256mp508)

## Set Up

### Hardware Set up

1. Connect the board to the computer using a USB cable, connecting to the Serial port.

    <img src="../../images/hardware_setup_curiosity.jpg" height="400" alt="Hardware Setup"/>
    
### Project Set Up

#### wolfCrypt Source

The wolfCrypt files in this project use wolfssl v5.8.4-stable release with edits to support the dsPIC33C device.

#### Edits that were required for dsPIC33C support

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

## Running the Demo

### Demo Configuration

The `app_config.h` file is used to configure the project. Due to device memory constraints, use caution when enabling more than one configuration at a time. The following options are available:

| Hash             | Width         | Height               |
| ----             | -----         | ------               |
|SHA-256_192 (N24) | 1, 2, 4, or 8 | 5, 10, 15, 20, or 25 |
|SHA-256 (N32)     | 1, 2, 4, or 8 | 5, 10, 15, 20, or 25 |

### Demo Output

The device will process the configured test vector using the wolfCrypt `wc_LmsKey_Verify` API. The test parameters and verification status will be printed to the terminal listening at a baud rate of 115200.

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ck256mp508-lms.X/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt).

## Benchmarking for LMS Verification

### Verification Time
|Hash|Width|Height|Verification time (Seconds)|
|---|---|---|---|
|SHA-256_192 (N24)|8|25|0.873507|
|SHA-256 (N32)|8|25|1.005691|

### Verification Size
|Hash|Width|Height|Flash (bytes)|RAM Static (bytes)|RAM Stack (bytes)|
|---|---|---|---|---|---|
|SHA-256_192 (N24)|8|25|4,752|718|1438|
|SHA-256 (N32)|8|25|5,088|718|1438|