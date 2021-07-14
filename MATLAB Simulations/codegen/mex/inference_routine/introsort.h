//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// introsort.h
//
// Code generation for function 'introsort'
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
namespace coder {
class anonymous_function;

class b_anonymous_function;

} // namespace coder

// Function Declarations
namespace coder {
namespace internal {
void introsort(const emlrtStack *sp, int32_T x[128],
               const b_anonymous_function *cmp);

void introsort(const emlrtStack *sp, int32_T x[32512],
               const anonymous_function *cmp);

} // namespace internal
} // namespace coder

// End of code generation (introsort.h)
