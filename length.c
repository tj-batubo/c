#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	string name = "";

	do 
	{
		name = get_string("Name: ");
	}
	while (strlen(name) < 1);
}
