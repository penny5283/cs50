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
    while (n <= 0);

    int res = 0;
    int digit = 0;
    int count = 1;
    int first_digit = 0;

    first_digit = n

    while (n > 0)
    {
        digit = n % 10;
        n = n / 10;
        count++;

        if (count % 2 == 0)
        {
            res += digit * 2;
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