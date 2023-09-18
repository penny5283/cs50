#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
    n = get_int("Credit card number: \n");
    }
    while (n <= 0);
    int res = 0;
    int digit = 0;
    int count = 1;
    while (n > 0)
    {
        digit = n % 10;
        n = n / 10;
        count++;
        if (count % 2 ==0)
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
        if (count == 15) & (n[0]==3)
        printf("AMEX")
        if ()
    }
    else
    {
        printf("INVALID")
    }
    }