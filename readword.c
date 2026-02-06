#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./chio.h"

#define YES	1
#define NO	0

void main(void)
{
    int ch, word;
    
    int numchar, numword, numline;
    
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
