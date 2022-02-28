#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/


//#define USE_MATRIX_I2C

#define EE_HANDS

#define CUSTOM_FONT

#define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding

#undef TAPPING_TERM
#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY
#define RETRO_TAPPING

#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4

#define SPLIT_TRANSACTION_IDS_KB MOUSE_SYNC
#define SPLIT_LAYER_STATE_ENABLE

