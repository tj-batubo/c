#include <cs50.h>
#include <stdio.h>

void draw(int height);
void drawb(int height);

int main(void)
{
	int height = get_int("Height: ");
	drawb(height);	
}

void draw(int height)
{	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}

void drawb(int height)
{

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < height - i; j++)
		{
			printf("#");
		}

		printf("\n");
	}
}
