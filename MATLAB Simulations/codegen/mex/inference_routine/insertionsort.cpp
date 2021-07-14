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
#include "eml_int_forloop_overflow_check.h"
#include "inference_routine_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo hb_emlrtRSI{
    18,              // lineNo
    "insertionsort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\insertionsort.m" // pathName
};

// Function Definitions
namespace coder {
namespace internal {
void insertionsort(const emlrtStack *sp, int32_T x[128], int32_T xstart,
                   int32_T xend, const b_anonymous_function *cmp)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  a = xstart + 1;
  st.site = &hb_emlrtRSI;
  if ((xstart + 1 <= xend) && (xend > 2147483646)) {
    b_st.site = &ib_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T k{a}; k <= xend; k++) {
    int32_T idx;
    int32_T xc;
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

void insertionsort(const emlrtStack *sp, int32_T x[32512], int32_T xstart,
                   int32_T xend, const anonymous_function *cmp)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  a = xstart + 1;
  st.site = &hb_emlrtRSI;
  if ((xstart + 1 <= xend) && (xend > 2147483646)) {
    b_st.site = &ib_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T k{a}; k <= xend; k++) {
    int32_T idx;
    int32_T xc;
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

} // namespace internal
} // namespace coder

// End of code generation (insertionsort.cpp)
