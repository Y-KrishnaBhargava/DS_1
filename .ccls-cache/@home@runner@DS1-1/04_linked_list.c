#include <stdio.h>
#include <stdlib.h>

int choice;

struct singly_node {
  int data;
  struct singly_node *next;
};

struct doubly_node {
  int data;
  struct doubly_node *next, *prev;
};

void menu(void) {
  printf("\n1. Singly Linked List \n2. Doubly Linked List \n3. Circular Linked "
         "List \n4. Exit");
  printf("\nChoose an option: ");
  scanf("%d", &choice);
}

void singly_linked_list() {
  printf("\n*** Singly Linked List ***");
  int choice = 1;
  struct singly_node *head = NULL, *new_node, *temp;
  while (choice == 1) {
    new_node = (struct singly_node *)malloc(sizeof(struct singly_node));
    printf("\nEnter node data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (head == NULL)
      head = temp = new_node;
    else {
      temp->next = new_node;
      temp = new_node;
    }
    printf("\nTo insert a new node press 1 else any other integer: ");
    scanf("%d", &choice);
  }

  printf("\nThe elements in the Singly Linked list are...");
  temp = head;
  while (temp != NULL) {
    printf("\n%d", temp->data);
    temp = temp->next;
  }
}

void doubly_linked_list() {
  printf("\n*** Doubly Linked List ***");
  int choice = 1;
  struct doubly_node *head = NULL, *new_node, *temp;
  while (choice == 1) {
    new_node = (struct doubly_node *)malloc(sizeof(struct doubly_node));
    printf("\nEnter node data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL) {
      head = temp = new_node;
    } else {
      temp->next = new_node;
      new_node->prev = temp;
      temp = new_node;
    }
    printf("\nTo insert a new node press 1 else any other integer: ");
    scanf("%d", &choice);
  }

  printf("\nThe elements in the Doubly Linked list are...");
  temp = head;
  while (temp != NULL) {
    printf("\n%d", temp->data);
    temp = temp->next;
  }
}

void circular_linked_list() {
  printf("\n*** Circular Linked List ***");
  int choice = 1;
  struct singly_node *head = NULL, *new_node, *temp;
  while (choice == 1) {
    new_node = (struct singly_node *)malloc(sizeof(struct singly_node));
    printf("\nEnter node data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (head == NULL) {
      head = temp = new_node;
      new_node->next = head;
    } else {
      temp->next = new_node;
      new_node->next = head;
      temp = new_node;
    }
    printf("\nTo insert a new node press 1 else any other integer: ");
    scanf("%d", &choice);
  }

  printf("\nThe elements in the Circular Linked list are...");
  temp = head;
  do {
    printf("\n%d", temp->data);
    temp = temp->next;
  } while (temp != head);
}

int main() {
  while (1) {
    menu();
    switch (choice) {
    case 1:
      singly_linked_list();
      break;
    case 2:
      doubly_linked_list();
      break;
    case 3:
      circular_linked_list();
      break;
    case 4:
      return 0;
    default:
      printf("\nInvalid Option");
    }
  }
}

/*

Observations:


Structures: Two structures are defined at the beginning, singly_node and
doubly_node, to represent nodes in a singly linked list and a doubly linked
list, respectively. Each node contains an integer data and a pointer to the next
node. In the case of doubly_node, there’s an additional pointer to the previous
node.

Menu Function: The menu function displays a menu to the user with four options:
create a singly linked list, create a doubly linked list, create a circular
linked list, or exit the program. The user’s choice is stored in the global
variable choice.

Singly Linked List Function: The singly_linked_list function creates a singly
linked list. It prompts the user to enter node data until the user decides to
stop. It then prints the data of all nodes in the list.

Doubly Linked List Function: The doubly_linked_list function works similarly to
the singly_linked_list function, but it creates a doubly linked list. Each node
has a pointer to the next node and a pointer to the previous node.

Circular Linked List Function: The circular_linked_list function also works
similarly, but it creates a circular linked list. In this type of list, the last
node points back to the first node, forming a circle.

Main Function: The main function is an infinite loop that keeps displaying the
menu and calling the appropriate function based on the user’s choice. The loop
breaks when the user chooses to exit. This program is a simple demonstration of
how different types of linked lists can be implemented in C.


NOTE : The circular linked list is implemented as a singly circular linked list,
not a doubly circular one.

 */