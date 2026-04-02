/******************************************
 **                                      **
 **             user library             **
 **                                      **
 ******************************************
 **               usrlib.c               **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/
 
#include "./usrlib.h"

int getch(void)
{
    int ch;
    struct termios old;
    struct termios current;
    
    tcgetattr(0, &old);
    
    current = old;
    current.c_lflag &= ~(ICANON|ECHO);
    current.c_cc[VMIN] = 1;
    current.c_cc[VTIME] = 0;
    
    tcsetattr(0, TCSAFLUSH, &current);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &old);		
    
    return ch;	
}

void putch(char ch)
{
    putchar(ch);	
}

int getint(int *pint)
{
	char intarray[INT_LENGTH];
	int ch, index = 0;
	
	while(1)
	{
		ch = getch();

		if ( ch != EOF && ch != ' ' && ch != '\n' && ch != '\t' && index < INT_LENGTH )
		    intarray[index++] = ch;
		else break;

		putch(ch);
	}
	
	intarray[index] = '\0';
	
	if (ch == EOF) return STOP;
	else return str2int(intarray, pint);
}

int str2int(char string[], int *pint)
{
	int index = 0, sign = 1;
	
	if( string[index] == '+' || string[index] == '-')
		sign = (string[index++] == '+') ? 1 : -1;

	*pint = 0;
	
	while( '0' <= string[index] && string[index] <= '9' )
	{
	    *pint = 10 * (*pint) + (string[index++] - '0');
	}
	
	if( index != 0 && string[index] == '\0' )
	{
		*pint = sign * (*pint);
		return YES_NUM;
	}
	else return NO_NUM;
}

int int2str(int number, char* num_str)
{
	float num = (float)number;
	int i = 0, pwr = 1;
	char temp_ch[256];

    while( (int)(num/pwr) > (float)((1/3)*3) ) {
        temp_ch[i++] = '0' + (int)num % (pwr*10) / pwr;
		pwr *= 10;
	}
	
	while( i > 0 )
	    *(num_str++) = temp_ch[--i];
	*num_str = '\0';

    return SUCCESS;
}

void getstring(FILE *file, char string[])
{
	int ch, index = 0;
	
	while((ch = getc(file)) != EOF) string[index++] = ch;
	
	string[index] = '\0';
}

int getstr(FILE *file, char *string)
{	
	int cond = TRUE;

	while (cond) {
	*(string) = getc(file);
    if ( *(string++) == '\0' ) cond = FALSE;
    else cond = TRUE;
    }
    	
	return SUCCESS;
}

int putstr(FILE *file, char *string)
{
	while( *(string) != '\0' ) {
		putc(*string++, file);
	}
	putc('\0', file);
	
	return SUCCESS;
}

int strlength(char sl[])
{
    int charnum = 0;
    char *strptr;
    
    strptr = sl;

    while(*sl++ != '\0')
        charnum++;
        
    return charnum;
}

int getintarray(int pNumber[], int size)
{
	int index = 0;
	int num, result; 
	
	while ( index < size && (result = getint(&num)) != STOP )
	{
		if (result == YES_NUM )
		{
			pNumber[index++] = num;
			printf ("\nInteger is %d\n", pNumber[index-1] );
		}
		else if (result == YES_NUM ) printf ("\nNot integer\n");
		else printf ("\nInvalid Input.\n");
		
		printf("\n> ");
	}
	
	return index;	
}

void str2intarray(char string[], int integer[])
{
	int ind_str = 0, ind_int = 0;
	int sign = 1;
	while(string[ind_str] != '\0')
	{
		if( string[ind_str] == '\n' || string[ind_str] == ' ' || string[ind_str] == '\t' || string[ind_str] == '.' ) ind_str++;
		else
		{			
			if( string[ind_str] == '+' || string[ind_str] == '-')
			{
				sign = (string[ind_str] == '+') ? 1 : -1;
				ind_str++;
			}
			else sign = 1;
			
			integer[ind_int] = 0;
			while( '0' <= string[ind_str] && string[ind_str] <= '9' )
			{
				integer[ind_int] = 10 * integer[ind_int] + (string[ind_str] - '0');
				ind_str++;
			}
			
			integer[ind_int] = sign * integer[ind_int];
			//printf("Integer[%d] =  %d\n", ind_int, integer[ind_int]);
			ind_int++;
		}
	}
}

void str2floatarray(char string[], float floatarray[])
{
	int ind_str = 0, ind_float = 0, ptrflag, underptr, decimal;
	int sign = 1;
	while(string[ind_str] != '\0')
	{
		ptrflag = 0;
		underptr = 0;
		decimal = 1;
		
		if( string[ind_str] == '\n' || string[ind_str] == ' ' || string[ind_str] == '\t') ind_str++;
		else
		{
			if( string[ind_str] == '+' || string[ind_str] == '-')
			{
				sign = (string[ind_str] == '+') ? 1 : -1;
				ind_str++;
			}
			else sign = 1;
			
			floatarray[ind_float] = 0.0;
			while( ('0' <= string[ind_str] && string[ind_str] <= '9') || string[ind_str] == '.' )
			{
			    if(ptrflag == 1) underptr++;
				if (string[ind_str] != '.') floatarray[ind_float] = 10 * floatarray[ind_float] + (string[ind_str] - '0');
				else ptrflag = 1;

				ind_str++;
			}
			
			for(int i = 0; i < underptr ; i++) decimal *= 10;
			
			floatarray[ind_float] = sign * floatarray[ind_float] / decimal;
			//printf("Float[%d] =  %f\n", ind_float, floatarray[ind_float]);
			ind_float++;
		}
	}
}

void sort(int pNumber[], int size, int direction)
{
	int i, j;
	
	for (i = 0 ; i < size-1 ; i++)
	    for (j = i+1 ; j < size ; j++)
	        {
				if(direction == UP)
				{
					if(pNumber[i] > pNumber[j]) swapbypointer(&pNumber[i], &pNumber[j]);
				}
				else if(direction == DOWN)
				{
					if(pNumber[i] < pNumber[j]) swapbypointer(&pNumber[i], &pNumber[j]);
				}
				else ;
			}      
}

void swapbypointer(int *x, int *y)
{
	int temp;
	
	temp = *x;
	*x = *y;
	*y = temp;
}

struct numbers swapbystructure(int x, int y)
{
	int temp;
	struct numbers num;

	num.x = x;
	num.y = y; 
		
	temp = num.x;
	num.x = num.y;
	num.y = temp;
	
	return num;
}

#ifdef RANDOM_DICE
unsigned int dice(time_t the_time)
{
	unsigned int seed;
	float roll;
	
	sleep(1);
	
	time(&the_time);
	seed = the_time % SCALE;
	//printf("\nthe_time : %d , seed : %d\n", the_time, seed);
	printf("\n");
#else
unsigned int dice(time_t the_time, unsigned int seed)
{
	float roll;
#endif
	static unsigned int random_num = 1;
			
	setrnd(seed, &random_num);
	
	roll = ( (float) rnd(&random_num) / SCALE ) * SIDES + 1;
	
	return (unsigned int) roll;
}

unsigned int rnd(unsigned int *random_num)
{

	*random_num = (*random_num * 25173 + 13849) % SCALE;

	return *random_num;
}

void setrnd (unsigned int x, unsigned int *random_num)
{
	*random_num = x;	
}

int mean(int values[], int number)
{
	int index;
	long sum;
	
	if (number <= 0)
	{
		printf("ERR : Invalid array index. \n");
		return FAIL;
	}
	else
	{
		for(index = 0, sum = 0 ; index < number ; index++)
		{
			sum += *(values+index);			
		}
		return (int)(sum / number);
	}
}

void sortstring(char *input[], int ct)
{
	char *temp;
	int x, y;
	
	for ( x = 0 ; x < (ct-1) ; x++)
	    for ( y = (x+1) ; y < ct ; y++)
			if ( strcmp(input[x], input[y]) > 0){
				temp = input[x];
				input[x] = input[y];
				input[y] = temp;
			}
}

void sortstringbystrcpy(char (*input)[LINLEN], int ct)
//void sortstringbystrcpy(char *input, int ct)
{
	char temp[LINLEN];
	int x, y;

	//printf("\nInput Result\n");
	//for ( x = 0; x < LIM ; x++)
	    //puts(input[x]);
	    ////puts(&input[x*LINLEN]);
	    
	for ( x = 0 ; x < (ct-1) ; x++)
	    for ( y = (x+1) ; y < ct ; y++)
	        if ( strcmp(input[x], input[y]) > 0){
				strcpy(temp, input[x]);
				strcpy(input[x], input[y]);
				strcpy(input[y], temp);
			}
			//if ( strcmp(&input[x*LINLEN], &input[y*LINLEN]) > 0){
			//	strcpy(temp, &input[x*LINLEN]);
			//	strcpy(&input[x*LINLEN], &input[y*LINLEN]);
			//	strcpy(&input[y*LINLEN], temp);
			//}
}

