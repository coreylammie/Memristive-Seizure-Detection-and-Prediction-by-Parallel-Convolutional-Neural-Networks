//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inference_routine.cpp
//
// Code generation for function 'inference_routine'
//

// Include files
#include "inference_routine.h"
#include "eml_int_forloop_overflow_check.h"
#include "inference_routine_data.h"
#include "inference_routine_types.h"
#include "rand.h"
#include "round.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "voltage_deg_model_sparse_conductance.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstring>

// Variable Definitions
static emlrtRSInfo emlrtRSI{
    119,                 // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    110,                 // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    103,                 // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    95,                  // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    87,                  // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    82,                  // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    77,                  // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    72,                  // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    67,                  // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    44,                  // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    43,                  // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

static emlrtRSInfo l_emlrtRSI{
    36,                  // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

static emlrtRSInfo m_emlrtRSI{
    27,                  // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

static emlrtRSInfo n_emlrtRSI{
    11,                  // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

static emlrtRSInfo o_emlrtRSI{
    10,                  // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

static emlrtRSInfo yb_emlrtRSI{
    867,                    // lineNo
    "minRealVectorOmitNaN", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pathName
};

static emlrtRSInfo ac_emlrtRSI{
    62,                      // lineNo
    "vectorMinOrMaxInPlace", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" // pathName
};

static emlrtRSInfo bc_emlrtRSI{
    54,                      // lineNo
    "vectorMinOrMaxInPlace", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" // pathName
};

static emlrtRSInfo cc_emlrtRSI{
    103,         // lineNo
    "findFirst", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" // pathName
};

static emlrtRSInfo dc_emlrtRSI{
    120,                        // lineNo
    "minOrMaxRealVectorKernel", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" // pathName
};

static emlrtRSInfo id_emlrtRSI{
    15,    // lineNo
    "max", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" // pathName
};

static emlrtRSInfo
    jd_emlrtRSI{
        44,         // lineNo
        "minOrMax", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

static emlrtRSInfo
    kd_emlrtRSI{
        79,        // lineNo
        "maximum", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

static emlrtRSInfo ld_emlrtRSI{
    197,             // lineNo
    "unaryMinOrMax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pathName
};

static emlrtRSInfo md_emlrtRSI{
    288,                     // lineNo
    "unaryMinOrMaxDispatch", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pathName
};

static emlrtRSInfo nd_emlrtRSI{
    356,          // lineNo
    "minOrMax2D", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pathName
};

static emlrtRSInfo od_emlrtRSI{
    438,                         // lineNo
    "minOrMax2DColumnMajorDim1", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pathName
};

static emlrtRSInfo pd_emlrtRSI{
    436,                         // lineNo
    "minOrMax2DColumnMajorDim1", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pathName
};

static emlrtRSInfo qd_emlrtRSI{
    175,             // lineNo
    "unaryMinOrMax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pathName
};

static emlrtRSInfo rd_emlrtRSI{
    871,                    // lineNo
    "maxRealVectorOmitNaN", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pathName
};

static emlrtRSInfo sd_emlrtRSI{
    15,    // lineNo
    "min", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" // pathName
};

static emlrtRSInfo
    td_emlrtRSI{
        46,         // lineNo
        "minOrMax", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

static emlrtRSInfo
    ud_emlrtRSI{
        92,        // lineNo
        "minimum", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

static emlrtRSInfo vd_emlrtRSI{
    185,             // lineNo
    "unaryMinOrMax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pathName
};

static emlrtMCInfo emlrtMCI{
    19,                  // lineNo
    9,                   // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtMCInfo b_emlrtMCI{
    120,                 // lineNo
    9,                   // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtECInfo emlrtECI{
    2,                   // nDims
    116,                 // lineNo
    15,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtBCInfo emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    116,                 // lineNo
    32,                  // colNo
    "predictions",       // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtBCInfo b_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    116,                 // lineNo
    30,                  // colNo
    "predictions",       // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtDCInfo emlrtDCI{
    102,                 // lineNo
    63,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    1                                                           // checkKind
};

static emlrtDCInfo b_emlrtDCI{
    102,                 // lineNo
    63,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    4                                                           // checkKind
};

static emlrtDCInfo c_emlrtDCI{
    102,                 // lineNo
    25,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    1                                                           // checkKind
};

static emlrtDCInfo d_emlrtDCI{
    102,                 // lineNo
    25,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    4                                                           // checkKind
};

static emlrtECInfo b_emlrtECI{
    2,                   // nDims
    89,                  // lineNo
    25,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtECInfo c_emlrtECI{
    2,                   // nDims
    84,                  // lineNo
    25,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtECInfo d_emlrtECI{
    2,                   // nDims
    79,                  // lineNo
    25,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtECInfo e_emlrtECI{
    2,                   // nDims
    74,                  // lineNo
    25,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtECInfo f_emlrtECI{
    2,                   // nDims
    69,                  // lineNo
    25,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtBCInfo c_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    52,                  // lineNo
    71,                  // colNo
    "conv_out",          // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    52,                  // lineNo
    53,                  // colNo
    "conv_out",          // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtECInfo g_emlrtECI{
    -1,                  // nDims
    40,                  // lineNo
    13,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtBCInfo e_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    40,                  // lineNo
    22,                  // colNo
    "conv_out",          // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtDCInfo e_emlrtDCI{
    40,                  // lineNo
    22,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    1                                                           // checkKind
};

static emlrtECInfo h_emlrtECI{
    -1,                  // nDims
    31,                  // lineNo
    13,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtBCInfo f_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    31,                  // lineNo
    22,                  // colNo
    "conv_out",          // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtDCInfo f_emlrtDCI{
    35,                  // lineNo
    67,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    1                                                           // checkKind
};

static emlrtDCInfo g_emlrtDCI{
    35,                  // lineNo
    67,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    4                                                           // checkKind
};

static emlrtBCInfo g_emlrtBCI{
    1,                   // iFirst
    64,                  // iLast
    35,                  // lineNo
    36,                  // colNo
    "input_vec",         // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtDCInfo h_emlrtDCI{
    35,                  // lineNo
    36,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    1                                                           // checkKind
};

static emlrtBCInfo h_emlrtBCI{
    1,                   // iFirst
    64,                  // iLast
    35,                  // lineNo
    34,                  // colNo
    "input_vec",         // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtRTEInfo emlrtRTEI{
    34,                  // lineNo
    17,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtDCInfo i_emlrtDCI{
    26,                  // lineNo
    67,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    1                                                           // checkKind
};

static emlrtDCInfo j_emlrtDCI{
    26,                  // lineNo
    67,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    4                                                           // checkKind
};

static emlrtBCInfo i_emlrtBCI{
    1,                   // iFirst
    64,                  // iLast
    26,                  // lineNo
    36,                  // colNo
    "input_vec",         // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtDCInfo k_emlrtDCI{
    26,                  // lineNo
    36,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    1                                                           // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    1,                   // iFirst
    64,                  // iLast
    26,                  // lineNo
    34,                  // colNo
    "input_vec",         // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtRTEInfo b_emlrtRTEI{
    25,                  // lineNo
    17,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtBCInfo k_emlrtBCI{
    1,                   // iFirst
    2560,                // iLast
    20,                  // lineNo
    34,                  // colNo
    "test_data",         // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtRTEInfo c_emlrtRTEI{
    18,                  // lineNo
    22,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtRTEInfo d_emlrtRTEI{
    26,              // lineNo
    27,              // colNo
    "unaryMinOrMax", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pName
};

static emlrtRTEInfo e_emlrtRTEI{
    124,             // lineNo
    27,              // colNo
    "unaryMinOrMax", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pName
};

static emlrtDCInfo l_emlrtDCI{
    2,                   // lineNo
    28,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    1                                                           // checkKind
};

static emlrtDCInfo m_emlrtDCI{
    2,                   // lineNo
    28,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    4                                                           // checkKind
};

static emlrtDCInfo n_emlrtDCI{
    23,                  // lineNo
    26,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    1                                                           // checkKind
};

static emlrtDCInfo o_emlrtDCI{
    23,                  // lineNo
    26,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    4                                                           // checkKind
};

static emlrtDCInfo p_emlrtDCI{
    23,                  // lineNo
    71,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    1                                                           // checkKind
};

static emlrtDCInfo q_emlrtDCI{
    23,                  // lineNo
    71,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    4                                                           // checkKind
};

static emlrtDCInfo r_emlrtDCI{
    2,                   // lineNo
    5,                   // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    1                                                           // checkKind
};

static emlrtDCInfo s_emlrtDCI{
    2,                   // lineNo
    5,                   // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    4                                                           // checkKind
};

static emlrtDCInfo t_emlrtDCI{
    23,                  // lineNo
    9,                   // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    1                                                           // checkKind
};

static emlrtBCInfo l_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    46,                  // lineNo
    9,                   // colNo
    "conv_out",          // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtBCInfo m_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    54,                  // lineNo
    50,                  // colNo
    "conv_out",          // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtBCInfo n_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    54,                  // lineNo
    68,                  // colNo
    "conv_out",          // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtDCInfo u_emlrtDCI{
    54,                  // lineNo
    21,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    1                                                           // checkKind
};

static emlrtBCInfo o_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    52,                  // lineNo
    44,                  // colNo
    "conv_out",          // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtBCInfo p_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    114,                 // lineNo
    9,                   // colNo
    "predictions",       // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtBCInfo q_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    117,                 // lineNo
    9,                   // colNo
    "dif",               // aName
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m", // pName
    0                                                           // checkKind
};

static emlrtRTEInfo o_emlrtRTEI{
    2,                   // lineNo
    5,                   // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtRTEInfo p_emlrtRTEI{
    23,                  // lineNo
    9,                   // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtRTEInfo q_emlrtRTEI{
    26,                  // lineNo
    20,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtRTEInfo r_emlrtRTEI{
    35,                  // lineNo
    20,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtRTEInfo s_emlrtRTEI{
    428,             // lineNo
    21,              // colNo
    "unaryMinOrMax", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pName
};

static emlrtRTEInfo t_emlrtRTEI{
    1,                   // lineNo
    16,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtRTEInfo u_emlrtRTEI{
    102,                 // lineNo
    16,                  // colNo
    "inference_routine", // fName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pName
};

static emlrtRSInfo be_emlrtRSI{
    120,                 // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

static emlrtRSInfo ce_emlrtRSI{
    19,                  // lineNo
    "inference_routine", // fcnName
    "E:\\Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-"
    "Neural-Networks\\MATLAB Simulations\\inference_routine.m" // pathName
};

// Function Declarations
static void disp(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);

static const mxArray *emlrt_marshallOut(const real_T u);

// Function Definitions
static void disp(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b((emlrtCTX)sp, 0, nullptr, 1, &pArray,
                        (const char_T *)"disp", true, location);
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

void inference_routine(inference_routineStackData *SD, const emlrtStack *sp,
                       const real_T tile_1[4096], const real_T tile_2[4096],
                       const real_T max_weight[8], real_T n_kernels,
                       const real_T kernel_sizes[2], const real_T dense1a[4096],
                       const real_T dense1b[4096], const real_T dense1c[4096],
                       const real_T dense1d[4096], const real_T dense1e[4096],
                       const real_T dense1b_diff[16], const real_T dense2b[2],
                       const real_T test_data[163840],
                       const real_T test_labels[2560], real_T n_samples,
                       coder::array<real_T, 2U> &out)
{
  static const int8_T reading[128]{
      1, 16, 17, 32, 33, 48, 49, 64, 1, 16, 17, 32, 33, 48, 49, 64,
      1, 16, 17, 32, 33, 48, 49, 64, 1, 16, 17, 32, 33, 48, 49, 64,
      1, 16, 17, 32, 33, 48, 49, 64, 1, 16, 17, 32, 33, 48, 49, 64,
      1, 16, 17, 32, 33, 48, 49, 64, 1, 16, 17, 32, 33, 48, 49, 64,
      1, 16, 17, 32, 33, 48, 49, 64, 1, 16, 17, 32, 33, 48, 49, 64,
      1, 16, 17, 32, 33, 48, 49, 64, 1, 16, 17, 32, 33, 48, 49, 64,
      1, 16, 17, 32, 33, 48, 49, 64, 1, 16, 17, 32, 33, 48, 49, 64,
      1, 16, 17, 32, 33, 48, 49, 64, 1, 16, 17, 32, 33, 48, 49, 64};
  coder::array<real_T, 2U> conv_out;
  coder::array<real_T, 2U> maxval;
  coder::array<int32_T, 1U> r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  real_T a__1[4096];
  real_T dif_data[2560];
  real_T avgpool_out[1088];
  real_T d_avgpool_out_data[1024];
  real_T c_avgpool_out_data[768];
  real_T b_avgpool_out_data[512];
  real_T avgpool_out_data[256];
  real_T I_temp[64];
  real_T tempI_data[64];
  real_T b_I_temp[32];
  real_T total[16];
  real_T rmaxlimit[8];
  real_T rminlimit[8];
  real_T b;
  real_T conv_outstep;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  int32_T dif_size[2];
  int32_T iv[2];
  int32_T iv1[2];
  int32_T test_labels_size[2];
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T d_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T n;
  int16_T tmp_data[2560];
  int8_T tempI_size[2];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  out.set_size(&o_emlrtRTEI, sp, 1, out.size(1));
  if (!(n_samples + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(n_samples + 1.0, &m_emlrtDCI, (emlrtCTX)sp);
  }
  b = static_cast<int32_T>(muDoubleScalarFloor(n_samples + 1.0));
  if (n_samples + 1.0 != b) {
    emlrtIntegerCheckR2012b(n_samples + 1.0, &l_emlrtDCI, (emlrtCTX)sp);
  }
  out.set_size(&o_emlrtRTEI, sp, out.size(0),
               static_cast<int32_T>(n_samples + 1.0));
  if (!(n_samples + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(n_samples + 1.0, &s_emlrtDCI, (emlrtCTX)sp);
  }
  if (n_samples + 1.0 != b) {
    emlrtIntegerCheckR2012b(n_samples + 1.0, &r_emlrtDCI, (emlrtCTX)sp);
  }
  n = static_cast<int32_T>(n_samples + 1.0);
  for (i = 0; i < n; i++) {
    out[i] = 0.0;
  }
  // Ground column voltages (set columns to 0 V)
  //  20-50 source resistance (ohms) for simulation model
  //  2-5 line resistance (ohms) for simulation model
  // 100 kohm is max resistance of memristors
  // 10 kohm is min resistance of memristors
  // limit for min_R [1,1] to turn off
  // limit for max_R [1,1] to turn off
  st.site = &o_emlrtRSI;
  coder::b_rand(rmaxlimit);
  for (i = 0; i < 8; i++) {
    rmaxlimit[i] = rmaxlimit[i] * 0.050000000000000044 + 1.0;
  }
  st.site = &n_emlrtRSI;
  coder::b_rand(rminlimit);
  //  Calculate max conductance based on resistance
  //  Calculate min conductance based on resistance
  for (i = 0; i < 8; i++) {
    b = 1.0 / (100000.0 * rmaxlimit[i]);
    rmaxlimit[i] = b;
    rminlimit[i] =
        (1.0 / (10000.0 * (rminlimit[i] * 0.050000000000000044 + 0.95)) - b) /
        max_weight[i];
  }
  i = static_cast<int32_T>(n_samples + 1.0);
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, n_samples + 1.0, mxDOUBLE_CLASS,
                                static_cast<int32_T>(n_samples + 1.0),
                                &c_emlrtRTEI, (emlrtCTX)sp);
  if (0 <= i - 1) {
    d = ((128.0 - kernel_sizes[0]) - kernel_sizes[1]) + 2.0;
    d1 = static_cast<int32_T>(muDoubleScalarFloor(d));
    d2 = static_cast<int32_T>(muDoubleScalarFloor(n_kernels));
    loop_ub = static_cast<int32_T>(d) * static_cast<int32_T>(n_kernels);
    i1 = static_cast<int32_T>((64.0 - kernel_sizes[0]) + 1.0);
    i2 = static_cast<int32_T>((64.0 - kernel_sizes[1]) + 1.0);
    d3 = kernel_sizes[0];
    loop_ub_tmp = static_cast<int32_T>(56.0 - kernel_sizes[0]);
    b_loop_ub = static_cast<int32_T>(kernel_sizes[0] + 1.0);
    test_labels_size[0] = 1;
  }
  for (int32_T sample_idx{0}; sample_idx < i; sample_idx++) {
    real_T dense2_out_idx_0;
    real_T dense2_out_idx_1;
    int32_T b_i;
    int32_T j;
    int32_T k;
    int32_T m;
    boolean_T exitg1;
    boolean_T p;
    st.site = &ce_emlrtRSI;
    disp(&st, emlrt_marshallOut(static_cast<real_T>(sample_idx) + 1.0),
         &emlrtMCI);
    if ((sample_idx + 1 < 1) || (sample_idx + 1 > 2560)) {
      emlrtDynamicBoundsCheckR2012b(sample_idx + 1, 1, 2560, &k_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    //  Input vector
    //  Forward operation for tiles 1 and 2 (convolution)
    if (!(d >= 0.0)) {
      emlrtNonNegativeCheckR2012b(d, &o_emlrtDCI, (emlrtCTX)sp);
    }
    if (d != d1) {
      emlrtIntegerCheckR2012b(d, &n_emlrtDCI, (emlrtCTX)sp);
    }
    conv_out.set_size(&p_emlrtRTEI, sp, static_cast<int32_T>(d),
                      conv_out.size(1));
    if (!(n_kernels >= 0.0)) {
      emlrtNonNegativeCheckR2012b(n_kernels, &q_emlrtDCI, (emlrtCTX)sp);
    }
    if (n_kernels != d2) {
      emlrtIntegerCheckR2012b(n_kernels, &p_emlrtDCI, (emlrtCTX)sp);
    }
    conv_out.set_size(&p_emlrtRTEI, sp, conv_out.size(0),
                      static_cast<int32_T>(n_kernels));
    if (d != d1) {
      emlrtIntegerCheckR2012b(d, &t_emlrtDCI, (emlrtCTX)sp);
    }
    if (n_kernels != d2) {
      emlrtIntegerCheckR2012b(n_kernels, &t_emlrtDCI, (emlrtCTX)sp);
    }
    for (k = 0; k < loop_ub; k++) {
      conv_out[k] = 0.0;
    }
    //  First convolution
    emlrtForLoopVectorCheckR2021a(
        1.0, 1.0, (64.0 - kernel_sizes[0]) + 1.0, mxDOUBLE_CLASS,
        static_cast<int32_T>((64.0 - kernel_sizes[0]) + 1.0), &b_emlrtRTEI,
        (emlrtCTX)sp);
    if (0 <= static_cast<int32_T>((64.0 - kernel_sizes[0]) + 1.0) - 1) {
      iv[0] = 1;
      iv[1] = 32;
    }
    if (0 <= i1 - 1) {
      c_loop_ub = static_cast<int32_T>(kernel_sizes[1] + 1.0);
      iv1[0] = 1;
    }
    for (b_i = 0; b_i < i1; b_i++) {
      b = ((static_cast<real_T>(b_i) + 1.0) + kernel_sizes[0]) - 1.0;
      if (static_cast<real_T>(b_i) + 1.0 > b) {
        k = -2;
        m = -1;
      } else {
        if ((static_cast<int32_T>(b_i + 1U) < 1) ||
            (static_cast<int32_T>(b_i + 1U) > 64)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1, 64,
                                        &j_emlrtBCI, (emlrtCTX)sp);
        }
        k = b_i - 2;
        if (b != static_cast<int32_T>(muDoubleScalarFloor(b))) {
          emlrtIntegerCheckR2012b(b, &k_emlrtDCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(b) < 1) || (static_cast<int32_T>(b) > 64)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b), 1, 64,
                                        &i_emlrtBCI, (emlrtCTX)sp);
        }
        m = static_cast<int32_T>(b) - 1;
      }
      if (!(kernel_sizes[1] + 1.0 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(kernel_sizes[1] + 1.0, &j_emlrtDCI,
                                    (emlrtCTX)sp);
      }
      if (kernel_sizes[1] + 1.0 !=
          static_cast<int32_T>(muDoubleScalarFloor(kernel_sizes[1] + 1.0))) {
        emlrtIntegerCheckR2012b(kernel_sizes[1] + 1.0, &i_emlrtDCI,
                                (emlrtCTX)sp);
      }
      n = m - k;
      maxval.set_size(&q_emlrtRTEI, sp, 1,
                      n + static_cast<int32_T>(kernel_sizes[1] + 1.0));
      maxval[0] = 1.0;
      for (j = 0; j <= n - 2; j++) {
        maxval[j + 1] = test_data[((k + j) + (sample_idx << 6)) + 2];
      }
      for (j = 0; j < c_loop_ub; j++) {
        maxval[(j + m) - k] = 0.0;
      }
      st.site = &m_emlrtRSI;
      c_voltage_deg_model_sparse_cond(SD, &st, tile_1, maxval, a__1, I_temp,
                                      &conv_outstep);
      for (k = 0; k < 64; k++) {
        I_temp[k] = (I_temp[k] - rmaxlimit[0]) / rminlimit[0];
      }
      if (1 > conv_out.size(1)) {
        n = 0;
      } else {
        n = conv_out.size(1);
      }
      if ((b_i + 1 < 1) || (b_i + 1 > conv_out.size(0))) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, conv_out.size(0), &f_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      iv1[1] = n;
      emlrtSubAssignSizeCheckR2012b(&iv1[0], 2, &iv[0], 2, &h_emlrtECI,
                                    (emlrtCTX)sp);
      for (k = 0; k < 32; k++) {
        m = k << 1;
        b_I_temp[k] = I_temp[m] - I_temp[m + 1];
      }
      for (k = 0; k < n; k++) {
        conv_out[b_i + conv_out.size(0) * k] = b_I_temp[k];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    //  Second convolution
    emlrtForLoopVectorCheckR2021a(
        1.0, 1.0, (64.0 - kernel_sizes[1]) + 1.0, mxDOUBLE_CLASS,
        static_cast<int32_T>((64.0 - kernel_sizes[1]) + 1.0), &emlrtRTEI,
        (emlrtCTX)sp);
    if (0 <= static_cast<int32_T>((64.0 - kernel_sizes[1]) + 1.0) - 1) {
      iv[0] = 1;
      iv[1] = 32;
    }
    if (0 <= i2 - 1) {
      d_loop_ub = static_cast<int32_T>(kernel_sizes[0] + 1.0);
      iv1[0] = 1;
    }
    for (b_i = 0; b_i < i2; b_i++) {
      b = ((static_cast<real_T>(b_i) + 1.0) + kernel_sizes[1]) - 1.0;
      if (static_cast<real_T>(b_i) + 1.0 > b) {
        k = -2;
        m = -1;
      } else {
        if ((static_cast<int32_T>(b_i + 1U) < 1) ||
            (static_cast<int32_T>(b_i + 1U) > 64)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1, 64,
                                        &h_emlrtBCI, (emlrtCTX)sp);
        }
        k = b_i - 2;
        if (b != static_cast<int32_T>(muDoubleScalarFloor(b))) {
          emlrtIntegerCheckR2012b(b, &h_emlrtDCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(b) < 1) || (static_cast<int32_T>(b) > 64)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b), 1, 64,
                                        &g_emlrtBCI, (emlrtCTX)sp);
        }
        m = static_cast<int32_T>(b) - 1;
      }
      if (!(kernel_sizes[0] + 1.0 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(kernel_sizes[0] + 1.0, &g_emlrtDCI,
                                    (emlrtCTX)sp);
      }
      if (kernel_sizes[0] + 1.0 !=
          static_cast<int32_T>(muDoubleScalarFloor(kernel_sizes[0] + 1.0))) {
        emlrtIntegerCheckR2012b(kernel_sizes[0] + 1.0, &f_emlrtDCI,
                                (emlrtCTX)sp);
      }
      n = m - k;
      maxval.set_size(&r_emlrtRTEI, sp, 1,
                      n + static_cast<int32_T>(kernel_sizes[0] + 1.0));
      maxval[0] = 1.0;
      for (j = 0; j <= n - 2; j++) {
        maxval[j + 1] = test_data[((k + j) + (sample_idx << 6)) + 2];
      }
      for (j = 0; j < d_loop_ub; j++) {
        maxval[(j + m) - k] = 0.0;
      }
      st.site = &l_emlrtRSI;
      c_voltage_deg_model_sparse_cond(SD, &st, tile_2, maxval, a__1, I_temp,
                                      &conv_outstep);
      for (k = 0; k < 64; k++) {
        I_temp[k] = (I_temp[k] - rmaxlimit[1]) / rminlimit[1];
      }
      if (1 > conv_out.size(1)) {
        n = 0;
      } else {
        n = conv_out.size(1);
      }
      b = (((static_cast<real_T>(b_i) + 1.0) + 64.0) - kernel_sizes[0]) + 1.0;
      if (b != static_cast<int32_T>(muDoubleScalarFloor(b))) {
        emlrtIntegerCheckR2012b(b, &e_emlrtDCI, (emlrtCTX)sp);
      }
      if ((static_cast<int32_T>(b) < 1) ||
          (static_cast<int32_T>(b) > conv_out.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b), 1,
                                      conv_out.size(0), &e_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      iv1[1] = n;
      emlrtSubAssignSizeCheckR2012b(&iv1[0], 2, &iv[0], 2, &g_emlrtECI,
                                    (emlrtCTX)sp);
      for (k = 0; k < 32; k++) {
        m = k << 1;
        b_I_temp[k] = I_temp[m] - I_temp[m + 1];
      }
      for (k = 0; k < n; k++) {
        conv_out[(static_cast<int32_T>(b) + conv_out.size(0) * k) - 1] =
            b_I_temp[k];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    //  Implement output resolution
    st.site = &k_emlrtRSI;
    b_st.site = &id_emlrtRSI;
    c_st.site = &jd_emlrtRSI;
    d_st.site = &kd_emlrtRSI;
    if ((conv_out.size(0) == 1) && (conv_out.size(1) != 1)) {
      emlrtErrorWithMessageIdR2018a(&d_st, &d_emlrtRTEI,
                                    "Coder:toolbox:autoDimIncompatibility",
                                    "Coder:toolbox:autoDimIncompatibility", 0);
    }
    if (conv_out.size(0) < 1) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &e_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    e_st.site = &ld_emlrtRSI;
    f_st.site = &md_emlrtRSI;
    g_st.site = &nd_emlrtRSI;
    m = conv_out.size(0);
    n = conv_out.size(1);
    maxval.set_size(&s_emlrtRTEI, &g_st, 1, conv_out.size(1));
    if (conv_out.size(1) >= 1) {
      h_st.site = &pd_emlrtRSI;
      if (conv_out.size(1) > 2147483646) {
        i_st.site = &ib_emlrtRSI;
        coder::check_forloop_overflow_error(&i_st);
      }
      for (j = 0; j < n; j++) {
        maxval[j] = conv_out[conv_out.size(0) * j];
        h_st.site = &od_emlrtRSI;
        if ((2 <= m) && (m > 2147483646)) {
          i_st.site = &ib_emlrtRSI;
          coder::check_forloop_overflow_error(&i_st);
        }
        for (b_i = 2; b_i <= m; b_i++) {
          conv_outstep = maxval[j];
          b = conv_out[(b_i + conv_out.size(0) * j) - 1];
          if (muDoubleScalarIsNaN(b)) {
            p = false;
          } else if (muDoubleScalarIsNaN(conv_outstep)) {
            p = true;
          } else {
            p = (conv_outstep < b);
          }
          if (p) {
            maxval[j] = b;
          }
        }
      }
    }
    st.site = &k_emlrtRSI;
    b_st.site = &id_emlrtRSI;
    c_st.site = &jd_emlrtRSI;
    d_st.site = &kd_emlrtRSI;
    if (maxval.size(1) < 1) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &e_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    e_st.site = &qd_emlrtRSI;
    f_st.site = &rd_emlrtRSI;
    m = maxval.size(1);
    if (maxval.size(1) <= 2) {
      if (maxval.size(1) == 1) {
        dense2_out_idx_0 = maxval[0];
      } else if ((maxval[0] < maxval[1]) ||
                 (muDoubleScalarIsNaN(maxval[0]) &&
                  (!muDoubleScalarIsNaN(maxval[1])))) {
        dense2_out_idx_0 = maxval[1];
      } else {
        dense2_out_idx_0 = maxval[0];
      }
    } else {
      g_st.site = &bc_emlrtRSI;
      if (!muDoubleScalarIsNaN(maxval[0])) {
        n = 1;
      } else {
        n = 0;
        h_st.site = &cc_emlrtRSI;
        if (maxval.size(1) > 2147483646) {
          i_st.site = &ib_emlrtRSI;
          coder::check_forloop_overflow_error(&i_st);
        }
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= m)) {
          if (!muDoubleScalarIsNaN(maxval[k - 1])) {
            n = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (n == 0) {
        dense2_out_idx_0 = maxval[0];
      } else {
        g_st.site = &ac_emlrtRSI;
        dense2_out_idx_0 = maxval[n - 1];
        j = n + 1;
        h_st.site = &dc_emlrtRSI;
        if ((n + 1 <= maxval.size(1)) && (maxval.size(1) > 2147483646)) {
          i_st.site = &ib_emlrtRSI;
          coder::check_forloop_overflow_error(&i_st);
        }
        for (k = j; k <= m; k++) {
          b = maxval[k - 1];
          if (dense2_out_idx_0 < b) {
            dense2_out_idx_0 = b;
          }
        }
      }
    }
    st.site = &k_emlrtRSI;
    b_st.site = &sd_emlrtRSI;
    c_st.site = &td_emlrtRSI;
    d_st.site = &ud_emlrtRSI;
    if ((conv_out.size(0) == 1) && (conv_out.size(1) != 1)) {
      emlrtErrorWithMessageIdR2018a(&d_st, &d_emlrtRTEI,
                                    "Coder:toolbox:autoDimIncompatibility",
                                    "Coder:toolbox:autoDimIncompatibility", 0);
    }
    e_st.site = &ld_emlrtRSI;
    f_st.site = &md_emlrtRSI;
    g_st.site = &nd_emlrtRSI;
    m = conv_out.size(0);
    n = conv_out.size(1);
    maxval.set_size(&s_emlrtRTEI, &g_st, 1, conv_out.size(1));
    if (conv_out.size(1) >= 1) {
      h_st.site = &pd_emlrtRSI;
      for (j = 0; j < n; j++) {
        maxval[j] = conv_out[conv_out.size(0) * j];
        h_st.site = &od_emlrtRSI;
        if ((2 <= m) && (m > 2147483646)) {
          i_st.site = &ib_emlrtRSI;
          coder::check_forloop_overflow_error(&i_st);
        }
        for (b_i = 2; b_i <= m; b_i++) {
          conv_outstep = maxval[j];
          b = conv_out[(b_i + conv_out.size(0) * j) - 1];
          if (muDoubleScalarIsNaN(b)) {
            p = false;
          } else if (muDoubleScalarIsNaN(conv_outstep)) {
            p = true;
          } else {
            p = (conv_outstep > b);
          }
          if (p) {
            maxval[j] = b;
          }
        }
      }
    }
    st.site = &k_emlrtRSI;
    b_st.site = &sd_emlrtRSI;
    c_st.site = &td_emlrtRSI;
    d_st.site = &ud_emlrtRSI;
    if (maxval.size(1) < 1) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &e_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    e_st.site = &vd_emlrtRSI;
    f_st.site = &yb_emlrtRSI;
    m = maxval.size(1);
    if (maxval.size(1) <= 2) {
      if (maxval.size(1) == 1) {
        conv_outstep = maxval[0];
      } else if ((maxval[0] > maxval[1]) ||
                 (muDoubleScalarIsNaN(maxval[0]) &&
                  (!muDoubleScalarIsNaN(maxval[1])))) {
        conv_outstep = maxval[1];
      } else {
        conv_outstep = maxval[0];
      }
    } else {
      g_st.site = &bc_emlrtRSI;
      if (!muDoubleScalarIsNaN(maxval[0])) {
        n = 1;
      } else {
        n = 0;
        h_st.site = &cc_emlrtRSI;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= m)) {
          if (!muDoubleScalarIsNaN(maxval[k - 1])) {
            n = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (n == 0) {
        conv_outstep = maxval[0];
      } else {
        g_st.site = &ac_emlrtRSI;
        conv_outstep = maxval[n - 1];
        j = n + 1;
        h_st.site = &dc_emlrtRSI;
        for (k = j; k <= m; k++) {
          b = maxval[k - 1];
          if (conv_outstep > b) {
            conv_outstep = b;
          }
        }
      }
    }
    conv_outstep = (dense2_out_idx_0 - conv_outstep) / 63.0;
    n = conv_out.size(0) * conv_out.size(1);
    for (k = 0; k < n; k++) {
      conv_out[k] = conv_out[k] / conv_outstep;
    }
    st.site = &j_emlrtRSI;
    coder::b_round(&st, conv_out);
    n = conv_out.size(0) * conv_out.size(1);
    for (k = 0; k < n; k++) {
      conv_out[k] = conv_out[k] * conv_outstep;
    }
    //  Apply ReLU
    m = conv_out.size(0) * conv_out.size(1) - 1;
    j = 0;
    for (b_i = 0; b_i <= m; b_i++) {
      if (conv_out[b_i] < 0.0) {
        j++;
      }
    }
    r.set_size(&t_emlrtRTEI, sp, j);
    n = 0;
    for (b_i = 0; b_i <= m; b_i++) {
      if (conv_out[b_i] < 0.0) {
        r[n] = b_i + 1;
        n++;
      }
    }
    n = r.size(0) - 1;
    m = conv_out.size(0) * conv_out.size(1);
    for (k = 0; k <= n; k++) {
      if ((r[k] < 1) || (r[k] > m)) {
        emlrtDynamicBoundsCheckR2012b(r[k], 1, m, &l_emlrtBCI, (emlrtCTX)sp);
      }
      conv_out[r[k] - 1] = 0.0;
    }
    //  Forward operation for tile 8 (avgerage pooling)
    std::memset(&avgpool_out[0], 0, 1088U * sizeof(real_T));
    for (b_i = 0; b_i < 34; b_i++) {
      m = (b_i << 1) + 1;
      for (j = 0; j < 32; j++) {
        if (m == 1) {
          if (1 > conv_out.size(0)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, conv_out.size(0), &d_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          if (2 > conv_out.size(0)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, conv_out.size(0), &c_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          if (j + 1 > conv_out.size(1)) {
            emlrtDynamicBoundsCheckR2012b(j + 1, 1, conv_out.size(1),
                                          &o_emlrtBCI, (emlrtCTX)sp);
          }
          avgpool_out[34 * j] = 0.5 * conv_out[conv_out.size(0) * j] +
                                0.5 * conv_out[conv_out.size(0) * j + 1];
        } else {
          if (m > conv_out.size(0)) {
            emlrtDynamicBoundsCheckR2012b(m, 1, conv_out.size(0), &m_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          if (j + 1 > conv_out.size(1)) {
            emlrtDynamicBoundsCheckR2012b(j + 1, 1, conv_out.size(1),
                                          &m_emlrtBCI, (emlrtCTX)sp);
          }
          if (m + 1 > conv_out.size(0)) {
            emlrtDynamicBoundsCheckR2012b(m + 1, 1, conv_out.size(0),
                                          &n_emlrtBCI, (emlrtCTX)sp);
          }
          if (j + 1 > conv_out.size(1)) {
            emlrtDynamicBoundsCheckR2012b(j + 1, 1, conv_out.size(1),
                                          &n_emlrtBCI, (emlrtCTX)sp);
          }
          b = (static_cast<real_T>(m) + 1.0) / 2.0;
          if (b != muDoubleScalarFloor(b)) {
            emlrtIntegerCheckR2012b(b, &u_emlrtDCI, (emlrtCTX)sp);
          }
          avgpool_out[(static_cast<int32_T>(b) + 34 * j) - 1] =
              0.5 * conv_out[(m + conv_out.size(0) * j) - 1] +
              0.5 * conv_out[m + conv_out.size(0) * j];
        }
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtCTX)sp);
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    //  Apply ReLU
    for (b_i = 0; b_i < 1088; b_i++) {
      if (avgpool_out[b_i] < 0.0) {
        avgpool_out[b_i] = 0.0;
      }
    }
    //  Forward operation for tile 3-7 (first dense layer with 8 neurons)
    //  Reformat the output from previous layer
    std::memset(&total[0], 0, 16U * sizeof(real_T));
    for (b_i = 0; b_i < 17; b_i++) {
      // 1088/64=17
      if (b_i + 1 <= 4) {
        k = b_i << 6;
        m = (b_i + 1) << 6;
        if (k + 1 > m) {
          k = 0;
          m = 0;
        }
        n = m - k;
        for (m = 0; m < n; m++) {
          avgpool_out_data[m] = avgpool_out[k + m];
        }
        st.site = &i_emlrtRSI;
        c_voltage_deg_model_sparse_cond(SD, &st, dense1a, avgpool_out_data, n,
                                        a__1, I_temp, &conv_outstep);
        k = (b_i + 1) << 1;
        m = reading[k - 2];
        k = reading[k - 1];
        if (m > k) {
          m = 0;
          k = 0;
        } else {
          m--;
        }
        tempI_size[0] = 1;
        n = k - m;
        tempI_size[1] = static_cast<int8_T>(n);
        for (k = 0; k < n; k++) {
          tempI_data[k] = (I_temp[m + k] - rmaxlimit[2]) / rminlimit[2];
        }
        iv1[0] = 1;
        iv1[1] = 16;
        iv[0] = tempI_size[0];
        iv[1] = tempI_size[1];
        emlrtSizeEqCheckNDR2012b(&iv1[0], &iv[0], &f_emlrtECI, (emlrtCTX)sp);
        for (k = 0; k < 16; k++) {
          total[k] += tempI_data[k];
        }
      } else if (b_i + 1 <= 8) {
        k = b_i << 6;
        m = (b_i + 1) << 6;
        if (k + 1 > m) {
          k = 0;
          m = 0;
        }
        n = m - k;
        for (m = 0; m < n; m++) {
          b_avgpool_out_data[m] = avgpool_out[k + m];
        }
        st.site = &h_emlrtRSI;
        c_voltage_deg_model_sparse_cond(SD, &st, dense1b, b_avgpool_out_data, n,
                                        a__1, I_temp, &conv_outstep);
        k = (b_i + 1) << 1;
        m = reading[k - 2];
        k = reading[k - 1];
        if (m > k) {
          m = 0;
          k = 0;
        } else {
          m--;
        }
        tempI_size[0] = 1;
        n = k - m;
        tempI_size[1] = static_cast<int8_T>(n);
        for (k = 0; k < n; k++) {
          tempI_data[k] = (I_temp[m + k] - rmaxlimit[3]) / rminlimit[3];
        }
        iv1[0] = 1;
        iv1[1] = 16;
        iv[0] = tempI_size[0];
        iv[1] = tempI_size[1];
        emlrtSizeEqCheckNDR2012b(&iv1[0], &iv[0], &e_emlrtECI, (emlrtCTX)sp);
        for (k = 0; k < 16; k++) {
          total[k] += tempI_data[k];
        }
      } else if (b_i + 1 <= 12) {
        k = b_i << 6;
        m = (b_i + 1) << 6;
        if (k + 1 > m) {
          k = 0;
          m = 0;
        }
        n = m - k;
        for (m = 0; m < n; m++) {
          c_avgpool_out_data[m] = avgpool_out[k + m];
        }
        st.site = &g_emlrtRSI;
        c_voltage_deg_model_sparse_cond(SD, &st, dense1c, c_avgpool_out_data, n,
                                        a__1, I_temp, &conv_outstep);
        k = reading[((b_i + 1) << 1) - 2];
        m = reading[((b_i + 1) << 1) - 1];
        if (k > m) {
          k = 0;
          m = 0;
        } else {
          k--;
        }
        tempI_size[0] = 1;
        n = m - k;
        tempI_size[1] = static_cast<int8_T>(n);
        for (m = 0; m < n; m++) {
          tempI_data[m] = (I_temp[k + m] - rmaxlimit[4]) / rminlimit[4];
        }
        iv1[0] = 1;
        iv1[1] = 16;
        iv[0] = tempI_size[0];
        iv[1] = tempI_size[1];
        emlrtSizeEqCheckNDR2012b(&iv1[0], &iv[0], &d_emlrtECI, (emlrtCTX)sp);
        for (k = 0; k < 16; k++) {
          total[k] += tempI_data[k];
        }
      } else if (b_i + 1 <= 16) {
        k = b_i << 6;
        m = (b_i + 1) << 6;
        if (k + 1 > m) {
          k = 0;
          m = 0;
        }
        n = m - k;
        for (m = 0; m < n; m++) {
          d_avgpool_out_data[m] = avgpool_out[k + m];
        }
        st.site = &f_emlrtRSI;
        c_voltage_deg_model_sparse_cond(SD, &st, dense1d, d_avgpool_out_data, n,
                                        a__1, I_temp, &conv_outstep);
        k = reading[((b_i + 1) << 1) - 2];
        m = reading[((b_i + 1) << 1) - 1];
        if (k > m) {
          k = 0;
          m = 0;
        } else {
          k--;
        }
        tempI_size[0] = 1;
        n = m - k;
        tempI_size[1] = static_cast<int8_T>(n);
        for (m = 0; m < n; m++) {
          tempI_data[m] = (I_temp[k + m] - rmaxlimit[5]) / rminlimit[5];
        }
        iv1[0] = 1;
        iv1[1] = 16;
        iv[0] = tempI_size[0];
        iv[1] = tempI_size[1];
        emlrtSizeEqCheckNDR2012b(&iv1[0], &iv[0], &c_emlrtECI, (emlrtCTX)sp);
        for (k = 0; k < 16; k++) {
          total[k] += tempI_data[k];
        }
      } else {
        std::copy(&avgpool_out[1024], &avgpool_out[1088], &tempI_data[0]);
        st.site = &e_emlrtRSI;
        c_voltage_deg_model_sparse_cond(SD, &st, dense1e, tempI_data, 64, a__1,
                                        I_temp, &conv_outstep);
        tempI_size[0] = 1;
        tempI_size[1] = 16;
        for (k = 0; k < 16; k++) {
          tempI_data[k] = (I_temp[k] - rmaxlimit[6]) / rminlimit[6];
        }
        iv1[0] = 1;
        iv1[1] = 16;
        iv[0] = tempI_size[0];
        iv[1] = tempI_size[1];
        emlrtSizeEqCheckNDR2012b(&iv1[0], &iv[0], &b_emlrtECI, (emlrtCTX)sp);
        for (k = 0; k < 16; k++) {
          total[k] += tempI_data[k];
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    //  Add bias
    for (k = 0; k < 16; k++) {
      total[k] += dense1b_diff[k];
    }
    //  Implement output resolution
    st.site = &d_emlrtRSI;
    b_st.site = &id_emlrtRSI;
    c_st.site = &jd_emlrtRSI;
    d_st.site = &kd_emlrtRSI;
    e_st.site = &qd_emlrtRSI;
    f_st.site = &rd_emlrtRSI;
    g_st.site = &bc_emlrtRSI;
    p = muDoubleScalarIsNaN(total[0]);
    if (!p) {
      n = 1;
    } else {
      n = 0;
      h_st.site = &cc_emlrtRSI;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= 16)) {
        if (!muDoubleScalarIsNaN(total[k - 1])) {
          n = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (n == 0) {
      dense2_out_idx_0 = total[0];
    } else {
      g_st.site = &ac_emlrtRSI;
      dense2_out_idx_0 = total[n - 1];
      j = n + 1;
      h_st.site = &dc_emlrtRSI;
      for (k = j; k < 17; k++) {
        b = total[k - 1];
        if (dense2_out_idx_0 < b) {
          dense2_out_idx_0 = b;
        }
      }
    }
    st.site = &d_emlrtRSI;
    b_st.site = &sd_emlrtRSI;
    c_st.site = &td_emlrtRSI;
    d_st.site = &ud_emlrtRSI;
    e_st.site = &vd_emlrtRSI;
    f_st.site = &yb_emlrtRSI;
    g_st.site = &bc_emlrtRSI;
    if (!p) {
      n = 1;
    } else {
      n = 0;
      h_st.site = &cc_emlrtRSI;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= 16)) {
        if (!muDoubleScalarIsNaN(total[k - 1])) {
          n = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (n == 0) {
      conv_outstep = total[0];
    } else {
      g_st.site = &ac_emlrtRSI;
      conv_outstep = total[n - 1];
      j = n + 1;
      h_st.site = &dc_emlrtRSI;
      for (k = j; k < 17; k++) {
        b = total[k - 1];
        if (conv_outstep > b) {
          conv_outstep = b;
        }
      }
    }
    conv_outstep = (dense2_out_idx_0 - conv_outstep) / 63.0;
    for (k = 0; k < 16; k++) {
      total[k] = muDoubleScalarRound(total[k] / conv_outstep) * conv_outstep;
    }
    //  Convert back from differential form and apply relu
    //  Forward operation for 1 (second dense layer with 2 neurons)
    if (!(kernel_sizes[0] + 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(kernel_sizes[0] + 1.0, &d_emlrtDCI,
                                  (emlrtCTX)sp);
    }
    if (kernel_sizes[0] + 1.0 !=
        static_cast<int32_T>(muDoubleScalarFloor(kernel_sizes[0] + 1.0))) {
      emlrtIntegerCheckR2012b(kernel_sizes[0] + 1.0, &c_emlrtDCI, (emlrtCTX)sp);
    }
    if (!(56.0 - kernel_sizes[0] >= 0.0)) {
      emlrtNonNegativeCheckR2012b(56.0 - kernel_sizes[0], &b_emlrtDCI,
                                  (emlrtCTX)sp);
    }
    if (56.0 - kernel_sizes[0] !=
        static_cast<int32_T>(muDoubleScalarFloor(56.0 - kernel_sizes[0]))) {
      emlrtIntegerCheckR2012b(56.0 - kernel_sizes[0], &emlrtDCI, (emlrtCTX)sp);
    }
    iv[1] = static_cast<int32_T>(56.0 - kernel_sizes[0]);
    maxval.set_size(&u_emlrtRTEI, sp, 1,
                    (static_cast<int32_T>(kernel_sizes[0] + 1.0) +
                     static_cast<int32_T>(56.0 - kernel_sizes[0])) +
                        8);
    for (k = 0; k < b_loop_ub; k++) {
      maxval[k] = 0.0;
    }
    for (k = 0; k < 8; k++) {
      m = k << 1;
      maxval[k + static_cast<int32_T>(d3 + 1.0)] = total[m] - total[m + 1];
    }
    for (k = 0; k < loop_ub_tmp; k++) {
      maxval[(k + static_cast<int32_T>(d3 + 1.0)) + 8] = 0.0;
    }
    st.site = &c_emlrtRSI;
    c_voltage_deg_model_sparse_cond(SD, &st, tile_1, maxval, a__1, I_temp,
                                    &conv_outstep);
    dense2_out_idx_0 = ((I_temp[0] - rmaxlimit[0]) / rminlimit[0] -
                        (I_temp[1] - rmaxlimit[0]) / rminlimit[0]) +
                       dense2b[0];
    dense2_out_idx_1 = ((I_temp[2] - rmaxlimit[0]) / rminlimit[0] -
                        (I_temp[3] - rmaxlimit[0]) / rminlimit[0]) +
                       dense2b[1];
    //  Implement output resolution
    st.site = &b_emlrtRSI;
    b_st.site = &id_emlrtRSI;
    c_st.site = &jd_emlrtRSI;
    d_st.site = &kd_emlrtRSI;
    e_st.site = &qd_emlrtRSI;
    f_st.site = &rd_emlrtRSI;
    if ((dense2_out_idx_0 < dense2_out_idx_1) ||
        (muDoubleScalarIsNaN(dense2_out_idx_0) &&
         (!muDoubleScalarIsNaN(dense2_out_idx_1)))) {
      conv_outstep = dense2_out_idx_1;
    } else {
      conv_outstep = dense2_out_idx_0;
    }
    st.site = &b_emlrtRSI;
    b_st.site = &sd_emlrtRSI;
    c_st.site = &td_emlrtRSI;
    d_st.site = &ud_emlrtRSI;
    e_st.site = &vd_emlrtRSI;
    f_st.site = &yb_emlrtRSI;
    if ((dense2_out_idx_0 > dense2_out_idx_1) ||
        (muDoubleScalarIsNaN(dense2_out_idx_0) &&
         (!muDoubleScalarIsNaN(dense2_out_idx_1)))) {
      b = dense2_out_idx_1;
    } else {
      b = dense2_out_idx_0;
    }
    conv_outstep = (conv_outstep - b) / 63.0;
    dense2_out_idx_0 =
        muDoubleScalarRound(dense2_out_idx_0 / conv_outstep) * conv_outstep;
    dense2_out_idx_1 =
        muDoubleScalarRound(dense2_out_idx_1 / conv_outstep) * conv_outstep;
    //  Convert to final prediction
    if ((dense2_out_idx_0 < dense2_out_idx_1) ||
        (muDoubleScalarIsNaN(dense2_out_idx_0) &&
         (!muDoubleScalarIsNaN(dense2_out_idx_1)))) {
      m = 2;
    } else {
      m = 1;
    }
    if ((static_cast<int32_T>(sample_idx + 1U) < 1) ||
        (static_cast<int32_T>(sample_idx + 1U) > out.size(1))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(sample_idx + 1U), 1,
                                    out.size(1), &p_emlrtBCI, (emlrtCTX)sp);
    }
    out[sample_idx] = static_cast<real_T>(m) - 1.0;
    //  List comparison and calculate accuracy
    if (1 > out.size(1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, out.size(1), &b_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if ((sample_idx + 1 < 1) || (sample_idx + 1 > out.size(1))) {
      emlrtDynamicBoundsCheckR2012b(sample_idx + 1, 1, out.size(1), &emlrtBCI,
                                    (emlrtCTX)sp);
    }
    dif_size[0] = 1;
    dif_size[1] = sample_idx + 1;
    test_labels_size[1] = sample_idx + 1;
    emlrtSizeEqCheckNDR2012b(&dif_size[0], &test_labels_size[0], &emlrtECI,
                             (emlrtCTX)sp);
    dif_size[0] = 1;
    dif_size[1] = sample_idx + 1;
    j = 0;
    n = 0;
    for (b_i = 0; b_i <= sample_idx; b_i++) {
      b = test_labels[b_i];
      conv_outstep = out[b_i] - b;
      dif_data[b_i] = conv_outstep;
      if (conv_outstep < 0.0) {
        j++;
      }
      if (out[b_i] - b < 0.0) {
        tmp_data[n] = static_cast<int16_T>(b_i + 1);
        n++;
      }
    }
    for (k = 0; k < j; k++) {
      int16_T i3;
      i3 = tmp_data[k];
      if ((i3 < 1) || (i3 > sample_idx + 1)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(i3), 1,
                                      sample_idx + 1, &q_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      dif_data[tmp_data[k] - 1] = 1.0;
    }
    st.site = &emlrtRSI;
    conv_outstep = (static_cast<real_T>(out.size(1)) -
                    coder::sum(&st, dif_data, dif_size)) /
                   static_cast<real_T>(out.size(1));
    st.site = &be_emlrtRSI;
    disp(&st, emlrt_marshallOut(conv_outstep), &b_emlrtMCI);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (inference_routine.cpp)
