#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_home_page_setv_text_label(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_home_page_seta_text_label(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_home_page_outv_text_label(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_home_page_outa_text_label(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_home_page_outc_num_label(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_home_page_outv_num_label(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_home_page_setv_spinbox(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_spinbox_get_step(ta);
            if (tick_value_change_obj != ta) {
                assignIntegerProperty(flowState, 9, 4, value, "Failed to assign Step in Spinbox widget");
            }
        }
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_spinbox_get_value(ta);
            if (tick_value_change_obj != ta) {
                assignIntegerProperty(flowState, 9, 5, value, "Failed to assign Value in Spinbox widget");
            }
        }
    }
}

static void event_handler_cb_home_page_seta_spinbox(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_spinbox_get_step(ta);
            if (tick_value_change_obj != ta) {
                assignIntegerProperty(flowState, 10, 5, value, "Failed to assign Step in Spinbox widget");
            }
        }
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_spinbox_get_value(ta);
            if (tick_value_change_obj != ta) {
                assignIntegerProperty(flowState, 10, 6, value, "Failed to assign Value in Spinbox widget");
            }
        }
    }
}

static void event_handler_cb_home_page_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_home_page_obj1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_home_page_obj2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

static void event_handler_cb_home_page_obj3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
}

void create_screen_home_page() {
    void *flowState = getFlowState(0, 0);
    lv_obj_t *obj = lv_obj_create(0);
    objects.home_page = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // setv_text_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.setv_text_label = obj;
            lv_obj_set_pos(obj, 89, 82);
            lv_obj_set_size(obj, 15, 15);
            lv_label_set_text(obj, "V");
            lv_obj_add_event_cb(obj, event_handler_cb_home_page_setv_text_label, LV_EVENT_ALL, flowState);
            add_style_home_set_text_label_style(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff3b30), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // seta_text_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.seta_text_label = obj;
            lv_obj_set_pos(obj, 89, 112);
            lv_obj_set_size(obj, 15, 15);
            lv_label_set_text(obj, "A");
            lv_obj_add_event_cb(obj, event_handler_cb_home_page_seta_text_label, LV_EVENT_ALL, flowState);
            add_style_home_set_text_label_style(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff34c759), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // outv_text_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.outv_text_label = obj;
            lv_obj_set_pos(obj, 284, 90);
            lv_obj_set_size(obj, 28, 28);
            lv_label_set_text(obj, "V");
            lv_obj_add_event_cb(obj, event_handler_cb_home_page_outv_text_label, LV_EVENT_ALL, flowState);
            add_style_home_out_text_label_style(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff3b30), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // outa_text_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.outa_text_label = obj;
            lv_obj_set_pos(obj, 284, 155);
            lv_obj_set_size(obj, 28, 28);
            lv_label_set_text(obj, "A");
            lv_obj_add_event_cb(obj, event_handler_cb_home_page_outa_text_label, LV_EVENT_ALL, flowState);
            add_style_home_out_text_label_style(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff34c759), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // outc_num_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.outc_num_label = obj;
            lv_obj_set_pos(obj, 120, 140);
            lv_obj_set_size(obj, 160, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_add_event_cb(obj, event_handler_cb_home_page_outc_num_label, LV_EVENT_ALL, flowState);
            add_style_home_out_num_label_style(obj);
        }
        {
            // outv_num_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.outv_num_label = obj;
            lv_obj_set_pos(obj, 120, 73);
            lv_obj_set_size(obj, 160, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_add_event_cb(obj, event_handler_cb_home_page_outv_num_label, LV_EVENT_ALL, flowState);
            add_style_home_out_num_label_style(obj);
        }
        {
            // vin_text_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.vin_text_label = obj;
            lv_obj_set_pos(obj, 202, 4);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            add_style_home_bar_label_style(obj);
        }
        {
            // vin_text_label_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.vin_text_label_1 = obj;
            lv_obj_set_pos(obj, 263, 4);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            add_style_home_bar_label_style(obj);
        }
        {
            // setv_spinbox
            lv_obj_t *obj = lv_spinbox_create(parent_obj);
            objects.setv_spinbox = obj;
            lv_obj_set_pos(obj, 8, 65);
            lv_obj_set_size(obj, 81, 38);
            lv_spinbox_set_digit_format(obj, 5, 2);
            lv_spinbox_set_range(obj, 0, 30000);
            lv_spinbox_set_rollover(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_home_page_setv_spinbox, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            add_style_home_set_volt_spinbox(obj);
        }
        {
            // seta_spinbox
            lv_obj_t *obj = lv_spinbox_create(parent_obj);
            objects.seta_spinbox = obj;
            lv_obj_set_pos(obj, 8, 95);
            lv_obj_set_size(obj, 81, 38);
            lv_spinbox_set_digit_format(obj, 5, 2);
            lv_spinbox_set_range(obj, 0, 5000);
            lv_spinbox_set_rollover(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_home_page_seta_spinbox, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            add_style_home_set_curr_spinbox(obj);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 120, 44);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "OUTPUT");
            add_style_home_out_title_style(obj);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 40, 20);
            lv_label_set_text(obj, "");
            lv_obj_add_event_cb(obj, event_handler_cb_home_page_obj0, LV_EVENT_ALL, flowState);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_roboto_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff34c759), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff3b30), LV_PART_MAIN | LV_STATE_DISABLED);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 50, 0);
            lv_obj_set_size(obj, 40, 20);
            lv_label_set_text(obj, "");
            lv_obj_add_event_cb(obj, event_handler_cb_home_page_obj1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_roboto_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff34c759), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff3b30), LV_PART_MAIN | LV_STATE_DISABLED);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 8, 44);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "SET");
            add_style_home_out_title_style(obj);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_t line_points[] = {
                { 0, 0 },
                { 0, 130 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_pos(obj, 111, 49);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 120, 123);
            lv_obj_set_size(obj, 160, 4);
            lv_obj_add_event_cb(obj, event_handler_cb_home_page_obj2, LV_EVENT_ALL, flowState);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff3b30), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff3b30), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 120, 190);
            lv_obj_set_size(obj, 160, 4);
            lv_obj_add_event_cb(obj, event_handler_cb_home_page_obj3, LV_EVENT_ALL, flowState);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff34c759), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff34c759), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff34c759), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_home_page() {
    void *flowState = getFlowState(0, 0);
    {
        bool new_val = evalBooleanProperty(flowState, 0, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.setv_text_label, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.setv_text_label;
            if (new_val) lv_obj_add_state(objects.setv_text_label, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.setv_text_label, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 2, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.seta_text_label, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.seta_text_label;
            if (new_val) lv_obj_add_state(objects.seta_text_label, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.seta_text_label, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 3, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.outv_text_label, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.outv_text_label;
            if (new_val) lv_obj_add_state(objects.outv_text_label, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.outv_text_label, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 4, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.outa_text_label, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.outa_text_label;
            if (new_val) lv_obj_add_state(objects.outa_text_label, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.outa_text_label, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 5, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.outc_num_label, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.outc_num_label;
            if (new_val) lv_obj_add_state(objects.outc_num_label, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.outc_num_label, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 5, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.outc_num_label);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.outc_num_label;
            lv_label_set_text(objects.outc_num_label, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 6, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.outv_num_label, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.outv_num_label;
            if (new_val) lv_obj_add_state(objects.outv_num_label, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.outv_num_label, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 6, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.outv_num_label);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.outv_num_label;
            lv_label_set_text(objects.outv_num_label, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 7, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.vin_text_label);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.vin_text_label;
            lv_label_set_text(objects.vin_text_label, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 8, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.vin_text_label_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.vin_text_label_1;
            lv_label_set_text(objects.vin_text_label_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 9, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.setv_spinbox, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.setv_spinbox;
            if (new_val) lv_obj_add_state(objects.setv_spinbox, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.setv_spinbox, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 9, 4, "Failed to evaluate Step in Spinbox widget");
        int32_t cur_val = lv_spinbox_get_step(objects.setv_spinbox);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.setv_spinbox;
            lv_spinbox_set_step(objects.setv_spinbox, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 9, 5, "Failed to evaluate Value in Spinbox widget");
        int32_t cur_val = lv_spinbox_get_value(objects.setv_spinbox);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.setv_spinbox;
            lv_spinbox_set_value(objects.setv_spinbox, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 10, 4, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.seta_spinbox, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.seta_spinbox;
            if (new_val) lv_obj_add_state(objects.seta_spinbox, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.seta_spinbox, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 10, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.seta_spinbox, LV_OBJ_FLAG_CLICKABLE);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.seta_spinbox;
            if (new_val) lv_obj_add_flag(objects.seta_spinbox, LV_OBJ_FLAG_CLICKABLE);
            else lv_obj_clear_flag(objects.seta_spinbox, LV_OBJ_FLAG_CLICKABLE);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 10, 5, "Failed to evaluate Step in Spinbox widget");
        int32_t cur_val = lv_spinbox_get_step(objects.seta_spinbox);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.seta_spinbox;
            lv_spinbox_set_step(objects.seta_spinbox, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 10, 6, "Failed to evaluate Value in Spinbox widget");
        int32_t cur_val = lv_spinbox_get_value(objects.seta_spinbox);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.seta_spinbox;
            lv_spinbox_set_value(objects.seta_spinbox, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 12, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj0, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj0;
            if (new_val) lv_obj_add_state(objects.obj0, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj0, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj0);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj0;
            lv_label_set_text(objects.obj0, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 13, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(objects.obj1, LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj1;
            if (new_val) lv_obj_add_state(objects.obj1, LV_STATE_DISABLED);
            else lv_obj_clear_state(objects.obj1, LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 13, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj1;
            lv_label_set_text(objects.obj1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 16, 3, "Failed to evaluate Value in Bar widget");
        int32_t cur_val = lv_bar_get_value(objects.obj2);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj2;
            lv_bar_set_value(objects.obj2, new_val, LV_ANIM_ON);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 17, 3, "Failed to evaluate Value in Bar widget");
        int32_t cur_val = lv_bar_get_value(objects.obj3);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj3;
            lv_bar_set_value(objects.obj3, new_val, LV_ANIM_ON);
            tick_value_change_obj = NULL;
        }
    }
}

void create_user_widget_my_spin_box(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
    }
}

void tick_user_widget_my_spin_box(void *flowState, int startWidgetIndex) {
}


extern void add_style(lv_obj_t *obj, int32_t styleIndex);
extern void remove_style(lv_obj_t *obj, int32_t styleIndex);

static const char *screen_names[] = { "home_page", "my_spin_box" };
static const char *object_names[] = { "home_page", "obj0", "obj1", "obj2", "obj3", "outa_text_label", "outc_num_label", "outv_num_label", "outv_text_label", "seta_spinbox", "seta_text_label", "setv_spinbox", "setv_text_label", "vin_text_label", "vin_text_label_1" };
static const char *style_names[] = { "home_set_num_label_style", "home_out_num_label_style", "home_bar_num_style", "home_bar_label_style", "home_set_text_label_style", "home_out_text_label_style", "home_set_volt_spinbox", "home_set_curr_spinbox", "home_out_title_style" };

void create_screens() {
    eez_flow_init_styles(add_style, remove_style);
    
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    eez_flow_init_style_names(style_names, sizeof(style_names) / sizeof(const char *));
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_home_page();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_home_page,
    0,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
