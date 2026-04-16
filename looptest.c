#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FIRST	20
#define NEXT	17

#define LIMIT	15

void main(void)
{
	/* To test comma operation */
	int ounces, cost;
	
	printf("ounces        cost \n");
	for (ounces=1, cost=FIRST ; ounces <= 16 ; ounces++, cost += NEXT)
	    printf("%6d     %7d\n", ounces, cost);

	/* Zennon's arrow to test comma operation */	    
	int count;
	float sum, x;
	
	for (sum=0.0, x=1.0, count=1 ; count <= LIMIT ; count++, x *= 2.0)
	{
	    sum += 1.0/x;
	    printf("sum = %f when count = %d.\n", sum, count);
	}

	/* To test do ~ while */
	int a,b;
	
	a = 0, b = 1;
		
	do {
		    printf("%d + %d = ", a, b);
		    printf("%d\n", a += b);		    
	} while (b++ < LIMIT);
	
	/* To test while in do ~ while */
	char ch = '!';     
	
	do {
			count = 1;	
			while (count++ <= 7) printf("%c= %3d  ",ch, ch++);
			printf("\n");
	} while(ch <= '~');

	/* To find All Prime Numbers */
    int number, divisor, findprime;
    int cnt = 1, primecnt = 0;
    
    do {
        printf("\n\nInput your number(>2) wanna find Prime Numbers in it : ");
        scanf("%d", &number);		
	} while (number < 2);
    
    for (findprime = 2 ; findprime <= number ; findprime++) {
		for (divisor = 2 ; findprime % divisor !=0 ; divisor ++) ;
		
		if (findprime == divisor) {
			printf("%6d ", findprime);
			if (cnt++ % 10 == 0) printf("\n");
			primecnt++;
		}
	} 
	printf("\n");
	printf("Total Count of Prime numbers is %d in %d\n", primecnt, number); 
}
