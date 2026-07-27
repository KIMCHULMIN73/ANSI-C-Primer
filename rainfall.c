/******************************************
 **                                      **
 **       rain fall from FILE I/O        **
 **                                      **
 ******************************************
 **              rainfall.c              **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/

#include "usrlib.h" 

#define MONTHS        12
#define YEARS         5

int main(int argc, char* argv[])
{
    FILE *in;                                // to point 'input file'

    char string[STR_LENGTH];                 // array to save values from input file, as string
    float floatarray[STR_LENGTH];            // to save values from string array, as floating number

    int year, month;                         // to count year and month
    static float rainfall[YEARS][MONTHS];    // to save values from floatarray with 5(years)-by-12(months) array
    float total, subtotal, avg[MONTHS];      // to save total value, sub total value and monthly average for 5 years

    in = fopen(argv[1],"r");
    if(in == NULL)
    {
        printf("There is no file to OPEN\n\n");
        return -1;
    }
    
    getstring(in, string);
    //str2intarray(string, integer);
    str2floatarray(string, floatarray);
    fclose(in);

    printf("**************************************************************************************\n");	
    printf("  YEAR  :  JAN  FEB  MAR  APR  MAY  JUN  JLY  AUG  SEP  OCT  NOV  DEC  :  TOTAL  AVG  \n");
    printf("--------------------------------------------------------------------------------------\n");	

    for (year = 0 ; year < YEARS  ; year++)
    {
        printf("%6d  : ",    1970+year);

        for(month = 0, subtotal = 0 ; month < MONTHS ; month++)
        {
            rainfall[year][month] = floatarray[year*MONTHS+month];
            subtotal += rainfall[year][month];
             
            if(rainfall[year][month] > 9.9)
                printf("%2.1f ",rainfall[year][month]);
            else
                printf(" %2.1f ",rainfall[year][month]);
        }
        printf("    %2.1f   %2.2f\n", subtotal, (float)subtotal/MONTHS);
    }

    printf("---------------------------------------------------------------------------------------\n");
    printf(" TOTAL  :");

    for (month = 0, total = 0 ; month < MONTHS ; month++)
    {
        for (year = 0, subtotal = 0 ; year < YEARS  ; year++)
            subtotal += rainfall[year][month];

        if(subtotal > 9.9)
            printf(" %2.1f",subtotal);
        else
            printf("  %2.1f",subtotal);

        total += subtotal;
        avg[month] = (float)subtotal/YEARS;
    }

    printf("    %2.1f   %2.2f\n", total, (float)total/YEARS);

    printf("   AVG  :");
    for (month = 0 ; month < MONTHS ; month++)
        if(avg[month] > 9.9)
            printf("%2.2f",avg[month]);
    else
        printf(" %2.2f",avg[month]);

    printf("    %2.2f   %2.2f\n", (float)total/YEARS, (float)total/YEARS/MONTHS);

    printf("**************************************************************************************\n");	
}
