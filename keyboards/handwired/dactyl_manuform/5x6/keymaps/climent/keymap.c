#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define ADJUST MO(_ADJUST)

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
};

// The layout of the soldered switches is different from the standard 5x6, so we redefine the pin matrix here.
#undef LAYOUT_5x6
#define LAYOUT_5x6( \
    L00, L01, L02, L03, L04, L05,                          R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,                          R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35,                          R30, R31, R32, R33, R34, R35, \
              L42, L43,                                              R42, R43, \
                        L52, L53,                          R52, R53, \
                           L44, L45,                    R40, R41, \
                            L54, L55,                  R50, R51 \
) { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L30, L31, L32, L33, L34, L35 }, \
    { XXX, XXX, L42, L43, L44, L45 }, \
    { XXX, XXX, L52, L53, L54, L55 }, \
\
    { R00, R01, R02, R03, R04, R05 }, \
    { R10, R11, R12, R13, R14, R15 }, \
    { R20, R21, R22, R23, R24, R25 }, \
    { R30, R31, R32, R33, R34, R35 }, \
    { R40, R41, R42, R43, XXX, XXX }, \
    { R50, R51, R52, R53, XXX, XXX } \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_5x6(
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_GRV,
        KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSPC,
        KC_LCTL, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                         LOWER , KC_LALT,                                                       KC_ENT, KC_RCTL,
                                         KC_LGUI,MT(MOD_LALT, KC_ENT),           KC_SPC, RAISE,
                                         KC_LCTL,KC_ENT,                         LOWER,  KC_RCTL,
                                          XXXXXXX,KC_VOLD,                      KC_VOLU,XXXXXXX
    ),

[_LOWER] = LAYOUT_5x6(
  KC_GRV ,    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, \
  _______,    KC_VOLU, _______, _______, TG(_RAISE), AG_TOGG,                      _______, KC_BSLS, KC_PIPE, KC_LBRC, KC_RBRC, KC_DEL , \
  _______,    KC_VOLD, _______, _______, _______, _______,                         _______, _______, _______, KC_LPRN, KC_RPRN, _______, \
  G(C(KC_Q)), KC_CAPS, _______, _______, C(KC_LEFT), C(KC_RGHT),                   KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_BSLS, _______, \
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______

    ),

[_RAISE] = LAYOUT_5x6(
    _______, _______, _______, _______, _______, _______,                    C(KC_LEFT), C(KC_RGHT) , _______, KC_LCBR, KC_RCBR, KC_TILD, \
    _______, _______, _______, _______, KC_HOME, KC_END ,                    KC_PGUP, XXXXXXX, KC_UP  , KC_LBRC, KC_RBRC, KC_DEL , \
    _______, _______, C(S(KC_TAB)), _______, C(KC_TAB), _______,             KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_PIPE, KC_ENT , \
    _______, _______, _______, _______, _______, _______,                    KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_BSLS, _______, \
                                                  _______,_______,            KC_RGUI ,KC_RALT,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______
    ),

[_ADJUST] = LAYOUT_5x6( \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_END , KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______
)
};


uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;

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

    }

    return true;
}
