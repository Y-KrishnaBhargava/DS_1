#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data; //node will store an integer
    struct node *right_child; // right child
    struct node *left_child; // left child
};

struct node* search(struct node *root, int x) {
    if(root==NULL || root->data==x) //if root->data is x then the element is found
        return root;
    else if(x>root->data) // x is greater, so we will search the right subtree
        return search(root->right_child, x);
    else //x is smaller than the data, so we will search the left subtree
        return search(root->left_child,x);
}

//function to find the minimum value in a node
struct node* find_minimum(struct node *root) {
    if(root == NULL)
        return NULL;
    else if(root->left_child != NULL) // node with minimum value will have no left child
        return find_minimum(root->left_child); // left most element will be minimum
    return root;
}

//function to create a node
struct node* new_node(int x) {
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

struct node* insert(struct node *root, int x) {
    //searching for the place to insert
    if(root==NULL)
        return new_node(x);
    else if(x>root->data) // x is greater. Should be inserted to right
        root->right_child = insert(root->right_child, x);
    else // x is smaller should be inserted to left
        root->left_child = insert(root->left_child,x);
    return root;
}
// funnction to delete a node
struct node* delete(struct node *root, int x) {
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = delete(root->right_child, x);
    else if(x<root->data)
        root->left_child = delete(root->left_child, x);
    else
    {
        //No Children
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root) {
    if(root!=NULL) // checking if the root is not null
    {
        inorder(root->left_child); // visiting left child
        printf(" %d ", root->data); // printing data at root
        inorder(root->right_child);// visiting right child
    }
}

int main() {

  clock_t start_time, end_time;
  double cpu_time_used;

  start_time = clock();
  
    /*
                   20
                 /    \
                /      \
               5       30
             /   \     /\
            /     \   /  \
           1      15 25  40
                /          \
               /            \
              9             45
            /   \          /
           /     \        /
          7      12      42
    */
    struct node *root;
    root = new_node(20);
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root, 45);
    insert(root, 42);

    inorder(root);
    printf("\n");

    root = delete(root, 1);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25   40
                /           \
               /             \
              9              45
            /   \           /
           /     \         /
          7      12       42
    */

    root = delete(root, 40);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  45
                 /       / 
                /       /   
               9       42    
             /   \          
            /     \        
           7      12      
    */

    root = delete(root, 45);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  42
                 /          
                /            
               9            
             /   \          
            /     \        
           7      12      
    */
    root = delete(root, 9);
    inorder(root);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  42
                 /          
                /            
               12            
             /             
            /             
           7            
    */
    printf("\n");


  end_time = clock();

  cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;


   printf("The execution time of the code is: %f seconds\n", cpu_time_used);


    return 0;
}

/*

observations about the provided code:

Data Structure: The code implements a Binary Search Tree (BST). In a BST, each node has a unique key, and for each node, all elements in the left subtree are less than the node, and all elements in the right subtree are greater than the node.

Node Structure: Each node in the tree contains an integer data, and pointers to its left and right child nodes.


Functions: The code includes functions for various operations on the BST:
new_node(int x): Creates a new node with data x.

insert(struct node *root, int x): Inserts a new node with data x into the BST rooted at root.

search(struct node *root, int x): Searches for a node with data x in the BST rooted at root.

find_minimum(struct node *root): Finds the node with the minimum data in the BST rooted at root.

delete(struct node *root, int x): Deletes the node with data x from the BST rooted at root.

inorder(struct node *root): Performs an inorder traversal of the BST rooted at root and prints the data of each node.

Memory Management: The code uses dynamic memory allocation (malloc) for creating new nodes, and it correctly frees memory (free) when nodes are deleted.

Test Case: The main function tests these operations with a series of insertions and deletions, and it prints the inorder traversal of the tree after each operation. The comments in the code provide a clear visualization of the state of the tree after each operation.

Efficiency: The time complexity of search, insert, and delete operations in a BST is O(h), where h is the height of the tree. In the worst case (when the tree becomes skewed), the height becomes n (number of nodes) and the time complexity becomes O(n).

NOTE : Time Complexity code added in the original code.

*/