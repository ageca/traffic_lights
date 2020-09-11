#ifndef SENSOR_H_
#define SENSOR_H_

/* Make public var */
extern int sensor_status; 
/* Make semaphore for my var */
extern pthread_mutex_t sensor_status_mutex;

/* Initialization function */
int initialize_sensor(void); 
/* Simulate sensor function */
int sensor_simulate(void);

#endif /* SENSOR_H_ */