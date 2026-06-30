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

#define ASCII_CAN          0x18    // Ascii code '0x18(24)' = CANCEL = 'CTRL' + 'X'
#define CARRIAGE_RETURN    "\n"    // empty input (ex. 'Carriage Return' or 'Enter')
#define STR_LEN            60      // max number of charcters in 'member', a string variable(array)
#define BLOCK_SIZE         100     // size of unit memory block
#define TOTAL_MEMBERS      40      // maximum number of total members

struct linklist                    // a data structure node to store one-character for single linked-list
{
    char ch;
    struct linklist *next;
};

struct linklist *makenode(struct linklist *rp, char ch);
void prnt(struct linklist *root);
void clear_stdin(void);
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
                    clear_stdin();
                    character_buffer();
                    break;

        case 2    : printf("\n\n**** Test string_buffer with memory-allocation ****");
                    clear_stdin();
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

    while((ch = getch()) != ASCII_CAN)
    {
        putch(ch);
        putch('\n');
        root = makenode(root, ch);
    }
        
    prnt(root);

}

struct linklist *makenode(struct linklist *rp, char ch)     // russian painter algorithm is here, is it enevitable?
{
    if (rp == NULL)
    {
        rp = malloc(sizeof(struct linklist));
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

void clear_stdin(void)
{
    int c;
    while ((c=getchar()) != '\n' && c != EOF)
        ;
}

/*
change code
 1. remove store array and make store pointer to alloc memory buffer
 2. string lenth > block size
 3. change routine - user can input larger string than intial memory buffer, 
                     and program has to allocate additional memory to store that string. 
*/

void string_buffer(void)
{
    int flag;                            // flag for while-loop
    int index;                           // index for pointer array, 'start' to distinguish each string(member)
    char member[STR_LEN];                // string variable(array) to store member's name & home-address
    char store[BLOCK_SIZE];              // memory buffer to store all member's information
    char *start[TOTAL_MEMBERS], *end;    // pointer to store location of each string(member)

    flag = TRUE;
    index = 0;
    start[0] = store;
    end = start[0] + BLOCK_SIZE - 1;

    while(flag)
    {
        printf("\nInput member's name & home-address.\n");
        fgets(member, STR_LEN, stdin);
        //printf("\nThe length of your input is %d\n",strlen(member));

        if (strcmp(member,CARRIAGE_RETURN) == 0)          // if 'memer' has not any string, then stop while() loop.
            flag = FALSE;
        else
            flag = TRUE;

        if(strlen(member) > (end - start[index]))    // if length of member is bigger than current memory buffer, then allocate additional memory buffer.
        {
            puts("Now allocating more memory buffer...\n");

            start[index] = malloc(BLOCK_SIZE);
            end = start[index] + BLOCK_SIZE - 1 ;
        }

        strcpy(start[index], member);
        start[index+1] = start[index] + strlen(member) + 1;

        if((flag != FALSE) && index++ < TOTAL_MEMBERS - 1)
        {
            printf("That is %dth(nd/rd)\n", index);
        }
        else
            flag = FALSE;
    }

    printf("### Result is as below : \n");
    for(int count = 0; count < index ; count++ )
        puts(start[count]);
}
