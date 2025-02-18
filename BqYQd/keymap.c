#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
  ST_MACRO_0,
};


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
tap_dance_action_t *action;

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    LT(3,KC_ESCAPE),KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           LT(5,KC_GRAVE), 
    MT(MOD_LCTL, KC_F13),KC_A,           KC_S,           LT(1,KC_D),     KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        MT(MOD_RCTL, KC_QUOTE),
    OSM(MOD_LSFT),  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       OSM(MOD_RSFT),  
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F17,         OSM(MOD_LALT),  OSM(MOD_LGUI),  KC_SPACE,                                       KC_F17,         MT(MOD_RGUI, KC_ENTER),MT(MOD_RALT, KC_LBRC),KC_RBRC,        KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    LT(7,KC_TAB),   ALL_T(KC_F18),                                  ALL_T(KC_F19),  LT(4,KC_BSPC)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_LALT, KC_S),KC_TRANSPARENT, TD(DANCE_0),    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_1),    KC_TRANSPARENT, MT(MOD_RALT, KC_L),MT(MOD_RSFT, KC_SCLN),KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           ST_MACRO_0,     KC_7,           KC_8,           KC_9,           KC_PERC,        QK_LLCK,        
    KC_TRANSPARENT, KC_0,           KC_6,           KC_7,           KC_8,           KC_9,                                           KC_0,           KC_4,           KC_5,           KC_6,           TD(DANCE_2),    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_NO,          KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_CIRC,        KC_HASH,        KC_DLR,         KC_PERC,        LALT(LSFT(KC_2)),                                KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EXLM,        KC_LPRN,        KC_AT,          KC_RPRN,        KC_AMPR,                                        KC_PIPE,        KC_LBRC,        KC_CAPS,        KC_RBRC,        KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_LCBR,        KC_ASTR,        KC_RCBR,        KC_NO,                                          KC_BSLS,        KC_UNDS,        KC_COMMA,       KC_PLUS,        KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_F19,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    QK_LLCK,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F11,         KC_F12,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        RGB_VAD,        RGB_VAI,                                        QK_BOOT,        KC_TRANSPARENT, KC_APPLICATION, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_0_255_255,  HSV_74_255_255, HSV_169_255_255,                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_voyager(
    QK_LLCK,        KC_NO,          KC_NO,          LGUI(KC_X),     KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_MS_UP,       KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_BTN1,     LGUI(KC_Z),     LGUI(KC_C),     LGUI(KC_V),     KC_NO,                                          QK_LLCK,        KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_BTN2,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_BSPC,        KC_ENTER,       KC_NO,                                          KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,TD(DANCE_3),    KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F18
  ),
};

