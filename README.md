<picture>
    <source media="(prefers-color-scheme: dark)" srcset="images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="images/microchip_logo_black_red.png">
</picture>

## dsPIC33 wolfCrypt Demos

# Description
dsPIC33 wolfCrypt Demos are a collection of MPLAB® X IDE projects to demonstrate the following cryptographic operations:
- AES
  - ECB
  - CBC
- MAC
  - AES-CMAC
- ECDSA
- SHA
  - SHA2
  - SHA3
  - SHAKE
- RSA (Rivest–Shamir–Adleman)
- LMS (Leighton–Micali Signatures)
- ML-DSA (Module-Lattice-Based Digital Signature Algorithm)
- ML-KEM (Module-Lattice-Based Key-Encapsulation Mechanism)

# Prerequisites

## Software Tool Versions Used
- dsPIC33AK-MP_DFP v1.3.185
- dsPIC33CK-MP_DFP v1.15.423
- MPLAB® X IDE [v6.30](https://www.microchip.com/mplabx)
- MPLAB® XC-DSC Compiler [v3.30](https://www.microchip.com/xcdsc)

## Hardware Tools
- dsPIC33AK512MPS512 Demos
  - dsPIC33AK512MPS512 Curiosity GP DIM ([EV80L65A](https://www.microchip.com/en-us/development-tool/EV80L65A))
  - Curiosity Platform Development Board ([EV74H48A](https://www.microchip.com/EV74H48A))
- dsPIC33CK256MP508 Demos
  - dsPIC33CK Curiosity Development Board ([DM330030](https://www.microchip.com/dm330030))
  - dsPIC33CK256MP508 High-Performance DSC (https://www.microchip.com/dspic33ck256mp508)

# Contents Summary
- dspic33ck256mp508
  - aes
  - ecdsa
  - lms
  - mac
  - ml-dsa
  - rsa
  - sha2
- dspic33ak512mps512
  - lms
  - ml-dsa
  - ml-kem
  - sha2
  - sha3
  - shake

# wolfCrypt APIs

These demos use the wolfCrypt library to perform the algorithms. The wolfCrypt library provides APIs that are used by the demos to access the library's functionality.

# MISRA

A MISRA scan has been conducted on each project. All application files are MISRA compliant for Required and Mandatory rules.

# Benchmarking
## Benchmarking Setup
The benchmarking results are obtained by modifying the demo projects to remove overheads such as:
- UART peripheral and print out statements.
- Isolation to use one algorithm at a time.
- Store input data in flash memory to benchmark RAM usage for CAM Hardware Driver

The benchmarking projects are configured to use the following:
- Optimization level -Os
- Tools and versions as listed in the Software Tools section above

### Performance Benchmarking
The following benchmarking results were obtained while testing the wolfCrypt APIs.

Benchmarking parameters: Device clock speed set to 200 MHz
|Algorithm|Performance|Parameters (sizes are in bytes)|
|----|----|----|
||||

### Memory Size Benchmarking
Flash size will vary based on size of the stored data inputs used with the library.

All projects have the following compiler options:
- Optimization for size (-Os)
- Isolate each function in a section - unchecked
- Remove unused sections - unchecked

| Algorithm | FLASH (bytes) | RAM Static (bytes) | RAM Stack (bytes)|
|----|----|----|----|
|||||