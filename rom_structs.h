/*
 * rom_structs.h
 *
 * This file contains structs that represent the data format of portions of an
 * SNES ROM image.
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

#ifndef ROM_STRUCTS_H_
#define ROM_STRUCTS_H_

#include <inttypes.h>

#include "constants.h"

struct SNES_Header_t
{
  // Cartridge name
  char cart_name[20];
};

// Typedefs for the memory blocks
typedef char[HIMEM_SIZE] Himem_Block_t;
typedef char[LOMEM_SIZE] Lomem_Block_t;

#endif /* ROM_STRUCTS_H_ */
