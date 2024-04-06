
# include <stdio.h>
#include<time.h>

int input[10] = {10, 9, 8, 7, 6, 5, 1, 2, 3, 4};
  // Elements are hard coded
void menu() {
  printf("\n1. Insertion Sort \n2. Merge Sort \n3. Quick Sort \n4. Selection Sort  \n5. Shell Sort  \n6. Heap Sort  \n9. Exit");
}

void print_array(){
  printf("\nElements after sorting are ...\n");
  for(int i=0; i<10; i++)
    printf("%d\t", input[i]);
  printf("\n");
}
/* Insertion Sort Algorithm
01. Iterate through all elements in the list.
02. Compare the current element to its predecessor.
03. If the current element is smaller (greater) than its predecessor, compare it to the elements before.  
04. Move the greater (smaller) elements one position up to make space for the swapped element.
*/

void insertion_sort() {
  for (int i=1; i<10; i++) {
    int element = input[i];
    int j = i-1;
    while ( j >= 0 && input[j] > element) {
      input[j+1] = input[j];
      j--;
    }
    input[j+1] = element;
  }
}

void selection_sort() {
  int minimum_value_index;
  for (int i=0; i<9; i++) {
     minimum_value_index = i;
    for (int j = i+1; j<10; j++) {
      if (input[j] < input[minimum_value_index])
          minimum_value_index = j;
    }
    // swap the minimum element with the first element
    int temp = input[minimum_value_index];
    input[minimum_value_index] = input[i];
    input[i] = temp;
    print_array();
  }
}


void merging(int low, int mid, int high) {
   int l1, l2, i;
   int b[10];
   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(input[l1] <= input[l2])
         b[i] = input[l1++];
      else
         b[i] = input[l2++];
   }
   while(l1 <= mid)    
      b[i++] = input[l1++];
   while(l2 <= high)   
      b[i++] = input[l2++];
   for(i = low; i <= high; i++)
      input[i] = b[i];
}

void merge_sort(int low, int high) {
   int mid;
   if(low < high) {
      mid = (low + high) / 2;
      merge_sort(low, mid);
      merge_sort(mid+1, high);
      merging(low, mid, high);
     print_array();
   } else { 
      return;
   }   
}

void quick_sort(int first,int last) {
  int i, j, pivot, temp;
  if(first<last) {
    pivot=first;
    i=first;
    j=last;
   while(i<j) {
      while(input[i]<=input[pivot]&&i<last)
        i++;
      while(input[j]>input[pivot])
        j--;
    if(i<j) {
      temp=input[i];
      input[i]=input[j];
      input[j]=temp;
     }
    }
    temp=input[pivot];
    input[pivot]=input[j];
    input[j]=temp;
    quick_sort(first,j-1);
    print_array();
    quick_sort(j+1,last);
    
  }
}

void shell_sort(int n) {
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = input[i];
      int j;
      for (j = i; j >= interval && input[j - interval] > temp; j -= interval) {
        input[j] = input[j - interval];
      }
      input[j] = temp;
    }
    print_array();
  }
}

void swap(int *a, int *b) {
 int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int n, int i) {
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2; 
if (left < n && input[left] > input[largest])
  largest = left;
if (right < n && input[right] > input[largest])
  largest = right;
if (largest != i) {
 swap(&input[i], &input[largest]);
 heapify(n, largest);
 }
}

void heap_sort(int n) {
 for (int i = n / 2 - 1; i >= 0; i--)
   heapify(n, i);
  for (int i = n - 1; i >= 0; i--) {
     swap(&input[0], &input[i]);
   heapify(i, 0);
  }
}

