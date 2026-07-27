/******************************************
 **                                      **
 **        generate random number        **
 **                                      **
 ******************************************
 **              randomnum.c             **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/

#include "usrlib.h"

#define MAXNUM        100
#define SIDES         100
#define SCALE         65536

unsigned int dice_100(void);
//unsigned int dice_100(time_t the_time);
unsigned int rnd(unsigned int *random_num);
void sleep_ms(long ms);

int main()
{
    int i;                                   // to count index for loop
    int values[MAXNUM];                      // to save a random number of dice
    //time_t the_time;                       // to save real time by 1 second unit

    printf("\n++++++++++ Values of array ++++++++++\n");
    for(i = 0 ; i < MAXNUM ; i++)
    {
        values[i] = dice_100();
        //values[i] = dice(the_time);
        if(i % 20 == 0) printf("\n");
        printf("%3d ",values[i]);
    }

    printf("\n\n###### Mean of Array is %d\n\n", mean(values, MAXNUM)); 
}

unsigned int dice_100(void)
//unsigned int dice_100(time_t the_time)
{
    unsigned int seed;
    float roll;
    static unsigned int random_num;
    struct timespec ts;                // to save real time by any second unit
    
    sleep_ms(50);
    //sleep(1);

    clock_gettime(CLOCK_REALTIME, &ts);
    //time(&the_time);

    seed = ts.tv_nsec % SCALE;
    //seed = the_time % SCALE;

    roll = ( (float) rnd(&seed) / SCALE ) * SIDES + 1;

    return (unsigned int) roll;
}

unsigned int rnd(unsigned int *random_num)
{
    *random_num = *random_num % SCALE;
    //*random_num = (*random_num * 25173 + 13849) % SCALE;

    return *random_num;
}

void sleep_ms(long ms)
{
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000L;
    nanosleep(&ts, NULL);
}

