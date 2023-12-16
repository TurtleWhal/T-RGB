#pragma once

#define MSG_BAT_VOLT_UPDATE 1
#define MSG_TOUCH_UPDATE 2
#define MSG_WIFI_UPDATE 3
#define MSG_TOUCH_INT_UPDATE 4

#define FT5x06_ADDR 0x38
#define CST820_ADDR 0x15
#define GT911_ADDR 0x5A

#include "stdint.h"
#include "lvgl.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        uint16_t x;
        uint16_t y;
    } touch_point_t;

    const char *getTouchAddr();

    void ui_begin();

    void ui_Main_screen_init(void);
    extern lv_obj_t *ui_Main;
    extern lv_obj_t *ui_Main_Label;

#ifdef __cplusplus
}
#endif