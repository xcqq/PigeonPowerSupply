#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations

typedef enum {
    vc_selction_MAX_SEL = 2,
    vc_selction_CURR_SEL = 1,
    vc_selction_VOLT_SEL = 0
} vc_selction;

typedef enum {
    cc_cv_mode_CV_MODE = 1,
    cc_cv_mode_CC_MODE = 0
} cc_cv_mode;

// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_SET_VOLT = 0,
    FLOW_GLOBAL_VARIABLE_SET_CURR = 1,
    FLOW_GLOBAL_VARIABLE_OUT_VOLT = 2,
    FLOW_GLOBAL_VARIABLE_OUT_CURR = 3,
    FLOW_GLOBAL_VARIABLE_INPUT_VOLT = 4,
    FLOW_GLOBAL_VARIABLE_CC_CV_FLAG = 5,
    FLOW_GLOBAL_VARIABLE_POWER_TEMP = 6,
    FLOW_GLOBAL_VARIABLE_OUT_ENABLE = 7,
    FLOW_GLOBAL_VARIABLE_SET_STEP = 8,
    FLOW_GLOBAL_VARIABLE_UPDATE_INTERVAL = 9,
    FLOW_GLOBAL_VARIABLE_SET_VOLT_MAX = 10,
    FLOW_GLOBAL_VARIABLE_SET_CURR_MAX = 11,
    FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG = 12
};

// Native global variables



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/