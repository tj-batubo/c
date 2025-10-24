#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct 
{
	string name;
	string number;
} person;

int main(void)
{
	person people[3];

	people[0].name = "person1";
	people[0].number = "08167642001";

	people[1].name = "person2";
	people[1].number = "09067321006";

	people[2].name = "Person3";
	people[2].number = "09105321736";

	string s = get_string("Name: ");
	for (int i = 0; i < 3; i++)
	{
		if (strcmp(people[i].name,s) == 0)
		{
			printf("Found Number: %s\n", people[i].number);
			return 0;
		}
	}

	
	printf("Person Not Found\n");
	return 1;
	
}
