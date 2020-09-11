#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#include "lights.h"
#include "periodic.h"
#include "sensor.h"

/* Keyboard thread function prototype */
void *tCycleThreadFunc(void *);

/* Thread variable */
pthread_t tCycleThread;
/* Thread attributes structure */
pthread_attr_t aCyclehreadAttr;

/* Parameters values */
int lights_params[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
/* Semaphores for params */

pthread_mutex_t params_mutex = PTHREAD_MUTEX_INITIALIZER;

int initialize_lights() {
    
	return 0;
}

int firstTask_NS() {
    pthread_mutex_lock(&params_mutex);
    lights_params[0] = 1;
    lights_params[4] = 0;
    lights_params[5] = 0; 
    pthread_mutex_unlock(&params_mutex);
    return 0; 

}
int secondTask_NS(){
    pthread_mutex_lock(&params_mutex);
    lights_params[0] = 2; 
    lights_params[6] = 2; 
    lights_params[7] = 2; 
    lights_params[3] = 2;
    pthread_mutex_unlock(&params_mutex);
    return 0; 
}
int thirdTask_NS(){
    pthread_mutex_lock(&params_mutex);
    lights_params[0] = 2; 
    lights_params[6] = 0; 
    lights_params[7] = 0; 
    lights_params[3] = 0;
    pthread_mutex_unlock(&params_mutex);
    return 0; 
}
int fourthTask_NS(){
    pthread_mutex_lock(&params_mutex);
    lights_params[0] = 3; 
    pthread_mutex_unlock(&params_mutex);

    return 0; 
}

int firstTask_NESW(){
    pthread_mutex_lock(&params_mutex);
    lights_params[0] = 0; 
    lights_params[1] = 1; 
    lights_params[6] = 1;
    pthread_mutex_unlock(&params_mutex);
    return 0; 
}
int secondTask_NESW(){
    pthread_mutex_lock(&params_mutex);
    lights_params[1] = 2; 
    lights_params[6] = 2;
    lights_params[2] = 2;
    pthread_mutex_unlock(&params_mutex);
    return 0; 
}
int thirdTask_NESW(){
    pthread_mutex_lock(&params_mutex);
    lights_params[1] = 2; 
    lights_params[6] = 2;
    lights_params[2] = 0;
    pthread_mutex_unlock(&params_mutex);
    return 0; 
}
int fourthTask_NESW(){
    pthread_mutex_lock(&params_mutex);
    lights_params[1] = 3; 
    lights_params[6] = 3;
    pthread_mutex_unlock(&params_mutex);
    return 0; 
}

int firstTask_EW(){
    pthread_mutex_lock(&params_mutex);
    lights_params[1] = 0; 
    lights_params[6] = 0;
    lights_params[4] = 1; 
    lights_params[5] = 1;
    pthread_mutex_unlock(&params_mutex);
    return 0; 
}
int secondTask_EW(){
    pthread_mutex_lock(&params_mutex);
    lights_params[4] = 2; 
    lights_params[5] = 2;
    lights_params[2] = 2; 
    lights_params[8] = 2; 
    pthread_mutex_unlock(&params_mutex);


    return 0; 
}
int thirdTask_EW(){
    pthread_mutex_lock(&params_mutex);
    lights_params[4] = 2; 
    lights_params[5] = 2;
    lights_params[2] = 0; 
    lights_params[8] = 0;  
    pthread_mutex_unlock(&params_mutex);
    return 0; 
}
int fourthTask_EW(){
    pthread_mutex_lock(&params_mutex);
    lights_params[4] = 3; 
    lights_params[5] = 3;
    pthread_mutex_unlock(&params_mutex); 
    return 0; 
}

