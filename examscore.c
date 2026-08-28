/******************************************
 **                                      **
 **         calculate exam score         **
 **                                      **
 ******************************************
 **              examscore.c             **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define EXIT    0

void main(void)
{
    float average;
    int num, sum, highest, lowest;
    int i, *score;

    average = 0;
    sum = highest = lowest = 0;

    printf ("Input maximum number for exam grade process : ");
    scanf("%d", &num);
    printf ("\nEnter the %d scores now.\n\n", num);

    score = malloc(num);    //memory allocation in HEAP

    for (i = 0 ; i < num ; i++)
    {
        printf("Input Score : ");
        scanf("%d",&score[i]);
        printf("\n");
        if(score[i] < EXIT)
        {
            num = i; 
            break;
        }
    }

    printf("\nInput Result : ");

    for (i = 0 ; i < num ; i++)
    {
        printf("%5d", score[i]);
        sum += score[i];
    }

    printf("\n");
    average = (float)sum / (float)num;

    printf("Total score : %d , Average score : %.2f\n", sum, average);

    for (highest = score[0], lowest = score[0], i = 1 ; i < num ; i++)
    {
        if(highest < score[i]) highest = score[i];
        if(lowest > score[i]) lowest = score[i];
    }
    
    printf("The highest Score : %d , The lowest Score : %d\n", highest, lowest);
}
