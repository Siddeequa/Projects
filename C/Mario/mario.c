#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare variables
    int height;
    
    // Get height from user
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8); // Reprompt user if height entered is outside range
    
    // Build pyramid
    
    int counter = 1; // Initialise counter for while loop
    
    while (counter <= height)
    {
        // Print empty spaces
        for (int i = 0; i < (height - counter); i++)
        {
            printf(" ");
        }
        
        // Print first set of hashes
        for (int j = 0; j < counter; j++)
        {
            printf("#");
        }
        
        // Print spaces between hashes
        printf("  ");
        
        // Print 2nd set of hashes
        for (int k = 0; k < counter; k++)
        {
            printf("#");
        }
        
        // Print newline
        printf("\n");
        
        // Increment counter
        counter++;
    }
}