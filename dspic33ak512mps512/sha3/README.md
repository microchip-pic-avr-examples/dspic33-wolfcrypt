<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33A SHA3  Example

## Summary

This MPLAB® X project demonstrates SHA3 Digest Generation by using wolfCrypt APIs.

## Project Set Up

### wolfCrypt Source

The wolfCrypt files in this project use wolfssl v5.8.4-stable release to support the dsPIC33A device.

## Running the Demo

Open the project in MPLAB® X IDE. Build the project and program the device.

### Demo Configuration

The `app_config.h` file is used to configure the project. The following options are available:

| SHA Type Enable | Application                                        |
| --------------- | -------------------------------------------------- |
| SHA3_224_ENABLE | SHA3-224 digest generation                         | 
| SHA3_256_ENABLE | SHA3-256 digest generation                         |
| SHA3_384_ENABLE | SHA3-384 digest generation                         |
| SHA3_512_ENABLE | SHA3-512 digest generation                         |
| RUN_ALL_VECTORS   | Runs all test vectors for each SHA3 type         |

### Demo Output

The resulting verification status is then printed to the terminal using UART with the following settings:

| Setting           | Value  
| -------           | -----  |
| Baudrate          | 115200 |
| Parity            | None   |
| Data Size         | 8      |
| Stop Bits         | 1      |
| Flow Control Mode | None   |

### Demo Execution

The device will process the configured test vector using the following APIs:

#### SHA3 Hash digest API's

* `wc_InitSha3_224, wc_InitSha3_256, wc_InitSha3_384, wc_InitSha3_512` - Initializes the SHA structure.
* `wc_Sha3_224_Update, wc_Sha3_256_Update, wc_Sha3_384_Update, wc_Sha3_512_Update` - Runs the SHA digest generation.
* `wc_Sha3_224_Final, wc_Sha3_256_Final, wc_Sha3_384_Final, wc_Sha3_512_Final` - Retrieves the final digest calculated by SHA.

### Test Vectors

The NIST test vectors used in this project are found in the the NIST ACVP Server's [SHA3 folders](https://github.com/usnistgov/ACVP-Server/tree/v1.1.0.40/gen-val/json-files).

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ak512mps512-sha3.X/crypto/wolfssl/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt).

## Benchmarking for SHA3 Digest Generation

### SHA3 Digest Generation Time

| SHA Type     | Time (seconds) |
| ------------ | -------------- |
| SHA3-224     | 0.000181       |
| SHA3-256     | 0.000182       |
| SHA3-334     | 0.000182       |
| SHA3-512     | 0.000182       |

### SHA3 Digest Generation Size

| SHA Type  | Flash (bytes) | RAM Static (bytes) | RAM Stack (bytes) |
| --------  | ------------- | ------------------ | ----------------- |
| SHA3-224  | 6,856         | 32                 |  596              |
| SHA3-256  | 6,860         | 32                 |  596              |
| SHA3-384  | 6,876         | 32                 |  596              |
| SHA3-512  | 6,892         | 32                 |  596              |