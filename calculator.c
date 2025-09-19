#include <stdio.h>
#include <cs50.h>

int main(void)
{
	int x = get_int("Division \nX: ");
	int y = get_int("Y: ");

	printf("Output: %.7f \n", (float) x / y);
}
