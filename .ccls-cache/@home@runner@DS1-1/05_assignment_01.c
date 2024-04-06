#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int main(void) {
    int *a = malloc((SIZE+1) * sizeof(int));
    if(a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int arr[SIZE] = {1,2,3,5,6,7,8,9};
    for (int i=0; i<SIZE; i++) {
        a[i] = arr[i];
        printf("%d \t",a[i]);
    }

    a[SIZE] = 25;
    printf("\nafter inserting...\n");
    for (int i=0; i<SIZE+1; i++) {
        printf("%d \t",a[i]);
    }
    printf("\n");

    free(a);
    return 0;
}

/*

Observations :

The code uses dynamic memory allocation to create an array of integers. This is done using the malloc() function, which allocates a block of memory of the specified size and returns a pointer to the beginning of this block.

The size of the memory block is calculated as (SIZE+1) * sizeof(int). This is because the code plans to add an additional element to the array later on.

The code checks if the memory allocation was successful by checking if the returned pointer is NULL. If malloc() fails, it returns NULL and the code prints an error message and returns 1 from main(), indicating an error.

The code then fills the dynamically allocated array with values from a static array and prints these values.

The code adds an additional value to the end of the dynamically allocated array. This would not be possible with a statically allocated array of size SIZE, demonstrating the flexibility of dynamic memory allocation.

The code then prints the values of the dynamically allocated array after the insertion, showing that the additional value has been successfully added.

Finally, the code frees the dynamically allocated memory using free(). This is important to prevent memory leaks. When you’re done with a block of dynamically allocated memory, you should always free it.

NOTE : Dynamic memory allocation gives us flexibility, but it also comes with the responsibility of managing the memory ourself.

*/