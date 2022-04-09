// Copyright 2022 Ajani James Bilby (@ajanibilby)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT




#define TAPPING_TERM 200



#define RGBLED_NUM 27
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_DI_PIN F6
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_STARTUP_HUE 209
#define RGB_MATRIX_STARTUP_SAT 255
#define RGB_MATRIX_STARTUP_VAL 100

#define RGBLIGHT_ANIMATIONS
#define RGB_MATRIX_LED_FLUSH_LIMIT 33 // 30fps (32ms frame time)

#if defined RGB_MATRIX_ENABLE
#  define RGB_MATRIX_KEYPRESSES   // reacts to keypresses
#  define RGB_MATRIX_FRAMEBUFFER_EFFECTS  // reacts to keyreleases (instead of keypresses)
// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#  define ENABLE_RGB_MATRIX_BREATHING
#  define EnABLE_RGB_MATRIX_CYCLE_PINWHEEL
#  define ENABLE_RGB_MATRIX_RAINDROPS
#  define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#  define ENABLE_RGB_MATRIX_HUE_BREATHING
#  define ENABLE_RGB_MATRIX_HUE_PENDULUM
#  define ENABLE_RGB_MATRIX_HUE_WAVE
#  define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#  define ENABLE_RGB_MATRIX_PIXEL_FLOW
#  define ENABLE_RGB_MATRIX_PIXEL_RAIN
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#  define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#  define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#  define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#endif

#define VIA_QMK_RGBLIGHT_ENABLE
#define VIA_CUSTOM_LIGHTING_ENABLE

#define FORCE_NKRO