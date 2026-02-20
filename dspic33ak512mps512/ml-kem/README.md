<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33A Module-Lattice-Based Key-Encapsulation Mechanism (ML-KEM) Decapsulation Example Application

## Description

This MPLAB® X project demonstrates ML-KEM decapsulation by using wolfCrypt APIs on a dsPIC33AK512MPS512 device.

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ak512mps512-ml-kem.X/crypto/wolfssl/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt).

## Project Setup

See the [dsPIC33AK512MPS512 README](../README.md) for software tools and hardware setup.

### wolfCrypt Source

The wolfCrypt files in this project use wolfssl v5.8.4-stable release to support the dsPIC33A device.

### Project Configuration

The `app_config.h` file is used to configure the project. The following options are available:

| Operation     | Parameter Set                          |
| ----          | -------------                          |
| Decapsulation | ML-KEM-512, ML-KEM-768, or ML-KEM-1024 |

## Running the Application

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

The device will process the configured test vector using the following APIs:

#### ML-KEM APIs

* `wc_MlKemKey_Init` -  Initializes the MlKemKey structure.
* `wc_MlKemKey_DecodePrivateKey` - Further initializes the MlKemKey structure with the private key information.
* `wc_MlKemKey_Decapsulate` - Derives the shared secret from the ciphertext.
* `wc_MlKemKey_Free` - Clears information from the MlKemKey structure.

The decapsulated shared secret will be compared to the expected result. The final status is then printed to the terminal listening at a baud rate of 115200.

## Benchmarking

### Performance Benchmarking
|Key Type|Verification time (Seconds)|
|---|---|---|---|
|ML-KEM 512|0.004674|
|ML-KEM 768|0.007522|
|ML-KEM 1024|0.011420|

### Memory Size Benchmarking
|Hash|Flash (bytes)|RAM Static (bytes)|RAM Stack (bytes)|
|---|---|---|---|---|---|
|ML-KEM 512|29,472|98|20,204|
|ML-KEM 768|30,944|98|20,204|
|ML-KEM 1024|32,576|98|20,204|