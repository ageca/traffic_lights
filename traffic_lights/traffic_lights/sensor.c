#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "sensor.h"
int sensor_status = 0; 

/* Semaphore */
pthread_mutex_t sensor_status_mutex = PTHREAD_MUTEX_INITIALIZER;

int initialize_sensor() {

	return 0;
}

int sensor_simulate() {

	time_t t;

    srand((unsigned) time(&t));

    pthread_mutex_lock(&sensor_status_mutex);
    sensor_status = rand()%2; 
    pthread_mutex_unlock(&sensor_status_mutex);

	return 0;

}

