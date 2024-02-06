/*# include <stdio.h>
# define SIZE 5


int array_data[SIZE];
int top_of_stack, front, rear;

void menu(void) {
  printf("\n1. Stack using Array");
  printf("\n2. Queue using Array");
  printf("\n3. Stack using Linked List");
  printf("\n4. Queue using Linked List");
  printf("\n5. Exit from the program");
  printf("\n\n Provide an option: ");
}

void push(void) {
  if (top_of_stack == SIZE) 
    printf("\nStack Overflow");
  else {
    printf("\nEnter the element to be pushed to the stack: ");
    scanf("%d", &array_data[top_of_stack++]);
  }
}

void pop(void) {
  if (top_of_stack == 0) 
    printf("\nStack underflow");
  else {
    printf("\nPopped element is: %d", array_data[--top_of_stack]);
  }
}

void display_stack(void) {
  if (top_of_stack == 0) 
    printf("\nNo elements in the stack\n");
  else 
   for (int i=0; i<top_of_stack; i++) 
     printf("%d \t", array_data[i] );
}


void enqueue(void) {
  if (rear == SIZE) 
    printf("\nQueue Full");
  else {
    printf("\nEnter the element to be inserted to the queue: ");
    scanf("%d", &array_data[rear++]);
  }
}

void dequeue(void) {
  if (front == rear) 
    printf("\nQueue Empty");
  else {
    printf("\nDeleted element is: %d", array_data[front++]);
  }
}

void display_queue(void) {
  if (front == rear) 
    printf("\nQueue Empty\n");
  else 
   for (int i=front; i<rear; i++) 
     printf("%d \t", array_data[i] );
}
void array_stack() {
  top_of_stack = 0;
  int choice;
  printf("\n***Creation of Stack using Array***");
  while(1) {
    printf("\n 1. Push \t 2. Pop \t 3. Display \t 4. Return to previous menu \n Choose an option: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1: push();
            break;
      case 2: pop();
            break;
      case 3: display_stack();
            break;
      case 4: return;
      default: printf("\nInvalid choice");
    }
  }  
}

void array_queue() {
  printf("\n***Creation of Queue using Array***");
  front =0;
  rear = 0;
  int choice;
  while(1) {
    printf("\n 1. Enqueue \t 2. Dequeue \t 3. Display \t 4. Return to previous menu \n Choose an option: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1: enqueue();
            break;
      case 2: dequeue();
            break;
      case 3: display_queue();
            break;
      case 4: return;
      default: printf("\nInvalid choice");
    }
  }
}
void linked_list_stack() {
  printf("\n***Creation of Stack using Linked List***");
}

void linked_list_queue() {
  printf("\n***Creation of Queue using Linked List***");
}

int main(void) {
  int choice;
  while (1){
    menu();
    scanf("%d", &choice);
    switch (choice){
      case 1: array_stack();
              break;
      case 2: array_queue();
              break;
      case 3: linked_list_stack();
              break;
      case 4: linked_list_queue();
              break;
      case 5: return 0;
      default: printf("Invalid Option.  Try again.");
    }
    
  }
} */


#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int array_data[SIZE];
int top_of_stack, front, rear;

Node* stack_top = NULL;
Node* queue_front = NULL;
Node* queue_rear = NULL;

void push(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = stack_top;
    stack_top = temp;
}