int main(void) {
  //Time complexity calculation
  clock_t start_time, end_time;
  double cpu_time_used;

  start_time = clock();

  
  int choice=0;
    menu();
    printf("\nSelect the sorting technique: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1: printf("\n**Insertion Sort**");
              insertion_sort();
              break;
      case 2: printf("\n**Merge Sort**");
              merge_sort(0, 9);
              break;
      case 3: printf("\n**Quick Sort**");
              quick_sort(0, 9);
              break;
      case 4: printf("\n**Selection Sort**");
              selection_sort();
              break;
      case 5: printf("\n**Shell Sort**");
              shell_sort(10);
              break;
      case 6: printf("\n**Heap Sort**");
              heap_sort(10);
              break;
      case 9: return 0;
      
      default: printf("Invalid choice");
      
    }
  print_array();


  end_time = clock();

  cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;


   printf("\n\nThe execution time of your code is: %f seconds\n", cpu_time_used);


}




  
  /* Observations and Output

Case 1 - Insertion Sort: If the user enters 1, the program will perform an Insertion Sort on the array. This algorithm iterates through the array and places each element in its correct position in the sorted portion of the array.


OUTPUT:


1. Insertion Sort 
2. Merge Sort 
3. Quick Sort 
4. Selection Sort  
5. Shell Sort  
6. Heap Sort  
9. Exit
Select the sorting technique:1

**Insertion Sort**
Elements after sorting are ...
1   2   3   4   5   6   7   8   9   10


The execution time of your code is: 0.000266 seconds




Case 2 - Merge Sort: If the user enters 2, the program will perform a Merge Sort on the array. This algorithm divides the array into two halves, sorts them separately, and then merges them. This process is recursive.

OUTPUT:


1. Insertion Sort 
2. Merge Sort 
3. Quick Sort 
4. Selection Sort  
5. Shell Sort  
6. Heap Sort  
9. Exit
Select the sorting technique: 2

**Merge Sort**
Elements after sorting are ...
9   10  8   7   6   5   1   2   3   4

Elements after sorting are ...
8   9   10  7   6   5   1   2   3   4

Elements after sorting are ...
8   9   10  6   7   5   1   2   3   4

Elements after sorting are ...
6   7   8   9   10  5   1   2   3   4

Elements after sorting are ...
6   7   8   9   10  1   5   2   3   4

Elements after sorting are ...
6   7   8   9   10  1   2   5   3   4

Elements after sorting are ...
6   7   8   9   10  1   2   5   3   4

Elements after sorting are ...
6   7   8   9   10  1   2   3   4   5

Elements after sorting are ...
1   2   3   4   5   6   7   8   9   10

Elements after sorting are ...
1   2   3   4   5   6   7   8   9   10


The execution time of your code is: 0.000537 seconds




Case 3 - Quick Sort: If the user enters 3, the program will perform a Quick Sort on the array. This algorithm selects a ‘pivot’ element from the array and partitions the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then recursively sorted.

OUTPUT:



1. Insertion Sort 
2. Merge Sort 
3. Quick Sort 
4. Selection Sort  
5. Shell Sort  
6. Heap Sort  
9. Exit
Select the sorting technique: 3

**Quick Sort**
Elements after sorting are ...
1   3   2   4   6   5   7   8   9   10

Elements after sorting are ...
1   2   3   4   6   5   7   8   9   10

Elements after sorting are ...
1   2   3   4   6   5   7   8   9   10

Elements after sorting are ...
1   2   3   4   5   6   7   8   9   10

Elements after sorting are ...
1   2   3   4   5   6   7   8   9   10

Elements after sorting are ...
1   2   3   4   5   6   7   8   9   10

Elements after sorting are ...
1   2   3   4   5   6   7   8   9   10

Elements after sorting are ...
1   2   3   4   5   6   7   8   9   10


The execution time of your code is: 0.000350 seconds



Case 4 - Selection Sort: If the user enters 4, the program will perform a Selection Sort on the array. This algorithm finds the minimum element from the array and swaps it with the element in the first position. Then it finds the second smallest element and swaps it with the element in the second position, and so on.


OUTPUT:


1. Insertion Sort 
2. Merge Sort 
3. Quick Sort 
4. Selection Sort  
5. Shell Sort  
6. Heap Sort  
9. Exit
Select the sorting technique: 4

**Selection Sort**
Elements after sorting are ...
1   9   8   7   6   5   10  2   3   4

Elements after sorting are ...
1   2   8   7   6   5   10  9   3   4

Elements after sorting are ...
1   2   3   7   6   5   10  9   8   4

Elements after sorting are ...
1   2   3   4   6   5   10  9   8   7

Elements after sorting are ...
1   2   3   4   5   6   10  9   8   7

Elements after sorting are ...
1   2   3   4   5   6   10  9   8   7

Elements after sorting are ...
1   2   3   4   5   6   7   9   8   10

Elements after sorting are ...
1   2   3   4   5   6   7   8   9   10

Elements after sorting are ...
1   2   3   4   5   6   7   8   9   10

Elements after sorting are ...
1   2   3   4   5   6   7   8   9   10


The execution time of your code is: 0.000428 seconds


Case 5 - Shell Sort: If the user enters 5, the program will perform a Shell Sort on the array. This algorithm is a generalized version of insertion sort. It first sorts elements far apart from each other and successively reduces the interval between the elements to be compared and sorted.

OUTPUT:


1. Insertion Sort 
2. Merge Sort 
3. Quick Sort 
4. Selection Sort  
5. Shell Sort  
6. Heap Sort  
9. Exit
Select the sorting technique: 5

**Shell Sort**
Elements after sorting are ...
5   1   2   3   4   10  9   8   7   6

Elements after sorting are ...
2   1   4   3   5   6   7   8   9   10

Elements after sorting are ...
1   2   3   4   5   6   7   8   9   10

Elements after sorting are ...
1   2   3   4   5   6   7   8   9   10


The execution time of your code is: 0.000431 seconds


Case 6 - Heap Sort: If the user enters 6, the program will perform a Heap Sort on the array. This algorithm builds a max heap (a complete binary tree where each parent node is greater than or equal to its child node) from the input data. Then it swaps the root node (maximum element) with the last element of the heap followed by reducing the heap size by one. This process is repeated until all the nodes of the heap are gone through.


OUTPUT:


1. Insertion Sort 
2. Merge Sort 
3. Quick Sort 
4. Selection Sort  
5. Shell Sort  
6. Heap Sort  
9. Exit
Select the sorting technique: 6

**Heap Sort**
Elements after sorting are ...
1   2   3   4   5   6   7   8   9   10


The execution time of your code is: 0.000324 seconds



Case 9 - Exit: If the user enters 9, the program will terminate.

Default - Invalid choice: If the user enters a number that doesn’t correspond to any of the cases, the program will print “Invalid choice”.

OUTPUT:


1. Insertion Sort 
2. Merge Sort 
3. Quick Sort 
4. Selection Sort  
5. Shell Sort  
6. Heap Sort  
9. Exit
Select the sorting technique: 9

After the sorting operation is performed (or if an invalid choice is made), the print_array function is called to print the current state of the array. 

This allows us to see the result of the sorting operation.

OUTPUT  :


1. Insertion Sort 
2. Merge Sort 
3. Quick Sort 
4. Selection Sort  
5. Shell Sort  
6. Heap Sort  
9. Exit
Select the sorting technique: 7
Invalid choice
**Insertion Sort**
Elements after sorting are ...
1   2   3   4   5   6   7   8   9   10


The execution time of your code is: 0.000360 seconds


NOTE: The Case number is kept '9' as it is. This is done to avoid any confusion since its value does not have any negative impact on the desired output of the program.

Time Complexity calculation Code is added to the 'main'


*/
