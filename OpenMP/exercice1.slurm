#!/bin/sh
#SBATCH --job-name=exercice1
#SBATCH --output=exercice1.o%j
#SBATCH --partition=nu-hpc
#SBATCH --ntasks=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=64
#SBATCH --nodes=1
#SBATCH --time=0:30:00


cd $SLURM_SUBMIT_DIR



###############Execution commands####################################

./exercice1


######################################################################

