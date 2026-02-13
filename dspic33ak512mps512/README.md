<picture>
    <source media="(prefers-color-scheme: dark)" srcset="../images/microchip_logo_white_red.png">
	<source media="(prefers-color-scheme: light)" srcset="../images/microchip_logo_black_red.png">
    <img alt="Microchip Logo." src="../images/microchip_logo_black_red.png">
</picture>

# dsPIC33AK512MPS512 Wolfcrypt Demo setup

## Software Used

- dsPIC33AK-MP_DFP v1.2.135
- MPLAB® X IDE **v6.30** (https://www.microchip.com/mplabx)
- MPLAB® XC-DSC Compiler **v3.30** (https://www.microchip.com/xcdsc)

## Hardware Used

- dsPIC33AK512MPS512 Curiosity GP DIM (https://www.microchip.com/EV80L65A)
- Curiosity Platform Development Board (https://www.microchip.com/EV74H48A)

## Set up

### Hardware Set up

1. Insert the dsPIC33AK512MPS512 DIM into the DIM J1 slot on the Curiosity Platform Development Board.
2. Connect the board from the J24 USB-C PKoB4 (PICKit™ On-Board 4) to the computer.

    <img src="../images/hardware_setup.jpg" height="400" alt="Hardware Setup"/>

### Project Set Up

#### wolfCrypt Source

The wolfCrypt files in this project use wolfssl [v5.8.4-commercial](https://github.com/wolfSSL/Microchip/tree/main/wolfssl-5.8.4-commercial) release to support the dsPIC33A device.

API documentation for wolfcrypt files used in the demo can be found at [wolfssl's website](https://www.wolfssl.com/documentation/manuals/wolfssl/group__wolfCrypt.html)

### wolfCrypt Library Set Up

For each demo project the custom user settings is enabled by defining a common macro `WOLFSSL_USER_SETTINGS` within the project properties. 
This allows the wolfCrypt library to be configured by macros specified within the `user_settings.h` file found under the app folder of each demo. 
These files enable specific APIs, device support, and includes additional configuration options. 
More information about the options can be found within the `user_settings.h` file.

## Licensing

The project is governed under the End User License Agreement (EULA) with wolfSSL. The EULA can be found at the root folder of dspic33-wolfCrypt repo. 
