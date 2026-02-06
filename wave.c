
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
    int numin;
    
    printf("Input your number :");
    
    while (1)
    {
		scanf("%d", &numin);
		switch (numin)
		{
			case 1 : printf("first");
					 break;
		         
			case 2 : printf("Second");
					 break;
		         
			case 3 : printf("Third");
					 break;
		         
			case 4 : printf("Fourth");
					 break;
		         		         
			case 5 : printf("Fifth");
					 break;
		         
			case 6 : printf("Sixth");
					 break;
		         
			case 7 : printf("Seventh");
					 break;
		         
			case 8 : printf("Eighth");
					 break;
		         
			case 9 : printf("Nineth");
					 break;
			default : printf("All");
					  break;
		}
		printf(" wave\n");
	}
}
