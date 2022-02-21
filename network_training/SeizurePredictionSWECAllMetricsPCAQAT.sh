#!/bin/bash
#SBATCH -N 1
#SBATCH --job-name=SeizurePredictionSWECAllMetricsPCAQAT
#SBATCH --mail-user=corey.lammie@jcu.edu.au 
#SBATCH --mail-type=END
#SBATCH -n 1
#SBATCH -c 1
#SBATCH --mem=15g
#SBATCH -o /scratch/jcu/cl/TBioCAS/Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-Neural-Networks/network_training/SWEC_ETHZ_output.log
#SBATCH -e /scratch/jcu/cl/TBioCAS/Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-Neural-Networks/network_training/SWEC_ETHZ_output.log
#SBATCH --partition=gpu
#SBATCH --gres=gpu:1
module load anaconda/3.6
source activate /scratch/jcu/cl/.conda/snnenv
module load cuda/11.1.1
module load gnu8/8.4.0
module load mvapich2
export CUBLAS_WORKSPACE_CONFIG=:16:8
srun python3 /scratch/jcu/cl/TBioCAS/Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-Neural-Networks/network_training/SeizurePredictionSWECAllMetricsPCAQAT.py