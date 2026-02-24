<picture>
    <source media="(prefers-color-scheme: dark)" srcset="images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="images/microchip_logo_black_red.png">
</picture>

# dsPIC33 wolfCrypt Example Applications

## Description
dsPIC33 wolfCrypt Example Applications are a collection of MPLAB® X IDE projects to demonstrate cryptographic operations using wolfSSL's wolfCrypt software library. 

## dsPIC33 wolfCrypt Support
The following table provides the overview of Cryptographic Algorithms Support on dsPIC33 devices for wolfSSL wolfCrypt APIs. Note: The dsPIC33AK device family contains the hardware Crypto Accelerator Module (CAM 05346) which was utilized within the LMS example application for its hash capabilities.

|Algorithm|Options|Modes|Supported Actions|dsPIC33CK Family|dsPIC33AK Family|
|---|---|---|---|---|---|
|AES|Key Size (bits): 128, 192, 256|ECB, CBC|Encryption and Decryption|[Supported](./dspic33ck256mp508/aes/)||
|MAC|Key Size (bits): 128, 192, 256|CMAC|Generation|[Supported](./dspic33ck256mp508/mac/)||
|ECDSA|ECC Curve: P256, P384|N/A|Signature Verification|[Supported](./dspic33ck256mp508/ecdsa/)||
|SHA|Digest Size (bits): 224, 256, 384, 512|SHA2, SHA3, SHAKE|N/A|[SHA2](./dspic33ck256mp508/sha2/)|<ul> <li>[SHA2](./dspic33ak512mps512/sha2/)</li> <li>[SHA3](./dspic33ak512mps512/sha3/)</li> <li>[SHAKE](./dspic33ak512mps512/shake/)</li></ul>|
|RSA|Key Size (bits): 3072|N/A|Signature Verification|[Supported](./dspic33ck256mp508/rsa/)||
|LMS|Width: 1, 2, 4, 8; Height: 5, 10, 15, 20, 25|SHA-256_192, SHA-256|Signature Verification|[Supported](./dspic33ck256mp508/lms/)|[Supported with use of CAM 05346](./dspic33ak512mps512/lms/)|
|ML-DSA|Parameter Set: ML-DSA-44, ML-DSA-65, ML-DSA-87|N/A|Signature Verification|[Supported](./dspic33ck256mp508/ml-dsa/)|[Supported](./dspic33ak512mps512/ml-dsa/)|
|ML-KEM|Security Level: ML-KEM-512, ML-KEM-768, ML-KEM-1024|N/A|Decapsulation||[Supported](./dspic33ak512mps512/ml-kem/)|

## dsPIC33 Cryptographic Algorithms Support Overview
The following table provides the overview of Cryptographic Algorithms Support on dsPIC33 devices.
- `Software` represents projects that use wolfCrypt software implementations for cryptographic functions in the example applications
- `CAM 05346` represents and links projects that use Microchip's hardware Crypto Accelerator Module integrated into the dsPIC33A device family
- The LMS example application uses CAM hardware for its hash capabilities on dsPIC33A devices

