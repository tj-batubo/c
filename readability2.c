#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

double letters = 0;
int words = 0;
double sentences = 0;

void count_sentence(string sentence);

double getrl(double nLetters, double nSentences, int nWords);

int main(void)
{
    string userText = get_string("Text: ");

    count_sentence(userText);

    int index = (int) round(getrl(letters, sentences, words));

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

double getrl(double nLetters, double nSentences, int nWords)
{
    letters = (nLetters / nWords) * 100;
    sentences = (nSentences / nWords) * 100;

    return (0.0588 * letters) - (0.296 * sentences) - 15.8;
}

void count_sentence(string sentence)
{
    int length = strlen(sentence);

    for (int i = 0; i < length; i++)
    {
        if (isalpha(sentence[i]))
        {
            letters++;
        }
        else if (sentence[i] == ' ')
        {
            words++;
        }
        else if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            sentences++;
        }
    }

    words++;
}

