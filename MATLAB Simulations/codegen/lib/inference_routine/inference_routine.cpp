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
#include "inference_routine_data.h"
#include "inference_routine_initialize.h"
#include "minOrMax.h"
#include "rand.h"
#include "voltage_deg_model_sparse_conductance.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Function Definitions
void inference_routine(const double tile_1[4096], const double tile_2[4096],
                       const double max_weight[8], double n_kernels,
                       const double kernel_sizes[2], const double dense1a[4096],
                       const double dense1b[4096], const double dense1c[4096],
                       const double dense1d[4096], const double dense1e[4096],
                       const double dense1b_diff[16], const double dense2b[2],
                       const double test_data[163840], const double[2560],
                       double n_samples, coder::array<double, 2U> &out)
{
  static const signed char reading[128]{
      1, 16, 17, 32, 33, 48, 49, 64, 1, 16, 17, 32, 33, 48, 49, 64,
      1, 16, 17, 32, 33, 48, 49, 64, 1, 16, 17, 32, 33, 48, 49, 64,
      1, 16, 17, 32, 33, 48, 49, 64, 1, 16, 17, 32, 33, 48, 49, 64,
      1, 16, 17, 32, 33, 48, 49, 64, 1, 16, 17, 32, 33, 48, 49, 64,
      1, 16, 17, 32, 33, 48, 49, 64, 1, 16, 17, 32, 33, 48, 49, 64,
      1, 16, 17, 32, 33, 48, 49, 64, 1, 16, 17, 32, 33, 48, 49, 64,
      1, 16, 17, 32, 33, 48, 49, 64, 1, 16, 17, 32, 33, 48, 49, 64,
      1, 16, 17, 32, 33, 48, 49, 64, 1, 16, 17, 32, 33, 48, 49, 64};
  coder::array<double, 2U> conv_out;
  coder::array<double, 2U> ex;
  coder::array<double, 2U> r;
  coder::array<int, 1U> r1;
  double a__1[4096];
  double avgpool_out[1088];
  double e_avgpool_out_data[1024];
  double d_avgpool_out_data[768];
  double c_avgpool_out_data[512];
  double b_avgpool_out_data[256];
  double I_temp[64];
  double avgpool_out_data[64];
  double b_I_temp[32];
  double total[16];
  double rmaxlimit[8];
  double rminlimit[8];
  double dense2_out[2];
  double b_rmaxlimit;
  double b_rminlimit;
  double conv_outstep;
  int b_loop_ub;
  int i;
  int i1;
  int i2;
  int loop_ub;
  int loop_ub_tmp;
  int unnamed_idx_1;
  if (!isInitialized_inference_routine) {
    inference_routine_initialize();
  }
  loop_ub_tmp = static_cast<int>(n_samples + 1.0);
  out.set_size(1, loop_ub_tmp);
  for (i = 0; i < loop_ub_tmp; i++) {
    out[i] = 0.0;
  }
  // Ground column voltages (set columns to 0 V)
  //  20-50 source resistance (ohms) for simulation model
  //  2-5 line resistance (ohms) for simulation model
  // 100 kohm is max resistance of memristors
  // 10 kohm is min resistance of memristors
  // limit for min_R [1,1] to turn off
  // limit for max_R [1,1] to turn off
  coder::b_rand(rmaxlimit);
  for (i = 0; i < 8; i++) {
    rmaxlimit[i] = rmaxlimit[i] * 0.050000000000000044 + 1.0;
  }
  coder::b_rand(rminlimit);
  //  Calculate max conductance based on resistance
  //  Calculate min conductance based on resistance
  for (i = 0; i < 8; i++) {
    conv_outstep = 1.0 / (100000.0 * rmaxlimit[i]);
    rmaxlimit[i] = conv_outstep;
    rminlimit[i] =
        (1.0 / (10000.0 * (rminlimit[i] * 0.050000000000000044 + 0.95)) -
         conv_outstep) /
        max_weight[i];
  }
  if (0 <= static_cast<int>(n_samples + 1.0) - 1) {
    loop_ub =
        static_cast<int>(((128.0 - kernel_sizes[0]) - kernel_sizes[1]) + 2.0) *
        static_cast<int>(n_kernels);
    i1 = static_cast<int>((64.0 - kernel_sizes[0]) + 1.0);
    i2 = static_cast<int>((64.0 - kernel_sizes[1]) + 1.0);
    unnamed_idx_1 = static_cast<int>(56.0 - kernel_sizes[0]);
    b_loop_ub = static_cast<int>(56.0 - kernel_sizes[0]);
    b_rmaxlimit = rmaxlimit[0];
    b_rminlimit = rminlimit[0];
  }
  for (int sample_idx{0}; sample_idx < loop_ub_tmp; sample_idx++) {
    int b_i;
    int j;
    int m;
    int n;
    //  Input vector
    //  Forward operation for tiles 1 and 2 (convolution)
    conv_out.set_size(
        static_cast<int>(((128.0 - kernel_sizes[0]) - kernel_sizes[1]) + 2.0),
        static_cast<int>(n_kernels));
    for (i = 0; i < loop_ub; i++) {
      conv_out[i] = 0.0;
    }
    //  First convolution
    for (b_i = 0; b_i < i1; b_i++) {
      conv_outstep = ((static_cast<double>(b_i) + 1.0) + kernel_sizes[0]) - 1.0;
      if (static_cast<double>(b_i) + 1.0 > conv_outstep) {
        i = 0;
        j = 1;
      } else {
        i = b_i;
        j = static_cast<int>(conv_outstep) + 1;
      }
      m = j - i;
      r.set_size(1, m + static_cast<int>(kernel_sizes[1] + 1.0));
      r[0] = 1.0;
      for (n = 0; n <= m - 2; n++) {
        r[n + 1] = test_data[(i + n) + (sample_idx << 6)];
      }
      m = static_cast<int>(kernel_sizes[1] + 1.0);
      for (n = 0; n < m; n++) {
        r[(n + j) - i] = 0.0;
      }
      voltage_deg_model_sparse_conductance(tile_1, r, a__1, I_temp,
                                           &conv_outstep);
      for (i = 0; i < 64; i++) {
        I_temp[i] = (I_temp[i] - rmaxlimit[0]) / rminlimit[0];
      }
      for (i = 0; i < 32; i++) {
        m = i << 1;
        b_I_temp[i] = I_temp[m] - I_temp[m + 1];
      }
      if (1 > conv_out.size(1)) {
        m = 0;
      } else {
        m = conv_out.size(1);
      }
      for (i = 0; i < m; i++) {
        conv_out[b_i + conv_out.size(0) * i] = b_I_temp[i];
      }
    }
    //  Second convolution
    for (b_i = 0; b_i < i2; b_i++) {
      conv_outstep = ((static_cast<double>(b_i) + 1.0) + kernel_sizes[1]) - 1.0;
      if (static_cast<double>(b_i) + 1.0 > conv_outstep) {
        i = 0;
        j = 1;
      } else {
        i = b_i;
        j = static_cast<int>(conv_outstep) + 1;
      }
      m = j - i;
      r.set_size(1, m + static_cast<int>(kernel_sizes[0] + 1.0));
      r[0] = 1.0;
      for (n = 0; n <= m - 2; n++) {
        r[n + 1] = test_data[(i + n) + (sample_idx << 6)];
      }
      m = static_cast<int>(kernel_sizes[0] + 1.0);
      for (n = 0; n < m; n++) {
        r[(n + j) - i] = 0.0;
      }
      voltage_deg_model_sparse_conductance(tile_2, r, a__1, I_temp,
                                           &conv_outstep);
      for (i = 0; i < 64; i++) {
        I_temp[i] = (I_temp[i] - rmaxlimit[1]) / rminlimit[1];
      }
      i = static_cast<int>(
              (((static_cast<double>(b_i) + 1.0) + 64.0) - kernel_sizes[0]) +
              1.0) -
          1;
      for (j = 0; j < 32; j++) {
        m = j << 1;
        b_I_temp[j] = I_temp[m] - I_temp[m + 1];
      }
      if (1 > conv_out.size(1)) {
        m = 0;
      } else {
        m = conv_out.size(1);
      }
      for (j = 0; j < m; j++) {
        conv_out[i + conv_out.size(0) * j] = b_I_temp[j];
      }
    }
    //  Implement output resolution
    m = conv_out.size(0);
    n = conv_out.size(1);
    ex.set_size(1, conv_out.size(1));
    if (conv_out.size(1) >= 1) {
      for (j = 0; j < n; j++) {
        ex[j] = conv_out[conv_out.size(0) * j];
        for (b_i = 2; b_i <= m; b_i++) {
          double b;
          boolean_T p;
          conv_outstep = ex[j];
          b = conv_out[(b_i + conv_out.size(0) * j) - 1];
          if (std::isnan(b)) {
            p = false;
          } else if (std::isnan(conv_outstep)) {
            p = true;
          } else {
            p = (conv_outstep < b);
          }
          if (p) {
            ex[j] = b;
          }
        }
      }
    }
    coder::internal::minimum(conv_out, r);
    conv_outstep =
        (coder::internal::maximum(ex) - coder::internal::minimum(r)) / 63.0;
    m = conv_out.size(0) * conv_out.size(1);
    for (i = 0; i < m; i++) {
      conv_out[i] = conv_out[i] / conv_outstep;
    }
    m = conv_out.size(0) * conv_out.size(1);
    for (n = 0; n < m; n++) {
      conv_out[n] = std::round(conv_out[n]);
    }
    m = conv_out.size(0) * conv_out.size(1);
    for (i = 0; i < m; i++) {
      conv_out[i] = conv_out[i] * conv_outstep;
    }
    //  Apply ReLU
    n = conv_out.size(0) * conv_out.size(1) - 1;
    m = 0;
    for (b_i = 0; b_i <= n; b_i++) {
      if (conv_out[b_i] < 0.0) {
        m++;
      }
    }
    r1.set_size(m);
    m = 0;
    for (b_i = 0; b_i <= n; b_i++) {
      if (conv_out[b_i] < 0.0) {
        r1[m] = b_i + 1;
        m++;
      }
    }
    m = r1.size(0) - 1;
    for (i = 0; i <= m; i++) {
      conv_out[r1[i] - 1] = 0.0;
    }
    //  Forward operation for tile 8 (avgerage pooling)
    std::memset(&avgpool_out[0], 0, 1088U * sizeof(double));
    for (b_i = 0; b_i < 34; b_i++) {
      m = (b_i << 1) + 1;
      for (j = 0; j < 32; j++) {
        if (m == 1) {
          avgpool_out[34 * j] = 0.5 * conv_out[conv_out.size(0) * j] +
                                0.5 * conv_out[conv_out.size(0) * j + 1];
        } else {
          avgpool_out[(static_cast<int>((static_cast<double>(m) + 1.0) / 2.0) +
                       34 * j) -
                      1] = 0.5 * conv_out[(m + conv_out.size(0) * j) - 1] +
                           0.5 * conv_out[m + conv_out.size(0) * j];
        }
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
    std::memset(&total[0], 0, 16U * sizeof(double));
    for (b_i = 0; b_i < 17; b_i++) {
      // 1088/64=17
      if (b_i + 1 <= 4) {
        i = b_i << 6;
        j = (b_i + 1) << 6;
        if (i + 1 > j) {
          i = 0;
          j = 0;
        }
        m = j - i;
        for (j = 0; j < m; j++) {
          b_avgpool_out_data[j] = avgpool_out[i + j];
        }
        voltage_deg_model_sparse_conductance(dense1a, b_avgpool_out_data, a__1,
                                             I_temp, &conv_outstep);
        i = (b_i + 1) << 1;
        j = reading[i - 2];
        i = reading[i - 1];
        if (j > i) {
          j = 0;
          i = 0;
        } else {
          j--;
        }
        m = i - j;
        for (i = 0; i < m; i++) {
          avgpool_out_data[i] = (I_temp[j + i] - rmaxlimit[2]) / rminlimit[2];
        }
        for (i = 0; i < 16; i++) {
          total[i] += avgpool_out_data[i];
        }
      } else if (b_i + 1 <= 8) {
        i = b_i << 6;
        j = (b_i + 1) << 6;
        if (i + 1 > j) {
          i = 0;
          j = 0;
        }
        m = j - i;
        for (j = 0; j < m; j++) {
          c_avgpool_out_data[j] = avgpool_out[i + j];
        }
        voltage_deg_model_sparse_conductance(dense1b, c_avgpool_out_data, a__1,
                                             I_temp, &conv_outstep);
        i = (b_i + 1) << 1;
        j = reading[i - 2];
        i = reading[i - 1];
        if (j > i) {
          j = 0;
          i = 0;
        } else {
          j--;
        }
        m = i - j;
        for (i = 0; i < m; i++) {
          avgpool_out_data[i] = (I_temp[j + i] - rmaxlimit[3]) / rminlimit[3];
        }
        for (i = 0; i < 16; i++) {
          total[i] += avgpool_out_data[i];
        }
      } else if (b_i + 1 <= 12) {
        i = b_i << 6;
        j = (b_i + 1) << 6;
        if (i + 1 > j) {
          i = 0;
          j = 0;
        }
        m = j - i;
        for (j = 0; j < m; j++) {
          d_avgpool_out_data[j] = avgpool_out[i + j];
        }
        voltage_deg_model_sparse_conductance(dense1c, d_avgpool_out_data, a__1,
                                             I_temp, &conv_outstep);
        i = reading[((b_i + 1) << 1) - 2];
        j = reading[((b_i + 1) << 1) - 1];
        if (i > j) {
          i = 0;
          j = 0;
        } else {
          i--;
        }
        m = j - i;
        for (j = 0; j < m; j++) {
          avgpool_out_data[j] = (I_temp[i + j] - rmaxlimit[4]) / rminlimit[4];
        }
        for (i = 0; i < 16; i++) {
          total[i] += avgpool_out_data[i];
        }
      } else if (b_i + 1 <= 16) {
        i = b_i << 6;
        j = (b_i + 1) << 6;
        if (i + 1 > j) {
          i = 0;
          j = 0;
        }
        m = j - i;
        for (j = 0; j < m; j++) {
          e_avgpool_out_data[j] = avgpool_out[i + j];
        }
        voltage_deg_model_sparse_conductance(dense1d, e_avgpool_out_data, a__1,
                                             I_temp, &conv_outstep);
        i = reading[((b_i + 1) << 1) - 2];
        j = reading[((b_i + 1) << 1) - 1];
        if (i > j) {
          i = 0;
          j = 0;
        } else {
          i--;
        }
        m = j - i;
        for (j = 0; j < m; j++) {
          avgpool_out_data[j] = (I_temp[i + j] - rmaxlimit[5]) / rminlimit[5];
        }
        for (i = 0; i < 16; i++) {
          total[i] += avgpool_out_data[i];
        }
      } else {
        std::copy(&avgpool_out[1024], &avgpool_out[1088], &avgpool_out_data[0]);
        voltage_deg_model_sparse_conductance(dense1e, avgpool_out_data, a__1,
                                             I_temp, &conv_outstep);
        for (i = 0; i < 16; i++) {
          total[i] += (I_temp[i] - rmaxlimit[6]) / rminlimit[6];
        }
      }
    }
    //  Add bias
    for (i = 0; i < 16; i++) {
      total[i] += dense1b_diff[i];
    }
    //  Implement output resolution
    conv_outstep =
        (coder::internal::maximum(total) - coder::internal::b_minimum(total)) /
        63.0;
    for (n = 0; n < 16; n++) {
      total[n] = std::round(total[n] / conv_outstep) * conv_outstep;
    }
    //  Convert back from differential form and apply relu
    //  Forward operation for 1 (second dense layer with 2 neurons)
    conv_outstep = kernel_sizes[0];
    m = static_cast<int>(kernel_sizes[0] + 1.0);
    r.set_size(1,
               (static_cast<int>(kernel_sizes[0] + 1.0) + unnamed_idx_1) + 8);
    for (i = 0; i < m; i++) {
      r[i] = 0.0;
    }
    for (i = 0; i < 8; i++) {
      j = i << 1;
      r[i + static_cast<int>(conv_outstep + 1.0)] = total[j] - total[j + 1];
    }
    for (i = 0; i < b_loop_ub; i++) {
      r[(i + static_cast<int>(conv_outstep + 1.0)) + 8] = 0.0;
    }
    voltage_deg_model_sparse_conductance(tile_1, r, a__1, I_temp,
                                         &conv_outstep);
    dense2_out[0] = ((I_temp[0] - b_rmaxlimit) / b_rminlimit -
                     (I_temp[1] - b_rmaxlimit) / b_rminlimit) +
                    dense2b[0];
    dense2_out[1] = ((I_temp[2] - b_rmaxlimit) / b_rminlimit -
                     (I_temp[3] - b_rmaxlimit) / b_rminlimit) +
                    dense2b[1];
    //  Implement output resolution
    conv_outstep = (coder::internal::b_maximum(dense2_out) -
                    coder::internal::minimum(dense2_out)) /
                   63.0;
    //  Convert to final prediction
    dense2_out[0] = std::round(dense2_out[0] / conv_outstep) * conv_outstep;
    dense2_out[1] = std::round(dense2_out[1] / conv_outstep) * conv_outstep;
    if ((dense2_out[0] < dense2_out[1]) ||
        (std::isnan(dense2_out[0]) && (!std::isnan(dense2_out[1])))) {
      m = 2;
    } else {
      m = 1;
    }
    out[sample_idx] = static_cast<double>(m) - 1.0;
    //  List comparison and calculate accuracy
  }
}

// End of code generation (inference_routine.cpp)
