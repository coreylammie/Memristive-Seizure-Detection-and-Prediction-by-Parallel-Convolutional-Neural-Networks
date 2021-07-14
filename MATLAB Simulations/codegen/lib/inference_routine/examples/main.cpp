//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// main.cpp
//
// Code generation for function 'main'
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include files
#include "main.h"
#include "inference_routine.h"
#include "inference_routine_terminate.h"
#include "coder_array.h"

// Function Declarations
static void argInit_1x16_real_T(double result[16]);

static void argInit_1x2560_real_T(double result[2560]);

static void argInit_1x2_real_T(double result[2]);

static void argInit_1x8_real_T(double result[8]);

static void argInit_64x2560_real_T(double result[163840]);

static void argInit_64x64_real_T(double result[4096]);

static double argInit_real_T();

static void main_inference_routine();

// Function Definitions
static void argInit_1x16_real_T(double result[16])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 16; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

static void argInit_1x2560_real_T(double result[2560])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 2560; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

static void argInit_1x2_real_T(double result[2])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 2; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

static void argInit_1x8_real_T(double result[8])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 8; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

static void argInit_64x2560_real_T(double result[163840])
{
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 64; idx0++) {
    for (int idx1{0}; idx1 < 2560; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + (idx1 << 6)] = argInit_real_T();
    }
  }
}

static void argInit_64x64_real_T(double result[4096])
{
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 64; idx0++) {
    for (int idx1{0}; idx1 < 64; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + (idx1 << 6)] = argInit_real_T();
    }
  }
}

static double argInit_real_T()
{
  return 0.0;
}

static void main_inference_routine()
{
  static double dv2[163840];
  coder::array<double, 2U> out;
  double tile_1_tmp[4096];
  double dv3[2560];
  double dv1[16];
  double dv[8];
  double kernel_sizes_tmp[2];
  double n_kernels_tmp;
  // Initialize function 'inference_routine' input arguments.
  // Initialize function input argument 'tile_1'.
  argInit_64x64_real_T(tile_1_tmp);
  // Initialize function input argument 'tile_2'.
  // Initialize function input argument 'max_weight'.
  n_kernels_tmp = argInit_real_T();
  // Initialize function input argument 'kernel_sizes'.
  argInit_1x2_real_T(kernel_sizes_tmp);
  // Initialize function input argument 'dense1a'.
  // Initialize function input argument 'dense1b'.
  // Initialize function input argument 'dense1c'.
  // Initialize function input argument 'dense1d'.
  // Initialize function input argument 'dense1e'.
  // Initialize function input argument 'dense1b_diff'.
  // Initialize function input argument 'dense2b'.
  // Initialize function input argument 'test_data'.
  // Initialize function input argument 'test_labels'.
  // Call the entry-point 'inference_routine'.
  argInit_1x8_real_T(dv);
  argInit_1x16_real_T(dv1);
  argInit_64x2560_real_T(dv2);
  argInit_1x2560_real_T(dv3);
  inference_routine(tile_1_tmp, tile_1_tmp, dv, n_kernels_tmp, kernel_sizes_tmp,
                    tile_1_tmp, tile_1_tmp, tile_1_tmp, tile_1_tmp, tile_1_tmp,
                    dv1, kernel_sizes_tmp, dv2, dv3, n_kernels_tmp, out);
}

int main(int, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_inference_routine();
  // Terminate the application.
  // You do not need to do this more than one time.
  inference_routine_terminate();
  return 0;
}

// End of code generation (main.cpp)
