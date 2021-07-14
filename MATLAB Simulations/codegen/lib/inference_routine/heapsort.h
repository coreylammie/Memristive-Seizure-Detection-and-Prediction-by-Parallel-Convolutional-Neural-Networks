//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// heapsort.h
//
// Code generation for function 'heapsort'
//

#ifndef HEAPSORT_H
#define HEAPSORT_H

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
void b_heapsort(int x[32512], int xstart, int xend,
                const b_anonymous_function *cmp);

void b_heapsort(int x[128], int xstart, int xend,
                const anonymous_function *cmp);

} // namespace internal
} // namespace coder

#endif
// End of code generation (heapsort.h)
