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

#define LOW           1
#define HIGH          1000
#define INIT_SCORE    100

void main(void)
{
    int random, innum, score;
    char name[50];

    srand(time(NULL));
    random = rand() % HIGH;
    score = INIT_SCORE;

    system("clear");
    printf("*******************************************\n");
    printf("****                                   ****\n");
    printf("****    Welcom to GUESS-NUMBER game    ****\n");
    printf("****                                   ****\n");
    printf("*******************************************\n");
    printf("**   Guess the exact number  1~%d !!   **\n", HIGH);
    printf("*******************************************\n");
    
    printf("\nFist, Input your name please > ");
    scanf("%s",&name);

    while( getchar() != '\n')
        ;

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

    system("beep");
    system("beep");

    printf("\n\nCongraturation %s.\nYou success to guess the number %d on %dth tries.\nSo, your Score is %d\n\n", name, (random+innum)/2, (INIT_SCORE+1)-score, score); 
}
