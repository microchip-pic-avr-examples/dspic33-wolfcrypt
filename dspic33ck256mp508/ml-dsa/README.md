<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../../../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../../../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../../../images/microchip_logo_black_red.png">
</picture>

# dsPIC33C Module-Lattice-Based Digital Signature (ML-DSA) Verification Example Application

## Decription

This MPLAB® X project demonstrates ML-DSA Verify using wolfCrypt APIs on a dsPIC33CK256MP508 device.

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found within the MPLAB® X project folder called [LICENSE_WOLFSSL_MICROCHIP](./dspic33ak512mps512-ml-dsa.X/crypto/wolfssl/LICENSE_WOLFSSL_MICROCHIP_v12052025.txt).

## Project Setup

See the [dsPIC33CK256MP508 README](../README.md) for software tools and hardware setup.

### wolfCrypt Source Edits to support dsPIC33C

1. `crypto\wolfssl\wolfssl\wolfcrypt\dilithium.h`

    Line 212: Cast the 1 literal to be of type sword32.
    ``` c
    //Before:
    #define DILITHIUM_GAMMA1_17             (1 << 17)

    //After:
    #define DILITHIUM_GAMMA1_17             ((sword32)1 << 17)
    ```
2. `crypto\wolfssl\wolfssl\wolfcrypt\dilithium.h`

    Line 2129 Cast the 1 literal to be of type sword32.
    ``` c
    //Before:
    #define DILITHIUM_GAMMA1_19             (1 << 19)

    //After:
    #define DILITHIUM_GAMMA1_19             ((sword32)1 << 19)
    ```

3. `crypto\wolfssl\wolfcrypt\src\dilithium.c`

    Line 9527 Cast the 1 literal to be of type sword32.
    ```c
    //Before:
    hi = (1 << params->gamma1_bits) - params->beta;

    //After:
    hi = ((sword32)1 << params->gamma1_bits) - params->beta;
    ```

4. `crypto\wolfssl\wolfcrypt\src\dilithium.c`

    Line 1886 through 1897 fix casts to sword32.
    ```c 
    //Before:
    z[i+0] = DILITHIUM_GAMMA1_17 -
                ( s[ 0]       | ((sword32)(s[ 1] << 8) |
                (sword32)(s[ 2] & 0x03) << 16));
    z[i+1] = DILITHIUM_GAMMA1_17 -
                ((s[ 2] >> 2) | ((sword32)(s[ 3] << 6) |
                (sword32)(s[ 4] & 0x0f) << 14));
    z[i+2] = DILITHIUM_GAMMA1_17 -
                ((s[ 4] >> 4) | ((sword32)(s[ 5] << 4) |
                (sword32)(s[ 6] & 0x3f) << 12));
    z[i+3] = DILITHIUM_GAMMA1_17 -
                ((s[ 6] >> 6) | ((sword32)(s[ 7] << 2) |
                (sword32)(s[ 8]       ) << 10));

    //After:
    z[i+0] = DILITHIUM_GAMMA1_17 - ((sword32)s[ 0]        | (((sword32)s[ 1] << 8) |
                                   ((sword32)s[ 2] & 0x03) << 16));
    z[i+1] = DILITHIUM_GAMMA1_17 - (((sword32)s[ 2] >> 2) | (((sword32)s[ 3] << 6) |
                                   ((sword32)s[ 4] & 0x0f) << 14));           
    z[i+2] = DILITHIUM_GAMMA1_17 - (((sword32)s[ 4] >> 4) | (((sword32)s[ 5] << 4) |
                                   ((sword32)s[ 6] & 0x3f) << 12));           
    z[i+3] = DILITHIUM_GAMMA1_17 - (((sword32)s[ 6] >> 6) | (((sword32)s[ 7] << 2) |
                                   ((sword32)s[ 8]       ) << 10));                    
    ```

5. `crypto\wolfssl\wolfcrypt\src\dilithium.c`

    Line 2008 through 2015 fix casts to sword32.
    ```c 
    //Before:
    z[i+0] = DILITHIUM_GAMMA1_19 - ( s[0]       | ((sword32)s[1] << 8) |
                                    ((sword32)(s[2] & 0x0f) << 16));
    z[i+1] = DILITHIUM_GAMMA1_19 - ((s[2] >> 4) | ((sword32)s[3] << 4) |
                                    ((sword32)(s[4]       ) << 12));
    z[i+2] = DILITHIUM_GAMMA1_19 - ( s[5]       | ((sword32)s[6] << 8) |
                                    ((sword32)(s[7] & 0x0f) << 16));
    z[i+3] = DILITHIUM_GAMMA1_19 - ((s[7] >> 4) | ((sword32)s[8] << 4) |
                                    ((sword32)(s[9]       ) << 12));

    //After:
    z[i+0] = DILITHIUM_GAMMA1_19 - ((sword32)s[0]        | ((sword32)s[1] << 8) |
                                   (((sword32)s[2] & (sword32)0x0f) << 16));
    z[i+1] = DILITHIUM_GAMMA1_19 - (((sword32)s[2] >> 4) | ((sword32)s[3] << 4) |
                                   ((sword32)s[4] << 12));
    z[i+2] = DILITHIUM_GAMMA1_19 - ((sword32)s[5]       |  ((sword32)s[6] << 8) |
                                   (((sword32)s[7] & (sword32)0x0f) << 16));
    z[i+3] = DILITHIUM_GAMMA1_19 - (((sword32)s[7] >> 4) | ((sword32)s[8] << 4) |
                                   ((sword32)s[9] << 12));
    ```

### Input Vector FIPS-204

The test vectors in this example application come from the NIST defined public keys, messages and signature values.
- These values are raw data inputs with no encoding. 

If another tool is used to generate a signature it may encode the message by default following [FIPS-204](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.204.pdf) (Algorithm 2 Step 10)
- If this is the case the following wolfcrypt verification api can be used to handle signatures generated with FIPS-204 encoding:

    ```c
    int wc_dilithium_verify_ctx_msg(
        const byte* sig, 
        word32 sigLen,
        const byte* ctx, // Set to NULL (unless additional encoding is required)
        word32 ctxLen,   // Set to 0 (or length of the ctx)
        const byte* msg, 
        word32 msgLen, 
        int* res,
        dilithium_key* key
    );
    ```

### Project Configuration

The `app_config.h` file is used to configure the project. Due to device memory constraints, use caution when enabling more than one configuration at a time. The following options using Dilithium are available:

- ML_DSA_44 
- ML_DSA_65
- ML_DSA_87

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
|ML-DSA type |Verification time (Seconds)|
|------------|------|
|Dilithium 44|0.2963|
|Dilithium 65|0.4870|
|Dilithium 87|0.7263|

### Memory Size Benchmarking
|ML-DSA type|Message Size (bytes)|Signature Size (bytes)|Key Size (bytes)|Flash (bytes)|RAM Static (bytes)|RAM Stack (bytes)|
|---|---|---|---|---|---|---|
|Dilithium 44|4,553|2,420|1,312|18,083|138|964|
|Dilithium 65|7,465|3,309|1,952|20,304|138|964|
|Dilithium 87|4,616|4,627|2,592|19,858|138|964|
