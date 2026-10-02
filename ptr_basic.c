/******************************************
 **                                      **
 **            test C pointer            **
 **                                      **
 ******************************************
 **              ptr_basic.c             **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/

#include "usrlib.h"

void main(void)
{
/* EXAMPLE 01 */
    int current, next;
    struct numbers num;

    current = 0, next = 100;
    printf("[BEFORE] current : %d , next : %d\n", current, next);
    swapbypointer(&current, &next);
    printf("[AFTER] current : %d , next : %d\n", current, next);

    current = 1000, next = 2000;
    printf("[BEFORE] current : %d , next : %d\n", current, next);
    num = swapbystructure(current, next);
    printf("[AFTER] current : %d , next : %d\n\n", num.x, num.y);

/* EXAMPLE 02 */
    long int val, *ptr, **pptr;

    val = 12345;
    ptr = &val;
    pptr = &ptr;

    printf("val : %u , ptr : ox%x , pptr : ox%x\n", val, ptr, pptr);

    **pptr += 54321;

    printf("val : %u , &a : ox%x\n", val, &val);
    printf("*ptr : %u , ptr : ox%x , &ptr : ox%x\n", *ptr, ptr, &ptr);	
    printf("**pptr : %u , *pptr : ox%x , pptr : ox%x , &pptr : ox%x\n\n\n", **pptr, *pptr, pptr, &pptr);

/* EXAMPLE 03 */
    double power(int base, int exp);

    printf("%d ^ %d = %.2f\n", 2, 3, power(2,3));
    printf("%d ^ %d = %.2f\n", -3, 3, power(-3,3));
    printf("%d ^ %d = %.2f\n", 4, -2, power(4,-2));
    printf("%d ^ %d = %.2f\n", 5, 10, power(5,10));
    printf("%d ^ %d = %.2f\n", 0, -2, power(0,-2));
    printf("%d ^ %d = %.2f\n", -2, 0, power(-2,0));

/* EXAMPLE 04 */
    void recursive(int cnt_param);
    printf("\n\nPush Enter Key to proceed");
    getchar();
    recursive(0);
}

double power(int base, int exp)
{
    double answer;

    if(exp > 0)
        for(answer = 1 ; exp > 0 ; exp--)
            answer *= base;
    else if( exp == 0 || base == 0)
        answer = 1;
    else
        for(answer = 1 ; exp < 0 ; exp++)
            answer /= base;

    return answer;
}

void recursive(int cnt_param)
{
    static int cnt_static;
    int cnt_auto = 0;
    static int *cnt_heap;

    if(cnt_static == 0)
    {
        cnt_heap = malloc(sizeof(int));
        if(cnt_heap == NULL)
            exit(-1);
        else
            (*cnt_heap) = 0;    // brakets are very important to keep operation priority
    }

    cnt_static++;
    cnt_param++;
    cnt_auto++;
    (*cnt_heap)++;             // brakets are very important to keep operation priority

    printf("I'll make stack overflow -> [static : %d] [param : %d] [auto : %d] [heap : %d]\n", cnt_static, cnt_param, cnt_auto, *cnt_heap);
    recursive(cnt_param);
}

