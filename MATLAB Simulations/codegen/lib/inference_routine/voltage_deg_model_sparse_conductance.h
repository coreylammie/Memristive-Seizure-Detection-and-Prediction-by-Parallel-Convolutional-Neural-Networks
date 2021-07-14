//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// voltage_deg_model_sparse_conductance.h
//
// Code generation for function 'voltage_deg_model_sparse_conductance'
//

#ifndef VOLTAGE_DEG_MODEL_SPARSE_CONDUCTANCE_H
#define VOLTAGE_DEG_MODEL_SPARSE_CONDUCTANCE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void voltage_deg_model_sparse_conductance(const double G_mem[4096],
                                          const double V_app_WL1_data[],
                                          double V_MAC_mat[4096],
                                          double b_I[64], double *P);

void voltage_deg_model_sparse_conductance(
    const double G_mem[4096], const coder::array<double, 2U> &V_app_WL1,
    double V_MAC_mat[4096], double b_I[64], double *P);

#endif
// End of code generation (voltage_deg_model_sparse_conductance.h)
