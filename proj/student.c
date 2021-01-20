//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args

  Student* newStudent = (Student *)malloc(sizeof(fname) + sizeof(lname) + sizeof(unsigned int) + sizeof(long int));
  newStudent->firstName = malloc(sizeof(fname));
  //newStudent->firstName = malloc(sizeof(char) * (strlen(fname) + 1));
  strcpy(newStudent->firstName, fname);
  newStudent->lastName = malloc(sizeof(lname));
  //newStudent->firstName = malloc(sizeof(char) * (strlen(lname) + 1));
  strcpy(newStudent->lastName, lname);
  newStudent->age = age;
  newStudent->id = id;

  students[numStudents] = newStudent;
  numStudents++;
}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  
  free(student->firstName);
  free(student->lastName);
  free(student);
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
 
  for (int i = 0; i < numStudents; i++) {
    deleteStudent(students[i]);
    students[i] = 0;
  }
  numStudents = 0;
}


void saveStudents(int* key, int size)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532 

  FILE* fp = fopen(STUFILE, "w");
  
  if (fp) {
    for (int i = 0; i < numStudents; i++) {
      Student* student = students[i];
      
      /*char fname[strlen(student->firstName)];
      strcpy(fname, student->firstName);
      encrypt(fname, &key, 1);

      char lname[strlen(student->lastName)];
      strcpy(lname, student->lastName);
      encrypt(lname, &key, 1);

      char ageStr[32];
      sprintf(ageStr, "%u", student->age);
      encrypt(ageStr, &key, 1);

      char idStr[32];
      sprintf(idStr, "%li", student->id);
      encrypt(idStr, &key, 1);

      fprintf(fp, "%s %s %s %s\n", fname, lname, ageStr, idStr);*/

      char outStr[strlen(student->firstName) + strlen(student->lastName) + (int) log(student->age) + (int) log(student->id) + 3];
      sprintf(outStr, "%s %s %u %li", student->firstName, student->lastName, student->age, student->id);

      //encrypt(outStr, key, (int) (sizeof(key) / sizeof(key[0])));
      encrypt(outStr, key, size);
      fprintf(fp, "%s\n", outStr);

    }
    fclose(fp);
  }
}


void loadStudents(int key[], int size)
{
  // load the students from the data file overwriting all exisiting students in memory

  FILE* fp = fopen(STUFILE, "r");

  if (fp) {

    deleteStudents();

    while(1) {
      //char fname[256]; char lname[256]; char ageStr[256]; char idStr[256];
      char inStr[256];
      //if (fscanf(fp, "%s %s %s %s\n", fname, lname, ageStr, idStr) == 4) {
      if (fscanf(fp, "%s\n", inStr) == 1) {

	/*char firstName[strlen(fname)];
	strcpy(firstName, fname);
	decrypt(firstName, &key, 1);

	char lastName[strlen(lname)];
	strcpy(lastName, lname);
	decrypt(lastName, &key, 1);

	//printf("Initial age string: %s\n", ageStr);
	decrypt(ageStr, &key, 1);
	//printf("Age string: %s\n", ageStr);
	unsigned int age;
	sscanf(ageStr, "%u", &age);
	//printf("Age int: %u\n", age);

	decrypt(idStr, &key, 1);
	long int id;
	sscanf(idStr, "%li", &id);*/

	char fname[256]; char lname[256]; unsigned int age; long int id;

        decrypt(inStr, key, size);

	sscanf(inStr, "%s %s %u %li\n", fname, lname, &age, &id);

	char firstName[strlen(fname)]; strcpy(firstName, fname);
	
	char lastName[strlen(lname)]; strcpy(lastName, lname);

        createStudent(firstName, lastName, age, id);
	printf("Student created: %s %s %u %li\n", firstName, lastName, age, id);
      } else
        break;
    }

    fclose(fp);
  }
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




