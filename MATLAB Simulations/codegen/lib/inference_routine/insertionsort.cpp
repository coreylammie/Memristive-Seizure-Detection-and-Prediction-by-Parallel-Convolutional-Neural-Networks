//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// insertionsort.cpp
//
// Code generation for function 'insertionsort'
//

// Include files
#include "insertionsort.h"
#include "anonymous_function.h"

// Function Definitions
namespace coder {
namespace internal {
void insertionsort(int x[32512], int xstart, int xend,
                   const b_anonymous_function *cmp)
{
  int i;
  i = xstart + 1;
  for (int k{i}; k <= xend; k++) {
    int idx;
    int xc;
    boolean_T exitg1;
    xc = x[k - 1] - 1;
    idx = k - 2;
    exitg1 = false;
    while ((!exitg1) && (idx + 1 >= xstart)) {
      boolean_T varargout_1;
      if (cmp->workspace.a[xc] < cmp->workspace.a[x[idx] - 1]) {
        varargout_1 = true;
      } else if (cmp->workspace.a[xc] == cmp->workspace.a[x[idx] - 1]) {
        varargout_1 = (cmp->workspace.b[xc] < cmp->workspace.b[x[idx] - 1]);
      } else {
        varargout_1 = false;
      }
      if (varargout_1) {
        x[idx + 1] = x[idx];
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x[idx + 1] = xc + 1;
  }
}

void insertionsort(int x[128], int xstart, int xend,
                   const anonymous_function *cmp)
{
  int i;
  i = xstart + 1;
  for (int k{i}; k <= xend; k++) {
    int idx;
    int xc;
    xc = x[k - 1];
    idx = k - 1;
    while ((idx >= xstart) &&
           (cmp->workspace.b[xc - 1] < cmp->workspace.b[x[idx - 1] - 1])) {
      x[idx] = x[idx - 1];
      idx--;
    }
    x[idx] = xc;
  }
}

} // namespace internal
} // namespace coder

// End of code generation (insertionsort.cpp)
