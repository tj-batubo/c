#include <cs50.h>
#include <stdio.h>
#include <string.h>

int getscore(string word);

int checkcase(char letter);

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
	int player1 = getscore(get_string("Player 1: "));
	int player2 = getscore(get_string("Player 2: "));

	if (player1 > player2)
	{
		printf("Player 1 wins!\n");
	} else if (player2 > player1)
	{
		printf("Player 2 wins!\n");
	} else 
	{
		printf("Tie!\n");
	}
}

int getscore(string word)
{
	int score = 0;
	
	//	loop through every letter in the string
	for (int i = 0; i < strlen(word); i++)
	{//	for every char in the string get its position in 0 - 25 by doing (A - char)
	 //	function to check case
	 int lcase = checkcase(word[i]);

	 // set index to 0 so it
	 int index = 0;

	 switch (lcase) {
	 	
		 case 0:
			 index = word[i] - 'A';
			 break;
		case 1:
			index = word[i] - 'a';
			break;
		defualt: 
			// if word is a sign not a char just give it one point
			break;
	 } 
		
		//	then check the it score in poits array by passing it as an index
		score+=POINTS[index];
	}

	return score;
}

int checkcase(char letter)
{
	//	if letter is in the range of uppercase it returns 0
	if (letter >= 'A' && letter <= 'Z')
	{
		return 0;
	} else if (letter >= 'a' && letter <= 'z')
	{
		return 1;
	} else 
	{
		return 2;
	}
	//	if lower retun 1
	//	else return 2
}
