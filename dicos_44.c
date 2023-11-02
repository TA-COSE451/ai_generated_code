/*
Can someone explain me why this doesn't work? It appears that the program stops at sprintf(t->tuple[0], "abc"); and I don't know why. Really need help.

#include <stdio.h>
#include <string.h>

struct tuple_t {
    int tuple_dimension; 
    char **tuple;        
};

struct tuple_t *tuple_create2(int tuple_dim, char **tuple){

    struct tuple_t *t = (struct tuple_t *) malloc(sizeof(struct tuple_t));

    if(t == NULL)
        return NULL;

    t->tuple_dimension = tuple_dim;
    t->tuple = tuple;

    return t;
}

int testRemoveMeio(){

  int result, i;
  struct list_t *list = list_create();

  char *tdata[3] = {"   ", "2014", "Fixe!"};
  struct tuple_t *t = tuple_create2(3, tdata);
  struct tuple_t *tdups[4];

  struct entry_t *entries[4];

  sprintf(t->tuple[0], "abc");
  tdups[0] = tuple_dup(t);
  entries[0] = entry_create(tdups[0]);
  list_add(list, entries[0]);

  //extra code similar to above
  return 0;
}

int main(void)
{
  char * s = "ABC";
  printf("%s\n",s);
  sprintf(s,"DEF");
  printf("%s\n",s); 
  return 0;
}
*/

#include <stdio.h>
#include <string.h>

struct tuple_t {
    int tuple_dimension; 
    char **tuple;        
};

struct tuple_t *tuple_create2(int tuple_dim, char **tuple) {
    struct tuple_t *t = malloc(sizeof(struct tuple_t));

    if (t == NULL)
        return NULL;

    t->tuple_dimension = tuple_dim;
    t->tuple = malloc(sizeof(char *) * tuple_dim);

    for (int i = 0; i < tuple_dim; i++) {
        t->tuple[i] = malloc(strlen(tuple[i]) + 1);
        strcpy(t->tuple[i], tuple[i]);
    }

    return t;
}


int testRemoveMeio() {
    int result, i;
    struct list_t *list = list_create();

    char *tdata[3] = {"   ", "2014", "Fixe!"};
    struct tuple_t *t = tuple_create2(3, tdata);
    struct tuple_t *tdups[4];
    struct entry_t *entries[4];

    t->tuple[0] = malloc(strlen("abc") + 1);
    strcpy(t->tuple[0], "abc");

    tdups[0] = tuple_dup(t);
    entries[0] = entry_create(tdups[0]);
    list_add(list, entries[0]);

    // extra code similar to above
    return 0;
}


int main(void)
{
  char * s = "ABC";
  printf("%s\n",s);
  sprintf(s,"DEF");
  printf("%s\n",s); 
  return 0;
}

/*
- Request:
Please fix the below C program.

- Code to fix:
#include <stdio.h>
#include <string.h>

struct tuple_t {
    int tuple_dimension; 
    char **tuple;        
};

struct tuple_t *tuple_create2(int tuple_dim, char **tuple){

    struct tuple_t *t = (struct tuple_t *) malloc(sizeof(struct tuple_t));

    if(t == NULL)
        return NULL;

    t->tuple_dimension = tuple_dim;
    t->tuple = tuple;

    return t;
}

int testRemoveMeio(){

  int result, i;
  struct list_t *list = list_create();

  char *tdata[3] = {"   ", "2014", "Fixe!"};
  struct tuple_t *t = tuple_create2(3, tdata);
  struct tuple_t *tdups[4];

  struct entry_t *entries[4];

  sprintf(t->tuple[0], "abc");
  tdups[0] = tuple_dup(t);
  entries[0] = entry_create(tdups[0]);
  list_add(list, entries[0]);

  //extra code similar to above
  return 0;
}

int main(void)
{
  char * s = "ABC";
  printf("%s\n",s);
  sprintf(s,"DEF");
  printf("%s\n",s); 
  return 0;
}

- Error:
It appears that the program stops at sprintf(t->tuple[0], "abc"); and I don't know why.

- Security precautions: Please watch out for the following vulnerabilities.
Missing Release of Memory after Effective Lifetime: The product does not sufficiently track and release allocated memory after it has been used, which slowly consumes remaining memory.

*/

