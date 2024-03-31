#include QMK_KEYBOARD_H

#define _COLEMAK 0
#define _QWERTY 1
#define _SYMBOL 2
#define _FUNCS 3
#define _NAV 4
#define _ADJUST 5

bool is_recording = false;
bool is_recording_led_on = false;
static uint16_t recording_timer;

enum custom_keycodes {
    PLUS_EQL = SAFE_RANGE,
    MINS_EQL,
    ARROW,
    FATARROW,
    RERUN,
    WAIT250,
    WAIT500,
    WAIT1000,
};

enum {
    TD_LCTL_LGUI,
    TD_RCTL_RGUI,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LCTL_LGUI] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LGUI),
    [TD_RCTL_RGUI] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, KC_RGUI),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PLUS_EQL:
            if (record->event.pressed) {
                SEND_STRING("+=");
            }
            break;
        
        case MINS_EQL:
            if (record->event.pressed) {
                SEND_STRING("-=");
            }
            break;
        
        case ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        
        case FATARROW:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;
        
        case RERUN:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER));
            }
            break;
        
        case WAIT250:
            if (record->event.pressed) {
                _delay_ms(250);
            }
            break;
        
        case WAIT500:
            if (record->event.pressed) {
                _delay_ms(500);
            }
            break;
        
        case WAIT1000:
            if (record->event.pressed) {
                _delay_ms(1000);
            }
            break;
     
        // case SH_OS:
        //     rgblight_set_layer_state(9, is_swap_hands_on());
        //     break;
    }
    return true;
}

void matrix_scan_user(void) {
    if (is_recording && timer_elapsed(recording_timer) > 250) {
        is_recording_led_on = !is_recording_led_on;
        recording_timer = timer_read();
        rgblight_set_layer_state(8, is_recording_led_on);
    }
}

void dynamic_macro_record_start_user(void) {
    is_recording = true;
    is_recording_led_on = true;
    rgblight_set_layer_state(8, is_recording_led_on);
    recording_timer = timer_read();
}

void dynamic_macro_record_end_user(int8_t direction) {
    is_recording = false;
    is_recording_led_on = false;
    rgblight_set_layer_state(8, is_recording_led_on);
}

// shortcuts to make keymap more readable
#define SYM MO(_SYMBOL)
#define FUNCS MO(_FUNCS)
#define TTFUNCS MO(_FUNCS)
#define NAV MO(_NAV)
#define QWERTY TG(_QWERTY)

#define ADJ_INS LT(_ADJUST, KC_INS)
#define COMPOSE KC_F21 // this does fit in the keymap but i wanted to make it more clear why it's there

#define LCTL_GUI TD(TD_LCTL_LGUI)
#define RCTL_GUI TD(TD_RCTL_RGUI)

#define LINEUP LALT(KC_UP)
#define LINEDOWN LALT(KC_DOWN)
#define TERMINAL LCTL(KC_GRV)
#define CMDPALET LCTL(LSFT(KC_P))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_PSCR ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,ADJ_INS ,                          KC_DEL  ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,QWERTY  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NAV     ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,KC_LT   ,                          KC_GT   ,KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,NAV     ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,LCTL_GUI,KC_LALT ,        KC_RALT ,RCTL_GUI,KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_UP   ,COMPOSE ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_LGUI ,KC_LALT ,FUNCS   ,     SYM     ,    KC_SPC  ,KC_BSPC ,        KC_RSFT ,KC_ENT  ,    SYM     ,     FUNCS   ,KC_LEFT ,KC_DOWN ,KC_RGHT 
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
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,ARROW   ,FATARROW,                                            XXXXXXX ,PLUS_EQL,MINS_EQL,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,KC_TILD ,KC_LBRC ,KC_RBRC ,KC_UNDS ,_______ ,                          _______ ,KC_QUES ,KC_PLUS ,KC_MINS ,KC_CIRC ,KC_SCLN ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PIPE ,KC_HASH ,KC_LPRN ,KC_RPRN ,KC_EQL  ,_______ ,                          _______ ,KC_EXLM ,KC_QUOT ,KC_DQUO ,KC_AT   ,KC_DLR  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,KC_GRV  ,KC_LCBR ,KC_RCBR ,KC_PERC ,_______ ,_______ ,        _______ ,_______ ,KC_ASTR ,KC_SLSH ,KC_BSLS ,KC_AMPR ,KC_COLN ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,XXXXXXX ,KC_RALT ,KC_RCTL 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_FUNCS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_F11  ,KC_F12  ,KC_F13  ,KC_F14  ,KC_F15  ,                                            KC_F16  ,KC_F17  ,KC_F18  ,KC_F19  ,KC_F20  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,XXXXXXX ,                          _______ ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,XXXXXXX ,                          XXXXXXX ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_MUTE ,KC_VOLD ,KC_VOLU ,KC_BRID ,KC_BRIU ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,XXXXXXX ,KC_COMM ,KC_DOT  ,XXXXXXX ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,KC_MPRV ,KC_MPLY ,KC_MNXT 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_NLCK ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_PGUP ,LINEUP  ,KC_UP   ,LINEDOWN,KC_HOME ,XXXXXXX ,                          _______ ,KC_PSLS ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_END  ,XXXXXXX ,                          XXXXXXX ,KC_PAST ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,TERMINAL,CMDPALET,XXXXXXX ,_______ ,_______ ,        _______ ,_______ ,KC_COMM ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     KC_P0   ,KC_PDOT ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QWERTY  ,RERUN   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,SH_OS   ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RESET   ,RGB_TOG ,RGB_VAD ,RGB_VAI ,XXXXXXX ,_______ ,                          XXXXXXX ,DM_RSTP ,DM_REC1 ,DM_REC2 ,XXXXXXX ,RESET   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,DM_PLY1 ,DM_PLY2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,WAIT250 ,WAIT500 ,WAIT1000,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};

