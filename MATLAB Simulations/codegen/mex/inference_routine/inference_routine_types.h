//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inference_routine_types.h
//
// Code generation for function 'inference_routine'
//

#pragma once

// Include files
#include "anonymous_function.h"
#include "rtwtypes.h"
#include "emlrt.h"

// Type Definitions
struct inference_routineStackData {
  struct {
    coder::anonymous_function b_this;
    int32_T t[32512];
  } f0;
  struct {
    int32_T ridxInt[32512];
    int32_T sortedIndices[32512];
    int32_T cidxInt[32512];
  } f1;
  struct {
    real_T i_vec[32512];
    real_T j_vec[32512];
    real_T vals[32512];
    real_T V[8192];
  } f2;
  struct {
    real_T i_vec[32512];
    real_T j_vec[32512];
    real_T vals[32512];
    real_T V[8192];
  } f3;
};

// End of code generation (inference_routine_types.h)
