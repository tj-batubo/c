#include <stdio.h>

void print_row(int n);

int main(void)
{
	//Never Change the number of rows or columns
	const int n = 7;
	
	//Print multiple rows
	for (int i = 0; i < n; i++)
	{
		print_row(n);
	}	
}

//Print 1 row
void print_row(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("#");
	}
	
	printf("\n");
}
