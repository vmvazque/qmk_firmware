#include QMK_KEYBOARD_H
// #include "util.h"
#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define BASE_LAYER 0
#define QWERTY_LAYER 1
#define ARROW_LAYER 2
#define FN_LAYER 3
#define UI_LAYER 4

#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum custom_keycodes {
  // QWERTY = SAFE_RANGE,
  SMALL_ARROW = SAFE_RANGE,
  FAT_ARROW
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case SMALL_ARROW:
      if (record -> event.pressed) {
        SEND_STRING("->");
      } else {

      }
    break;
    case FAT_ARROW:
      if (record -> event.pressed) {
        SEND_STRING("=>");
      } else {

      }
    break;
  }

  return true;
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}

//Tap Dance Definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
//   //Tap once for -, twice for _
//   // [TD_DASH_UNDER]  = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS)
// // Other declarations would go here, separated by commas, if you have them
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_LAYER] = LAYOUT_65(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_GRV, KC_HOME, \
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_LBRC, KC_RBRC, KC_BSPC, KC_PGUP, \
    LT(ARROW_LAYER, KC_BSPC), KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT, KC_ENT, KC_PGDN, \
    KC_LSFT, KC_X,    KC_C,    KC_D,    KC_V,    KC_Z,    KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_BSLS, KC_END, \
    KC_LCTL, KC_LGUI, KC_LALT, LT(UI_LAYER, KC_SPC), LT(FN_LAYER, KC_DEL),           XXXXXXX, LT(FN_LAYER,KC_SPC), KC_RALT, TO(QWERTY_LAYER), KC_DOLLAR, KC_LEFT, KC_RCTL, KC_RCTL
  ),

  [ARROW_LAYER] = LAYOUT_65(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , _______, SMALL_ARROW, FAT_ARROW, _______, _______, _______, \
    _______, _______, KC_VOLU, _______, _______, _______, _______, _______, KC_UP  , _______ , _______, _______, _______, _______, _______, \
    _______, _______, KC_VOLD, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , _______, KC_CAPS, _______,  _______, \
    _______, _______, _______, _______, _______,          _______, XXXXXXX, _______, _______, _______,  KC_MPRV, KC_MPLY, KC_MNXT
  ),

  [FN_LAYER] = LAYOUT_65(
    _______, KC_F1  , KC_F2        , KC_F3        , KC_F4         , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , RESET , _______, _______, \
    _______, _______, _______      , LGUI(KC_UP)  , _______       , _______, _______, _______, KC_PGUP, _______, _______, _______, _______, KC_INS, _______, \
    _______, _______, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RIGHT), _______, _______, KC_HOME, KC_PGDN, KC_END , _______, _______, _______, _______, \
    _______, _______, _______      , _______      , _______       , _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,                                      _______, XXXXXXX, _______, _______, _______, _______, _______, _______
  ),

  [UI_LAYER] = LAYOUT_65(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    RGB_TOG, RGB_MOD, _______, SCMD(KC_UP), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, SCMD(KC_LEFT), SCMD(KC_DOWN), SCMD(KC_RIGHT), _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,          _______, XXXXXXX, _______, _______, _______, _______, _______, _______
  ),

  [QWERTY_LAYER] = LAYOUT_65(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_GRV,  KC_HOME, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC_PGUP, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,  KC_END, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_DEL,           KC_SPC, XXXXXXX, KC_RALT, TO(BASE_LAYER), KC_DOLLAR, KC_LEFT, KC_DOWN, KC_RCTL
  ),
};

// void matrix_scan_user(void) {
//   #ifdef RGBLIGHT_ENABLE

//   static uint8_t old_layer = 255;
//   uint8_t new_layer = biton32(layer_state);
//   // rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);

//   if (old_layer != new_layer) {
//     switch (new_layer) {
//       case BASE_LAYER:
//         rgblight_setrgb(RGB_PURPLE);
//         break;
//       case ARROW_LAYER:
//         rgblight_setrgb(RGB_PINK);
//         break;
//       case FN_LAYER:
//         rgblight_setrgb(0xFF, 0x00, 0x00);
//         break;
//       case UI_LAYER:
//         rgblight_setrgb(0xFF, 0x20, 0x00);
//         break;
//     }

//     old_layer = new_layer;
//   }

//   #endif //RGBLIGHT_ENABLE
// }