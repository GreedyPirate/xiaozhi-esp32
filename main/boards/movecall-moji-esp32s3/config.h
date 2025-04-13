#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

// Movecall Moji configuration

#include <driver/gpio.h>

#define AUDIO_INPUT_SAMPLE_RATE  24000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

/**
 *  ESP32-S3 GPIO               | ES8311 引脚名   | ES8311 引脚号  | 功能说明
    -------------------------------------------------------------------------------
    AUDIO_I2S_GPIO_MCLK (GPIO6) | MCLK            | 2             | 主时钟输入（ES8311从模式需外部提供）
    AUDIO_I2S_GPIO_WS (GPIO12)  | LRCK            | 8             | 帧同步信号（左右声道标识）
    AUDIO_I2S_GPIO_BCLK (GPIO14)| SCLK/DMIC_SCL   | 6             | 位时钟信号
    AUDIO_I2S_GPIO_DOUT (GPIO11)| DSDIN           | 9             | DAC数据输入（ESP32发送音频到ES8311）
    AUDIO_I2S_GPIO_DIN (GPIO13) | ASDOUT          | 7             | ADC数据输出（ES8311发送音频到ESP32）
    AUDIO_CODEC_I2C_SDA_PIN     | CDATA           | 19            | I2C数据线
    (GPIO5)
    AUDIO_CODEC_I2C_SCL_PIN     | CCLK            | 1             | I2C时钟线
    (GPIO4)
    AUDIO_CODEC_PA_PIN (GPIO9)  | 外部功放使能引脚| -               | 控制外部功放模块的使能（非ES8311功能）
 */

#define AUDIO_I2S_GPIO_MCLK GPIO_NUM_6
#define AUDIO_I2S_GPIO_WS GPIO_NUM_12
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_14
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_13
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_11

#define AUDIO_CODEC_PA_PIN       GPIO_NUM_9
#define AUDIO_CODEC_I2C_SDA_PIN  GPIO_NUM_5
#define AUDIO_CODEC_I2C_SCL_PIN  GPIO_NUM_4
#define AUDIO_CODEC_ES8311_ADDR  ES8311_CODEC_DEFAULT_ADDR

#define BUILTIN_LED_GPIO        GPIO_NUM_21
#define BOOT_BUTTON_GPIO        GPIO_NUM_0

#define DISPLAY_WIDTH   240
#define DISPLAY_HEIGHT  240
#define DISPLAY_MIRROR_X true
#define DISPLAY_MIRROR_Y false
#define DISPLAY_SWAP_XY false

#define DISPLAY_OFFSET_X  0
#define DISPLAY_OFFSET_Y  0

#define DISPLAY_BACKLIGHT_PIN GPIO_NUM_3
#define DISPLAY_BACKLIGHT_OUTPUT_INVERT false

#define DISPLAY_SPI_SCLK_PIN    GPIO_NUM_16
#define DISPLAY_SPI_MOSI_PIN    GPIO_NUM_17
#define DISPLAY_SPI_CS_PIN      GPIO_NUM_15
#define DISPLAY_SPI_DC_PIN      GPIO_NUM_7
#define DISPLAY_SPI_RESET_PIN   GPIO_NUM_18

#define DISPLAY_SPI_SCLK_HZ     (40 * 1000 * 1000)

#endif // _BOARD_CONFIG_H_
