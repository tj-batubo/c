#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node* create(int value);
node* prepend(node* head, int value);
int destroy(node* head);
int destroy2(node* head);


int main(void) {
  node *list = create(7);

  if (!list) {
    exit(EXIT_FAILURE);
  }
  
  list = prepend(list, 6);
  
  if (!list) {
    exit(EXIT_FAILURE);
  }

  printf("%i\n", list->data);
  
  destroy(list);
  printf("%i\n", list->data);

  return 0;
}

node* create(int value) {
  node *nnode = malloc(sizeof(node));

  if (!nnode) {
    return nnode;
  }

  nnode->data = value;
  nnode->next = NULL;

  return nnode;
}

node* prepend(node* head, int value) {
  node *nnode = malloc(sizeof(node));

  if (!nnode) {
    return nnode;
  }

  nnode->data = value;
  nnode->next = head;

  head = nnode;

  return head; 
}

int destroy(node* head) {
  
  if (!head) {
    return 0;
  }
    
  if (head->next) {
    destroy(head->next);
  }

  free(head);
  return 0;
}

int destroy2(node* head) {

  if (!head) {
    return 0;
  }

  destroy2(head->next);

  free(head);
  return 0;
}
