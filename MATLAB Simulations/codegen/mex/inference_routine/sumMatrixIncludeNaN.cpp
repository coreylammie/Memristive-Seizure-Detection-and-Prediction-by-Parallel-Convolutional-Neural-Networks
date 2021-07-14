//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sumMatrixIncludeNaN.cpp
//
// Code generation for function 'sumMatrixIncludeNaN'
//

// Include files
#include "sumMatrixIncludeNaN.h"
#include "eml_int_forloop_overflow_check.h"
#include "inference_routine_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo ed_emlrtRSI{
    178,          // lineNo
    "sumColumnB", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

static emlrtRSInfo fd_emlrtRSI{
    210,         // lineNo
    "sumColumn", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

static emlrtRSInfo gd_emlrtRSI{
    182,          // lineNo
    "sumColumnB", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

static emlrtRSInfo hd_emlrtRSI{
    184,          // lineNo
    "sumColumnB", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

static emlrtRSInfo ae_emlrtRSI{
    189,          // lineNo
    "sumColumnB", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

// Function Definitions
namespace coder {
real_T sumColumnB(const real_T x[4096])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 1023; k++) {
    y += x[k + 1];
  }
  for (k = 0; k < 3; k++) {
    real_T b_y;
    int32_T vstart;
    vstart = (k + 1) << 10;
    b_y = x[vstart];
    for (int32_T b_k{0}; b_k < 1023; b_k++) {
      b_y += x[(vstart + b_k) + 1];
    }
    y += b_y;
  }
  return y;
}

real_T sumColumnB(const real_T x[4096], int32_T col)
{
  real_T y;
  int32_T i0;
  i0 = (col - 1) << 6;
  y = x[i0];
  for (int32_T k{0}; k < 63; k++) {
    y += x[(i0 + k) + 1];
  }
  return y;
}

real_T sumColumnB(const emlrtStack *sp, const real_T x_data[], int32_T vlen)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T y;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (vlen <= 1024) {
    st.site = &ed_emlrtRSI;
    y = x_data[0];
    b_st.site = &fd_emlrtRSI;
    if ((1 <= vlen - 1) && (vlen - 1 > 2147483646)) {
      c_st.site = &ib_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (int32_T k{0}; k <= vlen - 2; k++) {
      y += x_data[k + 1];
    }
  } else {
    real_T b_y;
    int32_T inb;
    int32_T k;
    int32_T nfb;
    nfb = vlen / 1024;
    inb = nfb << 10;
    st.site = &gd_emlrtRSI;
    y = x_data[0];
    b_st.site = &fd_emlrtRSI;
    for (k = 0; k < 1023; k++) {
      y += x_data[k + 1];
    }
    for (k = 2; k <= nfb; k++) {
      int32_T vstart;
      st.site = &hd_emlrtRSI;
      vstart = (k - 1) << 10;
      b_y = x_data[vstart];
      b_st.site = &fd_emlrtRSI;
      for (int32_T b_k{0}; b_k < 1023; b_k++) {
        b_y += x_data[(vstart + b_k) + 1];
      }
      y += b_y;
    }
    if (vlen > inb) {
      nfb = vlen - inb;
      st.site = &ae_emlrtRSI;
      b_y = x_data[inb];
      b_st.site = &fd_emlrtRSI;
      if ((1 <= nfb - 1) && (nfb - 1 > 2147483646)) {
        c_st.site = &ib_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (k = 0; k <= nfb - 2; k++) {
        b_y += x_data[(inb + k) + 1];
      }
      y += b_y;
    }
  }
  return y;
}

} // namespace coder

// End of code generation (sumMatrixIncludeNaN.cpp)
