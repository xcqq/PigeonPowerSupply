#include "setting_item.h"
#include "../../styles.h"
#include "eez-project/images.h"

void BoolSettingItem::setting_item_event_cb(lv_event_t *e)
{
    bool current_value = getValue();
    current_value = !current_value;
    setValue(current_value);
    if (current_value) {
        lv_obj_add_state(btn_switch, LV_STATE_CHECKED);
    } else {
        lv_obj_clear_state(btn_switch, LV_STATE_CHECKED);
    }
}

lv_obj_t *BoolSettingItem::render(lv_obj_t *parent)
{
    obj = lv_list_add_btn(parent, NULL, NULL);
    lv_obj_set_user_data(obj, this);
    lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_ROW);
    lv_obj_set_height(obj, 60);
    lv_obj_set_flex_align(obj, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    // symbol icon
    lv_obj_t *icon = lv_label_create(obj);
    lv_label_set_text(icon, "");
    lv_obj_set_flex_grow(icon, 2);
    // label
    lv_obj_t *label = lv_label_create(obj);
    lv_label_set_text(label, title);
    lv_obj_set_flex_grow(label, 8);
    // switch
    btn_switch = lv_switch_create(obj);
    lv_obj_set_flex_grow(btn_switch, 3);
    lv_obj_set_height(btn_switch, 32);
    lv_obj_set_width(btn_switch, 40);
    add_style_setting_list_switch_style(btn_switch);
    // place holder
    lv_obj_t *place_holder = lv_label_create(obj);
    lv_label_set_text(place_holder, "");
    lv_obj_set_height(place_holder, 16);
    lv_obj_set_width(place_holder, 16);


    lv_obj_add_event_cb(
        obj,
        [](lv_event_t *e) {
            auto item = (BoolSettingItem *)lv_event_get_user_data(e);
            item->setting_item_event_cb(e);
            if (item->callback) {
                item->callback(item, item->io);
            }
        },
        LV_EVENT_KEY, this);
    if (getValue()) {
        lv_obj_add_state(btn_switch, LV_STATE_CHECKED);
    } else {
        lv_obj_clear_state(btn_switch, LV_STATE_CHECKED);
    }
    lv_obj_set_user_data(obj, this);
    return obj;
}

void IntSettingItem::setting_item_event_cb(lv_event_t *e)
{
    if (e == nullptr) {
        return;
    }
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_KEY) {
        int current_value = getValue();
        lv_key_t key = lv_event_get_key(e);
        int new_value;
        switch (key) {
        case LV_KEY_UP:
            new_value = current_value + step;
            if (new_value <= max) {
                setValue(new_value);
                lv_spinbox_set_value(value_spinbox, new_value);
            }
            break;
        case LV_KEY_DOWN:
            new_value = current_value - step;
            if (new_value >= min) {
                setValue(new_value);
                lv_spinbox_set_value(value_spinbox, new_value);
            }
            break;
        case LV_KEY_ENTER:
            if (step == max - min) {
                step = 1;
            } else {
                step = max - min;
            }
            lv_spinbox_set_step(value_spinbox, step);
            break;
        }
    }
}

lv_obj_t *IntSettingItem::render(lv_obj_t *parent)
{
    obj = lv_list_add_btn(parent, NULL, NULL);
    lv_obj_set_user_data(obj, this);
    lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_ROW);
    lv_obj_set_height(obj, 60);
    lv_obj_set_flex_align(obj, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    // symbol icon
    lv_obj_t *icon = lv_label_create(obj);
    lv_label_set_text(icon, "");
    lv_obj_set_flex_grow(icon, 2);
    // label
    lv_obj_t *label = lv_label_create(obj);
    lv_label_set_text(label, title);
    lv_obj_set_flex_grow(label, 8);
    // spinbox
    value_spinbox = lv_spinbox_create(obj);
    lv_spinbox_set_range(value_spinbox, min, max);
    lv_spinbox_set_step(value_spinbox, step);
    int digit_count = 1;
    int max_abs = abs(max);
    int min_abs = abs(min);
    int largest = max_abs > min_abs ? max_abs : min_abs;
    while (largest >= 10) {
        largest /= 10;
        digit_count++;
    }
    lv_spinbox_set_digit_format(value_spinbox, digit_count, 0);
    lv_spinbox_set_value(value_spinbox, getValue());
    lv_obj_set_height(value_spinbox, 32);
    lv_obj_set_width(value_spinbox, 60);
    add_style_setting_spinbox_style(value_spinbox);
    // up down icon
    lv_obj_t *up_down_icon = lv_img_create(obj);
    lv_img_set_src(up_down_icon, &img_pic_up_down_light);
    lv_obj_set_height(up_down_icon,16);
    lv_obj_set_width(up_down_icon, 16);

    lv_obj_add_event_cb(
        obj,
        [](lv_event_t *e) {
            auto item = (IntSettingItem *)lv_event_get_user_data(e);
            item->setting_item_event_cb(e);
            if (item->callback) {
                item->callback(item, item->io);
            }
        },
        LV_EVENT_KEY, this);

    return obj;
}

void FloatSettingItem::setting_item_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_KEY) {
        float current_value = getValue();
        lv_key_t key = lv_event_get_key(e);

        if (key == LV_KEY_UP) {
            float new_value = roundf((current_value + step) * 10) / 10;
            if (new_value <= max) {
                setValue(new_value);
                lv_spinbox_set_value(value_spinbox, new_value * 10);
            }
        } else if (key == LV_KEY_DOWN) {
            float new_value = roundf((current_value - step) * 10) / 10;
            if (new_value >= min) {
                setValue(new_value);
                lv_spinbox_set_value(value_spinbox, new_value * 10);
            }
        }
    }
}

