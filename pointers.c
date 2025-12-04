#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int *x = malloc(3 * sizeof(int));
	x[0] = 71;
	x[1] = 72;
	x[2] = 73;
	free(x);	
}
