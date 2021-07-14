//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// voltage_deg_model_sparse_conductance.cpp
//
// Code generation for function 'voltage_deg_model_sparse_conductance'
//

// Include files
#include "voltage_deg_model_sparse_conductance.h"
#include "sparse.h"
#include "sparse1.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
void voltage_deg_model_sparse_conductance(const double G_mem[4096],
                                          const double V_app_WL1_data[],
                                          double V_MAC_mat[4096],
                                          double b_I[64], double *P)
{
  static double i_vec[32512];
  static double j_vec[32512];
  static double vals[32512];
  static double b_V[8192];
  coder::b_sparse V;
  coder::b_sparse r1;
  coder::sparse r;
  double V_MAC_WL[4096];
  double b_i_vec[128];
  double b_j_vec[128];
  double b_vals[128];
  double bsum;
  int b_index;
  int cend;
  int col_index;
  int i;
  int j;
  int row_index;
  //    This function calculates the voltages at every junction in a memristor
  //    crossbar when taking into consideration interconnect line resistances
  //    and source resistance.
  //    For more information on the model itself, see
  //    A. Chen, "A Comprehensive Crossbar Array Model With Solutions for Line
  //    Resistance and Nonlinear Device Characteristics", IEEE Transactions on
  //    Electron Devices, vol. 60, no. 4, pp. 1318-1326, 2013.
  //    Inputs:
  //    G_mem - m x n matrix of conductance values in the crossbar array (S)
  //    V_app_WL1 - m x 1 vector of input row voltages for MAC operation
  //    V_app_BL1 - n x 1 vector of input column voltages for MAC operation
  //    R_source - resistance between word/bit line voltage sources and
  //               crossbar (ohms)
  //    R_line - interconnect line resistance between adjacent memristor cells
  //             in the crossbar array (ohms)
  //    Output:
  //    V_MAC_mat - m x n matrix of parsed voltages over each memristor
  //    I - n x 1 vector of current running through each crossbar column
  //    P - static power
  //    Intermediate:
  //    V - 2*m*n x 1 sparse vector that contains word line voltages (at one
  //      terminal of a memristor) and bit line voltages (at the opposite
  //      memristor terminal)
  //    V = [V_WL(1,1),
  //        ...,
  //         V_WL(1,n),
  //        V_WL(m,1),
  //         ...,
  //         V_WL(m,n),
  //         V_BL(1,1),
  //         ...,
  //          V_BL(1,n),
  //         V_BL(m,1),
  //         ...,
  //        V_BL(m,n)]
  //     NOTE: To determine the voltage over a memristor,
  //            V(i,j) = V_WL(i,j) - V_BL(i,j)
  //  Set word/bit line voltages
  // V_app_WL1 = V_in;
  // V_app_BL2 = zeros(n, 1);
  for (row_index = 0; row_index < 32512; row_index++) {
    i_vec[row_index] = 1.0;
    j_vec[row_index] = 1.0;
    vals[row_index] = 0.0;
  }
  //  Fill up vectors
  b_index = 0;
  //  A matrix values
  i = 0;
  j = 1;
  for (col_index = 0; col_index < 4096; col_index++) {
    boolean_T guard1{false};
    guard1 = false;
    if (j == 1) {
      i_vec[b_index] = static_cast<double>(col_index) + 1.0;
      j_vec[b_index] = static_cast<double>(col_index) + 1.0;
      vals[b_index] = (G_mem[i] + 0.05) + 0.5;
      b_index++;
      guard1 = true;
    } else if (j == 64) {
      i_vec[b_index] = static_cast<double>(col_index) + 1.0;
      j_vec[b_index] = static_cast<double>(col_index) + 1.0;
      vals[b_index] = G_mem[i + 4032] + 0.5;
      b_index++;
    } else {
      i_vec[b_index] = static_cast<double>(col_index) + 1.0;
      j_vec[b_index] = static_cast<double>(col_index) + 1.0;
      vals[b_index] = G_mem[i + ((j - 1) << 6)] + 1.0;
      b_index++;
      guard1 = true;
    }
    if (guard1) {
      i_vec[b_index] = (static_cast<double>(col_index) + 1.0) + 1.0;
      j_vec[b_index] = static_cast<double>(col_index) + 1.0;
      vals[b_index] = -0.5;
      b_index++;
      i_vec[b_index] = static_cast<double>(col_index) + 1.0;
      j_vec[b_index] = (static_cast<double>(col_index) + 1.0) + 1.0;
      vals[b_index] = -0.5;
      b_index++;
    }
    j++;
    if (j > 64) {
      j = 1;
      i++;
    }
  }
  //  B matrix values
  i = 0;
  j = 1;
  for (col_index = 0; col_index < 4096; col_index++) {
    cend = b_index + col_index;
    i_vec[cend] = static_cast<double>(col_index) + 1.0;
    j_vec[cend] = (static_cast<double>(col_index) + 1.0) + 4096.0;
    vals[cend] = -G_mem[i + ((j - 1) << 6)];
    j++;
    if (j > 64) {
      j = 1;
      i++;
    }
  }
  b_index += 4096;
  //  C matrix values
  i = 0;
  j = 1;
  for (row_index = 0; row_index < 4096; row_index++) {
    cend = b_index + row_index;
    j_vec[cend] = (i << 6) + j;
    i_vec[cend] = (static_cast<double>(row_index) + 1.0) + 4096.0;
    vals[cend] = G_mem[i + ((j - 1) << 6)];
    i++;
    if (i + 1 > 64) {
      i = 0;
      j++;
    }
  }
  b_index += 4096;
  //  D matrix values
  i = 1;
  j = 1;
  for (row_index = 0; row_index < 4096; row_index++) {
    if (i == 1) {
      i_vec[b_index] = (static_cast<double>(row_index) + 1.0) + 4096.0;
      j_vec[b_index] = static_cast<double>(j) + 4096.0;
      vals[b_index] = -0.5 - G_mem[(j - 1) << 6];
      b_index++;
      i_vec[b_index] = (static_cast<double>(row_index) + 1.0) + 4096.0;
      j_vec[b_index] = (static_cast<double>(j) + 64.0) + 4096.0;
      vals[b_index] = 0.5;
      b_index++;
    } else if (i == 64) {
      i_vec[b_index] = (static_cast<double>(row_index) + 1.0) + 4096.0;
      j_vec[b_index] = (static_cast<double>(j) + 3968.0) + 4096.0;
      vals[b_index] = 0.5;
      b_index++;
      i_vec[b_index] = (static_cast<double>(row_index) + 1.0) + 4096.0;
      j_vec[b_index] = (static_cast<double>(j) + 4032.0) + 4096.0;
      vals[b_index] = (-0.05 - G_mem[((j - 1) << 6) + 63]) - 0.5;
      b_index++;
    } else {
      i_vec[b_index] = (static_cast<double>(row_index) + 1.0) + 4096.0;
      j_vec[b_index] = static_cast<double>(((i - 2) << 6) + j) + 4096.0;
      vals[b_index] = 0.5;
      b_index++;
      i_vec[b_index] = (static_cast<double>(row_index) + 1.0) + 4096.0;
      j_vec[b_index] = static_cast<double>(((i - 1) << 6) + j) + 4096.0;
      vals[b_index] = -G_mem[(i + ((j - 1) << 6)) - 1] - 1.0;
      b_index++;
      i_vec[b_index] = (static_cast<double>(row_index) + 1.0) + 4096.0;
      j_vec[b_index] = static_cast<double>((i << 6) + j) + 4096.0;
      vals[b_index] = 0.5;
      b_index++;
    }
    i++;
    if (i > 64) {
      i = 1;
      j++;
    }
  }
  //  Construct vectors for E matrix
  for (row_index = 0; row_index < 128; row_index++) {
    b_i_vec[row_index] = 1.0;
    b_j_vec[row_index] = 1.0;
    b_vals[row_index] = 0.0;
  }
  //  Populate vectors
  //  E_W values
  //  E_B values
  for (i = 0; i < 64; i++) {
    b_i_vec[i] = ((static_cast<double>(i) + 1.0) - 1.0) * 64.0 + 1.0;
    b_j_vec[i] = 1.0;
    b_vals[i] = V_app_WL1_data[i] / 20.0;
    b_i_vec[i + 64] = (static_cast<double>(i) + 1.0) * 64.0 + 4096.0;
    b_j_vec[i + 64] = 1.0;
    b_vals[i + 64] = -0.0;
  }
  // V = linsolve(combined_mat, E);
  coder::c_sparse(i_vec, j_vec, vals, &r);
  coder::c_sparse(b_i_vec, b_j_vec, b_vals, &r1);
  r.mldivide(&r1, &V);
  std::memset(&b_V[0], 0, 8192U * sizeof(double));
  cend = V.colidx[1] - 1;
  row_index = V.colidx[0];
  for (col_index = row_index; col_index <= cend; col_index++) {
    b_V[V.rowidx[col_index - 1] - 1] = V.d[col_index - 1];
  }
  //  Parse V to get column currents
  for (i = 0; i < 64; i++) {
    for (j = 0; j < 64; j++) {
      cend = (i << 6) + j;
      V_MAC_mat[i + (j << 6)] = b_V[cend] - b_V[cend + 4096];
    }
  }
  for (row_index = 0; row_index < 4096; row_index++) {
    V_MAC_WL[row_index] = V_MAC_mat[row_index] * G_mem[row_index];
  }
  for (row_index = 0; row_index < 64; row_index++) {
    cend = row_index << 6;
    bsum = V_MAC_WL[cend];
    for (b_index = 0; b_index < 63; b_index++) {
      bsum += V_MAC_WL[(cend + b_index) + 1];
    }
    b_I[row_index] = bsum;
  }
  for (row_index = 0; row_index < 4096; row_index++) {
    V_MAC_WL[row_index] *= V_MAC_mat[row_index];
  }
  *P = V_MAC_WL[0];
  for (b_index = 0; b_index < 1023; b_index++) {
    *P += V_MAC_WL[b_index + 1];
  }
  for (col_index = 0; col_index < 3; col_index++) {
    cend = (col_index + 1) << 10;
    bsum = V_MAC_WL[cend];
    for (b_index = 0; b_index < 1023; b_index++) {
      bsum += V_MAC_WL[(cend + b_index) + 1];
    }
    *P += bsum;
  }
}

