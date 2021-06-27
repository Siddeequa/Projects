#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get height from user
    // Declare height
    int height;
    do
    {
        height = get_int("Height: \n");
    }
    while (height < 1 || height > 8); // Condition to reprompt user if height entered is outside range

    // Build pyramid

    for (int i = 1; i <= height; i++)
    {
        // Print empty spaces
        for (int j = 0; j < (height - i); j++)
        {
            printf(" ");
        }

        // Print hash
        for (int k = 0; k < i ; k++)
        {
            printf("#");
        }

        // Print newline
        printf("\n");

    }
}