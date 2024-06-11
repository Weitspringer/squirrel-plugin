/*****************************************************************************\
 *  squirrel.h - Carbon aware scheduler plugin.
 *****************************************************************************
 *  Produced at University of Potsdam, Hasso Plattner Institute.
 *  Written by Luca Springer <luca.springer@student.hpi.de>
\*****************************************************************************/


#ifndef _SLURM_SQUIRREL_H
#define _SLURM_SQUIRREL_H

/* squirrel_agent - detached thread periodically when pending jobs can start */
extern void *squirrel_agent(void *args);

/* Terminate squirrel_agent */
extern void stop_squirrel_agent(void);
    
/* Note that slurm.conf has changed */
extern void squirrel_reconfig(void);

#endif	/* _SLURM_SQUIRREL_H */