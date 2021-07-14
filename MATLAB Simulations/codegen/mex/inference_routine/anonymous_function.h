//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// anonymous_function.h
//
// Code generation for function 'anonymous_function'
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
struct struct_T {
  int32_T a[32512];
  int32_T b[32512];
};

struct c_struct_T {
  int32_T a[128];
  int32_T b[128];
};

namespace coder {
class anonymous_function {
public:
  struct_T workspace;
};

class b_anonymous_function {
public:
  c_struct_T workspace;
};

} // namespace coder

// End of code generation (anonymous_function.h)
