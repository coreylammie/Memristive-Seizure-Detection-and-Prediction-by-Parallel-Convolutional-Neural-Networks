function [] = experimentRuns()
    for seed=5:9
    rng(seed);
    %% Define global variables 
    %To do:
    %R-max-min
    %Output resolution

    %To Ask
    %Switching mismatch
    %In-situ results
    %Sneak path
    %Crossbar type
    %Figure concepts
    %Writing and results

    %Finished:
    %Stuck on/off
    %4-bit
    %Input resolution


    array_row = 64;
    array_col = 64;
    n_ker = 32; %number of kernels
    n_kersize = [32,30]; %kernel sizes
    start_num = 1; %number of test data to run code through
    end_num = 2; %start_num+249;

    V_BL = zeros(64,1); %Ground column voltages (set columns to 0 V)

    predictions = [];

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    R_max = 100E3; %100 kohm is max resistance of memristors
    R_min = 10E3;  %10 kohm is min resistance of memristors

    rminrange = [0.95,1]; %limit for min_R [1,1] to turn off
    rmaxrange = [1,1.05]; %limit for max_R [1,1] to turn off

    percenterror = 0.05; %percent error for crossbar implementation, 0 to turn off

    R_source = 20; % 20-50 source resistance (ohms) for simulation model
    R_line = 2;   % 2-5 line resistance (ohms) for simulation model
    bit_res = 6; % bits for weight resolution

    inputbits = 6; %Number of input bits, comment out lines to turn off ###
    outputbits = 6;

    stuck = 0.001; %stuck on/off percentange, 0 to turn off

    visualize = 0; % 1 to visualize, 0 to not visualize
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    RMAX = R_max; %file labelling only
    RMIN = R_min; %file labelling only


    %% Read and reshape weights and bias
    %weights - original, weights2 - 6 bit trained

    % %Read weights1 and bias 32 bit resolution 
    % file1w = fopen('weights/conv1dweights.txt', 'r');
    % file1b = fopen('weights/conv1dbias.txt', 'r');
    % file2w = fopen('weights/conv1d_1weights.txt', 'r');
    % file2b = fopen('weights/conv1d_1bias.txt', 'r');
    % file3w = fopen('weights/denseweights.txt','r');
    % file3b = fopen('weights/densebias.txt','r');
    % file4w = fopen('weights/dense_1weights.txt','r');
    % file4b = fopen('weights/dense_1bias.txt','r');

    % %Read weights2 and bias 6 bit resolution
    % file1w = fopen('weights2/conv1dweights.txt', 'r');
    % file1b = fopen('weights2/conv1dbias.txt', 'r');
    % file2w = fopen('weights2/conv1d_1weights.txt', 'r');
    % file2b = fopen('weights2/conv1d_1bias.txt', 'r');
    % file3w = fopen('weights2/denseweights.txt','r');
    % file3b = fopen('weights2/densebias.txt','r');
    % file4w = fopen('weights2/dense_1weights.txt','r');
    % file4b = fopen('weights2/dense_1bias.txt','r');

    % %Read weights3 and bias with scaling to [-1.2to1.2] against all sets ABCDE
    % file1w = fopen('weights3/conv1dweights.txt', 'r');
    % file1b = fopen('weights3/conv1dbias.txt', 'r');
    % file2w = fopen('weights3/conv1d_1weights.txt', 'r');
    % file2b = fopen('weights3/conv1d_1bias.txt', 'r');
    % file3w = fopen('weights3/denseweights.txt','r');
    % file3b = fopen('weights3/densebias.txt','r');
    % file4w = fopen('weights3/dense_1weights.txt','r');
    % file4b = fopen('weights3/dense_1bias.txt','r');

    % %Read weights4 and bias 6 bit resolution with scaling to [-1.2to1.2] against all sets AE
    % file1w = fopen('weights4/conv1dweights.txt', 'r');
    % file1b = fopen('weights4/conv1dbias.txt', 'r');
    % file2w = fopen('weights4/conv1d_1weights.txt', 'r');
    % file2b = fopen('weights4/conv1d_1bias.txt', 'r');
    % file3w = fopen('weights4/denseweights.txt','r');
    % file3b = fopen('weights4/densebias.txt','r');
    % file4w = fopen('weights4/dense_1weights.txt','r');
    % file4b = fopen('weights4/dense_1bias.txt','r');

    %Read weights5 and bias 6 bit resolution with scaling to [-1.2to1.2]
    %against sets AE 0.97 train test accuracy
    % file1w = fopen('weights5/conv1dweights.txt', 'r');
    % file1b = fopen('weights5/conv1dbias.txt', 'r');
    % file2w = fopen('weights5/conv1d_1weights.txt', 'r');
    % file2b = fopen('weights5/conv1d_1bias.txt', 'r');
    % file3w = fopen('weights5/denseweights.txt','r');
    % file3b = fopen('weights5/densebias.txt','r');
    % file4w = fopen('weights5/dense_1weights.txt','r');
    % file4b = fopen('weights5/dense_1bias.txt','r');

    %Read weightsPytorch and bias full resolution
    %against sets AE 0.998 test accuracy
    file1w = fopen('weightsPytorch/conv1dweights.txt', 'r');
    file1b = fopen('weightsPytorch/conv1dbias.txt', 'r');
    file2w = fopen('weightsPytorch/conv1d_1weights.txt', 'r');
    file2b = fopen('weightsPytorch/conv1d_1bias.txt', 'r');
    file3w = fopen('weightsPytorch/denseweights.txt','r');
    file3b = fopen('weightsPytorch/densebias.txt','r');
    file4w = fopen('weightsPytorch/dense_1weights.txt','r');
    file4b = fopen('weightsPytorch/dense_1bias.txt','r');

    %Reshape and reorder weights
    conv1w = fscanf(file1w,'%f',[n_ker,n_kersize(1)]);
    %conv1w = permute(conv1w,[2,1]);
    conv1w = reshape(conv1w,[n_kersize(1),n_ker]);
    conv1b = fscanf(file1b,'%f',[1,n_ker]);

    conv2w = fscanf(file2w,'%f',[n_ker,n_kersize(2)]);
    %conv2w = permute(conv2w,[2,1]);
    conv2w = reshape(conv2w,[n_kersize(2),n_ker]);
    conv2b = fscanf(file2b,'%f',[1,n_ker]);

    dense1w = fscanf(file3w,'%f',[1088,8]);
    %dense1w = permute(dense1w,[2,1]);
    dense1b = fscanf(file3b,'%f',[1,8]);

    dense2w = fscanf(file4w,'%f',[8,2]);
    %dense2w = permute(dense2w,[2,1]);
    dense2b = fscanf(file4b,'%f',[1,2]);

    fclose('all');
    %% Convert into differential form
    conv1w_diff = zeros(n_kersize(1),n_ker*2);
    for kernel = 1:n_ker
        for row = 1:n_kersize(1)
            if conv1w(row,kernel) > 0
                conv1w_diff(row,kernel*2-1) = conv1w(row,kernel);
            else
                conv1w_diff(row,kernel*2) = -1*conv1w(row,kernel);
            end
        end
    end

    conv1b_diff = zeros(1,n_ker*2);
    for bias = 1:n_ker
        if conv1b(1,bias) > 0
            conv1b_diff(1,bias*2-1) = conv1b(1,bias);
        else
            conv1b_diff(1,bias*2) = -1*conv1b(1,bias);
        end
    end




    conv2w_diff = zeros(n_kersize(2),n_ker*2);
    for kernel = 1:n_ker
        for row = 1:n_kersize(2)
            if conv2w(row,kernel) > 0
                conv2w_diff(row,kernel*2-1) = conv2w(row,kernel);
            else
                conv2w_diff(row,kernel*2) = -1*conv2w(row,kernel);
            end
        end
    end

    conv2b_diff = zeros(1,n_ker*2);
    for bias = 1:n_ker
        if conv2b(1,bias) > 0
            conv2b_diff(1,bias*2-1) = conv2b(1,bias);
        else
            conv2b_diff(1,bias*2) = -1*conv2b(1,bias);
        end
    end



    dense1w_diff = zeros(1088,8*2);
    for kernel = 1:8
        for row = 1:1088
            if dense1w(row,kernel)>0
                dense1w_diff(row,kernel*2-1) = dense1w(row,kernel);
            else
                dense1w_diff(row,kernel*2) = -1*dense1w(row,kernel);
            end
        end
    end

    dense1b_diff = zeros(1,16);
    for bias = 1:8
        if dense1b(1,bias)>0
            dense1b_diff(1,bias*2-1) = dense1b(1,bias);
        else
            dense1b_diff(1,bias*2) = -1*dense1b(1,bias);
        end
    end




    dense2w_diff = zeros(8,4);
    for kernel = 1:2
        for row = 1:8
            if dense2w(row,kernel)>0
                dense2w_diff(row,kernel*2-1) = dense2w(row,kernel);
            else
                dense2w_diff(row,kernel*2) = -1*dense2w(row,kernel);
            end
        end
    end

    dense2b_diff = zeros(1,4);
    for bias = 1:2
        if dense2b(1,bias)>0
            dense2b_diff(1,bias*2-1) = dense2b(1,bias);
        else
            dense2b_diff(1,bias*2) = -1*dense2b(1,bias);
        end
    end


    %Check that all differential forms are implemented
    % min(conv1w_diff(:))
    % min(conv1b_diff(:))
    % min(conv2w_diff(:))
    % min(conv2b_diff(:))
    % min(dense1w_diff(:))
    % min(dense1b_diff(:))
    % min(dense2w_diff(:))
    % min(dense2b_diff(:))



    %% Map kernels onto crossbar

    %First convolution and dense layer 2 makes tile 1
    dense2w_diff_pad = zeros(8,60);
    dense2wb_diff = [dense2w_diff, dense2w_diff_pad];
    tile1_pad = zeros(23,64);
    tile1 = [conv1b_diff; conv1w_diff; dense2wb_diff ;tile1_pad];

    %Second convolution makes tile 2
    tile2_pad = zeros(33,64);
    tile2 = [conv2b_diff; conv2w_diff; tile2_pad];

    %Average pooling makes tile 8
    avgpool = zeros(64,64);
    for i=[1:17]
        avgpool(i*2-1,i)=0.5;
        avgpool(i*2,i)=0.5;
    end



    %First dense layer with 8 neurons makes tiles 3-7
    dense1a=[];
    dense1b=[];
    dense1c=[];
    dense1d=[];
    dense1e=[];
    for i=[1:4]
        dense1a = [dense1a,dense1w_diff(((i-1)*64+1):i*64,:)];
    end
    for i=[5:8]
        dense1b = [dense1b,dense1w_diff(((i-1)*64+1):i*64,:)];
    end
    for i=[9:12]
        dense1c = [dense1c,dense1w_diff(((i-1)*64+1):i*64,:)];
    end
    for i=[13:16]
        dense1d = [dense1d,dense1w_diff(((i-1)*64+1):i*64,:)];
    end
    for i=[17:17]
        dense1e = [dense1e,dense1w_diff(((i-1)*64+1):i*64,:)];
    end
    %Pad the dense1e since it is not using the entire 64by64
    [m,n] = size(dense1e);
    dense1epad = zeros(array_row,array_col-n); 
    dense1e = [dense1e,dense1epad];

    if (visualize == 1)
        figure('Renderer', 'painters', 'Position',[10 10 1200 1200])
        subplot(2,2,1)
        imagesc(dense1e); colormap('jet'); colorbar
        title('Mapping of Original Weights onto the Crossbar')
    end
    %% Find max of each tile
    % max1 = max(conv1w(:));
    % max2 = max(conv1b(:));
    % max3 = max(conv2w(:));
    % max4 = max(conv2b(:));
    %maxtile1 = max(max(max1,max2),max(max3,max4));
    maxtile1 = max(tile1(:));
    maxtile2 = max(tile2(:));
    maxtile3 = max(dense1a(:));
    maxtile4 = max(dense1b(:));
    maxtile5 = max(dense1c(:));
    maxtile6 = max(dense1d(:));
    maxtile7 = max(dense1e(:));
    maxtile8 = max(avgpool(:));

    max_weight = [maxtile1 maxtile2 maxtile3 maxtile4 maxtile5 maxtile6 maxtile7 maxtile8];
    %% Implement range R_max and R_min
    rmaxlimit = rmaxrange(1)+rand(1,8).*(rmaxrange(2)-rmaxrange(1));
    rminlimit = rminrange(1)+rand(1,8).*(rminrange(2)-rminrange(1));

    R_max = R_max.*rmaxlimit;
    R_min = R_min.*rminlimit;

    G_max = 1./R_min; %Calculate max conductance based on resistance
    G_min = 1./R_max; %Calculate min conductance based on resistance

    scaling_factor = (G_max - G_min)./max_weight;
    %% Implement weight resolution
    %Implement bit resolution in the memductance states
    G_step = (G_max - G_min)./(2^bit_res);
    % conv1_crossbar_tiled = round((conv1_crossbar_tiled_unscaled.*scaling_factor)./G_step)*G_step;

    tile1 = round((tile1.*scaling_factor(1))./G_step(1))*G_step(1)+G_min(1);
    tile2 = round((tile2.*scaling_factor(2))./G_step(2))*G_step(2)+G_min(2);
    dense1a = round((dense1a.*scaling_factor(3))./G_step(3))*G_step(3)+G_min(3);
    dense1b = round((dense1b.*scaling_factor(4))./G_step(4))*G_step(4)+G_min(4);
    dense1c = round((dense1c.*scaling_factor(5))./G_step(5))*G_step(5)+G_min(5);
    dense1d = round((dense1d.*scaling_factor(6))./G_step(6))*G_step(6)+G_min(6);
    dense1e = round((dense1e.*scaling_factor(7))./G_step(7))*G_step(7)+G_min(7);
    avgpool = round((avgpool.*scaling_factor(8))./G_step(8))*G_step(8)+G_min(8);


    if (visualize == 1)
        subplot(2,2,2)
        imagesc(dense1a); colormap('jet'); colorbar
        title('Mapping of Scaled Conductance Weights onto the Crossbar')
    end
    %% Introduce error
    %Error for tile 1
    tile1error = 1 + percenterror.*randn(size(tile1));
    tile1 = tile1.*tile1error;

    %Error for tile 2
    tile2error = 1 + percenterror.*randn(size(tile2));
    tile2 = tile2.*tile2error;

    %Error for tile 3
    dense1aerror = 1 + percenterror.*randn(size(dense1a));
    dense1a = dense1a.*dense1aerror;

    %Error for tile 4
    dense1berror = 1 + percenterror.*randn(size(dense1b));
    dense1b = dense1b.*dense1berror;

    %Error for tile 5
    dense1cerror = 1 + percenterror.*randn(size(dense1c));
    dense1c = dense1c.*dense1cerror;

    %Error for tile 6
    dense1derror = 1 + percenterror.*randn(size(dense1d));
    dense1d = dense1d.*dense1derror;

    %Error for tile 7
    dense1eerror = 1 + percenterror.*randn(size(dense1e));
    dense1e = dense1e.*dense1eerror;

    %Error for tile 8
    avgpoolerror = 1 + percenterror*randn(size(avgpool));
    avgpool = avgpool.*avgpoolerror;


    if (visualize == 1)
        subplot(2,2,3)
        imagesc(dense1a); colormap('jet'); colorbar
        title('Mapping of Scaled Conductance Weights with Error onto the Crossbar')
    end
    %% Stuck on/off (half at max conductance, half at min conductance)
    tostuck = randperm(array_row*array_col,round(array_row*array_col*stuck));
    [m,n] = size(tostuck);
    toGmin = tostuck(1,1:round(n/2));
    toGmax = tostuck(1,round(n/2)+1:end);

    tile1(toGmin) = G_min(1);
    tile2(toGmin) = G_min(2);
    dense1a(toGmin) = G_min(3);
    dense1b(toGmin) = G_min(4);
    dense1c(toGmin) = G_min(5);
    dense1d(toGmin) = G_min(6);
    dense1e(toGmin) = G_min(7);
    avgpool(toGmin) = G_min(8);

    tile1(toGmax) = G_max(1);
    tile2(toGmax) = G_max(2);
    dense1a(toGmax) = G_max(3);
    dense1b(toGmax) = G_max(4);
    dense1c(toGmax) = G_max(5);
    dense1d(toGmax) = G_max(6);
    dense1e(toGmax) = G_max(7);
    avgpool(toGmax) = G_max(8);