int pop() {
    Node* temp = stack_top;
    if (temp == NULL) {
        printf("\nStack underflow");
        return -1;
    }
    stack_top = stack_top->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

void enqueue(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (queue_front == NULL && queue_rear == NULL) {
        queue_front = queue_rear = temp;
        return;
    }
    queue_rear->next = temp;
    queue_rear = temp;
}

int dequeue() {
    Node* temp = queue_front;
    if (temp == NULL) {
        printf("\nQueue Empty");
        return -1;
    }
    if (queue_front == queue_rear) {
        queue_front = queue_rear = NULL;
    } else {
        queue_front = queue_front->next;
    }
    int dequeued = temp->data;
    free(temp);
    return dequeued;
}

void menu(void) {
    printf("\n1. Stack using Array");
    printf("\n2. Queue using Array");
    printf("\n3. Stack using Linked List");
    printf("\n4. Queue using Linked List");
    printf("\n5. Exit from the program");
    printf("\n\n Provide an option: ");
}

void push_array(void) {
    if (top_of_stack == SIZE) 
        printf("\nStack Overflow");
    else {
        printf("\nEnter the element to be pushed to the stack: ");
        scanf("%d", &array_data[top_of_stack++]);
    }
}

void pop_array(void) {
    if (top_of_stack == 0) 
        printf("\nStack underflow");
    else {
        printf("\nPopped element is: %d", array_data[--top_of_stack]);
    }
}

void display_stack_array(void) {
    if (top_of_stack == 0) 
        printf("\nNo elements in the stack\n");
    else 
        for (int i=0; i<top_of_stack; i++) 
            printf("%d \t", array_data[i] );
}

void enqueue_array(void) {
    if (rear == SIZE) 
        printf("\nQueue Full");
    else {
        printf("\nEnter the element to be inserted to the queue: ");
        scanf("%d", &array_data[rear++]);
    }
}

void dequeue_array(void) {
    if (front == rear) 
        printf("\nQueue Empty");
    else {
        printf("\nDeleted element is: %d", array_data[front++]);
    }
}

void display_queue_array(void) {
    if (front == rear) 
        printf("\nQueue Empty\n");
    else 
        for (int i=front; i<rear; i++) 
            printf("%d \t", array_data[i] );
}

void array_stack() {
    top_of_stack = 0;
    int choice;
    printf("\n***Creation of Stack using Array***");
    while(1) {
        printf("\n 1. Push \t 2. Pop \t 3. Display \t 4. Return to previous menu \n Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push_array();
                    break;
            case 2: pop_array();
                    break;
            case 3: display_stack_array();
                    break;
            case 4: return;
            default: printf("\nInvalid choice");
        }
    }  
}

void array_queue() {
    printf("\n***Creation of Queue using Array***");
    front =0;
    rear = 0;
    int choice;
    while(1) {
        printf("\n 1. Enqueue \t 2. Dequeue \t 3. Display \t 4. Return to previous menu \n Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue_array();
                    break;
            case 2: dequeue_array();
                    break;
            case 3: display_queue_array();
                    break;
            case 4: return;
            default: printf("\nInvalid choice");
        }
    }
}

void linked_list_stack() {
    printf("\n***Creation of Stack using Linked List***");
    int choice;
    while(1) {
        printf("\n 1. Push \t 2. Pop \t 3. Return to previous menu \n Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("\nEnter the element to be pushed to the stack: ");
                int data;
                scanf("%d", &data);
                push(data);
                break;
            case 2: 
                int popped = pop();
                if (popped != -1) {
                    printf("\nPopped element is: %d", popped);
                }
                break;
            case 3: return;
            default: printf("\nInvalid choice");
        }
    }  
}

void linked_list_queue() {
    printf("\n***Creation of Queue using Linked List***");
    int choice;
    while(1) {
        printf("\n 1. Enqueue \t 2. Dequeue \t 3. Return to previous menu \n Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("\nEnter the element to be inserted to the queue: ");
                int data;
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2: 
                int dequeued = dequeue();
                if (dequeued != -1) {
                    printf("\nDeleted element is: %d", dequeued);
                }
                break;
            case 3: return;
            default: printf("\nInvalid choice");
        }
    }
}

int main(void) {
    int choice;
    while (1){
        menu();
        scanf("%d", &choice);
        switch (choice){
            case 1: array_stack();
                    break;
            case 2: array_queue();
                    break;
            case 3: linked_list_stack();
                    break;
            case 4: linked_list_queue();
                    break;
            case 5: return 0;
            default: printf("Invalid Option.  Try again.");
        }
    }
}



/* 

Completed the given incomplete code and commented it out.

Some notable Observations :

Code shows how these can be implemented using both arrays and linked lists.
  
Understanding Functionality: The code demonstrates how stacks and queues work, including the basic operations like push (for stack), enqueue (for queue), pop (for stack), and dequeue (for queue).

Grasping Control Flow: The use of a menu-driven program helps understand control flow in a program. It uses a while loop and switch statement to continuously accept user input and perform actions based on that input.
  
Memory Management: The code provides an introduction to dynamic memory allocation in C, as seen with the malloc function in the linked list implementation.
  
Error Handling: The code includes basic error handling, for example, checking for stack overflow and underflow conditions.
  
Code Modularity: The code is modular, with separate functions for each operation. This is a good coding practice as it improves readability and maintainability of the code.

*/