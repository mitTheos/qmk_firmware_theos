 /* Copyright 2021 Dane Evans
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

#define ANIM_INVERT false
#define ANIM_RENDER_WPM true
#define FAST_TYPE_WPM 45 //Switch to fast animation when over words per minute

#ifdef OLED_ENABLE
#include "demon.c"
#endif

#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

 // from qmk configurator
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_PSCR, KC_BSPC, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, KC_LCTL, KC_LALT, KC_DOWN, KC_UP, KC_SPC, LT(1,KC_ENT), KC_LEFT, KC_RGHT, KC_DEL, KC_LGUI),
    [1] = LAYOUT(QK_BOOT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_NO, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_NO, KC_COLN, KC_F12, KC_DEL, KC_LBRC, KC_LCBR, KC_LPRN, KC_MINS, KC_NO, KC_NO, KC_EQL, KC_RPRN, KC_RCBR, KC_RBRC, KC_DQUO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LT, KC_GT, KC_QUES, KC_PIPE, KC_NO, KC_NO, KC_PGDN, KC_PGUP, KC_COLN, KC_NO, KC_HOME, KC_END, KC_NO, KC_NO)
};

#ifdef ENCODER_ENABLE

void encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code(KC_UP);
  } else {
    tap_code(KC_DOWN);
  }
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;
  }
  return rotation;
}

bool oled_task_user(void) {
  if (!is_keyboard_master()) {
    oled_render_anim();
  }
  return false;
}
#endif
