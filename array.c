/******************************************
 **                                      **
 **              test array              **
 **                                      **
 ******************************************
 **                array.c               **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/

#include "usrlib.h"

#define MAXNUM		100

unsigned int rnd(unsigned int *random_num);
void setrnd (unsigned int x, unsigned int *random_num);
unsigned int dice(time_t the_time);

int main(int argc, char* argv[])
{
	int index, values[MAXNUM];
	time_t the_time;
	
	printf("++++++++++ Values of array ++++++++++\n");
	for(index = 0 ; index < MAXNUM ; index++)
	{
		values[index] = dice(the_time);
		if(index % 20 == 0) printf("\n");
		printf("%3d ",values[index]);
	}
		
	printf("\n###### Mean of Array is %d\n\n", mean(values, MAXNUM));
	
#define PR(X)	printf("X = %u , *X = %5d , &X = %u\n", X, *X, &X)
    static int urn[] = {100, 200, 300};
    int *ptr1, *ptr2;
    
    ptr1 = urn; /* ptr1 = &urn[0] */
    ptr2 = &urn[2];  
    
    PR(ptr1);
    ptr1++;
    PR(ptr1);
    PR(ptr2);
    ++ptr2;
    PR(ptr2);
    printf("ptr2 - ptr1 = %u\n\n\n", ptr2 - ptr1);
    
#define MONTHS		12
#define YEARS		5

    FILE *in;
    char string[STR_LENGTH];
    //int integer[STR_LENGTH];
    float floatarray[STR_LENGTH];
    
    static float rainfall[YEARS][MONTHS];
    int year, month;
    float subtot, total, avg[MONTHS];

 	
	in = fopen(argv[1],"r");
	if(in == NULL) return -1;
	
	getstring(in, string);
	//str2intarray(string, integer);
	str2floatarray(string, floatarray);
	fclose(in);

	printf("**************************************************************************************\n");	
	printf("  YEAR  :  JAN  FEB  MAR  APR  MAY  JUN  JLY  AUG  SEP  OCT  NOV  DEC  :  TOTAL  AVG  \n");
	printf("--------------------------------------------------------------------------------------\n");	
	
	for (year = 0 ; year < YEARS  ; year++)
	{
	    printf("%6d  : ",    1970+year);

	    for(month = 0, subtot = 0 ; month < MONTHS ; month++)
	    {
	        rainfall[year][month] = floatarray[year*MONTHS+month];
	        subtot += rainfall[year][month]; 
	        if(rainfall[year][month] > 9.9) printf("%2.1f ",rainfall[year][month]);
	        else printf(" %2.1f ",rainfall[year][month]);
		}
		printf("    %2.1f   %2.2f\n", subtot, (float)subtot/MONTHS);
	}
	
	printf("---------------------------------------------------------------------------------------\n");
	printf(" TOTAL  :");

	
	for (month = 0, total = 0 ; month < MONTHS ; month++)
	{
	    for (year = 0, subtot = 0 ; year < YEARS  ; year++)
	    {
			subtot += rainfall[year][month];
		}
		if(subtot > 9.9) printf(" %2.1f",subtot);
	    else printf("  %2.1f",subtot);

	    total += subtot;
	    avg[month] = (float)subtot/YEARS;
	}

	printf("    %2.1f   %2.2f\n", total, (float)total/YEARS);

	printf("   AVG  :");
	for (month = 0 ; month < MONTHS ; month++)
	    if(avg[month] > 9.9) printf("%2.2f",avg[month]);
	    else printf(" %2.2f",avg[month]);

	printf("    %2.2f   %2.2f\n", (float)total/YEARS, (float)total/YEARS/MONTHS);
	
	printf("**************************************************************************************\n");	

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

