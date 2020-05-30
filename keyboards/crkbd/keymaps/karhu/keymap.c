#include QMK_KEYBOARD_H

// include timer for timer_read and timer_elapsed
#include "timer.h"

enum layer {
    LAYER_DEFAULT,
    LAYER_RAISED_LEFT,
    LAYER_RAISED_RIGHT,
    LAYER_RAISED_BOTH,
    LAYER_TOGGLED
};

enum custom_keycodes {
  _A_UML = SAFE_RANGE,
  _DL_WIN, // Desktop Left  when tapped, Win when held
  _DR_ALT, // Desktop Right when tapped, Alt when held
  _O_UML,
  _U_UML,
  _OSMODE
};

enum OS_Mode {
  OS_MODE_WINDOWS = 0,
  OS_MODE_LINUX = 1
};

enum OS_Mode os_mode = OS_MODE_WINDOWS;

#define LY_R_L MO(LAYER_RAISED_LEFT)
#define LY_R_R MO(LAYER_RAISED_RIGHT)
#define LY_TOG TG(LAYER_TOGGLED)

#define KY_CESC LCTL_T(KC_ESC)

#define C_MUL KC_KP_ASTERISK

// Shift when held, Spcace & Enter when tapped.
#define _SH_SPC LSFT_T(KC_SPC)
#define _SH_ENT LSFT_T(KC_ENT)

// German umlauts in a US International Layout.
// see: http://dry.sailingissues.com/us-international-keyboard-layout.html
// #define _A_UML RALT(KC_Q) // A umlaut (ä)
// #define _O_UML RALT(KC_P) // O umlaut (ö)
// #define _U_UML RALT(KC_Y) // U umlaut (ü)

#define _DESK_L LCTL(LGUI(KC_LEFT))
#define _DESK_R LCTL(LGUI(KC_RGHT))
#define _DESK_U LCTL(LGUI(KC_UP))
#define _DESK_D LCTL(LGUI(KC_DOWN))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default layer: http://www.keyboard-layout-editor.com/#/gists/08d9827d916662a9414f48805aa895a5 */
    [LAYER_DEFAULT] = LAYOUT(
        KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     LY_TOG,
        KC_TAB,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_BSPACE,
        KC_LCTRL, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                         KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_QUOT,
                                                _DL_WIN,  LY_R_L,   _SH_ENT,  _SH_SPC,  LY_R_R,   _DR_ALT
    ),

    /* Lower layer: http://www.keyboard-layout-editor.com/#/gists/c3fba5eaa2cd70fdfbdbc0f9e34d3bc0 */
    [LAYER_RAISED_LEFT] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _DESK_U,  _______,  _______,  _______,
        _______,  _A_UML,   _______,  _______,  _______,  _______,                      KC_LCBR,  _DESK_L,  _DESK_D,  _DESK_R,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,                      KC_RCBR,  KC_LPRN,  KC_RPRN,  KC_LBRC,  KC_RBRC,  KC_DEL,
                                                _______,  _______,  _______,  _______,  _______,  _______
    ),

    /* Raise layer: http://www.keyboard-layout-editor.com/#/gists/08b44355d4ca85d294bad9e2821f91d7 */
    [LAYER_RAISED_RIGHT] = LAYOUT(
        KC_AT,    KC_LABK,  KC_RABK,  KC_ASTR,  KC_SLASH, KC_PERC,                      _______,  _U_UML,   KC_UP,    _O_UML,   _______,  _______,
        KC_DLR,   KC_AMPR,  KC_EQUAL, KC_PLUS,  KC_MINUS, KC_CIRC,                      _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,
        _______,  KC_HASH,  KC_EXLM,  KC_QUES,  KC_UNDS,  KC_PIPE,                      _______,  _______,  _______,  _______,  _______,  KC_DEL,
                                                _______,  _______,  _______,  _______,  _______,  _______
    ),

    [LAYER_RAISED_BOTH] = LAYOUT(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                        KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,   KC_F12,
        KC_0,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_EQUAL, KC_6,     KC_7,     KC_8,      KC_9,     _______,
        _______,  _______,  _______,  _______,  _______,  _______,                      KC_PLUS,  KC_MINUS, KC_COMM,  KC_DOT,    C_MUL,    KC_DEL,
                                                _______,  _______,  _______,  _______,  _______,  _______
    ),

    [LAYER_TOGGLED] = LAYOUT(
        _OSMODE,  _______,  KC_MPLY,  KC_VOLU,  KC_MSTP,  _______,                      RESET,    RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  _______,  KC_MPRV,  KC_VOLD,  KC_MNXT,  _______,                      RGB_RMOD, RGB_VAI,  RGB_SAI,  RGB_HUI,  RGB_SPI,  _______,
        _______,  _______,  _______,  KC_MUTE,  _______,  _______,                      RGB_MOD,  RGB_VAD,  RGB_SAD,  RGB_HUD,  RGB_SPD,  RGB_TOG,
                                                _______,  _______,  _______,  _______,  _______,  _______
    )

};

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// For Windows, send special characters using ALT + NUMPAD
// see https://www.alt-codes.net/how_to_use_alt_codes/
void alt_code(uint8_t v0, uint8_t v1, uint8_t v2, uint8_t v3) {
  // save, then restet modifier state
  const uint8_t _real_mods = get_mods();
  clear_mods();
  // remember numlock state
  uint8_t num_lock = host_keyboard_leds() & (1<<USB_LED_NUM_LOCK);
  // activate numlock if necessary
  if (!num_lock) {
      register_code(KC_NUMLOCK);
      unregister_code(KC_NUMLOCK);
  }

  register_code(KC_RALT);
      if (v0) tap_code(KC_KP_ENTER + v0); else tap_code(KC_P0);
      if (v1) tap_code(KC_KP_ENTER + v1); else tap_code(KC_P0);
      if (v2) tap_code(KC_KP_ENTER + v2); else tap_code(KC_P0);
      if (v3) tap_code(KC_KP_ENTER + v3); else tap_code(KC_P0);
  unregister_code(KC_RALT);

  // disable numlock if necessary
  if (!num_lock) {
      register_code(KC_NUMLOCK);
      unregister_code(KC_NUMLOCK);
  }

  // restore modifier state
  set_mods(_real_mods);
}