%     if (visualize == 1)
%         subplot(2,2,4)
%         imagesc(dense1a); colormap('jet'); colorbar
%         figure()
%         imagesc(dense1b); colormap('jet'); colorbar
%         title('Mapping of Scaled Conductance Weights with Error and Stuck On/Off onto the Crossbar')
%     end
    %% ADC and DAC parameters
    % Check for ADC resolution effects with serial binary inputs
    % Run through CNN on crossbar

    % ADC parameters
    % round_adc = 1;   % set to 1 if outputs are rounded by ADC
    % adjust_adc_flag = 0; % set to 1 if outputs are dynamically rounded by ADC
    % max_current = 1024*0.2*G_max;
    % ADC_bit = 8;
    % adc_res = max_current/2^ADC_bit; % for R_min = 10k, resolution is 80 uA

    % DAC parameters
    % input_bits = 8; % analog input divided into a certain number of bits
    % input_res = 0.2/(2^input_bits - 1);
    %accuracy_DAC = zeros(1,6);

    %% Import train files 
    % %without normalization
    % testdatafile = fopen('test/testdata.txt', 'r');
    % testlabelfile = fopen('test/testlabel.txt', 'r');
    % 
    % testdata = fscanf(testdatafile,'%f',[64,2560]);
    % testdata = permute(testdata,[2,1]);
    % testlabel = fscanf(testlabelfile,'%f',[1,2560]);



    % %with normalization [-1.2,1.2] against all sets
    % testdatafile = fopen('test2/testdata.txt', 'r');
    % testlabelfile = fopen('test2/testlabel.txt', 'r');
    % 
    % testdata = fscanf(testdatafile,'%f',[64,2560]);
    % testdata = permute(testdata,[2,1]);
    % testlabel = fscanf(testlabelfile,'%f',[1,2560]);



    % %with normalization [-1.2,1.2] against set AE
    % testdatafile = fopen('test3/testdata.txt', 'r');
    % testlabelfile = fopen('test3/testlabel.txt', 'r');
    % 
    % testdata = fscanf(testdatafile,'%f',[64,2560]);
    % testdata = permute(testdata,[2,1]);
    % testlabel = fscanf(testlabelfile,'%f',[1,2560]);



    %with normalization [-1.2,1.2] against set AE 0.97 accuracy
    testdatafile = fopen('testPytorch/testdata.txt', 'r');
    testlabelfile = fopen('testPytorch/testlabel.txt', 'r');

    testdata = fscanf(testdatafile,'%f',[64,2560]);
    %testdata = permute(testdata,[2,1]);
    testlabel = fscanf(testlabelfile,'%f',[1,2560]);
    %% Implement input resolution
    inputstep = (max(max(testdata)) - min(min(testdata)))./(2^inputbits-1);
    testdata = round(testdata./inputstep)*inputstep;
    %% Start train loop
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

    %% Save Predictions

    filename = sprintf('LowResSeed%dRmaxrange%.3fRminrange%.3fPercenterror%.3fBitres%dInputbits%dOutputbits%dStuck%.4fRsource%dRline%dRmax%dRmin%d.txt',seed,rmaxrange(2),rminrange(1),percenterror,bit_res,inputbits,outputbits,stuck,R_source,R_line,RMAX,RMIN);
    writematrix(predictions,filename);
    end
end