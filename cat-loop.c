#include <stdio.h>
#include <cs50.h>

void meow(int n);

int main(void)
{
         int n = get_int("Number: ");
	 meow(n);
}

void meow(int n)
{
	for (int i = 0; i < n; i++)
	{
		int c = i;
		c += 1;
		printf("meow #%d \n", c);
	}
}
