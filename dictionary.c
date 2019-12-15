// Implements a dictionary's functionality

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

typedef struct _node {
	char word[LENGTH];
	struct _node *next;
	
} dictionary_node;


dictionary_node * hash_table[HASH_TABLE_LENGTH] = {0};

// Returns true if word is in dictionary else false
bool check(__attribute__((unused)) const char *word)
{
  /* for (int i = 0; i <= dictSize; i++) { */
  /*   printf(" %s ", dictPtr[i]); */
  /* } */
  return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char line[LENGTH];
	int i = 0;
    FILE *file = fopen (dictionary, "r");
    if (file != NULL) {
        while (fgets (line, sizeof line, file) != NULL) {
			i = i % HASH_TABLE_LENGTH;
			dictionary_node *node = malloc(sizeof(dictionary_node));
			strcpy(node->word, line);
			// Check if linked list initialized. If so, make new element the new head
			if (hash_table[i] == 0) {
				node->next = NULL;
				printf("Linked list doesn't exist. \n");
			} else {
				printf("Exists, changing head. \n");
				// Point to the head of the table
				node->next = hash_table[i];
			}
			// Change end of linked list to the new element
			hash_table[i] = node;
			i++;
        }
		printf("%s", hash_table[0]->next->next->next->word);
        fclose (file);
        return true;
    } else {
		return false;
    }
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
  return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    /* dictPtr = 0; */
    return true;
}
