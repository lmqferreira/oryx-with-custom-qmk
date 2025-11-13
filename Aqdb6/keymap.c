#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,        
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_DELETE,      
    OSM(MOD_LSFT),  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           PT_CCED,        KC_ENTER,       
    OSM(MOD_LCTL),  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           PT_COMM,        PT_DOT,         PT_MINS,        KC_PSCR,        
                                                    LT(1, KC_SPACE),MO(2),                                          MO(3),          LT(1, KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_PAGE_UP,     KC_PGDN,        KC_HOME,        KC_END,         KC_INSERT,      KC_BSPC,        
    KC_TAB,         PT_EXLM,        PT_AT,          PT_EURO,        PT_BSLS,        PT_PERC,                                        PT_AMPR,        PT_SLSH,        PT_LPRN,        PT_RPRN,        PT_ACUT,        KC_DELETE,      
    KC_TRANSPARENT, PT_CIRC,        PT_DQUO,        PT_DLR,         PT_GRV,         PT_PIPE,                                        PT_QUES,        PT_QUOT,        PT_LCBR,        PT_RCBR,        PT_TILD,        KC_ENTER,       
    KC_TRANSPARENT, PT_LABK,        PT_RABK,        PT_HASH,        PT_ASTR,        PT_LDAQ,                                        PT_EQL,         PT_PLUS,        PT_LBRC,        PT_RBRC,        PT_MORD,        KC_PSCR,        
                                                    OSM(MOD_RSFT),  KC_TRANSPARENT,                                 KC_TRANSPARENT, OSM(MOD_RSFT)
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_PAGE_UP,     KC_PGDN,        KC_HOME,        KC_END,         KC_INSERT,      KC_BSPC,        
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_PAGE_UP,     KC_UP,          KC_PGDN,        KC_PAUSE,       KC_DELETE,      
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_NO,                                          KC_NO,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_SCRL,        KC_ENTER,       
    KC_LEFT_CTRL,   KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          PT_PLUS,        PT_COMM,        PT_DOT,         PT_MINS,        KC_PSCR,        
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_SPACE
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_NO,                                          RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_NO,                                          KC_TRANSPARENT, KC_RIGHT_SHIFT, KC_RIGHT_CTRL,  KC_LEFT_ALT,    KC_RIGHT_GUI,   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', 
  '*', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', '*', 
  '*', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', '*', 
  '*', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', '*', 
  '*', '*', '*', '*'
);

const uint16_t PROGMEM combo0[] = { PT_AT, PT_EURO, PT_BSLS, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_M, PT_COMM, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_W, KC_R, KC_E, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_TAB),
    COMBO(combo1, OSM(MOD_LSFT)),
    COMBO(combo2, OSM(MOD_RSFT)),
    COMBO(combo3, KC_LEFT_ALT),
    COMBO(combo4, KC_LEFT_ALT),
    COMBO(combo5, KC_LEFT_GUI),
    COMBO(combo6, KC_RIGHT_GUI),
    COMBO(combo7, KC_CAPS),
    COMBO(combo8, KC_SPACE),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_D:
            return TAPPING_TERM + 100;
        case KC_C:
            return TAPPING_TERM + 100;
        case KC_V:
            return TAPPING_TERM + 75;
        case KC_L:
            return TAPPING_TERM + 150;
        case PT_DQUO:
            return TAPPING_TERM + 200;
        case PT_ASTR:
            return TAPPING_TERM + 75;
        case PT_RCBR:
            return TAPPING_TERM + 200;
        default:
            return TAPPING_TERM;
    }
}


extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {83,255,139}, {144,255,196}, {83,255,139}, {83,255,139}, {83,255,139}, {0,0,221}, {144,255,196}, {0,0,221}, {144,255,196}, {144,255,196}, {144,255,196}, {0,0,221}, {144,255,196}, {0,0,221}, {0,0,221}, {24,255,253}, {24,255,253}, {0,0,221}, {83,255,139}, {144,255,196}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {129,255,255}, {0,255,239}, {0,0,221}, {0,0,221}, {0,0,221}, {0,0,221}, {0,0,221}, {0,255,255}, {0,0,221}, {144,255,196}, {144,255,196}, {144,255,196}, {0,0,221}, {83,255,139}, {0,0,221}, {24,255,253}, {24,255,253}, {0,0,221}, {0,0,221}, {24,255,253}, {144,255,196}, {83,255,139} },

    [1] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {83,255,139}, {215,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {144,255,196}, {144,255,196}, {43,255,234}, {83,255,139}, {0,0,255}, {43,255,234}, {0,0,255}, {144,255,196}, {0,255,239}, {0,255,239}, {0,0,255}, {144,255,196}, {83,255,139}, {83,255,139}, {144,255,196}, {185,174,255}, {185,174,255}, {215,255,255}, {215,255,255}, {0,255,238}, {0,255,239}, {0,0,255}, {144,255,196}, {0,255,239}, {0,255,239}, {43,255,234}, {0,255,255}, {215,255,255}, {43,255,234}, {0,255,239}, {0,255,239}, {43,255,234}, {83,255,139}, {144,255,196}, {144,255,196}, {0,255,239}, {0,255,239}, {0,0,255}, {24,255,253}, {144,255,196}, {83,255,139} },

    [2] = { {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {83,255,139}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,239}, {0,255,239}, {0,255,239}, {0,255,239}, {0,255,239}, {0,0,0}, {0,255,239}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {144,255,196}, {185,174,255}, {185,174,255}, {215,255,255}, {215,255,255}, {0,255,238}, {0,255,239}, {0,0,0}, {185,174,255}, {129,255,255}, {185,174,255}, {24,255,253}, {0,255,255}, {0,0,0}, {129,255,255}, {129,255,255}, {129,255,255}, {24,255,253}, {83,255,139}, {0,0,0}, {43,255,234}, {43,255,234}, {43,255,234}, {43,255,234}, {24,255,253}, {144,255,196}, {83,255,139} },

    [3] = { {0,0,0}, {32,255,235}, {32,255,235}, {32,255,235}, {32,255,235}, {32,255,235}, {0,0,0}, {32,255,235}, {32,255,235}, {32,255,235}, {32,255,235}, {0,0,0}, {0,0,0}, {32,255,235}, {32,255,235}, {32,255,235}, {32,255,235}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {144,255,196}, {32,255,235}, {32,255,235}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,255,235}, {32,255,235}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,239}, {0,255,239}, {0,255,239}, {0,255,239}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {144,255,196}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 0:
        set_layer_color(0);
        break;
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
      case 3:
        set_layer_color(3);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}



// Latch Left Alt after first TAB on layer 1; release when layer 1 deactivates
static bool layer1_alt_latched = false;


#ifndef L1_LINGER_MS
#define L1_LINGER_MS 250
#endif

// Linger state
static bool lt1_held = false;              // LT(1, KC_SPACE) currently held
static bool l1_used_during_hold = false;   // Any key pressed while LT was held
static bool l1_linger = false;             // Linger active
static bool l1_linger_end_pending = false; // End linger after current key processing
static uint16_t l1_linger_timer = 0;       // Linger start timestamp

layer_state_t layer_state_set_user(layer_state_t state) {
    if (!layer_state_cmp(state, 1) && layer1_alt_latched) {
        layer1_alt_latched = false;
        unregister_mods(MOD_BIT(KC_LALT));
        send_keyboard_report();
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // Track LT hold lifecycle (only press sets flags; release handled post-process)
    if (keycode == LT(1, KC_SPACE)) {
        if (record->event.pressed) {
            lt1_held = true;
            l1_used_during_hold = false;
            // Cancel any existing linger when re-pressing LT
            if (l1_linger) {
                l1_linger = false;
                l1_linger_end_pending = false;
            }
        }
    } else if (record->event.pressed) {
        // Any key press while LT is held marks usage (disqualifies linger)
        if (lt1_held) {
            l1_used_during_hold = true;
        }
        // During linger: first key press consumes it (end after key processed)
        if (l1_linger) {
            l1_linger_end_pending = true;
        }
    }

    // Alt latch logic unchanged
    if (layer_state_is(1) && keycode == KC_TAB && record->event.pressed) {
        if (!layer1_alt_latched) {
            layer1_alt_latched = true;
            register_mods(MOD_BIT(KC_LALT));
        }
        return true;
    }

    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Handle LT release AFTER QMK core decided tap vs hold and toggled layer
    if (keycode == LT(1, KC_SPACE) && !record->event.pressed) {
        bool was_tap = (record->tap.count && !record->tap.interrupted);
        if (!was_tap) { // was a hold
            if (!l1_used_during_hold) {
                // Eligible for linger: re-enable layer 1 now (it was just turned off)
                layer_on(1);
                l1_linger = true;
                l1_linger_timer = timer_read();
            }
        }
        lt1_held = false;
    }

    // End linger after processing the first non-LT key in linger window
    if (l1_linger_end_pending) {
        l1_linger_end_pending = false;
        if (l1_linger) {
            l1_linger = false;
            layer_off(1);
        }
    }
}

void matrix_scan_user(void) {
    if (l1_linger && timer_elapsed(l1_linger_timer) > L1_LINGER_MS) {
        l1_linger = false;
        layer_off(1);
    }
}