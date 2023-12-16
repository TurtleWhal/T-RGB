#include "ui.h"

#include "Arduino.h"
#include "ArduinoJson.h"
#include "lvgl.h"

lv_obj_t *ui_Main;
lv_obj_t *ui_JSON_Label;
lv_obj_t *ui_CT_Label;
lv_obj_t *ui_CL_Label;
lv_obj_t *ui_GT_Label;
lv_obj_t *ui_GL_Label;

struct
{
    struct
    {
        int temp;
        int load;
    } cpu;
    struct
    {
        int temp;
        int load;
    } gpu;
} hardware;

void ui_begin()
{
    ui_Main = lv_obj_create(NULL);

    lv_obj_t *arc = lv_arc_create(ui_Main);
    lv_obj_set_width(arc, 480);
    lv_obj_set_height(arc, 480);
    lv_obj_set_style_arc_width(arc, 30, LV_PART_MAIN);
    lv_obj_set_style_arc_width(arc, 30, LV_PART_INDICATOR);

    //lv_obj_t *btn = lv_btn_create(ui_Main);
    //lv_obj_align(btn, LV_ALIGN_CENTER, 0, 0);
    //lv_obj_set_height(btn, 50);

    ui_JSON_Label = lv_label_create(ui_Main);
    lv_obj_set_y(ui_JSON_Label, -40);
    lv_obj_set_align(ui_JSON_Label, LV_ALIGN_CENTER);

    ui_CT_Label = lv_label_create(ui_Main);
    lv_obj_set_y(ui_CT_Label, -20);
    lv_obj_set_align(ui_CT_Label, LV_ALIGN_CENTER);

    ui_CL_Label = lv_label_create(ui_Main);
    lv_obj_set_y(ui_CL_Label, 0);
    lv_obj_set_align(ui_CL_Label, LV_ALIGN_CENTER);

    ui_GT_Label = lv_label_create(ui_Main);
    lv_obj_set_y(ui_GT_Label, 20);
    lv_obj_set_align(ui_GT_Label, LV_ALIGN_CENTER);

    ui_GL_Label = lv_label_create(ui_Main);
    lv_obj_set_y(ui_GL_Label, 40);
    lv_obj_set_align(ui_GL_Label, LV_ALIGN_CENTER);

    lv_scr_load(ui_Main);
}

void parseJsonData(String json)
{
    Serial.print("Parsing Json: ");
    Serial.println(json);
    //lv_label_set_text(ui_Main_Label, json.c_str());

    StaticJsonDocument<200> doc;

    DeserializationError error = deserializeJson(doc, json);
    if (error)
    {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        return;
    }

    hardware.cpu.temp = doc["ct"];
    hardware.cpu.load = doc["cl"];
    hardware.gpu.temp = doc["gt"];
    hardware.gpu.load = doc["gl"];

    /*Serial.println("Stats");
    Serial.println(hardware.cpu.temp);
    Serial.println(hardware.cpu.load);
    Serial.println(hardware.gpu.temp);
    Serial.println(hardware.gpu.load);*/

    lv_label_set_text(ui_JSON_Label, json.c_str());
    lv_label_set_text(ui_CT_Label, String(hardware.cpu.temp).c_str());
    lv_label_set_text(ui_CL_Label, String(hardware.cpu.load).c_str());
    lv_label_set_text(ui_GT_Label, String(hardware.gpu.temp).c_str());
    lv_label_set_text(ui_GL_Label, String(hardware.gpu.load).c_str());
}