#include <cs50.h>
#include <stdio.h>

int get_length(string str);
	
int main(void)
{
	string name = "";
	printf("Length: %i \n", get_length(name));
	do 
	{
		name = get_string("Name: ");
	} 
	while (get_length(name) < 1);
	
	printf("Length: %i \n", get_length(name));	
}

int get_length(string str)
{
	int n = 0;

	while (str[n] != '\0')
	{
		n++;
	}
	return n;
}
