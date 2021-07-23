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

#define KC_ KC_TRNS
#define _______ KC_TRNS

// Layer keys
#define KC_NAV MO(_NAV)
#define KC_NUM MO(_NUM)
#define KC_FUNC MO(_FUNC)
#define KC_SYM MO(_SYM)
#define KC_MOUS MO(_MOUSE)

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
#define KC_NWIN LGUI(KC_TAB)
#define KC_PWIN LGUI(LSFT(KC_TAB))
#define KC_SENT RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,    ,LCTL,LGUI,LALT,HOME,               END ,RALT,RGUI,RCTL,DEL ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,STAB,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,ENT ,SENT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,MOUS,         , N  , M  ,COMM,DOT ,SLSH,SENT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       NUM ,NAV ,SPC ,         SPC ,SYM ,FUNC
  //                  `----+----+----'        `----+----+----'
  ),


  [_FUNC] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,F7  ,F8  ,F9  ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LOCK,MAXM,CAPS,MOVE,VOLU,                   ,F4  ,F5  ,F6  ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,MUTE,                   ,F1  ,F2  ,F3  ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,MPRV,MSTP,MPLY,MNXT,VOLD,    ,         ,    ,    ,    ,    ,   ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_NAV] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,ESC ,    ,               BSPC,PGUP,UP  ,PGDN,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               BSPC,LEFT,DOWN,RGHT,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,HUDO,HCUT,HCPY,HPST,HRDO,    ,         ,    ,HOME,DEL ,END ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),


  [_SYM] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,COLN,MINS,QUOT,PLUS,AMPR,               RBRC,RCBR,RPRN,GT  ,BSLS,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,SCLN,UNDS,DQUO,EQL ,PIPE,               LBRC,LCBR,LPRN,LT  ,SLSH,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,EXLM,QUES,AT  ,DLR ,ASTR,    ,         ,HASH,CIRC,PERC,TILD,GRV ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),


  [_NUM] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,P7  ,P8  ,P9  ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,PSLS,PAST,PCMM,    ,                   ,P4  ,P5  ,P6  ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,PMNS,PPLS,PEQL,    ,                   ,P1  ,P2  ,P3  ,PENT,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,P0  ,P0  ,PDOT,PENT,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_MOUSE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               ACL0,BTN1,MS_U,BTN2,WH_U,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               ACL1,MS_L,MS_D,MS_R,WH_D,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,ACL2,BTN3,BTN4,BTN5,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  )


};