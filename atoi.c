/******************************************
 **                                      **
 **           ascii to integer           **
 **                                      **
 ******************************************
 **                atoi.c                **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/

#include "./usrlib.h"

#define YES     1
#define NO      0
#define SIZE    10
#define issign(c)    ( (c) == '-' || (c) == '+' ) ? (1) : (0)

int main(int argc, char *argv[])
{
    char ch;
    char number[SIZE] = {0};    //must initialize this array to zero
    int value;
    int digit = YES;
    int count = 0;

    puts("Enter an integer");
    fgets(number,SIZE,stdin);

    if (number[SIZE-1] != '\0')
    {
        puts("Too many digit.");
        exit(1);
    }

    while ( (ch = number[count++]) != '\0' && digit == YES )
    {
        if ( issign(ch) || isdigit(ch) || isspace(ch) )    // isdigit(),isspace() are standard macro in <ctype.h>
            digit = YES;
        else
            digit = NO;
    }

    printf("\n>input value : %s \n", number);

    if (digit == YES )
    {
        value = atoi(number);    // atoi() is standard library in <stdlib.h>
        printf(">Digit is %d\n\n",value);
    }
    else
        printf ("NO digit\n\n");
}
