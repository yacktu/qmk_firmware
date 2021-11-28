#include <stdio.h>
#include QMK_KEYBOARD_H

#include "drivers/sensors/pimoroni_trackball.h"
#include "pointing_device.h"

#include "report.h"
#include "transactions.h"
#include "timer.h"
#include <string.h>

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,  \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,    XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT), \
		 KC_LOWER, C(KC_LALT), KC_LALT ,GUI_T(KC_ENT), CTL_T(KC_ENT) ,   KC_SPC,KC_RAISE,KC_ENT, KC_RGUI, KC_RCTRL
),

[_RAISE] = LAYOUT(\
  _______, _______, _______, _______, _______, _______,                    C(KC_LEFT), C(KC_RGHT) , _______, KC_LCBR, KC_RCBR, KC_TILD, \
  _______, _______, _______, _______, KC_HOME, KC_END ,                    KC_PGUP, XXXXXXX, KC_UP  , KC_LBRC, KC_RBRC, KC_DEL , \
  _______, _______, C(S(KC_TAB)), _______, C(KC_TAB), _______,             KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_PIPE, KC_ENT , \
  _______, _______, _______, _______, _______, _______, KC_MPLY, _______ , KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_BSLS, _______, \
                    _______, _______, _______, _______, KC_SPC , _______ , _______, KC_RGUI, KC_RALT, _______ \
),

[_LOWER] = LAYOUT( \
  KC_GRV ,    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, \
  _______,    KC_VOLU, _______, _______, TG(_RAISE), AG_TOGG,                      _______, KC_BSLS, KC_PIPE, KC_LBRC, KC_RBRC, KC_DEL , \
  _______,    KC_VOLD, _______, _______, _______, _______,                         _______, _______, _______, KC_LPRN, KC_RPRN, _______, \
  G(C(KC_Q)), KC_CAPS, _______, _______, C(KC_LEFT), C(KC_RGHT), _______, _______, KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_BSLS, _______, \
                    _______, _______, _______, _______, KC_SPC ,       _______, _______, _______, _______, _______ \
),

[_ADJUST] = LAYOUT( \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_END , KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \
                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif


uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
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
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif

#ifdef POINTING_DEVICE_ENABLE

/*
bool pointing_device_task_user(pimoroni_data_t* trackball_data) {
    //pimoroni_trackball_set_scrolling(false);
    pimoroni_trackball_set_rgbw(0,0,0,80);
    pimoroni_trackball_set_precision(1);
    switch (get_highest_layer(layer_state)) {
	case _RAISE:
	    //pimoroni_trackball_set_scrolling(true);
	    pimoroni_trackball_set_rgbw(0,153,95,0);
	    pimoroni_trackball_set_precision(0.4);
	    break;
	case _LOWER:
            //pimoroni_trackball_set_scrolling(false);
	    pimoroni_trackball_set_rgbw(153,113,0,0);
	    pimoroni_trackball_set_precision(1);
	    break;
	case _ADJUST:
            //pimoroni_trackball_set_scrolling(false);
	    pimoroni_trackball_set_rgbw(153,0,110,0);
	    pimoroni_trackball_set_precision(0);
	    break;
        default:
            //pimoroni_trackball_set_scrolling(false);
	    pimoroni_trackball_set_rgbw(0,0,0,80);
	    pimoroni_trackball_set_precision(1);
	    break;
    }
    return true;
}
*/

static report_mouse_t shared_mouse_report;

void mouse_slave_handler(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer, uint8_t target2initiator_buffer_size, void* target2initiator_buffer) { memcpy(target2initiator_buffer, &shared_mouse_report, sizeof(shared_mouse_report)); }

void keyboard_post_init_user(void) {
    if (!is_keyboard_left()) {
        // trackball_set_rgbw(RGB_RED, 0x00);
        // trackball_set_precision(0.5);
    }
    // Reset the initial shared data value between master and slave
    memset(&shared_mouse_report, 0, sizeof(shared_mouse_report));
    // Register keyboard state sync split transaction
    transaction_register_rpc(MOUSE_SYNC, mouse_slave_handler);
}

#    ifndef POINTING_DEVICE_LEFT_SIDE
#        define POINTING_DEVICE_CHECK !is_keyboard_left()
#    else
#        define POINTING_DEVICE_CHECK is_keyboard_left()
#    endif

void pointing_device_send(void) {
    static report_mouse_t old_report  = {};
    report_mouse_t        temp_report = pointing_device_get_report();

    if (POINTING_DEVICE_CHECK) {
        if (!is_keyboard_master()) {
            memcpy(&shared_mouse_report, &temp_report, sizeof(report_mouse_t));  // update shared data
        }
    } else {
        if (is_keyboard_master()) {
            transaction_rpc_recv(MOUSE_SYNC, sizeof(report_mouse_t), &shared_mouse_report);
            temp_report = shared_mouse_report;
        }
    }

    // If you need to do other things, like debugging, this is the place to do it.
    if (is_keyboard_master() && has_mouse_report_changed(temp_report, old_report)) {
        host_mouse_send(&temp_report);
    }
    // send it and 0 it out except for buttons, so those stay until they are explicity over-ridden using update_pointing_device
    temp_report.x = 0;
    temp_report.y = 0;
    temp_report.v = 0;
    temp_report.h = 0;
    pointing_device_set_report(temp_report);
    old_report = temp_report;
}
void matrix_scan_user_throttled(void) {
    if (is_keyboard_master()) {
        pointing_device_send();
    }
}

void matrix_scan_user() {
    static fast_timer_t throttle = 0;
    if (timer_elapsed_fast(throttle) >= 8) {
        matrix_scan_user_throttled();
        throttle = timer_read_fast();
    }
}

void shutdown_keymap(void) {  }

#endif

