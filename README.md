<picture>
    <source media="(prefers-color-scheme: dark)" srcset="images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="images/microchip_logo_black_red.png">
</picture>

## dsPIC33 wolfCrypt Demos

# Description
dsPIC33 wolfCrypt Demos are a collection of MPLAB® X IDE projects to demonstrate cryptographic operations using wolfSSL's wolfCrypt software library. 

# dsPIC33 Cryptographic Algorithms Support Overview
The following table provides the overview of Cryptographic Algorithms Support on dsPIC33 devices using hardware Crypto Accelerator Module on supported dsPIC33A devices and wolfSSL wolfCrypt APIs on dsPIC33C and dsPIC33A devices.

|Algorithm|Options|Modes|Supported Actions|dsPIC33CK256MP508|dsPIC33AK512MPS512|
|---|---|---|---|---|---|
|AES|Key Size (bits): 128, 192, 256|ECB, CBC|Encryption and Decryption|[Software](./dspic33ck256mp508/aes/)|[CAM 05346](https://github.com/microchip-pic-avr-examples/dspic33a-crypto-accelerator-module/tree/main/dspic33ak512mps512/aes)|
|MAC|Key Size (bits): 128, 192, 256|CMAC|Generation|[Software](./dspic33ck256mp508/mac/)|[CAM 05346](https://github.com/microchip-pic-avr-examples/dspic33a-crypto-accelerator-module/tree/main/dspic33ak512mps512/mac)|
|ECDSA|ECC Curve: P256, P384|N/A|Signature Verification|[Software](./dspic33ck256mp508/ecdsa/)|[CAM 05346](https://github.com/microchip-pic-avr-examples/dspic33a-crypto-accelerator-module/tree/main/dspic33ak512mps512/dsa)|
|SHA|Digest Size (bits): 224, 256, 384, 512|SHA2, SHA3, SHAKE|N/A|[SHA2 (Software)](./dspic33ck256mp508/sha2/)|<ul><li>[SHA2 (CAM 05346)](https://github.com/microchip-pic-avr-examples/dspic33a-crypto-accelerator-module/tree/main/dspic33ak512mps512/hash)</li> <li>[SHA2 (Software)](./dspic33ak512mps512/sha2/)</li> <li>[SHA3 (Software)](./dspic33ak512mps512/sha3/)</li> <li>[SHAKE (Software)](./dspic33ak512mps512/shake/)</li></ul>|
|RSA|Key Size (bits): 3072|N/A|Signature Verification|[Software](./dspic33ck256mp508/rsa/)|Unsupported|
|LMS|Width: 1, 2, 4, 8; Height: 5, 10, 15, 20, 25|SHA-256_192, SHA-256|Signature Verification|[Software](./dspic33ck256mp508/lms/)|[Software](./dspic33ak512mps512/lms/)|
|ML-DSA|Parameter Set: ML-DSA-44, ML-DSA-65, ML-DSA-87|N/A|Signature Verification|[Software](./dspic33ck256mp508/ml-dsa/)|[Software](./dspic33ak512mps512/ml-dsa/)|
|ML-KEM|Security Level: ML-KEM-512, ML-KEM-768, ML-KEM-1024|N/A|Decapsulation|Unsupported|[Software](./dspic33ak512mps512/ml-kem/)|

### wolfCrypt Integration

#### wolfCrypt Source

The wolfCrypt files in this project use wolfssl [v5.8.4-commercial](https://github.com/wolfSSL/Microchip/tree/main/wolfssl-5.8.4-commercial) release to support dsPIC33A and dsPIC33C devices.

API documentation for wolfcrypt files used in the demo can be found at [wolfssl's website](https://www.wolfssl.com/documentation/manuals/wolfssl/group__wolfCrypt.html)

#### wolfCrypt Library Set Up

For each demo project the custom user settings is enabled by defining a common macro `WOLFSSL_USER_SETTINGS` within the project properties. 
This allows the wolfCrypt library to be configured by macros specified within the `user_settings.h` file found under the app folder of each demo. 
These files enable specific APIs, device support, and includes additional configuration options. 
More information about the options can be found within the `user_settings.h` file.

#### Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found at the root folder of dspic33-wolfCrypt repo called [LICENSE_WOLFSSL_MICROCHIP](./LICENSE_WOLFSSL_MICROCHIP_v12052025.txt). 

# Benchmarking
## Benchmarking Setup
The benchmarking results are obtained by modifying the demo projects to remove overheads such as:
- UART peripheral and print out statements.
- Isolation to use one algorithm at a time.
- Store input data in flash memory to benchmark RAM usage.

The benchmarking projects are configured to use the following:
- Optimization level -Os
- Tools and versions as listed in the Software Tools section above

### Performance Benchmarking
The following benchmarking results were obtained while testing the wolfCrypt APIs.

Benchmarking parameters: Device clock speed set to maximum, i.e. 100 MHz for dsPIC33C devices and 200 MHz for dsPIC33A devices.

|Algorithm|Performance|Parameters (sizes are in bytes)|
|----|----|----|
||||

### Memory Size Benchmarking
Flash size will vary based on size of the stored data inputs used with the library.

All projects have the following compiler options:
- Optimization for size (-Os)
- Isolate each Algorithm and input type into separately defined sections
- Remove demo only print statements and modules not required by the algorithm. 

| Algorithm | FLASH (bytes) | RAM Static (bytes) | RAM Stack (bytes)|
|----|----|----|----|
|||||