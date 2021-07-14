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
#include "inference_routine_data.h"
#include "inference_routine_types.h"
#include "rt_nonfinite.h"
#include "sparse.h"
#include "sparse1.h"
#include "sumMatrixIncludeNaN.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo p_emlrtRSI{
    194,                                    // lineNo
    "voltage_deg_model_sparse_conductance", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m" // pathName
};

static emlrtRSInfo q_emlrtRSI{
    219,                                    // lineNo
    "voltage_deg_model_sparse_conductance", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m" // pathName
};

static emlrtRSInfo r_emlrtRSI{
    222,                                    // lineNo
    "voltage_deg_model_sparse_conductance", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m" // pathName
};

static emlrtRSInfo s_emlrtRSI{
    223,                                    // lineNo
    "voltage_deg_model_sparse_conductance", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m" // pathName
};

static emlrtBCInfo r_emlrtBCI{
    1,                                      // iFirst
    32512,                                  // iLast
    66,                                     // lineNo
    9,                                      // colNo
    "i_vec",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    3                     // checkKind
};

static emlrtBCInfo s_emlrtBCI{
    1,                                      // iFirst
    32512,                                  // iLast
    76,                                     // lineNo
    9,                                      // colNo
    "i_vec",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    3                     // checkKind
};

static emlrtBCInfo t_emlrtBCI{
    1,                                      // iFirst
    32512,                                  // iLast
    71,                                     // lineNo
    9,                                      // colNo
    "i_vec",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    3                     // checkKind
};

static emlrtBCInfo u_emlrtBCI{
    1,                                      // iFirst
    64,                                     // iLast
    68,                                     // lineNo
    23,                                     // colNo
    "G_mem",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    0                     // checkKind
};

static emlrtBCInfo v_emlrtBCI{
    1,                                      // iFirst
    64,                                     // iLast
    78,                                     // lineNo
    23,                                     // colNo
    "G_mem",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    0                     // checkKind
};

static emlrtBCInfo w_emlrtBCI{
    1,                                      // iFirst
    64,                                     // iLast
    73,                                     // lineNo
    23,                                     // colNo
    "G_mem",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    0                     // checkKind
};

static emlrtBCInfo x_emlrtBCI{
    1,                                      // iFirst
    32512,                                  // iLast
    107,                                    // lineNo
    5,                                      // colNo
    "i_vec",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    3                     // checkKind
};

static emlrtBCInfo y_emlrtBCI{
    1,                                      // iFirst
    64,                                     // iLast
    109,                                    // lineNo
    20,                                     // colNo
    "G_mem",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    0                     // checkKind
};

static emlrtBCInfo ab_emlrtBCI{
    1,                                      // iFirst
    32512,                                  // iLast
    83,                                     // lineNo
    9,                                      // colNo
    "i_vec",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    3                     // checkKind
};

static emlrtBCInfo bb_emlrtBCI{
    1,                                      // iFirst
    32512,                                  // iLast
    126,                                    // lineNo
    5,                                      // colNo
    "i_vec",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    3                     // checkKind
};

static emlrtBCInfo cb_emlrtBCI{
    1,                                      // iFirst
    32512,                                  // iLast
    88,                                     // lineNo
    9,                                      // colNo
    "i_vec",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    3                     // checkKind
};

static emlrtBCInfo db_emlrtBCI{
    1,                                      // iFirst
    64,                                     // iLast
    128,                                    // lineNo
    19,                                     // colNo
    "G_mem",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    0                     // checkKind
};

static emlrtBCInfo eb_emlrtBCI{
    1,                                      // iFirst
    32512,                                  // iLast
    145,                                    // lineNo
    9,                                      // colNo
    "i_vec",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    3                     // checkKind
};

static emlrtBCInfo fb_emlrtBCI{
    1,                                      // iFirst
    32512,                                  // iLast
    169,                                    // lineNo
    9,                                      // colNo
    "i_vec",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    3                     // checkKind
};

static emlrtBCInfo gb_emlrtBCI{
    1,                                      // iFirst
    32512,                                  // iLast
    157,                                    // lineNo
    9,                                      // colNo
    "i_vec",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    3                     // checkKind
};

static emlrtBCInfo hb_emlrtBCI{
    1,                                      // iFirst
    64,                                     // iLast
    147,                                    // lineNo
    35,                                     // colNo
    "G_mem",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    0                     // checkKind
};

