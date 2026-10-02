/******************************************
 **                                      **
 **              test c pointer          **
 **                                      **
 ******************************************
 **             ptr_advance.c            **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/
#include "./usrlib.h"

#define PR(X)    printf("pointer X = %u , value *X = %5d , double pointer &X = %u\n", X, *X, &X)

int main()
{
/* EXAMPLE 01 */
    int *ptr1, *ptr2;
    static int urn[] = {100, 200, 300};    // size of array 'urn' is 3
    
    ptr1 = urn;    // is same to 'ptr1 = &urn[0]'
    ptr2 = &urn[2];  

    PR(ptr1);
    ptr1++;
    PR(ptr1);
    PR(ptr2);
    ++ptr2;
    PR(ptr2);
    
    printf("\nptr2 - ptr1 = %u\n\n", ptr2 - ptr1);


/* EXAMPLE 02 */
    int index, *ptr;
    int array[][] = { {1,3,5} , {2,4,6} , {5,6,8} , {123,234,456} };    // size of array 'array' is 4-by-3
    int brray[] = {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40};
    
    ptr = array[3];    //array[3] is name/pointer of array[3][0]

    for(index = 0 ; index < 3 ; index++)
        printf("array[3][%d] = %d\n", index, *(ptr+index));    // pointer operation is based on data-type

    ptr = brray;
    
    for(index = 0 ; index < (sizeof(brray) / sizeof(int)) ; index++)
        *ptr += *(ptr+index);

    printf("Total value is %d / %d\n\n",*ptr, brray[0]);

/* EXAMPLE 03 */
    char *chptr, crray[] = "AMIGO SIEMPRE";    //crray is char array, initiated with string.
    int  drray[] = {125, 255, 333, 450};
    long *lptr, erray[] = {1122, 2333, 334454, 23453};

    index = 0;
    chptr = crray;
    while(*(chptr+index) != '\0')
    {
        printf("crray[%2d] : *(0x%x) = %c\n", index, (chptr+index), *(chptr+index));
        index++;
    }

    putchar('\n');

    index = 0;
    ptr = drray;
    lptr = erray;
    while(index < 4)
    {
        printf("drray[%2d] : *(0x%x) = %d\n", index, (ptr+index), *(ptr+index));
        printf("erray[%2d] : *(0x%x)  = %u\n", index, (lptr+index), *(lptr+index));
        index++;
    }

/* EXAMPLE 04 */
    char frray[] = "NIRVANA is one of my favorite pop singer.";
    void ptrn_frray(char *array, int size);
    
    ptrn_frray(frray, sizeof(frray)/sizeof(char));

    ///////////////////////////////////////////////////////////////////////////////
    char grray[] = "REPUBLIC OF SOUTH KOREA IS NICK NAME OF NAMJOSEON";
    void ptrn_grray(char *array, int size);

    ptrn_grray(grray, sizeof(grray)/sizeof(char));

    char hrray[][4] = { {'A','B','C','D'}, {'E','F','G','H'}, {'I','J','K','L'} };
    //void ptrn_hrray(char *array, int size);
    void ptrn_hrray(char array[][4], int size);

    ptrn_hrray(hrray, sizeof(hrray)/sizeof(char));

    /////////////////////////////////////////////////////////////////////////////////
    char *str = "KOREA is my mother nation.";
    int length;

    length = strlength(str);
    printf("\nLength of \'%s\'s is %d\n", str, length);

    ///////////////////////////////////////////////////////////////////////////////
    void ptrn_week(char **week, int size);

    char *week[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

    ptrn_week(week, sizeof week / sizeof *week);

    ///////////////////////////////////////////////////////////////////////////////    
    void strarraylen(char **str, int size);
    char *strarray[] = { "My", "Name is", "Mustani Slav", "Rostro", "phobitchi", "3rd generation", "ultra super captiong computer" };
    
    strarraylen(strarray, sizeof strarray / sizeof *strarray); 
    
/* EXAMPLE 02 */
#define REG_ADDR 0x40000000

    unsigned int variable;
    volatile unsigned int *cpu_register;

    cpu_register = (volatile unsigned int *) REG_ADDR;

    variable = 0b0000111100001111;
    *cpu_register = 0b0000111100001111;
    sleep(1);
    variable = 0b1111000011110000;
    *cpu_register = 0b1111000011110000;
    sleep(1);
    variable = 0b0101010101010101;
    *cpu_register = 0b0101010101010101;


}

void strarraylen(char **str, int size)
{
    int length;

    for (int i = 0; i < size ; i++)
    {
        length = strlength(str[i]);
        printf("lenth of \'%s\' is %d\n", str[i], length);
    }
}

void ptrn_week(char **week, int size)
{
    printf("\n\n[ *week[i] , week[i][j] ]\n");

    for(int i = 0; i < size ; i++)
        printf("Initial of %s is %c\n", week[i], *week[i]);

    for(int i = 0; i < size ; i++)
        for(int j = 0; j < 3 ; j++)
            printf("%c", week[i][j]);

    printf("\n\n[Anoher Expression : **(week+i) , *(*week + i) ]\n");

    for(int i = 0; i < size ; i++)
        printf("Another Initial of %s is %c\n", *(week+i),**(week+i));

    printf("Anoher ");
    for(int i = 0; i < size*8 ; i++)
        printf("%c", *(*week + i));

    printf("\n\n");
}

//void ptrn_hrray(char *array, int size)
void ptrn_hrray(char (*array)[4], int size)
{
    putchar('\n');
    for(int i = 0 ; i < size/4 ; i++)
        for(int j = 0 ; j < size/3 ; j++)
            //putchar(array[i*4+j]);
            putchar(array[i][j]);

    putchar('\n');
}

void ptrn_grray(char *array, int size)
{
    putchar('\n');

    for(int i = 0 ; i < size ; i++)
    {
        for(int j = (size-i) ; j < size ; j++)
            putchar(array[j-1]);
            
        putchar('\n');
    }

    for(int i = size ; i >= 0 ; i--)
        printf("%s\n", &array[i]); 
}

void ptrn_frray(char *array, int size)
{
    putchar('\n');
    for(int index = 0 ; index < size ; index++)
        putchar(array[index]);
    putch('\n');
    putchar('\n');
}
