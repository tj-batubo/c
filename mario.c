#include <cs50.h>
#include <stdio.h>

void print_pyramid(int psize);

int main(void)
{
    while (true)
    {
	    int psize = get_int("Height: ");
	    if (psize > 0)
	    {
		    print_pyramid(psize);
		    break;
	    } 
	    else 
	    {
		    continue;
	    }
    }
}

void print_pyramid(int psize)
{
	int count = psize - 1;
    for (int i = 0; i < psize; i++)
    {
	    for (int k = count; k > i; k--)
	    {
		    printf(" ");
	    }

	    for (int j = 0; j <= i; j++)
	    {
		    printf("#");
	    }
	    
	    printf("\n");
    }

}
