/*
I was trying to implement Viterbi decoder in C.
So I thought of using a 2-dimensional array which i wanted to create dynamically. Here is the sample code for 2D array created dynamically:


place_table = (int **)malloc((no_places+1)*sizeof(int *));

for(i = 1; i <= no_places; i++)
    place_table[i] = (int *)malloc((no_places+1)*sizeof(int));


The size of this 2-dimensional array keeps on varying in my decoder, i.e., no_places keeps on varying, so I wanted to know how to reallocate memory for the 2-dimensional array.
Any suggestion or help would be greatly appreciated.
*/

// Declare your initial 2D array pointer
int **place_table = NULL;

// Function to allocate memory for the 2D array
void allocateMemory(int no_places) {
    // Allocate memory for the new array
    int **new_place_table = (int **)malloc((no_places + 1) * sizeof(int *));
    
    for (int i = 1; i <= no_places; i++) {
        new_place_table[i] = (int *)malloc((no_places + 1) * sizeof(int));
    }

    // Copy data from the old array to the new array
    for (int i = 1; i <= no_places; i++) {
        for (int j = 1; j <= no_places; j++) {
            new_place_table[i][j] = place_table[i][j];
        }
    }

    // Deallocate memory for the old array
    for (int i = 1; i <= no_places; i++) {
        free(place_table[i]);
    }
    free(place_table);

    // Update the pointer to the new array
    place_table = new_place_table;
}

// Function to deallocate memory for the 2D array
void deallocateMemory(int no_places) {
    for (int i = 1; i <= no_places; i++) {
        free(place_table[i]);
    }
    free(place_table);
    place_table = NULL; // Set the pointer to NULL to indicate no memory is allocated
}
