#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  struct stack *prev;
  int data;
} stack;

stack* init(int value) {
  stack *node = malloc(sizeof(stack));
  if (!node) {
    return node;
  }

  node->prev = NULL;
  node->data = value;
  
  return node;
}

stack* push(stack *s, int value) {
  stack *node = init(value);
  if (!node) {
    return s;
  }

  node->prev = s;

  return node;
}

stack *pop(stack *s) {
  
  stack *node = s->prev;
  free(s);

  return node;
}

void clear(stack *s) {

  stack *ptr = s;

  while (ptr) {
    
    ptr = s->prev;

    free(s);

    s = ptr;
  }
}

void print(stack *s) {
  printf("Stack:");

  for (stack *ptr = s; ptr != NULL; ptr = ptr->prev) {
    printf(" %i", ptr->data);
    
    if (ptr->prev != NULL) printf(",");
  }

  printf("\n");
}

int main(void) {
    stack *s = init(5);

    s = push(s, 4);
    s = push(s, 3);
    s = push(s, 2);
    s = push(s, 1);

  s = pop(s);

  print(s);
  clear(s);
  print(s);
}
