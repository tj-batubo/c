#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string str);
char rotate(int key, char pchar);

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
            // turn the argument provided into the key needed to cypher
            int key = atoi(argsv[1]);

            // get the plaintext to cypher
            string plaintext = get_string("plaintext:  ");

            printf("ciphertext: ");

            // loop throught plain text and pass each char into the rotate function
            // and print out each char returned
            for (int i = 0, length = strlen(plaintext); i < length; i++)
            {
                printf("%c", rotate(key, plaintext[i]));
            }

            printf("\n");
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

char rotate(int key, char pchar)
{
    // logic to get the char and move it's position (key) amount of places forward,
    // if reach z then wrap around back to a and continue from there
    //
    if (pchar >= 'A' && pchar <= 'Z')
    {
        // First we subtract A form pchar to get a baseline of 0 - 25 for 26 chars
        //
        // Then we add the key and divide it all by 26 use remainder
        // to see how many postitions to move after 0
        // and appearnently 19 % 26 means 19 - (26 * 19 / 26) and not whatever is left (i've kind of
        // been lied to)
        //
        // then add it to A to see hoe many places to go after A
        return (pchar - 'A' + key) % 26 + 'A';
    }
    else if (pchar >= 'a' && pchar <= 'z')
    {
        // the same formula as uppercase but with lowercase
        return (pchar - 'a' + key) % 26 + 'a';
    }

    return pchar;
}