lv_obj_t *FloatSettingItem::render(lv_obj_t *parent)
{
    obj = lv_list_add_btn(parent, NULL, NULL);
    lv_obj_set_user_data(obj, this);

    lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_ROW);
    lv_obj_set_height(obj, 60);
    lv_obj_set_flex_align(obj, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    // symbol icon
    lv_obj_t *icon = lv_label_create(obj);
    lv_label_set_text(icon, "");
    lv_obj_set_flex_grow(icon, 2);
    // label
    lv_obj_t *label = lv_label_create(obj);
    lv_label_set_text(label, title);
    lv_obj_set_flex_grow(label, 8);
    // spinbox
    value_spinbox = lv_spinbox_create(obj);
    lv_spinbox_set_range(value_spinbox, min * 10, max * 10);
    lv_spinbox_set_step(value_spinbox, step * 10);
    lv_spinbox_set_digit_format(value_spinbox, 3, 2);
    lv_spinbox_set_value(value_spinbox, getValue() * 10);
    lv_obj_set_height(value_spinbox, 32);
    lv_obj_set_width(value_spinbox, 60);
    add_style_setting_spinbox_style(value_spinbox);
    // up down icon
    lv_obj_t *up_down_icon = lv_img_create(obj);
    lv_img_set_src(up_down_icon, &img_pic_up_down_light);
    lv_obj_set_height(up_down_icon,16);
    lv_obj_set_width(up_down_icon, 16);

    lv_obj_add_event_cb(
        obj,
        [](lv_event_t *e) {
            auto item = (FloatSettingItem *)lv_event_get_user_data(e);
            item->setting_item_event_cb(e);
            if (item->callback) {
                item->callback(item, item->io);
            }
        },
        LV_EVENT_KEY, this);

    return obj;
}

vector<string> ListSettingItem::get_config_options() const
{
    vector<string> result;
    JsonArray options_array = json_config["options"].as<JsonArray>();
    for (JsonVariant value : options_array) {
        result.push_back(value.as<string>());
    }
    return result;
}

string ListSettingItem::getValue() const { return json_config["value"].as<string>(); }

void ListSettingItem::setValue(const string &value) const { json_config["value"].set(value); }

void ListSettingItem::setting_item_event_cb(lv_event_t *e)
{
    if (e == nullptr) {
        return;
    }
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_KEY) {
        lv_key_t key = lv_event_get_key(e);
        switch (key) {
        case LV_KEY_DOWN:
            if (lv_roller_get_selected(value_dropdown) < options.size() - 1) {
                lv_roller_set_selected(value_dropdown, lv_roller_get_selected(value_dropdown) + 1,
                                       LV_ANIM_ON);
                setValue(options[lv_roller_get_selected(value_dropdown)]);
            }
            break;
        case LV_KEY_UP:
            if (lv_roller_get_selected(value_dropdown) > 0) {
                lv_roller_set_selected(value_dropdown, lv_roller_get_selected(value_dropdown) - 1,
                                       LV_ANIM_ON);
                setValue(options[lv_roller_get_selected(value_dropdown)]);
            }
            break;
        }
    }
}

lv_obj_t *ListSettingItem::render(lv_obj_t *parent)
{
    obj = lv_list_add_btn(parent, NULL, NULL);
    lv_obj_set_user_data(obj, this);
    lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_ROW);
    lv_obj_set_height(obj, 60);
    lv_obj_set_flex_align(obj, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    // symbol icon
    lv_obj_t *icon = lv_label_create(obj);
    lv_label_set_text(icon, "");
    lv_obj_set_flex_grow(icon, 2);
    // label
    lv_obj_t *label = lv_label_create(obj);
    lv_label_set_text(label, title);
    lv_obj_set_flex_grow(label, 8);
    // value
    value_dropdown = lv_roller_create(obj);
    add_style_setting_list_roller_style(value_dropdown);
    // up down icon
    lv_obj_t *up_down_icon = lv_img_create(obj);
    lv_img_set_src(up_down_icon, &img_pic_up_down_light);
    lv_obj_set_height(up_down_icon,16);
    lv_obj_set_width(up_down_icon, 16);
    string options_str;
    for (size_t i = 0; i < options.size(); i++) {
        options_str += options[i];
        if (i < options.size() - 1) {
            options_str += "\n";
        }
    }
    if (options_str.empty()) {
        options_str = "No options";
    }
    lv_roller_set_options(value_dropdown, options_str.c_str(), LV_ROLLER_MODE_NORMAL);
    lv_obj_set_height(value_dropdown, 32);
    lv_obj_set_width(value_dropdown, 60);
    string current_value = getValue();
    for (size_t i = 0; i < options.size(); i++) {
        if (options[i] == current_value) {
            lv_roller_set_selected(value_dropdown, i, LV_ANIM_OFF);
            break;
        }
    }

    lv_obj_add_event_cb(
        obj,
        [](lv_event_t *e) {
            auto item = (ListSettingItem *)lv_event_get_user_data(e);
            item->setting_item_event_cb(e);
            if (item->callback) {
                item->callback(item, item->io);
            }
        },
        LV_EVENT_KEY, this);

    return obj;
}
