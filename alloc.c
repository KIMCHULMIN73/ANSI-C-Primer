/************************************************
 **                                            **
 **  memory allocation for single linked list  **
 **                                            **
 ************************************************
 **                  alloc.c                   **
 ************************************************
 **            kimchulmin, 2026.4              **
 ************************************************/

#include "./usrlib.h"

#define ASCII_CAN    0x18    // Ascii code '0x18(24)' = CANCEL = 'Ctrl' + 'x'
#define HALT         ""
#define BLOCK        100
#define STR_LEN      256     // max number of charcters in a string, named 'member'
#define MAX          50

struct linklist              // a data structure node for single linked-list
{
    char ch;
    struct linklist *next;
};

struct linklist *makenode(struct linklist *rp, char ch);
void prnt(struct linklist *root);
void character_buffer(void);
void string_buffer(void);

void main(void)
{
    int example_num;

    printf("\ninput example number to execute (1 or 2)\n");
    scanf("%d", &example_num);

    switch (example_num)
    {
        case 1    : printf("\n\n**** Test character_buffer with memory-allocation ****");
                    character_buffer();
                    break;

        case 2    : printf("\n\n**** Test string_buffer with memory-allocation ****");
                    string_buffer();
                    break;

        default   : break;
    }
}

void character_buffer(void)
{
    char ch;
    struct linklist *root;

    printf("\n\nif you input any key,\nthen console print-out that immediatley\n(to exit, input 'CTRL' + 'X')");

    root = NULL;

    while( (ch = getch()) != ASCII_CAN )
    {
        putch(ch);
        putch('\n');
        root = makenode(root, ch);
    }
        
    prnt(root);

}

struct linklist *makenode(struct linklist *rp, char ch)    // russian painter algorithm is here, is it enevitable?
{
    if (rp == NULL)
    {
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
    if(rp != NULL)
    {
        prnt(rp->next);
        printf("%c ", rp->ch);
    }
    else
        ;
}

void string_buffer(void)
{
    int flag;        // flag for while-loop
    int index = 0;
    int count = 0;
    char member[STR_LEN];    // string buffer array to store member's name & address
    char store[BLOCK];
    char *start[MAX],  *end;

    printf("Input member's name & home address.\n");

    start[0] = store;
    end = start[0] + BLOCK - 1;
    flag = TRUE;

    while(flag)
    {
        fgets(member, STR_LEN, stdin);

        if ( strcmp(member, HALT) == 0)
            flag = FALSE;
        else
            flag = TRUE;

        if( strlen(member) > (end - start[index]) )
        {
            puts("alloc more memory\n");

            start[index] = malloc(BLOCK);
            end = start[index] + BLOCK - 1 ;
        }
        strcpy( start[index], member );
        start[index + 1] = start[index] + strlen(member) + 1;

        if( index++ < MAX -1 )
        {
            printf("that is %dth(nd/rd)\n", index);
        }
        else
            flag = FALSE;
    }

    printf("### result is as below : \n");
    for( count = 0; count < index ; count++ )
        puts(start[count]);
}
