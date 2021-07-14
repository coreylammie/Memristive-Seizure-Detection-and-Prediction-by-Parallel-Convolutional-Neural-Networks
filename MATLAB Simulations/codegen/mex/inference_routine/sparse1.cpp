//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sparse1.cpp
//
// Code generation for function 'sparse1'
//

// Include files
#include "sparse1.h"
#include "anonymous_function.h"
#include "eml_int_forloop_overflow_check.h"
#include "inference_routine_data.h"
#include "inference_routine_types.h"
#include "introsort.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "coder_array.h"
#include "cs.h"
#include "makeCXSparseMatrix.h"
#include "solve_from_lu.h"
#include "solve_from_qr.h"
#include <algorithm>
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo kb_emlrtRSI{
    14,              // lineNo
    "sparse/fillIn", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\fillIn.m" // pathName
};

static emlrtRSInfo lb_emlrtRSI{
    1433,              // lineNo
    "sparse/mldivide", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo
    mb_emlrtRSI{
        158,                         // lineNo
        "CXSparseAPI/iteratedSolve", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" // pathName
    };

static emlrtRSInfo
    nb_emlrtRSI{
        289,                      // lineNo
        "CXSparseAPI/iteratedLU", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" // pathName
    };

static emlrtRSInfo
    ob_emlrtRSI{
        309,                      // lineNo
        "CXSparseAPI/iteratedLU", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" // pathName
    };

static emlrtRSInfo
    pb_emlrtRSI{
        312,                      // lineNo
        "CXSparseAPI/iteratedLU", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" // pathName
    };

static emlrtRSInfo
    qb_emlrtRSI{
        324,                      // lineNo
        "CXSparseAPI/iteratedLU", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" // pathName
    };

static emlrtRSInfo
    rb_emlrtRSI{
        331,                      // lineNo
        "CXSparseAPI/iteratedLU", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" // pathName
    };

static emlrtRSInfo
    sb_emlrtRSI{
        336,                      // lineNo
        "CXSparseAPI/iteratedLU", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" // pathName
    };

static emlrtRSInfo
    tb_emlrtRSI{
        455,                  // lineNo
        "CXSparseAPI/makeCX", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" // pathName
    };

static emlrtRSInfo
    ub_emlrtRSI{
        353,                      // lineNo
        "CXSparseAPI/iteratedQR", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" // pathName
    };

static emlrtRSInfo
    vb_emlrtRSI{
        382,                      // lineNo
        "CXSparseAPI/iteratedQR", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" // pathName
    };

static emlrtRSInfo
    wb_emlrtRSI{
        412,                      // lineNo
        "CXSparseAPI/iteratedQR", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" // pathName
    };

static emlrtRSInfo
    xb_emlrtRSI{
        419,                      // lineNo
        "CXSparseAPI/iteratedQR", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" // pathName
    };

static emlrtRSInfo ec_emlrtRSI{
    1459,                 // lineNo
    "sparse/spallocLike", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo fc_emlrtRSI{
    250,                     // lineNo
    "sparse/parenReference", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo gc_emlrtRSI{
    20,                        // lineNo
    "sparse/parenReference2D", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRSInfo hc_emlrtRSI{
    93,                        // lineNo
    "parenReference2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRSInfo ic_emlrtRSI{
    104,                       // lineNo
    "parenReference2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRSInfo jc_emlrtRSI{
    176,             // lineNo
    "sparse/sparse", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo lc_emlrtRSI{
    275,           // lineNo
    "sparse/full", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo mc_emlrtRSI{
    264,                  // lineNo
    "sparse/parenAssign", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo nc_emlrtRSI{
    56,                     // lineNo
    "sparse/parenAssign2D", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo oc_emlrtRSI{
    174,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo pc_emlrtRSI{
    184,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo qc_emlrtRSI{
    186,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo rc_emlrtRSI{
    198,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo sc_emlrtRSI{
    435,                  // lineNo
    "countNumnzInColumn", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo tc_emlrtRSI{
    337,       // lineNo
    "realloc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo uc_emlrtRSI{
    342,       // lineNo
    "realloc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo vc_emlrtRSI{
    245,                  // lineNo
    "shiftRowidxAndData", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo wc_emlrtRSI{
    246,                  // lineNo
    "shiftRowidxAndData", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRTEInfo k_emlrtRTEI{
    1589,              // lineNo
    9,                 // colNo
    "assertValidSize", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo l_emlrtRTEI{
    92,                        // lineNo
    1,                         // colNo
    "parenReference2DColumns", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pName
};

static emlrtRTEInfo x_emlrtRTEI{
    1433,     // lineNo
    13,       // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo y_emlrtRTEI{
    250,      // lineNo
    17,       // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo ab_emlrtRTEI{
    264,      // lineNo
    17,       // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

// Function Definitions
namespace coder {
void b_sparse::parenAssign(const emlrtStack *sp, const real_T rhs[8192])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T k;
  int32_T n;
  int32_T nz;
  int32_T nzColAlloc;
  int32_T nzRhs;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &nc_emlrtRSI;
  n = this->colidx[this->colidx.size(0) - 1] - 1;
  nz = this->colidx[this->colidx.size(0) - 1] - 1;
  nzColAlloc = this->colidx[1] - this->colidx[0];
  c_st.site = &oc_emlrtRSI;
  nzRhs = 0;
  d_st.site = &sc_emlrtRSI;
  for (k = 0; k < 8192; k++) {
    if (!(rhs[k] == 0.0)) {
      nzRhs++;
    }
  }
  if (nzColAlloc < nzRhs) {
    int32_T extraCol;
    int32_T start;
    extraCol = (nzRhs - nzColAlloc) - 1;
    start = this->colidx[1];
    if (2 - this->colidx[this->colidx.size(0) - 1] < extraCol + 1) {
      int32_T i;
      boolean_T overflow;
      nzColAlloc = extraCol + this->colidx[this->colidx.size(0) - 1];
      c_st.site = &pc_emlrtRSI;
      nzRhs = this->colidx[0];
      if (nzColAlloc > 8192) {
        nzColAlloc = 8192;
      }
      if (1 >= nzColAlloc) {
        nzColAlloc = 1;
      }
      this->rowidx.set_size(&ab_emlrtRTEI, &c_st, nzColAlloc);
      for (i = 0; i < nzColAlloc; i++) {
        this->rowidx[i] = 0;
      }
      this->d.set_size(&ab_emlrtRTEI, &c_st, nzColAlloc);
      for (i = 0; i < nzColAlloc; i++) {
        this->d[i] = 0.0;
      }
      this->maxnz = nzColAlloc;
      d_st.site = &tc_emlrtRSI;
      overflow =
          ((1 <= this->colidx[0] - 1) && (this->colidx[0] - 1 > 2147483646));
      if (overflow) {
        e_st.site = &ib_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      for (k = 0; k <= nzRhs - 2; k++) {
        this->rowidx[k] = 0;
        this->d[k] = 0.0;
      }
      d_st.site = &uc_emlrtRSI;
      overflow = ((this->colidx[1] <= n) && (n > 2147483646));
      if (overflow) {
        e_st.site = &ib_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      for (k = start; k <= nz; k++) {
        i = k + extraCol;
        this->rowidx[i] = 0;
        this->d[i] = 0.0;
      }
    } else {
      c_st.site = &qc_emlrtRSI;
      nzColAlloc = this->colidx[1] + extraCol;
      nzRhs = this->colidx[this->colidx.size(0) - 1] - this->colidx[1];
      if (nzRhs > 0) {
        d_st.site = &vc_emlrtRSI;
        std::memmove((void *)&this->rowidx[nzColAlloc],
                     (void *)&this->rowidx[start - 1],
                     (uint32_T)((size_t)nzRhs * sizeof(int32_T)));
        d_st.site = &wc_emlrtRSI;
        std::memmove((void *)&this->d[nzColAlloc], (void *)&this->d[start - 1],
                     (uint32_T)((size_t)nzRhs * sizeof(real_T)));
      }
    }
    nzColAlloc = this->colidx[0] - 1;
    for (k = 0; k < 8192; k++) {
      real_T b_d;
      b_d = rhs[k];
      if (b_d != 0.0) {
        this->rowidx[nzColAlloc] = k + 1;
        this->d[nzColAlloc] = b_d;
        nzColAlloc++;
      }
    }
    this->colidx[1] = (this->colidx[1] + extraCol) + 1;
  } else {
    nz = this->colidx[0] - 1;
    for (k = 0; k < 8192; k++) {
      real_T b_d;
      b_d = rhs[k];
      if (b_d != 0.0) {
        this->rowidx[nz] = k + 1;
        this->d[nz] = b_d;
        nz++;
      }
    }
    nzColAlloc -= nzRhs;
    if (nzColAlloc > 0) {
      int32_T start;
      start = this->colidx[1] - 1;
      c_st.site = &rc_emlrtRSI;
      nzRhs = (n - this->colidx[1]) + 1;
      if (nzRhs > 0) {
        d_st.site = &vc_emlrtRSI;
        std::memmove((void *)&this->rowidx[nz], (void *)&this->rowidx[start],
                     (uint32_T)((size_t)nzRhs * sizeof(int32_T)));
        d_st.site = &wc_emlrtRSI;
        std::memmove((void *)&this->d[nz], (void *)&this->d[start],
                     (uint32_T)((size_t)nzRhs * sizeof(real_T)));
      }
      this->colidx[1] = this->colidx[1] - nzColAlloc;
    }
  }
}

void b_sparse::parenReference(const emlrtStack *sp, b_sparse *s) const
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T i;
  int32_T nd_tmp;
  int32_T numalloc;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &gc_emlrtRSI;
  nd_tmp = this->colidx[1] - this->colidx[0];
  if (nd_tmp > 8192) {
    emlrtErrorWithMessageIdR2018a(&b_st, &l_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  c_st.site = &hc_emlrtRSI;
  d_st.site = &ec_emlrtRSI;
  e_st.site = &jc_emlrtRSI;
  if (nd_tmp < 0) {
    emlrtErrorWithMessageIdR2018a(&e_st, &k_emlrtRTEI,
                                  "Coder:toolbox:SparseNegativeSize",
                                  "Coder:toolbox:SparseNegativeSize", 0);
  }
  if (nd_tmp >= 1) {
    numalloc = nd_tmp;
  } else {
    numalloc = 1;
  }
  s->d.set_size(&y_emlrtRTEI, &d_st, numalloc);
  for (i = 0; i < numalloc; i++) {
    s->d[i] = 0.0;
  }
  s->maxnz = numalloc;
  s->colidx.set_size(&w_emlrtRTEI, &d_st, 2);
  s->colidx[0] = 1;
  s->rowidx.set_size(&y_emlrtRTEI, &d_st, numalloc);
  for (i = 0; i < numalloc; i++) {
    s->rowidx[i] = 0;
  }
  s->colidx[1] = 1;
  e_st.site = &ab_emlrtRSI;
  s->fillIn(&e_st);
  if (nd_tmp != 0) {
    numalloc = this->colidx[0] - 2;
    c_st.site = &ic_emlrtRSI;
    for (int32_T k{0}; k < nd_tmp; k++) {
      i = (numalloc + k) + 1;
      s->d[k] = this->d[i];
      s->rowidx[k] = this->rowidx[i];
    }
    s->colidx[1] = s->colidx[0] + nd_tmp;
  }
}

void b_sparse::fillIn(const emlrtStack *sp)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  idx = 1;
  b = this->colidx.size(0);
  st.site = &kb_emlrtRSI;
  if ((1 <= this->colidx.size(0) - 1) &&
      (this->colidx.size(0) - 1 > 2147483646)) {
    b_st.site = &ib_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T c{0}; c <= b - 2; c++) {
    int32_T ridx;
    ridx = this->colidx[c];
    this->colidx[c] = idx;
    int32_T exitg1;
    int32_T i;
    do {
      exitg1 = 0;
      i = this->colidx[c + 1];
      if (ridx < i) {
        real_T val;
        int32_T currRowIdx;
        val = 0.0;
        currRowIdx = this->rowidx[ridx - 1];
        while ((ridx < i) && (this->rowidx[ridx - 1] == currRowIdx)) {
          val += this->d[ridx - 1];
          ridx++;
        }
        if (val != 0.0) {
          this->d[idx - 1] = val;
          this->rowidx[idx - 1] = currRowIdx;
          idx++;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  this->colidx[this->colidx.size(0) - 1] = idx;
}

void b_sparse::full(const emlrtStack *sp, real_T y[8192]) const
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a;
  int32_T cend;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  std::memset(&y[0], 0, 8192U * sizeof(real_T));
  cend = this->colidx[1] - 1;
  a = this->colidx[0];
  st.site = &lc_emlrtRSI;
  overflow = ((this->colidx[0] <= this->colidx[1] - 1) &&
              (this->colidx[1] - 1 > 2147483646));
  if (overflow) {
    b_st.site = &ib_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T idx{a}; idx <= cend; idx++) {
    y[this->rowidx[idx - 1] - 1] = this->d[idx - 1];
  }
}

void sparse::locSortrows(inference_routineStackData *SD, const emlrtStack *sp,
                         int32_T idx[32512], int32_T a[32512], int32_T b[32512])
{
  emlrtStack st;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  std::copy(&a[0], &a[32512], &SD->f0.b_this.workspace.a[0]);
  std::copy(&b[0], &b[32512], &SD->f0.b_this.workspace.b[0]);
  st.site = &bb_emlrtRSI;
  internal::introsort(&st, idx, &SD->f0.b_this);
  std::copy(&a[0], &a[32512], &SD->f0.t[0]);
  for (k = 0; k < 32512; k++) {
    a[k] = SD->f0.t[idx[k] - 1];
  }
  std::copy(&b[0], &b[32512], &SD->f0.t[0]);
  for (k = 0; k < 32512; k++) {
    b[k] = SD->f0.t[idx[k] - 1];
  }
}

void sparse::mldivide(const emlrtStack *sp, const b_sparse *b,
                      b_sparse *y) const
{
  cs_di *cxA;
  cs_din *N;
  cs_dis *S;
  b_sparse r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T tmp[8192];
  real_T tol;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &lb_emlrtRSI;
  b_st.site = &mb_emlrtRSI;
  c_st.site = &nb_emlrtRSI;
  d_st.site = &tb_emlrtRSI;
  cxA = makeCXSparseMatrix(
      this->colidx[this->colidx.size(0) - 1] - 1, 8192, 8192,
      &(((::coder::array<int32_T, 1U> *)&this->colidx)->data())[0],
      &(((::coder::array<int32_T, 1U> *)&this->rowidx)->data())[0],
      &(((::coder::array<real_T, 1U> *)&this->d)->data())[0]);
  S = cs_di_sqr(2, cxA, 0);
  N = cs_di_lu(cxA, S, 1);
  cs_di_spfree(cxA);
  if (N == NULL) {
    c_st.site = &ob_emlrtRSI;
    internal::warning(&c_st);
    cs_di_sfree(S);
    cs_di_nfree(N);
    c_st.site = &pb_emlrtRSI;
    d_st.site = &ub_emlrtRSI;
    e_st.site = &tb_emlrtRSI;
    cxA = makeCXSparseMatrix(
        this->colidx[this->colidx.size(0) - 1] - 1, 8192, 8192,
        &(((::coder::array<int32_T, 1U> *)&this->colidx)->data())[0],
        &(((::coder::array<int32_T, 1U> *)&this->rowidx)->data())[0],
        &(((::coder::array<real_T, 1U> *)&this->d)->data())[0]);
    S = cs_di_sqr(2, cxA, 1);
    N = cs_di_qr(cxA, S);
    cs_di_spfree(cxA);
    qr_rank_di(N, &tol);
    d_st.site = &vb_emlrtRSI;
    e_st.site = &ec_emlrtRSI;
    y->d.set_size(&x_emlrtRTEI, &e_st, 1);
    y->d[0] = 0.0;
    y->maxnz = 1;
    y->colidx.set_size(&w_emlrtRTEI, &e_st, 2);
    y->colidx[0] = 1;
    y->rowidx.set_size(&x_emlrtRTEI, &e_st, 1);
    y->rowidx[0] = 0;
    y->colidx[1] = 1;
    f_st.site = &ab_emlrtRSI;
    y->fillIn(&f_st);
    d_st.site = &wb_emlrtRSI;
    b->parenReference(&d_st, &r);
    d_st.site = &wb_emlrtRSI;
    r.full(&d_st, tmp);
    solve_from_qr_di(N, S, (double *)&tmp[0], 8192, 8192);
    d_st.site = &xb_emlrtRSI;
    y->parenAssign(&d_st, tmp);
    cs_di_sfree(S);
    cs_di_nfree(N);
  } else {
    c_st.site = &qb_emlrtRSI;
    d_st.site = &ec_emlrtRSI;
    y->d.set_size(&x_emlrtRTEI, &d_st, 1);
    y->d[0] = 0.0;
    y->maxnz = 1;
    y->colidx.set_size(&w_emlrtRTEI, &d_st, 2);
    y->colidx[0] = 1;
    y->rowidx.set_size(&x_emlrtRTEI, &d_st, 1);
    y->rowidx[0] = 0;
    y->colidx[1] = 1;
    e_st.site = &ab_emlrtRSI;
    y->fillIn(&e_st);
    c_st.site = &rb_emlrtRSI;
    b->parenReference(&c_st, &r);
    c_st.site = &rb_emlrtRSI;
    r.full(&c_st, tmp);
    solve_from_lu_di(N, S, (double *)&tmp[0], 8192);
    c_st.site = &sb_emlrtRSI;
    y->parenAssign(&c_st, tmp);
    cs_di_sfree(S);
    cs_di_nfree(N);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder

// End of code generation (sparse1.cpp)
