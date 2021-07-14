//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rand.cpp
//
// Code generation for function 'rand'
//

// Include files
#include "rand.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder {
void b_rand(real_T r[8])
{
  emlrtRandu(&r[0], 8);
}

} // namespace coder

// End of code generation (rand.cpp)
