#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

//#define NO_XSHIFT

#define COLEMAK 0 // default layer
#define QWERTY 1 // default layer
#define SYMB 2 // symbols
#define MDIA 3 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

enum tapdance_ids {
	TD_NOOP_ENTER = 0,
	TD_ENTER_NOOP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Colemak layer
 *
 * ,----------------------------------------------------.           ,---------------------------------------------------.
 * |   =      |   1  |   2  |   3  |   4  |   5  |L1 Tog|           |L3 Tog|   6  |   7  |   8  |   9   |   0  |   -    |
 * |----------+------+------+------+------+-------------|           |------+------+------+------+-------+------+--------|
 * |   `/L3   |   Q  |   W  |   F  |   P  |   B  |   [  |           |  ]   |   J  |   L  |   U  |   Y   |   ;  |   \    |
 * |----------+------+------+------+------+------|      |           |      |------+------+------+-------+------+--------|
 * |Backspace |   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   I   |   O  | ' / L3 |
 * |----------+------+------+------+------+------|  L2  |           |  L2  |------+------+------+-------+------+--------|
 * | LShift   |   Z  |   X  |   C  |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .   |   /  | RShift |
 * `----------+------+------+------+------+-------------'           `-------------+------+------+-------+------+--------'
 *   |Ctrl/Esc| LGUI | LALT | Left | Right|                                       | Left | Down |   Up  | Right|Ctrl/Esc|
 *   `------------------------------------'                                       `-------------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Del  | Home |       | PgUp | Insert |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |Backsp| End  |       | PgDn |        |      |
 *                                 | Space|ace   |------|       |------|  Tab   |Enter |
 *                                 |      |      |LeftM |       |RightM|        |      |
 *                                 `--------------------'       `----------------------'
 */
[COLEMAK] = KEYMAP(  // layer 0 : colemak
        // left hand
        KC_EQL,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5, TT(QWERTY),
        LT(MDIA, KC_GRV), KC_Q,    KC_W,    KC_F,    KC_P,    KC_B, KC_LBRC,
        KC_BSPC,          KC_A,    KC_R,    KC_S,    KC_T,    KC_G,
        KC_LSPO,          KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, TT(SYMB),
          CTL_T(KC_ESC),  KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT,
							                                           KC_DELT, KC_HOME,
    						                                                    KC_END,
															   KC_SPC, KC_BSPC, LGUI(KC_W),
        // right hand
             TG(MDIA), KC_6, KC_7, KC_8,    KC_9,   KC_0,     KC_MINS,
             KC_RBRC,  KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN,  KC_BSLS,
                       KC_M, KC_N, KC_E,    KC_I,   KC_O,     LT(MDIA, KC_QUOT),
             TT(SYMB), KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH,  KC_RSPC,
                                   KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,  CTL_T(KC_ESC),
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
[QWERTY] = KEYMAP(  // layer 1 : default
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
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
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
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,RESET,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_0,   KC_0,    KC_DOT,  KC_EQL,  KC_NLCK,
       RESET,   KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MsUp |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsLeft|MsDown|MsRght|      |      |------|           |------|MsLeft|MsDown| MsUp |MsRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |  Play  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Rclk | Lclk |                                       |VolUp |VolDn | Mute |      |      |
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
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN1,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_MPLY,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ENTER_NOOP] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_NO),
  [TD_NOOP_ENTER] = ACTION_TAP_DANCE_DOUBLE(KC_NO, KC_ENT),
// Other declarations would go here, separated by commas, if you have them
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
        default:
            // none
            break;
    }

};
