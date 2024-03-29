/*
 *  Copyright [2019] [Gabriel Arjones]
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include "test_common.h"
#include <stdint.h>
#include <endian/endian.h>

using endian::le_uint64_t;

int g_status;

int main(int argc, char **argv) {
  uint8_t data[] = {0xbb, 0xaa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x16, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0xdd, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

  ASSERT(sizeof(le_uint64_t) == 8);
  testCommon<le_uint64_t>(data, sizeof(data));

  return g_status;
}
