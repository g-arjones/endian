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

#ifndef ENDIAN_ENDIAN_BASE_T_H_
#define ENDIAN_ENDIAN_BASE_T_H_

namespace endian {

#define ENDIAN_BEGIN_CLASS(cppname, cpptype)                                                       \
class cppname {                                                                                    \
 public:                                                                                           \
  cppname();                                                                                       \
  cppname(const cpptype &val);                                                                     \
                                                                                                   \
  template <typename T> cppname &operator +=(const T &rhs) { return (*this = (*this + rhs)); }     \
  template <typename T> cppname &operator -=(const T &rhs) { return (*this = (*this - rhs)); }     \
  template <typename T> cppname &operator *=(const T &rhs) { return (*this = (*this * rhs)); }     \
  template <typename T> cppname &operator /=(const T &rhs) { return (*this = (*this / rhs)); }     \
  template <typename T> cppname &operator %=(const T &rhs) { return (*this = (*this % rhs)); }     \
  template <typename T> cppname &operator <<=(const T &rhs) { return (*this = (*this << rhs)); }   \
  template <typename T> cppname &operator >>=(const T &rhs) { return (*this = (*this >> rhs)); }   \
  template <typename T> cppname &operator &=(const T &rhs) { return (*this = (*this & rhs)); }     \
  template <typename T> cppname &operator |=(const T &rhs) { return (*this = (*this | rhs)); }     \
  template <typename T> cppname &operator ^=(const T &rhs) { return (*this = (*this ^ rhs)); }     \
                                                                                                   \
  operator cpptype() const;                                                                        \
                                                                                                   \
  cppname &operator ++() { return (*this = (*this + 1)); }                                         \
  cppname &operator --() { return (*this = (*this - 1)); }                                         \
                                                                                                   \
  cppname operator ++(int) { cppname cpy(*this); ++*this; return cpy; }                            \
  cppname operator --(int) { cppname cpy(*this); --*this; return cpy; }

#define ENDIAN_END_CLASS(cppname, cpptype)                                                         \
} __attribute__((packed, aligned(1)));                                                             \

};  // namespace endian
#endif  // ENDIAN_ENDIAN_BASE_T_H_
