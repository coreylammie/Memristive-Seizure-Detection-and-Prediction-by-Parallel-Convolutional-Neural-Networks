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
#include "eml_rand_mt19937ar_stateful.h"
#include "inference_routine_data.h"

// Function Definitions
void inference_routine_initialize()
{
  eml_rand_mt19937ar_stateful_init();
  isInitialized_inference_routine = true;
}

// End of code generation (inference_routine_initialize.cpp)
