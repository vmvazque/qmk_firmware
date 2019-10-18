#include "banana_split.h"
enum custom_keycodes {
  SMALL_ARROW = SAFE_RANGE,
  FAT_ARROW,
};
// TAP dance declarations
enum {
  TD_DASH_UNDER = 0
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

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for -, twice for _
  [TD_DASH_UNDER]  = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//colemak mod dh
[0] = KEYMAP(KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0  , TD(TD_DASH_UNDER), KC_EQL  , KC_PIPE, KC_GRV, 
             KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN , KC_LBRC, KC_RBRC, KC_BSPC, 
             LT(2, KC_BSPC), KC_A   , KC_R   , KC_S   , KC_T   , KC_G   , KC_K   , KC_N   , KC_E   , KC_I   , KC_O    , KC_QUOT, KC_ENT, 
             KC_LSFT, KC_NO  , KC_X   , KC_C   , KC_D   , KC_V   , KC_Z   , KC_M   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_BSLS, 
             KC_LCTL, KC_LGUI , KC_LALT, LT(6, KC_SPC), LT(3, KC_DEL), KC_SPC, TO(7), TG(1)  , KC_NO , TG(4)  , KC_RCTL),
  //qwerty layer
[1] = KEYMAP(KC_ESC , KC_1    , KC_2   , KC_3, KC_4   , KC_5, KC_6   , KC_7  , KC_8   , KC_9   , KC_0  , KC_MINS, KC_EQL  , KC_PIPE, KC_GRV, 
             KC_TAB , KC_Q    , KC_W   , KC_E, KC_R   , KC_T, KC_Y   , KC_U  , KC_I   , KC_O   , KC_P  , KC_LBRC, KC_RBRC , KC_BSPC, 
             LT(2   , KC_BSPC), KC_A   , KC_S, KC_D   , KC_F, KC_G   , KC_H  , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT , KC_ENT , 
             KC_LSFT, KC_NO   , KC_Z   , KC_X, KC_C   , KC_V, KC_B   , KC_N  , KC_M   , KC_COMM, KC_DOT, KC_SLSH, KC_RSFT , KC_BSLS,
             KC_LCTL, KC_LGUI , KC_LALT, LT(6, KC_SPC), LT(3, KC_DEL), KC_SPC, TO(7), KC_TRNS  , KC_NO , KC_TRNS  , KC_RCTL),
//media + arrows
[2] = KEYMAP(KC_TRNS, LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SMALL_ARROW, FAT_ARROW, KC_TRNS, KC_TRNS, 
             KC_TRNS, KC_TRNS, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
             KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CAPS, KC_TRNS, 
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_NO, KC_MPLY, KC_MNXT),
//fkeys + pgup + home + etc...
[3] = KEYMAP(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, RESET, KC_TRNS, 
             KC_TRNS, KC_TRNS, KC_TRNS, LGUI(KC_UP), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
             KC_TRNS, KC_TRNS, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RIGHT), KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, 
             KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_INS, KC_TRNS),
//browsing layer
[4] = KEYMAP(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, LALT(KC_LEFT), LALT(KC_RIGHT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RCTL(KC_PGUP), RCTL(KC_PGDN), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(5), KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS),
//more browsing lazyness
[5] = KEYMAP(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, 
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, RCTL(KC_W), KC_TRNS, KC_TRNS, KC_TRNS, 
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
             KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS),
//moving around the UI         
[6] = KEYMAP(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
             KC_TRNS, KC_TRNS, KC_TRNS, SCMD(KC_UP), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MEH(KC_UP), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
             KC_TRNS, KC_TRNS, SCMD(KC_LEFT), SCMD(KC_DOWN), SCMD(KC_RIGHT), KC_TRNS, KC_TRNS, MEH(KC_LEFT), MEH(KC_DOWN), MEH(KC_RIGHT), KC_TRNS, KC_TRNS, KC_TRNS, 
             KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS),
//gaming layer
[7] = KEYMAP(KC_ESC , KC_1    , KC_2   , KC_3, KC_4   , KC_5, KC_6   , KC_7  , KC_8   , KC_9   , KC_0  , KC_MINS, KC_EQL  , KC_PIPE, KC_GRV, 
             KC_TAB , KC_Q    , KC_W   , KC_E, KC_R   , KC_T, KC_Y   , KC_U  , KC_I   , KC_O   , KC_P  , KC_LBRC, KC_RBRC , KC_BSPC, 
             KC_LCTL, KC_A   , KC_S, KC_D   , KC_F, KC_G   , KC_H  , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT , KC_ENT , 
             KC_LSFT, KC_NO   , KC_Z   , KC_X, KC_C   , KC_V, KC_B   , KC_N  , KC_M   , KC_COMM, KC_DOT, KC_SLSH, KC_RSFT , KC_BSLS, 
             KC_LCTL, KC_LGUI , KC_LALT, KC_SPC, KC_DEL, KC_SPC, TO(0), TG(1)  , KC_NO , TG(4)  , KC_RCTL),
};
