//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inference_routine_initialize.cpp
//
// Code generation for function 'inference_routine_initialize'
//

// Include files
#include "inference_routine_initialize.h"
#include "_coder_inference_routine_mex.h"
#include "inference_routine_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void inference_routine_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

// End of code generation (inference_routine_initialize.cpp)
