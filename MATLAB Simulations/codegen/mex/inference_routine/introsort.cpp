//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// introsort.cpp
//
// Code generation for function 'introsort'
//

// Include files
#include "introsort.h"
#include "anonymous_function.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "rt_nonfinite.h"
#include "stack1.h"

// Variable Definitions
static emlrtRSInfo db_emlrtRSI{
    47,          // lineNo
    "introsort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" // pathName
};

static emlrtRSInfo eb_emlrtRSI{
    49,          // lineNo
    "introsort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" // pathName
};

static emlrtRSInfo fb_emlrtRSI{
    55,          // lineNo
    "introsort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" // pathName
};

static emlrtRSInfo gb_emlrtRSI{
    58,          // lineNo
    "introsort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" // pathName
};

static emlrtRTEInfo n_emlrtRTEI{
    62,           // lineNo
    39,           // colNo
    "stack/push", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\stack.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
void introsort(const emlrtStack *sp, int32_T x[128],
               const b_anonymous_function *cmp)
{
  static const b_struct_T t4_d[24]{{
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   },
                                   {
                                       1,   // xstart
                                       128, // xend
                                       0    // depth
                                   }};
  b_stack st;
  emlrtStack b_st;
  int32_T j;
  b_st.prev = sp;
  b_st.tls = sp->tls;
  st.init(t4_d, 0);
  st.d[0].xstart = 1;
  st.d[0].xend = 128;
  st.d[0].depth = 0;
  st.n = 1;
  while (st.n > 0) {
    b_struct_T expl_temp;
    int32_T expl_temp_tmp_tmp;
    int32_T s_depth;
    int32_T t;
    expl_temp_tmp_tmp = st.n - 1;
    expl_temp = st.d[st.n - 1];
    s_depth = st.d[st.n - 1].depth;
    st.n--;
    t = expl_temp.xend - expl_temp.xstart;
    if (t + 1 <= 32) {
      b_st.site = &db_emlrtRSI;
      insertionsort(&b_st, x, expl_temp.xstart, expl_temp.xend, cmp);
    } else if (expl_temp.depth == 12) {
      b_st.site = &eb_emlrtRSI;
      b_heapsort(&b_st, x, expl_temp.xstart, expl_temp.xend, cmp);
    } else {
      int32_T pivot;
      int32_T xmid;
      xmid = (expl_temp.xstart + t / 2) - 1;
      t = x[expl_temp.xstart - 1];
      if (cmp->workspace.b[x[xmid] - 1] < cmp->workspace.b[t - 1]) {
        x[expl_temp.xstart - 1] = x[xmid];
        x[xmid] = t;
      }
      if (cmp->workspace.b[x[expl_temp.xend - 1] - 1] <
          cmp->workspace.b[x[expl_temp.xstart - 1] - 1]) {
        t = x[expl_temp.xstart - 1];
        x[expl_temp.xstart - 1] = x[expl_temp.xend - 1];
        x[expl_temp.xend - 1] = t;
      }
      if (cmp->workspace.b[x[expl_temp.xend - 1] - 1] <
          cmp->workspace.b[x[xmid] - 1]) {
        t = x[xmid];
        x[xmid] = x[expl_temp.xend - 1];
        x[expl_temp.xend - 1] = t;
      }
      pivot = x[xmid];
      x[xmid] = x[expl_temp.xend - 2];
      x[expl_temp.xend - 2] = pivot;
      xmid = expl_temp.xstart - 1;
      j = expl_temp.xend - 2;
      int32_T exitg1;
      do {
        exitg1 = 0;
        xmid++;
        int32_T exitg2;
        do {
          exitg2 = 0;
          t = cmp->workspace.b[pivot - 1];
          if (cmp->workspace.b[x[xmid] - 1] < t) {
            xmid++;
          } else {
            exitg2 = 1;
          }
        } while (exitg2 == 0);
        for (j--; t < cmp->workspace.b[x[j] - 1]; j--) {
        }
        if (xmid + 1 >= j + 1) {
          exitg1 = 1;
        } else {
          t = x[xmid];
          x[xmid] = x[j];
          x[j] = t;
        }
      } while (exitg1 == 0);
      x[expl_temp.xend - 2] = x[xmid];
      x[xmid] = pivot;
      if (xmid + 2 < expl_temp.xend) {
        b_st.site = &fb_emlrtRSI;
        if (expl_temp_tmp_tmp >= 24) {
          emlrtErrorWithMessageIdR2018a(&b_st, &n_emlrtRTEI,
                                        "Coder:toolbox:StackPushLimit",
                                        "Coder:toolbox:StackPushLimit", 0);
        }
        st.d[expl_temp_tmp_tmp].xstart = xmid + 2;
        st.d[expl_temp_tmp_tmp].xend = expl_temp.xend;
        st.d[expl_temp_tmp_tmp].depth = s_depth + 1;
        st.n = expl_temp_tmp_tmp + 1;
      }
      if (expl_temp.xstart < xmid + 1) {
        b_st.site = &gb_emlrtRSI;
        if (st.n >= 24) {
          emlrtErrorWithMessageIdR2018a(&b_st, &n_emlrtRTEI,
                                        "Coder:toolbox:StackPushLimit",
                                        "Coder:toolbox:StackPushLimit", 0);
        }
        st.d[st.n].xstart = expl_temp.xstart;
        st.d[st.n].xend = xmid + 1;
        st.d[st.n].depth = s_depth + 1;
        st.n++;
      }
    }
  }
}

void introsort(const emlrtStack *sp, int32_T x[32512],
               const anonymous_function *cmp)
{
  static const b_struct_T t9_d[56]{{
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   },
                                   {
                                       1,     // xstart
                                       32512, // xend
                                       0      // depth
                                   }};
  stack st;
  emlrtStack b_st;
  b_st.prev = sp;
  b_st.tls = sp->tls;
  st.init(t9_d, 0);
  st.d[0].xstart = 1;
  st.d[0].xend = 32512;
  st.d[0].depth = 0;
  st.n = 1;
  while (st.n > 0) {
    b_struct_T expl_temp;
    int32_T expl_temp_tmp_tmp;
    int32_T i;
    int32_T s_depth;
    expl_temp_tmp_tmp = st.n - 1;
    expl_temp = st.d[st.n - 1];
    s_depth = st.d[st.n - 1].depth;
    st.n--;
    i = expl_temp.xend - expl_temp.xstart;
    if (i + 1 <= 32) {
      b_st.site = &db_emlrtRSI;
      insertionsort(&b_st, x, expl_temp.xstart, expl_temp.xend, cmp);
    } else if (expl_temp.depth == 28) {
      b_st.site = &eb_emlrtRSI;
      b_heapsort(&b_st, x, expl_temp.xstart, expl_temp.xend, cmp);
    } else {
      int32_T b_i;
      int32_T pivot;
      int32_T t;
      int32_T xmid;
      boolean_T varargout_1;
      xmid = (expl_temp.xstart + i / 2) - 1;
      i = x[expl_temp.xstart - 1];
      t = cmp->workspace.a[x[xmid] - 1];
      b_i = cmp->workspace.a[i - 1];
      if (t < b_i) {
        varargout_1 = true;
      } else if (t == b_i) {
        varargout_1 = (cmp->workspace.b[x[xmid] - 1] < cmp->workspace.b[i - 1]);
      } else {
        varargout_1 = false;
      }
      if (varargout_1) {
        x[expl_temp.xstart - 1] = x[xmid];
        x[xmid] = i;
      }
      if (cmp->workspace.a[x[expl_temp.xend - 1] - 1] <
          cmp->workspace.a[x[expl_temp.xstart - 1] - 1]) {
        varargout_1 = true;
      } else {
        i = x[expl_temp.xend - 1] - 1;
        t = x[expl_temp.xstart - 1] - 1;
        if (cmp->workspace.a[i] == cmp->workspace.a[t]) {
          varargout_1 = (cmp->workspace.b[i] < cmp->workspace.b[t]);
        } else {
          varargout_1 = false;
        }
      }
      if (varargout_1) {
        t = x[expl_temp.xstart - 1];
        x[expl_temp.xstart - 1] = x[expl_temp.xend - 1];
        x[expl_temp.xend - 1] = t;
      }
      if (cmp->workspace.a[x[expl_temp.xend - 1] - 1] <
          cmp->workspace.a[x[xmid] - 1]) {
        varargout_1 = true;
      } else {
        i = x[expl_temp.xend - 1] - 1;
        if (cmp->workspace.a[i] == cmp->workspace.a[x[xmid] - 1]) {
          varargout_1 = (cmp->workspace.b[i] < cmp->workspace.b[x[xmid] - 1]);
        } else {
          varargout_1 = false;
        }
      }
      if (varargout_1) {
        t = x[xmid];
        x[xmid] = x[expl_temp.xend - 1];
        x[expl_temp.xend - 1] = t;
      }
      pivot = x[xmid] - 1;
      x[xmid] = x[expl_temp.xend - 2];
      x[expl_temp.xend - 2] = pivot + 1;
      b_i = expl_temp.xstart - 1;
      xmid = expl_temp.xend - 2;
      int32_T exitg1;
      do {
        int32_T exitg2;
        exitg1 = 0;
        b_i++;
        do {
          exitg2 = 0;
          i = cmp->workspace.a[x[b_i] - 1];
          if (i < cmp->workspace.a[pivot]) {
            varargout_1 = true;
          } else if (i == cmp->workspace.a[pivot]) {
            varargout_1 =
                (cmp->workspace.b[x[b_i] - 1] < cmp->workspace.b[pivot]);
          } else {
            varargout_1 = false;
          }
          if (varargout_1) {
            b_i++;
          } else {
            exitg2 = 1;
          }
        } while (exitg2 == 0);
        xmid--;
        do {
          exitg2 = 0;
          i = cmp->workspace.a[x[xmid] - 1];
          if (cmp->workspace.a[pivot] < i) {
            varargout_1 = true;
          } else if (cmp->workspace.a[pivot] == i) {
            varargout_1 =
                (cmp->workspace.b[pivot] < cmp->workspace.b[x[xmid] - 1]);
          } else {
            varargout_1 = false;
          }
          if (varargout_1) {
            xmid--;
          } else {
            exitg2 = 1;
          }
        } while (exitg2 == 0);
        if (b_i + 1 >= xmid + 1) {
          exitg1 = 1;
        } else {
          t = x[b_i];
          x[b_i] = x[xmid];
          x[xmid] = t;
        }
      } while (exitg1 == 0);
      x[expl_temp.xend - 2] = x[b_i];
      x[b_i] = pivot + 1;
      if (b_i + 2 < expl_temp.xend) {
        b_st.site = &fb_emlrtRSI;
        if (expl_temp_tmp_tmp >= 56) {
          emlrtErrorWithMessageIdR2018a(&b_st, &n_emlrtRTEI,
                                        "Coder:toolbox:StackPushLimit",
                                        "Coder:toolbox:StackPushLimit", 0);
        }
        st.d[expl_temp_tmp_tmp].xstart = b_i + 2;
        st.d[expl_temp_tmp_tmp].xend = expl_temp.xend;
        st.d[expl_temp_tmp_tmp].depth = s_depth + 1;
        st.n = expl_temp_tmp_tmp + 1;
      }
      if (expl_temp.xstart < b_i + 1) {
        b_st.site = &gb_emlrtRSI;
        if (st.n >= 56) {
          emlrtErrorWithMessageIdR2018a(&b_st, &n_emlrtRTEI,
                                        "Coder:toolbox:StackPushLimit",
                                        "Coder:toolbox:StackPushLimit", 0);
        }
        st.d[st.n].xstart = expl_temp.xstart;
        st.d[st.n].xend = b_i + 1;
        st.d[st.n].depth = s_depth + 1;
        st.n++;
      }
    }
  }
}

} // namespace internal
} // namespace coder

// End of code generation (introsort.cpp)
