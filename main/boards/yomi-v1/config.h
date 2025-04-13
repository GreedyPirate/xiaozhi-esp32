#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

#define AUDIO_I2S_MIC_GPIO_WS       GPIO_NUM_4
#define AUDIO_I2S_MIC_GPIO_SCK      GPIO_NUM_5
#define AUDIO_I2S_MIC_GPIO_DIN      GPIO_NUM_6
#define AUDIO_I2S_SPK_GPIO_DOUT     GPIO_NUM_7
#define AUDIO_I2S_SPK_GPIO_BCLK     GPIO_NUM_15
#define AUDIO_I2S_SPK_GPIO_LRCK     GPIO_NUM_16

#define BOOT_BUTTON_GPIO        GPIO_NUM_0

#define QSPI_LCD_H_RES           (360)
#define QSPI_LCD_V_RES           (360)
#define QSPI_LCD_BIT_PER_PIXEL   (16)

#define DISPLAY_MIRROR_X    false
#define DISPLAY_MIRROR_Y    false
#define DISPLAY_SWAP_XY     false

/*

显示屏引脚	功能	ESP32-S3 GPIO	注意事项
11 (SCK)	串行时钟	GPIO_NUM_21	QSPI时钟信号，需匹配SPI主机频率（如代码中配置为3MHz）
13 (CS)	片选信号	    GPIO_NUM_41	低电平有效，代码中已正确配置
14 (DC)	指令/数据选择	GPIO_NUM_NC	QSPI模式下需禁用（手册要求接地）
10 (SDA0)	QSPI数据线0	GPIO_NUM_47	QSPI数据线需配置为4线模式（代码中已启用.quad_mode = 1）
7 (SDA1)	QSPI数据线1	GPIO_NUM_48	
8 (SDA2)	QSPI数据线2	GPIO_NUM_45	
9 (SDA3)	QSPI数据线3	GPIO_NUM_35	
12 (RESET)	复位信号	GPIO_NUM_NC（未连接）	代码中未使用复位引脚，需确保显示屏硬件复位已处理（如通过上电自动复位）
2. 电源与背光连接
显示屏引脚	功能	ESP32-S3连接	注意事项
3 (GND)	电源地	ESP32的GND引脚	确保共地
4 (VCI)	电源正极（3.3V）	ESP32的3.3V输出	直接连接，避免电压波动
2 (LEDA)	背光阳极	GPIO_NUM_42	代码中通过此引脚控制背光，需串联5.1Ω限流电阻（手册第11页要求）
*/
#define QSPI_LCD_HOST           SPI2_HOST
#define QSPI_PIN_NUM_LCD_PCLK   GPIO_NUM_21
#define QSPI_PIN_NUM_LCD_CS     GPIO_NUM_41
#define QSPI_PIN_NUM_LCD_DATA0  GPIO_NUM_8
#define QSPI_PIN_NUM_LCD_DATA1  GPIO_NUM_9
#define QSPI_PIN_NUM_LCD_DATA2  GPIO_NUM_10
#define QSPI_PIN_NUM_LCD_DATA3  GPIO_NUM_7
#define QSPI_PIN_NUM_LCD_RST    GPIO_NUM_40
#define DISPLAY_BACKLIGHT_PIN   GPIO_NUM_NC

#define YOMI_QSPI_BUS_CONFIG(sclk, d0, d1, d2, d3, max_trans_sz)                  \
    {                                                                             \
        .data0_io_num = d0,                                                       \
        .data1_io_num = d1,                                                       \
        .sclk_io_num = sclk,                                                      \
        .data2_io_num = d2,                                                       \
        .data3_io_num = d3,                                                       \
        .max_transfer_sz = max_trans_sz,                                          \
    }

#define DISPLAY_OFFSET_X  0
#define DISPLAY_OFFSET_Y  0

#define DISPLAY_BACKLIGHT_OUTPUT_INVERT false

#endif // _BOARD_CONFIG_H_

