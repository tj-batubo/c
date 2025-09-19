#include <cs50.h>
#include <stdio.h>

int main(void)
{
	long dollars = 1;

	while (true)
	{
		char c = get_char("You Have $%li, Double it and give it to the next person? ", dollars);
		if (c == 'y' || c == 'Y')
		{
			dollars *= 2;
		}
		else if (c == 'n' || c == 'N')
		{
			 break;
		}
		else 
		{
			printf("Unrecogisable Input \n");
			continue;
		}
	}

	printf("Congratulations You have $%li \n", dollars);

}
