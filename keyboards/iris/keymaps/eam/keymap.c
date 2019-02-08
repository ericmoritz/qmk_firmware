#include QMK_KEYBOARD_H

#include "keymap.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_CESC MT(MOD_LCTL, KC_ESC)
#define KC_CSPC MT(MOD_LCTL, KC_SPC)
#define KC_CENT MT(MOD_LCTL, KC_ENT)
#define KC_OSLK LCTL(LGUI(KC_Q))
#define KC_RGB_TOG RGB_TOG

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GESC, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0 ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSPC ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CESC, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,LBRC,     RBRC , N  , M  ,COMM,DOT ,SLSH,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,LGUI,CSPC,        CENT ,LOWR,RASE
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,WAKE,OSLK,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,HOME, UP ,END ,PGUP,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,TILD,PIPE,MINS,PLUS,    ,                   ,LEFT,DOWN,RGHT,PGDN,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         , GRV,BSLS,UNDS, EQL,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
  RGB_TOG,    ,    ,    ,    ,VOLU,                   ,BTN1,MS_U,BTN2,WH_U,F12 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,BTN4,BTN3,BTN2,BTN1,MUTE,                   ,MS_L,MS_D,MS_R,WH_D,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,MPRV,MSTP,MPLY,MNXT,VOLD,    ,         ,    ,BTN3,BTN4,BTN5,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K,                           RGB_M_X,RGB_M_G,RGB_M_T, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RESET  , DEBUG  , RGB_HUD, RGB_SAD, RGB_VAD, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      _______, RGB_RMOD, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,                  _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_lower[][2]      = SONG(COIN_SOUND);
float tone_raise[][2]      = SONG(ONE_UP_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  twinkle(keycode, record);
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}


void twinkle(uint16_t keycode, keyrecord_t *record) {
  uint8_t v = 200;
  if (!record->event.pressed) {
    v = 255;
  }
  switch (keycode % 3) {
      case 0:
        // Pink
        rgblight_sethsv_noeeprom(330, 100, v);
        break;
      case 1:
        // Blue
        rgblight_sethsv_noeeprom(200, 100, v);
        break;
      default:
        // Purple
        rgblight_sethsv_noeeprom(299, 55, v);
        break;
    }
}

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
  case _RAISE:
    // Pink
    rgblight_sethsv_noeeprom(330, 100, 255);
    break;
  case _LOWER:
    // Blue
    rgblight_sethsv_noeeprom(200, 100, 255);
    break;
  case _ADJUST:
    // White
    rgblight_sethsv_noeeprom(0, 0, 255);
    break;
  default: //  for any other layers, or the default layer
    // Purple
    rgblight_sethsv_noeeprom(299, 55, 255);
    break;
  }
  return state;
}
