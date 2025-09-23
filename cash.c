#include <cs50.h>
#include <stdio.h>

int calculate_change(int change);

int main(void)
{
    int change;
    do
    {
        change = get_int("Change owned: ");
    }
    while (change < 0);

    printf("%i \n", calculate_change(change));
}

int calculate_change(int change)
{
    int cents = change / 25;
    change -= cents * 25;

    int dimes = change / 10;
    cents += dimes;
    change -= dimes * 10;

    int nickels = change / 5;
    cents += nickels;
    change -= nickels * 5;

    return cents + change;
}

