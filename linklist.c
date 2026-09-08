/******************************************
 **                                      **
 **             linked list              **
 **                                      **
 ******************************************
 **              linklist.c              **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/

#include "./usrlib.h"

enum color { WHITE, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, BLACK, NO_COLOR = 99 };

struct
{
    unsigned type:3;       // delcare prototype to use bit expression
    unsigned trailer:3;
    unsigned crc:2;
} header;                  // This is just a example to learn 'C' syntax, so you had not better use external variables as this.

typedef struct entity
{
    char name[15];
    int age;
    int height;
    struct entity *next;
} record;

int make_list(record *h_list);
void delete_list(record *h_list);
void print_list(record *h_list);

int insert_node(record *h_list, record *p_node);
void delete_node(record *h_list, char *name);
record *get_node(void);
void put_node(record *p_node);

void main(void)
{
    char name[15];
    int num_of_node, i;
    record node, list_entry;
    record *p_node, *h_list;

    header.type = 0b000;
    header.trailer = 0b000;
    header.crc = 0b10;

    *(list_entry.name) = '\0';
    list_entry.age = 0;
    list_entry.height = 0;    
    list_entry.next = NULL;

    h_list = &list_entry;    // handler for linked-list

    // to test make_list function
    make_list(h_list);
    print_list(h_list);

    // to test insert_node function
    printf("\n\nHow much new nodes you wanan insert to linklist : ");
    scanf("%d", &num_of_node);
    flush_stdin();

    if(num_of_node < 1)
        ;
    else
        for (i = 0 ; i < num_of_node ; i++)
        {
            if ((p_node = get_node()) == NULL)
                exit(0);
            else
                insert_node(p_node, h_list);
        }
    print_list(h_list);

    // to test delete_node function
    printf("Input name of node to delete : ");
    scanf("%s", name);
    flush_stdin();

    delete_node(h_list, name);
    print_list(h_list);

    // to test delete_list function : make_list() & delete_list() must be pair!
    delete_list(h_list);
}

int make_list(record *h_list)
{
    record *p_node;

    if(h_list == NULL)
        return FAIL;

    while(TRUE) 
        if ((p_node = get_node()) == NULL)
            exit(0);
        else if (strcmp(p_node->name, "/quit") == 0)
            break;
        else
            insert_node(p_node, h_list);

    return SUCCESS;
}

void delete_list(record *h_list)
{
/*    record *p_node, *prev_node, *current_node;

    if(h_list == NULL)
        exit(-1);

    prev_node = h_list;
    current_node = h_list->next;

    while(current_node != NULL)
    {
        prev_node = prev_node->next;
        current_node = current_node->next;
    }

    free(current_node);
*/
}

void print_list(record *h_list)
{
    record *p_node;

    if(h_list == NULL)
        return;

    for(p_node = h_list->next ; p_node != NULL ; p_node = p_node->next)
        put_node(p_node);
}

int insert_node(record *h_list, record *p_node)
{
    record *prev_node, *current_node;

    if((p_node == NULL) || (h_list == NULL))
        return FAIL;
    else
    {
        prev_node = h_list;
        current_node = h_list->next;

        while(current_node != NULL)
        {
            prev_node = current_node;
            current_node = current_node->next;
        }

        prev_node->next = p_node;
        p_node->next = current_node;

        return SUCCESS;
    }
}

void delete_node(record *h_list, char *name)
{
    int offset = 0;
    record *p_node, *prev_node, *current_node;

    if((p_node == NULL) || (h_list == NULL))
        exit(-1);

    for(p_node = h_list->next ; p_node != NULL ; p_node = p_node->next)
    {
        offset++;
        if (strcmp(p_node->name, name) == 0) break;
    }

    prev_node = h_list;
    current_node = h_list->next;

    for(int i = 1 ; i < offset ; i++)
    {
        prev_node = prev_node->next;
        current_node = current_node->next;
    }

    prev_node->next = current_node->next;
    free(current_node);
}

record *get_node(void)
{
    record *p_node;

    p_node = (record *)malloc(sizeof(record));

    if (p_node == NULL )
        return NULL;
    else
    {
        printf("\nInput name : ");
        scanf("%s", p_node->name);
        flush_stdin();

        if ( strcmp(p_node->name, "/quit") == 0 )
            return p_node;

        printf("\nInput age : ");
        scanf("%d", &(p_node->age));
        flush_stdin();
        printf("\nInput height : ");
        scanf("%d", &(p_node->height));
        flush_stdin();

        return p_node;
    }
}

void put_node(record *p_node)
{
    if(p_node == NULL)
        ;
    else
        printf("name : %s , age : %d , height : %d \n", p_node->name, p_node->age, p_node->height);
}
