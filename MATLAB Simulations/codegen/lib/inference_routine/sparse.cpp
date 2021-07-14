//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sparse.cpp
//
// Code generation for function 'sparse'
//

// Include files
#include "sparse.h"
#include "anonymous_function.h"
#include "introsort.h"
#include "sparse1.h"
#include "coder_array.h"
#include <algorithm>

// Function Definitions
namespace coder {
void c_sparse(const double varargin_1[32512], const double varargin_2[32512],
              const double varargin_3[32512], sparse *y)
{
  static int cidxInt[32512];
  static int ridxInt[32512];
  static int sortedIndices[32512];
  int c;
  int cptr;
  int i;
  for (cptr = 0; cptr < 32512; cptr++) {
    ridxInt[cptr] = static_cast<int>(varargin_1[cptr]);
    cidxInt[cptr] = static_cast<int>(varargin_2[cptr]);
    sortedIndices[cptr] = cptr + 1;
  }
  sparse::locSortrows(sortedIndices, cidxInt, ridxInt);
  y->d.set_size(32512);
  y->colidx.set_size(8193);
  y->colidx[0] = 1;
  y->rowidx.set_size(32512);
  for (i = 0; i < 32512; i++) {
    y->d[i] = 0.0;
    y->rowidx[i] = 0;
  }
  cptr = 0;
  for (c = 0; c < 8192; c++) {
    while ((cptr + 1 <= 32512) && (cidxInt[cptr] == c + 1)) {
      y->rowidx[cptr] = ridxInt[cptr];
      cptr++;
    }
    y->colidx[c + 1] = cptr + 1;
  }
  for (cptr = 0; cptr < 32512; cptr++) {
    y->d[cptr] = varargin_3[sortedIndices[cptr] - 1];
  }
  cptr = 1;
  for (c = 0; c < 8192; c++) {
    int ridx;
    ridx = y->colidx[c];
    y->colidx[c] = cptr;
    int exitg1;
    do {
      exitg1 = 0;
      i = y->colidx[c + 1];
      if (ridx < i) {
        double val;
        int currRowIdx;
        val = 0.0;
        currRowIdx = y->rowidx[ridx - 1];
        while ((ridx < i) && (y->rowidx[ridx - 1] == currRowIdx)) {
          val += y->d[ridx - 1];
          ridx++;
        }
        if (val != 0.0) {
          y->d[cptr - 1] = val;
          y->rowidx[cptr - 1] = currRowIdx;
          cptr++;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  y->colidx[8192] = cptr;
}

void c_sparse(const double varargin_1[128], const double varargin_2[128],
              const double varargin_3[128], b_sparse *y)
{
  anonymous_function b_this;
  int sortedIndices[128];
  int k;
  for (k = 0; k < 128; k++) {
    b_this.workspace.b[k] = static_cast<int>(varargin_1[k]);
    b_this.workspace.a[k] = static_cast<int>(varargin_2[k]);
    sortedIndices[k] = k + 1;
  }
  internal::introsort(sortedIndices, &b_this);
  std::copy(&b_this.workspace.b[0], &b_this.workspace.b[128],
            &b_this.workspace.a[0]);
  y->d.set_size(128);
  y->maxnz = 128;
  y->colidx.set_size(2);
  y->colidx[0] = 1;
  y->rowidx.set_size(128);
  for (k = 0; k < 128; k++) {
    int i;
    i = sortedIndices[k];
    b_this.workspace.b[k] = b_this.workspace.a[i - 1];
    y->d[k] = 0.0;
    y->rowidx[k] = 0;
    y->rowidx[k] = b_this.workspace.b[k];
    y->d[k] = varargin_3[i - 1];
  }
  y->colidx[1] = k + 1;
  y->fillIn();
}

} // namespace coder

// End of code generation (sparse.cpp)
