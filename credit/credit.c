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
    int count = 1;
    do
    {
    res += n % 10;
    count += 1;
    }
    while (n > 0);
}