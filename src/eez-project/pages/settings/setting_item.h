#pragma once

#include <ArduinoJson.h>
#include <array>
#include <lvgl.h>
#include <string>
#include <variant>
#include <vector>
#include "../../../io_service.h"

using std::string;
using std::vector;

template <typename T> class ConfigSettingItem
{
protected:
    const char *title;
    virtual void setting_item_event_cb(lv_event_t *e) {};
    const JsonVariant json_config;
    void (*callback)(ConfigSettingItem *, io_service &);
    io_service &io;
    lv_obj_t *obj;

public:
    ConfigSettingItem(const char *title, const JsonVariant config, io_service &io, void (*callback)(ConfigSettingItem *, io_service &))
        : title(title), json_config(config), io(io), callback(callback)
    {
    }

    virtual const char *getTitle() const { return title; };
    virtual T getValue() const = 0;
    virtual void setValue(const T &value) const = 0;
    virtual lv_obj_t *render(lv_obj_t *parent) = 0;
    virtual bool can_select() const { return false; }
    lv_obj_t *getObj() const { return obj; }
};

class IntSettingItem : public ConfigSettingItem<int>
{
private:
    int min;
    int max;
    int step;
    lv_obj_t *value_spinbox;
    int get_config_min() const
    {
        if (json_config.isNull() || json_config["min"].isNull()) {
            Serial.printf("[ERROR] Config is null: %s\n", title);
            return 0;
        }
        return json_config["min"].as<int>();
    }
    int get_config_max() const
    {
        if (json_config.isNull() || json_config["max"].isNull()) {
            Serial.printf("[ERROR] Config is null: %s\n", title);
            return 0;
        }
        return json_config["max"].as<int>();
    }
    int get_config_step() const
    {
        if (json_config.isNull() || json_config["step"].isNull()) {
            Serial.printf("[ERROR] Config is null: %s\n", title);
            return 0;
        }
        return json_config["step"].as<int>();
    }
    void setting_item_event_cb(lv_event_t *e) override;

public:
    IntSettingItem(const char *title, const JsonVariant config, io_service &io, void (*callback)(ConfigSettingItem *, io_service &)) : ConfigSettingItem(title, config, io, callback)
    {
        min = get_config_min();
        max = get_config_max();
        step = get_config_step();
    }
    int getValue() const override
    {
        if (json_config.isNull() || json_config["value"].isNull()) {
            Serial.printf("[ERROR] Config is null: %s\n", title);
            return 0;
        }
        return json_config["value"].as<int>();
    }
    void setValue(const int &value) const override { json_config["value"].set(value); }
    lv_obj_t *render(lv_obj_t *parent) override;
    bool can_select() const override { return true; }
};

class BoolSettingItem : public ConfigSettingItem<bool>
{
private:
    lv_obj_t *btn_switch;
    void setting_item_event_cb(lv_event_t *e) override;

public:
    BoolSettingItem(const char *title, const JsonVariant config, io_service &io, void (*callback)(ConfigSettingItem *, io_service &)) : ConfigSettingItem(title, config, io, callback)
    {
    }
    bool getValue() const override
    {
        if (json_config.isNull()) {
            Serial.printf("[ERROR] Config is null: %s\n", title);
            return false;
        }
        return json_config.as<bool>();
    }
    void setValue(const bool &value) const override { json_config.set(value); }
    lv_obj_t *render(lv_obj_t *parent) override;
    bool can_select() const override { return false; }
};

class FloatSettingItem : public ConfigSettingItem<float>
{
private:
    float min;
    float max;
    float step;
    lv_obj_t *value_spinbox;
    float get_config_min() const
    {
        if (json_config.isNull() || json_config["min"].isNull()) {
            Serial.printf("[ERROR] Config is null: %s\n", title);
            return 0.0f;
        }
        return json_config["min"].as<float>();
    }
    float get_config_max() const
    {
        if (json_config.isNull() || json_config["max"].isNull()) {
            Serial.printf("[ERROR] Config is null: %s\n", title);
            return 0.0f;
        }
        return json_config["max"].as<float>();
    }
    float get_config_step() const
    {
        if (json_config.isNull() || json_config["step"].isNull()) {
            Serial.printf("[ERROR] Config is null: %s\n", title);
            return 0.0f;
        }
        return json_config["step"].as<float>();
    }
    void setting_item_event_cb(lv_event_t *e) override;

public:
    FloatSettingItem(const char *title, const JsonVariant config, io_service &io, void (*callback)(ConfigSettingItem *, io_service &)) : ConfigSettingItem(title, config, io, callback)
    {
        min = get_config_min();
        max = get_config_max();
        step = get_config_step();
    }
    float getValue() const override
    {
        if (json_config.isNull() || json_config["value"].isNull()) {
            Serial.printf("[ERROR] Config is null: %s\n", title);
            return 0.0f;
        }
        return json_config["value"].as<float>();
    }
    void setValue(const float &value) const override { json_config["value"].set(value); }
    lv_obj_t *render(lv_obj_t *parent) override;
    bool can_select() const override { return true; }
};

class ListSettingItem : public ConfigSettingItem<string>
{
private:
    vector<string> options;
    lv_obj_t *value_dropdown;
    vector<string> get_config_options() const;
    void setting_item_event_cb(lv_event_t *e) override;

public:
    ListSettingItem(const char *title, const JsonVariant config, io_service &io, void (*callback)(ConfigSettingItem *, io_service &)) : ConfigSettingItem(title, config, io, callback)
    {
        options = get_config_options();
    }
    string getValue() const override;
    void setValue(const string &value) const override;
    lv_obj_t *render(lv_obj_t *parent) override;
    bool can_select() const override { return true; }
};
