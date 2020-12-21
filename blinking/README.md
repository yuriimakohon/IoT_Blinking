# IoT Ajax - Bkinking

Firmware for [LAUNCHXL-CC1352R1](https://www.ti.com/tool/LAUNCHXL-CC1352R1) whith diode blinking

## Description

This firmware intended for LAUNCHXL-CC1352R1 board.  
After connecting power board will toggle imbedded red diod  
with random interval from 1 to 10 seconds.

## BoosterPacks, Board Resources & Jumper Settings

For board specific jumper settings, resources and BoosterPack modifications,
refer to the __Board.html__ file.

> If you're using an IDE such as Code Composer Studio (CCS) or IAR, please  
refer to Board.html in your project directory for resources used and  
board-specific jumper settings.  

The Board.html can also be found in your SDK installation:

        <SDK_INSTALL_DIR>/source/ti/boards/<BOARD>

## Realization

In thread mainThread() initializes **TRNG** to generating random __seed__ for __**srand()**__.  
Use __**GPIO_toggle()**__ function for **CONFIG_GPIO_LED_0**.  
See also: [TRNG](https://software-dl.ti.com/simplelink/esd/simplelink_cc13x2_26x2_sdk/3.40.00.02/exports/docs/tidrivers/doxygen/html/_t_r_n_g_8h.html)

![LED](https://github.com/yuriimakohon/IoT_Blinking/blob/master/photo5406952514282172597.jpg)
