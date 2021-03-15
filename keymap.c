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
#define ALGR_X ALGR_T(KC_X)

#define CTL_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)
#define ALGR_FS ALGR_T(KC_DOT)


enum planck_layers
{
  _BASE,
  _MEDIA,
  _NAV,
  _MOUSE,
  _SYM,
  _NUM,
  _FN
};

enum planck_keycodes
{
  SMILEY = SAFE_RANGE,
  ECLIPSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{
/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |      |      |   J  |   L  |   U  |   Y  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  A/◆ | R/⎇  |  S/⇧ |  T/⎈ |   G  |      |      |   M  |  N/⎈ |  E/⇧ | I/⎇  |  O/◆ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |      |      |   K  |   H  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Del/⏯|BKSP/↑| Tab/⤒|      |      | Esc/$| Spc/0|Ent/Fn|      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_F,          KC_P,           KC_B,          XXXXXXX, XXXXXXX, KC_J,          KC_L,           KC_U,          KC_Y,     KC_QUOT,
    GUI_A,   ALT_R,   SFT_S,         CTL_t,          KC_G,          XXXXXXX, XXXXXXX, KC_M,          CTL_N,          SFT_E,         ALT_I,    GUI_O,
    KC_Z,    ALGR_X,  KC_C,          KC_D,           KC_V,          XXXXXXX, XXXXXXX, KC_K,          KC_H,           KC_COMM,       ALGR_FS,  KC_SLSH,
    XXXXXXX, XXXXXXX, LT(1, KC_DEL), LT(2, KC_BSPC), LT(3, KC_TAB), XXXXXXX, XXXXXXX, LT(4, KC_ESC), LT(5, KC_SPC),  LT(6, KC_ENT), XXXXXXX,  XXXXXXX
),

/* Media
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  ⏮  |  🔈  |  🔊  |  ⏭  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  ⏹  |  ⏯  |  🔇  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MEDIA] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MSTP, KC_MPLY, KC_MUTE, _______, _______
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | Redo | Paste| Copy |  Cut | Undo |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | CAPS |   ←  |   ↓  |   ↑  |   →  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Insert| Home | PDown|  PUp |  End |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, LCTL(LSFT(KC_Z)), KC_PSTE, KC_COPY, KC_CUT,  LCTL(KC_Z),
    _______, _______, _______, _______, _______, _______, _______, KC_CAPS,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    _______, _______, _______, _______, _______, _______, _______, KC_INS,           KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   ⇤  |   ⤓  |   ⤒  |   ⇥  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   ↞  |   ↡  |   ↟  |   ⇥  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  M1  |  M2  |  M3  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
    _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |   {  |   &  |   *  |   (  |   }  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   :  |   $  |   %  |   ^  |   +  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   |  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   (  |   )  |   _  |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = LAYOUT_planck_grid(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______, _______, _______, _______, _______, _______, _______,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, _______, _______, _______, _______, _______, _______, _______,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_LPRN, KC_RPRN, KC_UNDS, _______, _______, _______, _______, _______, _______, _______
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |   [  |   7  |   8  |   9  |   ]  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ;  |   4  |   5  |   6  |   =  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   \  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   .  |   0  |   -  |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_planck_grid(
    KC_LBRC, KC_7,    KC_8,   KC_9, KC_RBRC, _______, _______, _______, _______, _______, _______, _______,
    KC_SCLN, KC_4,    KC_5,   KC_6, KC_EQL,  _______, _______, _______, _______, _______, _______, _______,
    KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_DOT, KC_0, KC_MINS, _______, _______, _______, _______, _______, _______, _______
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |  F12 |  F7  |  F8  |  F9  |PrtScn|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F11 |  F4  |  F5  |  F6  | SLock|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F10 |  F1  |  F2  |  F3  |PBreak|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_planck_grid(
    KC_F12,  KC_F7,    KC_F8,    KC_F9,    KC_PSCR, _______, _______, _______, _______, _______, _______, _______,
    KC_F11,  KC_F4,    KC_F5,    KC_F6,    KC_SLCK, _______, _______, _______, _______, _______, _______, _______,
    KC_F10,  KC_F1,    KC_F2,    KC_F3,    KC_PAUS, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record)
{
   switch (keycode)
   {
      /*case LGUI_T(KC_A):
         return TAPPING_TERM + 10;*/
      case RGUI_T(KC_O):
         return TAPPING_TERM + 10;
      case LCTL_T(KC_T):
         return TAPPING_TERM + 10;
      case RCTL_T(KC_N):
         return TAPPING_TERM + 10;
      case LSFT_T(KC_S):
         return TAPPING_TERM - 20;
      case RSFT_T(KC_E):
         return TAPPING_TERM - 20;
      default:
         return TAPPING_TERM;
   }
};
