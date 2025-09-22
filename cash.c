#include <cs50.h>
#include <stdio.h>

int get_quarters(int change, int *cents);
int get_dimes(int change, int *cents);
int get_nickels(int change, int *cents);
int calculate_change(int change, int *cents);

int main(void)
{
	int change;
	do
	{
		change = get_int("Change owned: ");
	} while (change < 0);
	
	calculate_change(change, &change);
}

int calculate_change(int change, int *cents)
{
	int quarters = get_quarters(change, *cents);
	int dimes = get_dimes(change, *cents);
	int nickels = get_nickels(change, *cents));
}

int get_quarters(int change, int *cents)
{
	int quarters = 0;
	while (change >= 25)
	{
		quarters++;
		change -= 25;
	}
	
	*cents = change;
	return quarters;
}

int get_dimes(int change, int *cents)
{
        int dimes = 0;
        while (change >= 10)
        {
                dimes++;
                change -= 10;
        }

        *cents = change;
        return dimes;
}

int get_nickels(int change, int *cents)
{
        int nickels = 0;
        while (change >= 5)
        {
                nickels++;
                change -= 5;
        }

        *cents = change;
        return nickels;
}
