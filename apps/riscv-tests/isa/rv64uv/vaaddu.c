// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matheus Cavalcante <matheusd@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>

#include "vector_macros.h"

void TEST_CASE1(void) {
  VSET(16, e8, m1);
  VLOAD_8(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_8(v2, 1, 3, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 6, 6, 7, 8);
  asm volatile("vaaddu.vv v3, v1, v2");
  VCMP_U8(1, v3, 1, 3, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 6, 6, 7, 8);

  VSET(16, e16, m1);
  VLOAD_16(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_16(v2, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  asm volatile("vaaddu.vv v3, v1, v2");
  VCMP_U16(2, v3, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);

  VSET(16, e32, m1);
  VLOAD_32(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_32(v2, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  asm volatile("vaaddu.vv v3, v1, v2");
  VCMP_U32(3, v3, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);

  VSET(16, e64, m1);
  VLOAD_64(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_64(v2, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  asm volatile("vaaddu.vv v3, v1, v2");
  VCMP_U64(4, v3, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
}

void TEST_CASE2(void) {
  VSET(16, e8, m1);
  VLOAD_8(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_8(v2, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v3);
  asm volatile("vaaddu.vv v3, v1, v2, v0.t");
  VCMP_U8(5, v3, 0, 2, 0, 4, 0, 6, 0, 8, 0, 2, 0, 4, 0, 6, 0, 8);

  VSET(16, e16, m1);
  VLOAD_16(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_16(v2, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v3);
  asm volatile("vaaddu.vv v3, v1, v2, v0.t");
  VCMP_U16(6, v3, 0, 2, 0, 4, 0, 6, 0, 8, 0, 2, 0, 4, 0, 6, 0, 8);

  VSET(16, e32, m1);
  VLOAD_32(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_32(v2, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v3);
  asm volatile("vaaddu.vv v3, v1, v2, v0.t");
  VCMP_U32(7, v3, 0, 2, 0, 4, 0, 6, 0, 8, 0, 2, 0, 4, 0, 6, 0, 8);

  VSET(16, e64, m1);
  VLOAD_64(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_64(v2, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v3);
  asm volatile("vaaddu.vv v3, v1, v2, v0.t");
  VCMP_U64(8, v3, 0, 2, 0, 4, 0, 6, 0, 8, 0, 2, 0, 4, 0, 6, 0, 8);
}

/*void TEST_CASE3(void) {
  VSET(16, e8, m1);
  VLOAD_8(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  asm volatile("vaaddu.vi v3, v1, 5");
  VCMP_U8(9, v3, 3, 4, 4, 5, 5, 6, 6, 7, 3, 4, 4, 5, 5, 6, 6, 7);

  VSET(16, e16, m1);
  VLOAD_16(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  asm volatile("vaaddu.vi v3, v1, 5");
  VCMP_U16(10, v3, 3, 4, 4, 5, 5, 6, 6, 7, 3, 4, 4, 5, 5, 6, 6, 7);

  VSET(16, e32, m1);
  VLOAD_32(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  asm volatile("vaaddu.vi v3, v1, 5");
  VCMP_U32(11, v3, 3, 4, 4, 5, 5, 6, 6, 7, 3, 4, 4, 5, 5, 6, 6, 7);

  VSET(16, e64, m1);
  VLOAD_64(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  asm volatile("vaaddu.vi v3, v1, 5");
  VCMP_U64(12, v3, 3, 4, 4, 5, 5, 6, 6, 7, 3, 4, 4, 5, 5, 6, 6, 7);
}

void TEST_CASE4(void) {
  VSET(16, e8, m1);
  VLOAD_8(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v3);
  asm volatile("vaaddu.vi v3, v1, 5, v0.t");
  VCMP_U8(13, v3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 4, 0, 5, 0, 6, 0, 7);

  VSET(16, e16, m1);
  VLOAD_16(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v3);
  asm volatile("vaaddu.vi v3, v1, 5, v0.t");
  VCMP_U16(14, v3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 4, 0, 5, 0, 6, 0, 7);

  VSET(16, e32, m1);
  VLOAD_32(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v3);
  asm volatile("vaaddu.vi v3, v1, 5, v0.t");
  VCMP_U32(15, v3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 4, 0, 5, 0, 6, 0, 7);

  VSET(16, e64, m1);
  VLOAD_64(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v3);
  asm volatile("vaaddu.vi v3, v1, 5, v0.t");
  VCMP_U64(16, v3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 4, 0, 5, 0, 6, 0, 7);
}*/

void TEST_CASE5(void) {
  const uint32_t scalar = 5;

  VSET(16, e8, m1);
  VLOAD_8(v1, 1, 254, 3, 252, 5, 250, 7, 248, 9, 246, 11, 244, 13, 242, 15, 240);
  asm volatile("vaaddu.vx v3, v1, %[A]" ::[A] "r"(scalar));
  VCMP_U8(17, v3, 3, 130, 4, 129, 5, 128, 6, 127, 7, 126, 8, 125, 9, 124, 10, 123);

  VSET(16, e16, m1);
  VLOAD_16(v1, 1, 254, 3, 252, 5, 250, 7, 248, 9, 246, 11, 244, 13, 242, 15, 240);
  asm volatile("vaaddu.vx v3, v1, %[A]" ::[A] "r"(scalar));
  VCMP_U16(18, v3, 3, 130, 4, 129, 5, 128, 6, 127, 7, 126, 8, 125, 9, 124, 10, 123);

  VSET(16, e32, m1);
  VLOAD_32(v1, 1, 254, 3, 252, 5, 250, 7, 248, 9, 246, 11, 244, 13, 242, 15, 240);
  asm volatile("vaaddu.vx v3, v1, %[A]" ::[A] "r"(scalar));
  VCMP_U32(19, v3, 3, 130, 4, 129, 5, 128, 6, 127, 7, 126, 8, 125, 9, 124, 10, 123);

  VSET(16, e64, m1);
  VLOAD_64(v1, 1, 254, 3, 252, 5, 250, 7, 248, 9, 246, 11, 244, 13, 242, 15, 240);
  asm volatile("vaaddu.vx v3, v1, %[A]" ::[A] "r"(scalar));
  VCMP_U64(20, v3, 3, 130, 4, 129, 5, 128, 6, 127, 7, 126, 8, 125, 9, 124, 10, 123);
}

void TEST_CASE6(void) {
  const uint32_t scalar = 5;

  VSET(16, e8, m1);
  VLOAD_8(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v3);
  asm volatile("vaaddu.vx v3, v1, %[A], v0.t" ::[A] "r"(scalar));
  VCMP_U8(21, v3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 4, 0, 5, 0, 6, 0, 7);

  VSET(16, e16, m1);
  VLOAD_16(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v3);
  asm volatile("vaaddu.vx v3, v1, %[A], v0.t" ::[A] "r"(scalar));
  VCMP_U16(22, v3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 4, 0, 5, 0, 6, 0, 7);

  VSET(16, e32, m1);
  VLOAD_32(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v3);
  asm volatile("vaaddu.vx v3, v1, %[A], v0.t" ::[A] "r"(scalar));
  VCMP_U32(23, v3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 4, 0, 5, 0, 6, 0, 7);

  VSET(16, e64, m1);
  VLOAD_64(v1, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v3);
  asm volatile("vaaddu.vx v3, v1, %[A], v0.t" ::[A] "r"(scalar));
  VCMP_U64(24, v3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 4, 0, 5, 0, 6, 0, 7);
}

int main(void) {
  INIT_CHECK();
  enable_vec();

  TEST_CASE1();
  TEST_CASE2();
  //TEST_CASE3();
  //TEST_CASE4();
  TEST_CASE5();
  TEST_CASE6();

  EXIT_CHECK();
}
