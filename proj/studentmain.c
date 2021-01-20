#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "student.h"


const int BUFFSIZE=256;
char inputBuff[256];


int getInputNumber()
{
  int num;
  while (1)
  {
    fgets(inputBuff, BUFFSIZE, stdin);
    if (sscanf(inputBuff, "%ud", &num) == 1 && num >= 0) break;
                
    printf("Not a valid number - try again!\n");
  }
  return num;
}


int main()
{
  char fname[BUFFSIZE];
  char lname[BUFFSIZE];

  // key to encrypt/decrypt
  int* key = (int *)malloc(sizeof(int));
  key[0] = 0;
  int size = 1;

  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, l to load, s to save, e to Caesar encrypt, v to Vigenere encrypt, q to quit: ");
    fgets(inputBuff, BUFFSIZE, stdin);
    if (sscanf(inputBuff, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      printStudents();
      continue;
    }
    else if (c == 'l')
    {
      loadStudents(key, size);
      continue;
    }
    else if (c == 's')
    {
      saveStudents(key, size);
      continue;
    }
    else if (c == 'e')
    {
      printf("\nEnter a Caesar encrypt/decrypt key: ");
      fgets(inputBuff, BUFFSIZE, stdin);
      int x;
      if (sscanf(inputBuff, "%d", &x) == 1) {
        key = (int *)realloc(key, sizeof(int));
        key[0] = x;
	size = 1;
      }
      else
        printf("enter a positive shift key\n");
    }
    else if (c == 'v')
    {
      printf("\nEnter a Vigenere encrypt/decrypt keyword: ");
      fgets(inputBuff, BUFFSIZE, stdin);
      char x[256];
      if (sscanf(inputBuff, "%[^\n]", x) == 1) {
	key = (int *)realloc(key, sizeof(int) * strlen(x));
        for (int i = 0; i < strlen(x); i++) {
          key[i] = (int) x[i];
	}
	size = strlen(x);
      }
    }
    else if (c == 'a')
    {
      // enter a new student      
      printf("\n First name: ");
      fgets(inputBuff, BUFFSIZE, stdin);
      sscanf(inputBuff, "%s", fname);

      printf(" Last name: ");
      fgets(inputBuff, BUFFSIZE, stdin);
      sscanf(inputBuff, "%s", lname);
          
      printf(" Enter age: ");
      int age = getInputNumber();

      printf(" Enter id: ");
      int id = getInputNumber();

      createStudent(fname, lname, age, id);
    }
  }
  
  printf("\nGoodbye!\n");
}
