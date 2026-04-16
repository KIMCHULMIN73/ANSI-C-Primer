#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE	1;
#define FALSE	0;
#define SM		60		// seconds in a minute
#define SH		3600	// seconds in an hour
#define MK		0.62137	// miles in kilometer

struct profile {
	int		time;
	int		minPmile;
	int		secPmile;
	float	dist_mile;
	float	mph;
	float	timePmile;
};

int CalculateTimeVelocity(float dist_kilo, int min, int sec, struct profile* running);

void main(void) /* calculation of time and velocity to run 1 mile */
{
	float dist_kilo;
	struct profile running;
	
	int min, sec;
	
	printf("Enter the distance you run in kilometer : ");
	scanf("%f", &dist_kilo);	

	printf("Enter the time you run in minutes & seconds . . . \n");
	printf("First, Enter the minutes : ");
	scanf("%d", &min);
	
	printf("\nThen, Enter the seconds : ");
	scanf("%d", &sec);

    CalculateTimeVelocity(dist_kilo, min, sec, &running);

    printf("\nYou ran %.3f km (%.3f miles) in %d min %d sec.\n", dist_kilo, running.dist_mile, min, sec);
    printf("This pace corresponds to running a mile in %d min %d sec.\n", running.minPmile, running.secPmile);
    printf("So, your average speed is %.3f mph.\n", running.mph);
}

int CalculateTimeVelocity(float dist_kilo, int min, int sec, struct profile* running)
{
	running->time = (SM * min) + sec;
	running->dist_mile = MK * dist_kilo;
	running->mph = (running->dist_mile / running->time) * SH;
	running->timePmile = (float)running->time / running->dist_mile;
	running->minPmile = (int)running->timePmile / SM;
	running->secPmile = (int)running->timePmile % SM;
	
	return TRUE;
}