const uint16_t PROGMEM combo0[] = { KC_DOT, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_O, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_3, KC_2, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_1, KC_3, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_4, KC_6, COMBO_END};
const uint16_t PROGMEM combo9[] = { KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM combo10[] = { KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM combo11[] = { KC_LEFT, KC_UP, COMBO_END};
const uint16_t PROGMEM combo12[] = { KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM combo13[] = { KC_L, KC_K, COMBO_END};
const uint16_t PROGMEM combo14[] = { OSM(MOD_LSFT), KC_Z, COMBO_END};
const uint16_t PROGMEM combo15[] = { KC_SLASH, OSM(MOD_RSFT), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_EQUAL),
    COMBO(combo1, KC_MINUS),
    COMBO(combo2, TO(6)),
    COMBO(combo3, KC_COMMA),
    COMBO(combo4, KC_KP_DOT),
    COMBO(combo5, KC_KP_EQUAL),
    COMBO(combo6, KC_KP_PLUS),
    COMBO(combo7, KC_KP_MINUS),
    COMBO(combo8, KC_KP_ASTERISK),
    COMBO(combo9, TO(2)),
    COMBO(combo10, TO(1)),
    COMBO(combo11, TO(0)),
    COMBO(combo12, TO(1)),
    COMBO(combo13, KC_ESCAPE),
    COMBO(combo14, LSFT(KC_LEFT_CTRL)),
    COMBO(combo15, RSFT(KC_RIGHT_CTRL)),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(3,KC_ESCAPE):
            return TAPPING_TERM -25;
        case KC_E:
            return TAPPING_TERM -35;
        case KC_A:
            return TAPPING_TERM -35;
        case KC_S:
            return TAPPING_TERM + 5;
        case LT(1,KC_D):
            return TAPPING_TERM -15;
        case KC_G:
            return TAPPING_TERM + 5;
        case KC_X:
            return TAPPING_TERM -25;
        case KC_C:
            return TAPPING_TERM -35;
        case KC_V:
            return TAPPING_TERM + 5;
        case KC_SPACE:
            return TAPPING_TERM -25;
        case LT(7,KC_TAB):
            return TAPPING_TERM -25;
        case ALL_T(KC_F18):
            return TAPPING_TERM -15;
        case LT(5,KC_GRAVE):
            return TAPPING_TERM -25;
        case KC_K:
            return TAPPING_TERM -15;
        case KC_SCLN:
            return TAPPING_TERM -25;
        case KC_COMMA:
            return TAPPING_TERM -25;
        case KC_SLASH:
            return TAPPING_TERM + 65;
        case KC_F17:
            return TAPPING_TERM -15;
        case MT(MOD_RGUI, KC_ENTER):
            return TAPPING_TERM -25;
        case MT(MOD_RALT, KC_LBRC):
            return TAPPING_TERM -25;
        case KC_RBRC:
            return TAPPING_TERM -25;
        case ALL_T(KC_F19):
            return TAPPING_TERM -15;
        case LT(4,KC_BSPC):
            return TAPPING_TERM -15;
        case QK_LLCK:
            return TAPPING_TERM -55;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {74,229,173}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {16,255,248}, {0,0,255}, {0,0,255}, {41,255,255}, {0,0,255}, {0,0,255}, {74,229,173}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {21,255,255}, {0,0,255}, {74,229,173}, {74,229,173}, {74,229,173}, {0,0,255}, {152,255,255}, {74,229,173}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {205,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {74,229,173}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {74,229,173}, {74,229,173}, {74,229,173}, {74,229,173}, {74,229,173}, {0,0,255}, {0,0,255}, {21,255,255}, {74,229,173}, {0,245,245} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {16,255,248}, {0,0,0}, {41,255,255}, {41,255,255}, {16,255,248}, {0,0,0}, {74,229,173}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,229,173}, {74,229,173}, {74,229,173}, {0,0,255}, {0,0,0}, {74,229,173}, {0,0,0}, {0,0,0}, {0,255,210}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,229,173}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,229,173}, {0,255,210} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,229,173}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {16,255,248}, {16,255,248}, {16,255,248}, {219,255,255}, {16,255,248}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,210}, {0,255,210}, {0,255,210}, {207,255,255}, {0,245,245}, {41,255,255}, {16,255,248}, {16,244,245}, {16,244,245}, {207,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {74,229,173}, {152,255,255}, {0,0,0}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {207,255,255}, {207,255,255}, {207,255,255}, {207,255,255}, {207,255,255}, {0,0,0}, {207,255,255}, {207,255,255}, {207,255,255}, {207,255,255}, {207,255,255}, {0,0,0}, {0,0,0}, {205,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {207,255,255}, {205,255,255}, {41,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {207,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,255,210}, {207,255,255}, {207,255,255}, {207,255,255}, {207,255,255}, {205,255,255}, {0,0,0}, {16,244,245}, {16,244,245}, {16,255,248}, {16,255,248}, {16,255,248}, {74,229,173}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {74,229,173}, {74,229,173}, {74,229,173}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,229,173}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,229,173}, {41,255,255}, {74,229,173}, {74,229,173}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [7] = { {0,245,245}, {0,0,0}, {0,0,0}, {152,255,255}, {0,0,0}, {0,0,0}, {21,255,255}, {21,255,255}, {21,255,255}, {152,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {74,229,173}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {41,255,255}, {41,255,255}, {41,255,255}, {21,255,255}, {0,0,0}, {205,255,255}, {41,255,255}, {0,255,210}, {41,255,255}, {207,255,255}, {0,0,0}, {74,229,173}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {21,255,255} },

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
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
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
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 7:
      set_layer_color(7);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_4)) SS_DELAY(100) SS_TAP(X_DOT));
    }
    break;

    case TD(DANCE_0):
    case TD(DANCE_1):
    case TD(DANCE_2):
    case TD(DANCE_3):
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
        break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_74_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(74,255,255);
      }
      return false;
    case HSV_169_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;
  }
  return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_TAP_HOLD(KC_F, KC_F24),
        [DANCE_1] = ACTION_TAP_DANCE_TAP_HOLD(KC_J, KC_F24),
        [DANCE_2] = ACTION_TAP_DANCE_TAP_HOLD(KC_COLN, KC_SCLN),
        [DANCE_3] = ACTION_TAP_DANCE_TAP_HOLD(KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE),
};
