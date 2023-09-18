#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
        n = get_int("Height: \n");
    while (n < 1 || n > 8);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (int a = 1; a <= i; a++)
        {
            printf("#");
        }
        printf("  ");
        for (int b = 1; b <= i; b++)
        {
            printf("#");
        }
        printf("\n");
    }
}
