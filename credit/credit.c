#include <cs50.h>
#include <stdio.h>

int main(void)
{
    do
    {
    int n = get_int("");
    }
    while (n > 0);
    int res = 0;
    int digit = 0;
    int count = 1;
    do
    {
    digit = n % 10;
    count += 1;
    if count % 2 = 0
    res += digit * 2
    else
    res += digit
    }
    while (n > 0);
}