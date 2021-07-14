//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// heapsort.cpp
//
// Code generation for function 'heapsort'
//

// Include files
#include "heapsort.h"
#include "anonymous_function.h"
#include "eml_int_forloop_overflow_check.h"
#include "inference_routine_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo jb_emlrtRSI{
    20,         // lineNo
    "heapsort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\heapsort.m" // pathName
};

// Function Declarations
namespace coder {
namespace internal {
static void heapify(int32_T x[128], int32_T idx, int32_T xstart, int32_T xend,
                    const b_anonymous_function *cmp);

}
} // namespace coder

// Function Definitions
namespace coder {
namespace internal {
static void heapify(int32_T x[128], int32_T idx, int32_T xstart, int32_T xend,
                    const b_anonymous_function *cmp)
{
  int32_T cmpIdx;
  int32_T extremum;
  int32_T extremumIdx;
  int32_T leftIdx;
  boolean_T changed;
  boolean_T exitg1;
  changed = true;
  extremumIdx = (idx + xstart) - 2;
  leftIdx = ((idx << 1) + xstart) - 1;
  exitg1 = false;
  while ((!exitg1) && (leftIdx < xend)) {
    int32_T xcmp;
    changed = false;
    extremum = x[extremumIdx];
    cmpIdx = leftIdx - 1;
    xcmp = x[leftIdx - 1];
    if (cmp->workspace.b[xcmp - 1] < cmp->workspace.b[x[leftIdx] - 1]) {
      cmpIdx = leftIdx;
      xcmp = x[leftIdx];
    }
    if (cmp->workspace.b[x[extremumIdx] - 1] < cmp->workspace.b[xcmp - 1]) {
      x[extremumIdx] = xcmp;
      x[cmpIdx] = extremum;
      extremumIdx = cmpIdx;
      leftIdx = ((((cmpIdx - xstart) + 2) << 1) + xstart) - 1;
      changed = true;
    } else {
      exitg1 = true;
    }
  }
  if (changed && (leftIdx <= xend)) {
    extremum = x[extremumIdx];
    cmpIdx = x[leftIdx - 1];
    if (cmp->workspace.b[x[extremumIdx] - 1] < cmp->workspace.b[cmpIdx - 1]) {
      x[extremumIdx] = cmpIdx;
      x[leftIdx - 1] = extremum;
    }
  }
}

void b_heapsort(const emlrtStack *sp, int32_T x[128], int32_T xstart,
                int32_T xend, const b_anonymous_function *cmp)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  n = xend - xstart;
  for (idx = n + 1; idx >= 1; idx--) {
    heapify(x, idx, xstart, xend, cmp);
  }
  st.site = &jb_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    b_st.site = &ib_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T k{0}; k < n; k++) {
    int32_T t;
    idx = (xend - k) - 1;
    t = x[idx];
    x[idx] = x[xstart - 1];
    x[xstart - 1] = t;
    heapify(x, 1, xstart, (xend - k) - 1, cmp);
  }
}

