/******************************************
 **                                      **
 **              dice game               **
 **                                      **
 ******************************************
 **              dicegame.c              **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define SIDES		6
#define SCALE		65536

static unsigned int random_num = 1;

unsigned int rnd(unsigned int *random_num);
void setrnd (unsigned int x, unsigned int *random_num);
unsigned int dice(time_t the_time);

void main(void) 
{
	int dice_num, i;
	time_t the_time;
	
	printf("Input number of dices : ", dice_num);
	scanf("%d", &dice_num);
	
	for(i = 0 ; i < dice_num ; i++) 
		printf("value of %d dice: %d\n", i+1, dice(the_time));
}


unsigned int dice(time_t the_time)
{
	unsigned int seed;
	float roll;

	sleep(1);	
	time(&the_time);
	seed = the_time % SCALE;

	printf("\n");

	static unsigned int random_num = 1;
			
	setrnd(seed, &random_num);
	
	roll = ( (float) rnd(&random_num) / SCALE ) * SIDES + 1;
	
	return (unsigned int) roll;
}

unsigned int rnd(unsigned int *random_num)
{

	*random_num = (*random_num * 25173 + 13849) % SCALE;

	return *random_num;
}

void setrnd (unsigned int x, unsigned int *random_num)
{
	*random_num = x;	
}



