/******************************************
 **                                      **
 **           test allocation            **
 **                                      **
 ******************************************
 **                alloc.c               **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/

#include "./usrlib.h"

#define HALT	""
#define BLOCK		100
#define LENLIN		40
#define MAX			50
#define DRAMA		20000

struct linklist {
	char ch;
	struct linklist *next;
};

struct linklist *makenode(struct linklist *rp, char ch);
void prnt(struct linklist *root);

void main(void)
#ifndef EX1
{
	char ch;
	struct linklist *root;

    root = NULL;    
    while( (ch = getch()) != 24 ) {
		putch(ch);
		putch('\n');
        root = makenode(root, ch);
	}
        
    prnt(root);
}

struct linklist *makenode(struct linklist *rp, char ch)
{
	if (rp == NULL) {
		rp = malloc( sizeof(struct linklist) );
		rp->ch  = ch;
		rp->next = NULL;
	}
	else
	    rp->next = makenode(rp->next, ch);
	
    return rp;
}

void prnt(struct linklist *rp)
{
	if(rp != NULL) {
		prnt(rp->next);
		printf("%c\n", rp->ch);
	}
	else ;
}

#else
{
	char store[BLOCK], symph[LENLIN];
	char *starts[MAX],  *end;
	int index = 0, count = 0, flag = TRUE, cmp;
	
	starts[0] = store;
	end = starts[0] + BLOCK - 1;
	
	printf("Input long names to test malloc()\n");

	while(flag) 
	{
		gets(symph);
     		
		if ( strcmp(symph, HALT) == 0) flag = FALSE;
		else flag = TRUE;

		if( strlen(symph) > end - starts[index] ) {
			puts("alloc more memory\n");
			
			starts[index] = malloc(BLOCK);
			end = starts[index] + BLOCK - 1 ;
		}
		strcpy( starts[index], symph );
		starts[index + 1] = starts[index] + strlen(symph) + 1;
		
		if( index++ < MAX -1 ) {
			printf("that is %dth(nd/rd)\n", index);
		}
		else flag = FALSE;
	}
	
	printf("### result is as below : \n");
	for( count = 0; count < index ; count++ )
	    puts(starts[count]);
}
#endif
