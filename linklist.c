#include "./usrlib.h"

enum color { WHITE, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, BLACK, NOCOLOR = 99  };

struct {
	unsigned type : 3;
	unsigned trailer : 3;
	unsigned crc : 2;
} header;

typedef struct datal {
	char name[15];
	int age;
	int height;
	struct datal *next;
} record ;


record *get(void);
void put(record *pt);
void alist(record *pt, record *list);
void insert(record *pt);
void delete(record *pt);
void prnt(record *list);

void main(void)
{
	record list;
    record *pt;
    
    header.type = 0b000;
    header.trailer = 0b000;
    header.crc = 0b10;
    
    printf("header : %b\n",header);

    *(list.name) = '\0';
    list.age = 0;
    list.height = 0;    
    list.next = NULL;
        
    while(TRUE) 
		if ( ( pt = get() ) == NULL ) exit(0);
		else if ( strcmp(pt->name, "???") == 0 ) break;
		else alist(pt, &list);
    prnt(&list);
    
    insert(&list);
    prnt(&list);
    
    delete(&list);
    prnt(&list);
}

record *get(void)
{
	record *pt;

	pt = (record *)malloc(sizeof(record));
	
	if (pt == NULL ) return NULL;
	else {
        printf("\nInput name age height \n");
        scanf("%s", pt->name);
        scanf("%d", &(pt->age));
        scanf("%d", &(pt->height));
        return pt;
    }
}

void put(record *pt)
{
	printf("name : %s , age : %d , height : %d \n", pt->name, pt->age, pt->height);
}

void alist(record *pt, record *list)
{
	record *current, *before;
	
	before = list;
	current = list->next;
	
	while( current != NULL && current->height < pt->height ) {
		before = current;
		current = current->next;
	}
	
	pt->next = current;
	before->next = pt;
}

void insert(record *pt)
{
	int count;
	record *new_pt, *before, *current;

	printf("Input number to insert new node : ");
	scanf("%d", &count);
		
	new_pt = get();

	
	before = pt;
	current = pt->next;
	
	for(int i = 0 ; i < (count-1) ; i++ ) {
	    before = before->next;
	    current = current->next;
	}
	
	before->next = new_pt;
	new_pt->next = current;
	
}

void delete(record *pt)
{
	int count = 0;
	char name[15];
	record *index, *before, *current;

	printf("Input name of node to delete : ");
	scanf("%s", name);
    
	for( index = pt->next ; index != NULL ; index = index->next ) {
		count++;
		if ( strcmp( index->name, name ) == 0 ) break;
	}
	
	before = pt;
	current = pt->next;
	
	for(int i = 0 ; i < (count-1) ; i++ ) {
	    before = before->next;
	    current = current->next;
	}
	
	before->next = current->next;
	free(current);
}

void prnt(record *list)
{
    record *pt;
    
	for( pt = list->next ; pt != NULL ; pt = pt->next ) put(pt);
}
