#include <stdio.h>
#include <string.h>

int main(void) {
	
	FILE *file = fopen("phonebook.csv", "w");

	char name[20];
	char number[10];
	
	printf("Name: ");
	fgets(name, sizeof(name), stdin);

	name[strcspn(name, "\n")] = '\0';
	
	printf("Number: ");
	fgets(number, sizeof(number), stdin);

	name[strcspn(number, "\n")] = '\0';
	
	fprintf(file, "%s,%s\n", name, number);
	
	fclose(file);
}
