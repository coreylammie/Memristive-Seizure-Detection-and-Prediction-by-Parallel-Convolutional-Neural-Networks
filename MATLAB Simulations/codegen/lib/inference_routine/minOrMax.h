//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// minOrMax.h
//
// Code generation for function 'minOrMax'
//

#ifndef MINORMAX_H
#define MINORMAX_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
double b_maximum(const double x[2]);

double b_minimum(const double x[16]);

double maximum(const ::coder::array<double, 2U> &x);

double maximum(const double x[16]);

void minimum(const ::coder::array<double, 2U> &x,
             ::coder::array<double, 2U> &ex);

double minimum(const ::coder::array<double, 2U> &x);

double minimum(const double x[2]);

} // namespace internal
} // namespace coder

#endif
// End of code generation (minOrMax.h)
