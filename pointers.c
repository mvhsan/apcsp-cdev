#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);

  int d = 0;
  int e = 1;

  printf("The value of d is %d and its address is %p\n", d, (void*)&d);
  printf("The value of e is %d and its address is %p\n", e, (void*)&e);

  int* ptrtod = &d;
  int* ptrtoe = &e;
  int temp = *ptrtod;
  *ptrtod = *ptrtoe;
  *ptrtoe = temp;

  printf("Post swap:\n");
  printf("The value of d is %d and its address is %p\n", d, (void*)&d);
  printf("The value of e is %d and its address is %p\n", e, (void*)&e);
}
