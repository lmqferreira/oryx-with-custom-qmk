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



#define DUAL_FUNC_0 LT(3, KC_K)
#define DUAL_FUNC_1 LT(6, KC_N)
#define DUAL_FUNC_2 LT(12, KC_F6)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_PAGE_UP,     KC_PGDN,        KC_HOME,        KC_END,         KC_INSERT,      KC_DELETE,      
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPC,        
    OSM(MOD_LSFT),  LT(1, KC_A),    MT(MOD_LALT, KC_S),MT(MOD_LCTL, KC_D),MT(MOD_LSFT, KC_F),KC_G,                                           KC_H,           MT(MOD_RSFT, KC_J),MT(MOD_RCTL, KC_K),MT(MOD_LALT, KC_L),LT(1, PT_CCED), KC_ENTER,       
    KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           MT(MOD_LALT, KC_V),KC_B,                                           KC_N,           KC_M,           PT_COMM,        PT_DOT,         PT_MINS,        KC_ESCAPE,      
                                                    OSL(1),         MT(MOD_LGUI, KC_SPACE),                                KC_BSPC,        LT(1, KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_DELETE,      
    KC_TRANSPARENT, PT_EXLM,        PT_AT,          PT_EURO,        PT_BSLS,        PT_PERC,                                        PT_AMPR,        PT_SLSH,        PT_LPRN,        PT_RPRN,        PT_ACUT,        KC_BSPC,        
    KC_TRANSPARENT, PT_CIRC,        DUAL_FUNC_0,    DUAL_FUNC_1,    DUAL_FUNC_2,    PT_PIPE,                                        PT_QUOT,        PT_EQL,         PT_LCBR,        PT_RCBR,        PT_TILD,        KC_ENTER,       
    KC_TRANSPARENT, PT_LABK,        PT_RABK,        PT_HASH,        PT_ASTR,        PT_LDAQ,                                        PT_MORD,        PT_PLUS,        PT_LBRC,        PT_RBRC,        PT_QUES,        LALT(KC_PSCR),  
                                                    MO(2),          KC_LEFT_GUI,                                    KC_TRANSPARENT, MO(3)
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_SCRL,        KC_PAUSE,       KC_HOME,        KC_END,         KC_INSERT,      KC_DELETE,      
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_PAGE_UP,     KC_UP,          KC_PAGE_UP,     KC_PAUSE,       KC_BSPC,        
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_NO,                                          KC_NO,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_ENTER,       
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          LALT(KC_PSCR),  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_NO,                                          KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_NO,                                          KC_TRANSPARENT, KC_RIGHT_SHIFT, KC_RIGHT_CTRL,  KC_LEFT_ALT,    KC_RIGHT_GUI,   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  '*', '*', '*', '*'
);

const uint16_t PROGMEM combo0[] = { KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo2[] = { MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), MT(MOD_LSFT, KC_F), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_SPACE),
    COMBO(combo1, KC_ENTER),
    COMBO(combo2, KC_CAPS),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LALT, KC_S):
            return TAPPING_TERM + 75;
        case MT(MOD_LCTL, KC_D):
            return TAPPING_TERM + 100;
        case KC_C:
            return TAPPING_TERM + 100;
        case MT(MOD_LALT, KC_V):
            return TAPPING_TERM + 75;
        case MT(MOD_LALT, KC_L):
            return TAPPING_TERM + 150;
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
    [0] = { {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {83,255,139}, {0,0,0}, {83,255,139}, {83,255,139}, {83,255,139}, {0,0,255}, {144,255,196}, {144,255,196}, {144,255,196}, {144,255,196}, {144,255,196}, {0,0,255}, {144,255,196}, {0,0,255}, {0,0,255}, {0,0,255}, {144,255,196}, {0,0,255}, {144,255,196}, {83,255,139}, {185,174,255}, {185,174,255}, {185,174,255}, {185,174,255}, {185,174,255}, {185,174,255}, {0,0,255}, {83,255,139}, {83,255,139}, {83,255,139}, {0,0,255}, {0,255,239}, {0,0,255}, {144,255,196}, {144,255,196}, {144,255,196}, {144,255,196}, {83,255,139}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {43,255,234}, {0,255,239}, {83,255,139} },

    [1] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {83,255,139}, {0,0,255}, {0,0,255}, {0,0,255}, {144,255,196}, {144,255,196}, {43,255,234}, {83,255,139}, {0,0,255}, {43,255,234}, {0,0,255}, {144,255,196}, {0,255,239}, {0,255,239}, {0,0,255}, {144,255,196}, {0,0,255}, {144,255,196}, {24,255,253}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {185,174,255}, {0,0,255}, {144,255,196}, {0,255,239}, {0,255,239}, {43,255,234}, {0,255,239}, {83,255,139}, {144,255,196}, {0,255,239}, {0,255,239}, {43,255,234}, {83,255,139}, {0,0,255}, {144,255,196}, {0,255,239}, {0,255,239}, {83,255,139}, {24,255,253}, {0,0,255}, {168,168,255} },

    [2] = { {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {0,255,239}, {0,255,239}, {0,255,239}, {0,255,239}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {24,255,253}, {24,255,253}, {185,174,255}, {185,174,255}, {185,174,255}, {185,174,255}, {118,255,255}, {185,174,255}, {43,255,234}, {185,174,255}, {24,255,253}, {0,255,239}, {118,255,255}, {43,255,234}, {43,255,234}, {43,255,234}, {118,255,255}, {83,255,139}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {24,255,253}, {0,255,239}, {118,255,255} },

    [3] = { {0,0,0}, {32,255,235}, {32,255,235}, {32,255,235}, {32,255,235}, {32,255,235}, {0,0,0}, {32,255,235}, {32,255,235}, {32,255,235}, {32,255,235}, {0,0,0}, {0,0,0}, {32,255,235}, {32,255,235}, {32,255,235}, {32,255,235}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,255,235}, {32,255,235}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,255,235}, {32,255,235}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,239}, {0,255,239}, {0,255,239}, {0,255,239}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(PT_DQUO);
        } else {
          unregister_code16(PT_DQUO);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_ALT);
        } else {
          unregister_code16(KC_LEFT_ALT);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(PT_DLR);
        } else {
          unregister_code16(PT_DLR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(PT_GRV);
        } else {
          unregister_code16(PT_GRV);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_SHIFT);
        } else {
          unregister_code16(KC_LEFT_SHIFT);
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
