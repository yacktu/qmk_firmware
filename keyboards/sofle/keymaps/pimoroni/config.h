#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#ifdef PIMORONI_TRACKBALL_ENABLE
#   define POINTING_DEVICE_ROTATION_90
#   //define PIMORONI_TRACKBALL_SCALE 3
#   define SPLIT_TRANSACTION_IDS_KB MOUSE_SYNC
#endif

#undef TAPPING_TERM
#define TAPPING_TERM 250

