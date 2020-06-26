#!/bin/sh
#SBATCH --job-name=demo
#SBATCH --output=demo.o%j
#SBATCH --partition=nu-hpc
#SBATCH --nodes=1
#SBATCH --time=0:30:00


cd $SLURM_SUBMIT_DIR



###############Execution commands####################################

./demo

######################################################################

