/*
I'm trying to have the program check, that, if a user inputs nothing the print statement will say it cant find the file name, but the issue I'm having is that the command line will just go to a new line after hitting enter instead of saying the print statement. This is the code here. I was told that Null is the place holder for if nothing is put in so I thought it would work.

int main()
{
  FILE *fin;
  FILE *fout;
  char fInName[50];
  char fOutName[50];
  printf("pleas type input file, and output file please type legibly\n ");

  scanf("%s %s", &fInName, &fOutName);
  fin = fopen(fInName, "r");
  fout = fopen(fOutName, "r");

  if (fInName == NULL && fOutName == NULL)
  {
    printf("Error: Cannot open input file %s.", fInName);
  }
  else if (fInName != NULL && fOutName == NULL)
  {
    printf("file found");
  }
}

What im trying to test is if a first file name is entered and the second isnt then print the statement. If both arent entered then print file does not exist. there is more to the code to see if the file exists or not, but thst would be a bit much, now Im just trying to understand why it wont read unentered data. Ive tried looking at examples such as: How to detect empty string from fgets and tried to alter the code to fit that type of style but it didnt work for me so Im giving you the code it was originally so that anything helpful wouldnt confuse me more.
*/

#include <stdio.h>
#include <string.h>

int main() {
  FILE *fin;
  FILE *fout;
  char fInName[50];
  char fOutName[50];

  printf("Please type the input file name and the output file name (please type legibly):\n");
  scanf("%49s %49s", fInName, fOutName);

  if (strlen(fInName) == 0 && strlen(fOutName) == 0) {
    printf("Error: No file names entered.\n");
  } else if (strlen(fInName) != 0 && strlen(fOutName) == 0) {
    printf("Error: Only input file name entered.\n");
  } else if (strlen(fInName) == 0 && strlen(fOutName) != 0) {
    printf("Error: Only output file name entered.\n");
  } else {
    printf("Both file names entered.\n");
  }

  return 0;
}

/*
- Request:
I'm trying to have the below C program check, that, if a user inputs nothing the print statement will say it cant find the file name.
What im trying to test is if a first file name is entered and the second isnt then print the statement. If both arent entered then print file does not exist.

- Code to fix:
int main()
{
  FILE *fin;
  FILE *fout;
  char fInName[50];
  char fOutName[50];
  printf("pleas type input file, and output file please type legibly\n ");

  scanf("%s %s", &fInName, &fOutName);
  fin = fopen(fInName, "r");
  fout = fopen(fOutName, "r");

  if (fInName == NULL && fOutName == NULL)
  {
      printf("Error: Cannot open input file %s.", fInName);
  }
  else if (fInName != NULL && fOutName == NULL)
  {
      printf("file found");
  }
}

- Error:
The issue I'm having is that the command line will just go to a new line after hitting enter instead of saying the print statement.

- Security precautions: Please watch out for the following vulnerabilities.
NULL Pointer Dereference: A NULL pointer dereference occurs when the application dereferences a pointer that it expects to be valid, but is NULL, typically causing a crash or exit.

*/