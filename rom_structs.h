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

/*
 * Definition of an SNES header.  The header is a 64-byte block that records
 * basic information about the cartridge.  The table below lists the fields.
 * This struct is suitable to be laid over a 64-byte raw memory block (no
 * parsing required).
 *
 * Bytes   Type    Description
 * ------- ------- ------------------------------------------------------------
 * 0 - 20   char   Name of the ROM, typically in ASCII, using spaces to pad the
 *                 name to 21 bytes
 * 21       uint8  ROM layout, typically 0x20 for LoROM, or 0x21 for HiROM. Add
 *                 0x10 for FastROM
 * 22       uint8  Cartridge type, typically 0x00 for ROM only, or 0x02 for ROM
 *                 with save-RAM
 * 23       uint8  ROM size byte
 * 24       uint8  RAM size byte
 * 25       uint8  Country code, which selects the video in the emulator. Values
 *                 0x00, 0x01, 0x0d use NTSC. Values in range 0x02..0x0c use
 *                 PAL. Other values are invalid.
 * 26       uint8  Licensee code. If this value is 0x33, then the ROM has an
 *                 extended header with ID at 0xffb2..0xffb5.
 * 27       uint8  Version number, typically 0x00
 * 28 - 29  uint16 Checksum complement, which is the bitwise-xor of the checksum
 *                 and 0xffff
 * 30 - 31  uint16 SNES checksum
 * 32 - 35  N/A    Unknown
 * 36 - 37  uint16 COP interrupt handler (real mode)
 * 38 - 39  uint16 BRK interrupt handler (real mode)
 * 40 - 41  uint16 ABORT interrupt handler (real mode)
 * 42 - 43  uint16 NMI (vertical blank) interrupt handler (real mode)
 * 44 - 45  uint16 Unused
 * 46 - 47  uint16 IRQ interrupt handler (real mode)
 * 48 - 51  N/A    Unknown
 * 52 - 53  uint16 COP interrupt handler (emulation mode)
 * 54 - 55  uint16 Unused
 * 56 - 57  uint16 ABORT interrupt handler (emulation mode)
 * 58 - 59  uint16 NMI (vertical blank) interrupt handler (emulation mode)
 * 60 - 61  uint16 RESET (start game) interrupt handler (emulation mode)
 * 62 - 63  uint16 IRQ or BRK interrupt handler (emulation mode)
 */
struct SNES_Header_t
{
  char cart_name[21];
  uint8_t rom_type;
  uint8_t cart_type;
  uint8_t rom_size;
  uint8_t ram_size;
  uint8_t country_code;
  uint8_t licensee_code;
  uint8_t version;
  uint16_t checksum_complement;
  uint16_t checksum;
  uint16_t unused[2];
  uint16_t cop_handler_rm;
  uint16_t brk_handler_rm;
  uint16_t abort_handler_rm;
  uint16_t nmi_handler_rm;
  uint16_t unused2;
  uint16_t irq_handler_rm;
  uint16_t unused3[2];
  uint16_t cop_handler_em;
  uint16_t unused4;
  uint16_t abort_handler_em;
  uint16_t nmi_handler_em;
  uint16_t reset_handler_em;
  uint16_t irq_brk_handler_em;
};

// Convenience types for reading memory blocks

struct Lomem_Block_t
{
  unsigned char data[LOMEM_SIZE];
};

struct Himem_Block_t
{
  unsigned char data[HIMEM_SIZE];
};

#endif /* ROM_STRUCTS_H_ */
