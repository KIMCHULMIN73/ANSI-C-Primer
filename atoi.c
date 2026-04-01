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

#define issign(c)	( (c) == '-' || (c) == '+' ) ? (1) : (0)
#define SIZE	10
#define YES		1
#define NO		0

int main(int argc, char *argv[])
{
  char ch;
  static char number[SIZE];
  int value;
  int digit = YES;
  int count = 0;
	
	puts("Enter an integer");
	fgets(number,SIZE,stdin);
	
	if (number[SIZE-1] != '\0') {
		puts("Too many digit.");
		exit(1);
	}
	
	while ( (ch = number[count++]) != '\0' && digit == YES ) {
	    if ( issign(ch) || isdigit(ch) || isspace(ch) ) digit = YES;
	    else digit = NO; 	    
	}
	    
	printf("number[10] : %s \n", number);

	if (digit == YES ) {
		value = atoi(number);
		printf("Digit is %d\n",value);
	}
	else printf ("NO digit\n");
}
