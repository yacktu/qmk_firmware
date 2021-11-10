#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCtrl |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LOWER| LAlt | LGUI | /Enter  /       \Space \  |RAISE |Enter | Ctrl |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,  \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,    KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
                       MO(_LOWER), KC_LALT, KC_LGUI, LCTL_T(KC_ENT) ,    KC_SPC ,  MO(_RAISE), KC_ENT, KC_RCTRL \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | PgUp |      |      |AltTog|                    |      |   \  |   |  |   [  |   ]  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Home | PgDn | End  |      |      |-------.    ,-------|      |      |      |   (  |   )  |      |
 * |------+------+------+------+------+------| Vol+  |    | Vol-  |------+------+------+------+------+------|
 * |      | Caps |      |      |      |      |-------|    |-------|   _  |   -  |   =  |   +  |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LOWER| LAlt | LGUI | /Space  /       \Space \  |RAISE |Enter | Ctrl |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, \
  _______, _______, KC_PGUP, _______, TG(_RAISE), AG_TOGG,                _______, KC_BSLS, KC_PIPE, KC_LBRC, KC_RBRC, KC_DEL , \
  _______, KC_HOME, KC_PGDN,  KC_END, _______, _______,                   _______, _______, _______, KC_LPRN, KC_RPRN, _______, \
  _______, KC_CAPS, _______, _______, C(KC_LEFT), C(KC_RGHT), KC_VOLD, KC_VOLU, KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_BSLS, _______, \
                             _______, _______, _______, KC_SPC , _______, _______, _______, _______\
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
  _______, _______, _______, _______, _______, _______,                    C(KC_LEFT), C(KC_RGHT) , _______, KC_LCBR, KC_RCBR, KC_TILD, \
  _______, _______, _______, _______, _______, _______,                    KC_PGUP, XXXXXXX, KC_UP  , KC_LBRC, KC_RBRC, KC_DEL , \
  _______, _______, _______, _______, _______, _______,                    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_PIPE, KC_ENT , \
  _______, _______, _______, _______, _______, _______, KC_HOME, KC_END  , KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_BSLS, G(C(KC_Q)), \
                             _______, _______, _______, KC_SPC , _______ , _______, KC_RGUI, KC_RALT \
),
  /*_______, C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5),                     KC_PGUP, XXXXXXX, KC_UP  , KC_LBRC, KC_RBRC, KC_DEL , \
  //_______, C(KC_6), C(KC_7), C(KC_8), C(KC_9), C(KC_0),                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_PIPE, KC_ENT , \
  /*/
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LOWER| LAlt | LGUI | /Enter  /       \Space \  |RAISE |Enter | Ctrl |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,      XXXXXXX,                   XXXXXXX,   LCA(KC_LBRC), LCA(KC_BSLS), LCA(KC_RBRC), XXXXXXX, XXXXXXX, \
  XXXXXXX, LCA(KC_Q), LCA(KC_W), LCA(KC_E), XXXXXXX,      XXXXXXX,                   XXXXXXX,   LCA(KC_U),    LCA(KC_UP),   LCA(KC_I),    XXXXXXX, XXXXXXX, \
  XXXXXXX, LCA(KC_A), LCA(KC_S), LCA(KC_D), LCA(S(KC_D)), XXXXXXX,                   LCA(KC_M), LCA(KC_LEFT), LCA(KC_L),    LCA(KC_RGHT), XXXXXXX, XXXXXXX, \
  KC_LSFT, LCA(KC_Z), LCA(KC_X), LCA(KC_C), XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   LCA(KC_J),    LCA(KC_DOWN), LCA(KC_K),    XXXXXXX, KC_RSFT, \
                                 _______,   _______,      _______, _______, _______, _______,   _______,      _______ \
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    #ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
    #endif
    // set_timelog();
  }
  mod_state = get_mods();
  switch (keycode) {
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
