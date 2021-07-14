//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sparse.h
//
// Code generation for function 'sparse'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
struct inference_routineStackData;

namespace coder {
class sparse;

class b_sparse;

} // namespace coder

// Function Declarations
namespace coder {
void c_sparse(const emlrtStack *sp, const real_T varargin_1[128],
              const real_T varargin_2[128], const real_T varargin_3[128],
              b_sparse *y);

void c_sparse(inference_routineStackData *SD, const emlrtStack *sp,
              const real_T varargin_1[32512], const real_T varargin_2[32512],
              const real_T varargin_3[32512], sparse *y);

} // namespace coder

// End of code generation (sparse.h)
