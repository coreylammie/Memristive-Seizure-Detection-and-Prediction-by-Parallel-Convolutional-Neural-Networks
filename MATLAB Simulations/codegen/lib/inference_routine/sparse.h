//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sparse.h
//
// Code generation for function 'sparse'
//

#ifndef SPARSE_H
#define SPARSE_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class sparse;

class b_sparse;

} // namespace coder

// Function Declarations
namespace coder {
void c_sparse(const double varargin_1[32512], const double varargin_2[32512],
              const double varargin_3[32512], sparse *y);

void c_sparse(const double varargin_1[128], const double varargin_2[128],
              const double varargin_3[128], b_sparse *y);

} // namespace coder

#endif
// End of code generation (sparse.h)
