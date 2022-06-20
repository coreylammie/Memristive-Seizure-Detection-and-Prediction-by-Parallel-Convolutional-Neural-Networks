% mycluster=parcluster('local');
% mycluster.NumWorkers=32;
% parpool('local', 32);
n_seed = 5;
output_dir = 'out';
table_headers = {'seed', 'R_min_range', 'R_max_range', 'percent_error', 'bit_res', 'input_bits', 'output_bits', 'stuck', 'R_source', 'R_line', 'R_min', 'R_max', 'predictions_file_path'};
table_data = cell(n_seed, 13);
for seed=1:n_seed
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
    end_num = start_num + 249;
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    R_max = 100E3; %100 kohm is max resistance of memristors
    R_min = 10E3;  %10 kohm is min resistance of memristors

    rminrange = [0.95,1]; %limit for min_R [1,1] to turn off
    rmaxrange = [1,1.05]; %limit for max_R [1,1] to turn off

    percenterror = 0.05; %percent error for crossbar implementation, 0 to turn off

    V_BL = zeros(64,1); %Ground column voltages (set columns to 0 V)
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

%     if (visualize == 1)
        figure('Renderer', 'painters', 'Position',[10 10 1200 1200])
        subplot(2,2,1)
        imagesc(dense1e); colormap('jet'); colorbar
        title('Mapping of Original Weights onto the Crossbar')
%     end
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


%     if (visualize == 1)
        subplot(2,2,2)
        imagesc(dense1a); colormap('jet'); colorbar
        title('Mapping of Scaled Conductance Weights onto the Crossbar')
%     end
    
end
T = cell2table(table_data);
T.Properties.VariableNames = table_headers;
writetable(T,'out/experiment_runs.csv')  