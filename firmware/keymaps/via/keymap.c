#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
		KC_ESC,     KC_1,    KC_2,     KC_3,   KC_4,     KC_5,
		KC_TAB,     KC_Q,    KC_W,     KC_E,   KC_R,     KC_T,
		KC_LSFT,    KC_A,    KC_S,     KC_D,   KC_F,     KC_G,
		KC_LCTRL,   KC_Z,    KC_X,     KC_C,   KC_V,     KC_B,
		                               KC_COMMA, KC_DOT, KC_SLASH
    )
};


union via_layout_options_t {
	uint32_t raw;
	struct {
		bool layout_split_backspace;
		bool another_layout_config;
	};
};

union via_layout_options_t via_layout_options;

/**
 * @brief blank out leds based on layout
 *
 * Disable certain leds based on the layout.  Could use flags here, but doesn't matter.
 */
void rgb_matrix_indicators_user(void) {
#    ifdef VIA_ENABLE
	if (via_layout_options.layout_split_backspace) {
		rgb_matrix_set_color(5, 0, 0, 0);
		rgb_matrix_set_color(7, 0, 0, 0);
	} else {
		rgb_matrix_set_color(6, 0, 0, 0);
	}
#endif
}

/**
 * @brief grab layout options at in interval
 *
 * Because VIA doesn't offer the keyboard code any way to get this information normally,
 * we have to use an ugly fucking hack to read the information frequently.
 */
#    ifdef VIA_ENABLE
void via_set_layout_options_kb(uint32_t value) {
	via_layout_options.raw = value;
}
#endif


void via_qmk_rgblight_get_value(uint8_t *data) {
	uint8_t *value_id   = &(data[0]);
	uint8_t *value_data = &(data[1]);
	switch (*value_id) {
		case id_qmk_rgblight_brightness: {
			value_data[0] = rgb_matrix_get_val();
			break;
		}
		case id_qmk_rgblight_effect: {
			value_data[0] = rgb_matrix_is_enabled() ? rgb_matrix_get_mode() : 0;
			break;
		}
		case id_qmk_rgblight_effect_speed: {
			value_data[0] = rgb_matrix_get_speed();
			break;
		}
		case id_qmk_rgblight_color: {
			value_data[0] = rgb_matrix_get_hue();
			value_data[1] = rgb_matrix_get_sat();
			break;
		}
	}
}

void via_qmk_rgblight_set_value(uint8_t *data) {
	uint8_t *value_id   = &(data[0]);
	uint8_t *value_data = &(data[1]);
	switch (*value_id) {
		case id_qmk_rgblight_brightness: {
			rgb_matrix_sethsv_noeeprom(rgblight_get_hue(), rgblight_get_sat(), value_data[0]);
			break;
		}
		case id_qmk_rgblight_effect: {
			if (value_data[0] == 0) {
				rgb_matrix_disable_noeeprom();
			} else {
				rgb_matrix_enable_noeeprom();
				rgb_matrix_mode_noeeprom(value_data[0]);
			}
			break;
		}
		case id_qmk_rgblight_effect_speed: {
			rgb_matrix_set_speed_noeeprom(value_data[0]);
			break;
		}
		case id_qmk_rgblight_color: {
			rgb_matrix_sethsv_noeeprom(value_data[0], value_data[1], rgblight_get_val());
			break;
		}
	}
}


void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
	uint8_t *command_id = &(data[0]);
	uint8_t *command_data = &(data[1]);
	switch (*command_id) {
		case id_lighting_set_value:
			via_qmk_rgblight_set_value(command_data);
			break;
		case id_lighting_get_value:
			via_qmk_rgblight_get_value(command_data);
			break;
		case id_lighting_save:
			eeconfig_update_rgb_matrix();
			break;
		default:
			// Unhandled message.
			*command_id = id_unhandled;
			break;
	}
}