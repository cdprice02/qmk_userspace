// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define TAPPING_TERM_PER_KEY
#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#    define TAPPING_TERM 200
#endif

#ifdef ENCODER_RESOLUTION
#    undef ENCODER_RESOLUTION
#    define ENCODER_RESOLUTION 4
#endif
