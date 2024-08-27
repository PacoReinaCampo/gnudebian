///////////////////////////////////////////////////////////////////////////////////
//                                            __ _      _     _                  //
//                                           / _(_)    | |   | |                 //
//                __ _ _   _  ___  ___ _ __ | |_ _  ___| | __| |                 //
//               / _` | | | |/ _ \/ _ \ '_ \|  _| |/ _ \ |/ _` |                 //
//              | (_| | |_| |  __/  __/ | | | | | |  __/ | (_| |                 //
//               \__, |\__,_|\___|\___|_| |_|_| |_|\___|_|\__,_|                 //
//                  | |                                                          //
//                  |_|                                                          //
//                                                                               //
//                                                                               //
//              Peripheral-NTM for MPSoC                                         //
//              Neural Turing Machine for MPSoC                                  //
//                                                                               //
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
//                                                                               //
// Copyright (c) 2020-2024 by the author(s)                                      //
//                                                                               //
// Permission is hereby granted, free of charge, to any person obtaining a copy  //
// of this software and associated documentation files (the "Software"), to deal //
// in the Software without restriction, including without limitation the rights  //
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell     //
// copies of the Software, and to permit persons to whom the Software is         //
// furnished to do so, subject to the following conditions:                      //
//                                                                               //
// The above copyright notice and this permission notice shall be included in    //
// all copies or substantial portions of the Software.                           //
//                                                                               //
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR    //
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,      //
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE   //
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER        //
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, //
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN     //
// THE SOFTWARE.                                                                 //
//                                                                               //
// ============================================================================= //
// Author(s):                                                                    //
//   Paco Reina Campo <pacoreinacampo@queenfield.tech>                           //
//                                                                               //
///////////////////////////////////////////////////////////////////////////////////

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../../../library/nn/dnc/memory/dnc_addressing.h"
#include "../../../../library/nn/dnc/memory/dnc_allocation_weighting.h"
#include "../../../../library/nn/dnc/memory/dnc_backward_weighting.h"
#include "../../../../library/nn/dnc/memory/dnc_forward_weighting.h"
#include "../../../../library/nn/dnc/memory/dnc_matrix_content_based_addressing.h"
#include "../../../../library/nn/dnc/memory/dnc_memory_matrix.h"
#include "../../../../library/nn/dnc/memory/dnc_memory_retention_vector.h"
#include "../../../../library/nn/dnc/memory/dnc_precedence_weighting.h"
#include "../../../../library/nn/dnc/memory/dnc_sort_vector.h"
#include "../../../../library/nn/dnc/memory/dnc_temporal_link_matrix.h"
#include "../../../../library/nn/dnc/memory/dnc_usage_vector.h"
#include "../../../../library/nn/dnc/memory/dnc_vector_content_based_addressing.h"

int main() {
  srand(time(NULL));

  int random_integer = rand();
    
  double data_a_in = (double)random_integer / RAND_MAX;
  double data_b_in = (double)random_integer / RAND_MAX;

  double data_out;

  data_out = data_a_in + data_b_in;

  assert(dnc_addressing_adder(data_a_in, data_b_in) == data_out);

  data_out = data_a_in - data_b_in;

  assert(dnc_addressing_subtractor(data_a_in, data_b_in) == data_out);

  data_out = data_a_in * data_b_in;

  assert(dnc_addressing_multiplier(data_a_in, data_b_in) == data_out);

  data_out = data_a_in / data_b_in;

  assert(dnc_addressing_divider(data_a_in, data_b_in) == data_out);

  return 0;
}