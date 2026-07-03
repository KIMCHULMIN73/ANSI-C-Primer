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

#define ASCII_CAN          0x18        // Ascii code '0x18(24)' = CANCEL = 'CTRL' + 'X'
#define CARRIAGE_RETURN    "\n"        // 'Carriage Return' or 'Enter'
#define STR_LEN            256         // max number of charcters in 'member', a string variable(array)
#define TOTAL_MEMBERS      50          // maximum number of total members

#ifdef VARI_ALLOC

#elifdef UNIT_ALLOC
    #define UNIT_MEM_SIZE      10      // size of unit memory block

    struct unit_storage                // a data structure node to make unit strage with double linked-list
    {
        char *unit_memory;
        struct unit_storage *prev;
        struct unit_storage *next;
    };
#else
    #define BLOCK_SIZE         100     // size of unit memory block
#endif

struct linklist                        // a data structure node to store one-character with single linked-list
{
    char ch;
    struct linklist *next;
};

struct linklist *makenode(struct linklist *rp, char ch);
void prnt(struct linklist *root);
void clear_stdin(void);
void character_buffer(void);
void string_buffer(void);
struct unit_storage *add_storage(int num_of_storage);

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

    printf("\n\nif you input any key,\nthen console print-out that immediatley\n(to exit, input 'CTRL' + 'X')\n");

    root = NULL;

    while((ch = getch()) != ASCII_CAN)
    {
        putch(ch);
        putch('\n');
        root = makenode(root, ch);
    }

    prnt(root);
    putch('\n');
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

void string_buffer(void)
#ifdef VARI_ALLOC
{
    int flag;                            // flag for while-loop
    int index, count;
    int string_lenth;
    char member[STR_LEN];                // string variable(array) to store member's name & home-address
    char *storage[TOTAL_MEMBERS];        // pointer to store all members's information.

    flag = TRUE;
    index = 0;

    printf("\nWelcome to various size allocation~!\n");

    while(flag)
    {
        printf("\nInput member's name & home-address.\n");
        fgets(member, STR_LEN, stdin);
        string_lenth = strlen(member);

        if(strcmp(member,CARRIAGE_RETURN) == 0)    // if 'memer' has not any string, then stop while() loop.
            flag = FALSE;
        else
            flag = TRUE;

        storage[index] = malloc(string_lenth);
        
        strcpy(storage[index], member);

        if((flag != FALSE) && index++ < TOTAL_MEMBERS - 1)
        {
            printf("That is %dth(nd/rd)\n", index);
        }
        else
            flag = FALSE;
    }

    printf("### Result is as below : \n");
    for(int count = 0; count < index ; count++ )
    {
        puts(storage[count]);
        free(storage[count]);
    }
}
#elifdef UNIT_ALLOC
{
// STR_LEN 50, UNIT_MEM_SIZE 10
//    struct unit_storage
//    {
//        char *unit_memory
//        struct storage *prev;
//        struct storage *next;
//    }

    int flag;
    int index;
    int string_lenth, quotient, remainder, storage_size;
    char member[STR_LEN];
    struct unit_storage *my_storage;

    flag = TRUE;

    printf("\nWelcome to unit size allocation~!\n");

    while(flag)
    {
        printf("\nInput member's name & home-address.\n");
        fgets(member, STR_LEN, stdin);
        string_lenth = strlen(member);

        if (strcmp(member,CARRIAGE_RETURN) == 0)          // if 'memer' has not any string, then stop while() loop.
            flag = FALSE;
        else
            flag = TRUE;

        quotient = string_lenth / UNIT_MEM_SIZE;
        remainder = string_lenth % UNIT_MEM_SIZE;

        if(remainder == 0)
            storage_size = quotient;
        else
            storage_size = quotient + 1;

        printf("\ninput string is %d bytes, so you need %d of unit_storages\n",string_lenth, storage_size);
        my_storage = add_storage(storage_size);

    }

}

struct unit_storage *add_storage(int num_of_storage)
{
    struct unit_storage *strg;

    strg = calloc(1, sizeof(struct unit_storage));

    strg->unit_memory = malloc(UNIT_MEM_SIZE);
    strg->prev = NULL;
    strg->next = NULL;

    return strg;
}


#else
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

    printf("\nWelcome to classic allocation~!\n");

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
        free(start[count]);
}
#endif
