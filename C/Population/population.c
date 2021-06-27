// Header files
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declaration of variables
    int popSize, endSize, years;

    // TODO: Prompt for start size

    // Initialise Start size of llamas population
    popSize = 0;

    do
    {
        // Getting start size as input from user
        popSize = get_int("Llamas population start size (9 or above): \n");
    }
    while (popSize < 9); // program will keep reprompting user if number entered is less than 9

    // TODO: Prompt for end size

    // Initialise End size of llamas population
    endSize = 0;

    do
    {
        // Getting end size as input from user
        endSize = get_int("Llamas population end size (greater or equal to start size): \n");
    }
    while (endSize < popSize); // program will keep prompting user if number entered is less than start size


    // TODO: Calculate number of years until we reach threshold

    // Initialise number of years
    years = 0;

    while (popSize < endSize)
    {
        // Adjusting population according to births and deaths
        popSize = popSize + (popSize / 3) - (popSize / 4);
        // Incrementing nummber of years by 1
        years++;
    }


    // TODO: Print number of years

    printf("Years: %i\n", years);

}