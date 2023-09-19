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
    int digit_count = 1;

    while (card_number > 0)
    {
        int digit = card_number % 10;
        card_number /= 10;
        digit_count++;

        if (digit_count % 2 == 0)
        {
            digit *= 2;
        }
            if (digit > 9)
            {
                digit -= 9;
            }
    }
    sum += digit;
}
