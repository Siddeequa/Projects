#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Declare variables
    float change;
    int cents;
    
    // Prompt user for amount of change 
    do
    {
        change = get_float("Change owed: ");
    }
    while (change <= 0); // Reprompt user if negative value is entered
    
    // Convert dollar into cents
    cents = round(change * 100);
    
    // Initialise number of coins to be returned
    int coins = 0;
    
    // Implement greedy algorithm
    
    while (cents >= 25)
    {
        cents = cents - 25; // Decrease amount owed by 25
        coins++; // Increase number of coins to be returned
    }
    
    while (cents < 25 && cents >= 10)
    {
        cents = cents - 10;
        coins++;
    }
    
    while (cents < 10 && cents >= 5)
    {
        cents = cents - 5;
        coins++;
    }
    
    while (cents < 5 && cents >= 1)
    {
        cents--;
        coins++;
    }
    
    // Print number of coins to be returned
    printf("%i\n", coins);
}