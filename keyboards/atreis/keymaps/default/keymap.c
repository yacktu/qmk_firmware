/* Copyright 2018 dek <dek@yolops.net>
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
#include "atreis.h"
#include "eeconfig.h"

#define _QWERTY 0
#define _FN 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  FN
};

#define KC_FN FN
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_BL_T BL_TOGG
#define KC_R_TG RGB_TOG
#define KC_R_MO RGB_MOD
#define KC_R_HI RGB_HUI
#define KC_R_HD RGB_HUD
#define KC_R_SI RGB_SAI
#define KC_R_SD RGB_SAD
#define KC_R_VI RGB_VAI
#define KC_R_VD RGB_VAD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GRV,  1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ESC , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LGUI, Z  , X  , C  , V  , B  ,LALT,     RALT, N  , M  ,COMM,DOT ,SLSH,BSLS,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                         FN,LSFT,ENT ,         SPC ,LCTRL,RALT
  //                  `----+----+----'        `----+----+----'
  ),
  [_FN] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,EQL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RST , NO , NO , NO , NO ,LBRC,               RBRC,END ,HOME,LBRC,RBRC,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     R_TG,R_MO,R_HI,R_SI,R_VI, NO ,               LEFT,DOWN, UP ,RGHT, NO , NO ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     BL_T,BL_S,R_HD,R_SD,R_VD,LCBR, NO ,      NO ,RCBR,PGDN,PGUP,LCBR,RCBR,PIPE,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        NO , NO , NO ,          NO , NO , NO 
  //                  `----+----+----'        `----+----+----'
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
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
      break;
  }

  return true;
}

void led_set_user(uint8_t usb_led) {

}
