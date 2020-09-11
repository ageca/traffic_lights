#ifndef LIGHTS_H_
#define LIGHTS_H_


/* Make this vars public */
extern int lights_params[9];
/* Make semaphores for my vars public */
extern pthread_mutex_t params_mutex;

/* Tasks for cycle */
int firstTask_NS(void);
int secondTask_NS(void);
int thirdTask_NS(void);
int fourthTask_NS(void);
int firstTask_NESW(void);
int secondTask_NESW(void);
int thirdTask_NESW(void);
int fourthTask_NESW(void);
int firstTask_EW(void);
int secondTask_EW(void);
int thirdTask_EW(void);
int fourthTask_EW(void);

/* Function initialize lights thread */
int initialize_lights();

#endif /* LIGHTS_H_ */