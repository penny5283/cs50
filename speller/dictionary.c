// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <strings.h>
#include <stdlib.h> 
extern int count;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int index = 0;
    index = hash(word);
    node *cursor = table[index];
    while(cursor != NULL)
    {
       if (strcasecmp(cursor->word, word) == 0) {
        return true;  // Word found
    }
    cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int index = 0;
    int len = strlen(word);
    if (len > 0) {
        index += (toupper(word[0]) - 'A') * 26 * 26;
    }
    if (len > 1) {
        index += (toupper(word[1]) - 'A') * 26;
    }
    return index % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL) {
        return false;
    }
    char word[LENGTH + 1];
    count = 0;
    while(fscanf(file, "%s", word) != EOF)
    {
        count += 1;
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
        }
        //copy the word into the node
        strcpy(new_node->word, word);
        unsigned int index = hash(word);
        // Insert the node at the beginning of the linked list in the bucket
        new_node->next = table[index];
        table[index] = new_node;
    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N; i++)
    {
    node *cursor = table[i];
    while(cursor != NULL)
    {
        node *tmp = cursor;
        cursor = cursor -> next;
        free(tmp);
    }
    }
    return true;
}
