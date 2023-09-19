#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompte user for a credit number
    long long card_number;
    do
    {
    card_number = get_long_long("Credit card number: ");
    }
    while (card_number <= 0);

    int sum = 0;
    int digit_count = 0;
    int res = 0;
    int digit;

    while (card_number > 0)
    {
        int digit = card_number % 10;
        card_number /= 10;
        digit_count++;
        first_digit = card_number;

        if (digit_count % 2 == 0)
        {
            digit *= 2;
        }
            if (digit > 9)
            {
                digit -= 9;
            }
        sum += digit;
    }


// check if the card number is valid and determine its type
if(sum % 10 == 0)
{
    if(digit_count == 15 && (card_number ==34 || card_number == 37))
    {
        printf("AMEX\n");
    }
    else if(digit_count == 16 && (card_number >= 51 && card_number <= 55))
        printf("MASTERCARD\n");
    else if((digit_count == 13 || digit_count ==16)) && (first_digit == 4)
        printf("CREDIT\n")
    else
        printf("INVALID")
}
