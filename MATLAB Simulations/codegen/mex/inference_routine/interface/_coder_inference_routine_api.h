//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_inference_routine_api.h
//
// Code generation for function '_coder_inference_routine_api'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
struct inference_routineStackData;

// Function Declarations
void inference_routine_api(inference_routineStackData *SD,
                           const mxArray *const prhs[15], const mxArray **plhs);

// End of code generation (_coder_inference_routine_api.h)
