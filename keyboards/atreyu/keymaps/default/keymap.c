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
#include "atreyu.h"
#include "eeconfig.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LWR,
  RSE,
  ADJ
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_FN FN
#define KC_LWR LWR
#define KC_RSE RSE
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_BL_T BL_TOGG
#define KC_LCTL_T LCTL_T

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_kc(
  //,-----+-----+-----+-----+-----+-----.              ,-----+-----+-----+-----+-----+-----.
     ESC  , 1   , 2   , 3   , 4   , 5   ,                6   , 7   , 8   , 9   , 0   ,GRV ,
  //,-----+-----+-----+-----+-----+-----.              ,-----+-----+-----+-----+-----+-----.
     TAB  , Q   , W   , E   , R   , T   ,                Y   , U   , I   , O   , P   ,BSPC ,
  //,-----+-----+-----+-----+-----+-----.              ,-----+-----+-----+-----+-----+-----.
     LCTRL, A   , S   , D   , F   , G   ,                H   , J   , K   , L   ,SCLN ,QUOT ,
  //,-----+-----+-----+-----+-----+-----.              ,-----+-----+-----+-----+-----+-----.
     LSFT , Z   , X   , C   , V   , B   ,                N   , M   ,COMM ,DOT  ,SLSH ,RSFT ,
  //`-----+-----+-----+-----+-----+-----+-----/  \-----+-----+-----+-----+-----+-----+-----'
                  LWR ,LALT ,LGUI , LCTL_T(KC_ENT) ,LBRC ,   RBRC, SPC , RSE, ENT , RCTRL 
                
  //            `-----+-----+-----+-----+-----'  `-----+-----+-----+-----+-----'
  ),
  [_LOWER] = LAYOUT( \
  KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, \
  _______, KC_VOLU, _______, _______, TG(_RAISE), AG_TOGG,                _______, KC_BSLS, KC_PIPE, KC_LBRC, KC_RBRC, KC_DEL , \
  _______, KC_VOLD, _______, _______, _______, _______,                   _______, _______, _______, KC_LPRN, KC_RPRN, _______, \
  G(C(KC_Q)), KC_CAPS, _______, _______, C(KC_LEFT), C(KC_RGHT),             KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_BSLS, _______, \
                             _______, _______, _______, KC_SPC , KC_VOLD, KC_VOLU, _______, _______, _______, _______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |   {  |   }  |   ~  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LOCK | PgUp |      |      |      |                    | PgUp |  XX  | Up   |   [  |   ]  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Home | PgDn | End  |      |      |-------.    ,-------| PgDn | Left | Down |Right |   |  |Enter |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   _  |   -  |   =  |   +  |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LOWER| LAlt | LGUI | /Enter  /       \Space \  |RAISE | RAlt | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(\
  _______, _______, _______, _______, _______, _______,                    C(KC_LEFT), C(KC_RGHT), _______, KC_LCBR, KC_RCBR, KC_TILD, \
  _______, _______, _______, _______, KC_HOME, KC_END ,                    KC_PGUP, XXXXXXX, KC_UP  , KC_LBRC, KC_RBRC, KC_DEL , \
  _______, _______, _______, _______, _______, _______,                    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_PIPE, KC_ENT , \
  _______, _______, _______, _______, _______, _______,                    KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_BSLS, _______, \
                    _______, _______, _______, KC_SPC , KC_HOME, KC_END  , _______, _______, KC_RGUI, KC_RALT \
),

[_ADJUST] = LAYOUT(\
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_END , KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                    _______, _______, _______, KC_SPC , KC_HOME, KC_END  , _______, _______, KC_RGUI, KC_RALT \
)


};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();
  switch (keycode) {
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
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
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
