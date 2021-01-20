//
// encrypt.c
//

#include <string.h>

#include "encrypt.h"


char CHARS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int CHARS_LEN = 62;


char shiftChar(char c, int shift, int direction)
{
  // implement the character shift here:
  //  given a char c shift it either forwards (direction == 1) or backwards (direction == 0)
  //  use the CHARS array above
  //  return the newly shifted char
  //
  // eg.
  //   shiftChar('c', 3, 1) : 'f'
  //   shiftChar('S', 2, 0) : 'P'
  //   shiftChar('b', 3, 0) : '8'

  char ret;

  if ( ('0' <= c && '9' >= c) || ('A' <= c && 'Z' >= c) || ('a' <= c && 'z' >= c) ) {
  
    int index = c;

    if (index >= CHARS[0])
      index = index - CHARS[0];
    else if (index >= CHARS[26])
      index = index - CHARS[26] + 26;
    else
      index = index - CHARS[52] + 52;

    if (direction == 1)
      index+=shift;
    else
      index-=shift;

    index = (index % CHARS_LEN);
    if (index < 0) 
      index+=CHARS_LEN;
  
    ret = CHARS[index];
  } else {

    int index;

    if (direction == 1)
      index = c + shift;
    else
      index = c - shift;

    index = (index % 128);
    if (index < 0)
      index+=128;

    ret = index;
  }
  
  return ret;
}


void encrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 1);
  }
}


void decrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 0);
  }
}


void caesarEncrypt(char str[], int shift)
{
  int shifts[] = { shift };
  encrypt(str, shifts, 1);
}


void caesarDecrypt(char str[], int shift)
{
  int shifts[] = { shift };
  decrypt(str, shifts, 1);
}


