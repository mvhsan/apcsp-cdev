#include<stdio.h>

int main()
{
  int a = 545;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));

  long int b = 545;
  printf("long int b value: %li and size: %lu bytes\n", b, sizeof(b));

  unsigned int c = 545;
  printf("unsigned int c value: %u and size: %lu bytes\n", c, sizeof(c));

  char d = 'a';
  printf("char d value: %c and size: %lu bytes\n", d, sizeof(d));

  double e = 54.5;
  printf("double e value: %f and size: %lu bytes\n", e, sizeof(e));

}

