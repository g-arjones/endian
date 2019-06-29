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

#include <endian/be_uint24_t.h>
#include <stdint.h>

namespace endian {

be_uint24_t::be_uint24_t() : msb_(0), mid_(0), lsb_(0) {}

be_uint24_t::be_uint24_t(const uint32_t &val)
  : msb_((val >> 16) & 0xFF)
  , mid_((val >> 8) & 0xFF)
  , lsb_(val & 0xFF) {}

be_uint24_t::operator uint32_t() const { return (lsb_ | (mid_ << 8) | (msb_ << 16)); }

};  // namespace endian
