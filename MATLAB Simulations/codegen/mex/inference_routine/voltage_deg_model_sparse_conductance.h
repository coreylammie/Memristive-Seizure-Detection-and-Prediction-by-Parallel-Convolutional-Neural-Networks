//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// voltage_deg_model_sparse_conductance.h
//
// Code generation for function 'voltage_deg_model_sparse_conductance'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
struct inference_routineStackData;

// Function Declarations
void c_voltage_deg_model_sparse_cond(
    inference_routineStackData *SD, const emlrtStack *sp,
    const real_T G_mem[4096], const real_T V_app_WL1_data[],
    int32_T V_app_WL1_size, real_T V_MAC_mat[4096], real_T b_I[64], real_T *P);

void c_voltage_deg_model_sparse_cond(inference_routineStackData *SD,
                                     const emlrtStack *sp,
                                     const real_T G_mem[4096],
                                     const coder::array<real_T, 2U> &V_app_WL1,
                                     real_T V_MAC_mat[4096], real_T b_I[64],
                                     real_T *P);

// End of code generation (voltage_deg_model_sparse_conductance.h)
