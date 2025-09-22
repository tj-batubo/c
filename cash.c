#include <cs50.h>
#include <stdio.h>

int main(void)
{

	int change;
	do 
	{
		int change = get_int("Change owned: ");
	} while (change < 1);

	// Calculate how many quarters you should give customer
    	// Subtract the value of those quarters from cents

    	// Calculate how many dimes you should give customer
    	// Subtract the value of those dimes from remaining cents

    	// Calculate how many nickels you should give customer
    	// Subtract the value of those nickels from remaining cents

    	// Calculate how many pennies you should give customer
    	// Subtract the value of those pennies from remaining cents

    	// Sum the number of quarters, dimes, nickels, and pennies used
    	// Print that sum


}

int get_quarters(int change)
{
	int quarters = change /  0.25;
	if (quarters % 0.25 != 0)
	{
			
	}

}