static emlrtBCInfo ib_emlrtBCI{
    1,                                      // iFirst
    32512,                                  // iLast
    151,                                    // lineNo
    9,                                      // colNo
    "i_vec",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    3                     // checkKind
};

static emlrtBCInfo jb_emlrtBCI{
    1,                                      // iFirst
    32512,                                  // iLast
    175,                                    // lineNo
    9,                                      // colNo
    "i_vec",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    3                     // checkKind
};

static emlrtBCInfo kb_emlrtBCI{
    1,                                      // iFirst
    32512,                                  // iLast
    163,                                    // lineNo
    9,                                      // colNo
    "i_vec",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    3                     // checkKind
};

static emlrtBCInfo lb_emlrtBCI{
    1,                                      // iFirst
    64,                                     // iLast
    177,                                    // lineNo
    24,                                     // colNo
    "G_mem",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    0                     // checkKind
};

static emlrtBCInfo mb_emlrtBCI{
    1,                                      // iFirst
    64,                                     // iLast
    165,                                    // lineNo
    37,                                     // colNo
    "G_mem",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    0                     // checkKind
};

static emlrtBCInfo nb_emlrtBCI{
    1,                                      // iFirst
    32512,                                  // iLast
    181,                                    // lineNo
    9,                                      // colNo
    "i_vec",                                // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    3                     // checkKind
};

static emlrtBCInfo ob_emlrtBCI{
    -1,                                     // iFirst
    -1,                                     // iLast
    207,                                    // lineNo
    19,                                     // colNo
    "V_app_WL1",                            // aName
    "voltage_deg_model_sparse_conductance", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\voltage_deg_model_sp"
    "arse_conductance.m", // pName
    0                     // checkKind
};

