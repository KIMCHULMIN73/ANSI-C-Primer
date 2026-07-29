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

#define YEARS     5
#define MONTHS    12

int main(int argc, char* argv[])
{
    FILE *in;                                // to point 'input file'
    int year, month;                         // to count year and month

    char string[STR_LENGTH];                 // char array to save string from input file
    float floatarray[STR_LENGTH];            // to save floating numbers which are extracted from string array by 'str2floatarray()' function.
    static float rainfall[YEARS][MONTHS];    // to save values from floatarray into 5(years)-by-12(months) array
    float total, subtotal, avg[MONTHS];      // to save total value, sub total value and monthly average for 5 years

    in = fopen(argv[1],"r");
    if(in == NULL)
    {
        printf("There is no file to OPEN\n\n");
        return -1;
    }
    else
    {
        getstring(in, string);
        //str2intarray(string, integer);
        str2floatarray(string, floatarray);

        fclose(in);
    }

    printf("*******************************************************************************************************\n");
    printf("  YEAR  :   JAN   FEB   MAR   APR   MAY   JUN   JLY   AUG   SEP   OCT   NOV   DEC   :   TOTAL   AVG    \n");
    printf("-------------------------------------------------------------------------------------------------------\n");

    for (year = 0 ; year < YEARS  ; year++)
    {
        printf("%6d  :   ",    2021 + year);

        for(month = 0, subtotal = 0 ; month < MONTHS ; month++)
        {
            rainfall[year][month] = floatarray[year*MONTHS+month];
            subtotal += rainfall[year][month];

            if(rainfall[year][month] < 10)
                printf("%3.1f   ",rainfall[year][month]);
            else if(rainfall[year][month] < 100)
                printf("%4.1f  ",rainfall[year][month]);
            else
                printf("%5.1f ",rainfall[year][month]);
        }
        printf("    %3.1f   %3.2f\n", subtotal, (float)subtotal/MONTHS);
    }

    printf("-------------------------------------------------------------------------------------------------------\n");
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

    printf("*******************************************************************************************************\n");
}
