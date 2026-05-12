/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

#define SCROLL_LAYER 3 // must greater than AUTO_MOUSE_DEFAULT_LAYER

enum layers {
  QWERTY,
  COLEMAK,
  MOUSE,
  NAV,
  SYM,
  FN,
  CONF
};


enum keycodes {
    SW_WIN = SAFE_RANGE,  // Switch to next window      (alt-tab)
    SW_TAB,  // Switch to next   TAB        (ctl-tab)
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_ESC   , KC_Q     , KC_W     ,  KC_E    , KC_R     , KC_T     ,                                                            KC_Y     ,  KC_U    ,  KC_I     ,  KC_O    ,   KC_P     , G(KC_L)   ,
    KC_TAB   , KC_A     , KC_S     ,  KC_D    , KC_F     , KC_G     ,                                                            KC_H     ,  KC_J    ,  KC_K     ,  KC_L    ,   KC_SCLN  , S(KC_7)  ,
    KC_LSFT  , KC_Z     , KC_X     ,  KC_C    , KC_V     , KC_B     ,                                                            KC_N     ,  KC_M    ,  KC_COMM  ,  KC_DOT  ,   KC_SLSH  , G(KC_SPC)  ,
                                  KC_LALT,KC_LGUI,LT(FN,KC_ESC)  ,LT(NAV,KC_SPC),    KC_LSFT,                  LT(6,KC_BSPC),LT(4,KC_ENT), RCTL_T(KC_LNG2),     KC_RALT  , KC_PSCR
  ),

  // colemak-dh
  [1] = LAYOUT_universal(
    KC_ESC   , KC_Q         ,    KC_W     ,     KC_F    ,    KC_P     , KC_B     ,                                        KC_J     ,     KC_L     ,     KC_U     ,     KC_Y     ,     KC_QUOT     , G(KC_L)   ,
    KC_TAB   , KC_A         ,    KC_R     ,     KC_S    ,    KC_T     , KC_G     ,                                        KC_M     ,     KC_N     ,     KC_E     ,     KC_I     ,     KC_O        , S(KC_7)  ,
    KC_LSFT  , KC_Z         ,    KC_X     ,     KC_C    ,    KC_D     , KC_V     ,                                        KC_K     ,     KC_H     ,     KC_COMM  ,     KC_DOT   ,     KC_SCLN     , G(KC_SPC)  ,
                                  KC_LALT,KC_LGUI,LT(FN,KC_ESC)  ,LT(NAV,KC_SPC),    KC_LSFT,                  LT(6,KC_BSPC),LT(4,KC_ENT), RCTL_T(KC_LNG2),     KC_RALT  , KC_PSCR
  ),
  
  //mouse
  [2] = LAYOUT_universal(
    _______  , KC_TAB  , SW_WIN  , SW_TAB  , _______  , _______  ,                                        _______  , C(KC_V)  , C(KC_C)  , C(KC_X)  , C(KC_Z)  , _______  ,
    _______  , KC_LGUI  , KC_LALT  , KC_LCTL  , KC_LSFT  , _______  ,                                        _______  , KC_BTN1  , KC_BTN3  , KC_BTN2  , _______  , _______  ,
    _______  , C(KC_Z)  , C(KC_X)  , C(KC_C)  , C(KC_V)  , _______  ,                                        _______  , KC_BTN4  , KC_BTN5  , _______  , _______  , _______  ,
                  _______  , _______ , _______  ,         _______  , _______  ,                    _______  , _______  , _______       , _______  , _______
  ),

  // Nav // TBD
  [3] = LAYOUT_universal(
    _______  , KC_TAB   , SW_WIN   , SW_TAB   , _______  , _______  ,                                         KC_PGUP  , KC_HOME  , KC_UP    , KC_END   , _______  , _______  ,
    _______  , OSM(MOD_LGUI)  , OSM(MOD_LALT)  , OSM(MOD_LCTL)  , OSM(MOD_LSFT)  , _______  ,                                         KC_PGDN  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , _______  ,
    _______  , C(KC_Z)  , C(KC_X)  , C(KC_C)  , C(KC_V)  , _______  ,                                         _______  , _______  , _______  , _______   , _______  , _______  ,
                  _______  , _______ , _______  ,         _______  , _______  ,                   KC_DEL   , _______  , _______       , _______  , _______
  ),

  // symbol and num // TBD
  [4] = LAYOUT_universal(
    _______  , KC_GRV   , KC_7     , KC_8    , KC_9     , S(KC_8)  ,                                         S(KC_7)  , S(KC_LBRC), S(KC_RBRC), S(KC_3)  , S(KC_4)  , _______  ,
    _______  ,S(KC_SCLN), KC_4     , KC_5    , KC_6     , KC_MINS  ,                                         KC_BSLS  , S(KC_9)   , S(KC_0)   , KC_EQL   , KC_QUOT  , S(KC_2)  ,
    _______  ,S(KC_MINS), KC_1     , KC_2    , KC_3     , S(KC_EQL),                                       S(KC_BSLS) , KC_LBRC   , KC_RBRC   ,S(KC_1)   ,S(KC_SLSH),S(KC_INT3),
                  _______  , _______ , KC_DOT  ,          KC_0     , _______  ,                   KC_DEL   , _______  , _______       , _______  , _______
  ),

  // fn and media
  [5] = LAYOUT_universal(
    _______  ,   KC_F1   , KC_F2    , KC_F3   , KC_F4    , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  ,   KC_F5   , KC_F6    , KC_F7   , KC_F8    , _______  ,                                        _______  , KC_MPRV  , KC_VOLD  , KC_VOLU  , KC_MNXT  , _______  ,
    _______  ,   KC_F9   , KC_F10   , KC_F11  , KC_F12   , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
                  _______  , _______  , _______  ,        _______  , _______  ,                   _______  , KC_MPLY  , _______       , _______  , _______
  ),

  // config layer
  [6] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        AML_TO   , AML_I50  , AML_D50  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , SCRL_DVD , SCRL_DVI , _______  , TG(1)    , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
                  QK_BOOT  , KBC_RST  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , KBC_RST  , QK_BOOT
  ),

  // experimental syn/num layer : under construction
  [7] = LAYOUT_universal(
    _______  ,   KC_1   ,   KC_2   ,   KC_3   ,   KC_4   ,   KC_5   ,                                          KC_6   ,   KC_7   ,   KC_8   ,   KC_9   ,   KC_0   , _______  ,
    _______  ,  S(KC_1) ,  S(KC_2) ,  S(KC_3) ,  S(KC_4) ,  S(KC_5) ,                                        KC_EQL  ,  S(KC_7) , S(KC_8)  ,  _______ , KC_QUOT  , _______  ,
    _______  ,  KC_GRV  , S(KC_LBRC)  , KC_LBRC  ,  S(KC_9)  , _______  ,                                    KC_MINS  ,  S(KC_0) , KC_RBRC  ,S(KC_RBRC), KC_BSLS  , _______  ,
                  _______  , _______  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , _______  , _______
  )
};
// clang-format on

