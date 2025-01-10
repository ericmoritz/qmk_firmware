#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWR,
    KC_RASE,
    KC_ADJ,
    KC_OSLK // OS Lock
};

bool isSneaking = false;
bool isJumping = false;
bool isBarking = false;
bool showedJump = true;
bool anyKeyPressed = false;
bool guiPressed = false;
bool altPressed = false;
bool ctrlPressed = false;

#include "oled.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 */

[_QWERTY] = LAYOUT(
//,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
   KC_GRV , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                      KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_DEL ,
//|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                      KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSPC,
//|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   KC_ESC , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                      KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
//|-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
   KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,KC_MPLY,     KC_MUTE, KC_N  , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
//`-------+-------+-------+-------+-------+-------+-------     |-------+-------+-------+-------+-------+-------+-------'
                    KC_LGUI,KC_LALT,KC_LCTL,KC_LOWR,KC_SPC,     KC_ENT ,KC_LOWR,KC_RCTL,KC_LALT,KC_RGUI
//                `-------+-------+-------+-------+-------'    `-------+-------+-------+-------+-------'
),
/* LOWER
   [({})]
   +-=

*/
[_LOWER] = LAYOUT(
                  //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
                     KC_TILD,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,                     KC_CIRC,KC_AMPR,KC_ASTR,_______,_______,_______,
                  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
                     _______,_______,KC_LBRC,KC_LPRN,KC_LCBR,_______,                     _______,KC_RCBR,KC_RPRN,KC_RBRC,_______,KC_BSLS,
                     //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
                     _______,_______,KC_PLUS,KC_MINS,KC_EQL,_______,                      KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_COLN,KC_DQUO,
                     //`-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
                     _______,_______,_______,KC_UNDS,KC_PIPE,_______,_______,     _______,_______,_______,KC_LABK,KC_RABK,KC_QUES,_______,
                     //`-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------'
                     _______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______
                     //                `-------+-------+-------+-------+-------'    `-------+-------+-------+-------+-------'
                  ),
// NOTE: I don't use this layer
/* RAISE
 */
[_RAISE] = LAYOUT(
                   //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                   //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                   //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                   //`-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                   //`-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------'
                   _______,_______,_______,_______,_______,     _______,_______,_______,_______,_______
                   //                `-------+-------+-------+-------+-------'    `-------+-------+-------+-------+-------'
                  ),
/* ADJUST
 */
[_ADJUST] = LAYOUT(
                   //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
                    KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                      KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11,
                   //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
                   QK_BOOT,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                   //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                   //`-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                   //`-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------'
                   _______,_______,_______,_______,_______,     _______,_______,_______,_______,_______
                   //                `-------+-------+-------+-------+-------'    `-------+-------+-------+-------+-------'
                   )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    anyKeyPressed = record->event.pressed;

    switch (keycode) {
        case KC_LOWR:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RASE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJ:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_OSLK:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_mods(mod_config(MOD_LGUI));
                register_code(KC_Q);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_mods(mod_config(MOD_LGUI));
                unregister_code(KC_Q);
            }
            return false;

        /* KEYBOARD PET STATUS START */
        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
                ctrlPressed = true;
            } else {
                isSneaking = false;
                ctrlPressed = false;
            }
            break;
        case KC_LALT:
        case KC_RALT:
            if (record->event.pressed) {
                altPressed = true;
            } else {
                altPressed = false;
            }
            break;
        case KC_LGUI:
        case KC_RGUI:
            if (record->event.pressed) {
                guiPressed = true;
                isBarking = true;
            } else {
                guiPressed = false;
                isBarking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
        /* KEYBOARD PET STATUS END */

    }
    return true;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    { ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif
