#include <cs50.h>
#include <stdio.h>

string cipher_input(string plaintext);

int main(int argc, string argv[])
{
//get the input from user
do
string plaintext = get_string("caesar key:");
while (isdigit())
//process the input
string ciphertext = cipher_input(plaintext);
//print the outcome in a proper way

}
int cipher_input(string plaintext)
{
    string outcome = 0;
    char alpha = 0;
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char alpha = plaintext[i];
        outcome += alpha + 1;
    }
    return outcome;
}

