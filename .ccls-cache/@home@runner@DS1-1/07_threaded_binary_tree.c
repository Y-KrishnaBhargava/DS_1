// Cprogram to convert a Binary Tree to	Threaded Tree 
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

// Structure of a node in threaded binary tree
struct node
{
	int key;
	struct node *left, *right;
	// Used to indicate whether the right pointer
	// is a normal right pointer or a pointer
	// to inorder successor.
	bool isThreaded;
};

// Converts tree with given root to threaded binary tree.
// This function returns rightmost child of root.
struct node *createThreaded(struct node *root) {
	// Base cases : Tree is empty or has single node
	if (root == NULL)
		return NULL;
	if (root->left == NULL && root->right == NULL)
		return root;

	// Find predecessor if it exists
	if (root->left != NULL)  {
		// Find predecessor of root (Rightmost child in left subtree)
		struct node* l = createThreaded(root->left);

		// Link a thread from predecessor to root.
		l->right = root;
		l->isThreaded = true;
	}

	// If current node is rightmost child
	if (root->right == NULL)
		return root;

	// Recur for right subtree.
	return createThreaded(root->right);
}

// A utility function to find leftmost node in a binary tree rooted with 'root'.
// This function is used in inOrder()
struct node *leftMost(struct node *root) {
	while (root != NULL && root->left != NULL)
		root = root->left;
	return root;
}

// Function to do inorder traversal of a threadded binary tree
void inOrder(struct node *root) {
	if (root == NULL) return;
	// Find the leftmost node in Binary Tree
	struct node *cur = leftMost(root);
	while (cur != NULL)	{
		printf("%d ", cur->key);

		// If this Node is a thread Node, then go to inorder successor
		if (cur->isThreaded)
			cur = cur->right;
		else // Else go to the leftmost child in right subtree
			cur = leftMost(cur->right);
	}
}

// A utility function to create a new node
struct node *newNode(int key) {
	struct node *temp = (struct node *) malloc (sizeof (struct node));
	temp->left = temp->right = NULL;
	temp->key = key;
	return temp;
}

int main()
{
	/*	 1
			/ \
		 2   3
		/ \ / \
	  4 5 6 7 */
	struct node *root = (struct node * ) malloc(sizeof (struct node));
  root->key = 1;
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	createThreaded(root);

	printf("Inorder traversal of created threaded tree is\n");
	inOrder(root);
	return 0;
}
/*

observations :

Purpose: The code is designed to convert a binary tree into a threaded binary tree and perform an inorder traversal on it. A threaded binary tree makes inorder traversal faster and does possible without stack or without recursion.
Structures and Variables: The node structure is defined with key, left, right, and isThreaded fields. key holds the value of the node, left and right are pointers to the left and right child nodes respectively, and isThreaded is a boolean that indicates whether the right pointer is a normal right pointer or a pointer to the inorder successor.

Functions: The code includes several functions:
createThreaded: This function converts a binary tree into a threaded binary tree. It recursively traverses the tree in a reverse inorder manner and makes all possible right pointers to point to the inorder successor.

leftMost: This function is used to find the leftmost node in a binary tree. It’s used in the inOrder function to start the traversal from the leftmost node.

inOrder: This function performs an inorder traversal on a threaded binary tree. It starts from the leftmost node and follows the threaded links.

newNode: This function creates a new node with the given key.

Memory Allocation: The newNode function uses malloc to allocate memory for new nodes. The main function also uses malloc to allocate memory for the root node. However, there are no checks to see if malloc returns NULL, which can lead to undefined behavior if the memory allocation fails.

Sample Tree: In the main function, a sample binary tree is created for demonstration purposes. The tree is then converted into a threaded binary tree, and an inorder traversal is performed.

Output: The output of the program will be the inorder traversal of the created threaded binary tree, printed to the console.

Error Handling: The code does not include any error handling mechanisms. For instance, it does not check if malloc successfully allocates memory.

Portability: The code uses standard C library functions and should be portable across different platforms that support C.


*/