// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: For macOS
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |  1/! |  2/@ |  3/# |  4/$ |  5/% |  6/^ |           |  7/& | 8/ * |  9/( |  0/) |  -/_ |  =/+ |  `/~   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [/{ |           |  [/{ |   Y  |   U  |   I  |   O  |   P  |   \/|  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;/: |  '/"   |
 * |--------+------+------+------+------+------|  ]/} |           |  ]/} |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  ,/< |  ./> |  //? | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *  | LCtrl |      |      | LAlt | LGUI |                                       |   B  |  [/{ |  ]/} |      | ~L1  |
 *  `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Left |Right |       | Left | Right  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  Up  |       |  Up  |        |      |
 *                                 |LShift|Back  |------|       |------|  Enter |RShift|
 *                                 |/Space|space | Down |       | Down |        |/Space|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,   KC_1,   KC_2,   KC_3,     KC_4,     KC_5,  KC_6,
        KC_TAB,   KC_Q,   KC_W,   KC_E,     KC_R,     KC_T,  KC_LBRC,
        KC_LCTL,  KC_A,   KC_S,   KC_D,     KC_F,     KC_G,
        KC_LSFT,  KC_Z,   KC_X,   KC_C,     KC_V,     KC_B,  KC_RBRC,
        KC_LCTL,  KC_NO,  KC_NO,  KC_LALT,  KC_LGUI,
                                                        KC_LEFT,  KC_RGHT,
                                                                  KC_UP  ,
                                       LSFT_T(KC_SPC),  KC_BSPC,  KC_DOWN,
        // right hand
             KC_7,     KC_8,   KC_9,   KC_0,     KC_MINS,  KC_EQL,   KC_GRV,
             KC_LBRC,  KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,     KC_BSLS,
                       KC_H,   KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
             KC_RBRC,  KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                               KC_B,   KC_LBRC,  KC_RBRC,  KC_NO,   TT(SYMB),
             KC_LEFT,  KC_RGHT,
             KC_UP,
             KC_DOWN,  KC_ENT,  RSFT_T(KC_SPC)
    ),
/* Keymap 1: For Windows
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |  1/! |  2/@ |  3/# |  4/$ |  5/% |  6/^ |           |  7/& | 8/ * |  9/( |  0/) |  -/_ |  =/+ |  `/~   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [/{ |           |  [/{ |   Y  |   U  |   I  |   O  |   P  |   \/|  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;/: |  '/"   |
 * |--------+------+------+------+------+------|  ]/} |           |  ]/} |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  ,/< |  ./> |  //? | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *  | LCtrl |      |      | LGUI | LAlt |                                       |   B  |  [/{ |  ]/} |      |      |
 *  `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Left |Right |       | Left | Right  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  Up  |       |  Up  |        |      |
 *                                 |LShift|Back  |------|       |------|  Enter |RShift|
 *                                 |/Space|space | Down |       | Down |        |/Space|
 *                                 `--------------------'       `----------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
        // left hand
        KC_ESC,   KC_1,   KC_2,   KC_3,     KC_4,     KC_5,  KC_6,
        KC_TAB,   KC_Q,   KC_W,   KC_E,     KC_R,     KC_T,  KC_LBRC,
        KC_LCTL,  KC_A,   KC_S,   KC_D,     KC_F,     KC_G,
        KC_LSFT,  KC_Z,   KC_X,   KC_C,     KC_V,     KC_B,  KC_RBRC,
        KC_LCTL,  KC_NO,  KC_NO,  KC_LGUI,  KC_LALT,
                                                        KC_LEFT,  KC_RGHT,
                                                                  KC_UP  ,
                                       LSFT_T(KC_SPC),  KC_BSPC,  KC_DOWN,
        // right hand
             KC_7,     KC_8,   KC_9,   KC_0,     KC_MINS,  KC_EQL,   KC_GRV,
             KC_LBRC,  KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,     KC_BSLS,
                       KC_H,   KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
             KC_RBRC,  KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                               KC_B,   KC_LBRC,  KC_RBRC,  KC_NO,    KC_TRNS,
             KC_LEFT,  KC_RGHT,
             KC_UP,
             KC_DOWN,  KC_ENT,  RSFT_T(KC_SPC)
    ),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }

};
