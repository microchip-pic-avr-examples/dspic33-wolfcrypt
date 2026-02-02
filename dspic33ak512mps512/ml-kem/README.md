<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33A PQC ML-KEM (Module-Lattice-Based Key-Encapsulation Mechanism) Decapsulation

## Summary

This MPLAB® X project demonstrates ML-KEM decapsulation by using wolfCrypt APIs.

## Software Used

- dsPIC33AK-MP_DFP v1.2.135
- MPLAB® X IDE **v6.30** (https://www.microchip.com/mplabx)
- MPLAB® XC-DSC Compiler **v3.30** (https://www.microchip.com/xcdsc)

## Hardware Used

- dsPIC33AK512MPS512 Curiosity GP DIM (https://www.microchip.com/en-us/development-tool/EV80L65A)
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

### Demo Configuration

The `app_config.h` file is used to configure the project. The following options are available:

| Demo          | Parameter Set                          |
| ----          | -------------                          |
| Decapsulation | ML-KEM-512, ML-KEM-768, or ML-KEM-1024 |

### Demo Output

The device will process the configured test vector using the following APIs:

* `wc_MlKemKey_Init` -  Initializes the MlKemKey structure.
* `wc_MlKemKey_DecodePrivateKey` - Further initializes the MlKemKey structure with the private key information.
* `wc_MlKemKey_Decapsulate` - Derives the shared secret from the ciphertext.
* `wc_MlKemKey_Free` - Clears information from the MlKemKey structure.

The decapsulated shared secret will be compared to the expected result. The final status is then printed to the terminal listening at a baud rate of 115200.

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found at the root folder of dspic33-wolfCrypt repo. 

## Benchmarking for ML-KEM Decapsulation

### Decapsulation Time
|Key Type|Verfication time (Seconds)|
|---|---|---|---|
|ML-KEM 512|0.004676|
|ML-KEM 768|0.007521|
|ML-KEM 1024|0.011421|

### Decapsulation Size
|Hash|Flash (bytes)|RAM Static (bytes)|RAM Stack (bytes)|
|---|---|---|---|---|---|
|ML-KEM 512|29,016|98|20,204|
|ML-KEM 768|30,488|98|20,204|
|ML-KEM 1024|32,120|98|20,204|