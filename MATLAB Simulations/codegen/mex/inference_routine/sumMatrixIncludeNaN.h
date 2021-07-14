//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sumMatrixIncludeNaN.h
//
// Code generation for function 'sumMatrixIncludeNaN'
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

// Function Declarations
namespace coder {
real_T sumColumnB(const real_T x[4096]);

real_T sumColumnB(const real_T x[4096], int32_T col);

real_T sumColumnB(const emlrtStack *sp, const real_T x_data[], int32_T vlen);

} // namespace coder

// End of code generation (sumMatrixIncludeNaN.h)
