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

#include <endian/le_uint16_t.h>
#include <stdint.h>

namespace endian {

le_uint16_t::le_uint16_t() : lsb_(0), msb_(0) {}
le_uint16_t::le_uint16_t(const uint16_t &val) : lsb_(val & 0xFF), msb_(val >> 8) {}
le_uint16_t::operator uint16_t() const { return (lsb_ | (msb_ << 8)); }

};  // namespace endian
