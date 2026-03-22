#include <stdio.h>

#define CAPACITY 5

typedef struct {
  int data[CAPACITY];
  int top;
} stack;

void push(stack *s, int value);
int pop(stack *s);

void print(stack s);

int main(void) {
  stack s;
  s.top = 0;
  
  push(&s, 1);
  push(&s, 2);
  push(&s, 3);
  push(&s, 4);
  push(&s, 5);
  push(&s, 6);
  
  print(s);

  printf("Removed (%i)\n", pop(&s));
  printf("Removed (%i)\n", pop(&s));
  printf("Removed (%i)\n", pop(&s));
  printf("Removed (%i)\n", pop(&s));
  printf("Removed (%i)\n", pop(&s));
  printf("Removed (%i)\n", pop(&s));

  print(s);
}

int pop(stack *s) {
  int top = s->top;
  int data;

  if (top > 0) top--;

  data = s->data[top];

  s->data[top] = 0;

  s->top = top;
  return data;
}


void push(stack *s, int value) {
  if (s->top < CAPACITY) {
    s->data[s->top] = value;
    s->top++;
  }
}

void print(stack s) {
  printf("Stack:");
  
  int pretop = s.top;
  pretop--;

  for (int i = 0; i < s.top; i++) {
    printf(" %i", s.data[i]);
    if (i != pretop) {
      printf(",");
    }
  }

  printf("\n");
}

