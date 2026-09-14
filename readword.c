/******************************************
 **                                      **
 **    count number of char/word/line    **
 **                                      **
 ******************************************
 **              readword.c              **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/

#include "usrlib.h"

#define YES	1
#define NO	0

enum color { WHITE, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, BLACK, NO_COLOR = 99 };

struct
{
    unsigned type:3;       // delcare prototype to use bit expression
    unsigned trailer:3;
    unsigned crc:2;
} header;                  // This is just a example to learn 'C' syntax, so you had not better use external variables as this.

void main(void)
{
    int ch, word;

    int numchar, numword, numline;
    
    header.type = 0b000;
    header.trailer = 0b000;
    header.crc = 0b10;


    word = NO;
    numchar = numword = numline = 0;
    
    while((ch = getchar()) != EOF)
    {
        numchar++;

        if(ch == '\n') numline++;

        if( (word == NO) && (ch != ' ') && (ch != '\t') && (ch != '\n') )
        {
            word = YES;
            numword++;
        }

        if( (word == YES) && (ch == ' ' || ch == '\t' || ch == '\n') ) word = NO;
    }

    printf("\nTotal count of charaters is %d\ncount of word is %d\ncount of line is %d\n"
    , numchar, numword, numline);
}
