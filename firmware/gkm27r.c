#include "gkm27r.h"

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {      5,      4,      3,      2,      1,      0 },
  {      6,      7,      8,      9,     10,     11 },
  {     17,     16,     15,     14,     13,     12 },
  {     18,     19,     20,     21,     22,     23 },
  {    NO_LED, NO_LED, NO_LED,  26,     25,     24 }
}, {
  // LED Index to Physical Position
  {0,  0}, {45,  0}, {90,  0}, {134,  0}, {179,  0}, {224,  0},
  {0, 16}, {45, 16}, {90, 16}, {134, 16}, {179, 16}, {224, 16},
  {0, 32}, {45, 32}, {90, 32}, {134, 32}, {179, 32}, {224, 32},
  {0, 48}, {45, 48}, {90, 48}, {134, 48}, {179, 48}, {224, 48},
                               {134, 64}, {179, 64}, {224, 64},
}, {
  // LED Index to Flag
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
           4, 4, 4,
} };
