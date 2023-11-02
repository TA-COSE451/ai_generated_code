/*
I am trying to open using sys call and read in tokens from the file. I need to create a linked list of tokens. I am getting tokens but once I tried my little implementation of trying to create nodes. I am getting a Segmentation fault: 11 What am I doing wrong here ?

I have been on with this for a long time and I can not seem to get this down. Any help will be helpful. Thank you

I want to know if my implementation is even correct for reading in tokens from the file and making a linked list?

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1000

struct node {
    char data;
    struct node *next;
};

int main(int argc, char const *argv[])
{
    // char str[100] = "Hello, my, name, is, Amir";
    const char s[2] = ",";
    char *token;


    // printf("\nREAD FROM STRING.\n");
    // //get the first token
    // token = strtok(str, s);
    // printf("First token: %s\n", token);

    // while(token != NULL)
    // {
    //  printf("%s\n", token);

    //  token = strtok(NULL, s);
    // }
    printf("file name: %s\n",argv[1]);
    int fd, flag;
    char *buffer[BUFSIZE];

    char *print_tokens;
    int token_idx;

    char read_char;

    struct node *p, *q, *head;
    int i, n, item;

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        return -1;
    }

    // create the first node 
    q = (struct node *)malloc(sizeof(struct node));
    q->data = item;
    q->next = NULL; 

    printf("\nREAD FROM FILE.\n");

    while((flag = read(fd, &read_char, 1))> 0)
    {

        token = strtok(&read_char, s);  

        // create a node and point the value to the node
        q = (struct node *)malloc(sizeof(struct node));
        q->data = token;
        q->next = NULL;


        p->next = q;
        p = p->next;
        // while(token != NULL)
        // {
        //  printf("%s\n", token);

        //  token = strtok(NULL, s);

        // }

    }

    p = head;
    while(!p)
    {
        printf("%s\n", p->data);
        p = p->next;
    }

    return 0;
}

//comparator function for strings
int compare(char *str1, char *str2) {
    while (*str1 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1000

struct node {
    char *data;
    struct node *next;
};

int main(int argc, char const *argv[]) {
    const char s[2] = ",";
    char buffer[BUFSIZE];

    struct node *p, *q, *head = NULL; // Initialize head to NULL

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read into buffer
    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, BUFSIZE)) > 0) {
        buffer[bytesRead] = '\0'; // Null-terminate the buffer
        char *token = strtok(buffer, s);
        while (token != NULL) {
            q = (struct node *)malloc(sizeof(struct node));
            q->data = strdup(token); // Store a copy of the token
            q->next = NULL;

            if (head == NULL) {
                head = q;
                p = head;
            } else {
                p->next = q;
                p = p->next;
            }

            token = strtok(NULL, s);
        }
    }

    close(fd);

    // Print the linked list
    p = head;
    while (p != NULL) {
        printf("%s\n", p->data);
        p = p->next;
    }

    // Free allocated memory
    p = head;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q->data); // Free the strdup'd string
        free(q);       // Free the node
    }

    return 0;
}
