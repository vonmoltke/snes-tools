/*
 * hexdumper.c
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

#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "rom_structs.h"
#include "util.h"

int main(const int argc, const char* argv[])
{
  if (argc < 2)
  {
    printf("ERROR: not enough arguments");
    printf("Expected %d; got %d", 2, argc);
    return -1;
  }

  const char* rom_filename = argv[1];
  const FILE* rom_file = fopen(rom_filename);

  // Read all data and verify successful read
  char *raw_rom_data = malloc(MAX_ROM_SIZE);
  const size_t bytes_read = fread(raw_rom_data, 1, MAX_ROM_SIZE, rom_file);

  // Either bytes_resd should be  MAX_ROM_SIZE, or it should be less and
  // rom_file should be at EOF
  if (bytes_read < MAX_ROM_SIZE)
  {
    if (feof(rom_file) == 0)
    {
      printf("Error reading file %s\n", rom_filename);
      // TODO add error code?
      return -1;
    }
  }

  const ROM_TYPE_t rom_type = id_ROM_type(raw_rom_data);

  return 0;
}
