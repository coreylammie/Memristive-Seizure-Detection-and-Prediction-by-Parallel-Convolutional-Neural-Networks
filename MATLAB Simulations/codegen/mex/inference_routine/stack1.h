//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// stack1.h
//
// Code generation for function 'stack1'
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

// Type Definitions
struct b_struct_T {
  int32_T xstart;
  int32_T xend;
  int32_T depth;
};

namespace coder {
namespace internal {
class stack {
public:
  void init(const b_struct_T t6_d[56], int32_T t6_n);
  b_struct_T d[56];
  int32_T n;
};

class b_stack {
public:
  void init(const b_struct_T t1_d[24], int32_T t1_n);
  b_struct_T d[24];
  int32_T n;
};

} // namespace internal
} // namespace coder

// End of code generation (stack1.h)
