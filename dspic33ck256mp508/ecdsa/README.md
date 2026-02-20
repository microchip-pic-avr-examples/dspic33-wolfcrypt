<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33C Elliptic Curve Digital Signature Algorithm (ECDSA) Verification Example Application

## Decription

This MPLAB® X project demonstrates ECDSA verification by using wolfCrypt APIs on a dsPIC33CK256MP508 device.

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ck256mp508-ecdsa.X/crypto/wolfssl/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt).

## Project Setup

See the [dsPIC33CK256MP508 README](../README.md) for software tools and hardware setup.

### wolfCrypt Source

The wolfCrypt files in this project use wolfssl v5.8.4-stable release to support the dsPIC33C device.

### Project Configuration

The `app_config.h` file is used to configure the project. The following options are available:

| ECC Curve  | Application                  |
| ---------- | -----------                  |
| P256       | ECDSA Signature Verification | 
| P384       | ECDSA Signature Verification |

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

<img src="../../images/ecdsa_ecc_verify_output.jpg" alt="ECDSA ECC Verify output"/>

### Application Execution

The device will process the configured test vector using the following APIs:

#### ECDSA Signature Verification

* `wc_ecc_init` - Initializes the ECC key structure.
* `wc_ecc_import_unsigned` - Further initializes the ECC key structure with the key information.
* `wc_ecc_verify_hash` - Verifies the hash and signature against the selected curve.

### Test Vectors

The NIST test vectors used in this project are found in the following [repo](https://github.com/usnistgov/ACVP-Server/blob/v1.1.0.40/gen-val/json-files/ECDSA-SigVer-1.0/internalProjection.json).

## Benchmarking

### Performance Benchmarking

| ECC Curve    | Cycles        | Time (seconds) |
| ------------ | ------------- | -------------- |
| P256         |   548,985,500 |  5.489855      |
| P384         | 1,708,674,700 | 17.086748      |

### Memory Size Benchmarking

|ECC Curve | Flash (bytes) | RAM Static (bytes) | RAM Stack (bytes) |
| -------- | ------------- | ------------------ | ----------------- |
| P256     | 11,926        | 204                |  6,370            |
| P384     | 11,966        | 204                |  6,370            |
