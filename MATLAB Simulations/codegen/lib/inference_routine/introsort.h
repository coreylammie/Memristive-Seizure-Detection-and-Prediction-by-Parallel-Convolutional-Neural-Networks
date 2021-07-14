//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// introsort.h
//
// Code generation for function 'introsort'
//

#ifndef INTROSORT_H
#define INTROSORT_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class b_anonymous_function;

class anonymous_function;

} // namespace coder

// Function Declarations
namespace coder {
namespace internal {
void introsort(int x[32512], const b_anonymous_function *cmp);

void introsort(int x[128], const anonymous_function *cmp);

} // namespace internal
} // namespace coder

#endif
// End of code generation (introsort.h)
