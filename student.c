#include <stdio.h>
#include <string.h>

// student structure
struct Student {
  char firstName[20];
  char lastName[20];
  int age;
  int id;
};


void printStudent(struct Student* student) {
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n    id: %d\n", student->age, student->id);
}


void printAllStudents(struct Student students[], int num) {
  // call printStudent for each student in students
  for (int i = 0; i < num; i++) {
    printf("\n----- Student %d -----\n", i);
    printStudent(students+i);
  }
}


int main()
{

  // an array of students
  struct Student students[100];
  int numStudents = 0;
  
  while (1)
  {
    char c;
    char input[256];
    printf("\nEnter a to add, p to print, q to quit: ");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
      struct Student newStudent;

      printf("  First name: ");
      fgets(input, 256, stdin);
      sscanf(input, "%s", &(newStudent.firstName));
      printf("  Last name: ");
      fgets(input, 256, stdin);
      sscanf(input, "%s", &(newStudent.lastName));
      while (1) {
        printf("  Age: ");
        fgets(input, 256, stdin);
        if (sscanf(input, "%d", &(newStudent.age)) == 1) break;
	else printf("Please enter an integer\n");
      }
      while (1) {
        printf("  Student ID: ");
        fgets(input, 256, stdin);
        if (sscanf(input, "%d", &(newStudent.id)) == 1) break;
	else printf("Please enter an integer\n");
      }

      students[numStudents] = newStudent;

      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n\n");
}