// #0080FF
#define HSV_BASE_BLUE 149, 255, 255
#define HSV_VIOLET    180, 255, 255
#define HSV_ROSE      222, 255, 255

// *******  *******
const rgblight_segment_t PROGMEM rgb_COLEMAK[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_BASE_BLUE} // start at led 0, set 14 leds to main keyboard colour
);

// *******  *******
const rgblight_segment_t PROGMEM rgb_QWERTY[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_RED}
);

// *******  *******
const rgblight_segment_t PROGMEM rgb_SYMBOL[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_GREEN}
);

// *******  *******
const rgblight_segment_t PROGMEM rgb_FUNCS[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_GOLD}
);

// *******  *******
const rgblight_segment_t PROGMEM rgb_NAV[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_PURPLE}
);

// *******  *******
const rgblight_segment_t PROGMEM rgb_ADJUST[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_PINK}
);

// -----**  **-----
const rgblight_segment_t PROGMEM rgb_caps_lock[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 4, HSV_MAGENTA}
);

// **-----  -----**
const rgblight_segment_t PROGMEM rgb_num_lock[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_MAGENTA},
    {12, 2, HSV_MAGENTA}
);

// ---****  ****---
const rgblight_segment_t PROGMEM rgb_recording[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 8, HSV_PINK}
);

// --***--  --***--
const rgblight_segment_t PROGMEM rgb_swap_hands[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 3, HSV_ROSE},
    {9, 3, HSV_VIOLET}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST( // layers overlap, later take precedence, max 12 layers (change in rules.mk)
    rgb_COLEMAK,    // 0
    rgb_QWERTY,     // 1
    rgb_SYMBOL,     // 2
    rgb_FUNCS,      // 3
    rgb_NAV,        // 4
    rgb_ADJUST,     // 5
    rgb_caps_lock,  // 6
    rgb_num_lock,   // 7
    rgb_recording,  // 8
    rgb_swap_hands  // 9
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

/*
#define LAYOUT( \
  k00, k01, k02, k03, k04, k05,                          k08, k09, k10, k11, k12, k13, \
  k14, k15, k16, k17, k18, k19, k06,                k07, k22, k23, k24, k25, k26, k27, \
  k28, k29, k30, k31, k32, k33, k20,                k21, k36, k37, k38, k39, k40, k41, \
  k42, k43, k44, k45, k46, k47, k34, k48,      k49, k35, k50, k51, k52, k53, k54, k55, \
  k56, k57, k58, k59,    k60,   k61, k62,      k63, k64,   k65,    k66, k67, k68, k69  \
) \
row/col 0    1    2    3    4    5    6
0    { k00, k01, k02, k03, k04, k05, k06 }, \
1    { k14, k15, k16, k17, k18, k19, k20 }, \
2    { k28, k29, k30, k31, k32, k33, k34 }, \
3    { k42, k43, k44, k45, k46, k47, k48 }, \
4    { k56, k57, k58, k59, k60, k61, k62 }, \

5    { k13, k12, k11, k10, k09, k08, k07 }, \
6    { k27, k26, k25, k24, k23, k22, k21 }, \
7    { k41, k40, k39, k38, k37, k36, k35 }, \
8    { k55, k54, k53, k52, k51, k50, k49 }, \
9    { k69, k68, k67, k66, k65, k64, k63 }  \
}
*/
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}, {6, 5}},
    {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 6}},
    {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}, {6, 7}},
    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}},
    {{0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9}, {6, 9}},

    {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}},
    {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}},
    {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}},
    {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}},
    {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}},
};
