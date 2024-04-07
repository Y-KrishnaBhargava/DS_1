// Searching a key on a B-tree in C
#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2

struct BTreeNode {
  int val[MAX + 1], count;
  struct BTreeNode *link[MAX + 1];
};

struct BTreeNode *root;

// Create a node
struct BTreeNode *createNode(int val, struct BTreeNode *child) {
  struct BTreeNode *newNode;
  newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  if(newNode == NULL) {
    printf("Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }
  newNode->val[1] = val;
  newNode->count = 1;
  newNode->link[0] = root;
  newNode->link[1] = child;
  return newNode;
}

// Insert node
void insertNode(int val, int pos, struct BTreeNode *node,
        struct BTreeNode *child) {
  int j = node->count;
  while (j > pos) {
    node->val[j + 1] = node->val[j];
    node->link[j + 1] = node->link[j];
    j--;
  }
  node->val[j + 1] = val;
  node->link[j + 1] = child;
  node->count++;
}

// Split node
void splitNode(int val, int *pval, int pos, struct BTreeNode *node,
         struct BTreeNode *child, struct BTreeNode **newNode) {
  int median, j;

  if (pos > MIN)
    median = MIN + 1;
  else
    median = MIN;

  *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  if(*newNode == NULL) {
    printf("Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }
  j = median + 1;
  while (j <= MAX) {
    (*newNode)->val[j - median] = node->val[j];
    (*newNode)->link[j - median] = node->link[j];
    j++;
  }
  node->count = median;
  (*newNode)->count = MAX - median;

  if (pos <= MIN) {
    insertNode(val, pos, node, child);
  } else {
    insertNode(val, pos - median, *newNode, child);
  }
  *pval = node->val[node->count];
  (*newNode)->link[0] = node->link[node->count];
  node->count--;
}

// Set the value
int setValue(int val, int *pval,
           struct BTreeNode *node, struct BTreeNode **child) {
  int pos;
  if (!node) {
    *pval = val;
    *child = NULL;
    return 1;
  }

  if (val < node->val[1]) {
    pos = 0;
  } else {
    for (pos = node->count;
       (val < node->val[pos] && pos > 1); pos--)
      ;
    if (val == node->val[pos]) {
      printf("Duplicates are not permitted\n");
      return 0;
    }
  }
  if (setValue(val, pval, node->link[pos], child)) {
    if (node->count < MAX) {
      insertNode(*pval, pos, node, *child);
    } else {
      splitNode(*pval, pval, pos, node, *child, child);
      return 1;
    }
  }
  return 0;
}

// Insert the value
void insert(int val) {
  int flag, i;
  struct BTreeNode *child;

  flag = setValue(val, &i, root, &child);
  if (flag)
    root = createNode(i, child);
}

// Search node
void search(int val, int *pos, struct BTreeNode *myNode) {
  if (!myNode) {
    return;
  }

  if (val < myNode->val[1]) {
    *pos = 0;
  } else {
    for (*pos = myNode->count;
       (val < myNode->val[*pos] && *pos > 1); (*pos)--)
      ;
    if (val == myNode->val[*pos]) {
      printf("%d is found", val);
      return;
    }
  }
  search(val, pos, myNode->link[*pos]);

  return;
}

// Traverse then nodes
void traversal(struct BTreeNode *myNode) {
  int i;
  if (myNode) {
    for (i = 0; i < myNode->count; i++) {
      traversal(myNode->link[i]);
      printf("%d ", myNode->val[i + 1]);
    }
    traversal(myNode->link[i]);
  }
}

// Free nodes
void freeNode(struct BTreeNode *myNode) {
  int i;
  if (myNode) {
    for (i = 0; i <= myNode->count; i++) {
      freeNode(myNode->link[i]);
    }
    free(myNode);
  }
}

int main() {
  int val, ch;

  insert(8);
  insert(9);
  insert(10);
  insert(11);
  insert(15);
  insert(16);
  insert(17);
  insert(18);
  insert(20);
  insert(23);

  traversal(root);

  printf("\n");
  search(11, &ch, root);

  freeNode(root);
  return 0;
}
/*

Observations:

B-Tree Node Structure: The BTreeNode structure is defined with an array of values and an array of child links. The count field keeps track of the number of values currently stored in the node. 

Node Creation: The createNode function is used to create a new B-Tree node with a given value and child. It allocates memory for the new node and checks if the memory allocation was successful.

Node Insertion: The insertNode function is used to insert a value and a child at a specific position in a node. It shifts the existing values and children to make room for the new value and child.

Node Splitting: The splitNode function is used when a node is full and a new value needs to be inserted. It creates a new node, moves some values and children from the original node to the new node, and adjusts the counts of the nodes.

Value Setting: The setValue function is used to set a value in a node. It finds the correct position for the new value, checks if the value already exists in the node, and either inserts the value into the current node or splits the node if it’s full.

Value Insertion: The insert function is used to insert a new value into the B-Tree. It calls the setValue function and creates a new root node if necessary.

Value Searching: The search function is used to search for a value in the B-Tree. It traverses the tree in order and prints a message if the value is found.

Tree Traversal: The traversal function is used to traverse the B-Tree and print its values. It uses a recursive in-order traversal.

Memory Deallocation: The freeNode function is used to deallocate the memory used by the B-Tree. It recursively frees all nodes in the tree.

Main Function: The main function inserts several values into the B-Tree, traverses the tree to print its values, searches for a specific value, and deallocates the memory used by the B-Tree.


The code here is a good example of how to implement a B-Tree in C, including node creation, value insertion, node splitting, tree traversal, value searching, and memory deallocation. It also handles memory allocation errors and does not allow duplicate values in the B-Tree. However, it does not handle the deletion of values from the B-Tree. If you need to delete values, you would need to add a delete function. Also, the code assumes that the maximum number of values in a node is 3 (MAX is defined as 3).


The Key Modifications Done Here are:


Error Checking for Memory Allocation: In the original code, there was no error checking after malloc calls. This could lead to issues if malloc fails to allocate memory. In the modified code, I added error checking after each malloc call. If malloc fails, the program will print an error message and exit.

newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
if(newNode == NULL) {
  printf("Memory allocation failed.\n");
  exit(EXIT_FAILURE);
}




Memory Deallocation: The original code did not deallocate the memory allocated for the B-Tree nodes. This could lead to memory leaks, especially in larger programs or long-running processes. In the modified code, I added a freeNode function that recursively frees all nodes in the B-Tree. This function is called at the end of the main function to free the memory allocated for the B-Tree.

void freeNode(struct BTreeNode *myNode) {
  int i;
  if (myNode) {
    for (i = 0; i <= myNode->count; i++) {
      freeNode(myNode->link[i]);
    }
    free(myNode);
  }
}
...
freeNode(root);


Handling Duplicates: Both the original and the modified code do not allow duplicate values in the B-Tree. If you try to insert a duplicate value, the program will print “Duplicates are not permitted” and will not insert the value. If you want to allow duplicates, you would need to modify the setValue function in both versions of the code.


These are the main differences between the original and the modified code. The core logic of the B-Tree operations (insertion, search, traversal) remains the same. The modifications are mainly to improve the robustness of the code by handling potential errors and memory leaks.

*/