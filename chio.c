/* charater I/O functions - getch(), putch() for LINUX */

#include <termio.h>

int getch(void);
void putch(char ch);

int getch(void)
{
    int ch;
    struct termios old;
    struct termios current;
    
    tcgetattr(0, &old);
    
    current = old;
    current.c_lflag &= ~(ICANON|ECHO);
    current.c_cc[VMIN] = 1;
    current.c_cc[VTIME] = 0;
    
    tcsetattr(0, TCSAFLUSH, &current);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &old);		
    
    return ch;	
}

void putch(char ch)
{
    putchar(ch);	
}
