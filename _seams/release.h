/* IGEEK @version 0.x
@link    https://github.com/kabuki-starship/igeek.git
@file    /_seams/release.inl
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2015-9 Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain
one at <https://mozilla.org/MPL/2.0/>. */
#pragma once
#include <_config.h>

#if SEAM == KABUKI_PACKAGES_RELEASE
#include "_debug.inl"
#else
#include "_release.inl"
#endif

using namespace _;

namespace igeek { 
inline const CHA* Release (CHA* seam_log, CHA* seam_end, const CHA* args) {
#if SEAM >= KABUKI_PACKAGES_RELEASE
  TEST_BEGIN;
#endif
  return 0;
}
}  //< namespace igeek
