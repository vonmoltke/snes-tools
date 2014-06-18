/*
 * pto2_rom_structs.h
 *
 * Structs that define the in-memory format of data entries in the PTO 2 ROM.
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

#ifndef PTO2_ROM_STRUCTS_H_
#define PTO2_ROM_STRUCTS_H_

#include <inttypes.h>

/*
 * Entry for a tank in the scenario data
 *
 * name      - Null-padded name of the tank
 * active    - 1 if the tank is active at the beginning of the scenario; 0
 *             otherwise
 * firepower - Offensive power of the tank; real value is +1
 * armor     - Defensive power of the tank; real value is +1
 */
struct Tank_t
{
  char name[13];
  uint8_t active    :4;
  uint8_t firepower :2;
  uint8_t armor     :2;
};



#endif /* PTO2_ROM_STRUCTS_H_ */
