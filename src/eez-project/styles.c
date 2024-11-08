#include "styles.h"
#include "images.h"
#include "fonts.h"

//
// Style: home_set_num_label_style
//

void init_style_home_set_num_label_style_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_lcd_font_30);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
};

lv_style_t *get_style_home_set_num_label_style_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_set_num_label_style_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_home_set_num_label_style(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_home_set_num_label_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_home_set_num_label_style(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_home_set_num_label_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: home_out_num_label_style
//

void init_style_home_out_num_label_style_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_roboto_50);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_RIGHT);
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
};

lv_style_t *get_style_home_out_num_label_style_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_out_num_label_style_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_home_out_num_label_style_MAIN_DISABLED(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xff767676));
};

lv_style_t *get_style_home_out_num_label_style_MAIN_DISABLED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_out_num_label_style_MAIN_DISABLED(style);
    }
    return style;
};

void add_style_home_out_num_label_style(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_home_out_num_label_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_home_out_num_label_style_MAIN_DISABLED(), LV_PART_MAIN | LV_STATE_DISABLED);
};

void remove_style_home_out_num_label_style(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_home_out_num_label_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_home_out_num_label_style_MAIN_DISABLED(), LV_PART_MAIN | LV_STATE_DISABLED);
};

//
// Style: home_bar_num_style
//

void init_style_home_bar_num_style_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_lcd_font_20);
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
};

lv_style_t *get_style_home_bar_num_style_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_bar_num_style_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_home_bar_num_style(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_home_bar_num_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_home_bar_num_style(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_home_bar_num_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: home_bar_label_style
//

void init_style_home_bar_label_style_MAIN_DEFAULT(lv_style_t *style) {
    init_style_home_bar_num_style_MAIN_DEFAULT(style);
    
    lv_style_set_text_font(style, &ui_font_roboto_10);
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
};

lv_style_t *get_style_home_bar_label_style_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_bar_label_style_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_home_bar_label_style(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_home_bar_label_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_home_bar_label_style(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_home_bar_label_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: home_set_text_label_style
//

void init_style_home_set_text_label_style_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_roboto_14);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
    lv_style_set_text_color(style, lv_color_hex(0xffffffff));
    lv_style_set_bg_opa(style, 255);
    lv_style_set_bg_color(style, lv_color_hex(0xff767676));
    lv_style_set_radius(style, 3);
};

lv_style_t *get_style_home_set_text_label_style_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_set_text_label_style_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_home_set_text_label_style_MAIN_DISABLED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff767676));
};

lv_style_t *get_style_home_set_text_label_style_MAIN_DISABLED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_set_text_label_style_MAIN_DISABLED(style);
    }
    return style;
};

void add_style_home_set_text_label_style(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_home_set_text_label_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_home_set_text_label_style_MAIN_DISABLED(), LV_PART_MAIN | LV_STATE_DISABLED);
};

void remove_style_home_set_text_label_style(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_home_set_text_label_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_home_set_text_label_style_MAIN_DISABLED(), LV_PART_MAIN | LV_STATE_DISABLED);
};

//
// Style: home_out_text_label_style
//

void init_style_home_out_text_label_style_MAIN_DEFAULT(lv_style_t *style) {
    init_style_home_set_text_label_style_MAIN_DEFAULT(style);
    
    lv_style_set_text_font(style, &ui_font_roboto_24);
    lv_style_set_radius(style, 5);
};

lv_style_t *get_style_home_out_text_label_style_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_out_text_label_style_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_home_out_text_label_style_MAIN_DISABLED(lv_style_t *style) {
    init_style_home_set_text_label_style_MAIN_DISABLED(style);
    
};

lv_style_t *get_style_home_out_text_label_style_MAIN_DISABLED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_out_text_label_style_MAIN_DISABLED(style);
    }
    return style;
};

void add_style_home_out_text_label_style(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_home_out_text_label_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_home_out_text_label_style_MAIN_DISABLED(), LV_PART_MAIN | LV_STATE_DISABLED);
};

void remove_style_home_out_text_label_style(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_home_out_text_label_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_home_out_text_label_style_MAIN_DISABLED(), LV_PART_MAIN | LV_STATE_DISABLED);
};

//
// Style: home_set_volt_spinbox
//

void init_style_home_set_volt_spinbox_CURSOR_DISABLED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xffffffff));
    lv_style_set_text_font(style, &ui_font_roboto_24);
    lv_style_set_bg_opa(style, 0);
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
};

lv_style_t *get_style_home_set_volt_spinbox_CURSOR_DISABLED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_set_volt_spinbox_CURSOR_DISABLED(style);
    }
    return style;
};

void init_style_home_set_volt_spinbox_CURSOR_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xffff3b30));
    lv_style_set_text_font(style, &ui_font_roboto_24);
    lv_style_set_radius(style, 4);
};

lv_style_t *get_style_home_set_volt_spinbox_CURSOR_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_set_volt_spinbox_CURSOR_DEFAULT(style);
    }
    return style;
};

