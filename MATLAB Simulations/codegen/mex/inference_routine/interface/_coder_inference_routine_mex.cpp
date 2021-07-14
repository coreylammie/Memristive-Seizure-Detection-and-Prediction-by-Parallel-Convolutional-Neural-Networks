//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_inference_routine_mex.cpp
//
// Code generation for function '_coder_inference_routine_mex'
//

// Include files
#include "_coder_inference_routine_mex.h"
#include "_coder_inference_routine_api.h"
#include "inference_routine_data.h"
#include "inference_routine_initialize.h"
#include "inference_routine_terminate.h"
#include "inference_routine_types.h"
#include "rt_nonfinite.h"
#include <cstddef>
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void inference_routine_mexFunction(inference_routineStackData *SD, int32_T nlhs,
                                   mxArray *plhs[1], int32_T nrhs,
                                   const mxArray *prhs[15])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 15) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 15, 4,
                        17, "inference_routine");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "inference_routine");
  }
  // Call the function.
  inference_routine_api(SD, prhs, &outputs);
  // Copy over outputs to the caller.
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  inference_routineStackData *c_inference_routineStackDataGlo{nullptr};
  c_inference_routineStackDataGlo = new inference_routineStackData;
  mexAtExit(&inference_routine_atexit);
  // Module initialization.
  inference_routine_initialize();
  try {
    emlrtShouldCleanupOnError((emlrtCTX *)emlrtRootTLSGlobal, false);
    // Dispatch the entry-point.
    inference_routine_mexFunction(c_inference_routineStackDataGlo, nlhs, plhs,
                                  nrhs, prhs);
    // Module termination.
    inference_routine_terminate();
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
  delete c_inference_routineStackDataGlo;
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           (void *)&emlrtExceptionBridge);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_inference_routine_mex.cpp)
