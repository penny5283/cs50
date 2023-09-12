#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int get_start_size(void)
    {
        int n;
        do {
            n = get_int("Start size")
        }
        while (n > 9);
        return n
    }
    // TODO: Prompt for start size
    int get_start_size(void)
        {
            int n2;
            do {
                n2 = get_int("Start size")
            }
            while (n2 > n);
            return n2
        }
    // TODO: Prompt for end size

    // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years
}
