/******************************************
 **                                      **
 **             test string              **
 **                                      **
 ******************************************
 **               string.c               **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/
 
#include "./usrlib.h"

#define MSG		"You must have many talents. Tell me some."
#define MAX_LENGTH	256

char m1[] = "Just limit yourself to one line's worth.";
char *m2 = "If you can't think of anything, fake it.";

int main(argc, argv)
int argc;
char* argv[]; 
{
#ifdef STR_EXAM
	char name[LINLEN];
	static char talents[LINLEN];
	int i;
	char *m3 = "\nEnough about me -- What's your name?";
	static char *mytal[LIM] = {
		"Adding numbers swiftly",
		"Multiplying accurately",
		"Stashing data",
		"Following instructions to the letter",
		"Understanding the C language"
	};
	
	printf("Hi ! I'm Clyde the Computer. I have many talents.\n");
	printf("%s\n", "Let me tell you some of them.");
	puts("What were they? Ah, yes, here is partial list.");
	
	for ( i = 0 ; i < LIM ; i++ )
	    puts(mytal[i]);
	puts(m3);
	gets(name);
	
	printf("Well , %s, %s\n", name, MSG);
	printf("%s\n%s\n", m1, m2);
	
	gets(talents);
	puts("Let's see if I've got that list:");
	puts(talents);
	
	printf("Thank you for the information Sir, (Miss/Mr./Mrs.) %s\n", name);

    static char *ptr[] = {
		"Fucking KOREA", "Go to hell, GaeHanminkuk", "What a fucking korean flower.",
		"This is Powerful PC for U.S.A."};
		
	puts(ptr[0]);
	puts(ptr[1]);
	puts(ptr[2]);
	puts(ptr[3]);
	putchar('W');
	putchar('I');
	putchar('N');

//////////////////////////////////////////////////////////////////////	
    float x, y;
    
    printf("\n\nInput 2 float numbers\n");
    scanf("%f %f", &x, &y);
    printf("%f\n%e\n", x, y);

    int totallength;   
    char flower[LINLEN];
    char addon[] = "is smell like baking bread.";
       
    puts("What's your favorite flower?");
    gets(flower);
    totallength = strlen(addon) + strlen(flower) + 1;
    
    if(totallength < LINLEN)
        strcat(flower, addon);
    puts(flower);
	
//////////////////////////////////////////////////////////////////////	
	char *ptr2;
	ptr2 = malloc(LINLEN);
	
	while(*ptr2 != EOF) {
		putch('>');
		gets(ptr2);
		puts(ptr2);
	}
	
#else
    #define HALT	""

    char input[LIM][LINLEN];
    char *ptstr[LIM];
    int ct = 0;

    printf ("%s, \n", argv[0]);

    for ( ct = 0 ; ct < argc ; ct++) {
		if (argv[ct][0] == '-') {
			switch (argv[ct][1]) {
			case 'r' : printf ("%s \n", "reverse"); break;
			case 'b' : printf ("%s \n", "break"); break;
			case 'c' : printf ("%s \n", "clear"); break;
			case 'd' : printf ("%s \n", "deleted"); break;
			case 's' : printf ("%s \n", "saved"); break;
			case 'x' : printf ("%s \n", "xcopy"); break;
			default  : printf ("%s %d\n", "DEFAULT", argc);
			}
		
		}
	}
    
    ct = 0;
    
    printf("If you input Max. %d sentence, I will sort them.\n To stop, you can hit [ENTER] key.\n", LIM);
    
    while ( fgets(input[ct], MAX_LENGTH, stdin) != NULL && strcmp(input[ct], HALT) != 0 && ++ct < LIM) {
		ptstr[ct] = input[ct];
	}
	
	//sortstring(ptstr, ct++);
	sortstringbystrcpy(input, ct);
	
	printf("\n\nThe result of sorting sentence is as below.\n");
	for ( ct = 0; ct < LIM ; ct++)
	    //puts(ptstr[ct]);
	    puts(input[ct]);
#endif

	return SUCCESS;
}

