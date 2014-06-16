/*
 * util.c
 *
 * Utility functions for working with SNES ROMs
 *
 * ----------------------------------------------------------------------------
 * 
 * Copyright 2014 Wayne Krug
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdbool.h>

#include "rom_structs.h"

ROM_TYPE_t id_ROM_type(const char* rom_data)
{
  // TODO implement me
  return LOMEM;
};
