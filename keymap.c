/* Copyright 2015-2017 Jack Humbert
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

/* Homerow mod aliases */
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define CTL_t LCTL_T(KC_T)

#define CTL_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)


enum planck_layers
{
  _BASE,
  _GAME,
  _TYPING,
  _NAV,
  _NUM,
  _FUNCTION,
};

enum planck_keycodes
{
  SMILEY = SAFE_RANGE,
  ECLIPSE,
  CHAT,
  GAME,
  DEFGAME,
  DEFBASE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{
/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Ent  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |  A/◆ | R/⎇  |  S/⇧ |  T/⎈ |   G  |   M  |  N/⎈ |  E/⇧ | I/⎇  |  O/◆ |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Num  |  No  |  Alt |  Cmd |  Nav | Space|  Alt |  No  |  No  |  No  |  No  |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,  KC_W,    KC_F,    KC_P,    KC_B,  KC_J,   KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_ENT,
    KC_BSPC, GUI_A, ALT_R,   SFT_S,   CTL_t,   KC_G,  KC_M,   CTL_N,   SFT_E,   ALT_I,  GUI_O,   KC_QUOT,
    XXXXXXX, KC_Z,  KC_X,    KC_C,    KC_D,    KC_V,  KC_K,   KC_H,    KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,
    XXXXXXX, MO(4), XXXXXXX, XXXXXXX, XXXXXXX, MO(3), KC_SPC, XXXXXXX, XXXXXXX, SMILEY, XXXXXXX, XXXXXXX
),

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   J  |   L  |   U  |   Y  |   ;  |  Ent |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   A  |   S  |   W  |   D  |   G  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   R  |   K  |   H  |   ,  |   .  |TYPING| Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Num | Curr.|  Alt | Space|   C  | Space|  Alt |  No  |  No  |  No  |  No  |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_planck_grid(
    KC_ESC,  KC_1,  KC_2,  KC_3,    KC_4,    KC_5,  KC_J,   KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_ENT,
    KC_LSFT, KC_A,  KC_S,  KC_W,    KC_D,    KC_G,  KC_H,   KC_N,    KC_E,    KC_I,   KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,  KC_X,  KC_C,    KC_D,    KC_V,  KC_K,   KC_H,    KC_COMM, KC_DOT, CHAT,    KC_RSFT,
    KC_LCTL, MO(4), KC_NO, KC_LALT, KC_LGUI, MO(3), KC_SPC, KC_RALT, KC_NO,   KC_NO,  KC_NO,   DEFBASE
),

/* Supplemental Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | GAME |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Num  |  No  |  Alt |  Cmd |  Nav | Space|  Alt |  No  |  No  |  No  |  No  |
 * `-----------------------------------------------------------------------------------'
 */
[_TYPING] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,  KC_W,  KC_F,    KC_P,    KC_B,  KC_J,   KC_L,    KC_U,    KC_Y,   KC_SCLN, GAME,
    KC_BSPC, KC_A,  KC_R,  KC_S,    KC_T,    KC_G,  KC_M,   KC_N,    KC_E,    KC_I,   KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,  KC_X,  KC_C,    KC_D,    KC_V,  KC_K,   KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, MO(4), KC_NO, KC_LALT, KC_LGUI, MO(3), KC_SPC, KC_RALT, KC_NO,   KC_NO,  KC_NO,   KC_NO
),



/* Nav/Misc
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   !  |   @  |   #  |   $  |   %  | Down | Right|   `  |   -  |   =  |  Ent |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |   {  |   }  |   [  |   ]  |   \  |   ~  |   (  |   )  |   ^  |   &  |  *   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift| Prev | Next | VOL- | Vol+ | Play |  Up  | Left |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Num | For. |  Alt |  Cmd | Curr.| Space|  Alt |  No  |  No  |  No  |  No  |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
    KC_TAB,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_DOWN, KC_RGHT, KC_GRV,  KC_MINS, KC_EQL,  KC_TRNS,
    KC_TRNS,  KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD, KC_LPRN, KC_RPRN, KC_CIRC, KC_AMPR, KC_ASTR,
    KC_TRNS,  KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_UP,   KC_LEFT, KC_TRNS, KC_TRNS, ECLIPSE, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   7  |   8  |   9  |   -  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |   A  |   R  |   S  |   T  |   G  |   M  |   4  |   5  |   6  |   +  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   1  |   2  |   3  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Curr.| Func |  Alt |  Cmd |  Nav | Space|  Alt |  No  |  No  |  No  |  No  |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_planck_grid(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_7, KC_8,    KC_9,    KC_PMNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4, KC_5,    KC_6,    KC_PPLS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_2,    KC_3,    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, MO(5),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |  RGB |   W  |   F  |   P  | BASE |   J  |  F7  |  F8  |  F9  |  F10 |  Ent |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |   A  |   R  |   S  |   T  | GAME |   M  |  F4  |  F5  |  F6  |  F11 |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |  F1  |  F2  |  F3  |  F12 | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Curr.| Curr.|  Alt |  Cmd |  Nav | Space|  Alt |  No  |  No  |  No  |  No  |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_planck_grid(
    KC_TRNS, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, DF(_BASE), KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DF(_GAME), KC_TRNS, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F12,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{
  switch (keycode) 
  {
    case SMILEY:
      if (record->event.pressed) 
      {
        SEND_STRING(":)");
      }
      else 
      {
      }
      return false;
      break;

    case ECLIPSE:
      if (record->event.pressed)
      {
        SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LSFT)SS_TAP(X_F11)SS_UP(X_LGUI)SS_UP(X_LSFT));
      }
      break;
 
    case CHAT:
      if (record->event.pressed)
      {
        SEND_STRING("/");
        layer_off(_GAME);
        layer_on(_TYPING);
      }
      //else
      //{
      //  layer_off(_TYPING);
      //  layer_on(_GAME);
      //}
      return false;
      break;
   
    case GAME:
      if (record->event.pressed)
      {
        SEND_STRING(SS_TAP(X_ENTER));
        layer_off(_TYPING);
        layer_on(_GAME);
      }
      //else
      //{
      //  layer_on(_TYPING);
      //  layer_off(_GAME);
      //}
      return false;
      break;

    case DEFBASE:
      if (record->event.pressed)
      {
        //default_layer_set(0x00000001);
        layer_off(_TYPING);
        layer_off(_GAME);
        layer_on(_BASE);
      }
      return false;
      break;

    case RCTL_T(KC_N):
      if (record->tap.count > 0)
          if (get_mods() & MOD_BIT(KC_RSHIFT))
          {
            {
              unregister_mods(MOD_BIT(KC_RSHIFT));
              tap_code(KC_E);
              tap_code(KC_N);
              add_mods(MOD_BIT(KC_RSHIFT));
              return false;
            }
          }
      return true;

    case LCTL_T(KC_T):
      if (record->tap.count > 0)
      {
        if (get_mods() & MOD_BIT(KC_LSHIFT))
        {
            unregister_mods(MOD_BIT(KC_LSHIFT));
            tap_code(KC_S);
            tap_code(KC_T);
            add_mods(MOD_BIT(KC_LSHIFT));
            return false;
        }
      }
      return true;

    default:
      return true;
  }
  return true;
};
