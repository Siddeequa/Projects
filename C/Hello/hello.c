#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for name 
    string name = get_string("What is your name?\n");
    
    // Greeting user
    printf("hello, %s\n", name);
}