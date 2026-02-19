<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33A SHAKE Example

## Summary

This MPLAB® X project demonstrates SHAKE Digest Generation by using wolfCrypt APIs.

## Project Set Up

### wolfCrypt Source

The wolfCrypt files in this project use wolfssl v5.8.4-stable release to support the dsPIC33A device.

## Running the Demo

Open the project in MPLAB® X IDE. Build the project and program the device.

### Demo Configuration

The `app_config.h` file is used to configure the project. The following options are available:

| SHAKE Type Enable | Application                                      |
| ----------------- | ------------------------------------------------ |
| SHAKE128_ENABLE   | SHAKE 128 digest generation                      |
| SHAKE256_ENABLE   | SHAKE 256 digest generation                      |
| RUN_ALL_VECTORS   | Runs all test vectors for each SHAKE type        |

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

#### SHAKE Hash digest API's

* `wc_InitShake128, wc_InitShake256` - Initializes the SHAKE structure.
* `wc_Shake128_Update, wc_Shake256_Update` - Runs the SHAKE digest generation.
* `wc_Shake128_Final, wc_Shake256_Final` - Retrieves the final digest calculated by SHAKE.

### Test Vectors

The NIST test vectors used in this project are found in the the NIST ACVP Server's [SHAKE folders](https://github.com/usnistgov/ACVP-Server/tree/v1.1.0.40/gen-val/json-files).

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ak512mps512-shake.X/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt).

## Benchmarking for SHAKE Digest Generation

### SHAKE Digest Generation Time

| SHAKE Type     | Time (seconds) |
| -------------- | -------------- |
| SHAKE 128      | 0.000181       |
| SHAKE 256      | 0.000181       |

### SHAKE Digest Generation Size

| SHAKE Type  | Flash (bytes) | RAM Static (bytes) | RAM Stack (bytes) |
| ----------- | ------------- | ------------------ | ----------------- |
| SHAKE 128   | 6,736         | 32                 |  532              |
| SHAKE 256   | 6,764         | 52                 |  532              |