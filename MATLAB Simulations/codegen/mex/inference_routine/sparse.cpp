//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sparse.cpp
//
// Code generation for function 'sparse'
//

// Include files
#include "sparse.h"
#include "anonymous_function.h"
#include "inference_routine_data.h"
#include "inference_routine_types.h"
#include "introsort.h"
#include "rt_nonfinite.h"
#include "sparse1.h"
#include "coder_array.h"
#include <algorithm>

// Variable Definitions
static emlrtRSInfo v_emlrtRSI{
    13,       // lineNo
    "sparse", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" // pathName
};

static emlrtRSInfo w_emlrtRSI{
    119,             // lineNo
    "sparse/sparse", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo x_emlrtRSI{
    120,             // lineNo
    "sparse/sparse", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    138,             // lineNo
    "sparse/sparse", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRTEInfo f_emlrtRTEI{
    1618,                  // lineNo
    31,                    // colNo
    "assertValidIndexArg", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo g_emlrtRTEI{
    1620,                  // lineNo
    31,                    // colNo
    "assertValidIndexArg", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo h_emlrtRTEI{
    153,             // lineNo
    43,              // colNo
    "sparse/sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo i_emlrtRTEI{
    148,             // lineNo
    43,              // colNo
    "sparse/sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo v_emlrtRTEI{
    13,       // lineNo
    1,        // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" // pName
};

// Function Definitions
namespace coder {
void c_sparse(const emlrtStack *sp, const real_T varargin_1[128],
              const real_T varargin_2[128], const real_T varargin_3[128],
              b_sparse *y)
{
  b_anonymous_function b_this;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T d;
  int32_T sortedIndices[128];
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &v_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &w_emlrtRSI;
  for (k = 0; k < 128; k++) {
    d = varargin_1[k];
    if (!(d == d)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
                                    "MATLAB:sparsfcn:nonIntegerIndex",
                                    "MATLAB:sparsfcn:nonIntegerIndex", 0);
    }
    b_this.workspace.b[k] = static_cast<int32_T>(d);
  }
  b_st.site = &x_emlrtRSI;
  for (k = 0; k < 128; k++) {
    d = varargin_2[k];
    if (!(d == d)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
                                    "MATLAB:sparsfcn:nonIntegerIndex",
                                    "MATLAB:sparsfcn:nonIntegerIndex", 0);
    }
    b_this.workspace.a[k] = static_cast<int32_T>(d);
  }
  for (k = 0; k < 128; k++) {
    sortedIndices[k] = k + 1;
  }
  b_st.site = &y_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  internal::introsort(&c_st, sortedIndices, &b_this);
  std::copy(&b_this.workspace.b[0], &b_this.workspace.b[128],
            &b_this.workspace.a[0]);
  for (k = 0; k < 128; k++) {
    b_this.workspace.b[k] = b_this.workspace.a[sortedIndices[k] - 1];
  }
  y->d.set_size(&v_emlrtRTEI, &st, 128);
  y->maxnz = 128;
  y->colidx.set_size(&w_emlrtRTEI, &st, 2);
  y->colidx[0] = 1;
  y->rowidx.set_size(&v_emlrtRTEI, &st, 128);
  for (k = 0; k < 128; k++) {
    y->d[k] = 0.0;
    y->rowidx[k] = 0;
    y->rowidx[k] = b_this.workspace.b[k];
    y->d[k] = varargin_3[sortedIndices[k] - 1];
  }
  y->colidx[1] = k + 1;
  b_st.site = &ab_emlrtRSI;
  y->fillIn(&b_st);
}

void c_sparse(inference_routineStackData *SD, const emlrtStack *sp,
              const real_T varargin_1[32512], const real_T varargin_2[32512],
              const real_T varargin_3[32512], sparse *y)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T val;
  int32_T c;
  int32_T i;
  int32_T maxr;
  int32_T ridx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &v_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &w_emlrtRSI;
  for (ridx = 0; ridx < 32512; ridx++) {
    val = varargin_1[ridx];
    if (!(val == val)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
                                    "MATLAB:sparsfcn:nonIntegerIndex",
                                    "MATLAB:sparsfcn:nonIntegerIndex", 0);
    }
    if (!(val < 2.147483647E+9)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &g_emlrtRTEI,
                                    "MATLAB:sparsfcn:largeIndex",
                                    "MATLAB:sparsfcn:largeIndex", 0);
    }
    SD->f1.ridxInt[ridx] = static_cast<int32_T>(val);
  }
  b_st.site = &x_emlrtRSI;
  for (ridx = 0; ridx < 32512; ridx++) {
    val = varargin_2[ridx];
    if (!(val == val)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
                                    "MATLAB:sparsfcn:nonIntegerIndex",
                                    "MATLAB:sparsfcn:nonIntegerIndex", 0);
    }
    if (!(val < 2.147483647E+9)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &g_emlrtRTEI,
                                    "MATLAB:sparsfcn:largeIndex",
                                    "MATLAB:sparsfcn:largeIndex", 0);
    }
    SD->f1.cidxInt[ridx] = static_cast<int32_T>(val);
  }
  for (ridx = 0; ridx < 32512; ridx++) {
    SD->f1.sortedIndices[ridx] = ridx + 1;
  }
  b_st.site = &y_emlrtRSI;
  sparse::locSortrows(SD, &b_st, SD->f1.sortedIndices, SD->f1.cidxInt,
                      SD->f1.ridxInt);
  maxr = SD->f1.ridxInt[0];
  for (ridx = 0; ridx < 32511; ridx++) {
    i = SD->f1.ridxInt[ridx + 1];
    if (maxr < i) {
      maxr = i;
    }
  }
  if (maxr > 8192) {
    emlrtErrorWithMessageIdR2018a(
        &st, &i_emlrtRTEI, "Coder:builtins:IndexOutOfBounds",
        "Coder:builtins:IndexOutOfBounds", 6, 12, maxr, 12, 1, 12, 8192);
  }
  if (SD->f1.cidxInt[32511] > 8192) {
    emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI,
                                  "Coder:builtins:IndexOutOfBounds",
                                  "Coder:builtins:IndexOutOfBounds", 6, 12,
                                  SD->f1.cidxInt[32511], 12, 1, 12, 8192);
  }
  y->d.set_size(&v_emlrtRTEI, &st, 32512);
  y->colidx.set_size(&w_emlrtRTEI, &st, 8193);
  y->colidx[0] = 1;
  y->rowidx.set_size(&v_emlrtRTEI, &st, 32512);
  for (i = 0; i < 32512; i++) {
    y->d[i] = 0.0;
    y->rowidx[i] = 0;
  }
  maxr = 0;
  for (c = 0; c < 8192; c++) {
    while ((maxr + 1 <= 32512) && (SD->f1.cidxInt[maxr] == c + 1)) {
      y->rowidx[maxr] = SD->f1.ridxInt[maxr];
      maxr++;
    }
    y->colidx[c + 1] = maxr + 1;
  }
  for (ridx = 0; ridx < 32512; ridx++) {
    y->d[ridx] = varargin_3[SD->f1.sortedIndices[ridx] - 1];
  }
  maxr = 1;
  for (c = 0; c < 8192; c++) {
    ridx = y->colidx[c];
    y->colidx[c] = maxr;
    int32_T exitg1;
    do {
      exitg1 = 0;
      i = y->colidx[c + 1];
      if (ridx < i) {
        int32_T currRowIdx;
        val = 0.0;
        currRowIdx = y->rowidx[ridx - 1];
        while ((ridx < i) && (y->rowidx[ridx - 1] == currRowIdx)) {
          val += y->d[ridx - 1];
          ridx++;
        }
        if (val != 0.0) {
          y->d[maxr - 1] = val;
          y->rowidx[maxr - 1] = currRowIdx;
          maxr++;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  y->colidx[8192] = maxr;
}

} // namespace coder

// End of code generation (sparse.cpp)
