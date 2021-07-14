//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inference_routine.h
//
// Code generation for function 'inference_routine'
//

#pragma once

// Include files
#include "inference_routine_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void inference_routine(inference_routineStackData *SD, const emlrtStack *sp,
                       const real_T tile_1[4096], const real_T tile_2[4096],
                       const real_T max_weight[8], real_T n_kernels,
                       const real_T kernel_sizes[2], const real_T dense1a[4096],
                       const real_T dense1b[4096], const real_T dense1c[4096],
                       const real_T dense1d[4096], const real_T dense1e[4096],
                       const real_T dense1b_diff[16], const real_T dense2b[2],
                       const real_T test_data[163840],
                       const real_T test_labels[2560], real_T n_samples,
                       coder::array<real_T, 2U> &out);

// End of code generation (inference_routine.h)
