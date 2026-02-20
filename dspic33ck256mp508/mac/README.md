<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
    <source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33C wolfCrypt Message Authentication Code (MAC) Generation Example Application

## Description

This MPLAB® X project demonstrates MAC generation by using wolfCrypt APIs on a dsPIC33CK256MP508 device.

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ck256mp508-aes.X/crypto/wolfssl/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt).

## Project Setup

See the [dsPIC33CK256MP508 README](../README.md) for software tools and hardware setup.

### wolfCrypt Source

The wolfCrypt files in this project use wolfssl v5.8.4-stable release to support the dsPIC33C device.

### Project Configuration

The `app_config.h` file is used to configure the project. The following options are available:

| AES Key Size Enable | Algorithms  |
| ---------------     | ----------- |
| AES_128             | CMAC        |
| AES_192             | CMAC        |
| AES_256             | CMAC        |

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

<img src="../../images/cmac_generation_output.jpg" alt="AES CMAC Output" width="750"/>

### Application Execution

The device will process the input vectors using the following APIs:

#### AES-CMAC APIs

* `wc_InitCmac` - Initializes the CMAC structure.
* `wc_CmacUpdate` - Processes input data for a CMAC operation and updates the CMAC context.
* `wc_CmacFinal` - Retrieves the final CMAC value.

### Test Vectors

The NIST test vectors used in this project are found in the following [repo](https://github.com/usnistgov/ACVP-Server/tree/v1.1.0.40/gen-val/json-files/CMAC-AES-1.0).

## Benchmarking

### Performance Benchmarking

#### AES-CMAC
|Key Size (bytes)|Plaintext Size (bytes)|MAC Size (bytes)|Generation Performance (seconds)|
|----|----|----|----|
|16|532|16|0.002837|
|24|532|16|0.003278|
|32|532|16|0.003734|

### Memory Size Benchmarking
The following results include usage of AES-CMAC APIs. Flash size will vary based on size of the stored data inputs used with the library.

|Mode|FLASH (bytes)|RAM Static (bytes)|RAM Stack (bytes)|
|----|----|----|----|
|AES-CMAC|9,247|528|166|