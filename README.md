# Squirrel - Carbon-Aware Slurm Scheduling
The carbon-aware scheduler plugin for Slurm

## Prerequisites
- You can access the source code of your Slurm installation.

## Setup
In order to use this plugin, you have to follow these steps:
1) Copy the `src/plugins/sched/squirrel` folder to the same path in your Slurm source code.
2) In `slurm.conf`, set `SchedulerType=sched/squirrel`.
3) Rebuild Slurm.
