/******************************************
 **                                      **
 **          test data structure         **
 **                                      **
 ******************************************
 **             datastruct.c             **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "./usrlib.h"

#define MAXBOOKS    100
#define HALT        ""
#define LEN         20

struct book
{
    char title[LINLEN];
    char author[LINLEN];
    int pages;
    char date[11];
    int value;
};

struct name
{
    char first[LEN];
    char last[LEN];
};

struct guy
{
    struct name names;
    char favfood[LEN];
    char job[LEN];
    float income;
};

struct funds
{
    char *bank;
    float bankfund;
    char *save;
    float savefund;
} stan = {"Garlic Melon Bank", 1023.4, "Snoopy's Saving and Loan", 4239.87};

int main(argc, argv)
int argc;
char* argv[];
{
    int i = 0;
    struct book mybook = {"Life is", "Chulmin Kim", 486, "1999/09/09", 500000};
    static struct book manybook[MAXBOOKS];

    printf("| %s | %s | %d pages | %d won | %s |\n", mybook.title, mybook.author,
            mybook.pages, mybook.value, mybook.date); 

    while (i < MAXBOOKS)
    {
        printf("Input title of book %d : ", i+1);
        fgets(manybook[i].title, LINLEN, stdin);
        if( strcmp(manybook[i].title, HALT) != 0)
            ;
        else
            break;

        printf("Input author of book %d : ", i+1);
        fgets(manybook[i].author, LINLEN, stdin);

        printf("Input date of book %d (yyyy/mm/dd): ", i+1);
        fgets(manybook[i].date, 11, stdin);

        printf("Input pages of book %d : ", i+1);
        scanf("%d", &(manybook[i].pages));

        printf("Input value of book %d : ", i+1); 
        scanf("%d", &(manybook[i].value));

        while(getch() != '\n');

        printf("| %s | %s | %d pages | %d won | %s |\n  ", manybook[i].title, manybook[i].author,
                manybook[i].pages, manybook[i].value, manybook[i++].date); 		
    }
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct guy collegue[2] = { {"Robert", "Johnson", "dduckbbaegi", "rich man", 990000000}, 
                               {"Jung", "Yura", "dounut", "rich girl",990000000} };

    struct guy *who;

    who = &collegue[0];

    printf("[ARRAY] address 1 : %u , address 2 : %u\n", &collegue[0], &collegue[1]);
    printf("[POINTER] address 1 : %u , address 2 : %u\n", who, who+1);

    printf("%s  %s  %s  %s  %u\n", who->names.first, who->names.last, who->favfood, (*who).job, (*who).income);
    printf("%s  %s  %s  %s  %u\n", (who+1)->names.first, (who+1)->names.last, (*(who+1)).favfood, (who+1)->job, (*(who+1)).income);	

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct funds nats[1] = {{"Melon Garlic Bank", 1024.4, "Simpson's Saving and Loan", 4233.33}};

    float sum(float x, float y);
    float sumbyptr(struct funds *stan);
    float sumbyref(struct funds stan);

    printf( "\n%s : %f\n%s : %f\nSUM : %f\n", stan.bank, stan.bankfund, stan.save, stan.savefund, sum(stan.bankfund, stan.savefund) );

    printf( "SUM by pointer : %f\n", sumbyptr(&stan) );

    printf( "SUM by reference : %f\n", sumbyref(stan) );

    printf( "SUM by array : %f\n", sumbyptr(nats) );

    return SUCCESS;
}

float sumbyref(struct funds stan) /* This expression is allowed Since "LATTICE C 3.0" */
{
    float sum;

    sum = stan.bankfund + stan.savefund;

    return sum;

}

float sumbyptr(struct funds *stan)
{
    float sum;

    sum = stan->bankfund + stan->savefund;

    return sum;
}

float sum(float x, float y)
{
    float sum;

    sum = x + y;

    return sum;
}
