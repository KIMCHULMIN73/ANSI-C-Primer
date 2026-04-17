/******************************************
 **                                      **
 **         guess the exact number       **
 **                                      **
 ******************************************
 **                guess.c               **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HIGH	1000
#define LOW		1

void main(void)
{
    int random, innum, score;
    char name[50];
    
    srand(time(NULL));
    random = rand() % 100;
    score = HIGH;
    
    printf("\n\n**** Guess the exact number 1~%d !! ****\n\n",HIGH);
    //printf("%d",random);    
    
    printf("Fist, Input your name please : ");
    scanf("%s",&name);

    do
    {
        printf("\nInput a number you guess as answer : ");
		scanf("%d", &innum);
        
		if (random > innum)
		{ 
		    printf("why don't you input upper number?\n");
		    score -= 1;
		}
		else if(random < innum)
		{
		    printf("why don't you input lower number?\n");
		    score -= 1;
		}   

	} while(random != innum);
	
    printf("Congraturation %s, you success to guess the number %d on %dth tries.\nSo, your Score is %d\n\n", name, (random+innum)/2, HIGH-score+1, score); 
}
