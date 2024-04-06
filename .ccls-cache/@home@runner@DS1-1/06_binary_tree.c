/*

#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node* left;
  struct node* right;
};

// Inorder traversal
void inorderTraversal(struct node* root) {
  if (root == NULL) 
    return;
  inorderTraversal(root->left);
  printf("%d ->", root->item);
  inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node* root) {
  if (root == NULL) 
    return;
  printf("%d ->", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node* root) {
  if (root == NULL) 
    return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->item);
}

// Create a new Node
struct node* createNode(int value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {
  root->left = createNode(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {
  root->right = createNode(value);
  return root->right;
}

int main() {
  struct node* root = createNode(1);
  insertLeft(root, 2);
  insertRight(root, 3);
  insertLeft(root->left, 4);

  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);
}


Output

Inorder traversal 
4 ->2 ->1 ->3 ->
Preorder traversal 
1 ->2 ->4 ->3 ->
Postorder traversal 
4 ->2 ->3 ->1 ->

*/  



#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int item;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertLeft(Node* root, int value) {
    root->left = createNode(value);
    return root->left;
}

Node* insertRight(Node* root, int value) {
    root->right = createNode(value);
    return root->right;
}

void inorderTraversal(Node* root) {
    if (root == NULL) 
        return;
    inorderTraversal(root->left);
    printf("%d -> ", root->item);
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == NULL) 
        return;
    printf("%d -> ", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL) 
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d -> ", root->item);
}

int main() {
    Node* root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);

    printf("Inorder traversal \n");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal \n");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal \n");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

/* Output

Inorder traversal 
4 -> 2 -> 1 -> 3 -> 
Preorder traversal 
1 -> 2 -> 4 -> 3 -> 
Postorder traversal 
4 -> 2 -> 3 -> 1 -> 



The Differences between the two versions of the code:

Struct Definition:
Original Code: The struct node is defined without a typedef. So, every time you declare a new Node, you have to use the struct keyword.

Rewritten Code: The Node is defined with a typedef, which allows you to declare a new Node without the struct keyword.

Memory Allocation:
Original Code: The malloc function is used to allocate memory for a new node.

Rewritten Code: The malloc function is also used to allocate memory for a new node.

Function Definitions:
Both versions of the code define the same functions (createNode, insertLeft, insertRight, inorderTraversal, preorderTraversal, postorderTraversal) with the same functionality.

Main Function:
Both versions of the code create the same binary tree in the main function and perform the same traversals on it.


*/
