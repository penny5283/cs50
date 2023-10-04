#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string rotate(string plaintext, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string keystring = argv[1];

    for (int i = 0, n = strlen(keystring); i < n; i++)
    {
        if (!isdigit(keystring[i]))
        {
            printf("Key must contain only numeric characters.\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    if (key <= 0)
    {
        printf("Key must be a positive integer.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    string ciphertext = rotate(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

string rotate(string plaintext, int key)
{
    string outcome = plaintext;

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char alpha = plaintext[i];

        if (isalpha(alpha))
        {
            char post_char = alpha;

            if (islower(alpha))
            {
                // Rotate lowercase letters
                post_char = 'a' + ((alpha - 'a' + key) % 26 + 26) % 26;
            }
            else if (isupper(alpha))
            {
                // Rotate uppercase letters
                post_char = 'A' + ((alpha - 'A' + key) % 26 + 26) % 26;
            }

            outcome[i] = post_char;
        }
    }
    return outcome;
}

