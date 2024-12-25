#include "setting_item.h"
#include "../../styles.h"

void BoolSettingItem::setting_item_event_cb(lv_event_t *e)
{
    bool current_value = getValue();
    Serial.println("Current value: " + String(current_value));
    current_value = !current_value;
    setValue(current_value);
    Serial.println("New value: " + String(current_value));
    if (current_value) {
        lv_obj_add_state(btn_switch, LV_STATE_CHECKED);
    } else {
        lv_obj_clear_state(btn_switch, LV_STATE_CHECKED);
    }
}

lv_obj_t *BoolSettingItem::render(lv_obj_t *parent)
{
    btn = lv_list_add_btn(parent, NULL, NULL);
    lv_obj_set_user_data(btn, this);
    lv_obj_set_flex_flow(btn, LV_FLEX_FLOW_ROW);
    lv_obj_set_height(btn, 60);
    lv_obj_set_flex_align(btn, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    // symbol icon
    lv_obj_t *icon = lv_label_create(btn);
    lv_label_set_text(icon, "");
    lv_obj_set_flex_grow(icon, 2);
    // label
    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, title);
    lv_obj_set_flex_grow(label, 8);
    // switch
    btn_switch = lv_switch_create(btn);
    lv_obj_set_flex_grow(btn_switch, 3);
    lv_obj_set_height(btn_switch, 26);

    lv_obj_add_event_cb(
        btn,
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
    lv_obj_set_user_data(btn, this);
    return btn;
}

void IntSettingItem::setting_item_event_cb(lv_event_t *e)
{
    if (e == nullptr) {
        Serial.println("Event is null");
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
    btn = lv_list_add_btn(parent, NULL, NULL);
    lv_obj_set_user_data(btn, this);
    lv_obj_set_flex_flow(btn, LV_FLEX_FLOW_ROW);
    lv_obj_set_height(btn, 60);
    lv_obj_set_flex_align(btn, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    // symbol icon
    lv_obj_t *icon = lv_label_create(btn);
    lv_label_set_text(icon, "");
    lv_obj_set_flex_grow(icon, 2);
    // label
    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, title);
    lv_obj_set_flex_grow(label, 8);
    // spinbox
    value_spinbox = lv_spinbox_create(btn);
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
    lv_obj_set_flex_grow(value_spinbox, 3);
    add_style_setting_spinbox_style(value_spinbox);

    lv_obj_add_event_cb(
        btn,
        [](lv_event_t *e) {
            auto item = (IntSettingItem *)lv_event_get_user_data(e);
            item->setting_item_event_cb(e);
            if (item->callback) {
                item->callback(item, item->io);
            }
        },
        LV_EVENT_KEY, this);

    return btn;
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
    btn = lv_list_add_btn(parent, NULL, NULL);
    lv_obj_set_user_data(btn, this);

    lv_obj_set_flex_flow(btn, LV_FLEX_FLOW_ROW);
    lv_obj_set_height(btn, 60);
    lv_obj_set_flex_align(btn, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    // symbol icon
    lv_obj_t *icon = lv_label_create(btn);
    lv_label_set_text(icon, "");
    lv_obj_set_flex_grow(icon, 2);
    // label
    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, title);
    lv_obj_set_flex_grow(label, 8);
    // spinbox
    value_spinbox = lv_spinbox_create(btn);
    lv_spinbox_set_range(value_spinbox, min * 10, max * 10);
    lv_spinbox_set_step(value_spinbox, step * 10);
    lv_spinbox_set_digit_format(value_spinbox, 3, 2);
    lv_spinbox_set_value(value_spinbox, getValue() * 10);
    lv_obj_set_height(value_spinbox, 32);
    lv_obj_set_flex_grow(value_spinbox, 4);
    add_style_setting_spinbox_style(value_spinbox);

    lv_obj_add_event_cb(
        btn,
        [](lv_event_t *e) {
            auto item = (FloatSettingItem *)lv_event_get_user_data(e);
            item->setting_item_event_cb(e);
            if (item->callback) {
                item->callback(item, item->io);
            }
        },
        LV_EVENT_KEY, this);

    return btn;
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
        Serial.println("Event is null");
        return;
    }
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_KEY) {
        lv_key_t key = lv_event_get_key(e);
        Serial.println("Key: " + String(key));
        switch (key) {
        case LV_KEY_UP:
            if (lv_roller_get_selected(value_dropdown) < options.size() - 1) {
                lv_roller_set_selected(value_dropdown, lv_roller_get_selected(value_dropdown) + 1,
                                       LV_ANIM_ON);
            }
            break;
        case LV_KEY_DOWN:
            if (lv_roller_get_selected(value_dropdown) > 0) {
                lv_roller_set_selected(value_dropdown, lv_roller_get_selected(value_dropdown) - 1,
                                       LV_ANIM_ON);
            }
            break;
        }
    }
}

lv_obj_t *ListSettingItem::render(lv_obj_t *parent)
{
    btn = lv_list_add_btn(parent, NULL, NULL);
    lv_obj_set_user_data(btn, this);
    lv_obj_set_flex_flow(btn, LV_FLEX_FLOW_ROW);
    lv_obj_set_height(btn, 60);
    lv_obj_set_flex_align(btn, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    // symbol icon
    lv_obj_t *icon = lv_label_create(btn);
    lv_label_set_text(icon, "");
    lv_obj_set_flex_grow(icon, 2);
    // label
    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, title);
    lv_obj_set_flex_grow(label, 8);
    // value
    value_dropdown = lv_roller_create(btn);
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
    lv_obj_set_flex_grow(value_dropdown, 3);
    string current_value = getValue();
    for (size_t i = 0; i < options.size(); i++) {
        if (options[i] == current_value) {
            lv_roller_set_selected(value_dropdown, i, LV_ANIM_OFF);
            break;
        }
    }

    lv_obj_add_event_cb(
        btn,
        [](lv_event_t *e) {
            auto item = (ListSettingItem *)lv_event_get_user_data(e);
            item->setting_item_event_cb(e);
            if (item->callback) {
                item->callback(item, item->io);
            }
        },
        LV_EVENT_KEY, this);

    return btn;
}
