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

/*****************************************************************************/
/*                                 Tap Dance                                  */
/*****************************************************************************/
void eam_lssc(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 1) {
    if(!state->pressed) {
      register_code(KC_LSFT);
      register_code(KC_9);
    } else {
      register_code(KC_LSFT);
    }
  } else if (state->count == 2) {
    register_code(KC_LSFT);
    register_code(KC_LBRC);
  } else if (state->count == 3) {
    register_code(KC_LBRC);
  }
}

void eam_lssc_reset(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 1) {
    if(!state->pressed) {
      unregister_code(KC_LSFT);
      unregister_code(KC_9);
      unregister_code(KC_LSFT);
    } else {
      unregister_code(KC_LSFT);
    }
  } else if (state->count == 2) {
    unregister_code(KC_LSFT);
    unregister_code(KC_LBRC);
  } else if (state->count == 3) {
    unregister_code(KC_LBRC);
  }
}

void eam_rssc(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 1) {
    if(!state->pressed) {
      register_code(KC_LSFT);
      register_code(KC_0);
    } else {
      register_code(KC_RSFT);
    }
  } else if (state->count == 2) {
    register_code(KC_LSFT);
    register_code(KC_RBRC);
  } else if (state->count == 3) {
    register_code(KC_RBRC);
  }
}

void eam_rssc_reset(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 1) {
    if(!state->pressed) {
      unregister_code(KC_LSFT);
      unregister_code(KC_0);
      unregister_code(KC_RSFT);
    } else {
      unregister_code(KC_RSFT);
    }
  } else if (state->count == 2) {
    unregister_code(KC_LSFT);
    unregister_code(KC_RBRC);
  } else if (state->count == 3) {
    unregister_code(KC_RBRC);
  }
}


enum {
      // Left Super Space Cadet Shift
      TD_LSSCS = 0,
      TD_RSSCS
};

qk_tap_dance_action_t tap_dance_actions[] = {
                                             [TD_LSSCS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, eam_lssc, eam_lssc_reset),
                                             [TD_RSSCS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, eam_rssc, eam_rssc_reset),
};


#define KC_ KC_TRNS
#define _______ KC_TRNS
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_CESC CTL_T(KC_ESC)
#define KC_CSPC CTL_T(KC_SPC)
#define KC_CENT CTL_T(KC_ENT)
#define KC_OSLK LCTL(LGUI(KC_Q))
#define KC_RGB_TOG RGB_TOG
#define KC_LSSC TD(TD_LSSCS)
#define KC_RSSC TD(TD_RSSCS)

/*****************************************************************************/
/*                                pointer mods                               */
/*****************************************************************************/
// This makes the TGB and YHN keys GUI, CTRL, and ALT for both hands

#define KC_LTT GUI_T(KC_T)
#define KC_LTG CTL_T(KC_G)
#define KC_LTB ALT_T(KC_B)
#define KC_RTY RGUI_T(KC_Y)
#define KC_RTH RCTL_T(KC_H)
#define KC_RTN RALT_T(KC_N)
/*****************************************************************************/
/*                                Layout                                     */
/*****************************************************************************/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    LBRC, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0 ,RBRC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  ,LTT ,               RTY , U  , I  , O  , P  ,BSPC ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ESC , A  , S  , D  , F  ,LTG ,               RTH , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSSC, Z  , X  , C  , V  ,LTB ,    ,         ,RTN , M  ,COMM,DOT ,SLSH,RSSC,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,SPC,         ENT,LOWR,RASE
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,WAKE,OSLK,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,HOME, UP ,END ,PGUP,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,TILD,PIPE,PLUS,MINS,    ,               PGDN,LEFT,DOWN,RGHT,PGDN,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,GRV ,BSLS,EQL ,UNDS,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
  RGB_TOG,    ,    ,    ,    ,VOLU,               WH_U,BTN1,MS_U,BTN2,WH_U,F12 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
          ,BTN4,BTN3,BTN2,BTN1,MUTE,               WH_D,MS_L,MS_D,MS_R,WH_D,    ,
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
}

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
  case _RAISE:
    // Pink
    rgblight_sethsv_noeeprom(330, 255, 255);
    break;
  case _LOWER:
    // Blue
    rgblight_sethsv_noeeprom(240, 255, 255);
    break;
  case _ADJUST:
    // White
    rgblight_sethsv_noeeprom(0, 0, 255);
    break;
  default: //  for any other layers, or the default layer
    // Purple
    rgblight_sethsv_noeeprom(299, 140, 163);
    break;
  }
  return state;
}
