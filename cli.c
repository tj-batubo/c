#include <cs50.h>
#include <stdio.h>

int main(int argsc, string argsv[])
{
	if (argsc > 1)
	{
		printf("Hello, ");

		for (int i = 1; i < argsc; i++)
		{
			printf("%s ", argsv[i]);
		}
		printf("\n");
	}
	else 
	{
		printf("Hello, World\n");
	}
}
