#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2) // Argument counts comprises run command and key
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++) // Iterate over key character by character
        {
            if (!isdigit(argv[1][i])) // If character is not a digit
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        // Convert string argument into integer
        int key = atoi(argv[1]); // Store in integer type variable

        string plaintext = get_string("plaintext: "); // Get plaintext from user
        int len_plaintext = strlen(plaintext); // Length of plaintext

        // Declare an array of the same size as plaintext to hold ciphertext
        int ciphertext[len_plaintext]; // Array is of type integer because integers will be added to plaintext ascii values

        for (int i = 0, n = strlen(plaintext); i < n; i++) // Iterate over plaintext elements entered
        {
            if (!isalpha(plaintext[i])) // If not an alphabet
            {
                ciphertext[i] = plaintext[i]; // Store as it is
            }
            else
            {
                int check = plaintext[i] + key; // Variable check will store integer ascii value of rotated value

                if (isupper(plaintext[i])) // If alphabet is uppercase
                {
                    if (check > 90) // Ascii value of capital z is 90. If it will exceed the ascii uppercase letters range
                    {
                        // Remove ascii value 'A' to get numbers to zero so that we can use caesar formula
                        // Formula: ci = (pi + k) % 26
                        // Remove 'A' from plaintext alphabet and perform operation
                        // If value goes beyond 26, the modulo operator will wrap it back to the start
                        // Then add 'A' value again as per ascii chart to get value in actual ascii chart

                        // Adjust formula
                        ciphertext[i] = (((plaintext[i] - 'A') + key) % 26) + 'A';
                    }
                    else
                    {
                        ciphertext[i] = plaintext[i] + key;
                    }
                }
                else
                {
                    if (check > 122) // Ascii value for lowercase z
                    {
                        ciphertext[i] = (((plaintext[i] - 'a') + key) % 26) + 'a';
                    }
                    else
                    {
                        ciphertext[i] = plaintext[i] + key;
                    }
                }
            }
        }

        // Print ciphertext
        printf("ciphertext: ");
        // Iterate over ciphertext array element by element
        for (int i = 0, n = (sizeof ciphertext / sizeof ciphertext[0]); i < n; i++)
        {
            printf("%c", ciphertext[i]); // Print element in ciphertext array
        }
        //Print a new line at the end of iteration operation
        printf("\n");
    }
    else // If less or more than 2 argument count
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Exit by returning zero from main
    return 0;
}