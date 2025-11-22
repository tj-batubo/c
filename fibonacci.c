#include <stdio.h>
#include <stdlib.h>

void fibonacci(int previous, int current, int length);

int main(int argc, char *argv[]) {
		
	// if it's greater than 2, show usage error
	if (argc > 2) {
		printf("Usage: ./fib [length] || 10\n");
		return 1;
	}

	//set fib length to 10 if no args provided
	int length = argc < 2 ? 10 : atoi(argv[1]);

	// function will accept the first two starting numbers and the length for how many fib numbers to print in total 
	fibonacci(0,1,length);
}

void fibonacci(int previous, int current, int length) {
	
	// if length is less then 0, stop;
	if (length == 0) {
		printf("\n");		
		return;
	}
	
	
	// first print out previous
	printf(" %d ", previous);

	// print new current by adding previous and current
	fibonacci(current, current + previous, length - 1);
	
}
