#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// Array containing lowercase letters
int alphalower[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
// Array containing uppercase letters
int alphaupper[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        if (score1 < score2)
        {
            printf("Player 2 wins!\n");
        }
        else
        {
            printf("Tie!\n");
        }
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    // Declare return variable
    int points[100]; // To hold points for each letter
    int score = 0;

    for (int i = 0, n = strlen(word); i < n; i++) // Iterate over each letter in word
    {
        if (islower(word[i]))
        {
            for (int j = 0; j < 26; j++) // Iterate through lowercase alphabets array
            {
                if (word[i] == alphalower[j]) // Check whether letter is in array
                {
                    points[i] = POINTS[j]; // Allocate points as per index (index in points array same as index in alphabets array)
                }
            }
        }
        else
        {
            if (isupper(word[i]))
            {
                for (int a = 0; a < 26; a++) // Iterate through uppercase alphabets array
                {
                    if (word[i] == alphaupper[a])
                    {
                        points[i] = POINTS[a];
                    }
                }
            }
            else
            {
                points[i] = 0; // Allocate zero points if other characters entered
            }
        }

        // Add score
        score = score + points[i];
    }
    // Output score
    return score;
}