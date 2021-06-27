#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get number
    long number = get_long("Number: ");

    // Implement checksum

    // Initialise variables
    long last_two = 0, before_last = 0, last = 0, product = 0, product_first = 0, product_last = 0, sum = 0;

    for (long i = number; i > 0; i /= 100)
    {
        // Get last two digits
        last_two = i % 100;

        // Get two last digits separately
        last = last_two % 10;
        before_last = last_two / 10;

        // Multiply before last digit by 2
        product = before_last * 2;

        // Get product digits separately
        if (product >= 10)
        {
            product_last = product % 10;
            product_first = product / 10;
        }
        else
        {
            product_last = product % 10;
            product_first = 0;
        }

        // Add all digits together
        sum = sum + product_first + product_last + last;
    }

    // Validate checksum
    if (sum % 10 == 0)
    {
        // Getting digit count
        // Initialise counter
        int i = 0;
        long num = number;

        while (num > 0)
        {
            num /= 10;
            i++;
        }

        // Getting first two numbers
        long first = 0, second = 0;

        while (number > 10)
        {
            first = number / 10;
            second = number % 10;
            number /= 10;
        }

        // For American Express - 15 digits & starts with 34 or 37
        if (i == 15 && first == 3 && (second == 4 || second == 7))
        {
            printf("AMEX\n");
        }
        else
        {
            // For Mastercard - 16 digits & starts with 51, 52, 53, 54, 55
            if (i == 16 && first == 5 && (second > 0 && second < 6))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                //For Visa - 13|16 digits & starts with 4
                if ((i == 13 || i == 16) && first == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

