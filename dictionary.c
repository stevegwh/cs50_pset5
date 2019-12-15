// Implements a dictionary's functionality

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "dictionary.h"

char * dict[10];
char ** dictPtr = dict;

// Returns true if word is in dictionary else false
bool check(__attribute__((unused)) const char *word)
{
  return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    int len = sizeof(dict)/sizeof(char *);
    char line[LENGTH];
    FILE *file = fopen (dictionary, "r");
    if (file != NULL) {
        int i = 0;
        while (fgets (line, sizeof line, file) != NULL) {
            if ( i == len  - 1) {
              int origlen = len;
              len *= 2;
              char * tmp[len];
              for (int x = 0; x < origlen; x++) {
                tmp[x] = dictPtr[x];
              }
              dictPtr = tmp;
            }
            dictPtr[i] = line;
            printf("%s", dictPtr[i]);
            i++;
        }
        /* fprintf(stdout, "%d", len); */
        fclose (file);
        // Stash array size at start of array 
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
