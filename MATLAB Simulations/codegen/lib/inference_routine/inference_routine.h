//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inference_routine.h
//
// Code generation for function 'inference_routine'
//

#ifndef INFERENCE_ROUTINE_H
#define INFERENCE_ROUTINE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void
inference_routine(const double tile_1[4096], const double tile_2[4096],
                  const double max_weight[8], double n_kernels,
                  const double kernel_sizes[2], const double dense1a[4096],
                  const double dense1b[4096], const double dense1c[4096],
                  const double dense1d[4096], const double dense1e[4096],
                  const double dense1b_diff[16], const double dense2b[2],
                  const double test_data[163840],
                  const double test_labels[2560], double n_samples,
                  coder::array<double, 2U> &out);

#endif
// End of code generation (inference_routine.h)
