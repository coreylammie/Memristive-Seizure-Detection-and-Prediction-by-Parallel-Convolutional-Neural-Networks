import numpy as np
import torch


def voltage_deg_model_sparse_conductance(G_mem, V_app_WL1, V_app_BL2, R_source, R_line):
    m = G_mem.shape[0]
    n = G_mem.shape[1]
    # Set word/bit line voltages
    indices = torch.zeros(2, 8 * m * n - 2 * m - 2 * n)
    values = torch.zeros(8 * m * n - 2 * m - 2 * n)
    index = 0
    # A matrix
    i = 0
    j = 0
    for col_index in range(m * n):
        row_index = col_index
        indices[0, index] = row_index
        indices[1, index] = col_index
        if (j == 0):
            values[index] = G_mem[i, j] + 1 / R_source + 1 / R_line
        else:
            if (j == n - 1):
                values[index] = G_mem[i, j] + 1 / R_line
            else:
                indices[0, index] = row_index
                indices[1, index] = col_index
                values[index] = G_mem[i, j] + 2 / R_line

        index += 1
        if (j < n - 1):
            indices[0, index] = row_index + 1
            indices[1, index] = col_index
            values[index] = -1 / R_line
            index += 1
            indices[0, index] = row_index
            indices[1, index] = col_index + 1
            values[index] = -1 / R_line
            index += 1

        j += 1
        if (j > n - 1):
            j = 0
            i += 1

    # B matrix
    i = 0
    j = 0
    for col_index in range(m * n):
        row_index = col_index
        indices[0, index] = row_index
        indices[1, index] = m * n + col_index
        values[index] = -G_mem[i, j]
        index += 1
        j += 1
        if (j > n - 1):
            j = 0
            i += 1

    # C matrix
    i = 0
    j = 0
    for row_index in range(m * n):
        col_index = n * i + j
        indices[0, index] = m * n + row_index
        indices[1, index] = col_index
        values[index] = G_mem[i, j]
        index += 1
        i += 1
        if (i > m - 1):
            i = 0
            j += 1

    # D matrix
    i = 0
    j = 0
    for row_index in range(m * n):
        if (i == 0):
            col_index = j
            indices[0, index] = m * n + row_index
            indices[1, index] = m * n + col_index
            values[index] = -1 / R_line - G_mem[i, j]
            index += 1
            col_index = (n * (i + 1)) + j
            indices[0, index] = m * n + row_index
            indices[1, index] = m * n + col_index
            values[index] = 1 / R_line
            index += 1
        elif (i == m - 1):
            col_index = (n * (i - 1)) + j
            indices[0, index] = m * n + row_index
            indices[1, index] = m * n + col_index
            values[index] = 1 / R_line
            index += 1
            col_index = (n * i) + j
            indices[0, index] = m * n + row_index
            indices[1, index] = m * n + col_index
            values[index] = -1 / R_source - G_mem[i, j] - 1 / R_line
            index += 1
        else:
            col_index = (n * (i - 1)) + j
            indices[0, index] = m * n + row_index
            indices[1, index] = m * n + col_index
            values[index] = 1 / R_line
            index += 1
            col_index = (n * i) + j
            indices[0, index] = m * n + row_index
            indices[1, index] = m * n + col_index
            values[index] = -G_mem[i, j] - 2 / R_line
            index += 1
            col_index = (n * (i + 1)) + j
            indices[0, index] = m * n + row_index
            indices[1, index] = m * n + col_index
            values[index] = 1 / R_line
            index += 1

        i += 1
        if (i > m - 1):
            i = 0
            j += 1

    ABCD_matrix = torch.sparse_coo_tensor(
        indices=indices, values=values, size=(2 * m * n, 2 * m * n))

    # E matrix
    indices = torch.zeros(2, m + n)
    values = torch.ones(m + n)
    index = 0
    # E_W values
    for i in range(m):
        indices[0, index] = i * n
        values[index] = V_app_WL1[i] / R_source
        index += 1

    # E_B values
    for j in range(n):
        indices[0, index] = m * n + (j + 1) * m - 1
        values[index] = -V_app_BL2[j] / R_source
        index += 1

    E_matrix = torch.sparse_coo_tensor(
        indices=indices, values=values, size=(2 * m * n, 1))
    V = torch.linalg.solve(ABCD_matrix.to_dense(), E_matrix.to_dense())
    V_applied = torch.zeros((m, n))
    for i in range(m):
        for j in range(n):
            V_applied[i, j] = V[n * (i - 1) + j] - V[m * n + n * (i - 1) + j]

    return V_applied


if __name__ == "__main__":
    m = 64
    n = 64
    G_mem = torch.ones(m, n)
    V_app_WL1 = torch.ones(m, 1) * 2
    V_app_BL2 = torch.ones(n, 1) * 3
    R_source = 1e5
    R_line = 5
    voltage_deg_model_sparse_conductance(
        G_mem, V_app_WL1, V_app_BL2, R_source, R_line)
