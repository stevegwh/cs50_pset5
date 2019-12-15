// Implements a dictionary's functionality

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

unsigned long hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

typedef struct _node {
	char word[LENGTH];
	struct _node *next;
	
} dictionary_node;

dictionary_node * hash_table[500] = {0};

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
// 	dictionary_node HEAD;
// 	HEAD.next = NULL;
// 	HEAD.word = NULL;
    char line[LENGTH];
	int i = 0;
    FILE *file = fopen (dictionary, "r");
    if (file != NULL) {
        while (fgets (line, sizeof line, file) != NULL) {
// 			if (i == 0) {
// 				char s[LENGTH];
// 				strcpy(s, line);
// 				HEAD.word = s;
// 				i++;
// 				continue;
// 			}
// 			dictionary_node node;
// 			char s[LENGTH];
// 			strcpy(s, line);
// 			node.word = s;
// 			node.next = &HEAD;
// 			HEAD = node;
// 			printf("%s", HEAD.word);
// 			dictionary_node node;
			if (i == 500) {
				break;
			}
			dictionary_node *node = malloc(sizeof(dictionary_node));
			strcpy(node->word, line);
			hash_table[i] = node;
// 			printf("%lu ", hash(line) % 500);
// 			printf("%s", hash_table[i]->word);
			i++;
        }
		printf("%s", hash_table[2]->word);
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
