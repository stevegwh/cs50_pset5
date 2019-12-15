
// Implements a dictionary's functionality


#include "dictionary.h"

int dictSize = 0;

typedef struct node {
	char word[LENGTH + 1];
	struct node *next;
	
} node;
node * hash_table[HASH_TABLE_LENGTH];

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
  char word_copy[len + 1];

  for (int i = 0; i < len; i++) {
     word_copy[i] = tolower(word[i]);
  }

  word_copy[len] = '\0';

  node * current = hash_table[hash_it(word_copy)];
  while (current != NULL) {
    if (strcmp(current->word, word_copy) == 0) {
      return true;
    } else {
      current = current->next;
    }
  }
  return false;
}

/* // Loads dictionary into memory, returning true if successful else false */
/* bool load(const char *dictionary) */
/* { */
/*     for (int i = 0; i < HASH_TABLE_LENGTH; i++) */
/*     { */
/*         hash_table[i] = NULL; */
/*     } */
/*     char line[LENGTH]; */
/*     FILE *file = fopen (dictionary, "r"); */
/*     if (file != NULL) { */
/*         while (fgets (line, sizeof line, file) != NULL) { */
/*       node *node1 = malloc(sizeof(node)); */
/*       if (node1 == NULL) { */
/*         printf("Could not malloc a new node.\n"); */
/*         return false; */
/*       } */
/*       strcpy(node1->word, line); */
/*       int i = hash_it(node1->word); */
/* // 			Check if linked list initialized. If so, make new element the new head */
/*       if (hash_table[i] == NULL) { */
/*         node1->next = NULL; */
/*       } else { */
/* // 				Point to the head of the table */
/*         node1->next = hash_table[i]; */
/*       } */
/* // 			Change end of linked list to the new element */
/*       hash_table[i] = node1; */
/*       dictSize++; */
/*         } */
/* // 		printf("%s", hash_table[0]->next->next->next->word); */
/*         fclose (file); */
/*         return true; */
/*     } else { */
/*     return false; */
/*     } */
/* } */

bool load(const char* dictionary)
{
    // make all hash table elements NULL
    for (int i = 0; i < HASH_TABLE_LENGTH; i++)
    {
        hash_table[i] = NULL;
    }

    // open dictionary
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("Could not open dictionary.\n");
        return false;
    }

    while (true)
    {
        // malloc a node for each new word
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Could not malloc a new node.\n");
            return false;
        }

        // read a word from the dictionary and store it in new_node->word
        fscanf(fp, "%s", new_node->word);
        new_node->next = NULL;

        if (feof(fp))
        {
            // hit end of file
            free(new_node);
            break;
        }

        dictSize++;

        // hashtable[h] is a pointer to a key-value pair
        int h = hash_it(new_node->word);
        node* head = hash_table[h];

        // if bucket is empty, insert the first node
        if (head == NULL)
        {
            hash_table[h] = new_node;
        }
        // if bucket is not empty, attach node to front of list
        // design choice: unsorted linked list to minimize load time rather
        // than sorted linked list to minimize check time
        else
        {
            new_node->next = hash_table[h];
            hash_table[h] = new_node;
        }
    }
    // close dictionary
    fclose(fp);
    return true;
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

