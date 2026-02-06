#include "./usrlib.h"

#define UPPER	1
#define LOWER	0

int convlet(char *file_1, char *file_2, int option);

int main(int argc, char *argv[])
{

	FILE *fpt;
	long offset = 0L;
	int max, cnt;
    int flag = TRUE, option = UP;
    char ch;	
	max = cnt = 0;

    if (argc < 2) { puts("Must input file name to run program properly.\n"); goto EXIT; }
    else 
#ifdef CH15	
	{
		if ( (fpt = fopen(argv[1], "r")) == 0 ) printf("Cannot open the FILE %s\n", argv[1]);
		else {
			while( getc(fpt) != EOF ) max ++;
		    while (cnt++ < max) {
				if ( fseek(fpt, offset++, 0) == 0 ) putchar(getc(fpt));
				if ( fseek(fpt, -(offset+1), 2 ) == 0) putchar(getc(fpt));
			}
			fclose(fpt);
		}
	}
#else
    while(flag){
		printf("Input Option 'U' or 'L' to convert letters : ");
		scanf("%c", &ch);
		
		if( ch == 'U' || ch == 'u' ) { option = UP; flag = FALSE; }
		else if (ch == 'L' || ch == 'l' ) { option = DOWN; flag = FALSE; }
		else { printf ("\nInvalid Value\n\n"); getchar(); }
	}
	
	convlet(argv[1], argv[2], option);
    

#endif

EXIT :
}

int convlet(char *file_1, char *file_2, int option)
{
	FILE *fpt_1, *fpt_2;
	char *opt;
	int ch;
	
	if ( option == UP ) opt = "UPPER";
	else opt = "LOWER";

    if ( (fpt_1 = fopen(file_1, "r")) == 0 ) printf("Cannot open the FILE %s\n", file_1);
	else {
		printf("Start to convert from FILE '%s' to FILE '%s' with '%s' condition\n", file_1, file_2, opt);
		fpt_2 = fopen(file_2, "w");
		while( (ch = getc(fpt_1)) != EOF ){
			if( option == UP ) ch = islower(ch) ? toupper(ch) : ch;
			else ch = isupper(ch) ? tolower(ch) : ch;
			putc(ch, fpt_2);
		}
		fclose(fpt_1);
		fclose(fpt_2);
	}
	
	puts("THE END.");
	putch('\n');
}
