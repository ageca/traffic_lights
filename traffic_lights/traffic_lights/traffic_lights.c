#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mqueue.h>
#include <pthread.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>


#include "sensor.h"
#include "periodic.h"
#include "lights.h"


/*
 * Main project function
 */
int main(int argc, char *argv[]) {


	init_periodic();

 	while(getc(stdin)=='q') {};
		
	return EXIT_SUCCESS;
}