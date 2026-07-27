/************************************************
 **                                            **
 **  memory allocation for single linked list  **
 **                                            **
 ************************************************
 **                memalloc.c                  **
 ************************************************
 **            kimchulmin, 2026.4              **
 ************************************************/

#include "./usrlib.h"

#define ASCII_CAN          0x18    // ascii code '0x18(24)' = CANCEL = 'CTRL' + 'X'
#define ENTER    "\n"              // 'Enter'
#define STR_LEN            256     // max number of charcters in 'member', a string variable(array)
#define TOTAL_MEMBERS      10      // maximum number of total members

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

struct linklist                    // a data structure node to store one-character with single linked-list
{
    char ch;
    struct linklist *next;
};

void character_buffer(void);
struct linklist *makenode(struct linklist *rp, char ch);
void prnt(struct linklist *root);
void freenode(struct linklist *rp);
void string_buffer(void);
#ifdef UNIT_ALLOC
struct unit_storage *alloc_storage_node(struct unit_storage *sp);
void save_member_into_storage(struct unit_storage *sp, char member[]);
void print_storage(struct unit_storage *sp[], int member_index);
void free_string_buffer(struct unit_storage *sp[], int member_index);
#endif

void main(void)
{
    int flag;
    char example, retry;

    flag = TRUE;
    while(flag)
    {
        system("clear");
        printf("\ninput example number to execute (1 or 2)\n");
        //scanf("%c",example);
        //example = getchar();
        example = getch();

        switch (example)
        {
            case '1'    : printf("\n\n**** Test character_buffer with memory-allocation ****");
                          //flush_stdin();
                          character_buffer();
                          break;

            case '2'    : printf("\n\n**** Test string_buffer with memory-allocation ****");
                          //flush_stdin();
                          string_buffer();
                          break;

            default     : break;
        }

        printf("\n\nRetry?(Y/N)");
        retry = getch();
        
        if(retry == 'N' || retry == 'n')
        {
            flag = FALSE;
            putch('\n');
        }
        else
            flag = TRUE;
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

    printf("\n\n[result]\n");
    prnt(root);
    putch('\n');

    freenode(root);
}

struct linklist *makenode(struct linklist *rp, char ch)    // russian painter algorithm is here, is it inevitable?
{
    if (rp == NULL)
    {
        rp = malloc(sizeof(struct linklist));
        if(rp == NULL)
            perror("malloc is failed in makenode()");
        else
        {
            rp->ch  = ch;
            rp->next = NULL;
        }
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

void freenode(struct linklist *rp)
{
    if(rp != NULL)
    {
        freenode(rp->next);
        free(rp);
        rp = NULL;
    }
    else
        ;
}

void string_buffer(void)
#ifdef VARI_ALLOC
{
    int flag;                        // flag for while-loop
    int pos;                         // index/position of member of 'storage' array 
    int string_lenth;                // variables to calculate string length
    char member[STR_LEN];            // string variable(array) to store member's name & home-address
    char *storage[TOTAL_MEMBERS];    // pointer to store all members's information.

    printf("\n------------------------------------\n");
    printf("\nWelcome to various size allocation~!\n");
    printf("\n------------------------------------\n");

    pos = 0;
    flag = TRUE;

    while(flag)
    {
        printf("\nInput member's name & home-address.\n");
        fgets(member, STR_LEN, stdin);
        string_lenth = strlen(member);

        if(strcmp(member,ENTER) == 0)    // if 'memer' has not any string, then stop while() loop.
            flag = FALSE;
        else
            flag = TRUE;

        storage[pos] = malloc(string_lenth);
        if(storage[pos] == NULL)
        {
            perror("malloc is failed at storage[pos] pointer array in string_buffer()");
            flag = FALSE;
            break;
        }

        strcpy(storage[pos], member);

        if((flag != FALSE) && pos++ < TOTAL_MEMBERS - 1)
        {
            printf("That is %dth(nd/rd/th)\n", pos);
        }
        else
            flag = FALSE;
    }

    printf("### Result is as below : \n");
    while(--pos >= 0)
    {
        if(storage[pos] != NULL)
        {
            puts(storage[pos]);
            free(storage[pos]);
        }

        storage[pos] = NULL;
    }
}
#elifdef UNIT_ALLOC
{
    int flag;                                               // flag for while-loop
    int unit_number;                                        // to count number of unit(10-byte memory)s 
    int member_index;                                       // to index members
    int string_lenth, quotient, remainder, storage_size;    // variables to calculate string length & storage size
    char member[STR_LEN];                                   // string variable(array) to store member's name & home-address
    struct unit_storage *storage[TOTAL_MEMBERS];            // pointer to store location of each string(member)

    flag = TRUE;
    member_index = 0;

    printf("\n-------------------------------------\n");
    printf("\n  Welcome to unit size allocation~!\n");
    printf("\n-------------------------------------\n");

    while(flag)
    {
        if (member_index < TOTAL_MEMBERS )
        {
            printf("\nInput %d(st/nd/th) member's name & home-address.\n", member_index + 1);
            fgets(member, STR_LEN, stdin);
        }

        if (member_index >= TOTAL_MEMBERS || strcmp(member,ENTER) == 0)    // condition to stop while() loop.
            flag = FALSE;
        else
        {
            string_lenth = strlen(member);
            member[string_lenth-1] = '\0';                                           // because fgets() includes '\n' in its result string so remove '\n' with '\0'-the end of string.

            string_lenth = strlen(member);
            quotient = string_lenth / UNIT_MEM_SIZE;
            remainder = string_lenth % UNIT_MEM_SIZE;

            storage_size = quotient + (remainder ? 1 : 0);                           // caculate storage size to save a strimg in member[]

            storage[member_index] = NULL;

            for(unit_number = 0 ; unit_number < storage_size ; unit_number++)
                storage[member_index] = alloc_storage_node(storage[member_index]);

            save_member_into_storage(storage[member_index], member);

            member_index++;
        }
    }

    printf("\n*************************");
    printf("\n   Total member : %d", member_index);
    printf("\n*************************\n");
    
    if(member_index > 0)
        print_storage(&storage[0], member_index);
    
    free_string_buffer(&storage[0], member_index);

}

struct unit_storage *alloc_storage_node(struct unit_storage *sp)
{
    if (sp == NULL)
    {
        sp = malloc(sizeof(struct unit_storage));
        if(sp == NULL)
            perror("malloc for 'sp' is failed in alloc_storage_node()");
        else
        {
            sp->unit_memory = malloc(UNIT_MEM_SIZE);
            if(sp->unit_memory == NULL)
                perror("malloc for 'sp->unit_memory' is failed in alloc_storage_node()");
            sp->prev = NULL;
            sp->next = NULL;
        }
    }
    else
    {
        sp->next = alloc_storage_node(sp->next);
        (sp->next)->prev = sp;
    }

    return sp;
}

void save_member_into_storage(struct unit_storage *sp, char member[])
{
    int i, j;    // to count number in for-loop or while-loop

    i = 0, j = 0;
    while(member[i] != '\0')
    {
        *((sp->unit_memory) + j) = member[i++];

        if(j < UNIT_MEM_SIZE)
        {
            j++;
        }
        else
        {
            j = 0;
            sp = sp->next;
        }
    }
}

void print_storage(struct unit_storage *sp[], int member_index)
{
    int i, j;    // to index array in for-loop or while-loop
    struct unit_storage *storage;

    for(i = 0 ; i < member_index ; i++)
    {
        j = 0;
        storage = *(sp+i);

        while(storage != NULL && *((storage->unit_memory) + j) != '\0')
        {
            printf("%c", *((storage->unit_memory) + j));

            if(j < UNIT_MEM_SIZE - 1)
                j++;
            else
            {
                j = 0;
                storage = storage->next;
                if(storage == NULL)
                    break;
            }
        }
        printf("\n");
    }
}

void free_string_buffer(struct unit_storage *sp[], int member_index)
{
    int i, j;    // to index array in for-loop or while-loop
    struct unit_storage *storage;

    for(i = 0 ; i < member_index ; i++)
    {
        storage = *(sp+i);

        while(storage != NULL)
        {
            free(storage->unit_memory);
            storage->unit_memory = NULL;

            if(storage->next == NULL)
                break;
            else
                storage = storage->next;
            
            free(storage->prev);
            storage->prev = NULL;
        }
    }
}

#else
{
    int flag;                            // flag for while-loop
    int pos;                             // index for pointer array, 'start' to distinguish each string(member)
    char member[STR_LEN];                // string variable(array) to store member's name & home-address
    char store[BLOCK_SIZE];              // memory buffer to store all member's information
    char *start[TOTAL_MEMBERS], *end;    // pointer to store location of each string(member)
    _Bool malloc_flag[TOTAL_MEMBERS];    // flag whether malloc() is called or not

    flag = TRUE;
    pos = 0;
    start[0] = store;
    end = start[0] + BLOCK_SIZE - 1;
    
    printf("\n------------------------------------\n");
    printf("\nWelcome to classic allocation~!\n");
    printf("\n------------------------------------\n");

    memset(malloc_flag, FALSE, sizeof(malloc_flag));
    
    while(flag)
    {
        printf("\nInput member's name & home-address.\n");
        fgets(member, STR_LEN, stdin);

        if (strcmp(member,ENTER) == 0)    // if 'memer' has not any string, then stop while() loop.
            flag = FALSE;
        else
            flag = TRUE;

        if(strlen(member) > (end - start[pos]))     // if length of member is bigger than current memory buffer, then allocate additional memory buffer.
        {
            puts("Now allocating more memory buffer...\n");

            start[pos] = malloc(BLOCK_SIZE);
            if(start[pos] == NULL)
            {
                perror("malloc is failed at start[pos] pointer array");
                flag = FALSE;
                break;
            }
            malloc_flag[pos] = TRUE;
            end = start[pos] + BLOCK_SIZE - 1 ;
        }
        else
            malloc_flag[pos] = FALSE;

        strcpy(start[pos], member);
        start[pos+1] = start[pos] + strlen(member) + 1;

        if((flag != FALSE) && pos < TOTAL_MEMBERS - 1)
        {
            pos++;
            printf("That is %d(nd/rd/th)\n", pos);
        }
        else
            flag = FALSE;
    }

    printf("### Result is as below : \n");
    while(--pos >= 0)
    {
        puts(start[pos]);

        if(malloc_flag[pos] == TRUE)
            free(start[pos]);

        start[pos] = NULL;
    }
}
#endif
