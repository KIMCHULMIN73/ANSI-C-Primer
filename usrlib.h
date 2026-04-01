#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <termio.h>
#include <unistd.h>
#include <math.h>
#include <ctype.h>

#define INT_LENGTH	128
#define STR_LENGTH	1024

#define STOP		-1

#define YES_NUM		0
#define NO_NUM		1

#define UP		1
#define DOWN	-1

#define FAIL		0
#define SUCCESS		1

#define FALSE		0
#define TRUE		1

#define SIDES		100
#define SCALE		65536

#define LIM		5
#define LINLEN	81

struct numbers {
	int		x;
	int		y;
};

int getch(void);
void putch(char ch);
int getint(int *pint);
int str2int(char *intarray, int *pint);
int int2str(int number, char* num_str);
void getstring(FILE *file, char string[]);
int getstr(FILE *file, char *string);
int putstr(FILE *file, char *string);
int strlength(char sl[]);
int getintarray(int pNumber[], int size);
void str2intarray(char string[], int integer[]);
void str2floatarray(char string[], float floatarray[]);
void sort(int pNumber[], int size, int direction);
void swapbypointer(int *x, int *y);
struct numbers swapbystructure(int x, int y);
unsigned int rnd(unsigned int *random_num);
void setrnd (unsigned int x, unsigned int *random_num);
#ifdef RANDOM_DICE
unsigned int dice(time_t the_time);
#else
unsigned int dice(time_t the_time, unsigned int seed);
#endif
int mean(int values[], int number);
void sortstring(char *input[], int ct);
void sortstringbystrcpy(char (*input)[LINLEN], int ct);
//void sortstringbystrcpy(char *input, int ct);


