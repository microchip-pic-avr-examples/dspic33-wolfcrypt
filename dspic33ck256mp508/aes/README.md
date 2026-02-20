<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33C Advanced Encryption Standard (AES) Example Application

## Description

This MPLAB® X project demonstrates AES processing by using wolfCrypt APIs on a dsPIC33CK256MP508 device.

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ck256mp508-aes.X/crypto/wolfssl/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt).

## Project Setup

See the [dsPIC33CK256MP508 README](../README.md) for software tools and hardware setup.

### wolfCrypt Source

The wolfCrypt files in this project use wolfssl v5.8.4-stable release to support the dsPIC33C device.

### Project Configuration

The `app_config.h` file is used to configure the project. The following options are available:

| AES Key Size Enable | Algorithms  | Operations       |
| ---------------     | ----------- | ----------       |
| AES_128             | ECB, CBC    | Encrypt, Decrypt |
| AES_192             | ECB, CBC    | Encrypt, Decrypt |
| AES_256             | ECB, CBC    | Encrypt, Decrypt |

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

### Application Execution

The device will process the input vectors using the following APIs:

#### AES-ECB APIs

* `wc_AesInit` - Initializes the AES structure.
* `wc_AesSetKey` - Further initializes the AES structure with the key information.
* `wc_AesEcbEncrypt` - Encrypts the given plaintext using ECB mode.
* `wc_AesEcbDecrypt` - Decrypts the given ciphertext using ECB mode.

#### AES-CBC APIs

* `wc_AesInit` - Initializes the AES structure.
* `wc_AesSetKey` - Further initializes the AES structure with the key and initialization vector information.
* `wc_AesCbcEncrypt` - Encrypts the given plaintext using CBC mode.
* `wc_AesCbcDecrypt` - Decrypts the given ciphertext using CBC mode.

### Test Vectors

The NIST test vectors used in this project are found in the following [repo](https://github.com/usnistgov/ACVP-Server/blob/v1.1.0.40/gen-val/json-files/).

## Benchmarking

### Performance Benchmarking
The following benchmarking results were obtained with the device clock speed set to 200MHz.

#### AES-ECB

|Key Size (bytes)|Plaintext Size (bytes)|Encryption Performance (seconds)|
|----|----|----|
|16|80|0.000404|
|24|80|0.000472|
|32|80|0.000550|

|Key Size (bytes)|Plaintext Size (bytes)|Decryption Performance (seconds)|
|----|----|----|
|16|80|0.000492|
|24|80|0.000578|
|32|80|0.000673|

#### AES-CBC
|Key Size (bytes)|Initialization Vector Size (bytes)|Plaintext Size (bytes)|Encryption Performance (seconds)|
|----|----|----|----|
|16|16|80|0.000417|
|24|16|80|0.000483|
|32|16|80|0.000560|

|Key Size (bytes)|Initialization Vector Size (bytes)|Ciphertext Size (bytes)|Decryption Performance (seconds)|
|----|----|----|----|
|16|16|80|0.000513|
|24|16|80|0.000601|
|32|16|80|0.000694|

### Memory Size Benchmarking
The following results include usage of ECB and CBC APIs. Flash size will vary based on size of the stored data inputs used with the library.

|AES Mode|Direction|FLASH (bytes)|RAM Static (bytes)|RAM Stack (bytes)|
|----|----|----|----|----|
|ECB              |Encrypt            |7,987|480|116|
|ECB              |Decrypt            |7,965|480|116|
|CBC              |Encrypt            |8,078|480|116|
|CBC              |Decrypt            |8,069|480|116|
|All Modes Enabled|Encrypt and Decrypt|10,644|480|116|