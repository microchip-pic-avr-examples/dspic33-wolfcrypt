<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33A Secure Hash Algorithm - KECCAK (SHAKE) Digest Generation Example Application

## Description

This MPLAB® X project demonstrates SHAKE Digest Generation by using wolfCrypt APIs on a dsPIC33AK512MPS512 device.

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ak512mps512-shake.X/crypto/wolfssl/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt).

## Project Setup

See the [dsPIC33AK512MPS512 README](../README.md) for software tools and hardware setup.

### Test Vectors

The NIST test vectors used in this project are found in the the NIST ACVP Server's [SHAKE folders](https://github.com/usnistgov/ACVP-Server/tree/v1.1.0.40/gen-val/json-files).

### Project Configuration

The `app_config.h` file is used to configure the project. The following options are available:

| SHAKE Type Enable | Application                                      |
| ----------------- | ------------------------------------------------ |
| SHAKE128_ENABLE   | SHAKE 128 digest generation                      |
| SHAKE256_ENABLE   | SHAKE 256 digest generation                      |
| RUN_ALL_VECTORS   | Runs all test vectors for each SHAKE type        |

## Running the Application

Open the project in MPLAB® X IDE. Build the project and program the device.

### Application Output

The resulting verification status is then printed to the terminal using UART with the following settings:

| Setting           | Value  
| -------           | -----  |
| Baudrate          | 115200 |
| Parity            | None   |
| Data Size         | 8      |
| Stop Bits         | 1      |
| Flow Control Mode | None   |

## Benchmarking

### Performance Benchmarking

| SHAKE Type     | Time (seconds) |
| -------------- | -------------- |
| SHAKE 128      | 0.000177       |
| SHAKE 256      | 0.000178       |

### Memory Size Benchmarking

| SHAKE Type  | Flash (bytes) | RAM Static (bytes) | RAM Stack (bytes) |
| ----------- | ------------- | ------------------ | ----------------- |
| SHAKE 128   | 6,732         | 32                 |  528              |
| SHAKE 256   | 6,760         | 52                 |  528              |