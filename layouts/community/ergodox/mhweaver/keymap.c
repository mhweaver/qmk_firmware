#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_steno.h"

//#define NO_XSHIFT

#define _COLEMAK 0 // default layer
#define _QWERTY 1 // default layer
#define _SYMB 2 // symbols
#define _PLOVER 3 // plover layer

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Colemak layer
 *
 * ,----------------------------------------------------.           ,---------------------------------------------------.
 * |   =      |   1  |   2  |   3  |   4  |   5  |QWERTY|           |PLOVER|   6  |   7  |   8  |   9   |   0  |   -    |
 * |----------+------+------+------+------+-------------|           |------+------+------+------+-------+------+--------|
 * |   `      |   Q  |   W  |   F  |   P  |   B  |   [  |           |  ]   |   J  |   L  |   U  |   Y   |   ;  |   \    |
 * |----------+------+------+------+------+------|      |           |      |------+------+------+-------+------+--------|
 * |Backspace |   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   I   |   O  |   '    |
 * |----------+------+------+------+------+------|   (  |           |  )   |------+------+------+-------+------+--------|
 * | LShift   |   Z  |   X  |   C  |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .   |   /  | RShift |
 * `----------+------+------+------+------+-------------'           `-------------+------+------+-------+------+--------'
 *   |Ctrl/Esc| LGUI | LALT | Left |   L2 |                                       | Left | Down |   Up  | Right|  Ctrl  |
 *   `------------------------------------'                                       `-------------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Del  | Home |       | PgUp | Insert |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |Backsp| End  |       | PgDn |        |      |
 *                                 | Space|ace   |------|       |------|  Tab   |Enter |
 *                                 |      |      |LeftM |       |RightM|        |      |
 *                                 `--------------------'       `----------------------'
 */
[_COLEMAK] = LAYOUT_ergodox(  // layer 0 : colemak
        // left hand
        KC_EQL,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5, TT(_QWERTY),
        KC_GRV,          KC_Q,    KC_W,    KC_F,    KC_P,    KC_B, KC_LBRC,
        KC_BSPC,         KC_A,    KC_R,    KC_S,    KC_T,    KC_G,
        KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, KC_LPRN,
          CTL_T(KC_ESC), OSM(MOD_LGUI), OSM(MOD_LALT), KC_BSPC, TT(_SYMB),
							                                           KC_DELT, KC_HOME,
    						                                                    KC_END,
															   KC_SPC, KC_BSPC, LGUI(KC_W),
        // right hand
             TG(_PLOVER), KC_6, KC_7, KC_8,    KC_9,   KC_0,     KC_MINS,
             KC_RBRC,     KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN,  KC_BSLS,
                          KC_M, KC_N, KC_E,    KC_I,   KC_O,     KC_QUOT,
             KC_RPRN,   KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,
                                   KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,  KC_RCTL,
             KC_PGUP,          KC_INS,
             KC_PGDN,
             LGUI(KC_E),KC_TAB,KC_ENT
    ),
