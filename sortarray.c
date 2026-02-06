#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "./usrlib.h"

void main (void)
{
	int *pNumber, size, direction;
	char sortway;
	
	printf("Input the max size of integer array : ");
	getint(&size);
	pNumber = malloc(size);
	printf("\n> ");
	
	size = getintarray(pNumber, size);
	
	printf("Total count is %d\n", size);
	for(int i = 0 ; i < size ; i++) printf("%d    ",pNumber[i]);

	printf("\nInput the way for sorting - U(p)/D(own) ? ");
	sortway = getch();
	
	if (sortway == 'U' || sortway == 'u') direction = 1;
	else if (sortway == 'D' || sortway == 'd') direction = -1;
	else direction = 1;

	sort(pNumber, size, direction);
	for(int i = 0 ; i < size ; i++) printf("%d    ",pNumber[i]);
	printf("\n");
}
