#include <stdio.h>

#define CAPACITY 5

typedef struct _queue {

  int data[CAPACITY];
  int front;
  int size;

} queue;

void enqueue(queue *que, int value) {
  int size = que->size + que->front;
  
  if (size < CAPACITY) {
    que->data[size] = value;
    que->size++;
    printf("\nQued: (%i).\nQue Size: (%i).\nQue Front: (%i).\n", value, que->size, que->front);
  }
  else {
    printf("\n(%i) Not Qued.\n", value);
  }
}

int dequeue(queue *que) { 
  if (que->size > 0) {
    int data = que->data[que->front];
  
    que->data[que->front] = 0;
    
    if (que->front < (CAPACITY - 1)) {
      que->front++;
    }

    que->size--;

    printf("\nDequed: (%i).\nQue Size: (%i).\nQue Front: (%i).\n", data, que->size, que->front);
    return data;
  }
  else {
    printf("\nNo Items In Que.\n");
  }

  return 0;
}

void print(queue que) {
  int size = que.size + que.front;

  printf("Que: ");

  for (int i = que.front; i < size; i++) {

    printf(" %i", que.data[i]);

    if (i < (size - 1)) {
      printf(",");
    }
  }

  printf(".\n");
} 

int main(void) {
  
  queue que;
  que.front = 0;
  que.size = 0;
  
  enqueue(&que, 313411);
  enqueue(&que, 4312312);
  enqueue(&que, 32434);
  enqueue(&que, 453453);
  enqueue(&que, 675635);
  enqueue(&que, 4534535);

  
  dequeue(&que);
  dequeue(&que);
  dequeue(&que);
  dequeue(&que);
  dequeue(&que);
  dequeue(&que);
  

  //print(que);
  return 0;
}