void b_heapsort(const emlrtStack *sp, int32_T x[32512], int32_T xstart,
                int32_T xend, const anonymous_function *cmp)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T cmpIdx;
  int32_T extremum;
  int32_T extremumIdx;
  int32_T i;
  int32_T i1;
  int32_T idx;
  int32_T leftIdx;
  int32_T n;
  int32_T t;
  int32_T xcmp;
  boolean_T changed;
  boolean_T exitg1;
  boolean_T varargout_1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  n = xend - xstart;
  for (idx = n + 1; idx >= 1; idx--) {
    changed = true;
    extremumIdx = (idx + xstart) - 2;
    leftIdx = ((idx << 1) + xstart) - 2;
    exitg1 = false;
    while ((!exitg1) && (leftIdx + 1 < xend)) {
      changed = false;
      extremum = x[extremumIdx];
      cmpIdx = leftIdx;
      xcmp = x[leftIdx];
      i = x[leftIdx + 1] - 1;
      i1 = cmp->workspace.a[x[leftIdx] - 1];
      t = cmp->workspace.a[i];
      if (i1 < t) {
        varargout_1 = true;
      } else if (i1 == t) {
        varargout_1 = (cmp->workspace.b[x[leftIdx] - 1] < cmp->workspace.b[i]);
      } else {
        varargout_1 = false;
      }
      if (varargout_1) {
        cmpIdx = leftIdx + 1;
        xcmp = x[leftIdx + 1];
      }
      i = cmp->workspace.a[x[extremumIdx] - 1];
      i1 = cmp->workspace.a[xcmp - 1];
      if (i < i1) {
        varargout_1 = true;
      } else if (i == i1) {
        varargout_1 =
            (cmp->workspace.b[x[extremumIdx] - 1] < cmp->workspace.b[xcmp - 1]);
      } else {
        varargout_1 = false;
      }
      if (varargout_1) {
        x[extremumIdx] = xcmp;
        x[cmpIdx] = extremum;
        extremumIdx = cmpIdx;
        leftIdx = ((((cmpIdx - xstart) + 2) << 1) + xstart) - 2;
        changed = true;
      } else {
        exitg1 = true;
      }
    }
    if (changed && (leftIdx + 1 <= xend)) {
      extremum = x[extremumIdx];
      i = cmp->workspace.a[x[extremumIdx] - 1];
      i1 = cmp->workspace.a[x[leftIdx] - 1];
      if (i < i1) {
        varargout_1 = true;
      } else if (i == i1) {
        varargout_1 = (cmp->workspace.b[x[extremumIdx] - 1] <
                       cmp->workspace.b[x[leftIdx] - 1]);
      } else {
        varargout_1 = false;
      }
      if (varargout_1) {
        x[extremumIdx] = x[leftIdx];
        x[leftIdx] = extremum;
      }
    }
  }
  st.site = &jb_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    b_st.site = &ib_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T k{0}; k < n; k++) {
    idx = (xend - k) - 1;
    t = x[idx];
    x[idx] = x[xstart - 1];
    x[xstart - 1] = t;
    changed = true;
    extremumIdx = xstart - 1;
    leftIdx = xstart;
    exitg1 = false;
    while ((!exitg1) && (leftIdx + 1 < idx)) {
      changed = false;
      extremum = x[extremumIdx];
      cmpIdx = leftIdx;
      xcmp = x[leftIdx];
      i = x[leftIdx + 1];
      i1 = cmp->workspace.a[x[leftIdx] - 1];
      if (i1 < cmp->workspace.a[i - 1]) {
        varargout_1 = true;
      } else if (i1 == cmp->workspace.a[i - 1]) {
        varargout_1 =
            (cmp->workspace.b[x[leftIdx] - 1] < cmp->workspace.b[i - 1]);
      } else {
        varargout_1 = false;
      }
      if (varargout_1) {
        cmpIdx = leftIdx + 1;
        xcmp = i;
      }
      i = cmp->workspace.a[x[extremumIdx] - 1];
      i1 = cmp->workspace.a[xcmp - 1];
      if (i < i1) {
        varargout_1 = true;
      } else if (i == i1) {
        varargout_1 =
            (cmp->workspace.b[x[extremumIdx] - 1] < cmp->workspace.b[xcmp - 1]);
      } else {
        varargout_1 = false;
      }
      if (varargout_1) {
        x[extremumIdx] = xcmp;
        x[cmpIdx] = extremum;
        extremumIdx = cmpIdx;
        leftIdx = ((((cmpIdx - xstart) + 2) << 1) + xstart) - 2;
        changed = true;
      } else {
        exitg1 = true;
      }
    }
    if (changed && (leftIdx + 1 <= idx)) {
      extremum = x[extremumIdx];
      i = cmp->workspace.a[x[extremumIdx] - 1];
      i1 = cmp->workspace.a[x[leftIdx] - 1];
      if (i < i1) {
        varargout_1 = true;
      } else if (i == i1) {
        varargout_1 = (cmp->workspace.b[x[extremumIdx] - 1] <
                       cmp->workspace.b[x[leftIdx] - 1]);
      } else {
        varargout_1 = false;
      }
      if (varargout_1) {
        x[extremumIdx] = x[leftIdx];
        x[leftIdx] = extremum;
      }
    }
  }
}

} // namespace internal
} // namespace coder

// End of code generation (heapsort.cpp)
