#include <stdio.h>

void swap(int *a, int *b);

int main(void) {
	int x = 1;
	int y = 2;

	printf("x is %i, y is %i\n", x, y);
	swap(&x, &y);
	printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b) {

	//we're now passing in the adress so we first we store a in a temp
	int temp = *a;
	// then we store the derefrence of b in def a
	*a = *b;
	// then we store temp in deref of b
	*b = temp;
	
}
