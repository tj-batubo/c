#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool only_digits(string str);

// provide arguments
int main(int argsc, string argsv[])
{
    // if arguments provided are just the program or more than 2, send a usage error
    if (argsc != 2)
    {
        printf("Usage: ./ceaser key\n");
        return 1;
    }
    // if they are
    else
    {
        // check if the argument is made up of just digits
        if (only_digits(argsv[1]))
        {
            return 0;
        }
        // if not tell send a usage error
        else
        {
            printf("Usage: ./ceaser key\n");
            return 1;
        }
    }
}

// function to check if an argument is made of just digits
bool only_digits(string str)
{
    // logic to check whether a string contains only digits or chars

    // loop through the string
    for (int i = 0, length = strlen(str); i < length; i++)
    {
        // check if the character code is between 49 & 57 (0 & 9) inclusive
        // if a char is not return false
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
            return false;
        }
    }

    return true;
}
