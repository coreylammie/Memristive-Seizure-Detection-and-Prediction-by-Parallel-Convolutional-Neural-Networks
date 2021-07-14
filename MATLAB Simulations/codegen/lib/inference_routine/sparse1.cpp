//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sparse1.cpp
//
// Code generation for function 'sparse1'
//

// Include files
#include "sparse1.h"
#include "anonymous_function.h"
#include "introsort.h"
#include "coder_array.h"
#include "cs.h"
#include "makeCXSparseMatrix.h"
#include "solve_from_lu.h"
#include "solve_from_qr.h"
#include <algorithm>
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
void b_sparse::parenAssign(const double rhs[8192])
{
  int k;
  int n;
  int nz;
  int nzColAlloc;
  int nzRhs;
  n = this->colidx[this->colidx.size(0) - 1];
  nz = this->colidx[this->colidx.size(0) - 1] - 1;
  nzColAlloc = this->colidx[1] - this->colidx[0];
  nzRhs = 0;
  for (k = 0; k < 8192; k++) {
    if (!(rhs[k] == 0.0)) {
      nzRhs++;
    }
  }
  if (nzColAlloc < nzRhs) {
    int extraCol;
    int start;
    extraCol = (nzRhs - nzColAlloc) - 1;
    start = this->colidx[1];
    if (2 - this->colidx[this->colidx.size(0) - 1] < extraCol + 1) {
      nzColAlloc = extraCol + this->colidx[this->colidx.size(0) - 1];
      n = this->colidx[0];
      if (nzColAlloc > 8192) {
        nzColAlloc = 8192;
      }
      if (1 >= nzColAlloc) {
        nzColAlloc = 1;
      }
      this->rowidx.set_size(nzColAlloc);
      this->d.set_size(nzColAlloc);
      for (nzRhs = 0; nzRhs < nzColAlloc; nzRhs++) {
        this->rowidx[nzRhs] = 0;
        this->d[nzRhs] = 0.0;
      }
      this->maxnz = nzColAlloc;
      for (k = 0; k <= n - 2; k++) {
        this->rowidx[k] = 0;
        this->d[k] = 0.0;
      }
      for (k = start; k <= nz; k++) {
        nzRhs = k + extraCol;
        this->rowidx[nzRhs] = 0;
        this->d[nzRhs] = 0.0;
      }
    } else {
      nzColAlloc = this->colidx[1] + extraCol;
      nzRhs = this->colidx[this->colidx.size(0) - 1] - this->colidx[1];
      if (nzRhs > 0) {
        std::memmove((void *)&this->rowidx[nzColAlloc],
                     (void *)&this->rowidx[start - 1],
                     (unsigned int)((size_t)nzRhs * sizeof(int)));
        std::memmove((void *)&this->d[nzColAlloc], (void *)&this->d[start - 1],
                     (unsigned int)((size_t)nzRhs * sizeof(double)));
      }
    }
    nzColAlloc = this->colidx[0] - 1;
    for (k = 0; k < 8192; k++) {
      double b_d;
      b_d = rhs[k];
      if (b_d != 0.0) {
        this->rowidx[nzColAlloc] = k + 1;
        this->d[nzColAlloc] = b_d;
        nzColAlloc++;
      }
    }
    this->colidx[1] = (this->colidx[1] + extraCol) + 1;
  } else {
    nz = this->colidx[0] - 1;
    for (k = 0; k < 8192; k++) {
      double b_d;
      b_d = rhs[k];
      if (b_d != 0.0) {
        this->rowidx[nz] = k + 1;
        this->d[nz] = b_d;
        nz++;
      }
    }
    nzColAlloc -= nzRhs;
    if (nzColAlloc > 0) {
      int start;
      start = this->colidx[1] - 1;
      nzRhs = n - this->colidx[1];
      if (nzRhs > 0) {
        std::memmove((void *)&this->rowidx[nz], (void *)&this->rowidx[start],
                     (unsigned int)((size_t)nzRhs * sizeof(int)));
        std::memmove((void *)&this->d[nz], (void *)&this->d[start],
                     (unsigned int)((size_t)nzRhs * sizeof(double)));
      }
      this->colidx[1] = this->colidx[1] - nzColAlloc;
    }
  }
}

void b_sparse::parenReference(b_sparse *s) const
{
  int i;
  int nd_tmp;
  int numalloc;
  nd_tmp = this->colidx[1] - this->colidx[0];
  if (nd_tmp >= 1) {
    numalloc = nd_tmp;
  } else {
    numalloc = 1;
  }
  s->d.set_size(numalloc);
  s->maxnz = numalloc;
  s->colidx.set_size(2);
  s->colidx[0] = 1;
  s->rowidx.set_size(numalloc);
  for (i = 0; i < numalloc; i++) {
    s->d[i] = 0.0;
    s->rowidx[i] = 0;
  }
  s->colidx[1] = 1;
  s->fillIn();
  if (nd_tmp != 0) {
    numalloc = this->colidx[0] - 2;
    for (int k{0}; k < nd_tmp; k++) {
      i = (numalloc + k) + 1;
      s->d[k] = this->d[i];
      s->rowidx[k] = this->rowidx[i];
    }
    s->colidx[1] = s->colidx[0] + nd_tmp;
  }
}

