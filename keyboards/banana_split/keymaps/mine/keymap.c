#include "banana_split.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define BASE_LAYER 0
// #define QWERTY_LAYER 1
#define ARROW_LAYER 1
#define FN_LAYER 2
#define UI_LAYER 3
#define GAMING_LAYER 4

#define _______ KC_TRNS
#define XXXXXXX KC_NO

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
[BASE_LAYER] = KEYMAP(
  KC_ESC         , KC_1    , KC_2   , KC_3        , KC_4   , KC_5        , KC_6   , KC_7  , KC_8            , KC_9    , KC_0    , KC_MINUS, KC_EQL  , KC_PIPE, KC_GRV, 
  KC_TAB         , KC_Q    , KC_W   , KC_F        , KC_P   , KC_B        , KC_J   , KC_L  , KC_U            , KC_Y    , KC_SCLN , KC_LBRC , KC_RBRC , KC_BSPC, 
  LT(ARROW_LAYER , KC_BSPC), KC_A   , KC_R        , KC_S   , KC_T        , KC_G   , KC_K  , KC_N            , KC_E    , KC_I    , KC_O    , KC_QUOT , KC_ENT , 
  KC_LSFT        , XXXXXXX , KC_X   , KC_C        , KC_D   , KC_V        , KC_Z   , KC_M  , KC_H            , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT , KC_BSLS, 
  KC_LCTL        , KC_LGUI , KC_LALT, LT(UI_LAYER , KC_SPC), LT(FN_LAYER , KC_DEL), KC_SPC, TO(GAMING_LAYER), KC_DOWN , XXXXXXX , KC_UP   , KC_RCTL),

//media + arrows
[ARROW_LAYER] = KEYMAP(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, SMALL_ARROW, FAT_ARROW, _______, KC_TRNS, 
  _______, _______, KC_VOLU, _______, _______, _______, _______, _______, KC_UP, _______, _______, _______, _______, _______, 
  _______, _______, KC_VOLD, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______,
  _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_CAPS, _______, 
  _______, _______, _______, _______, _______, _______, _______, KC_MPRV, XXXXXXX, KC_MPLY, KC_MNXT),
//fkeys + pgup + home + etc...
[FN_LAYER] = KEYMAP(
  KC_GRV , KC_F1  , KC_F2        , KC_F3        , KC_F4         , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10  , KC_F11 , KC_F12 , RESET  , _______, 
  _______, _______, _______      , LGUI(KC_UP)  , _______       , _______, _______, _______, KC_PGUP, _______, _______ , _______, _______, KC_INS, 
  _______, _______, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RIGHT), _______, _______, KC_HOME, KC_PGDN, KC_END , _______ , _______, _______, 
  _______, XXXXXXX, _______      , _______      , _______       , _______, _______, _______, _______, _______, _______ , _______, _______, _______, 
  _______, _______, _______      , _______      , _______       , _______, _______, _______, XXXXXXX, KC_INS , _______),


//moving around the UI         
[UI_LAYER] = KEYMAP(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
  _______, _______, _______, SCMD(KC_UP), _______, _______, _______, _______, MEH(KC_UP), _______, _______, _______, _______, _______, 
  _______, _______, SCMD(KC_LEFT), SCMD(KC_DOWN), SCMD(KC_RIGHT), _______, _______, MEH(KC_LEFT), MEH(KC_DOWN), MEH(KC_RIGHT), _______, _______, _______, 
  _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______),
//gaming layer
[GAMING_LAYER] = KEYMAP(
  KC_ESC , KC_1    , KC_2   , KC_3  , KC_4  , KC_5  , KC_6 , KC_7  , KC_8    , KC_9   , KC_0    , KC_MINS , KC_EQL  , KC_PIPE, KC_GRV, 
  KC_TAB , KC_Q    , KC_W   , KC_E  , KC_R  , KC_T  , KC_Y , KC_U  , KC_I    , KC_O   , KC_P    , KC_LBRC , KC_RBRC , KC_BSPC, 
  KC_LCTL, KC_A    , KC_S   , KC_D  , KC_F  , KC_G  , KC_H , KC_J  , KC_K    , KC_L   , KC_SCLN , KC_QUOT , KC_ENT  , 
  KC_LSFT, XXXXXXX , KC_Z   , KC_X  , KC_C  , KC_V  , KC_B , KC_N  , KC_M    , KC_COMM, KC_DOT  , KC_SLSH , KC_RSFT , KC_BSLS, 
  KC_LCTL, KC_LGUI , KC_LALT, KC_SPC, KC_DEL, KC_SPC, TO(BASE_LAYER), XXXXXXX , XXXXXXX , XXXXXXX  , KC_RCTL),
};
