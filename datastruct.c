/******************************************
 **                                      **
 **          test data structure         **
 **                                      **
 ******************************************
 **             datastruct.c             **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/

#include "./usrlib.h"

#define MAXBOOKS    100
//#define HALT        '\n'
#define HALT        "\n"
#define LIM         5
#define LEN         20

struct book
{
    char title[LINLEN];
    char author[LINLEN];
    char date[LINLEN];
    int pages;
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

int main(argc, argv)    //we can declare C function prototypes as this style.
int argc;
char* argv[];
{
/*Test struct book */
    int i = 0;
    static struct book manybook[MAXBOOKS];
    struct book mybook = {"Life is", "Chulmin Kim", "1999/09/09", 486, 500000};

    system("clear");
    printf("<SAMPLE CODE>\n| %s | %s | %d pages | %d won | %s |\n", mybook.title, mybook.author,
            mybook.pages, mybook.value, mybook.date); 

    while (i < MAXBOOKS)
    {
        printf("\nInput title of book %d : ", i+1);
        fgets(manybook[i].title, LINLEN, stdin);     //why we use fgets() instead of scanf() in this line?

        //if(manybook[i].title[0] == HALT)           //compare between characters
        if(strcmp(manybook[i].title, HALT) == 0)     //compare between strings
            break;
        else
            ;

        printf("Input author of book %d : ", i+1);
        fgets(manybook[i].author, LINLEN, stdin);    //why we use fgets() instead of scanf() in this line?
        //scanf("%s",manybook[i].author);

        printf("Input date of book %d (yyyy/mm/dd): ", i+1);
        fgets(manybook[i].date, LINLEN, stdin);          //why we use fgets() instead of scanf() in this line?
        //scanf("%s",manybook[i].date);
        
        printf("Input pages of book %d : ", i+1);
        scanf("%d", &(manybook[i].pages));          //why we use scanf() instead of fgets() in this line?

        printf("Input value of book %d : ", i+1); 
        scanf("%d", &(manybook[i].value));          //why we use scanf() instead of fgets() in this line?

        flush_stdin();
        while(getch() != '\n');

        manybook[i].title[strcspn(manybook[i].title, "\n")] = '\0';      //remove '\n' from string
        manybook[i].author[strcspn(manybook[i].author, "\n")] = '\0';    //remove '\n' from string
        manybook[i].date[strcspn(manybook[i].date, "\n")] = '\0';        //remove '\n' from string

        printf("| %s | %s | %d pages | %d won | %s |\n  ", manybook[i].title, manybook[i].author,
                manybook[i].pages, manybook[i].value, manybook[i++].date);

        flush_stdin();
    }

/*Test struct guy */

    struct guy collegue[2] = { {"Robert", "Johnson", "pizza", "rich man", 990000000}, 
                               {"Park", "Dducksun", "dduckbbaegi", "rich girl",990000000} };

    static struct guy *who;

    who = &collegue[0];

    printf("\n\n[ARRAY]   address 1 : %u , address 2 : %u\n", &collegue[0], &collegue[1]);
    printf("[POINTER] address 1 : %u , address 2 : %u\n", who, who+1);

    printf("%s  %s  %s  %s  %u\n", who->names.first, who->names.last, who->favfood, (*who).job, (*who).income);
    printf("%s  %s  %s  %s  %u\n", (who+1)->names.first, (who+1)->names.last, (*(who+1)).favfood, (who+1)->job, (*(who+1)).income);	

/*Test struct funds */

    struct funds nats[1] = {{"Melon Garlic Bank", 1024.4, "Simpson's Saving and Loan", 4233.33}};

    //we can declare function prototype as below in main(), but this way is not recommended.
    float sum(float x, float y);
    float sumbyptr(struct funds *stan);
    float sumbyref(struct funds stan);

    printf( "\n\n%s : %f\n%s : %f\nSUM : %f\n", stan.bank, stan.bankfund, stan.save, stan.savefund, sum(stan.bankfund, stan.savefund) );

    printf( "SUM by pointer : %f\n", sumbyptr(&stan) );

    printf( "SUM by reference : %f\n", sumbyref(stan) );

    printf( "\n\n%s : %f\n%s : %f\nSUM : %f\n", nats->bank, nats->bankfund, nats[0].save, nats[0].savefund, sum(nats->bankfund, nats->savefund) );

    return SUCCESS;
}

float sum(float x, float y)
{
    float sum;

    sum = x + y;

    return sum;
}

float sumbyref(struct funds stan)    //structure type can be allowed as input parameter for functios, Since "LATTICE C 3.0"
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