void b_sparse::fillIn()
{
  int i;
  int idx;
  idx = 1;
  i = this->colidx.size(0);
  for (int c{0}; c <= i - 2; c++) {
    int ridx;
    ridx = this->colidx[c];
    this->colidx[c] = idx;
    int exitg1;
    int i1;
    do {
      exitg1 = 0;
      i1 = this->colidx[c + 1];
      if (ridx < i1) {
        double val;
        int currRowIdx;
        val = 0.0;
        currRowIdx = this->rowidx[ridx - 1];
        while ((ridx < i1) && (this->rowidx[ridx - 1] == currRowIdx)) {
          val += this->d[ridx - 1];
          ridx++;
        }
        if (val != 0.0) {
          this->d[idx - 1] = val;
          this->rowidx[idx - 1] = currRowIdx;
          idx++;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  this->colidx[this->colidx.size(0) - 1] = idx;
}

void sparse::locSortrows(int idx[32512], int a[32512], int b[32512])
{
  static b_anonymous_function b_this;
  static int t[32512];
  int k;
  std::copy(&a[0], &a[32512], &b_this.workspace.a[0]);
  std::copy(&b[0], &b[32512], &b_this.workspace.b[0]);
  internal::introsort(idx, &b_this);
  std::copy(&a[0], &a[32512], &t[0]);
  for (k = 0; k < 32512; k++) {
    a[k] = t[idx[k] - 1];
  }
  std::copy(&b[0], &b[32512], &t[0]);
  for (k = 0; k < 32512; k++) {
    b[k] = t[idx[k] - 1];
  }
}

void sparse::mldivide(const b_sparse *b, b_sparse *y) const
{
  static double tmp[8192];
  cs_di *cxA;
  cs_din *N;
  cs_dis *S;
  b_sparse b_this;
  double tol;
  cxA = makeCXSparseMatrix(
      this->colidx[this->colidx.size(0) - 1] - 1, 8192, 8192,
      &(((::coder::array<int, 1U> *)&this->colidx)->data())[0],
      &(((::coder::array<int, 1U> *)&this->rowidx)->data())[0],
      &(((::coder::array<double, 1U> *)&this->d)->data())[0]);
  S = cs_di_sqr(2, cxA, 0);
  N = cs_di_lu(cxA, S, 1);
  cs_di_spfree(cxA);
  if (N == NULL) {
    int cend;
    int i;
    cs_di_sfree(S);
    cs_di_nfree(N);
    cxA = makeCXSparseMatrix(
        this->colidx[this->colidx.size(0) - 1] - 1, 8192, 8192,
        &(((::coder::array<int, 1U> *)&this->colidx)->data())[0],
        &(((::coder::array<int, 1U> *)&this->rowidx)->data())[0],
        &(((::coder::array<double, 1U> *)&this->d)->data())[0]);
    S = cs_di_sqr(2, cxA, 1);
    N = cs_di_qr(cxA, S);
    cs_di_spfree(cxA);
    qr_rank_di(N, &tol);
    b->parenReference(&b_this);
    std::memset(&tmp[0], 0, 8192U * sizeof(double));
    cend = b_this.colidx[1] - 1;
    i = b_this.colidx[0];
    for (int idx{i}; idx <= cend; idx++) {
      tmp[b_this.rowidx[idx - 1] - 1] = b_this.d[idx - 1];
    }
    solve_from_qr_di(N, S, (double *)&tmp[0], 8192, 8192);
    y->d.set_size(1);
    y->d[0] = 0.0;
    y->maxnz = 1;
    y->colidx.set_size(2);
    y->colidx[0] = 1;
    y->rowidx.set_size(1);
    y->rowidx[0] = 0;
    y->colidx[1] = 1;
    y->fillIn();
    y->parenAssign(tmp);
    cs_di_sfree(S);
    cs_di_nfree(N);
  } else {
    int cend;
    int i;
    b->parenReference(&b_this);
    std::memset(&tmp[0], 0, 8192U * sizeof(double));
    cend = b_this.colidx[1] - 1;
    i = b_this.colidx[0];
    for (int idx{i}; idx <= cend; idx++) {
      tmp[b_this.rowidx[idx - 1] - 1] = b_this.d[idx - 1];
    }
    solve_from_lu_di(N, S, (double *)&tmp[0], 8192);
    y->d.set_size(1);
    y->d[0] = 0.0;
    y->maxnz = 1;
    y->colidx.set_size(2);
    y->colidx[0] = 1;
    y->rowidx.set_size(1);
    y->rowidx[0] = 0;
    y->colidx[1] = 1;
    y->fillIn();
    y->parenAssign(tmp);
    cs_di_sfree(S);
    cs_di_nfree(N);
  }
}

} // namespace coder

// End of code generation (sparse1.cpp)
