function [V_MAC_mat, I, P] = voltage_deg_model_sparse_conductance(G_mem,V_app_WL1,V_app_BL2,R_source,R_line)
%   This function calculates the voltages at every junction in a memristor
%   crossbar when taking into consideration interconnect line resistances
%   and source resistance.

%   For more information on the model itself, see 
%   A. Chen, "A Comprehensive Crossbar Array Model With Solutions for Line 
%   Resistance and Nonlinear Device Characteristics", IEEE Transactions on 
%   Electron Devices, vol. 60, no. 4, pp. 1318-1326, 2013.

%   Inputs:
%   G_mem - m x n matrix of conductance values in the crossbar array (S)
%   V_app_WL1 - m x 1 vector of input row voltages for MAC operation
%   V_app_BL1 - n x 1 vector of input column voltages for MAC operation
%   R_source - resistance between word/bit line voltage sources and 
%              crossbar (ohms)
%   R_line - interconnect line resistance between adjacent memristor cells
%            in the crossbar array (ohms)

%   Output:
%   V_MAC_mat - m x n matrix of parsed voltages over each memristor
%   I - n x 1 vector of current running through each crossbar column
%   P - static power

%   Intermediate:
%   V - 2*m*n x 1 sparse vector that contains word line voltages (at one
%     terminal of a memristor) and bit line voltages (at the opposite 
%     memristor terminal)
%   V = [V_WL(1,1), 
%       ..., 
%        V_WL(1,n), 
%       V_WL(m,1), 
%        ..., 
%        V_WL(m,n),
%        V_BL(1,1), 
%        ..., 
%         V_BL(1,n), 
%        V_BL(m,1), 
%        ..., 
%       V_BL(m,n)]

%    NOTE: To determine the voltage over a memristor, 
%           V(i,j) = V_WL(i,j) - V_BL(i,j)

m = size(G_mem,1);
n = size(G_mem,2);

% Set word/bit line voltages
%V_app_WL1 = V_in;
%V_app_BL2 = zeros(n, 1);

i_vec = ones(1, 8*m*n-2*m-2*n);
j_vec = ones(1, 8*m*n-2*m-2*n);
vals = zeros(1, 8*m*n-2*m-2*n);

% Fill up vectors
index = 1;

% A matrix values
i = 1;
j = 1;

for col_index = 1:m*n
    row_index = col_index;
    if (j == 1)
        i_vec(index) = row_index;
        j_vec(index) = col_index;
        vals(index) = G_mem(i, j) + 1/R_source + 1/R_line;
        index = index + 1;
    elseif (j == n)
        i_vec(index) = row_index;
        j_vec(index) = col_index;
        vals(index) = G_mem(i, j) + 1/R_line;
        index = index + 1;
    else
        i_vec(index) = row_index;
        j_vec(index) = col_index;
        vals(index) = G_mem(i, j) + 2/R_line;
        index = index + 1;
    end

    if (j < n)
        i_vec(index) = row_index+1;
        j_vec(index) = col_index;
        vals(index) = -1/R_line;
        index = index + 1;

        i_vec(index) = row_index;
        j_vec(index) = col_index+1;
        vals(index) = -1/R_line;
        index = index + 1;
    end

    j = j + 1;
    if (j > n)
        j = 1;
        i = i + 1;
    end
end

% B matrix values
i = 1;
j = 1;
for col_index = 1:m*n
    row_index = col_index;
    
    i_vec(index) = row_index;
    j_vec(index) = m*n + col_index;
    vals(index) = -G_mem(i,j);
    
    index = index + 1;
    
    j = j + 1;
    if (j > n)
        j = 1;
        i = i + 1;
    end
end

% C matrix values
i = 1;
j = 1;
for row_index = 1:m*n
    col_index = n*(i-1)+j;
    
    i_vec(index) = m*n + row_index;
    j_vec(index) = col_index;
    vals(index) = G_mem(i,j);
    
    index = index + 1;
    
    i = i + 1;
    if (i > m)
        i = 1;
        j = j + 1;
    end
end

% D matrix values
i = 1;
j = 1;
for row_index = 1:m*n
    if (i == 1)
        col_index = j;
        i_vec(index) = m*n + row_index;
        j_vec(index) = m*n + col_index;
        vals(index) = -1/R_line - G_mem(i,j);
        index = index + 1;
        
        col_index = (n*i)+j;
        i_vec(index) = m*n + row_index;
        j_vec(index) = m*n + col_index;
        vals(index) = 1/R_line;
        index = index + 1;
    elseif (i == m)
        col_index = (n*(i-2))+j;
        i_vec(index) = m*n + row_index;
        j_vec(index) = m*n + col_index;
        vals(index) = 1/R_line;
        index = index + 1;
        
        col_index = (n*(i-1))+j;
        i_vec(index) = m*n + row_index;
        j_vec(index) = m*n + col_index;
        vals(index) = -1/R_source - G_mem(i, j) - 1/R_line;
        index = index + 1;
    else
        col_index = (n*(i-2))+j;
        i_vec(index) = m*n + row_index;
        j_vec(index) = m*n + col_index;
        vals(index) = 1/R_line;
        index = index + 1;
        
        col_index = (n*(i-1))+j;
        i_vec(index) = m*n + row_index;
        j_vec(index) = m*n + col_index;
        vals(index) = -G_mem(i, j) - 2/R_line;
        index = index + 1;
        
        col_index = (n*i)+j;
        i_vec(index) = m*n + row_index;
        j_vec(index) = m*n + col_index;
        vals(index) = 1/R_line;
        index = index + 1;
    end
    
    i = i + 1;
    if (i > m)
        i = 1;
        j = j + 1;
    end
end

combined_mat = sparse(i_vec, j_vec, vals, 2*m*n, 2*m*n, 8*m*n-2*m-2*n);

% Construct vectors for E matrix
i_vec = ones(1, m+n);
j_vec = ones(1, m+n);
vals = zeros(1, m+n);

index = 1;
% Populate vectors
% E_W values
for i = 1:m
    i_vec(index) = (i-1)*n + 1;
    j_vec(index) = 1;
    vals(index) = V_app_WL1(i)/R_source;
    index = index + 1;
end

% E_B values
for j = 1:n
    i_vec(index) = m*n + j*m;
    j_vec(index) = 1;
    vals(index) = -V_app_BL2(j)/R_source;
    index = index + 1;
end

E = sparse(i_vec, j_vec, vals, 2*m*n, 1, m+n);

%V = linsolve(combined_mat, E);
V = combined_mat\E;
V = full(V);

% Parse V to get column currents
V_MAC_WL = zeros(m, n);
V_MAC_BL = zeros(m, n);
V_MAC_mat = zeros(m, n);

for i = 1:m
    for j = 1:n
        V_MAC_WL(i, j) = V(n*(i-1)+j);
        V_MAC_BL(i, j) = V(m*n + n*(i-1)+j);
        V_MAC_mat(i, j) = V_MAC_WL(i, j) - V_MAC_BL(i, j);
    end
end

I_MAC = V_MAC_mat.*G_mem;
I = sum(I_MAC);

P = I_MAC .* V_MAC_mat;
P = sum(P(:));
end