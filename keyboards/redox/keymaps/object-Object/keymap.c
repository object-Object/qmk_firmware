#include QMK_KEYBOARD_H

#define _COLEMAK 0
#define _QWERTY 1
#define _SYMBOL 2
#define _FUNCS 3
#define _NAV 4
#define _ADJUST 5

// tap dance declarations
enum {
   TD_CTL_WIN,
};

// tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
   ACTION_TAP_DANCE_DOUBLE(KC_RCTL, KC_RGUI),
};

// shortcuts to make keymap more readable
#define SYM MO(_SYMBOL)
#define FUNCS MO(_FUNCS)
#define TTFUNCS TT(_FUNCS)
#define NAV MO(_NAV)
#define QWERTY TG(_QWERTY)

#define ADJ_HOME LT(_ADJUST, KC_HOME)
#define ADJ_PGUP LT(_ADJUST, KC_PGUP)

#define CTL_WIN TD(TD_CTL_WIN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_PSCR ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,KC_INS  ,                          KC_DEL  ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NAV     ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,NAV     ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,ADJ_PGUP,KC_PGDN ,        KC_END  ,ADJ_HOME,KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_UP   ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_LGUI ,KC_LALT ,TTFUNCS ,     SYM     ,    KC_SPC  ,KC_BSPC ,        CTL_WIN ,KC_ENT  ,    SYM     ,     TTFUNCS ,KC_LEFT ,KC_DOWN ,KC_RGHT 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,_______ ,                          _______ ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,_______ ,                          _______ ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,_______ ,_______ ,        _______ ,_______ ,KC_N    ,KC_M    ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMBOL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_TILD ,KC_LBRC ,KC_RBRC ,KC_UNDS ,XXXXXXX ,                          XXXXXXX ,KC_QUES ,KC_PLUS ,KC_MINS ,KC_CIRC ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_PIPE ,KC_HASH ,KC_LPRN ,KC_RPRN ,KC_EQL  ,_______ ,                          _______ ,KC_EXLM ,KC_QUOT ,KC_DQUO ,KC_AT   ,KC_DLR  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,KC_GRV  ,KC_LCBR ,KC_RCBR ,KC_PERC ,KC_PGUP ,_______ ,        _______ ,KC_HOME ,KC_ASTR ,KC_SLSH ,KC_BSLS ,KC_AMPR ,XXXXXXX ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,XXXXXXX ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     XXXXXXX ,XXXXXXX ,KC_RALT ,KC_RCTL 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_FUNCS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_F11  ,KC_F12  ,KC_F13  ,KC_F14  ,KC_F15  ,                                            KC_F16  ,KC_F17  ,KC_F18  ,KC_F19  ,KC_F20  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,XXXXXXX ,                          XXXXXXX ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,XXXXXXX ,                          XXXXXXX ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_MUTE ,KC_VOLD ,KC_VOLU ,KC_BRID ,KC_BRIU ,KC_PGUP ,_______ ,        _______ ,KC_HOME ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,FUNCS   ,     XXXXXXX ,    _______ ,_______ ,        _______ ,_______ ,    XXXXXXX ,     FUNCS   ,KC_MPRV ,KC_MPLY ,KC_MNXT 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_NLCK ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_UP   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_PSLS ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RGHT ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_PAST ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_PGUP ,_______ ,        _______ ,KC_HOME ,XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,XXXXXXX ,     XXXXXXX ,    _______ ,_______ ,        _______ ,_______ ,    XXXXXXX ,     KC_P0   ,KC_PDOT ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QWERTY  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RESET   ,RGB_TOG ,RGB_VAD ,RGB_VAI ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,RESET   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,QWERTY  ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,QWERTY  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};

const rgblight_segment_t PROGMEM rgb_COLEMAK[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_CYAN} // start at led 0, set 14 leds to cyan
);

const rgblight_segment_t PROGMEM rgb_QWERTY[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_RED}
);

const rgblight_segment_t PROGMEM rgb_SYMBOL[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_GREEN}
);

const rgblight_segment_t PROGMEM rgb_FUNCS[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_GOLD}
);

const rgblight_segment_t PROGMEM rgb_NAV[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM rgb_ADJUST[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_PINK}
);

const rgblight_segment_t PROGMEM rgb_caps_lock[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 4, HSV_MAGENTA}
);

const rgblight_segment_t PROGMEM rgb_num_lock[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_MAGENTA},
    {12, 2, HSV_MAGENTA}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST( // layers overlap, later take precedence, max 8 layers
    rgb_COLEMAK,
    rgb_QWERTY,
    rgb_SYMBOL,
    rgb_FUNCS,
    rgb_NAV,
    rgb_ADJUST,
    rgb_caps_lock,
    rgb_num_lock
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
    rgblight_set_layer_state(0, true);
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(6, led_state.caps_lock);
    rgblight_set_layer_state(7, !led_state.num_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAK));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    for (int i=0; i<=_ADJUST; i++) {
        rgblight_set_layer_state(i, layer_state_cmp(state, i));
    }
    return state;
}
