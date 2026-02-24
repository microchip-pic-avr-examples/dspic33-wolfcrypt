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

### Project Configuration

The `app_config.h` file is used to configure the project. The following options are available:

| Operation     | Parameter Set                          |
| ----          | -------------                          |
| Decapsulation | ML-KEM-512, ML-KEM-768, or ML-KEM-1024 |

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