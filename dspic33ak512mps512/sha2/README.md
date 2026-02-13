<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33A SHA2 Example

## Summary

This MPLAB® X project demonstrates SHA2 hash operations by using wolfCrypt APIs.

## Software Used 

- dsPIC33AK-MP_DFP v1.3.185
- MPLAB® X IDE **v6.30** (https://www.microchip.com/mplabx)
- MPLAB® XC-DSC Compiler **v3.30** (https://www.microchip.com/xcdsc)

## Hardware Used

- dsPIC33AK512MPS512 Curiosity GP DIM (https://www.microchip.com/EV80L65A)
- Curiosity Platform Development Board (https://www.microchip.com/EV74H48A)

## Set up

### Hardware Set up

1. Insert the dsPIC33AK512MPS512 DIM into the DIM J1 slot on the Curiosity Platform Development Board.
2. Connect the board from the J24 USB-C PKoB4 (PICKit™ On-Board 4) to the computer.

    <img src="../../images/hardware_setup.jpg" height="400" alt="Hardware Setup"/>

### Project Set Up

#### wolfCrypt Source

The wolfCrypt files in this project use wolfssl v5.8.4-stable release to support the dsPIC33A device.

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

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ak512mps512-sha2.X/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt).

## Benchmarking for SHA2 Generation

### Verification Time

| SHA Type     | Time (seconds) |
| ------------ | -------------- |
| SHA-224      | 0.000027       |
| SHA-256      | 0.000027       |
| SHA-334      | 0.000087       |
| SHA-512      | 0.000089       |

### Verification Size

| SHA Type | Flash (bytes) | RAM Static (bytes) | RAM Stack (bytes) |
| -------- | ------------- | ------------------ | ----------------- |
| SHA-224  | 21,172        | 32                 |  1,476            |
| SHA-256  | 21,176        | 32                 |  1,476            |
| SHA-384  | 21,192        | 32                 |  1,476            |
| SHA-512  | 21,208        | 32                 |  1,476            |