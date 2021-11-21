/* Copyright 2019 Leo Batyuk
 * Copyright 2020 Drashna Jaelre <@drashna>
 * Copyright 2020 @ben_roe (keycapsss.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAME,
    _MOUSE
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define GAME TG(_GAME)
#define MOUSE TG(_MOUSE)
#define COPY LCTL(KC_INS)
#define INSERT LSFT(KC_INS)
#define S_DELETE LSFT(KC_DELETE)
#define AE RALT(KC_Q)
#define UE RALT(KC_Y)
#define OE RALT(KC_P)
#define SS RALT(KC_S)
#define QUAKE LALT(KC_RBRC)
#define A_TAB RALT(KC_TAB)
#define C_TAB RCTL(KC_TAB)
#define BACK LALT(KC_LEFT)
#define FORW LALT(KC_RIGHT)
#define F_LOWER LT(LOWER, KC_F)
#define J_RAISE LT(RAISE, KC_J)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,--------------------------------------------.                    ,----------------------------------------------.
 * |    `    |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -        |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |   Tab   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  BS       |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |   ESC   |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '/RSHIFT |
 * |---------+------+------+------+------+------|   (   |    |    )  |------+------+------+------+------+-----------|
 * |  LCTRL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RCTRL/Ent  |
 * `--------------------------------------------|      /      \      \----------------------------------------------'
 *               | WIN  | LOWER | LALT | LOWER | Space/        \ RSFT | RAISE | RALT  | RAISE | APP  |
 *                `----------------------------------'          '------------------------------------'
 */

 [_QWERTY] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    KC_ESC,   KC_A,    KC_S,   KC_D, F_LOWER,    KC_G,                            KC_H, J_RAISE,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LPRN,  KC_RPRN,      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, RCTL_T(KC_ENT),
                      KC_LGUI, TG(_MOUSE), KC_LALT, LOWER, LSFT_T(KC_SPC), RSFT_T(KC_ENT),   RAISE,   KC_RALT, LOWER, KC_APP
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | SDEL |  DEL | Pos1 | PgUp | DEL  |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |      |A-TAB |A-TAB | End  |PgDown|  APP |-------|    |-------| APP  | COPY |INSERT| QUAKE| BSLS |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *             | WIN  | LOWER | LALT | LOWER | Space/       \ RSFT | RAISE | RALT  | RAISE | APP  |
 *              `----------------------------------'         '------------------------------------'
 */

[_LOWER] = LAYOUT(
    _______,   KC_F1,    KC_F2,   KC_F3,    KC_F4,    KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
     KC_GRV,    KC_1,     KC_2,    KC_3,     KC_4,     KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
    _______,S_DELETE,KC_DELETE, KC_HOME,  KC_PGUP,KC_DELETE,                     KC_LEFT, KC_DOWN,   KC_UP,  KC_RGHT,XXXXXXX, XXXXXXX,
    _______,   A_TAB,    A_TAB,  KC_END,  KC_PGDN,   KC_APP,   KC_LBRC,  KC_RBRC,  KC_APP,    COPY,  INSERT,    QUAKE, KC_NUBS, _______,
                        _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______
),
/* RAISE
 * ,-------------------------------------------.                    ,-----------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |        |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |   0  | F12  |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |        |      |  ß   |  -   |  =   | DEL  |-------.    ,-------|  ML  |  MD  |  MU  |  ML  |      |      |
 * |--------+------+------+------+------+------|   {   |    |   }   |------+------+------+------+------+------|
 * |        |A-TAB |   ä  |  ü   |  ö   |  ß   |-------|    |-------|  MB1 |  MB2 | MB3  |      |      |      |
 * `-------------------------------------------|       /     \      \-----------------------------------------'
 *               | WIN  | LOWER | LALT | LOWER | Space/       \ MB1  | RAISE | RALT  | RAISE | APP  |
 *                `----------------------------------'         '------------------------------------'
 */

[_RAISE] = LAYOUT(
    _______,   KC_F1,   KC_F2,    KC_F3,  KC_F4,    KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    _______,    KC_1,    KC_2,     KC_3,   KC_4,     KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
    _______, _______,      SS,  KC_MINS, KC_EQL,KC_DELETE,                   KC_MS_L, KC_MS_L, KC_MS_U, KC_MS_R, _______, _______,
    _______,   A_TAB,      AE,       UE,      OE,      SS, KC_LCBR, KC_RCBR, KC_BTN1, KC_BTN2, KC_MS_D, KC_BTN3, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* ADJUST (Press LOWER and RAISE together)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |RESET |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB ON| HUE+ | SAT+ | VAL+ |      |      |                    |      | PREV | PLAY | NEXT |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | MODE | HUE- | SAT- | VAL- |      |      |-------.    ,-------|      | VOL- | MUTE | VOL+ |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|  GAME|MOUSE |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *             | WIN  | LOWER | LALT | LOWER | Space/       \ RSFT | RAISE | RALT  | RAISE | APP  |
 *              `----------------------------------'         '------------------------------------'
 */

