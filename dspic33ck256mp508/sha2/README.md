<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33C SHA2 Example

## Summary

This MPLAB® X project demonstrates SHA2 hash operations by using wolfCrypt APIs on a dsPIC33CK256MP508 device.

## Project Set Up

### wolfCrypt Source

The wolfCrypt files in this project use wolfssl v5.8.4-stable release to support the dsPIC33C device.

## Running the Demo

Open the project in MPLAB® X IDE. Build the project and program the device.

### Demo Configuration

The `app_config.h` file is used to configure the project. The following options are available:

| SHA Type Enable | Application                  |
| --------------- | -----------                  |
| SHA2_224_ENABLE | SHA-224 digest generation    | 
| SHA2_256_ENABLE | SHA-256 digest generation    |
| SHA2_384_ENABLE | SHA-384 digest generation    |
| SHA2_512_ENABLE | SHA-512 digest generation    |

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

#### SHA2 Hash digest API's

* `wc_InitSha224_ex, wc_InitSha256_ex, wc_InitSha384_ex, wc_InitSha512_ex` - Initializes the SHA structure.
* `wc_Sha224Update, wc_Sha256Update, wc_Sha384Update, wc_Sha512Update` - Runs the SHA digest generation.
* `wc_Sha224Final, wc_Sha256Final, wc_Sha384Final, wc_Sha512Final` - Retrieves the final digest calculated by SHA.

### Test Vectors

The NIST test vectors used in this project are found in the the NIST ACVP Server's [SHA2 folders](https://github.com/usnistgov/ACVP-Server/tree/v1.1.0.40/gen-val/json-files).

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ck256mp508-sha2.X/crypto/wolfssl/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt). 

## Benchmarking for SHA2 Generation

### Verification Time

| SHA Type     | Cycles        | Time (seconds) |
| ------------ | ------------- | -------------- |
| SHA-224      | 31,800        | 0.000318       |
| SHA-256      | 31,800        | 0.000318       |
| SHA-334      | 98,700        | 0.000987       |
| SHA-512      | 99,900        | 0.000999       |

### Verification Size

| SHA Type | Flash (bytes) | RAM Static (bytes) | RAM Stack (bytes) |
| -------- | ------------- | ------------------ | ----------------- |
| SHA-224  | 12,647        | 122                |  962              |
| SHA-256  | 12,649        | 122                |  962              |
| SHA-384  | 12,657        | 122                |  962              |
| SHA-512  | 12,665        | 122                |  962              |