|Algorithm|Supported Actions|dsPIC33CK Family|dsPIC33AK Family|
|---|---|---|---|
|AES|Encryption and Decryption|[Software](./dspic33ck256mp508/aes/)|[CAM 05346](https://github.com/microchip-pic-avr-examples/dspic33a-crypto-accelerator-module/tree/main/dspic33ak512mps512/aes)|
|MAC|Generation|[Software](./dspic33ck256mp508/mac/)|[CAM 05346](https://github.com/microchip-pic-avr-examples/dspic33a-crypto-accelerator-module/tree/main/dspic33ak512mps512/mac)|
|ECDH|Shared Secret Generation||[CAM 05346](https://github.com/microchip-pic-avr-examples/dspic33a-crypto-accelerator-module/tree/main/dspic33ak512mps512/ecdh)|
|ECDSA|Signature Verification|[Software](./dspic33ck256mp508/ecdsa/)|[CAM 05346](https://github.com/microchip-pic-avr-examples/dspic33a-crypto-accelerator-module/tree/main/dspic33ak512mps512/dsa)|
|SHA|N/A|[SHA2 (Software)](./dspic33ck256mp508/sha2/)|<ul><li>[SHA2 (CAM 05346)](https://github.com/microchip-pic-avr-examples/dspic33a-crypto-accelerator-module/tree/main/dspic33ak512mps512/hash)</li> <li>[SHA2 (Software)](./dspic33ak512mps512/sha2/)</li> <li>[SHA3 (Software)](./dspic33ak512mps512/sha3/)</li> <li>[SHAKE (Software)](./dspic33ak512mps512/shake/)</li></ul>|
|RSA|Signature Verification|[Software](./dspic33ck256mp508/rsa/)||
|LMS|Signature Verification|[Software](./dspic33ck256mp508/lms/)|[Software + CAM 05346](./dspic33ak512mps512/lms/)|
|ML-DSA|Signature Verification|[Software](./dspic33ck256mp508/ml-dsa/)|[Software](./dspic33ak512mps512/ml-dsa/)|
|ML-KEM|Decapsulation||[Software](./dspic33ak512mps512/ml-kem/)|

## wolfCrypt Integration

### wolfCrypt Source

The wolfCrypt files in this project use wolfssl [v5.8.4-commercial](https://github.com/wolfSSL/Microchip/tree/main/wolfssl-5.8.4-commercial) release to support dsPIC33A and dsPIC33C devices.

API documentation for wolfcrypt files used in the example application can be found at [wolfssl's website](https://www.wolfssl.com/documentation/manuals/wolfssl/group__wolfCrypt.html)

### wolfCrypt Library Setup

For each example application the custom user settings is enabled by defining a common macro `WOLFSSL_USER_SETTINGS` within the project properties. 
This allows the wolfCrypt library to be configured by macros specified within the `user_settings.h` file found under the app folder of each example application. 
These files enable specific APIs, device support, and includes additional configuration options. 
More information about the options can be found within the `user_settings.h` file.

### Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found at the root folder of dspic33-wolfCrypt repo called [LICENSE_WOLFSSL_MICROCHIP](./LICENSE_WOLFSSL_MICROCHIP_v12052025.txt). 

## Benchmarking
### Benchmarking Setup
The benchmarking results are obtained by modifying the example application to remove overheads such as:
- UART peripheral and print out statements
- Isolation to use one algorithm at a time
- Store input data in flash memory to benchmark RAM usage

The benchmarking projects are configured to use the following:
- Optimization level -Os
- Tools and versions as listed in the Software Tools section above

### Performance Benchmarking
The following benchmarking results were obtained while testing the wolfCrypt APIs.

Benchmarking parameters: Device clock speed set to maximum, i.e. 100 MHz for dsPIC33C devices and 200 MHz for dsPIC33A devices.

|Algorithm|Parameters (sizes are in bytes)|dsPIC33CK256MP508 (time in s)|dsPIC33AK512MPS512 (time in s)|
|----|----|----|----|
|AES-CBC|Key Size: 32 bytes, IV Size: 16 bytes, Plaintext: 80 bytes, Direction: Encryption||0.000560|
|AES-ECB|Key Size: 32 bytes, Plaintext: 80 bytes, Direction: Encryption||0.000550|
|ECDSA|Curve: P384||17.086748|
|LMS|SHA-256, Width: 8, Height: 25|0.081927|1.203449|
|MAC-CMAC|Key Size: 32 bytes, Plaintext Size: 532 bytes, MAC Size: 16 bytes||0.003734|
|ML-DSA|Dilithium 87|0.047319|0.7263|
|ML-KEM|ML-KEM 1024|0.011420||
|RSA|Key Size: 3072 bits, Padding types: PKCS#1 v1.5||2.518086|
|SHA2|SHA Type: SHA-512|0.000091|0.000999|
|SHA3|SHA Type: SHA3-512|0.000178||
|SHAKE|SHAKE Type: SHAKE 256|0.000178||

### Memory Size Benchmarking
Flash size will vary based on size of the stored data inputs used with the library.

All projects have the following compiler options:
- Isolate each algorithm and input type into separately defined sections
- Remove print statements and modules not required by the algorithm

<table>
  <tr>
    <th rowspan="2">Algorithm</th>
    <th rowspan="2">Parameters</th>
    <th colspan="3">dsPIC33CK256MP508</th>
    <th colspan="3">dsPIC33AK512MPS512</th>
  </tr>
  <tr>
    <th>FLASH <br>(bytes)</th>
    <th>RAM <br>Static <br>(bytes)</th>
    <th>RAM <br>Stack <br>(bytes)</th>
    <th>FLASH <br>(bytes)</th>
    <th>RAM <br>Static <br>(bytes)</th>
    <th>RAM <br>Stack <br>(bytes)</th>
  </tr>
  <tr>
    <td>AES</td>
    <td>All Modes (ECB and CBC), Encrypt and Decrypt Enabled</td>
    <td>10,644</td><td>480</td><td>116</td>
    <td></td><td></td><td></td>
  </tr>
  <tr>
    <td>ECDSA</td>
    <td>Curve: P384</td>
    <td>11,966</td><td>204</td><td>6,370</td>
    <td></td><td></td><td></td>
  </tr>
  <tr>
    <td>LMS</td>
    <td>SHA-256, Width: 8, Height: 25</td>
    <td>5,097</td><td>798</td><td>1,442</td>
    <td>14,688</td><td>78</td><td>1,852</td>
  </tr>
  <tr>
    <td>MAC-CMAC</td>
    <td>Key Size: 32 bytes, Plaintext Size: 532 bytes, MAC Size: 16 bytes</td>
    <td>9,247</td><td>528</td><td>166</td>
    <td></td><td></td><td></td>
  </tr>
  <tr>
    <td>ML-DSA</td>
    <td>Dilithium 87, Message Size: 4,616 bytes</td>
    <td>19,858</td><td>138</td><td>964</td>
    <td>40,536</td><td>56</td><td>1,192</td>
  </tr>
  <tr>
    <td>ML-KEM</td>
    <td>ML-KEM 1024</td>
    <td></td><td></td><td></td>
    <td>32,576</td><td>98</td><td>20,204</td>
  </tr>
  <tr>
    <td>RSA</td>
    <td>Key Size: 3072 bits, Padding types: PKCS#1 v1.5</td>
    <td>7,774</td><td>140</td><td>5,728</td>
    <td></td><td></td><td></td>
  </tr>
  <tr>
    <td>SHA2</td>
    <td>SHA Type: SHA-512</td>
    <td>12,665</td><td>122</td><td>962</td>
    <td>21,340</td><td>32</td><td>1,484</td>
  </tr>
  <tr>
    <td>SHA3</td>
    <td>SHA Type: SHA3-512</td>
    <td></td><td></td><td></td>
    <td>6,888</td><td>32</td><td>592</td>
  </tr>
  <tr>
    <td>SHAKE</td>
    <td>SHAKE Type: SHAKE 256</td>
    <td></td><td></td><td></td>
    <td>6,760</td><td>52</td><td>528</td>
  </tr>
</table>