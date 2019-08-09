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

#ifndef ENDIAN_LE_UINT64_T_H_
#define ENDIAN_LE_UINT64_T_H_

#include <endian/endian_base.h>

namespace endian {

typedef endian_base<uint64_t, endianness_t::LITTLE> le_uint64_t;

};  // namespace endian
#endif  // ENDIAN_LE_UINT64_T_H_
