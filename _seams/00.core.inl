/* IGEEK @version 0.x
@link    https://github.com/kabuki-starship/igeek.git
@file    /_seams/00.core.h
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2015-9 Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain
one at <https://mozilla.org/MPL/2.0/>. */
#pragma once
#include <_config.h>
#if SEAM == IGEEK_TEST
#include "_debug.inl"
#else
#include "_release.inl"
#endif
using namespace _;
namespace igeek {
inline const CHA* Core(const CHA* args) {
#if SEAM >= IGEEK_CORE
  TEST_BEGIN;

#endif
  return 0;
}
}  // namespace igeek