void init_style_home_set_volt_spinbox_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_roboto_24);
    lv_style_set_pad_top(style, 5);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_pad_left(style, 2);
    lv_style_set_pad_right(style, 2);
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
    lv_style_set_pad_row(style, 0);
    lv_style_set_pad_column(style, 0);
    lv_style_set_border_width(style, 0);
    lv_style_set_bg_opa(style, 0);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_LEFT);
};

lv_style_t *get_style_home_set_volt_spinbox_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_set_volt_spinbox_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_home_set_volt_spinbox_MAIN_DISABLED(lv_style_t *style) {
    lv_style_set_outline_width(style, 0);
    lv_style_set_outline_color(style, lv_color_hex(0xff000000));
};

lv_style_t *get_style_home_set_volt_spinbox_MAIN_DISABLED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_set_volt_spinbox_MAIN_DISABLED(style);
    }
    return style;
};

void add_style_home_set_volt_spinbox(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_home_set_volt_spinbox_CURSOR_DISABLED(), LV_PART_CURSOR | LV_STATE_DISABLED);
    lv_obj_add_style(obj, get_style_home_set_volt_spinbox_CURSOR_DEFAULT(), LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_home_set_volt_spinbox_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_home_set_volt_spinbox_MAIN_DISABLED(), LV_PART_MAIN | LV_STATE_DISABLED);
};

void remove_style_home_set_volt_spinbox(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_home_set_volt_spinbox_CURSOR_DISABLED(), LV_PART_CURSOR | LV_STATE_DISABLED);
    lv_obj_remove_style(obj, get_style_home_set_volt_spinbox_CURSOR_DEFAULT(), LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_home_set_volt_spinbox_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_home_set_volt_spinbox_MAIN_DISABLED(), LV_PART_MAIN | LV_STATE_DISABLED);
};

//
// Style: home_set_curr_spinbox
//

void init_style_home_set_curr_spinbox_MAIN_DEFAULT(lv_style_t *style) {
    init_style_home_set_volt_spinbox_MAIN_DEFAULT(style);
    
    lv_style_set_outline_color(style, lv_color_hex(0xff521414));
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
};

lv_style_t *get_style_home_set_curr_spinbox_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_set_curr_spinbox_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_home_set_curr_spinbox_MAIN_DISABLED(lv_style_t *style) {
    init_style_home_set_volt_spinbox_MAIN_DISABLED(style);
    
};

lv_style_t *get_style_home_set_curr_spinbox_MAIN_DISABLED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_set_curr_spinbox_MAIN_DISABLED(style);
    }
    return style;
};

void init_style_home_set_curr_spinbox_CURSOR_DEFAULT(lv_style_t *style) {
    init_style_home_set_volt_spinbox_CURSOR_DEFAULT(style);
    
    lv_style_set_bg_color(style, lv_color_hex(0xff34c759));
};

lv_style_t *get_style_home_set_curr_spinbox_CURSOR_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_set_curr_spinbox_CURSOR_DEFAULT(style);
    }
    return style;
};

void init_style_home_set_curr_spinbox_CURSOR_DISABLED(lv_style_t *style) {
    init_style_home_set_volt_spinbox_CURSOR_DISABLED(style);
    
};

lv_style_t *get_style_home_set_curr_spinbox_CURSOR_DISABLED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_set_curr_spinbox_CURSOR_DISABLED(style);
    }
    return style;
};

void add_style_home_set_curr_spinbox(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_home_set_curr_spinbox_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_home_set_curr_spinbox_MAIN_DISABLED(), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_add_style(obj, get_style_home_set_curr_spinbox_CURSOR_DEFAULT(), LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_home_set_curr_spinbox_CURSOR_DISABLED(), LV_PART_CURSOR | LV_STATE_DISABLED);
};

void remove_style_home_set_curr_spinbox(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_home_set_curr_spinbox_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_home_set_curr_spinbox_MAIN_DISABLED(), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_remove_style(obj, get_style_home_set_curr_spinbox_CURSOR_DEFAULT(), LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_home_set_curr_spinbox_CURSOR_DISABLED(), LV_PART_CURSOR | LV_STATE_DISABLED);
};

//
// Style: home_out_title_style
//

void init_style_home_out_title_style_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_roboto_14);
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
};

lv_style_t *get_style_home_out_title_style_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_home_out_title_style_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_home_out_title_style(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_home_out_title_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_home_out_title_style(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_home_out_title_style_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_home_set_num_label_style,
        add_style_home_out_num_label_style,
        add_style_home_bar_num_style,
        add_style_home_bar_label_style,
        add_style_home_set_text_label_style,
        add_style_home_out_text_label_style,
        add_style_home_set_volt_spinbox,
        add_style_home_set_curr_spinbox,
        add_style_home_out_title_style,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_home_set_num_label_style,
        remove_style_home_out_num_label_style,
        remove_style_home_bar_num_style,
        remove_style_home_bar_label_style,
        remove_style_home_set_text_label_style,
        remove_style_home_out_text_label_style,
        remove_style_home_set_volt_spinbox,
        remove_style_home_set_curr_spinbox,
        remove_style_home_out_title_style,
    };
    remove_style_funcs[styleIndex](obj);
}

