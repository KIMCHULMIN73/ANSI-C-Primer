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
#define LENLIN       40
#define MAX          50

struct linklist              // a data structure node for single linked-list
{
    char ch;
    struct linklist *next;
};

struct linklist *makenode(struct linklist *rp, char ch);
void key_in_buffer(void);
void example_2(void);
void prnt(struct linklist *root);

void main(void)
{
    int example_num;

    printf("\ninput example number to execute (1 or 2)\n");
    scanf("%d", &example_num);

    switch (example_num)
    {
        case 1    : printf("\n\n**** Welcome Key-in Buffer with memory-allocation ****");
                    printf("\n\nif you input any key,\nthen console print-out that character~!\n(to exit, input 'CTRL' + 'X')");
                    key_in_buffer();
                    break;

        case 2    : printf("\n\n**** Welcome Key-in Buffer with memory-allocation ****");
                    printf("\n\nif you input any key,\nthen console print-out that character~!\n(to exit, input 'CTRL' + 'X')");
                    example_2();
                    break;

        default   : break;
    }
}

void key_in_buffer(void)
{
    char ch;
    struct linklist *root;

    root = NULL;

    while( (ch = getch()) != ASCII_CAN )
    {
        putch(ch);
        putch('\n');
        root = makenode(root, ch);
    }
        
    prnt(root);

}

void example_2(void)
{
    int index = 0, count = 0, flag = TRUE, cmp;
    char store[BLOCK], symph[LENLIN];
    char *start[MAX],  *end;

    start[0] = store;
    end = start[0] + BLOCK - 1;

    printf("Input long names to test memory allocation()\n");

    while(flag)
    {
        fgets(symph, LENLIN, stdin);

        if ( strcmp(symph, HALT) == 0)
            flag = FALSE;
        else
            flag = TRUE;

        if( strlen(symph) > (end - start[index]) )
        {
            puts("alloc more memory\n");

            start[index] = malloc(BLOCK);
            end = start[index] + BLOCK - 1 ;
        }
        strcpy( start[index], symph );
        start[index + 1] = start[index] + strlen(symph) + 1;

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
