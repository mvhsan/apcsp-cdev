#include <stdio.h>
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, int* b)
{
  if (argc == 3) {
    if (sscanf(argv[1], "%f", a) != 1) {
      printf("First argument must be a floating-point number! Using default value of 5.2\n");
    }
    if (sscanf(argv[2], "%d", b) != 1) {
      printf("Second argument must be an integer! Using default value of 3\n");
    }
  } else {
    char input[256];
    while(1) {
      printf("Starting radius: ");
      fgets(input, 256, stdin);
      if (sscanf(input, "%f", a) == 1) break;
      else printf("\nStarting radius must be a floating-point value!\n");
    }
    while(1) {
      printf("Number of increments: ");
      fgets(input, 256, stdin);
      if (sscanf(input, "%d", b) == 1) break;
      else printf("\nNumber of increments must be an integer!\n");
    }
  }
}

// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main

float areaOfCircle(float radius) {
  float area = M_PI * radius * radius;
  return area;
}

int main(int argc, char* argv[]) 
{
  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
  float start = 5.2;
  int reps = 3;
  
  // for testing only - do not change
  getTestInput(argc, argv, &start, &reps);

  printf("calculating area of circle starting at %f, and ending at %f\n", start, start+reps-1);
  
  // add your code below to call areaOfCircle function with values between
  // start and end

  for (int i = 0; i < reps; i++) {
    float radius = start + i;
    float area = areaOfCircle(radius);
    printf("Area of circle with radius %f = %f\n", radius, area);
  }

}
