// Implements a dictionary's functionality


#include "dictionary.h"

int dictSize = 0;

typedef struct node {
	char word[LENGTH + 1];
	struct node *next;
	
} node;
node * hash_table[HASH_TABLE_LENGTH] = {0};

/**
 * Hash function via reddit user delipity:
 * https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn
 */
int hash_it(char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % HASH_TABLE_LENGTH;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
  int len = strlen(word);
  char copy[len + 1];

  for (int i = 0; i < len; i++) {
     copy[i] = tolower(word[i]);
  }

  copy[len] = '\0';

  node * current = hash_table[hash_it(copy)];
  while (current != NULL) {
    if (strcmp(current->word, copy) == 0) {
      return true;
    } else {
      current = current->next;
    }
  }
  return false;
}

/* // Loads dictionary into memory, returning true if successful else false */
bool load(const char *dictionary)
{
    FILE *file = fopen (dictionary, "r");
    if (file != NULL) {
      while(!feof(file)) {
          node *node1 = malloc(sizeof(node));

          if (node1 == NULL) {
            printf("Could not malloc a new node.\n");
            return false;
          }

          fscanf(file, "%s", node1->word);
          int h = hash_it(node1->word);
  //      If list isn't initialized then start the list.
          if (hash_table[h] == 0) {
            node1->next = NULL;
          } else {
  // 				Point the new node to the old head of the list
            node1->next = hash_table[h];
          }
  // 			Change head of linked list to the new node
          hash_table[h] = node1;
          dictSize++;
        }
        fclose (file);
        return true;
    } else {
      return false;
    }
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
  return dictSize;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    /* dictPtr = 0; */
    return true;
}

