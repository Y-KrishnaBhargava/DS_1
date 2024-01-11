# include <stdio.h>
# include <string.h>
#include <time.h>

int main(void) {
  clock_t start_time, end_time;
  double cpu_time_used;

  start_time = clock();

  char sentence[20];
  int number_of_letters = 0;
  printf("Enter a sentence: ");
  //scanf("%s", sentence);
  fgets(sentence, sizeof(sentence), stdin);
  for (int i=0; i<strlen(sentence); i++)
    if (sentence[i] !=  ' ')
      number_of_letters++;
  printf("\nThe number of letters in the given sentence are : %d\n", number_of_letters);

  end_time = clock();

  cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;


   printf("The execution time of your code is: %f seconds\n", cpu_time_used);

  return 0;
}

/* Obervations:
01. How to work with sentences having a space in between?
Ans: Here we are using scanf("%s", sentence) at 14th line to read the input sentence. The scanf function with %s format specifier reads a string until it encounters a whitespace (space, newline, etc.).

So, it doesn’t read the full sentence if there are spaces in between words.

To read a full line (a sentence with spaces),We can use fgets function. 

I commented the code at 14th line and added the fgets function at 15th line.
This should solve the problem.

Time complexity calculatibg code is also added in the original Code.


Output:
Case - 01
Enter a sentence: Red emperor

The number of letters in the given sentence are : 11
The execution time of your code is: 0.000177 seconds

Case - 02  
Enter a sentence: DEath is Upon us. Save your Soul.

The number of letters in the given sentence are : 15
The execution time of your code is: 0.000153 seconds


this is due to fgets has less buffer space and it stops a period(included).
it is also counting newline '\n' along with 'DEath is Upon us' 

*/  


  

