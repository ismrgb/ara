// Copyright 2020 ETH Zurich and University of Bologna.
//
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Author: Matheus Cavalcante, ETH Zurich
//         Samuel Riedel, ETH Zurich
//         Matteo Perotti, ETH Zurich

#include <stdint.h>
#include <string.h>

#include "printf.h"
#include "runtime.h"

#ifdef IMATMUL
#include "benchmark/imatmul_bmark.c"
#include "kernel/imatmul.h"
#else

#ifdef FMATMUL
#include "benchmark/fmatmul_bmark.c"
#include "kernel/fmatmul.h"
#else

#ifdef ICONV2D
#include "benchmark/iconv2d_bmark.c"
#include "conv2d.h"
#else

#ifdef FCONV2D
#include "benchmark/fconv2d_bmark.c"
#include "conv2d.h"
#endif