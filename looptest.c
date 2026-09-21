/******************************************
 **                                      **
 **          test c loop function        **
 **                                      **
 ******************************************
 **              looptest.c              **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/

#include "usrlib.h"

#define LIMIT    20

void main(void)
{
    /* ZENNON'S ARROW with comma operation in for-loop */
    char ch = '!';     
    int a, b;
    int count;
    int max_number, divisor, find_prime, prime_count;
    float sum, x;

    system("clear");
    
    for (sum=0.0, x=1.0, count=1 ; ; count++, x *= 2.0)
    {
        sum += 1.0/x;
        printf("sum = %.16f when count = %d\n", sum, count);
        if(sum == 2)
        {
            printf("\nZENNON'S ARROW has arrived at the targt after %d attempts~!!\n", count);
            break;
        }
    }

    putchar('\n');

    /* to test do ~ while */

    a = 0, b = 1;

    do
    {
        printf("%d + %d = ", a, b);
        printf("%d\n", a += b);  
    } while (b++ < LIMIT)
        ;

    putchar('\n');

    /* to test while in do ~ while */

    do
    {
        count = 1;
        while (count++ <= 7)
            printf("%c= %3d  ",ch, ch++);
        printf("\n");
    } while(ch <= '~')
        ;

    putchar('\n');

    /* to find all Prime-Numbers under maximum number with nested for-loop */

    do
    {
        count = 1;
        prime_count = 0;
        printf("\n\nInput your number(>2) wanna find Prime Numbers in it : ");
        scanf("%d", &max_number);
    } while (max_number < 2)
        ;

    for (find_prime = 2 ; find_prime <= max_number ; find_prime++)
    {
        for (divisor = 2 ; find_prime % divisor != 0 ; divisor ++)
            ;

        if (find_prime == divisor)
        {
            printf("%6d ", find_prime);
            if (count++ % 10 == 0) printf("\n");
            prime_count++;
        }
    }
    printf("\nTotal Count of Prime numbers is %d in %d\n", prime_count, max_number); 
}
