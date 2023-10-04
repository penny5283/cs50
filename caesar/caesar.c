#include <cs50.h>
#include <stdio.h>

string cipher_input(string plaintext);
int key = 0;
int main(int argc, string argv[])
{
// Check if the string contains only digits or is a valid number
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+') {
            printf("Usage: ./caesar key")
            return 1; // Not a number
        }
    }
    int key = argc;
    return 0; // It's a number
//get string input from user
    string plaintext = get_string("plaintext: ");
//process the input
    string ciphertext = rotate(plaintext);
//print the outcome in a proper way
    printf("ciphertext: %c", ciphertext);
}
string rotate(string plaintext)
{
    string outcome = 0;
    char alpha = 0;
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char alpha = plaintext[i];
        char post_char = alpha + key;
        if (post_char >= 'a' && post_char <= 'z')
        {
            //rotate lowercase letters
            post_char = 'a' + (post_char - 'a' + 1) % 26;
        }
        else if (post_char >= 'A' && post_char <= 'Z')
        {
            //rotate uppercase letters
            post_char = 'A' + (post_char - 'A' + 1) % 26;
        }
        outcome += post_char;
    }
    return outcome;
}

