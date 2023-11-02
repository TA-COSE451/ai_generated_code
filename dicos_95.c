/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROZ 100
char *deleteLastChar(char* s)
{
    int rozmiar,i;
    char *tab1;

    rozmiar=strlen(s);
    tab1=(char*)malloc((rozmiar-1)*sizeof(int));
    for(i=0;i<(rozmiar-1); i++)
    {
        tab1[i]=s[i];
    }
    return tab1;
    free(s);
}

main()
{
    char tab1[ROZ], *tab2;
    int l,i,p,a;

    printf("podaj napis\n");

    fgets(tab1, 100, stdin);

    l=strlen(tab1);     
    tab2=malloc(l*sizeof(int));
    if (tab2==NULL)
        printf("blad");
    for(i=0;i<l;i++)
    {
        tab2 = deleteLastChar(tab2);
        p = strlen(tab2);
        for(a=0;a<p;a++)
        {
            printf("%c",tab2[a]);
        }
    }
}


Hi I'm trying to make a program which is deleting the last char from string over and over again until there is no more chars in it. It has to be done on dynamic arrays by shortening new arrray and rewrite previous array into it. Program is compiling without any errors, although it doesn't work as it suppouse to do. After putting an input it is outputting "e" multiple times.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROZ 100

char *deleteLastChar(char *s) {
    int rozmiar, i;
    char *tab1;

    rozmiar = strlen(s);
    tab1 = (char *)malloc((rozmiar - 1) * sizeof(char));

    if (tab1 == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (i = 0; i < (rozmiar - 1); i++) {
        tab1[i] = s[i];
    }

    return tab1;
}

int main() {
    char tab1[ROZ], *tab2;
    int l, i, p, a;

    printf("Podaj napis\n");
    fgets(tab1, 100, stdin);

    l = strlen(tab1);

    // Allocate memory for tab2
    tab2 = (char *)malloc(l * sizeof(char));
    
    if (tab2 == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    strcpy(tab2, tab1);  // Copy the input string to tab2

    for (i = 0; i < l; i++) {
        p = strlen(tab2);
        
        for (a = 0; a < p; a++) {
            printf("%c", tab2[a]);
        }
        
        tab2 = deleteLastChar(tab2);  // Update tab2 by removing the last character
    }

    // Free the memory allocated for tab2
    free(tab2);

    return 0;
}
