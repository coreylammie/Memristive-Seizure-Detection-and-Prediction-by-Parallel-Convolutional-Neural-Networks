#!/bin/bash
#SBATCH -N 1
#SBATCH --job-name=JCU-CL-CHBMIT
#SBATCH --mail-user=corey.lammie@jcu.edu.au 
#SBATCH --mail-type=END
#SBATCH -n 1
#SBATCH -c 1
#SBATCH --mem=100g
#SBATCH -o tmp/out.txt
#SBATCH -e tmp/error.txt
module load anaconda/3.6
source activate /scratch/jcu/cl/.conda/memtorch
module load cuda/11.1.1
module load gnu8/8.4.0
module load mvapich2
pip install -r /scratch/jcu/cl/CHBMIT/requirements.txt
srun python3 /scratch/jcu/cl/CHBMIT/extract_interval_data.py