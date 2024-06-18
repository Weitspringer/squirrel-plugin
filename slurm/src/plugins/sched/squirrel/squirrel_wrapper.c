/*****************************************************************************\
 *  squirrel.c - NO-OP plugin for carbon aware scheduler.
 *****************************************************************************
 *  Produced at University of Potsdam, Hasso Plattner Institute.
 *  Written by Luca Springer <luca.springer@student.hpi.de>
\*****************************************************************************/

#include <stdio.h>

#include "slurm/slurm_errno.h"

#include "src/common/plugin.h"
#include "src/common/log.h"
#include "src/common/node_select.h"
#include "src/slurmctld/job_scheduler.h"
#include "src/slurmctld/reservation.h"
#include "src/slurmctld/slurmctld.h"
#include "src/plugins/sched/squirrel/squirrel.h"

const char		plugin_name[]	= "Slurm Squirrel Scheduler plugin";
const char		plugin_type[]	= "sched/squirrel";
const uint32_t		plugin_version	= SLURM_VERSION_NUMBER;

static pthread_t squirrel_thread = 0;
static pthread_mutex_t thread_flag_mutex = PTHREAD_MUTEX_INITIALIZER;

int init(void)
{
	sched_verbose("Squirrel scheduler plugin loaded");

	slurm_mutex_lock( &thread_flag_mutex );
	if ( squirrel_thread ) {
		debug2( "Squirrel scheduler thread already running, "
			"not starting another" );
		slurm_mutex_unlock( &thread_flag_mutex );
		return SLURM_ERROR;
	}

	/* since we do a join on this later we don't make it detached */
	slurm_thread_create(&squirrel_thread, squirrel_agent, NULL);

	slurm_mutex_unlock( &thread_flag_mutex );

	return SLURM_SUCCESS;
}

void fini(void)
{
	slurm_mutex_lock( &thread_flag_mutex );
	if ( squirrel_thread ) {
		verbose( "Squirrel scheduler plugin shutting down" );
		stop_squirrel_agent();
		pthread_join(squirrel_thread, NULL);
		squirrel_thread = 0;
	}
	slurm_mutex_unlock( &thread_flag_mutex );
}

extern int sched_p_reconfig(void)
{
	squirrel_reconfig();
	return SLURM_SUCCESS;
}