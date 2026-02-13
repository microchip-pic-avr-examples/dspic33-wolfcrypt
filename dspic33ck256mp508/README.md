<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../images/microchip_logo_black_red.png">
</picture>

# dsPIC33CK256MP508 Wolfcrypt Demo setup

## Software Used 

- dsPIC33CK-MP_DFP **1.15.423**
- MPLAB® X IDE **v6.30** (https://www.microchip.com/mplabx)
- MPLAB® XC-DSC Compiler **v3.30** (https://www.microchip.com/xcdsc)

## Hardware Used

- dsPIC33CK Curiosity Development Board (https://www.microchip.com/dm330030)
    - This development board has a built-in dsPIC33CK256MP508 High-Performance DSC (https://www.microchip.com/dspic33ck256mp508)

## Set up

### Hardware Set up

1. Connect the board to the computer using a USB cable, connecting to the PICkit™ On-Board (PKOB) programmer/debugger.

    <img src="../images/hardware_setup_curiosity.jpg" height="400" alt="Hardware Setup"/>

### wolfCrypt Source

The wolfCrypt files in this project use wolfssl [v5.8.4-commercial](https://github.com/wolfSSL/Microchip/tree/main/wolfssl-5.8.4-commercial) release to support the dsPIC33C device.

API documentation for wolfcrypt files used in the demo can be found at [wolfssl's website](https://www.wolfssl.com/documentation/manuals/wolfssl/group__wolfCrypt.html)

### wolfCrypt Library Set Up

For each demo project the custom user settings is enabled by defining a common macro `WOLFSSL_USER_SETTINGS` within the project properties. 
This allows the wolfCrypt library to be configured by macros specified within the `user_settings.h` file found under the app folder of each demo. 
These files enable specific APIs, device support, and includes additional configuration options. 
More information about the options can be found within the `user_settings.h` file.

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found at the root folder of dspic33-wolfCrypt repo. 
