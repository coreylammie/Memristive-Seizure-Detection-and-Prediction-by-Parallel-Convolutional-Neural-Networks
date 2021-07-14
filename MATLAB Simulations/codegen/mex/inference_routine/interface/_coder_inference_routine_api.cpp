//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_inference_routine_api.cpp
//
// Code generation for function '_coder_inference_routine_api'
//

// Include files
#include "_coder_inference_routine_api.h"
#include "inference_routine.h"
#include "inference_routine_data.h"
#include "inference_routine_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *max_weight,
                                   const char_T *identifier))[8];

static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[8];

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *n_kernels,
                                 const char_T *identifier);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *kernel_sizes,
                                   const char_T *identifier))[2];

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2];

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *dense1b_diff,
                                   const char_T *identifier))[16];

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[16];

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *tile_1,
                                 const char_T *identifier))[4096];

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId))[4096];

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *test_data,
                                   const char_T *identifier))[163840];

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[163840];

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *test_labels,
                                   const char_T *identifier))[2560];

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2560];

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4096];

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[8];

static real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2];

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[16];

static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[163840];

static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2560];

// Function Definitions
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *max_weight,
                                   const char_T *identifier))[8]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[8];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(max_weight), &thisId);
  emlrtDestroyArray(&max_weight);
  return y;
}

static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[8]
{
  real_T(*y)[8];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *n_kernels,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(sp, emlrtAlias(n_kernels), &thisId);
  emlrtDestroyArray(&n_kernels);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *kernel_sizes,
                                   const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(kernel_sizes), &thisId);
  emlrtDestroyArray(&kernel_sizes);
  return y;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2]
{
  real_T(*y)[2];
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *dense1b_diff,
                                   const char_T *identifier))[16]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[16];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = e_emlrt_marshallIn(sp, emlrtAlias(dense1b_diff), &thisId);
  emlrtDestroyArray(&dense1b_diff);
  return y;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[16]
{
  real_T(*y)[16];
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *tile_1,
                                 const char_T *identifier))[4096]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[4096];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(tile_1), &thisId);
  emlrtDestroyArray(&tile_1);
  return y;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId))[4096]
{
  real_T(*y)[4096];
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  static const int32_T iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 2U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 2U> *)&u)->size(), 2);
  emlrtAssign(&y, m);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *test_data,
                                   const char_T *identifier))[163840]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[163840];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(test_data), &thisId);
  emlrtDestroyArray(&test_data);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[163840]
{
  real_T(*y)[163840];
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *test_labels,
                                   const char_T *identifier))[2560]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2560];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = g_emlrt_marshallIn(sp, emlrtAlias(test_labels), &thisId);
  emlrtDestroyArray(&test_labels);
  return y;
}

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2560]
{
  real_T(*y)[2560];
  y = n_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4096]
{
  static const int32_T dims[2]{64, 64};
  real_T(*ret)[4096];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[4096])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[8]
{
  static const int32_T dims[2]{1, 8};
  real_T(*ret)[8];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[8])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims[2]{1, 2};
  real_T(*ret)[2];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[16]
{
  static const int32_T dims[2]{1, 16};
  real_T(*ret)[16];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[16])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[163840]
{
  static const int32_T dims[2]{64, 2560};
  real_T(*ret)[163840];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[163840])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2560]
{
  static const int32_T dims[2]{1, 2560};
  real_T(*ret)[2560];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[2560])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void inference_routine_api(inference_routineStackData *SD,
                           const mxArray *const prhs[15], const mxArray **plhs)
{
  coder::array<real_T, 2U> out;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*test_data)[163840];
  real_T(*dense1a)[4096];
  real_T(*dense1b)[4096];
  real_T(*dense1c)[4096];
  real_T(*dense1d)[4096];
  real_T(*dense1e)[4096];
  real_T(*tile_1)[4096];
  real_T(*tile_2)[4096];
  real_T(*test_labels)[2560];
  real_T(*dense1b_diff)[16];
  real_T(*max_weight)[8];
  real_T(*dense2b)[2];
  real_T(*kernel_sizes)[2];
  real_T n_kernels;
  real_T n_samples;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  tile_1 = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "tile_1");
  tile_2 = emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "tile_2");
  max_weight = b_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "max_weight");
  n_kernels = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "n_kernels");
  kernel_sizes = d_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "kernel_sizes");
  dense1a = emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "dense1a");
  dense1b = emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "dense1b");
  dense1c = emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "dense1c");
  dense1d = emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "dense1d");
  dense1e = emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "dense1e");
  dense1b_diff = e_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "dense1b_diff");
  dense2b = d_emlrt_marshallIn(&st, emlrtAlias(prhs[11]), "dense2b");
  test_data = f_emlrt_marshallIn(&st, emlrtAlias(prhs[12]), "test_data");
  test_labels = g_emlrt_marshallIn(&st, emlrtAlias(prhs[13]), "test_labels");
  n_samples = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[14]), "n_samples");
  // Invoke the target function
  inference_routine(SD, &st, *tile_1, *tile_2, *max_weight, n_kernels,
                    *kernel_sizes, *dense1a, *dense1b, *dense1c, *dense1d,
                    *dense1e, *dense1b_diff, *dense2b, *test_data, *test_labels,
                    n_samples, out);
  // Marshall function outputs
  out.no_free();
  *plhs = emlrt_marshallOut(out);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_inference_routine_api.cpp)
