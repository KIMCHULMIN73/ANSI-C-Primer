/******************************************
 **                                      **
 **            test C pointer            **
 **                                      **
 ******************************************
 **               pointer.c              **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/

#include "usrlib.h"
#include <time.h>

void main(void)
{
	volatile unsigned int cpu_register;
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
	
	long int a, *ptr, **pptr;
	
	a = 324;
	ptr = &a;
	pptr = &ptr;
	
	printf("a : %u , ptr : ox%x , pptr : ox%x\n", a, ptr, pptr);
	
	**pptr += 25;
	
	printf("a : %u , &a : ox%x\n", a, &a);
	printf("*ptr : %u , ptr : ox%x , &ptr : ox%x\n", *ptr, ptr, &ptr);	
	printf("**pptr : %u , *pptr : ox%x , pptr : ox%x , &pptr : ox%x\n\n\n", **pptr, *pptr, pptr, &pptr);
	
	double power(int base, int exp);
	
	printf("%d ^ %d = %.2f\n", 2, 3, power(2,3));
	printf("%d ^ %d = %.2f\n", -3, 3, power(-3,3));
	printf("%d ^ %d = %.2f\n", 4, -2, power(4,-2));
	printf("%d ^ %d = %.2f\n", 5, 10, power(5,10));
	printf("%d ^ %d = %.2f\n", 0, -2, power(0,-2));
	printf("%d ^ %d = %.2f\n", -2, 0, power(-2,0));
	
	void recursive(int cnt_param);

	recursive(1);
}

void recursive(int cnt_param)
{
	static int cnt_static;
	int cnt_auto = 0;
	
	cnt_static++;
	cnt_param++;
	cnt_auto++;
	
	printf("I'm memory killer -> [static : %d] [param : %d] [auto : %d]\n", cnt_static, cnt_param, cnt_auto);
	recursive(cnt_param);
}

double power(int base, int exp)
{
	double answer;
	
	if(exp > 0) for(answer = 1 ; exp > 0 ; exp--) answer *= base;
	else if( exp == 0 || base == 0) answer = 1;
	else for(answer = 1 ; exp < 0 ; exp++) answer /= base;

	return answer;
}
