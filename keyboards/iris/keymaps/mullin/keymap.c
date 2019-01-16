#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _NAV 1
#define _NUM 2
#define _FUNC 3
#define _SYM 4
#define _MOUSE 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAV,
  NUM,
  FUNC,
  SYM,
  MOUSE,
  ZEROS
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

// Layer keys
#define KC_NAV NAV
#define KC_NUM NUM
#define KC_FUNC FUNC
#define KC_SYM SYM
#define KC_MOUS MOUSE

// Num layer
#define KC_000 ZEROS
#define KC_STAB LSFT(KC_TAB)
#define KC_RST RESET

#define KC_REDO LSFT(KC_UNDO)
#define KC_LOCK KC_SLEP
#define KC_MAXM LALT(KC_F10)
#define KC_MOVE KC_NO

#define KC_HCUT LGUI(KC_X)
#define KC_HCPY LGUI(KC_C)
#define KC_HPST LGUI(KC_V)
#define KC_HPNX LALT(KC_Y)
#define KC_HUDO LGUI(KC_Z)
#define KC_HRDO LGUI(LSFT(KC_Z))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,LGUI,LCTL,LSFT,LALT,TAB ,               STAB,RALT,RSFT,RCTL,RGUI,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     MOUS, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,ENT ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         , Z  , X  , C  , V  , B  ,    ,         , N  , M  ,COMM,DOT ,SLSH,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       FUNC,NAV ,SPC ,         SPC ,SYM ,NUM
  //                  `----+----+----'        `----+----+----'
  ),

  [_NAV] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,LGUI,LCTL,LSFT,LALT,TAB ,               STAB,RALT,RSFT,RCTL,RGUI,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,ENT ,STAB,TAB ,ESC ,DEL ,               STAB,PGUP,UP  ,PGDN,MENU,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     MOUS,LGUI,LCTL,LSFT,LALT,BSPC,               BSPC,LEFT,DOWN,RGHT,ENT ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,HUDO,HCUT,HCPY,HPST,HPNX,    ,         ,TAB ,HOME,DEL ,END ,HRDO,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       FUNC,NAV ,SPC ,         SPC ,SYM ,NUM
  //                  `----+----+----'        `----+----+----'
  ),

  [_NUM] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,LGUI,LCTL,LSFT,LALT,TAB ,               STAB,RALT,RSFT,RCTL,RGUI,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,EXLM,STAB,TAB ,PEQL,CIRC,               PMNS,P7  ,P8  ,P9  ,PAST,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     MOUS,LGUI,LCTL,LSFT,LALT,BSPC,               PPLS,P4  ,P5  ,P6  ,PENT,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,LPRN,LT  ,PERC,GT  ,RPRN,    ,         ,P0  ,P1  ,P2  ,P3  ,PSLS,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       FUNC,NAV ,SPC ,         SPC ,SYM ,NUM
  //                  `----+----+----'        `----+----+----'
  ),


  [_FUNC] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,LGUI,LCTL,LSFT,LALT,TAB ,               STAB,RALT,RSFT,RCTL,RGUI,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LOCK,MAXM,CAPS,MOVE,VOLU,               PGUP,F7  ,F8  ,F9  ,F10 ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     MOUS,LGUI,LCTL,LSFT,LALT,MUTE,               BSPC,F4  ,F5  ,F6  ,F11 ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,MPRV,MSTP,MPLY,MNXT,VOLD,    ,         ,PLUS,F1  ,F2  ,F3  ,F12,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       FUNC,NAV ,SPC ,         SPC ,SYM ,NUM
  //                  `----+----+----'        `----+----+----'
  ),

  [_SYM] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,LGUI,LCTL,LSFT,LALT,TAB ,               STAB,RALT,RSFT,RCTL,RGUI,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,COLN,MINS,QUOT,PLUS,AMPR,               RBRC,RCBR,RPRN,GT  ,BSLS,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     MOUS,SCLN,UNDS,DQUO,EQL ,PIPE,               LBRC,LCBR,LPRN,LT  ,SLSH,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,EXLM,QUES,AT  ,DLR ,ASTR,    ,         ,HASH,CIRC,PERC,TILD,GRV ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       FUNC,NAV ,SPC ,         SPC ,SYM ,NUM
  //                  `----+----+----'        `----+----+----'
  ),

  [_MOUSE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,LGUI,LCTL,LSFT,LALT,TAB ,               STAB,RALT,RSFT,RCTL,RGUI,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,BTN1,MS_U,BTN2,WH_U,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     MOUS,    ,    ,    ,    ,    ,                   ,MS_L,MS_D,MS_R,WH_D,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       FUNC,NAV ,SPC ,         SPC ,SYM ,NUM
  //                  `----+----+----'        `----+----+----'
  )


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
      } else {
        layer_off(_NAV);
      }
      return false;
      break;
    case NUM:
      if (record->event.pressed) {
        layer_on(_NUM);
      } else {
        layer_off(_NUM);
      }
      return false;
      break;
    case FUNC:
      if (record->event.pressed) {
        layer_on(_FUNC);
      } else {
        layer_off(_FUNC);
      }
      return false;
      break;
  case SYM:
      if (record->event.pressed) {
          layer_on(_SYM);
      } else {
          layer_off(_SYM);
      }
      return false;
      break;
  case MOUSE:
      if (record->event.pressed) {
          layer_on(_MOUSE);
      } else {
          layer_off(_MOUSE);
      }
      return false;
      break;
  case ZEROS:
      if (record->event.pressed) {
          SEND_STRING("000");
      }
      return false;
      break;
  }
  return true;
}
