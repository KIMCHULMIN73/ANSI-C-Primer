/******************************************
 **                                      **
 **            char to ascii             **
 **                                      **
 ******************************************
 **              char2asc.c              **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/
 
#include <stdio.h>

void main(void) /* converts 2 char to int */
{
    char ch;

    printf("Input a character by your keyboard.\n");
    scanf("%c",&ch);

    printf("ASCII CODE of \'%c\' is %d.\n", ch, ch);
}
