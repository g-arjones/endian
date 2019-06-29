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

#ifndef TEST_TEST_COMMON_H_
#define TEST_TEST_COMMON_H_

#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>

template <typename T>
struct packet_t {
  T a;
  T b;
  T c;
} __attribute__((packed, aligned(1)));

extern int g_status;

#define ASSERT(expr)                                                                                      \
  do {                                                                                                    \
    if (!(expr)) {                                                                                        \
      g_status = 1;                                                                                       \
      std::cout << __FILE__ << ":" << __LINE__ << ": Assertion \"" << #expr << "\" failed!" << std::endl; \
    }                                                                                                     \
  } while ( 0 )

template <typename T>
void testCommon(const uint8_t *data, size_t size) {
  packet_t<T> bar;

  memcpy(&bar, data, size);
  ASSERT(bar.a == 0xaabb);
  ASSERT(bar.b == 0x16);
  ASSERT(bar.c == 0xccdd);

  bar.a = 0xaabb;
  bar.b = 0x16;
  bar.c = 0xccdd;
  ASSERT(bar.a == 0xaabb);
  ASSERT(bar.b == 0x16);
  ASSERT(bar.c == 0xccdd);
  ASSERT(memcmp(&bar, data, size) == 0);

  bar.a = 4;
  ASSERT(bar.a + 1 == 5);
  ASSERT(bar.a - 1 == 3);
  ASSERT(bar.a / 2 == 2);
  ASSERT(bar.a * 2 == 8);
  ASSERT(bar.a % 3 == 1);

  ASSERT(bar.a++ == 4);
  ASSERT(bar.a == 5);

  ASSERT(++bar.a == 6);
  ASSERT(bar.a == 6);

  ASSERT(bar.a-- == 6);
  ASSERT(bar.a == 5);

  ASSERT(--bar.a == 4);
  ASSERT(bar.a == 4);

  T &a = (bar.a += 1);
  a++;
  ASSERT(a == 6);
  ASSERT(a == bar.a);

  T &b = ++bar.a;
  b++;
  ASSERT(b == 8);
  ASSERT(b == bar.a);

  T &c = (bar.a -= 1);
  c--;
  ASSERT(c == 6);
  ASSERT(c == bar.a);

  T &d = --bar.a;
  d--;
  ASSERT(d == 4);
  ASSERT(d == bar.a);

  T &e = (bar.a /= 1);
  e++;
  ASSERT(e == 5);
  ASSERT(e == bar.a);

  T &f = (bar.a *= 1);
  f++;
  ASSERT(f == 6);
  ASSERT(f == bar.a);

  T &g = (bar.a %= 5);
  g++;
  ASSERT(g == 2);
  ASSERT(g == bar.a);

  bar.a = 0x00FF;
  T &h = (bar.a <<= 8);
  ASSERT(h == 0xFF00);
  h = 0;
  ASSERT(h == bar.a);

  bar.a = 0xFF00;
  T &i = (bar.a >>= 8);
  ASSERT(i == 0x00FF);
  i = 0;
  ASSERT(i == bar.a);

  bar.a = 0xFF00;
  T &j = (bar.a |= 0x00FF);
  ASSERT(j == 0xFFFF);
  j = 0;
  ASSERT(j == bar.a);

  bar.a = 0xFFFF;
  T &k = (bar.a &= 0x00FF);
  ASSERT(k == 0x00FF);
  k = 0;
  ASSERT(k == bar.a);

  bar.a = 0xFF00;
  T &l = (bar.a ^= 0x00FF);
  ASSERT(l == 0xFFFF);
  l = 0;
  ASSERT(l == bar.a);

  bar.a = 2;
  ASSERT(bar.a > 1);
  ASSERT(bar.a >= 2);
  ASSERT(bar.a < 3);
  ASSERT(bar.a <= 2);
  ASSERT(bar.a == 2);
  ASSERT(bar.a != 3);

  bar.a = 1;
  ASSERT(bar.a);
  ASSERT(bar.a && true);
  ASSERT(bar.a || true);

  bar.a = 0;
  ASSERT(!bar.a);
  ASSERT(!(bar.a && true));
  ASSERT(bar.a || true);

  bar.a = 0x00FF;
  ASSERT((bar.a | 0xFF00) == 0xFFFF);
  ASSERT((bar.a & 0xFF00) == 0x0000);
  ASSERT((bar.a ^ 0xFF00) == 0xFFFF);
  ASSERT((bar.a << 8) == 0xFF00);
  ASSERT(bar.a ? true : false);

  bar.a = 0xFF00;
  ASSERT((bar.a >> 8) == 0x00FF);

  bar.a = ~bar.a;
  ASSERT(bar.a == 0x00FF);
}

#endif  // TEST_TEST_COMMON_H_
