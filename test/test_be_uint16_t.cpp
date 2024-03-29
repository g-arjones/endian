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

using endian::be_uint16_t;

int g_status;

int main(int argc, char **argv) {
  uint8_t data[] = {0xaa, 0xbb, 0x00, 0x16, 0xcc, 0xdd};

  ASSERT(sizeof(be_uint16_t) == 2);
  testCommon<be_uint16_t>(data, sizeof(data));

  return g_status;
}
