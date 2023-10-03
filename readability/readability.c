#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int number_o_letters(string txt);
int number_o_sentences(string txt);
int number_o_words(string txt);

int main(void)
{
    // get input from user
    string text = get_string("Text:");
    // score the whole text
    int l = number_o_letters(text);
    int s = number_o_sentences(text);
    int w = number_o_words(text);
    float avg_l = (float) l / w * 100;
    float avg_s = (float) s / w * 100;
    int index = (int) (0.0588 * avg_l - 0.296 * avg_s - 15.8 + 0.5);

    // Print the readability level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

int number_o_letters(string txt)
{
    int count_l = 0;
    for (int i = 0, n = strlen(txt); i < n; i++)
    {
        char alpha = txt[i];
        if (isalpha(alpha))
        {
            count_l += 1;
        }
    }
    return count_l;
}
int number_o_sentences(string txt)
{
    int count_s = 0;
    for (int i = 0, n = strlen(txt); i < n; i++)
    {
        char alpha = txt[i];
        if (alpha == '!' || alpha == '.' || alpha == '?')
        {
            count_s += 1;
        }
        else
        {
            count_s += 0;
        }
    }
    return count_s;
}
int number_o_words(string txt)
{
    int count_w = 0;
    for (int i = 0, n = strlen(txt); i < n; i++)
    {
        char alpha = txt[i];
        if (alpha == ' ')
        {
            count_w += 1;
        }
    }
    count_w += 1;
    return count_w;
}