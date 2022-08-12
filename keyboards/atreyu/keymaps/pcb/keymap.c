/* Copyright 2021 heyzeus <climent@gmail.com>
 * Copyright 2018 dek <dek@yolops.net>
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
#include "atreyu.h"
#include "eeconfig.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _NAV 4
#define _SYM 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LWR,
  RSE,
  ADJ,
  NAV,
  SYM
};

#define KC_ KC_TRNS

#define KC_FN FN
#define KC_LWR LWR
#define KC_RSE RSE
#define KC_NAV NAV
#define KC_SYM SYM
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_BL_T BL_TOGG
#define KC_LCTL_T LCTL_T
#define KC_GUI_T GUI_T
#define KC_ALT_T ALT_T

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
     KC_ESC  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                    KC_6   , KC_7   , KC_8   , KC_9   , KC_0    ,KC_EQL ,
     KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                    KC_Y   , KC_U   , KC_I   , KC_O   , KC_P    ,KC_BSPC ,
     KC_GRV  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                    KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN ,LT(_SYM,KC_QUOT) ,
     KC_LSFT , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                    KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH ,KC_MINS,
     KC_LCTRL,         KC_LALT , KC_LGUI, LWR    , KC_ENT , KC_LBRC , KC_RBRC, KC_SPC , RSE    , KC_NO  ,  KC_NO , NAV
                
  ),

[_RAISE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX, XXXXXXX, KC_UP  , XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL , 
  XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,                    XXXXXXX, G(A(KC_LEFT)), G(A(KC_RGHT)), XXXXXXX, XXXXXXX, XXXXXXX, 
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C(KC_A),                    C(KC_E), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, A(KC_B),  A(KC_F), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX
),

[_LOWER] = LAYOUT(
  XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                    XXXXXXX, KC_P7  , KC_P8  , KC_P9  , XXXXXXX, XXXXXXX, 
  XXXXXXX, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                    XXXXXXX, KC_P4  , KC_P5  , KC_P6  , XXXXXXX, KC_DEL , 
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_P1  , KC_P2  , KC_P3  , XXXXXXX, XXXXXXX, 
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_COMM, KC_P0  , KC_DOT , KC_BSLS, XXXXXXX, 
  XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX
),

[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX
),

[_NAV] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, 
  XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID,  KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX
),

[_SYM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX
)

};

#ifdef COMBO_ENABLE

enum combo_events {
    CAPS_LOCK,
    C_A_LOCK_L,
    C_A_LOCK_R,
    EM_EMAIL,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM caps_lock[] = {KC_LSFT, KC_RSFT, COMBO_END};
const uint16_t PROGMEM c_a_lock_r[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM c_a_lock_l[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM email_combo[] = {KC_ESC, KC_GRV, COMBO_END};
combo_t key_combos[] = {
    COMBO(caps_lock, KC_CAPS),
    COMBO(c_a_lock_r, C(KC_LALT)),
    COMBO(c_a_lock_l, C(KC_LALT)),
    COMBO_ACTION(email_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case EM_EMAIL:
      if (pressed) {
        SEND_STRING("climent@gmail.com");
      }
      break;
  }
}

#endif


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();
  switch (keycode) {
    case LT(_SYM,KC_QUOT):
      // Intercept hold action when shift is held.
      if ((get_mods() & MOD_MASK_SHIFT) != 0 &&
          !record->tap.count) {
         if (record->event.pressed) {
            tap_code(KC_QUOT);  // Type Shift + quote.
         }
         return false;  // Skip default handling.
      }
      break;  // Otherwise continue with default handling.
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;

    case LWR:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case RSE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        update_tri_layer(_NAV, _RAISE, _NAV);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        update_tri_layer(_NAV, _RAISE, _NAV);
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

    case ADJ:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;

    case KC_ESC:
     if ((get_mods() & MOD_BIT(KC_LGUI)) == MOD_BIT(KC_LGUI)) {
        if (record->event.pressed) {
          register_code(KC_GRV);
        } else {
          unregister_code(KC_GRV);
        }
        return false;
      }
      return true;
      break;

    case KC_TAB:
      {
      static bool tab_key_registered;
      if (record->event.pressed) {
        if ((get_mods() & (MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTRL))) == (MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTRL))) {
          del_mods(MOD_MASK_GUI);
          add_mods(MOD_MASK_SHIFT);
          register_code(KC_TAB);
          tab_key_registered = true;
          set_mods(mod_state);
          return false;
        }
      } else {
        if (tab_key_registered) {
          unregister_code(KC_TAB);
          tab_key_registered = false;
          return false;
        }
        return true;
      }
      }
      return true;
      break;
}

  return true;
}

void led_set_user(uint8_t usb_led) {

}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
      if (clockwise) {
          tap_code(KC_VOLU);
      } else {
          tap_code(KC_VOLD);
      }
    }
    if (index == 0) {
      if (IS_LAYER_ON(_LOWER)) {
        if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
      } else {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
      }
    }
    return true;
}

#endif

#ifdef RGBLIGHT_ENABLE

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_RED}
);
const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_raise_layer,
    my_lower_layer,
    my_adjust_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    rgblight_set_layer_state(1, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    return state;
}

#endif
