#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for a credit number
    long long card_number;
    do
    {
        card_number = get_long_long("Credit card number: ");
    }
    while (card_number <= 0);

    int sum = 0;
    int digit_count = 0;
    int first_digit = 0; // Initialize first_digit
    int digit;
    long long original_card_number = card_number;

    // Calculate the sum of the credit card digits
    while (card_number > 0)
    {
        digit = card_number % 10;
        card_number /= 10;
        digit_count++;
        if (digit_count % 2 == 0)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = 0;
            }
        }
        sum += digit;
    }

    //get the first digit from original card number
    while(original_card_number >= 10)
    {
        original_card_number /= 10;
    }
    first_digit = original_card_number;

    //get the second digit
    
    // Check if the card number is valid and determine its type
    if (sum % 10 == 0)
    {
        if ((digit_count == 15) && ((first_digit == 3) || (card_number == 37)))
        {
            printf("AMEX\n");
        }
        else if ((digit_count == 16) && (card_number >= 51 && card_number <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((digit_count == 13 || digit_count == 16) && (first_digit == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n"); // Added missing '\n' and semicolon
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