void matrix_init_user(void) {
  set_unicode_input_mode(UC_LNX);
};

void send_a_umlaut(bool shift) {
  if (os_mode == OS_MODE_WINDOWS) {
    if (shift) {
      alt_code(0,1,9,6);
    } else {
      alt_code(0,2,2,8);
    }
  } else {
    if (shift) {
        send_unicode_hex_string("00C4");
    } else {
        send_unicode_hex_string("00E4");
    }
  }
}

void send_u_umlaut(bool shift) {
  if (os_mode == OS_MODE_WINDOWS) {
    if (shift) {
      alt_code(0,2,2,0);
    } else {
      alt_code(0,2,5,2);
    }
  } else {
    if (shift) {
        send_unicode_hex_string("00DC");
    } else {
        send_unicode_hex_string("00FC");
    }
  }
}

void send_o_umlaut(bool shift) {
  if (os_mode == OS_MODE_WINDOWS) {
    if (shift) {
      alt_code(0,2,1,4);
    } else {
      alt_code(0,2,4,6);
    }
  } else {
    if (shift) {
        send_unicode_hex_string("00D6");
    } else {
        send_unicode_hex_string("00F6");
    }
  }
}

uint16_t _DL_WIN_timer = 0;
uint16_t _DR_ALT_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _A_UML:
      if (record->event.pressed) {
        send_a_umlaut(get_mods() & MODS_SHIFT_MASK);
        return false;
      }
      break;
    case _U_UML:
      if (record->event.pressed) {
        send_u_umlaut(get_mods() & MODS_SHIFT_MASK);
        return false;
      }
      break;
    case _O_UML:
      if (record->event.pressed) {
        send_o_umlaut(get_mods() & MODS_SHIFT_MASK);
        return false;
      }
      break;
    case _OSMODE:
      if (record->event.pressed) {
        os_mode = 1 - os_mode; // toggle between 0 and 1
        return false;
      }
      break;
    case _DL_WIN:
      if (record->event.pressed) {
        _DL_WIN_timer = timer_read();
        register_code(KC_LWIN);
      } else {
        if (timer_elapsed(_DL_WIN_timer) > 250) {
          unregister_code(KC_LWIN);
        } else {
          // Tap case
          if (os_mode == OS_MODE_WINDOWS) {
            tap_code16(LCTL(KC_LEFT));
            unregister_code(KC_LWIN);
          } else {
            unregister_code(KC_LWIN);
            tap_code16(LCTL(LALT(KC_LEFT)));
          }
        }
      }
      return false;
    case _DR_ALT:
      if (record->event.pressed) {
        _DR_ALT_timer = timer_read();
        register_code(KC_RALT);
      } else {
        if (timer_elapsed(_DR_ALT_timer) > 250) {
          unregister_code(KC_RALT);
        } else {
          // Tap case
          if (os_mode == OS_MODE_WINDOWS) {
            unregister_code(KC_RALT);
            tap_code16(LGUI(LCTL(KC_RIGHT)));
          } else {
            tap_code16(LCTL(KC_RIGHT));
            unregister_code(KC_RALT);
          }
        }
      }
      return false;
  }
  return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, LAYER_RAISED_LEFT, LAYER_RAISED_RIGHT, LAYER_RAISED_BOTH);
}
