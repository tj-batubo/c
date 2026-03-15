#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct car {
  int year;
  char *name;
  char *model;
  bool sold;
};

typedef struct car car;

int main(void) {

  struct car car1 = {
    2008,
    "Lexus",
    "ES 350",
    false
  };

  car car2;

  car2.year = 2015;
  car2.name = "lesux";
  car2.model = "rx 350";
  car2.sold = true;


  car car3 = {
    .name = "Toyata",
    .year = 2005,
    .sold = true
  };

  car *car4 = malloc(sizeof(car));

  (*car4).name = "Tesla";

  printf("Car 1: %s\n", car1.name);
  printf("Car 2: %s\n", car2.name);
  printf("Car 3: %s\n", car3.name);
  printf("Car 4: %s\n", car4->name);

free(car4);
}
