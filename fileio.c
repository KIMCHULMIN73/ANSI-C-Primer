/******************************************
 **                                      **
 **             test file i/o            **
 **                                      **
 ******************************************
 **               fileio.c               **
 ******************************************
 **          kimchulmin, 2026.4          **
 ******************************************/

#include "./usrlib.h"

#ifdef CONV_LETT
#define UPPER    1
#define LOWER    0

// convert_letter() funcion, depending on option, converts 'upper letter' in source file to 'lower letter' in destination file, vice versa 
int convert_letter(char *src_file, char *dest_file, int option);
#endif

int main(int argc, char *argv[])
{
    FILE *fpt;
    long offset;
    int max, cnt;
    int option;
    char ch;

    fpt = NULL;
    offset = 0L;
    max = cnt = 0;
    option = UP;

    if (argc < 2)
    {
        puts("Must input file name to operate properly.\n");
        goto EXIT;
    }
    else
#ifndef CONV_LETT
    {
        if ( (fpt = fopen(argv[1], "r")) == NULL )
            printf("Cannot open the FILE %s\n", argv[1]);
        else
        {
            while( getc(fpt) != EOF ) max ++;    // count the number of characters in file, pointed 'ftp'
            
            while (cnt++ < max)
            {
                // move a position of file pointer to get specific data in file, pointed 'ftp'
                if (!fseek(fpt, offset++, SEEK_SET)) putchar(getc(fpt));
                if (!fseek(fpt, -offset, SEEK_END)) putchar(getc(fpt));
            }
            fclose(fpt);
        }
    }
#else
    while(TRUE)
    {
        printf("Input Option 'U' or 'L' to convert letters : ");
        scanf("%c", &ch);

        if( ch == 'U' || ch == 'u' )
        {
            option = UP;
            break;
        }
        else if (ch == 'L' || ch == 'l' )
        {
            option = DOWN;
            break;
        }
        else
        {
            printf ("\nInvalid Value\n\n");
            while( (ch=getchar()) != '\n' )    // buffer flushing for next--turn scanf()
                ;
        }
    }

    convert_letter(argv[1], argv[2], option);
#endif

EXIT :
    return FAIL;
}

#ifdef CONV_LETT
int convert_letter(char *src_file, char *dest_file, int option)
{
    int ch;
    char *opt;
    FILE *fpt_src, *fpt_dest;

    if ( option == UP )
        opt = "UPPER";
    else
        opt = "LOWER";

    if ( (fpt_src = fopen(src_file, "r")) == NULL )
        printf("Cannot open the FILE %s\n", src_file);
    else
    {
        printf("Start to convert from FILE '%s' to FILE '%s' with '%s' condition\n", src_file, dest_file, opt);
        fpt_dest = fopen(dest_file, "w");
        while( (ch = getc(fpt_src)) != EOF )
        {
            if( option == UP )
                ch = islower(ch) ? toupper(ch) : ch;
            else
                ch = isupper(ch) ? tolower(ch) : ch;
                
            putc(ch, fpt_dest);
        }
        fclose(fpt_src);
        fclose(fpt_dest);
    }

    puts("THE END.");
    putch('\n');
}
#endif
