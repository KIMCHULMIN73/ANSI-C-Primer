#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define EXIT	-999

void main(void)
{
		int max, sum, highest, lowest, i, innum;
		float average;
		int *score;
		
		sum = average = highest = lowest = 0;
		
		printf ("Input maximum number for exam grade process : ");
		scanf("%d", &max);

		printf ("\nEnter the %d scores now.\n\n", max);
		
		innum = max;
		score = malloc(innum);
				
		for (i = 0 ; i < max ; i++) {
			printf("Input Score : ");
			scanf("%d",&score[i]);
			printf("\n");
			if(score[i] == EXIT) {
				innum = i; 
				break;
			}
		}
		
		printf("\nInput Result : ");
		for (i = 0 ; i < innum ; i++) {
			printf("%5d", score[i]);
			sum += score[i];
		}
		printf("\n");
		average = (float)sum / (float)innum;
		
		printf("Total score : %d , Average score : %.2f\n", sum, average);
		
		for (highest = score[0], lowest = score[0], i = 1 ; i < innum ; i++) {
			if(highest < score[i]) highest = score[i];
			if(lowest > score[i]) lowest = score[i];
		}
		printf("The highest Score : %d , The lowest Score : %d\n", highest, lowest);		
}
