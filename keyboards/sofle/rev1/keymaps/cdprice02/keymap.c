// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    _DEFAULT,
    _NUMBERS,
    _NAVIGATION,
    _SYMBOLS,
    _FUNCTIONS,
};

enum custom_keycodes { KC_PRVWD = QK_USER, KC_NXTWD, KC_LSTRT, KC_LEND, EN_CCW1, EN_CW1, EN_CCW2, EN_CW2 };

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // clang-format off
    [_DEFAULT] = {ENCODER_CCW_CW(EN_CCW1, EN_CW1)},
    [_NUMBERS] = {ENCODER_CCW_CW(EN_CCW2, EN_CW2)},
    [_NAVIGATION] = {ENCODER_CCW_CW(EN_CCW2, EN_CW2)},
    [_SYMBOLS] = {ENCODER_CCW_CW(EN_CCW2, EN_CW2)},
    [_FUNCTIONS] = {ENCODER_CCW_CW(EN_CCW2, EN_CW2)},
    // clang-format on
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI |      | ESC  | Space| / Tab   /       \Enter \  | Space| DEL  |      | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_DEFAULT] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_TAB, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LGUI, XXXXXXX, KC_ESC, LT(_NAVIGATION, KC_SPC), LT(_FUNCTIONS, KC_TAB), LT(_SYMBOLS, KC_ENT), LT(_NUMBERS, KC_SPC), KC_DEL, XXXXXXX, KC_RGUI),
    /*
     * NAVIGATION
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |      | NXTW |      |      |      |                    | COPY | UNDO |      |      | PSTE |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  | GUI  | ALT  | CTL  | SFT  |      |-------.    ,-------| LEFT | DOWN |  UP  | RGHT |      |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |LShift|      | CUT  |      |      | PRVW |-------|    |-------|      |      |      |      |      |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI |      | ESC  | Space| / Tab   /       \Enter \  | Space| DEL  |      | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_NAVIGATION] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_NXTWD, XXXXXXX, XXXXXXX, XXXXXXX, KC_COPY, KC_UNDO, XXXXXXX, XXXXXXX, KC_PSTE, XXXXXXX, _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_CUT, XXXXXXX, XXXXXXX, KC_PRVWD, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /*
     * FUNCTIONS
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |      |      |      |      |      |                    |NumLck|  F1  |  F2  |  F3  |  F4  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  | GUI  | ALT  | CTL  | SFT  |      |-------.    ,-------|CapLck|  F5  |  F6  |  F7  |  F8  |  '   |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------|    |-------|ScrLck|  F9  |  F10 |  F11 |  F12 |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI |      | ESC  | Space| / Tab   /       \Enter \  | Space| DEL  |      | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_FUNCTIONS] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LNUM, KC_F1, KC_F2, KC_F3, KC_F4, XXXXXXX, _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_LCAP, KC_F5, KC_F6, KC_F7, KC_F8, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_LSCR, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /*
     * SYMBOLS
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |      |      |      |   ~  |   -  |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   {  |   [  |   (  |   '  |   =  |-------.    ,-------|      | SFT  | CTL  | ALT  | GUI  |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |LShift|   }  |   ]  |   )  |   "  |   \  |-------|    |-------|      |      |      |      |      |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI |      | ESC  | Space| / Tab   /       \Enter \  | Space| DEL  |      | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_SYMBOLS] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD, KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_LCBR, KC_LBRC, KC_LPRN, KC_QUOT, KC_EQL, XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX, _______, KC_RCBR, KC_RBRC, KC_RPRN, KC_DQUO, KC_BSLS, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /*
     * NUMBERS
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |      |   7  |   8  |   9  |   -  |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |   4  |   5  |   6  |   =  |-------.    ,-------|      | SFT  | CTL  | ALT  | GUI  |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |LShift|      |   1  |   2  |   3  |   \  |-------|    |-------|      |      |      |      |      |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI |      | ESC  | Space| / Tab   /       \Enter \  | Space| DEL  |      | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_NUMBERS] = LAYOUT(_______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, XXXXXXX, KC_7, KC_8, KC_9, KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_4, KC_5, KC_6, KC_EQL, XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX, _______, XXXXXXX, KC_1, KC_2, KC_3, KC_BSLS, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, LT(_NAVIGATION, KC_0), _______, _______, _______, _______, _______, _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case EN_CCW1:
            if (record->event.pressed) {
                tap_code(KC_VOLU);
            }
            break;
        case EN_CW1:
            if (record->event.pressed) {
                tap_code(KC_VOLD);
            }
            break;
        case EN_CCW2:
            if (record->event.pressed) {
                tap_code(KC_PGDN);
            }
            break;
        case EN_CW2:
            if (record->event.pressed) {
                tap_code(KC_PGUP);
            }
            break;
    }
    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_logo_text(void) {
    oled_write_P(PSTR("sofle"), false);
}

void render_kb_LED_state(void) {
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.num_lock ? PSTR("N ") : PSTR("  "), false);
    oled_write_P(led_usb_state.caps_lock ? PSTR("C ") : PSTR("  "), false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("S ") : PSTR("  "), false);
}

void render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case _DEFAULT:
            oled_write_P(PSTR("Base"), false);
            break;
        case _NUMBERS:
            oled_write_P(PSTR("Num"), false);
            break;
        case _NAVIGATION:
            oled_write_P(PSTR("Nav"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("Sym"), false);
            break;
        case _FUNCTIONS:
            oled_write_P(PSTR("Func"), false);
            break;
        default:
            oled_write_P(PSTR("Unk"), false);
    }
}

bool oled_task_user(void) {
    if (!oled_task_kb()) {
        return false;
    }

    render_space();
    render_logo_text();
    render_space();
    render_layer_state();
    render_space();
    render_kb_LED_state();

    return false;
}
#endif
