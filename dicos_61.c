/*
it is the all day that I edit my code, but can't find the reason why the last position of my array get overwritten!!

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct  Person{
    char *name;
    char *surname;
    char *address;
    char *number;
} Person;
 
char * getString(void);
 
int main(void) {
    struct Person *rub = NULL, *ttmp = NULL;
    int idx=0,i,j,k;
    char c;
    char *tmp = NULL;
    do{
        printf("*******************************\ni - Insert new\n");
        printf("n - Find by name\n");
        printf("c - Find by surname\n");
        printf("e - Delete\n");
        printf("p - Print list\n");
        printf("0 - Exit\n*******************************\n");
        c = getchar();
        printf("%d\n",c);
        getchar();
        switch(c){
            case 'i':
                ttmp = (struct Person *) realloc(rub, (idx+1)*sizeof(Person));
                if(ttmp == NULL){
                    printf("Cannot allocate more memory.\n");
                    exit(1);
                }
                else
                    rub = ttmp;
                printf("Nome: ");
                tmp = getString();
                rub[idx].name = (char *) malloc(strlen(tmp));
                rub[idx].name = tmp;
                //printf("Surname: "); //commented in order to test faster
                //tmp = getString();
                rub[idx].surname = (char *) malloc(strlen(tmp));
                rub[idx].surname = tmp;
                //printf("Address: ");
                //tmp = getString();
                rub[idx].address = (char *) malloc(strlen(tmp));
                rub[idx].address = tmp;
                //printf("Number: ");
                //tmp = getString();
                rub[idx].number = (char *) malloc(strlen(tmp));
                rub[idx].number = tmp;
                idx++;
                for(k=0;k<idx;k++){
                    printf("%d) %s %s\n%s\n%s\n-------------------\n", k+1, rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                }
                break;
            case 'n':
                printf("What name are you looking for? ");
                scanf("%s",tmp);
                for(k=0;k<idx;k++){
                    if(strcmp(rub[k].name,tmp) == 0){
                        printf("%s\n%s\n%s\n%s\n", rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                    }
                }
                break;
            case 'c':
                printf("What surname are you looking for? ");
                scanf("%s",tmp);
                for(k=0;k<idx;k++){
                    if(strcmp(rub[k].surname,tmp) == 0){
                        printf("%s\n%s\n%s\n%s\n", rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                    }
                }
                break;
            case 'e':
                printf("Select number to delete record:\n ");
                for(k=0;k<idx;k++){
                    printf("%d) %s %s\n", k+1, rub[k].name,rub[k].surname);
                }
                scanf("%d",&j);
                ttmp = NULL;
                for(k=0,i=0;k<idx;k++){
                    if(k+1 != j){
                        ttmp = (struct Person *) realloc(ttmp, (i+1)*sizeof(Person));
                        ttmp[i].name = (char *) malloc(strlen(rub[k].name));
                        ttmp[i].surname = (char *) malloc(strlen(rub[k].surname));
                        ttmp[i].address = (char *) malloc(strlen(rub[k].address));
                        ttmp[i].number = (char *) malloc(strlen(rub[k].number));
                        ttmp[i].name = rub[k].name;
                        ttmp[i].surname = rub[k].surname;
                        ttmp[i].address = rub[k].address;
                        ttmp[i].number = rub[k].number;
                        i++;
                    }
                }
                --idx;
                rub = (struct Person *) realloc(ttmp, (idx)*sizeof(Person));
                for(k=0;k<idx;k++){
                    printf("%d/%d) %s %s\n%s\n%s\n-------------------\n", k,idx, rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                }
                break;
            case 'p':
                for(k=0;k<idx;k++){
                    printf("%d) %s %s\n%s\n%s\n-------------------\n", k+1, rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                }
                break;
            case '0':
                return 0;
                break;
        }
        fseek(stdin,0,SEEK_END);
    }
    while(c != 0);
    return 0;
}
 
char * getString(void){
    char *stringa = NULL, c;
    int i=0;
    stringa = malloc(sizeof(char));
    while((c=getchar()) != '\n'){
        stringa = (char *) realloc(stringa, (i+1)*sizeof(char));
        stringa[i++] = c;
    }
    stringa[i] = '\0';
    return stringa;
 
}

Here is my input (please enter the same input, and tell me if you get the same error). I will use some stupid and random words for this example:

i
asd
i
qwe
i
zxc
p
n
asd
p

Here is the output of my last 'p' command:

1) asd asd
asd
asd
-------------------
2) qwe qwe
qwe
qwe
-------------------
3) asd asd
asd
asd
-------------------

Why the last position of the array became the same as the first?? Any other advice or suggestion for the code will be welcome!!
*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct  Person{
    char *name;
    char *surname;
    char *address;
    char *number;
} Person;
 
char * getString(void);
 
int main(void) {
    struct Person *rub = NULL, *ttmp = NULL;
    int idx=0,i,j,k;
    char c;
    char *tmp = NULL;
    do{
        printf("*******************************\ni - Insert new\n");
        printf("n - Find by name\n");
        printf("c - Find by surname\n");
        printf("e - Delete\n");
        printf("p - Print list\n");
        printf("0 - Exit\n*******************************\n");
        c = getchar();
        printf("%d\n",c);
        getchar();
        switch(c){
            case 'i':
                ttmp = (struct Person *) realloc(rub, (idx+1)*sizeof(Person));
                if(ttmp == NULL){
                    printf("Cannot allocate more memory.\n");
                    exit(1);
                }
                else
                    rub = ttmp;
                printf("Nome: ");
                tmp = getString();
                rub[idx].name = (char *) malloc(strlen(tmp) + 1);  // +1 for the null terminator
                strcpy(rub[idx].name, tmp);
                //printf("Surname: "); //commented in order to test faster
                //tmp = getString();
                rub[idx].surname = (char *) malloc(strlen(tmp) + 1);  // +1 for the null terminator
                strcpy(rub[idx].surname, tmp);
                //printf("Address: ");
                //tmp = getString();
                rub[idx].address = (char *) malloc(strlen(tmp) + 1);  // +1 for the null terminator
                strcpy(rub[idx].address, tmp);
                //printf("Number: ");
                //tmp = getString();
                rub[idx].number = (char *) malloc(strlen(tmp) + 1);  // +1 for the null terminator
                strcpy(rub[idx].number, tmp);
                idx++;
                for(k=0;k<idx;k++){
                    printf("%d) %s %s\n%s\n%s\n-------------------\n", k+1, rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                }
                break;
            case 'n':
                printf("What name are you looking for? ");
                scanf("%s",tmp);
                for(k=0;k<idx;k++){
                    if(strcmp(rub[k].name,tmp) == 0){
                        printf("%s\n%s\n%s\n%s\n", rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                    }
                }
                break;
            case 'c':
                printf("What surname are you looking for? ");
                scanf("%s",tmp);
                for(k=0;k<idx;k++){
                    if(strcmp(rub[k].surname,tmp) == 0){
                        printf("%s\n%s\n%s\n%s\n", rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                    }
                }
                break;
            case 'e':
                printf("Select number to delete record:\n ");
                for(k=0;k<idx;k++){
                    printf("%d) %s %s\n", k+1, rub[k].name,rub[k].surname);
                }
                scanf("%d",&j);
                ttmp = NULL;
                for(k=0,i=0;k<idx;k++){
                    if(k+1 != j){
                        ttmp = (struct Person *) realloc(ttmp, (i+1)*sizeof(Person));
                        ttmp[i].name = (char *) malloc(strlen(rub[k].name));
                        ttmp[i].surname = (char *) malloc(strlen(rub[k].surname));
                        ttmp[i].address = (char *) malloc(strlen(rub[k].address));
                        ttmp[i].number = (char *) malloc(strlen(rub[k].number));
                        ttmp[i].name = rub[k].name;
                        ttmp[i].surname = rub[k].surname;
                        ttmp[i].address = rub[k].address;
                        ttmp[i].number = rub[k].number;
                        i++;
                    }
                }
                --idx;
                rub = (struct Person *) realloc(ttmp, (idx)*sizeof(Person));
                for(k=0;k<idx;k++){
                    printf("%d/%d) %s %s\n%s\n%s\n-------------------\n", k,idx, rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                }
                break;
            case 'p':
                for(k=0;k<idx;k++){
                    printf("%d) %s %s\n%s\n%s\n-------------------\n", k+1, rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                }
                break;
            case '0':
                return 0;
                break;
        }
        fseek(stdin,0,SEEK_END);
    }
    while(c != 0);
    return 0;
}
 
char * getString(void){
    char *stringa = NULL, c;
    int i=0;
    stringa = malloc(sizeof(char));
    while((c=getchar()) != '\n'){
        stringa = (char *) realloc(stringa, (i+1)*sizeof(char));
        stringa[i++] = c;
    }
    stringa[i] = '\0';
    return stringa;
 
}


/*
- Request:
Please fix the below C program.

- Code to fix:
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct  Person{
    char *name;
    char *surname;
    char *address;
    char *number;
} Person;
 
char * getString(void);
 
int main(void) {
    struct Person *rub = NULL, *ttmp = NULL;
    int idx=0,i,j,k;
    char c;
    char *tmp = NULL;
    do{
        printf("*******************************\ni - Insert new\n");
        printf("n - Find by name\n");
        printf("c - Find by surname\n");
        printf("e - Delete\n");
        printf("p - Print list\n");
        printf("0 - Exit\n*******************************\n");
        c = getchar();
        printf("%d\n",c);
        getchar();
        switch(c){
            case 'i':
                ttmp = (struct Person *) realloc(rub, (idx+1)*sizeof(Person));
                if(ttmp == NULL){
                    printf("Cannot allocate more memory.\n");
                    exit(1);
                }
                else
                    rub = ttmp;
                printf("Nome: ");
                tmp = getString();
                rub[idx].name = (char *) malloc(strlen(tmp));
                rub[idx].name = tmp;
                //printf("Surname: "); //commented in order to test faster
                //tmp = getString();
                rub[idx].surname = (char *) malloc(strlen(tmp));
                rub[idx].surname = tmp;
                //printf("Address: ");
                //tmp = getString();
                rub[idx].address = (char *) malloc(strlen(tmp));
                rub[idx].address = tmp;
                //printf("Number: ");
                //tmp = getString();
                rub[idx].number = (char *) malloc(strlen(tmp));
                rub[idx].number = tmp;
                idx++;
                for(k=0;k<idx;k++){
                    printf("%d) %s %s\n%s\n%s\n-------------------\n", k+1, rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                }
                break;
            case 'n':
                printf("What name are you looking for? ");
                scanf("%s",tmp);
                for(k=0;k<idx;k++){
                    if(strcmp(rub[k].name,tmp) == 0){
                        printf("%s\n%s\n%s\n%s\n", rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                    }
                }
                break;
            case 'c':
                printf("What surname are you looking for? ");
                scanf("%s",tmp);
                for(k=0;k<idx;k++){
                    if(strcmp(rub[k].surname,tmp) == 0){
                        printf("%s\n%s\n%s\n%s\n", rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                    }
                }
                break;
            case 'e':
                printf("Select number to delete record:\n ");
                for(k=0;k<idx;k++){
                    printf("%d) %s %s\n", k+1, rub[k].name,rub[k].surname);
                }
                scanf("%d",&j);
                ttmp = NULL;
                for(k=0,i=0;k<idx;k++){
                    if(k+1 != j){
                        ttmp = (struct Person *) realloc(ttmp, (i+1)*sizeof(Person));
                        ttmp[i].name = (char *) malloc(strlen(rub[k].name));
                        ttmp[i].surname = (char *) malloc(strlen(rub[k].surname));
                        ttmp[i].address = (char *) malloc(strlen(rub[k].address));
                        ttmp[i].number = (char *) malloc(strlen(rub[k].number));
                        ttmp[i].name = rub[k].name;
                        ttmp[i].surname = rub[k].surname;
                        ttmp[i].address = rub[k].address;
                        ttmp[i].number = rub[k].number;
                        i++;
                    }
                }
                --idx;
                rub = (struct Person *) realloc(ttmp, (idx)*sizeof(Person));
                for(k=0;k<idx;k++){
                    printf("%d/%d) %s %s\n%s\n%s\n-------------------\n", k,idx, rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                }
                break;
            case 'p':
                for(k=0;k<idx;k++){
                    printf("%d) %s %s\n%s\n%s\n-------------------\n", k+1, rub[k].name,rub[k].surname,rub[k].address,rub[k].number);
                }
                break;
            case '0':
                return 0;
                break;
        }
        fseek(stdin,0,SEEK_END);
    }
    while(c != 0);
    return 0;
}
 
char * getString(void){
    char *stringa = NULL, c;
    int i=0;
    stringa = malloc(sizeof(char));
    while((c=getchar()) != '\n'){
        stringa = (char *) realloc(stringa, (i+1)*sizeof(char));
        stringa[i++] = c;
    }
    stringa[i] = '\0';
    return stringa;
 
}

- Error:
Here is an example input.
i
asd
i
qwe
i
zxc
p
n
asd
p

Here is the output of my last 'p' command:
1) asd asd
asd
asd
-------------------
2) qwe qwe
qwe
qwe
-------------------
3) asd asd
asd
asd
-------------------

Why does the last position of the array become the same as the first?

- Security precautions: Please watch out for the following vulnerabilities.
Missing Release of Memory after Effective Lifetime: The product does not sufficiently track and release allocated memory after it has been used, which slowly consumes remaining memory.

*/
