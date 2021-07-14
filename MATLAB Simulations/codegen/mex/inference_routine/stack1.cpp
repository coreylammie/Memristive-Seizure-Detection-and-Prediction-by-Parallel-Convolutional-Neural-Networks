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
#include "rt_nonfinite.h"
#include <algorithm>

// Function Definitions
namespace coder {
namespace internal {
void b_stack::init(const b_struct_T t1_d[24], int32_T t1_n)
{
  std::copy(&t1_d[0], &t1_d[24], &this->d[0]);
  this->n = t1_n;
}

void stack::init(const b_struct_T t6_d[56], int32_T t6_n)
{
  std::copy(&t6_d[0], &t6_d[56], &this->d[0]);
  this->n = t6_n;
}

} // namespace internal
} // namespace coder

// End of code generation (stack1.cpp)
