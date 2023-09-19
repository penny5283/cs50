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
        else
        {
            res += digit;
        }
        }
    if (res % 10 == 0)
    {
        if (count == 15 && n[0]==3)
        printf("AMEX");
        if (count == 16 && n[0]==5)
        printf("MASTERCARD");
        if (count == 13 || count == 16)
            if n[0]==4
            printf("VISA");

    }
    else
    {
        printf("INVALID")
    }
    }