#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function declarations
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float average(int number, int word);
int coleman_liau_index(float letter, float sentence);

int main(void)
{
    // Get input 
    string text = get_string("Text: ");
    
    // Count letters
    int count_letter = count_letters(text); // Call count letters function and store value in count_letter

    // Count words
    int count_word = count_words(text); //Call count words function and store value in count_word

    // Count sentences
    int count_sentence = count_sentences(text); // Call count sentences function and store value in count_sentence
    
    // Output grade level
    
    // Average number of letters per 100 words
    float avg_letter = average(count_letter, count_word); // Call average function and store float result in float variable
    
    // Average number of sentences per 100 words
    float avg_sentence = average(count_sentence, 
                                 count_word); // Call average function, pass in needed args and store result in float variable

    // Call Coleman-Liau index function
    int index = coleman_liau_index(avg_letter, avg_sentence); // Pass in required arguments and store int result in int variable
    
    // Output index result
    if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        if (index < 1)
        {
            printf("Before Grade 1\n");
        }
        else
        {
            printf("Grade 16+\n"); // If it is not less than 16, it should be 16 or above 
        }
    }
}

// Functions

// Count number of letters
int count_letters(string text)
{
    // Variable to store alphabet count
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++) // Iterate over each character in entered text
    {
        if (isalpha(text[i])) // Checks only alphabets
        {
            count++;
        }
    }
    return count;
}

// Count number of words
int count_words(string text)
{
    // Each word is separated by a space. If there are 4 spaces, it means there are 5 words.
    
    // Variable to store count
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++) // Iterate over eavery character entered
    {
        if (isspace(text[i])) // Checks for spaces
        {
            count++;
        }
    }
    // Add 1 to number of spaces to get number of words
    count++;
    return count;
}

// Count sentences
int count_sentences(string text)
{
    // Each sentence ends with a period, an exclamation point or a question mark
    
    // Variable to store count
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

// Calculate average per 100 words
float average(int number, int word)
{
    // Cast values to float for precision because of averaging
    
    float average = (float) number / (float) word * 100;
    return average;
}

// Coleman-Liau index 
int coleman_liau_index(float letter, float sentence)
{
    float index = 0.0588 * letter - 0.296 * sentence - 15.8; // Coleman-Liau index formula
    
    // Round index to nearest integer
    index = round(index); 
    return index;
}
