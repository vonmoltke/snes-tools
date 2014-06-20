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
#include <ctype.h>

#include "constants.h"
#include "rom_structs.h"
#include "util.h"

Block_Type_t process_block(const char* block, const int block_number, const int block_size)
{
  for (int line_start = 0; line_start < block_size; line_start += 16)
  {
    printf("%08x:  ", (block_number * block_size) + line_start);

    char ascii_string[17];
    ascii_string[16] = '\0';
    for (int byte = line_start; byte < (line_start + 16); ++byte)
    {
      printf("%02x ", block[byte]);
      ascii_string[byte - line_start] = isprint(block[byte]) ? block[byte] : '.';
    }

    printf(" |%s|\n", ascii_string);
  }

  return EMPTY;
}

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

  const int rom_block_size;
  switch (id_ROM_type(raw_rom_data))
  {
  case LOMEM:
    rom_block_size = LOMEM_SIZE;
    break;
  case HIMEM:
    rom_block_size = HIMEM_SIZE;
    break;
  default:
    printf("Invalid ROM type");
    return -1;
  }

  const int num_blocks = bytes_read / rom_block_size;
  // Verify the division had no truncated remainder
  if ((rom_block_size * num_blocks) != bytes_read)
  {
    printf("Did not read an integer number of blocks from the ROM image");
    return -1;
  }

  char *block = raw_rom_data;
  for (int block_number = 0; block_number < num_blocks; ++block_number)
  {
    printf("\nBlock %d:\n\n");
    Block_Type_t type = process_block(block, block_number, rom_block_size);
    block += rom_block_size;
  }

  return 0;
}
