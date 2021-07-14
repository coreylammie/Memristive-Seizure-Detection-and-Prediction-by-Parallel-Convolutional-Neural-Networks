//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// stack1.cpp
//
// Code generation for function 'stack1'
//

// Include files
#include "stack1.h"
#include <algorithm>

// Function Definitions
namespace coder {
namespace internal {
void stack::init(const b_struct_T t5_d[56], int t5_n)
{
  std::copy(&t5_d[0], &t5_d[56], &this->d[0]);
  this->n = t5_n;
}

void b_stack::init(const b_struct_T t0_d[24], int t0_n)
{
  std::copy(&t0_d[0], &t0_d[24], &this->d[0]);
  this->n = t0_n;
}

} // namespace internal
} // namespace coder

// End of code generation (stack1.cpp)
