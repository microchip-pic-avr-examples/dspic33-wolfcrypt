<picture>
    <source media="(prefers-color-scheme: dark)" srcset="images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="images/microchip_logo_black_red.png">
</picture>

## dsPIC33 wolfCrypt Demos

# Description
dsPIC33 wolfCrypt Demos are a collection of MPLAB® X IDE projects to demonstrate the following cryptographic operations using wolfSSL's wolfCrypt software library:

|Algorithm|Options|Modes|Supported Actions|dsPIC33CK256MP508|dsPIC33A CAM v2|dsPIC33A CAM v3|dsPIC33A Software|
|---|---|---|---|---|---|---|---|
|AES|Key Size (bits): 128, 192, 256|ECB, CBC|Encryption and Decryption|[✅](./dspic33ck256mp508/aes/)|[❌*](https://github.com/microchip-pic-avr-examples/dspic33a-crypto-accelerator-module/tree/main/dspic33ak512mps512/aes)|❌|❌|
|MAC|Key Size (bits): 128, 192, 256|CMAC|Generation|[✅](./dspic33ck256mp508/mac/)|[❌*](https://github.com/microchip-pic-avr-examples/dspic33a-crypto-accelerator-module/tree/main/dspic33ak512mps512/mac)|❌|❌|
|ECDSA|ECC Curve: P256, P384|N/A|Signature Verification|[✅](./dspic33ck256mp508/ecdsa/)|[❌*](https://github.com/microchip-pic-avr-examples/dspic33a-crypto-accelerator-module/tree/main/dspic33ak512mps512/dsa)|❌|❌|
|SHA|Digest Size (bits): 224, 256, 384, 512|SHA2, SHA3, SHAKE|N/A|[✅](./dspic33ck256mp508/sha2/)|[✅](https://github.com/microchip-pic-avr-examples/dspic33a-crypto-accelerator-module/tree/main/dspic33ak512mps512/hash)|❌|❌|
|RSA|Key Size (bits): 3072|N/A|Signature Verification|[✅](./dspic33ck256mp508/rsa/)|❌|❌|❌|
|LMS|Width: 1, 2, 4, 8; Height: 5, 10, 15, 20, 25|SHA-256_192, SHA-256|Signature Verification|[✅](./dspic33ck256mp508/lms/)|❌|❌|[✅](./dspic33ak512mps512/lms/)|
|ML-DSA|Parameter Set: ML-DSA-44, ML-DSA-65, ML-DSA-87|N/A|Signature Verification|[✅](./dspic33ck256mp508/ml-dsa/)|❌|❌|[✅](./dspic33ak512mps512/ml-dsa/)|
|ML-KEM|Security Level: ML-KEM-512, ML-KEM-768, ML-KEM-1024|N/A|Decapsulation|❌|❌|❌|[✅](./dspic33ak512mps512/ml-kem/)|

*Supported by the CAM v2 alone. See [here](https://github.com/microchip-pic-avr-examples/dspic33a-crypto-accelerator-module/tree/main/dspic33ak512mps512) for demo projects.
**Supported by the CAM v3 alone. See [here](https://github.com/microchip-pic-avr-examples/dspic33a-crypto-accelerator-module/tree/main/dspic33ak256mps306) for demo projects.

# wolfCrypt APIs

These demos use the wolfCrypt library to perform the algorithms. The wolfCrypt library provides APIs that are used by the demos to access the library's functionality. The wolfSSL API documentation can be found [here](https://www.wolfssl.com/documentation/manuals/wolfssl/group__TLS.html). 

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

Benchmarking parameters: Device clock speed set to 100 MHz for dsPIC33C devices and 200 MHz for dsPIC33A devices.

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