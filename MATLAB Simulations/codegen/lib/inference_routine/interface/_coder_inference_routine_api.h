//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_inference_routine_api.h
//
// Code generation for function 'inference_routine'
//

#ifndef _CODER_INFERENCE_ROUTINE_API_H
#define _CODER_INFERENCE_ROUTINE_API_H

// Include files
#include "coder_array_mex.h"
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void inference_routine(real_T tile_1[4096], real_T tile_2[4096],
                       real_T max_weight[8], real_T n_kernels,
                       real_T kernel_sizes[2], real_T dense1a[4096],
                       real_T dense1b[4096], real_T dense1c[4096],
                       real_T dense1d[4096], real_T dense1e[4096],
                       real_T dense1b_diff[16], real_T dense2b[2],
                       real_T test_data[163840], real_T test_labels[2560],
                       real_T n_samples, coder::array<real_T, 2U> *out);

void inference_routine_api(const mxArray *const prhs[15], const mxArray **plhs);

void inference_routine_atexit();

void inference_routine_initialize();

void inference_routine_terminate();

void inference_routine_xil_shutdown();

void inference_routine_xil_terminate();

#endif
// End of code generation (_coder_inference_routine_api.h)
