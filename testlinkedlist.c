#include <stdio.h>
#include <stdlib.h>


typedef struct node {
  struct node *prev;
  int data;
  struct node *next;
} node;

node* create(int value);
node* prepend(node * head, int value);
node* find(node *head, int value);
node* ndelete(node *fnode);
node* insert(node *nnode, int value, char flag);

void print(node *list);
void clear(node *list);

int main(int argc, char *argv[]) {

  node *list = create(atoi(argv[1]));

  for (int i = 2; i < argc; i++) {
    list = prepend(list, atoi(argv[i]));
  }
  
  node *inode = insert(find(list, 1), 0, 'e');

  list = (inode) ? inode : list;

  inode = insert(find(list, 9), 10, 'b');

  list = (inode) ? inode : list;

  print(list);

  clear(list);

  return 0;
}

node* insert(node *nnode, int value, char flag) {
  if (!nnode) {
    printf("No node inserted.\n");
    return NULL;
  }

  node *inode = create(value);
  if (!inode) {
    printf("No node inserted.\n");
    return NULL;
  }

  int isFirst = 0;
  
  if (flag == 'e') {
    inode->next = nnode;
    if (nnode->prev) {
      inode->prev = nnode->prev;
      nnode->prev->next = inode;
    }

    nnode->prev = inode;
  }
  else if (flag == 'b') {
    inode->prev = nnode;
    if (nnode->next) {
      inode->next = nnode->next;
      nnode->next->prev = inode;
    }else {
      isFirst = 1;
    }

    nnode->next = inode;
  }
  else {
    printf("Flags = 'b' & 'e'\n");
    return NULL;
  }

  printf("Node (%i) inserted.\n", value);
  return (isFirst) ? inode : NULL; 
}

void clear(node *list) {
  if (!list) return;

  /*
  for (node *ptr = list; ptr != NULL; ptr = ptr->prev) {
    printf("Deleting Node: %i\n", ptr->data);
     ptr = ndelete(ptr);

  }
  */

  node *ptr = list;

  while (ptr) {
    //printf("Deleting Node: %i\n", ptr->data);
    ptr = ndelete(ptr);

  }

  printf("List Freed\n");
}

node* ndelete(node *fnode) {
  if (!fnode) return NULL;

  node *head = NULL;

  if (!fnode->prev && fnode->next) {
    fnode->next->prev = NULL;
  } 
  else if (!fnode->next && fnode->prev) {
    fnode->prev->next = NULL;
    head = fnode->prev;
  }
  else if (fnode->prev && fnode->next){
    fnode->prev->next = fnode->next;
    fnode->next->prev = fnode->prev;
  }
  
  printf("Node (%i) Deleted.\n", fnode->data);
  free(fnode);

  return head;
}

node* find(node *head, int value) {
  node *ptr = head;
  
  while (ptr) {
    if (ptr->data == value) {
      printf("Found Node: %i\n", ptr->data);
      return ptr;
    }

    ptr = ptr->prev;
  }

  return NULL;
}

void print(node* list) {
  if (!list) return;

  node *ptr = list;

  printf("List: ");
  while (ptr) {
    printf("%i ", ptr->data);
    ptr = ptr->prev;
  }

  printf("\n");
}

node* prepend(node *head, int value) {
  node *nnode = create(value);
  if (!nnode) {
    return head;
  }

  nnode->data = value;
  nnode->prev = head;
  head->next = nnode;
  
  return nnode;
}

node* create(int value) {
  node *nnode = malloc(sizeof(node));
  if (!nnode) {
    return nnode;
  }

  nnode->prev = NULL;
  nnode->data = value;
  nnode->next = NULL;

  return nnode;
}
