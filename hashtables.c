#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* linked list to store ss*/
typedef struct _list {
  struct _list *next;
  char *data;
} list;

#define HASHSIZE 101

/* K&R Hash Function
 * Produces a 32 bit hash
 * adds each char to a multiplication of the previous hashval by 31
 * to create an order dependent hash*/
unsigned int hash(char *s) {
  unsigned int hashval;

  for (hashval = 0; *s != '\0'; s++) {
    hashval = *s + (31 * hashval);
  }

  return hashval % HASHSIZE;
}

list* create(char *s) {
  list *node = malloc(sizeof(list));
  if (!node) return NULL;

  node->next = NULL;
  node->data = s;

  return node;
}

void destroy(list **hashtab) {
}

list* insert(list *l, char *s) {
  list *node = create(s);
  if (!node) return l;
  
  node->next = l;

  return node;
}

list* find(list *l, char *s) {
  list *ptr = l;

  while (ptr) {
    if (strcmp(ptr->data, s) == 0) return ptr;
    ptr = ptr->next;
  }

  return NULL;
}

void print(list **ht) {
  printf("Table\n|\n");
  for (int i = 0; i < HASHSIZE; i++) {
    if (ht[i]) {
      printf("|_ ");
      list *ptr = ht[i];

      while (ptr) {
        printf("%s", ptr->data);
        ptr = ptr->next;
        
        if (ptr) printf("->");
      }

      printf("\n");
    }
  }
}

int main(int argc, char *argv[]) {

  if (argc < 2 || argc > HASHSIZE) exit(EXIT_FAILURE);
  
  list **hashtab = calloc(HASHSIZE, sizeof(list));
  if (!hashtab) exit(EXIT_FAILURE); 

  for (int i = 1; i < argc; i++) {
    unsigned hashv = hash(argv[i]);

    if (!hashtab[hashv]) {
      hashtab[hashv] = create(argv[i]);
    } 
    else {
      list *fnode = find(hashtab[hashv], argv[i]);
      hashtab[hashv] = (fnode) ? hashtab[hashv] : insert(hashtab[hashv], argv[i]);
    }
  }

  print(hashtab);
}