// Function Definitions
void c_voltage_deg_model_sparse_cond(
    inference_routineStackData *SD, const emlrtStack *sp,
    const real_T G_mem[4096], const real_T V_app_WL1_data[],
    int32_T V_app_WL1_size, real_T V_MAC_mat[4096], real_T b_I[64], real_T *P)
{
  coder::b_sparse E;
  coder::b_sparse V;
  coder::sparse combined_mat;
  emlrtStack st;
  real_T V_MAC_WL[4096];
  real_T i_vec[128];
  real_T j_vec[128];
  real_T vals[128];
  int32_T b_index;
  int32_T col_index;
  int32_T i;
  int32_T j;
  int32_T j_vec_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
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
  for (j_vec_tmp = 0; j_vec_tmp < 32512; j_vec_tmp++) {
    SD->f3.i_vec[j_vec_tmp] = 1.0;
    SD->f3.j_vec[j_vec_tmp] = 1.0;
    SD->f3.vals[j_vec_tmp] = 0.0;
  }
  //  Fill up vectors
  b_index = 0;
  //  A matrix values
  i = 1;
  j = 1;
  for (col_index = 0; col_index < 4096; col_index++) {
    boolean_T guard1{false};
    guard1 = false;
    if (j == 1) {
      if ((b_index + 1 < 1) || (b_index + 1 > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index + 1, 1, 32512, &r_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f3.i_vec[b_index] = static_cast<real_T>(col_index) + 1.0;
      SD->f3.j_vec[b_index] = static_cast<real_T>(col_index) + 1.0;
      if (i > 64) {
        emlrtDynamicBoundsCheckR2012b(65, 1, 64, &u_emlrtBCI, (emlrtCTX)sp);
      }
      SD->f3.vals[b_index] = (G_mem[i - 1] + 0.05) + 0.5;
      b_index++;
      guard1 = true;
    } else if (j == 64) {
      if ((b_index + 1 < 1) || (b_index + 1 > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index + 1, 1, 32512, &t_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f3.i_vec[b_index] = static_cast<real_T>(col_index) + 1.0;
      SD->f3.j_vec[b_index] = static_cast<real_T>(col_index) + 1.0;
      if (i > 64) {
        emlrtDynamicBoundsCheckR2012b(65, 1, 64, &w_emlrtBCI, (emlrtCTX)sp);
      }
      SD->f3.vals[b_index] = G_mem[i + 4031] + 0.5;
      b_index++;
    } else {
      if ((b_index + 1 < 1) || (b_index + 1 > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index + 1, 1, 32512, &s_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f3.i_vec[b_index] = static_cast<real_T>(col_index) + 1.0;
      SD->f3.j_vec[b_index] = static_cast<real_T>(col_index) + 1.0;
      if (i > 64) {
        emlrtDynamicBoundsCheckR2012b(65, 1, 64, &v_emlrtBCI, (emlrtCTX)sp);
      }
      SD->f3.vals[b_index] = G_mem[(i + ((j - 1) << 6)) - 1] + 1.0;
      b_index++;
      guard1 = true;
    }
    if (guard1) {
      if ((b_index + 1 < 1) || (b_index + 1 > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index + 1, 1, 32512, &ab_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f3.i_vec[b_index] = (static_cast<real_T>(col_index) + 1.0) + 1.0;
      SD->f3.j_vec[b_index] = static_cast<real_T>(col_index) + 1.0;
      SD->f3.vals[b_index] = -0.5;
      b_index += 2;
      if ((b_index < 1) || (b_index > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index, 1, 32512, &cb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f3.i_vec[b_index - 1] = static_cast<real_T>(col_index) + 1.0;
      SD->f3.j_vec[b_index - 1] = (static_cast<real_T>(col_index) + 1.0) + 1.0;
      SD->f3.vals[b_index - 1] = -0.5;
    }
    j++;
    if (j > 64) {
      j = 1;
      i++;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  //  B matrix values
  i = 1;
  j = 1;
  for (col_index = 0; col_index < 4096; col_index++) {
    j_vec_tmp = b_index + col_index;
    if ((j_vec_tmp + 1 < 1) || (j_vec_tmp + 1 > 32512)) {
      emlrtDynamicBoundsCheckR2012b(j_vec_tmp + 1, 1, 32512, &x_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    SD->f3.i_vec[j_vec_tmp] = static_cast<real_T>(col_index) + 1.0;
    SD->f3.j_vec[j_vec_tmp] = (static_cast<real_T>(col_index) + 1.0) + 4096.0;
    if (i > 64) {
      emlrtDynamicBoundsCheckR2012b(65, 1, 64, &y_emlrtBCI, (emlrtCTX)sp);
    }
    SD->f3.vals[j_vec_tmp] = -G_mem[(i + ((j - 1) << 6)) - 1];
    j++;
    if (j > 64) {
      j = 1;
      i++;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  //  C matrix values
  i = 0;
  j = 1;
  for (col_index = 0; col_index < 4096; col_index++) {
    j_vec_tmp = b_index + col_index;
    SD->f3.j_vec[j_vec_tmp + 4096] = (i << 6) + j;
    if ((j_vec_tmp + 4097 < 1) || (j_vec_tmp + 4097 > 32512)) {
      emlrtDynamicBoundsCheckR2012b(j_vec_tmp + 4097, 1, 32512, &bb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    SD->f3.i_vec[j_vec_tmp + 4096] =
        (static_cast<real_T>(col_index) + 1.0) + 4096.0;
    if (j > 64) {
      emlrtDynamicBoundsCheckR2012b(65, 1, 64, &db_emlrtBCI, (emlrtCTX)sp);
    }
    SD->f3.vals[j_vec_tmp + 4096] = G_mem[i + ((j - 1) << 6)];
    i++;
    if (i + 1 > 64) {
      i = 0;
      j++;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  b_index += 8192;
  //  D matrix values
  i = 1;
  j = 1;
  for (col_index = 0; col_index < 4096; col_index++) {
    if (i == 1) {
      if ((b_index + 1 < 1) || (b_index + 1 > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index + 1, 1, 32512, &eb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f3.i_vec[b_index] = (static_cast<real_T>(col_index) + 1.0) + 4096.0;
      SD->f3.j_vec[b_index] = static_cast<real_T>(j) + 4096.0;
      if (j > 64) {
        emlrtDynamicBoundsCheckR2012b(65, 1, 64, &hb_emlrtBCI, (emlrtCTX)sp);
      }
      SD->f3.vals[b_index] = -0.5 - G_mem[(j - 1) << 6];
      b_index += 2;
      if ((b_index < 1) || (b_index > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index, 1, 32512, &ib_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f3.i_vec[b_index - 1] =
          (static_cast<real_T>(col_index) + 1.0) + 4096.0;
      SD->f3.j_vec[b_index - 1] = (static_cast<real_T>(j) + 64.0) + 4096.0;
      SD->f3.vals[b_index - 1] = 0.5;
    } else if (i == 64) {
      if ((b_index + 1 < 1) || (b_index + 1 > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index + 1, 1, 32512, &gb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f3.i_vec[b_index] = (static_cast<real_T>(col_index) + 1.0) + 4096.0;
      SD->f3.j_vec[b_index] = (static_cast<real_T>(j) + 3968.0) + 4096.0;
      SD->f3.vals[b_index] = 0.5;
      b_index += 2;
      if ((b_index < 1) || (b_index > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index, 1, 32512, &kb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f3.i_vec[b_index - 1] =
          (static_cast<real_T>(col_index) + 1.0) + 4096.0;
      SD->f3.j_vec[b_index - 1] = (static_cast<real_T>(j) + 4032.0) + 4096.0;
      if (j > 64) {
        emlrtDynamicBoundsCheckR2012b(65, 1, 64, &mb_emlrtBCI, (emlrtCTX)sp);
      }
      SD->f3.vals[b_index - 1] = (-0.05 - G_mem[((j - 1) << 6) + 63]) - 0.5;
    } else {
      if ((b_index + 1 < 1) || (b_index + 1 > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index + 1, 1, 32512, &fb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f3.i_vec[b_index] = (static_cast<real_T>(col_index) + 1.0) + 4096.0;
      SD->f3.j_vec[b_index] = static_cast<real_T>(((i - 2) << 6) + j) + 4096.0;
      SD->f3.vals[b_index] = 0.5;
      b_index += 2;
      if ((b_index < 1) || (b_index > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index, 1, 32512, &jb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f3.i_vec[b_index - 1] =
          (static_cast<real_T>(col_index) + 1.0) + 4096.0;
      SD->f3.j_vec[b_index - 1] =
          static_cast<real_T>(((i - 1) << 6) + j) + 4096.0;
      if (j > 64) {
        emlrtDynamicBoundsCheckR2012b(65, 1, 64, &lb_emlrtBCI, (emlrtCTX)sp);
      }
      SD->f3.vals[b_index - 1] = -G_mem[(i + ((j - 1) << 6)) - 1] - 1.0;
      if (b_index + 1 > 32512) {
        emlrtDynamicBoundsCheckR2012b(32513, 1, 32512, &nb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f3.i_vec[b_index] = (static_cast<real_T>(col_index) + 1.0) + 4096.0;
      SD->f3.j_vec[b_index] = static_cast<real_T>((i << 6) + j) + 4096.0;
      SD->f3.vals[b_index] = 0.5;
      b_index++;
    }
    i++;
    if (i > 64) {
      i = 1;
      j++;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  st.site = &p_emlrtRSI;
  coder::c_sparse(SD, &st, SD->f3.i_vec, SD->f3.j_vec, SD->f3.vals,
                  &combined_mat);
  //  Construct vectors for E matrix
  for (j_vec_tmp = 0; j_vec_tmp < 128; j_vec_tmp++) {
    i_vec[j_vec_tmp] = 1.0;
    j_vec[j_vec_tmp] = 1.0;
    vals[j_vec_tmp] = 0.0;
  }
  //  Populate vectors
  //  E_W values
  for (i = 0; i < 64; i++) {
    i_vec[i] = ((static_cast<real_T>(i) + 1.0) - 1.0) * 64.0 + 1.0;
    j_vec[i] = 1.0;
    if (i + 1 > V_app_WL1_size) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, V_app_WL1_size, &ob_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    vals[i] = V_app_WL1_data[i] / 20.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  //  E_B values
  for (j = 0; j < 64; j++) {
    i_vec[j + 64] = (static_cast<real_T>(j) + 1.0) * 64.0 + 4096.0;
    j_vec[j + 64] = 1.0;
    vals[j + 64] = -0.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  st.site = &q_emlrtRSI;
  coder::c_sparse(&st, i_vec, j_vec, vals, &E);
  // V = linsolve(combined_mat, E);
  st.site = &r_emlrtRSI;
  combined_mat.mldivide(&st, &E, &V);
  st.site = &s_emlrtRSI;
  V.full(&st, SD->f3.V);
  //  Parse V to get column currents
  for (i = 0; i < 64; i++) {
    for (j = 0; j < 64; j++) {
      j_vec_tmp = (i << 6) + j;
      V_MAC_mat[i + (j << 6)] =
          SD->f3.V[j_vec_tmp] - SD->f3.V[j_vec_tmp + 4096];
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  for (j_vec_tmp = 0; j_vec_tmp < 4096; j_vec_tmp++) {
    V_MAC_WL[j_vec_tmp] = V_MAC_mat[j_vec_tmp] * G_mem[j_vec_tmp];
  }
  for (j_vec_tmp = 0; j_vec_tmp < 64; j_vec_tmp++) {
    b_I[j_vec_tmp] = coder::sumColumnB(V_MAC_WL, j_vec_tmp + 1);
  }
  for (j_vec_tmp = 0; j_vec_tmp < 4096; j_vec_tmp++) {
    V_MAC_WL[j_vec_tmp] *= V_MAC_mat[j_vec_tmp];
  }
  *P = coder::sumColumnB(V_MAC_WL);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void c_voltage_deg_model_sparse_cond(inference_routineStackData *SD,
                                     const emlrtStack *sp,
                                     const real_T G_mem[4096],
                                     const coder::array<real_T, 2U> &V_app_WL1,
                                     real_T V_MAC_mat[4096], real_T b_I[64],
                                     real_T *P)
{
  coder::b_sparse E;
  coder::b_sparse V;
  coder::sparse combined_mat;
  emlrtStack st;
  real_T V_MAC_WL[4096];
  real_T i_vec[128];
  real_T j_vec[128];
  real_T vals[128];
  int32_T b_index;
  int32_T col_index;
  int32_T i;
  int32_T j;
  int32_T j_vec_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
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
  for (j_vec_tmp = 0; j_vec_tmp < 32512; j_vec_tmp++) {
    SD->f2.i_vec[j_vec_tmp] = 1.0;
    SD->f2.j_vec[j_vec_tmp] = 1.0;
    SD->f2.vals[j_vec_tmp] = 0.0;
  }
  //  Fill up vectors
  b_index = 0;
  //  A matrix values
  i = 1;
  j = 1;
  for (col_index = 0; col_index < 4096; col_index++) {
    boolean_T guard1{false};
    guard1 = false;
    if (j == 1) {
      if ((b_index + 1 < 1) || (b_index + 1 > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index + 1, 1, 32512, &r_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f2.i_vec[b_index] = static_cast<real_T>(col_index) + 1.0;
      SD->f2.j_vec[b_index] = static_cast<real_T>(col_index) + 1.0;
      if (i > 64) {
        emlrtDynamicBoundsCheckR2012b(65, 1, 64, &u_emlrtBCI, (emlrtCTX)sp);
      }
      SD->f2.vals[b_index] = (G_mem[i - 1] + 0.05) + 0.5;
      b_index++;
      guard1 = true;
    } else if (j == 64) {
      if ((b_index + 1 < 1) || (b_index + 1 > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index + 1, 1, 32512, &t_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f2.i_vec[b_index] = static_cast<real_T>(col_index) + 1.0;
      SD->f2.j_vec[b_index] = static_cast<real_T>(col_index) + 1.0;
      if (i > 64) {
        emlrtDynamicBoundsCheckR2012b(65, 1, 64, &w_emlrtBCI, (emlrtCTX)sp);
      }
      SD->f2.vals[b_index] = G_mem[i + 4031] + 0.5;
      b_index++;
    } else {
      if ((b_index + 1 < 1) || (b_index + 1 > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index + 1, 1, 32512, &s_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f2.i_vec[b_index] = static_cast<real_T>(col_index) + 1.0;
      SD->f2.j_vec[b_index] = static_cast<real_T>(col_index) + 1.0;
      if (i > 64) {
        emlrtDynamicBoundsCheckR2012b(65, 1, 64, &v_emlrtBCI, (emlrtCTX)sp);
      }
      SD->f2.vals[b_index] = G_mem[(i + ((j - 1) << 6)) - 1] + 1.0;
      b_index++;
      guard1 = true;
    }
    if (guard1) {
      if ((b_index + 1 < 1) || (b_index + 1 > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index + 1, 1, 32512, &ab_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f2.i_vec[b_index] = (static_cast<real_T>(col_index) + 1.0) + 1.0;
      SD->f2.j_vec[b_index] = static_cast<real_T>(col_index) + 1.0;
      SD->f2.vals[b_index] = -0.5;
      b_index += 2;
      if ((b_index < 1) || (b_index > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index, 1, 32512, &cb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f2.i_vec[b_index - 1] = static_cast<real_T>(col_index) + 1.0;
      SD->f2.j_vec[b_index - 1] = (static_cast<real_T>(col_index) + 1.0) + 1.0;
      SD->f2.vals[b_index - 1] = -0.5;
    }
    j++;
    if (j > 64) {
      j = 1;
      i++;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  //  B matrix values
  i = 1;
  j = 1;
  for (col_index = 0; col_index < 4096; col_index++) {
    j_vec_tmp = b_index + col_index;
    if ((j_vec_tmp + 1 < 1) || (j_vec_tmp + 1 > 32512)) {
      emlrtDynamicBoundsCheckR2012b(j_vec_tmp + 1, 1, 32512, &x_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    SD->f2.i_vec[j_vec_tmp] = static_cast<real_T>(col_index) + 1.0;
    SD->f2.j_vec[j_vec_tmp] = (static_cast<real_T>(col_index) + 1.0) + 4096.0;
    if (i > 64) {
      emlrtDynamicBoundsCheckR2012b(65, 1, 64, &y_emlrtBCI, (emlrtCTX)sp);
    }
    SD->f2.vals[j_vec_tmp] = -G_mem[(i + ((j - 1) << 6)) - 1];
    j++;
    if (j > 64) {
      j = 1;
      i++;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  //  C matrix values
  i = 0;
  j = 1;
  for (col_index = 0; col_index < 4096; col_index++) {
    j_vec_tmp = b_index + col_index;
    SD->f2.j_vec[j_vec_tmp + 4096] = (i << 6) + j;
    if ((j_vec_tmp + 4097 < 1) || (j_vec_tmp + 4097 > 32512)) {
      emlrtDynamicBoundsCheckR2012b(j_vec_tmp + 4097, 1, 32512, &bb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    SD->f2.i_vec[j_vec_tmp + 4096] =
        (static_cast<real_T>(col_index) + 1.0) + 4096.0;
    if (j > 64) {
      emlrtDynamicBoundsCheckR2012b(65, 1, 64, &db_emlrtBCI, (emlrtCTX)sp);
    }
    SD->f2.vals[j_vec_tmp + 4096] = G_mem[i + ((j - 1) << 6)];
    i++;
    if (i + 1 > 64) {
      i = 0;
      j++;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  b_index += 8192;
  //  D matrix values
  i = 1;
  j = 1;
  for (col_index = 0; col_index < 4096; col_index++) {
    if (i == 1) {
      if ((b_index + 1 < 1) || (b_index + 1 > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index + 1, 1, 32512, &eb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f2.i_vec[b_index] = (static_cast<real_T>(col_index) + 1.0) + 4096.0;
      SD->f2.j_vec[b_index] = static_cast<real_T>(j) + 4096.0;
      if (j > 64) {
        emlrtDynamicBoundsCheckR2012b(65, 1, 64, &hb_emlrtBCI, (emlrtCTX)sp);
      }
      SD->f2.vals[b_index] = -0.5 - G_mem[(j - 1) << 6];
      b_index += 2;
      if ((b_index < 1) || (b_index > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index, 1, 32512, &ib_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f2.i_vec[b_index - 1] =
          (static_cast<real_T>(col_index) + 1.0) + 4096.0;
      SD->f2.j_vec[b_index - 1] = (static_cast<real_T>(j) + 64.0) + 4096.0;
      SD->f2.vals[b_index - 1] = 0.5;
    } else if (i == 64) {
      if ((b_index + 1 < 1) || (b_index + 1 > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index + 1, 1, 32512, &gb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f2.i_vec[b_index] = (static_cast<real_T>(col_index) + 1.0) + 4096.0;
      SD->f2.j_vec[b_index] = (static_cast<real_T>(j) + 3968.0) + 4096.0;
      SD->f2.vals[b_index] = 0.5;
      b_index += 2;
      if ((b_index < 1) || (b_index > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index, 1, 32512, &kb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f2.i_vec[b_index - 1] =
          (static_cast<real_T>(col_index) + 1.0) + 4096.0;
      SD->f2.j_vec[b_index - 1] = (static_cast<real_T>(j) + 4032.0) + 4096.0;
      if (j > 64) {
        emlrtDynamicBoundsCheckR2012b(65, 1, 64, &mb_emlrtBCI, (emlrtCTX)sp);
      }
      SD->f2.vals[b_index - 1] = (-0.05 - G_mem[((j - 1) << 6) + 63]) - 0.5;
    } else {
      if ((b_index + 1 < 1) || (b_index + 1 > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index + 1, 1, 32512, &fb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f2.i_vec[b_index] = (static_cast<real_T>(col_index) + 1.0) + 4096.0;
      SD->f2.j_vec[b_index] = static_cast<real_T>(((i - 2) << 6) + j) + 4096.0;
      SD->f2.vals[b_index] = 0.5;
      b_index += 2;
      if ((b_index < 1) || (b_index > 32512)) {
        emlrtDynamicBoundsCheckR2012b(b_index, 1, 32512, &jb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f2.i_vec[b_index - 1] =
          (static_cast<real_T>(col_index) + 1.0) + 4096.0;
      SD->f2.j_vec[b_index - 1] =
          static_cast<real_T>(((i - 1) << 6) + j) + 4096.0;
      if (j > 64) {
        emlrtDynamicBoundsCheckR2012b(65, 1, 64, &lb_emlrtBCI, (emlrtCTX)sp);
      }
      SD->f2.vals[b_index - 1] = -G_mem[(i + ((j - 1) << 6)) - 1] - 1.0;
      if (b_index + 1 > 32512) {
        emlrtDynamicBoundsCheckR2012b(32513, 1, 32512, &nb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      SD->f2.i_vec[b_index] = (static_cast<real_T>(col_index) + 1.0) + 4096.0;
      SD->f2.j_vec[b_index] = static_cast<real_T>((i << 6) + j) + 4096.0;
      SD->f2.vals[b_index] = 0.5;
      b_index++;
    }
    i++;
    if (i > 64) {
      i = 1;
      j++;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  st.site = &p_emlrtRSI;
  coder::c_sparse(SD, &st, SD->f2.i_vec, SD->f2.j_vec, SD->f2.vals,
                  &combined_mat);
  //  Construct vectors for E matrix
  for (j_vec_tmp = 0; j_vec_tmp < 128; j_vec_tmp++) {
    i_vec[j_vec_tmp] = 1.0;
    j_vec[j_vec_tmp] = 1.0;
    vals[j_vec_tmp] = 0.0;
  }
  //  Populate vectors
  //  E_W values
  for (i = 0; i < 64; i++) {
    i_vec[i] = ((static_cast<real_T>(i) + 1.0) - 1.0) * 64.0 + 1.0;
    j_vec[i] = 1.0;
    if (i + 1 > V_app_WL1.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, V_app_WL1.size(1), &ob_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    vals[i] = V_app_WL1[i] / 20.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  //  E_B values
  for (j = 0; j < 64; j++) {
    i_vec[j + 64] = (static_cast<real_T>(j) + 1.0) * 64.0 + 4096.0;
    j_vec[j + 64] = 1.0;
    vals[j + 64] = -0.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  st.site = &q_emlrtRSI;
  coder::c_sparse(&st, i_vec, j_vec, vals, &E);
  // V = linsolve(combined_mat, E);
  st.site = &r_emlrtRSI;
  combined_mat.mldivide(&st, &E, &V);
  st.site = &s_emlrtRSI;
  V.full(&st, SD->f2.V);
  //  Parse V to get column currents
  for (i = 0; i < 64; i++) {
    for (j = 0; j < 64; j++) {
      j_vec_tmp = (i << 6) + j;
      V_MAC_mat[i + (j << 6)] =
          SD->f2.V[j_vec_tmp] - SD->f2.V[j_vec_tmp + 4096];
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  for (j_vec_tmp = 0; j_vec_tmp < 4096; j_vec_tmp++) {
    V_MAC_WL[j_vec_tmp] = V_MAC_mat[j_vec_tmp] * G_mem[j_vec_tmp];
  }
  for (j_vec_tmp = 0; j_vec_tmp < 64; j_vec_tmp++) {
    b_I[j_vec_tmp] = coder::sumColumnB(V_MAC_WL, j_vec_tmp + 1);
  }
  for (j_vec_tmp = 0; j_vec_tmp < 4096; j_vec_tmp++) {
    V_MAC_WL[j_vec_tmp] *= V_MAC_mat[j_vec_tmp];
  }
  *P = coder::sumColumnB(V_MAC_WL);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (voltage_deg_model_sparse_conductance.cpp)
