//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sparse1.h
//
// Code generation for function 'sparse1'
//

#ifndef SPARSE1_H
#define SPARSE1_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class b_sparse;

}

// Type Definitions
namespace coder {
class sparse {
public:
  void mldivide(const b_sparse *b, b_sparse *y) const;
  static void locSortrows(int idx[32512], int a[32512], int b[32512]);
  array<double, 1U> d;
  array<int, 1U> colidx;
  array<int, 1U> rowidx;
};

class b_sparse {
public:
  void parenReference(b_sparse *s) const;
  void fillIn();
  void parenAssign(const double rhs[8192]);
  array<double, 1U> d;
  array<int, 1U> colidx;
  array<int, 1U> rowidx;
  int maxnz;
};

} // namespace coder

#endif
// End of code generation (sparse1.h)
