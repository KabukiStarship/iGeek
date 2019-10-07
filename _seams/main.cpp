/* IGEEK @version 0.x
@link    https://github.com/kabuki-starship/igeek.git
@file    /_seams/main.h
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2015-9 Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain
one at <https://mozilla.org/MPL/2.0/>. */
#include "../../kabuki.toolkit/server.inl"
int main(int arg_count, const char** args) {
  return kt::Server(args, arg_count).Run();
}
