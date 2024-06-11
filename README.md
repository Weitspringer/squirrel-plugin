# Squirrel - Carbon-Aware Slurm Scheduling
The carbon-aware scheduler plugin for Slurm

## Prerequisites
- Slurm installation
- automake

## Setup
In order to use this plugin, you have to follow these steps:
1) Copy the `src/plugins/sched/squirrel` folder to the same path in your Slurm source code.
2) Overwrite Slurm's `src/plugins/sched/Makefile.am` with the same file from the squirrel-plugin repository.
3) In `slurm.conf`, set `SchedulerType=sched/squirrel`.
4) Execute automake in the root directory of Slurm.
5) Rebuild Slurm.
