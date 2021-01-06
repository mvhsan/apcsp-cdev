#include <stdio.h>

int main()
{
  int a;
  int b = 3;
  int c;

  a = 2;
  c = a + b;
  printf("Sum of %d and %d is %d\n", a, b, c);
  printf("a is currently %d and c is currently %d\n", a, c);

  int placeholder = a;
  a = c;
  c = placeholder;
  printf("a is now %d and c is now %d\n", a, c);
}
