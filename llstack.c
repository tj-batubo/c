#include <stdio.h>
#include <stdlib.h>


typedef struct stack {
  struct stack *prev;
  int data;
} stack;

stack *init(int value);
stack *push(stack *s, int value);
stack *pop(stack *s);

void print(stack *s);
void clear(stack *s);

int main(void) {

  stack *linkeds = init(4);
  linkeds = push(linkeds, 3);
  linkeds = push(linkeds, 2);
  linkeds = push(linkeds, 1);

  print(linkeds);
  clear(linkeds);
  print(linkeds);
}

void clear(stack *s) {
  stack *ptr = s;

  while (ptr) {
    ptr = pop(ptr);
  }
  
  printf("Stack Freed.\n");
}

stack *pop(stack *s) {
  stack *top = NULL;
  int data = s->data;
  if (s->prev) {
    top = s->prev;
  }

  free(s);
  printf("Deleted (%i)\n", data);
  return top;
}


void print(stack *s) {
  printf("Stack:");
  for (stack *ptr = s; ptr != NULL; ptr = ptr->prev) {
    printf(" %i", ptr->data);
    if (ptr->prev != NULL) printf(",");
  }

  printf("\n");
}

stack *init(int value) {
  stack *s = malloc(sizeof(stack));
  if (!s) return NULL;

  s->data = value;
  s->prev = NULL;
}

stack *push(stack *s, int value) {
  stack *linkeds = init(value);
  if (!linkeds) return s;

  linkeds->data = value;
  linkeds->prev = s;
  return linkeds;
}