enum combos {
  JK_BTN1,
  KL_BTN2,
  JL_BTN3,
  MCOM_BTN4,
  COMDOT_BTN5
};

const uint16_t PROGMEM jk_combo[] = { KC_J, KC_K, COMBO_END };
const uint16_t PROGMEM kl_combo[] = { KC_K, KC_L, COMBO_END };
const uint16_t PROGMEM jl_combo[] = { KC_J, KC_L, COMBO_END };
const uint16_t PROGMEM mcom_combo[] = { KC_M, KC_COMM, COMBO_END };
const uint16_t PROGMEM comdot_combo[] = { KC_COMM, KC_DOT, COMBO_END };

combo_t key_combos[] = {
  [JK_BTN1] = COMBO( jk_combo, KC_BTN1 ),
  [KL_BTN2] = COMBO( kl_combo, KC_BTN2 ),
  [JL_BTN3] = COMBO( jl_combo, KC_BTN3 ),
  [MCOM_BTN4] = COMBO( mcom_combo, KC_BTN4 ),
  [COMDOT_BTN5] = COMBO( comdot_combo, KC_BTN5 ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is SCROLL_LAYER
    keyball_set_scroll_mode(get_highest_layer(state) == SCROLL_LAYER);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

// todo: seperate to other file
void update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            register_code(tabish);
        } else {
            unregister_code(tabish);
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (*active) {
        unregister_code(cmdish);
        *active = false;
    }
}

bool sw_win_active = false;
bool sw_tab_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LALT, KC_TAB, SW_WIN,
        keycode, record
    );
    update_swapper(
        &sw_tab_active, KC_LCTL, KC_TAB, SW_TAB,
        keycode, record
    );

    return true;
}