[_ADJUST] = LAYOUT(
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    GAME,   MOUSE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
  ),
/* GAME
 * ,--------------------------------------------.                    ,----------------------------------------------.
 * |    `    |   1  |   2  |   3  |   4  |   5  |                    |  F6  |  F7  |  F8  |      | F10  |   F11     |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |   Tab   |  F1  |   Q  |   W  |   E  |   R  |                    |      |      |      |      |      |   F12     |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |   ESC   |Shift |   A  |   S  |   D  |   F  |-------.    ,-------| Left | Down |  Up  |Right |      |           |
 * |---------+------+------+------+------+------|  F5   |    |  F9   |------+------+------+------+------+-----------|
 * |  LCTRL  |  F2  |   Z  |   X  |   C  |   V  |-------|    |-------|      |      |      |      |      |           |
 * `--------------------------------------------|      /      \      \----------------------------------------------'
 *               | WIN  | LOWER | LALT |    F3  |Space/        \ Enter| RAISE | RALT  | RAISE | APP  |
 *                `----------------------------------'          '------------------------------------'
 */

[_GAME] = LAYOUT(
    KC_GRV,      KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                           KC_F6,   KC_F7,   KC_F8, XXXXXXX,  KC_F10,  KC_F11,
    KC_TAB,     KC_F1,   KC_Q,    KC_W,    KC_E,    KC_R,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F12,
    KC_ESC, KC_LSHIFT,   KC_A,    KC_S,    KC_D,    KC_F,                         KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
    KC_LCTRL,   KC_F2,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_F5,      KC_F9,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                           KC_LGUI, LOWER, KC_LALT,  KC_F3,   KC_SPC,   KC_ENT,   RAISE,   KC_RALT,   GAME, KC_APP
 ),
/* MOUSE
 * ,-------------------------------------------.                    ,-----------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |        |      |      |      |      |      |                    |      | Back |  MU  | Forw |      | F12  |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC    |      |      | Pos1 | PgUp | DEL  |-------.    ,-------|      |  ML  |  MD  |  ML  |      |      |
 * |--------+------+------+------+------+------|   {   |    |   }   |------+------+------+------+------+------|
 * |        |      |      | End  |PgDown|  ß   |-------|    |-------|  MB1 |  MB2 |      |  MB3 |      |      |
 * `-------------------------------------------|       /     \      \-----------------------------------------'
 *               | WIN  | LOWER | LALT | LOWER | MB3  /       \ MB1  | RAISE | RALT  | RAISE | APP  |
 *                `----------------------------------'         '------------------------------------'
 */

[_MOUSE] = LAYOUT(
    XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                    XXXXXXX,    BACK, KC_MS_U,    FORW, XXXXXXX,  KC_F12,
    _______, XXXXXXX, XXXXXXX, KC_HOME,  KC_PGUP, KC_DELETE,                  XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
    XXXXXXX, XXXXXXX, XXXXXXX,  KC_END,  KC_PGDN, XXXXXXX,   BACK,    FORW,   KC_BTN1, KC_BTN2, XXXXXXX, KC_BTN3, _______, _______,
                      _______, _______, _______, _______, KC_BTN3, KC_BTN1, _______, _______, _______, _______
 )
// Mouse VIM
//[_MOUSE] = LAYOUT(
//    XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
//    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                    XXXXXXX,    BACK, XXXXXXX,    FORW, XXXXXXX,  KC_F12,
//    _______, XXXXXXX, XXXXXXX, KC_HOME,  KC_PGUP, KC_DELETE,                  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
//    XXXXXXX, XXXXXXX, XXXXXXX,  KC_END,  KC_PGDN, XXXXXXX,   BACK,    FORW,   KC_BTN1, KC_BTN2, XXXXXXX, KC_BTN3, _______, _______,
//                      _______, _______, _______, _______, KC_BTN3, KC_BTN1, _______, _______, _______, _______
// )
};


layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_270;
    }
}

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0};
    oled_write_P(corne_logo, false);
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_ADJUST)) {
        oled_write_P(adjust_layer, false);
    } else if(layer_state_is(_LOWER)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_RAISE)) {
        oled_write_P(raise_layer, false);
    } else if(layer_state_is(_MOUSE)) {
        oled_write_P(PSTR("MOUSE\n"), false);
        render_space();
    } else if(layer_state_is(_GAME)) {
        oled_write_P(PSTR("GAME\n"), false);
        render_space();
        render_space();
    } else {
        oled_write_P(default_layer, false);
    }
}

void render_status_main(void) {
    render_space();
    render_space();
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

void render_status_secondary(void) {
    render_space();
    render_space();
    render_logo();
    render_space();
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}

#endif