/* Keymap 1: Basic layer
 *
 * ,----------------------------------------------------.           ,---------------------------------------------------.
 * |          |      |      |      |      |      |      |           |      |      |      |      |       |      |        |
 * |----------+------+------+------+------+-------------|           |------+------+------+------+-------+------+--------|
 * |          |      |      |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O   |   P  |        |
 * |----------+------+------+------+------+------|      |           |      |------+------+------+-------+------+--------|
 * |          |      |   S  |   D  |   F  |      |------|           |------|   H  |   J  |   K  |   L   |   ;  |        |
 * |----------+------+------+------+------+------|      |           |      |------+------+------+-------+------+--------|
 * |          |      |      |      |   V  |   B  |      |           |      |   N  |   M  |      |       |      |        |
 * `----------+------+------+------+------+-------------'           `-------------+------+------+-------+------+--------'
 *   |        |      |      |      |      |                                       |      |      |       |      |      |
 *   `------------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_QWERTY] = LAYOUT_ergodox(  // layer 1 : default
        // left hand
        KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_TRNS, KC_TRNS, KC_E,    KC_R,    KC_T,    KC_TRNS,
        KC_TRNS,   KC_TRNS, KC_S,    KC_D,    KC_F,    KC_TRNS,
        KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_V,    KC_B,    KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
														           KC_TRNS, KC_TRNS,
                               							                    KC_TRNS,
                               							  KC_TRNS, KC_TRNS, KC_TRNS,
				  // right hand
             KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
             KC_TRNS,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_TRNS,
                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_TRNS,
             KC_TRNS,     KC_N,    KC_M,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS,        KC_TRNS,
             KC_TRNS,
             KC_TRNS,KC_TRNS,KC_TRNS
    ),
/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         | Rclk | MsUp | Lclk |      | Home |      |           |      | PgDn |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |MsLeft|MsDown|MsRght|      | End  |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      | PgUp |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |   0  |    0 |   .  |   =  |NumLck|
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |FLASH |       |FLASH |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[_SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_BTN2,KC_MS_U,KC_BTN1,KC_TRNS,KC_HOME,KC_TRNS,
       KC_TRNS,KC_MS_L,KC_MS_D,KC_MS_R,KC_TRNS,KC_END,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                        KC_TRNS,RESET,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_PGDN,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_TRNS, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_PGUP, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_0,   KC_0,    KC_DOT,  KC_EQL,  KC_NLCK,
       RESET,   KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Steno for Plover
 *
 * ,--------------------------------------------------.      ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |      |      |      |      |      |      |      |   NC   |
 * |--------+------+------+------+------+-------------|      |------+------+------+------+------+------+--------|
 * |   FN   |   1  |   2  |   3  |   4  |   5  |      |      |      |  6   |  7   |   8  |   9  |  NA  |   NB   |
 * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * |        |   S  |   T  |   P  |   H  |   *  |------|      |------|  *   |  F   |   P  |   L  |  T   |   D    |
 * |--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
 * |        |   S  |   K  |   W  |   R  |   *  |      |      |      |  *   |  R   |   B  |   G  |  S   |   Z    |
 * `--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                  |      |      |  PWR | RES1 | RES2 |
 *   `----------------------------------'                                  `----------------------------------'
 *                                        ,-------------.  ,-------------.
 *                                        |      |      |  |      |      |
 *                                 ,------|------|------|  |------+------+------.
 *                                 |      |      |      |  |      |      |      |
 *                                 |   A  |   O  |------|  |------|  E   |  U   |
 *                                 |      |      |      |  |      |      |      |
 *                                 `--------------------'  `--------------------'
 */

[_PLOVER] = LAYOUT_ergodox(  // layout: layer 4: Steno for Plover
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        STN_FN,  STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  KC_TRNS,
        KC_TRNS, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,
        KC_TRNS, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                      KC_TRNS, KC_TRNS,
                                               KC_TRNS,
                               STN_A, STN_O,   KC_TRNS,
        // right hand
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, STN_NC,
             KC_TRNS, STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,
                      STN_ST4, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
               KC_NO, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                               KC_NO,   KC_NO,   STN_PWR, STN_RE1, STN_RE2,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, STN_E,   STN_U
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(_SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool lshifted = false;
bool rshifted = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    //case EPRM:
    //  if (record->event.pressed) {
    //    eeconfig_init();
    //  }
    //  return false;
    //  break;
    //case VRSN:
    //  if (record->event.pressed) {
    //    SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    //  }
    //  return false;
    //  break;
    //case RGB_SLD:
    //  if (record->event.pressed) {
    //    #ifdef RGBLIGHT_ENABLE
    //      rgblight_mode(1);
    //    #endif
    //  }
    //  return false;
    //  break;
#ifdef NO_XSHIFT
	case KC_LSPO:
		lshifted = record->event.pressed;
		break;
	case KC_RSPC:
		rshifted = record->event.pressed;
		break;
  }
  if (lshifted ^ rshifted) {
	if (record->event.key.col & 0x3) { // col & 3 = col in [1,2,3]
		uint8_t row = record->event.key.row;
		if (lshifted && row >= 3 && row <= 7)
			return false; // disable left
		else if (rshifted && row >= 12 && row <= 16)
			return false; // disable right
	}
#endif
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
	steno_set_mode(STENO_MODE_GEMINI);
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
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
		case 3:
			ergodox_right_led_3_on();
        default:
            // none
            break;
    }

};
