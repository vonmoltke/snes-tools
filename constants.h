/*
 * constants.h
 *
 * SNES=related constants
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

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

// Size of the himem and lowmem blocks (in bytes)
const int HIMEM_SIZE = 64 * 1024;
const int LOMEM_SIZE = 32 * 1024;

// Size of the SFC header (in bytes), if present.  This will act as an offset
// for all other memory addresses when processing an SFC file.
const int SFC_HEADER_SIZE = 512;

#endif /* CONSTANTS_H_ */