//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// stack1.h
//
// Code generation for function 'stack1'
//

#ifndef STACK1_H
#define STACK1_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
struct b_struct_T {
  int xstart;
  int xend;
  int depth;
};

namespace coder {
namespace internal {
class stack {
public:
  void init(const b_struct_T t5_d[56], int t5_n);
  b_struct_T d[56];
  int n;
};

class b_stack {
public:
  void init(const b_struct_T t0_d[24], int t0_n);
  b_struct_T d[24];
  int n;
};

} // namespace internal
} // namespace coder

#endif
// End of code generation (stack1.h)
