#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

int main(int argc, string argv[])
{ 
    if (argc == 2) // If only 1 command line arg entered
    {
        // Check that key is alphabetic and contains 26 letters without repetition
        
        int length = strlen(argv[1]); // Length of string entered
        if (length == 26) // Ensuring there are 26 characters
        {
            for (int i = 0; i < length; i++) // Iterate over each charater entered
            {
                if (isalpha(argv[1][i])) //Ensuring an alphabet is entered
                {
                    // Iterate over array again to check each character against each other
                    for (int j = (i + 1); j < length; j++) // Initialise j to (i + 1) so that argv[i] is not compared to itself
                    {
                        if (argv[1][i] == argv[1][j]) // If there is repetition
                        {
                            printf("Key must not contain repeated characters.\n"); // Print error message
                            return 1; 
                        }
                    }
                }
                else
                {
                    printf("Key must only contain alphabetic characters.\n"); // Print error message 
                    return 1;
                }
            }
        }
        else
        {
            printf("Key must contain 26 characters.\n"); // Print error message
            return 1;
        }
        
        // After validating key
        string key = argv[1]; // Assign string to variable key
        
        // Convert key to uppercase
        for (int i = 0; i < 26; i++)
        {
            key[i] = toupper(key[i]);
        }
        
        // Get plaintext from user
        string plaintext = get_string("plaintext: ");
        
        // Map plaintext characters to key
        
        // Array to hold ciphertext
        int len_plaintext = strlen(plaintext); // Length of plaintext entered
        char ciphertext[len_plaintext]; // Give ciphertext array same length as plaintext
        
        // First, map ordered letters of the alphabet to letters in key
        
        // String of alphabets with which to match key characters
        string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        
        // Proceed to encipher plaintext
        for (int i = 0; i < len_plaintext; i++) // Iterate over plaintext
        {
            if (isalpha(plaintext[i])) // If character is an alphabet
            {
                if (isupper(plaintext[i])) // If alphabet is uppercase
                {
                    for (int j = 0; j < 26; j++) // Iterate over string alpha
                    {
                        if (plaintext[i] == alpha[j]) // If character matches
                        {
                            ciphertext[i] = key[j];
                        }
                    }
                }
                else // If character is lowercase
                {
                    for (int j = 0; j < 26; j++) // Iterate over string alpha
                    {
                        if (plaintext[i] == tolower(alpha[j])) // If character matches
                        {
                            ciphertext[i] = tolower(key[j]);
                        }
                    }
                }
            }
            else
            {
                ciphertext[i] = plaintext[i]; // Store character as it is
            }
        }
        
        // Print ciphertext
        printf("ciphertext: ");
        // Iterate over ciphertext array to print out all characters
        for (int i = 0, n = (sizeof ciphertext / sizeof ciphertext[0]); i < n; i++)
        {
            printf("%c", ciphertext[i]);
        }
        // Print new line
        printf("\n");
    }
    else
    {
        printf("Usage: ./substitution key\n"); // Print error message 
        return 1;
    }
    
    // Exit by returning zero from main
    return 0;
}