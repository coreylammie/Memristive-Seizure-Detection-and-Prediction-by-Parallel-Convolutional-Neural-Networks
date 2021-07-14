function [outputArg1,outputArg2] = inference_routine(inputArg1,inputArg2)
for z = start_num:end_num
    z
    inputvec = testdata(:,z); %input vector
    inputvec = inputvec';
    
    %% Forward Operation for tile 1 and 2 (convolution)
    totalI = [];
    %First convolution
    for i = 1:(64-n_kersize(1)+1)
        V_WL = [1,inputvec(i:i+n_kersize(1)-1),zeros(1,n_kersize(2)+1)];
        [VM_temp, I_temp, P_temp] = voltage_deg_model_sparse_conductance(tile1,V_WL,V_BL,R_source,R_line);
        I_temp=(I_temp-G_min(1))./scaling_factor(1);
        posI = I_temp(:,1:2:end);
        negI = I_temp(:,2:2:end);
        tempI = posI-negI;
        totalI = [totalI;tempI];
    end
    
    %Second convolution
    for i = 1:(64-n_kersize(2)+1)
        V_WL = [1,inputvec(i:i+n_kersize(2)-1),zeros(1,n_kersize(1)+1),];
        [VM_temp, I_temp, P_temp] = voltage_deg_model_sparse_conductance(tile2,V_WL,V_BL,R_source,R_line);
        I_temp=(I_temp-G_min(2))./scaling_factor(2);
        posI = I_temp(:,1:2:end);
        negI = I_temp(:,2:2:end);
        tempI = posI-negI;
        totalI = [totalI;tempI];
    end
    
    conv_out = totalI;
    
    % Implement output resolution
    conv_outstep = (max(max(conv_out)) - min(min(conv_out)))./(2^outputbits-1);
    conv_out = round(conv_out./conv_outstep)*conv_outstep;
    
    %Apply relu
    conv_out(conv_out<0)=0;
    %% Forward operation for tile 8 (avgerage pooling)
    avgpool_out = 0;
    % totalI = [];
    % for i=1:n_ker
    %     V_WL = [conv_out(1:34,i);zeros(30,1)];
    %     [~, I_temp, P_temp] = voltage_deg_model_sparse_conductance(avgpool,V_WL,V_BL,R_source,R_line);
    %     tempI1=(I_temp(1:17)-G_min(8))./scaling_factor(8);
    %
    %     V_WL = [conv_out(35:68,i);zeros(30,1)];
    %     [VM_temp, I_temp, P_temp] = voltage_deg_model_sparse_conductance(avgpool,V_WL,V_BL,R_source,R_line);
    %     tempI2=(I_temp(1:17)-G_min(8))./scaling_factor(8);
    %
    %
    %     tempI = [tempI1,tempI2];
    %     totalI = [totalI;tempI];
    % end
    %
    % avgpool_out = totalI';
    %
    % % Implement output resolution
    % avgpool_outstep = (max(max(avgpool_out)) - min(min(avgpool_out)))./(2^outputbits-1);
    % avgpool_out = round(avgpool_out./avgpool_outstep)*avgpool_outstep;
    
    for i=1:2:68
        for j=1:32
            if i==1
                avgpool_out(1,j) = 0.5*conv_out(i,j)+0.5*conv_out(i+1,j);
            else
                avgpool_out((i+1)/2,j) = 0.5*conv_out(i,j)+0.5*conv_out(i+1,j);
            end
        end
    end
    
    %Apply relu
    avgpool_out(avgpool_out<0)=0;
    %% Forward operation for tile 3-7 (first dense layer with 8 neurons)
    
    %Reformat the output from previous layer
    %avgpool_out = permute(avgpool_out,[2,1]);
    avgpool_out = reshape(avgpool_out,[1088,1]);
    
    %Perform calculation
    total = zeros(1,16);
    reading = [1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64,1,16,17,32,33,48,49,64];
    for i=1:17 %1088/64=17
        if (1<=i) && (i<=4)
            V_WL = [avgpool_out(((i-1)*64+1):i*64,:)];
            [VM_temp, I_temp, P_temp] = voltage_deg_model_sparse_conductance(dense1a,V_WL,V_BL,R_source,R_line);
            tempI=(I_temp(reading(1,(i*2-1)):reading(1,i*2))-G_min(3))./scaling_factor(3);
            total = total+tempI;
        elseif (5<=i) && (i<=8)
            V_WL = [avgpool_out(((i-1)*64+1):i*64,:)];
            [VM_temp, I_temp, P_temp] = voltage_deg_model_sparse_conductance(dense1b,V_WL,V_BL,R_source,R_line);
            tempI=(I_temp(reading(1,(i*2-1)):reading(1,i*2))-G_min(4))./scaling_factor(4);
            total = total+tempI;
        elseif (9<=i) && (i<=12)
            V_WL = [avgpool_out(((i-1)*64+1):i*64,:)];
            [VM_temp, I_temp, P_temp] = voltage_deg_model_sparse_conductance(dense1c,V_WL,V_BL,R_source,R_line);
            tempI=(I_temp(reading(1,(i*2-1)):reading(1,i*2))-G_min(5))./scaling_factor(5);
            total = total+tempI;
        elseif (13<=i) && (i<=16)
            V_WL = [avgpool_out(((i-1)*64+1):i*64,:)];
            [VM_temp, I_temp, P_temp] = voltage_deg_model_sparse_conductance(dense1d,V_WL,V_BL,R_source,R_line);
            tempI=(I_temp(reading(1,(i*2-1)):reading(1,i*2))-G_min(6))./scaling_factor(6);
            total = total+tempI;
        else
            V_WL = [avgpool_out(((i-1)*64+1):i*64,:)];
            [VM_temp, I_temp, P_temp] = voltage_deg_model_sparse_conductance(dense1e,V_WL,V_BL,R_source,R_line);
            tempI=(I_temp(reading(1,(i*2-1)):reading(1,i*2))-G_min(7))./scaling_factor(7);
            total = total+tempI;
        end
    end
    
    %Add bias
    total = total+dense1b_diff;
    
    % Implement output resolution
    totalstep = (max(max(total)) - min(min(total)))./(2^outputbits-1);
    total = round(total./totalstep)*totalstep;
    
    %Convert back from differential form and apply relu
    posI = total(:,1:2:end);
    negI = total(:,2:2:end);
    dense1_out = posI-negI;
    %dense1_out(dense1_out<0)=0;
    
    
    
    %% Forward operation for 1 (second dense layer with 2 neurons)
    
    a = size(dense1_out);
    V_WL = [zeros(1,n_kersize(1)+1),dense1_out,zeros(1,64-8-n_kersize(1))];
    [VM_temp, I_temp, P_temp] = voltage_deg_model_sparse_conductance(tile1,V_WL,V_BL,R_source,R_line);
    tempI=(I_temp(1:4)-G_min(1))./scaling_factor(1);
    posI = tempI(:,1:2:end);
    negI = tempI(:,2:2:end);
    dense2_out = posI-negI;
    dense2_out=dense2_out+dense2b;
    
    % Implement output resolution
    dense2_outstep = (max(max(dense2_out)) - min(min(dense2_out)))./(2^outputbits-1);
    dense2_out = round(dense2_out./dense2_outstep)*dense2_outstep;
    
    
    
    %% Convert to final prediction
    [maxNum,maxIndex]=max(dense2_out);
    predictions = [predictions,maxIndex-1];
    
    %% List comparison and calculate accuracy
    dif = predictions-testlabel(1,start_num:z);
    dif(dif<0)=1;
    [rown,coln] = size(predictions);
    accuracy = (coln-sum(dif))./coln
end
end

