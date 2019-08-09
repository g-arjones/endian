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

#ifndef ENDIAN_BASE_H_
#define ENDIAN_BASE_H_

#include <stdint.h>
#include <stddef.h>

#include <type_traits>

namespace endian {

enum class endianness_t {
  BIG,
  LITTLE
};

template <typename host_t, endianness_t endianness>
class endian_base {
 public:
  endian_base() : bytes_{0} {}
  endian_base(const host_t &val) {
    uint8_t shifter = initialShifter();
    for (size_t i = 0; i < sizeof(host_t); i++, iterateShifter(shifter)) {
      bytes_[i] = (uint8_t)((val >> shifter) & 0xFF);
    }
  }

  operator host_t() const {
    host_t result = 0;
    uint8_t shifter = initialShifter();
    for (size_t i = 0; i < sizeof(host_t); i++, iterateShifter(shifter)) {
        result |= (bytes_[i] << shifter);
    }
    return result;
  }

  template <typename T> endian_base &operator +=(const T &rhs) { return (*this = (*this + rhs)); }
  template <typename T> endian_base &operator -=(const T &rhs) { return (*this = (*this - rhs)); }
  template <typename T> endian_base &operator *=(const T &rhs) { return (*this = (*this * rhs)); }
  template <typename T> endian_base &operator /=(const T &rhs) { return (*this = (*this / rhs)); }
  template <typename T> endian_base &operator %=(const T &rhs) { return (*this = (*this % rhs)); }
  template <typename T> endian_base &operator <<=(const T &rhs) { return (*this = (*this << rhs)); }
  template <typename T> endian_base &operator >>=(const T &rhs) { return (*this = (*this >> rhs)); }
  template <typename T> endian_base &operator &=(const T &rhs) { return (*this = (*this & rhs)); }
  template <typename T> endian_base &operator ^=(const T &rhs) { return (*this = (*this ^ rhs)); }
  template <typename T> endian_base &operator |=(const T &rhs) { return (*this = (*this | rhs)); }
  endian_base &operator ++() { return (*this = (*this + 1)); }
  endian_base &operator --() { return (*this = (*this - 1)); }
  endian_base operator ++(int) { endian_base cpy(*this); ++*this; return cpy; }
  endian_base operator --(int) { endian_base cpy(*this); --*this; return cpy; }
 private:
  uint8_t bytes_[sizeof(host_t)];
  uint8_t initialShifter() const { return endianness == endianness_t::BIG ? 8 * (sizeof(host_t) - 1) : 0; }
  uint8_t iterateShifter(uint8_t& shifter) const { return endianness == endianness_t::BIG ? shifter -= 8 : shifter += 8; }
} __attribute__((packed, aligned(1)));


};  // namespace endian
#endif  // ENDIAN_BASE_H_
