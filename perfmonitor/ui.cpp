#include "ui.h"

#include "Arduino.h"
#include "SD_MMC.h"
#include "lvgl.h"

void ui_begin()
{
    lv_obj_t *cout = lv_obj_create(lv_scr_act());
    lv_obj_set_size(cout, LV_PCT(100), LV_PCT(100));
    lv_obj_set_scroll_dir(cout, LV_DIR_NONE);

    lv_obj_t *btn = lv_btn_create(cout);
    // lv_obj_align_to(btn, touch_status, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
    lv_obj_align(btn, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_height(btn, 50);
    // lv_obj_add_event_cb(
    //     btn, [](lv_event_t *e)
    //     { test_button_press(); },
    //     LV_EVENT_CLICKED, NULL);

    lv_obj_t *testbtn_label = lv_label_create(btn);
    lv_obj_center(testbtn_label);
    lv_label_set_text(testbtn_label, "Test");

    Serial.println("Ui Loaded");
}