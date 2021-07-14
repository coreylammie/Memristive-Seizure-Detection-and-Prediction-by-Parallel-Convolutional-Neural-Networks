//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sparse1.h
//
// Code generation for function 'sparse1'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
namespace coder {
class b_sparse;

}
struct inference_routineStackData;

// Type Definitions
namespace coder {
class sparse {
public:
  void mldivide(const emlrtStack *sp, const b_sparse *b, b_sparse *y) const;
  static void locSortrows(inference_routineStackData *SD, const emlrtStack *sp,
                          int32_T idx[32512], int32_T a[32512],
                          int32_T b[32512]);
  array<real_T, 1U> d;
  array<int32_T, 1U> colidx;
  array<int32_T, 1U> rowidx;
};

class b_sparse {
public:
  void parenReference(const emlrtStack *sp, b_sparse *s) const;
  void full(const emlrtStack *sp, real_T y[8192]) const;
  void fillIn(const emlrtStack *sp);
  void parenAssign(const emlrtStack *sp, const real_T rhs[8192]);
  array<real_T, 1U> d;
  array<int32_T, 1U> colidx;
  array<int32_T, 1U> rowidx;
  int32_T maxnz;
};

} // namespace coder

// End of code generation (sparse1.h)
