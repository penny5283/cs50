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
    do
    {
    digit = n % 10;
    count += 1;
    if count % 2 = 0
    {
    res += digit * 2
    }
    else
    {
        res += digit
    }
    while (n > 0);
    if res % 10 =0
    printf("1")
    else
    printf("2")
}