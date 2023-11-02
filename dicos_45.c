/*
#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
} 

int main(){
    int i, size;

    struct Album* pAlbum;
    printf("Enter the number of album: ");
    scanf_s("%d", &size);

    pAlbum = malloc(sizeof(pAlbum) * size);

    for(i=0; i<size; i++) {
        printf("Enter the album title: ");
        scanf_s("%p", pAlbum[i].title);
    }

    free(pAlbum);
    return 0;
}

I want to let the user enter the title for as many albums as they want. The error is that scanf only comes up once for pAlbump[i].tittle for the loop. I'm i allocating the memory incorrectly?
*/

#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
}; // <-- Missing semicolon here

int main(){
    int i, size;

    struct Album* pAlbum;
    printf("Enter the number of albums: ");
    scanf_s("%d", &size);

    pAlbum = malloc(sizeof(struct Album) * size);

    for (i = 0; i < size; i++) {
        printf("Enter the album title: ");
        char buffer[100];
        scanf_s("%s", buffer, sizeof(buffer));
        pAlbum[i].title = malloc(strlen(buffer) + 1); // Allocate memory for title
        strcpy(pAlbum[i].title, buffer); // Copy title to allocated memory
    }

    // Print the album titles
    for (i = 0; i < size; i++) {
        printf("Album %d title: %s\n", i+1, pAlbum[i].title);
    }

    // Free memory for album titles
    for (i = 0; i < size; i++) {
        free(pAlbum[i].title);
    }
    free(pAlbum);

    return 0;
}

/*
- Request:
Please fix the below C code to obtain user input as album titles.

- Code to fix:
#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
} 

int main(){
    int i, size;

    struct Album* pAlbum;
    printf("Enter the number of album: ");
    scanf_s("%d", &size);

    pAlbum = malloc(sizeof(pAlbum) * size);

    for(i=0; i<size; i++) {
        printf("Enter the album title: ");
        scanf_s("%p", pAlbum[i].title);
    }

    free(pAlbum);
    return 0;
}

- Error:
I want to let the user enter the title for as many albums as they want. The error is that scanf only comes up once for pAlbump[i].title for the loop.

- Security precautions: Please watch out for the following vulnerabilities.
Buffer Copy without Checking Size of Input ('Classic Buffer Overflow'): The product copies an input buffer to an output buffer without verifying that the size of the input buffer is less than the size of the output buffer, leading to a buffer overflow.

*/
