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
    int first_two_digits = 0; // Initialize first_digit
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
            if (digit >= 10)
            digit -= 9;
        }
        // printf("%d", digit);
        // printf("\n");
        sum += digit;
    }

    //get the first two digits from original card number
    while(original_card_number >= 100)
    {
        original_card_number /= 10;
    }
    first_two_digits = original_card_number;
    printf("%d", sum);
    printf("%d", digit_count);
    // Check if the card number is valid and determine its type
    if (sum % 10 == 0)
    {
        if ((digit_count == 15) && ((first_two_digits == 34) || (first_two_digits == 37)))
        {
            printf("AMEX\n");
        }
        else if ((digit_count == 16) && (first_two_digits >= 51 && first_two_digits <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((digit_count == 13 || digit_count == 16) && (first_two_digits/10 == 4))
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

