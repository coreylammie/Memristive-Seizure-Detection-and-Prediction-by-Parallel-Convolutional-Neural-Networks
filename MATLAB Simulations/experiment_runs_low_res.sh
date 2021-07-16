#!/bin/bash
#SBATCH -N 1
#SBATCH --job-name=JCU-CL-MATLAB_experiment_runs_low_res
#SBATCH --mail-user=corey.lammie@jcu.edu.au 
#SBATCH --mail-type=END
#SBATCH -n 1
#SBATCH -c 32
#SBATCH --mem=50g
#SBATCH -o experiment_runs_low_res_out.txt
#SBATCH -e experiment_runs_low_res_error.txt
#SBATCH --partition=gpu
#SBATCH --gres=gpu:1
module load matlab/R2019b
module load cuda/11.3.0
module load gnu8/8.4.0
module load mvapich2
matlab -nodisplay -nosplash -r experiment_runs_low_res