void voltage_deg_model_sparse_conductance(
    const double G_mem[4096], const coder::array<double, 2U> &V_app_WL1,
    double V_MAC_mat[4096], double b_I[64], double *P)
{
  static double i_vec[32512];
  static double j_vec[32512];
  static double vals[32512];
  static double b_V[8192];
  coder::b_sparse V;
  coder::b_sparse r1;
  coder::sparse r;
  double V_MAC_WL[4096];
  double b_i_vec[128];
  double b_j_vec[128];
  double b_vals[128];
  double bsum;
  int b_index;
  int cend;
  int col_index;
  int i;
  int j;
  int row_index;
  //    This function calculates the voltages at every junction in a memristor
  //    crossbar when taking into consideration interconnect line resistances
  //    and source resistance.
  //    For more information on the model itself, see
  //    A. Chen, "A Comprehensive Crossbar Array Model With Solutions for Line
  //    Resistance and Nonlinear Device Characteristics", IEEE Transactions on
  //    Electron Devices, vol. 60, no. 4, pp. 1318-1326, 2013.
  //    Inputs:
  //    G_mem - m x n matrix of conductance values in the crossbar array (S)
  //    V_app_WL1 - m x 1 vector of input row voltages for MAC operation
  //    V_app_BL1 - n x 1 vector of input column voltages for MAC operation
  //    R_source - resistance between word/bit line voltage sources and
  //               crossbar (ohms)
  //    R_line - interconnect line resistance between adjacent memristor cells
  //             in the crossbar array (ohms)
  //    Output:
  //    V_MAC_mat - m x n matrix of parsed voltages over each memristor
  //    I - n x 1 vector of current running through each crossbar column
  //    P - static power
  //    Intermediate:
  //    V - 2*m*n x 1 sparse vector that contains word line voltages (at one
  //      terminal of a memristor) and bit line voltages (at the opposite
  //      memristor terminal)
  //    V = [V_WL(1,1),
  //        ...,
  //         V_WL(1,n),
  //        V_WL(m,1),
  //         ...,
  //         V_WL(m,n),
  //         V_BL(1,1),
  //         ...,
  //          V_BL(1,n),
  //         V_BL(m,1),
  //         ...,
  //        V_BL(m,n)]
  //     NOTE: To determine the voltage over a memristor,
  //            V(i,j) = V_WL(i,j) - V_BL(i,j)
  //  Set word/bit line voltages
  // V_app_WL1 = V_in;
  // V_app_BL2 = zeros(n, 1);
  for (row_index = 0; row_index < 32512; row_index++) {
    i_vec[row_index] = 1.0;
    j_vec[row_index] = 1.0;
    vals[row_index] = 0.0;
  }
  //  Fill up vectors
  b_index = 0;
  //  A matrix values
  i = 0;
  j = 1;
  for (col_index = 0; col_index < 4096; col_index++) {
    boolean_T guard1{false};
    guard1 = false;
    if (j == 1) {
      i_vec[b_index] = static_cast<double>(col_index) + 1.0;
      j_vec[b_index] = static_cast<double>(col_index) + 1.0;
      vals[b_index] = (G_mem[i] + 0.05) + 0.5;
      b_index++;
      guard1 = true;
    } else if (j == 64) {
      i_vec[b_index] = static_cast<double>(col_index) + 1.0;
      j_vec[b_index] = static_cast<double>(col_index) + 1.0;
      vals[b_index] = G_mem[i + 4032] + 0.5;
      b_index++;
    } else {
      i_vec[b_index] = static_cast<double>(col_index) + 1.0;
      j_vec[b_index] = static_cast<double>(col_index) + 1.0;
      vals[b_index] = G_mem[i + ((j - 1) << 6)] + 1.0;
      b_index++;
      guard1 = true;
    }
    if (guard1) {
      i_vec[b_index] = (static_cast<double>(col_index) + 1.0) + 1.0;
      j_vec[b_index] = static_cast<double>(col_index) + 1.0;
      vals[b_index] = -0.5;
      b_index++;
      i_vec[b_index] = static_cast<double>(col_index) + 1.0;
      j_vec[b_index] = (static_cast<double>(col_index) + 1.0) + 1.0;
      vals[b_index] = -0.5;
      b_index++;
    }
    j++;
    if (j > 64) {
      j = 1;
      i++;
    }
  }
  //  B matrix values
  i = 0;
  j = 1;
  for (col_index = 0; col_index < 4096; col_index++) {
    cend = b_index + col_index;
    i_vec[cend] = static_cast<double>(col_index) + 1.0;
    j_vec[cend] = (static_cast<double>(col_index) + 1.0) + 4096.0;
    vals[cend] = -G_mem[i + ((j - 1) << 6)];
    j++;
    if (j > 64) {
      j = 1;
      i++;
    }
  }
  b_index += 4096;
  //  C matrix values
  i = 0;
  j = 1;
  for (row_index = 0; row_index < 4096; row_index++) {
    cend = b_index + row_index;
    j_vec[cend] = (i << 6) + j;
    i_vec[cend] = (static_cast<double>(row_index) + 1.0) + 4096.0;
    vals[cend] = G_mem[i + ((j - 1) << 6)];
    i++;
    if (i + 1 > 64) {
      i = 0;
      j++;
    }
  }
  b_index += 4096;
  //  D matrix values
  i = 1;
  j = 1;
  for (row_index = 0; row_index < 4096; row_index++) {
    if (i == 1) {
      i_vec[b_index] = (static_cast<double>(row_index) + 1.0) + 4096.0;
      j_vec[b_index] = static_cast<double>(j) + 4096.0;
      vals[b_index] = -0.5 - G_mem[(j - 1) << 6];
      b_index++;
      i_vec[b_index] = (static_cast<double>(row_index) + 1.0) + 4096.0;
      j_vec[b_index] = (static_cast<double>(j) + 64.0) + 4096.0;
      vals[b_index] = 0.5;
      b_index++;
    } else if (i == 64) {
      i_vec[b_index] = (static_cast<double>(row_index) + 1.0) + 4096.0;
      j_vec[b_index] = (static_cast<double>(j) + 3968.0) + 4096.0;
      vals[b_index] = 0.5;
      b_index++;
      i_vec[b_index] = (static_cast<double>(row_index) + 1.0) + 4096.0;
      j_vec[b_index] = (static_cast<double>(j) + 4032.0) + 4096.0;
      vals[b_index] = (-0.05 - G_mem[((j - 1) << 6) + 63]) - 0.5;
      b_index++;
    } else {
      i_vec[b_index] = (static_cast<double>(row_index) + 1.0) + 4096.0;
      j_vec[b_index] = static_cast<double>(((i - 2) << 6) + j) + 4096.0;
      vals[b_index] = 0.5;
      b_index++;
      i_vec[b_index] = (static_cast<double>(row_index) + 1.0) + 4096.0;
      j_vec[b_index] = static_cast<double>(((i - 1) << 6) + j) + 4096.0;
      vals[b_index] = -G_mem[(i + ((j - 1) << 6)) - 1] - 1.0;
      b_index++;
      i_vec[b_index] = (static_cast<double>(row_index) + 1.0) + 4096.0;
      j_vec[b_index] = static_cast<double>((i << 6) + j) + 4096.0;
      vals[b_index] = 0.5;
      b_index++;
    }
    i++;
    if (i > 64) {
      i = 1;
      j++;
    }
  }
  //  Construct vectors for E matrix
  for (row_index = 0; row_index < 128; row_index++) {
    b_i_vec[row_index] = 1.0;
    b_j_vec[row_index] = 1.0;
    b_vals[row_index] = 0.0;
  }
  //  Populate vectors
  //  E_W values
  //  E_B values
  for (i = 0; i < 64; i++) {
    b_i_vec[i] = ((static_cast<double>(i) + 1.0) - 1.0) * 64.0 + 1.0;
    b_j_vec[i] = 1.0;
    b_vals[i] = V_app_WL1[i] / 20.0;
    b_i_vec[i + 64] = (static_cast<double>(i) + 1.0) * 64.0 + 4096.0;
    b_j_vec[i + 64] = 1.0;
    b_vals[i + 64] = -0.0;
  }
  // V = linsolve(combined_mat, E);
  coder::c_sparse(i_vec, j_vec, vals, &r);
  coder::c_sparse(b_i_vec, b_j_vec, b_vals, &r1);
  r.mldivide(&r1, &V);
  std::memset(&b_V[0], 0, 8192U * sizeof(double));
  cend = V.colidx[1] - 1;
  row_index = V.colidx[0];
  for (col_index = row_index; col_index <= cend; col_index++) {
    b_V[V.rowidx[col_index - 1] - 1] = V.d[col_index - 1];
  }
  //  Parse V to get column currents
  for (i = 0; i < 64; i++) {
    for (j = 0; j < 64; j++) {
      cend = (i << 6) + j;
      V_MAC_mat[i + (j << 6)] = b_V[cend] - b_V[cend + 4096];
    }
  }
  for (row_index = 0; row_index < 4096; row_index++) {
    V_MAC_WL[row_index] = V_MAC_mat[row_index] * G_mem[row_index];
  }
  for (row_index = 0; row_index < 64; row_index++) {
    cend = row_index << 6;
    bsum = V_MAC_WL[cend];
    for (b_index = 0; b_index < 63; b_index++) {
      bsum += V_MAC_WL[(cend + b_index) + 1];
    }
    b_I[row_index] = bsum;
  }
  for (row_index = 0; row_index < 4096; row_index++) {
    V_MAC_WL[row_index] *= V_MAC_mat[row_index];
  }
  *P = V_MAC_WL[0];
  for (b_index = 0; b_index < 1023; b_index++) {
    *P += V_MAC_WL[b_index + 1];
  }
  for (col_index = 0; col_index < 3; col_index++) {
    cend = (col_index + 1) << 10;
    bsum = V_MAC_WL[cend];
    for (b_index = 0; b_index < 1023; b_index++) {
      bsum += V_MAC_WL[(cend + b_index) + 1];
    }
    *P += bsum;
  }
}

// End of code generation (voltage_deg_model_sparse_conductance.cpp)
