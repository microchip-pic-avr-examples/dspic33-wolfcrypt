<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33C Rivest–Shamir–Adleman (RSA) Verification Example Application

## Description

This MPLAB® X project demonstrates RSA Verification by using wolfCrypt APIs on a dsPIC33CK256MP508 device.

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ak512mps512-ml-dsa.X/crypto/wolfssl/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt).

## Project Setup

See the [dsPIC33CK256MP508 README](../README.md) for software tools and hardware setup.

### Test Vectors

The NIST test vectors used in this project are found at the following [repo](https://github.com/usnistgov/ACVP-Server/blob/v1.1.0.40/gen-val/json-files/RSA-SigVer-FIPS186-5/internalProjection.json).

### Project Configuration

The `app_config.h` file is used to configure the project. The following options are available:

| RSA Key Size (bits) | Padding Type | Application            |
| ------------------- | ------------ | -----------            |
| 3072                | PKCS#1 v1.5  | Signature Verification |

## Running the Application

Open the project in MPLAB® X IDE. Build the project and program the device.

### Application Output

The result data is compared to expected output. The final status is then printed to the terminal using UART and the following settings:

| Setting           | Value  
| -------           | -----  |
| Baudrate          | 115200 |
| Parity            | None   |
| Data Size         | 8      |
| Stop Bits         | 1      |
| Flow Control Mode | None   |

## Benchmarking

### Performance Benchmarking

| RSA Key Size (bits) | Padding Type | Application            | Cycles      | Time (seconds) |
| ------------------- | ------------ | -----------            | ------      | -------------- |
| 3072                | PKCS#1 v1.5  | Signature Verification | 251,808,600 | 2.518086       |

### Memory Usage Benchmarking

| RSA Key Size (bits) | Padding Type | Application            | Flash (words) |RAM Static (bytes)|RAM Stack (bytes)|
| ------------------- | ------------ | -----------            | -----------   | -------------    | -------------   |
| 3072                | PKCS#1 v1.5  | Signature Verification | 7,774         | 140              | 5,728           |