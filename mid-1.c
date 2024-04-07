/*A left rotation operation on an array of size  shifts each of the array's elements  unit to the left. Given an integer, , rotate the array that many steps left and return the result.
Example
After  rotations, .
Returns
int[n]: the rotated array
Input Format
The first line contains two space-separated integers that denote , the number of integers, and , the number of left rotations to perform.
The second line contains  space-separated integers that describe .
Constraints
Sample Input
5 4
1 2 3 4 5
Sample Output
5 1 2 3 4
Explanation




# include <stdio.h>
# include <stdlib.h>
int main(void) {
    int n, d;
    scanf("%d %d", &n, &d);
    int * arr = (int *)malloc(n * sizeof(int));
    for(int i=0; i<n; i++)
      scanf("%d", &arr[i]);
    for (int i=0; i<d; i++) {
        int temp = arr[0];
        for (int j=1; j<n; j++)
          arr[j-1] = arr[j];
        arr[n-1] = temp;
    }
    for(int i=0; i<n; i++)
      printf("%d ", arr[i]);
}


*/


#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, d;
    if (scanf("%d %d", &n, &d) != 2) {
        printf("Invalid input\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input\n");
            free(arr);
            return 1;
        }
    }

    d %= n;  // Reduce the number of rotations
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[(i + d) % n]);
    }
    printf("\n");

    free(arr);
    return 0;
}


/*

Observations:

Input Validation: The code checks if the input is valid. If the input is not valid, it prints an error message and returns 1 to indicate an error.

Memory Allocation: The code dynamically allocates memory for the array. If the memory allocation fails, it prints an error message and returns 1 to indicate an error.

Error Handling: The code checks the return value of scanf when reading the array elements. If scanf fails, it prints an error message, frees the allocated memory, and returns 1 to indicate an error.

Efficiency: The code reduces the number of rotations by using the modulus operator. This can significantly improve efficiency when the number of rotations is larger than the size of the array.

Memory Management: The code frees the dynamically allocated memory before the program ends to prevent memory leaks.

Output: The code prints the rotated array after performing the left rotations.


This code rewritten here reduces the number of rotations by using the modulus operator, which can significantly improve efficiency when the number of rotations is larger than the size of the array. It also checks the return values of scanf and malloc to handle invalid inputs and memory allocation failures, respectively. Finally, it frees the dynamically allocated memory before the program ends to prevent memory leaks. This code should be more robust and efficient than the original version.


HOW DOES MODULUS OPERATOR REDUCE THE NUMBER OF ROTATIONS?

When I have an array of n elements and perform n rotations, the array ends up looking exactly the same as it did before any rotations. This is because each element has moved n positions to the left, which, given the circular nature of the array, is equivalent to not moving at all.

So, if I’m asked to perform d rotations, I can instead perform d mod n rotations, where mod is the modulus operator. This is because performing d rotations is equivalent to performing d mod n rotations.

For instance, if n = 5 and d = 14, then d mod n = 14 mod 5 = 4. So, I only need to perform 4 rotations instead of 14.

This approach can significantly reduce the number of rotations when d is much larger than n, which can improve the efficiency of the code. In the code you provided, d %= n; is used to reduce the number of rotations. This line of code calculates d mod n and assigns the result back to d. So, the subsequent code performs d rotations, which is the reduced number of rotations. This is how the modulus operation reduces the number of rotations in the code.

Layman's explanation:

let’s say you’ve got a bunch of friends standing in a line. Now, you ask everyone to take one step to the left. The friend at the front of the line goes all the way to the back. If you keep doing this, eventually everyone will end up back in their original spots. That’s pretty much what happens when you rotate an array n times, where n is the number of friends (or the size of the array).

Now, If you’re asked to do d rotations, you don’t have to do all d of them. You can take a shortcut and just do d mod n rotations.

Why? Because doing d rotations ends up being the same as doing d mod n rotations. It’s like if you have 5 friends and you’re asked to rotate them 14 times, you only need to rotate 4 times (because 14 mod 5 equals 4).

This shortcut can save you a ton of time, especially when d is a lot bigger than n. In thIS code , that’s exactly what d %= n; is doing. It’s figuring out the shortcut. So the rest of the code only does the reduced number of rotations. That’s how using modulus can make the code more efficient. 

*/
