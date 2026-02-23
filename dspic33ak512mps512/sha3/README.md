<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33A Secure Hash Algorithm 3 (SHA3) Digest Generation Example Application

## Description

This MPLAB® X project demonstrates SHA3 Digest Generation by using wolfCrypt APIs on a dsPIC33AK512MPS512 device.

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ak512mps512-sha3.X/crypto/wolfssl/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt).

## Project Setup

See the [dsPIC33AK512MPS512 README](../README.md) for software tools and hardware setup.

### Test Vectors

The NIST test vectors used in this project are found in the the NIST ACVP Server's [SHA3 folders](https://github.com/usnistgov/ACVP-Server/tree/v1.1.0.40/gen-val/json-files).

### Project Configuration

The `app_config.h` file is used to configure the project. The following options are available:

| SHA Type Enable | Application                                        |
| --------------- | -------------------------------------------------- |
| SHA3_224_ENABLE | SHA3-224 digest generation                         | 
| SHA3_256_ENABLE | SHA3-256 digest generation                         |
| SHA3_384_ENABLE | SHA3-384 digest generation                         |
| SHA3_512_ENABLE | SHA3-512 digest generation                         |
| RUN_ALL_VECTORS   | Runs all test vectors for each SHA3 type         |

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

| SHA Type     | Time (seconds) |
| ------------ | -------------- |
| SHA3-224     | 0.000177       |
| SHA3-256     | 0.000178       |
| SHA3-334     | 0.000178       |
| SHA3-512     | 0.000178       |

### Memory Size Benchmarking

| SHA Type  | Flash (bytes) | RAM Static (bytes) | RAM Stack (bytes) |
| --------  | ------------- | ------------------ | ----------------- |
| SHA3-224  | 6,852         | 32                 |  592              |
| SHA3-256  | 6,856         | 32                 |  592              |
| SHA3-384  | 6,872         | 32                 |  592              |
| SHA3-512  | 6,888         | 32                 |  592              |