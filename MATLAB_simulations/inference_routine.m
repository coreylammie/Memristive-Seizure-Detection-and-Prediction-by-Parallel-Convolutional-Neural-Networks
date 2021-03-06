function out = inference_routine(tile_1, tile_2, n_kernels, kernel_sizes, dense1a, dense1b, dense1c, dense1d, dense1e, dense1b_diff, dense2b, R_source, R_line, G_min, output_bits, scaling_factor, test_data, test_labels, n_samples)
    predictions = zeros(1, n_samples+1);
    V_BL = zeros(64,1); % Ground column voltages (set columns to 0 V)
    for sample_idx = 1:n_samples+1
        disp(sample_idx);
        input_vec = test_data(:, sample_idx); % Input vector
        input_vec = input_vec';
        % Forward operation for tiles 1 and 2 (convolution)
        conv_out_1 = zeros(64 - kernel_sizes(1) + 1, n_kernels);
        conv_out_2 = zeros(64 - kernel_sizes(2) + 1, n_kernels);
        i_range = 64 - min(kernel_sizes(1), kernel_sizes(2)) + 1;
        parfor i = 1:i_range
            if i <= 64 - kernel_sizes(1) + 1
                % First convolutional layer
                V_WL = [1, input_vec(i:i+kernel_sizes(1)-1), zeros(1, kernel_sizes(2)+1)];
                [~, I_temp, ~] = voltage_deg_model_sparse_conductance(tile_1, V_WL, V_BL, R_source, R_line);
                conv_out_1(i, :) = I_temp(:, 1:2:end) - I_temp(:, 2:2:end);
            end
            if i <= 64 - kernel_sizes(2) + 1
                % Second convolutional layer
                V_WL = [1, input_vec(i:i+kernel_sizes(2)-1), zeros(1, kernel_sizes(1)+1),];
                [~, I_temp, ~] = voltage_deg_model_sparse_conductance(tile_2, V_WL, V_BL, R_source, R_line);
                conv_out_2(i, :) = I_temp(:, 1:2:end) - I_temp(:, 2:2:end);
            end
        end
        conv_out_1 = conv_out_1 ./ scaling_factor(1);
        conv_out_2 = conv_out_2 ./ scaling_factor(2);
        conv_out = [conv_out_1; conv_out_2];
        % Implement output resolution
        conv_outstep = (max(max(conv_out)) - min(min(conv_out)))./(2^output_bits-1);
        conv_out = round(conv_out./conv_outstep)*conv_outstep;
        % Apply ReLU
        conv_out(conv_out<0)=0;
        % Forward operation for tile 8 (avgerage pooling)
        avgpool_out = zeros(34, 32);
        i_values = 1:2:68;
        parfor i_values_idx = 1:numel(i_values)            
            avgpool_out(i_values_idx, :) = conv_out(i_values(i_values_idx),1:32) + conv_out(i_values(i_values_idx)+1,1:32);
        end
        avgpool_out = avgpool_out ./ 2;
        % Apply ReLU
        avgpool_out(avgpool_out<0) = 0;
        % Forward operation for tile 3-7 (first dense layer with 8 neurons)
        avgpool_out = reshape(avgpool_out,[1088,1]); % Reformat the output from previous layer
        total = zeros(1,16);
        reading = [1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64];
        parfor i=1:17 %1088/64=17
            if (1<=i) && (i<=4)
                V_WL = [avgpool_out(((i-1)*64+1):i*64,:)];
                [~, I_temp, ~] = voltage_deg_model_sparse_conductance(dense1a,V_WL,V_BL,R_source,R_line);
                tempI=(I_temp(reading(1,(i*2-1)):reading(1,i*2))-G_min(3))./scaling_factor(3);
                total = total+tempI;
            elseif (5<=i) && (i<=8)
                V_WL = [avgpool_out(((i-1)*64+1):i*64,:)];
                [~, I_temp, ~] = voltage_deg_model_sparse_conductance(dense1b,V_WL,V_BL,R_source,R_line);
                tempI=(I_temp(reading(1,(i*2-1)):reading(1,i*2))-G_min(4))./scaling_factor(4);
                total = total+tempI;
            elseif (9<=i) && (i<=12)
                V_WL = [avgpool_out(((i-1)*64+1):i*64,:)];
                [~, I_temp, ~] = voltage_deg_model_sparse_conductance(dense1c,V_WL,V_BL,R_source,R_line);
                tempI=(I_temp(reading(1,(i*2-1)):reading(1,i*2))-G_min(5))./scaling_factor(5);
                total = total+tempI;
            elseif (13<=i) && (i<=16)
                V_WL = [avgpool_out(((i-1)*64+1):i*64,:)];
                [~, I_temp, ~] = voltage_deg_model_sparse_conductance(dense1d,V_WL,V_BL,R_source,R_line);
                tempI=(I_temp(reading(1,(i*2-1)):reading(1,i*2))-G_min(6))./scaling_factor(6);
                total = total+tempI;
            else
                V_WL = [avgpool_out(((i-1)*64+1):i*64,:)];
                [~, I_temp, ~] = voltage_deg_model_sparse_conductance(dense1e,V_WL,V_BL,R_source,R_line);
                tempI=(I_temp(reading(1,(i*2-1)):reading(1,i*2))-G_min(7))./scaling_factor(7);
                total = total+tempI;
            end
        end
        % Add bias
        total = total + dense1b_diff;
        % Implement output resolution
        totalstep = (max(max(total)) - min(min(total)))./(2^output_bits-1);
        total = round(total./totalstep)*totalstep;
        % Convert back from differential form and apply relu
        pos_I = total(:,1:2:end);
        neg_I = total(:,2:2:end);
        dense1_out = pos_I - neg_I;
        % Forward operation for 1 (second dense layer with 2 neurons)
        V_WL = [zeros(1,kernel_sizes(1)+1),dense1_out,zeros(1,64-8-kernel_sizes(1))];
        [~, I_temp, ~] = voltage_deg_model_sparse_conductance(tile_1,V_WL,V_BL,R_source,R_line);
        tempI=(I_temp(1:4)-G_min(1))./scaling_factor(1);
        pos_I = tempI(:, 1:2:end);
        neg_I = tempI(:, 2:2:end);
        dense2_out = pos_I-neg_I;
        dense2_out = dense2_out + dense2b;
        % Implement output resolution
        dense2_outstep = (max(max(dense2_out)) - min(min(dense2_out)))./(2^output_bits-1);
        dense2_out = round(dense2_out./dense2_outstep)*dense2_outstep;
        % Convert to final prediction
        [~, maxIndex] = max(dense2_out);
        predictions(1, sample_idx) = maxIndex - 1;
        % List comparison and calculate accuracy
        dif = predictions(1, 1:sample_idx) - test_labels(1, 1:sample_idx);
        dif(dif<0) = 1;
        [~, coln] = size(predictions);
        accuracy = (coln-sum(dif))./coln;
        disp(accuracy);
    end
    out = predictions;
end

