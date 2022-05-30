/* Copyright 2021 eithanshavit
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

enum layer_names {
    _MAIN,
    _RAISE,
    _CORNERS,
    _VERTICAL,
    _SMALLCORNERS,
    _SMALLMIDDLES
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
  //┌─────────┬─────────┬─────────┐
     KC_VOLD,     KC_MUTE,  KC_VOLU,
  //├─────────┼─────────┼─────────┤
     KC_LEFT,     KC_DOWN,  KC_RIGHT,
  //├─────────┼─────────┼─────────┤
     LT(_RAISE, 0),    G(KC_GRV), TO(_MAIN)
  //└─────────┴─────────┴─────────┘
  ),
  [_RAISE] = LAYOUT(
  //┌─────────┬─────────┬─────────┐
     TO(_CORNERS), TO(_VERTICAL), TO(_SMALLCORNERS),
  //├─────────┼─────────┼─────────┤
     G(KC_LEFT),  TO(_SMALLMIDDLES), G(KC_RIGHT),
  //├─────────┼─────────┼─────────┤
     _______,  _______, TO(_MAIN)
  //└─────────┴─────────┴─────────┘
  ),
  [_CORNERS] = LAYOUT(
  //┌─────────┬─────────┬─────────┐
     C(A(KC_U)), C(A(KC_M)), C(A(KC_I)),
  //├─────────┼─────────┼─────────┤
     C(A(KC_J)), C(A(KC_L)), C(A(KC_K)),
  //├─────────┼─────────┼─────────┤
     KC_RSFT,    G(KC_GRV),  TO(_MAIN)
  //└─────────┴─────────┴─────────┘
  ),
  [_VERTICAL] = LAYOUT(
  //┌─────────┬─────────┬─────────┐
     C(A(KC_LBRC)),  C(A(KC_BSLS)), C(A(KC_RBRC)),
  //├─────────┼─────────┼─────────┤
     C(A(KC_LEFT)),  C(A(KC_L)),    C(A(KC_RIGHT)),
  //├─────────┼─────────┼─────────┤
     KC_RSFT,   G(KC_GRV),  TO(_MAIN)
  //└─────────┴─────────┴─────────┘
  ),
  [_SMALLCORNERS] = LAYOUT(
  //┌─────────┬─────────┬─────────┐
     C(A(KC_Q)),  C(A(KC_W)), C(A(KC_E)),
  //├─────────┼─────────┼─────────┤
     C(A(KC_Z)),  C(A(KC_X)), C(A(KC_C)),
  //├─────────┼─────────┼─────────┤
     KC_RSFT,   G(KC_GRV),  TO(_MAIN)
  //└─────────┴─────────┴─────────┘
  ),

  [_SMALLMIDDLES] = LAYOUT(
  //┌─────────┬─────────┬─────────┐
     C(A(KC_A)),  C(A(KC_S)), C(A(KC_D)),
  //├─────────┼─────────┼─────────┤
     _______,_______,_______,
  //├─────────┼─────────┼────────i─┤
     KC_RSFT,   G(KC_GRV),  TO(_MAIN)
  //└─────────┴─────────┴─────────┘
  )

};

#ifdef COMBO_ENABLE

enum combo_events {
    CAPS_LOCK,
    C_A_LOCK_L,
    C_A_LOCK_R,
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
