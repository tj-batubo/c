#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

double charCount = 0;
double senCount = 0;

int wordCount = 1;
int spaceCount = 0;

//	we're asuming sentence doesn not start or end with a space
//	so word count should be number of spaces + 1

void count_sentence(string sentence);

double get_reading_level(double letters, int words, double sents);

int main(void)
{
	string userText = get_string("Text: ");

	count_sentence(userText);
	
	double read_level = get_reading_level(charCount, wordCount, senCount);

	int index = (int) round(read_level);
	
	printf("Letters: %lf \nWords: %d \nSentences: %lf \nReading level: %lf \nRounded: %d \n", charCount, wordCount, senCount, read_level, index);


	//	if less than 1 display 1, else if greater than 16
	//	display 16+ else just number
	if (index < 1) {
	
		printf("Before Grade 1 \n");

	} else if (index > 16) {

		printf("Grade 16+ \n");

	} else {

		printf("Grade %d \n", index);

	}
}

double get_reading_level(double letters, int words, double sents) {

	letters =  (letters / words) * 100;
	sents = (sents / words) * 100;

	return (0.0588 * letters) - (0.296 * sents) - 15.8;	

}

void count_sentence(string sentence)
{
	int length = strlen(sentence);
	
	//	if there is a sentence 
	if (length > 0)
	{
		//	for every char in the string
		for (int i = 0; i < length; i++)
		{
			//	if char is an alphabet count char
			if (isalpha(sentence[i]))
			{
				charCount++;
			} 
			
			else if (sentence[i] == ' ')
			{
				//	if char is space count it
				spaceCount++;
			}
			
			//	if the char is	is punct count it
			//	if not char ispunct will be zero
			else if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
			{
				senCount++;
			}
		}

		// if there are spaces, since there isn't 
		// going to be trailing or leading white spaces
		// we can say word count is spaces + 1
		wordCount = spaceCount + 1;
	}
}
