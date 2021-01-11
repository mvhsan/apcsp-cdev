#include <stdio.h>
#include <string.h>

int main() {
	char alpha1[27];
	char charToAdd = 'a';
	for (int i = 0; i < 26; i++) {
		alpha1[i] = charToAdd;
		charToAdd++;
	}
	alpha1[26] = '\0';
	
	char alpha2[] = "abcdefghijklmnopqrstuvwxyz";
	
	if (strcmp(alpha1, alpha2) == 0)
		printf("alpha1 and alpha2 are the same.\n");
	else
		printf("alpha1 and alpha2 are not the same.\n");

	for (int i = 0; i < 26; i++)
		alpha1[i]-=32;
	if (strcmp(alpha1, alpha2) == 0)
		printf("alpha1 and alpha2 are the same.\n");
	else
		printf("alpha1 and alpha2 are not the same.\n");
	
	char alpha3[53];
	strcpy(alpha3, alpha1);
	strcat(alpha3, alpha2);
	printf("First string: %s\nSecond string: %s\nCombined string: %s\n",
			alpha1, alpha2, alpha3);
}
