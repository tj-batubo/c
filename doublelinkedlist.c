#include <stdio.h>
#include <stdlib.h>


typedef struct node {
  
  int data;
  struct node *prev;
  struct node *next;

} node;

node* create(int val);
node* insert(node *head, int val);
node* find(node *head, int val);
void delete(node *head);
void print(node* head);

int main(void) {

  node *list = create(9);
  if (!list) {
    exit(EXIT_FAILURE);
  }
 
  list = insert(list, 8);
  list = insert(list, 7);
  list = insert(list, 6);
  list = insert(list, 5);

  delete(find(list, 7));

  print(list);
  return 0;
}

void print(node* head) {

  while(head) {
    printf("%i\n", head->data);
    head = head->next;
  }

}

void delete(node *head) {

  head->prev->next = head->next;
  head->next->prev = head->prev;

  free(head);
}

node* find(node *head, int val) {

  if (!head) {
    return head;
  }

  node *ptr = head;

  while (ptr) {
    if (ptr->data == val) {
      return ptr;
    }

    ptr = ptr->next;
  }

  return ptr;
}

node* insert(node *head, int val) {
  if (!head) {
    return head;
  }

  node *nnode = create(val);
  if (!nnode) {
    return head;
  }
   
  head->prev = nnode;
  nnode->next = head;
  head = nnode;

  return nnode;
}

node* create(int val) {
  
  node *nnode = malloc(sizeof(node));
  if (!nnode) {
    return nnode;
  }

  nnode->data = val;
  nnode->prev = NULL;
  nnode->next = NULL;

  return nnode;
}
