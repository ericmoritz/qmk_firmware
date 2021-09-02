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

#include "oled.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 */

[_QWERTY] = LAYOUT(
//,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
   KC_GRV , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                      KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_OSLK,
//|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                      KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSPC,
//|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   KC_ESC , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                      KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
//|-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
   KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,KC_MUTE,     KC_MPLY, KC_N  , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
//`-------+-------+-------+-------+-------+-------+-------     |-------+-------+-------+-------+-------+-------+-------'
                    KC_LGUI,KC_LALT,KC_LCTL,KC_LOWR, KC_SPC,    KC_ENT ,KC_RASE,KC_RCTL,KC_LALT,KC_RGUI
//                `-------+-------+-------+-------+-------'    `-------+-------+-------+-------+-------'
),
/* LOWER
 */
[_LOWER] = LAYOUT(
//,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
   _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,
//|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   _______,KC_BSLS,KC_ASTR,KC_PLUS,KC_MINS,_______,                     _______,KC_UNDS,_______,_______,_______,_______,
//|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   _______,KC_EQL ,KC_LBRC,KC_LCBR,KC_LPRN,KC_LT  ,                     KC_GT  ,KC_RPRN,KC_RCBR,KC_RBRC,KC_PIPE,_______,
//|-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
   _______,_______,_______,_______,_______,_______,_______,     _______,_______,_______,_______,_______,_______,_______,
//`-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------'
                   _______,_______,_______,_______,_______,     KC_EQL ,_______,_______,_______,_______
//                `-------+-------+-------+-------+-------'    `-------+-------+-------+-------+-------'
),
/* RAISE
 */
[_RAISE] = LAYOUT(
//,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
   _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,KC_MINS,KC_EQL ,
//|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   _______,KC_BSLS,KC_ASTR,KC_PLUS,KC_MINS,_______,                     _______,_______,_______,KC_LBRC,KC_RBRC,KC_BSLS,
//|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   _______,KC_EQL ,KC_LBRC,KC_LCBR,KC_LPRN,KC_LT  ,                     KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,_______,_______,
//`-------+-------+-------+-------+-------+-------+-------.    .-------+-------+-------+-------+-------+-------+-------|
   _______,_______,_______,_______,_______,_______,_______,     _______,_______,_______,_______,_______,_______,_______,
//`-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------'
                   _______,_______,_______,_______,KC_UNDS,     _______,_______,_______,_______,_______
//                `-------+-------+-------+-------+-------'    `-------+-------+-------+-------+-------'
),
/* ADJUST
 */
  [_ADJUST] = LAYOUT(
//,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
//|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
    RESET ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
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
#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    }
    return true;
}

#endif
