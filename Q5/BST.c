#include <stdio.h>
#include "BST.h"
#include "TreePrintLibrary.h"

#define ifNull(parameter)do{ if ((parameter) == NULL){ printf("allocation failed"); exit(1);}}while(0);
void initBST(BST* bst);
void insertBST(BST* bst, int value);
void insert(TreeNode* root, TreeNode* newNode);
void printTreeInorder(BST* bst);
void inorder(TreeNode * root);
void destroyBST(BST * bst);
int findIndexNFromLast(BST * bst, int N);


void initBST(BST* bst)
{
	bst->root = NULL;
}

void insertBST(BST* bst, int value)
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	ifNull(newNode);
	newNode->element = value;
	newNode->left = NULL;
	newNode->right = NULL;
	insert(bst, newNode);

}

void insert(TreeNode* root, TreeNode* newNode) {
	if (newNode->element <= root->element)
		if (root->left == NULL)
			root->left = newNode;
		else
			insert(root->left, newNode);
	if (newNode->element > root->element)
		if (root->right == NULL)
			root->right = newNode;
		else
			insert(root->right, newNode);
}

void printTreeInorder(BST* bst) {
	if (bst == NULL) { printf("The tree is empty\n"); return 0; }
	inorder(bst);
}

void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d", root->element);
		inorder(root->right);
	}
}

void destroyBST(BST* bst) {
	if (bst == NULL)
		return;
	destroyBST(bst->root->left);
	destroyBST(bst->root->right);
	free(bst->root);
}

int findIndexNFromLast(BST* bst, int N) {
	if (bst == NULL) { exit(1); };

}

int reversInorder(TreeNode* node, int N) {
	if (N == 0)
		return node->element;
	
	if (node != NULL) {
		reversInorder(node->right,--N);
		reversInorder(node->left,--N);
	}
	
}


