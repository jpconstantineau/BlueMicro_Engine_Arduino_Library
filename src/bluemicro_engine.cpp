// SPDX-FileCopyrightText: 2022 BlueMicro_Engine_Arduino_Library contributors (https://github.com/jpconstantineau/BlueMicro_Engine_Arduino_Library/graphs/contributors)
//
// SPDX-License-Identifier: BSD-3-Clause

#include "bluemicro_engine.h"

// command_less is used for sorting
bool command_less (command_t i,command_t j) { return (i.first<j.first); }