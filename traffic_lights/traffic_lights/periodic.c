#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
#include <mqueue.h>

#include "sensor.h"
#include "periodic.h"
#include "lights.h"


/* Thread function prototype */
void *tPeriodicThreadFunc(void *);
/* Thread counter */
int i = 0;
sig_atomic_t first_flag = 1; 
sig_atomic_t second_flag = 0;
sig_atomic_t third_flag = 0;

/**
 * Function starts periodic thread
 */
int init_periodic() {


	int status;

	/* Thread attributes variable */
	pthread_attr_t aPeriodicThreadAttr;
	/* Structure with time values */
	struct	itimerspec timerSpecStruct;
	/* Timer variable */
	timer_t	timerVar;
	/* Signal variable */
	struct	sigevent timerEvent;

	/* Initialize thread attributes structure */
	pthread_attr_init(&aPeriodicThreadAttr);

	/* Initialize event to create thread */
	timerEvent.sigev_notify = SIGEV_THREAD;
    timerEvent.sigev_notify_function = tPeriodicThreadFunc;
	timerEvent.sigev_notify_attributes = &aPeriodicThreadAttr;

	/* Create timer */
  	if ((status = timer_create(CLOCK_REALTIME, &timerEvent, &timerVar))) {
  		fprintf(stderr, "Error creating timer : %d\n", status);
  		return 0;
  	}

	/* Set up timer structure with time parameters */
	timerSpecStruct.it_value.tv_sec = 1;
	timerSpecStruct.it_value.tv_nsec = 0;
	timerSpecStruct.it_interval.tv_sec = 2;
	timerSpecStruct.it_interval.tv_nsec = 0;

	/* Initialize sensor */
	initialize_sensor();
	initialize_lights();
	/* Change timer parameters and run */
	timer_settime( timerVar, 0, &timerSpecStruct, NULL);

	return 0;
}

/*
 *  Periodic thread function
 */
void *tPeriodicThreadFunc(void *cookie) {

	/* Scheduling policy: FIFO or RR */
	int policy = SCHED_FIFO;
	/* Structure of other thread parameters */
	struct sched_param param;

	/* Read modify and set new thread priority */
	param.sched_priority = sched_get_priority_max(policy-1);
	pthread_setschedparam( pthread_self(), policy, &param);

    	/*Simulate sensor */
    
	sensor_simulate();
	if (first_flag){
		if (i < 1 ){
			firstTask_NS();
		}
		else if (i < 3){
			secondTask_NS();
		}
		else if (i < 5 && sensor_status == 1) {
			thirdTask_NS();
		}
		else{ 
			fourthTask_NS();
			first_flag = 0;
			second_flag = 1;
			i = -1; 
		}
	}
	else if (second_flag) {
		if (i < 1 ){
			firstTask_NESW();
		}
		else if (i < 3){
			secondTask_NESW();
		}
		else if (i < 5 && sensor_status == 1) {
			thirdTask_NESW();
		}
		else{ 
			fourthTask_NESW();
			second_flag = 0;
			third_flag = 1;
			i = -1; 
		}
	}
	else if (third_flag) {
		if (i < 1 ){
			firstTask_EW();
		}
		else if (i < 3){
			secondTask_EW();
		}
		else if (i < 5 && sensor_status == 1) {
			thirdTask_EW();
		}
		else{ 
			fourthTask_EW();
			first_flag = 1;
			third_flag = 0;			
			i = -1;
		}
	}
	printf("%d", lights_params[0]);
	i++;
	
	return 0;
}