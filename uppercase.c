#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	string name = get_string("Before: ");
	
	printf("After:  ");

	for (int i =0, n = strlen(name); i < n; i++)
	{
		//if i is =greater than or equal to a and z
		if (name[i] >= 'a' && name[i] <= 'z')
		{
			//chnage to uppercase
			printf("%c", name[i] - ('a' - 'A'));
		}
		else 
		{
			printf("%c", name[i]);
		}
	}
	printf("\n");
}


