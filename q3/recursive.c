#include <stdlib.h>
#include <stdio.h>
TreeNode* flatten(TreeNode *root) {
	if (root == NULL) return NULL;
	TreeNode* rightTree = root->right;    
	TreeNode* newHead = root;  
	TreeNode* leftList = flatten(root->left);  
	if (leftList != NULL)  {
		newHead = leftList;
		TreeNode* tail = leftList->left; 
		tail->right = root;
		root->left = tail;
		leftList->left = root; 
	}
	TreeNode* rightList = flatten(rightTree); 
	if (rightList != NULL) {
		root->right = rightList;
		newHead->left = rightList->left;
		rightList->left = root;  
		}
		return newHead;  		
}

int main()
{
    TreeNode *head;
    flatten(head);
    printf("%d->%d->%d->%d->%d->%d\n",head->data,
           head->right->data,
           head->right->right->data,
           head->right->right->right->data,
           head->right->right->right->right->data,
           head->right->right->right->right->right->data);
    return 0;
}
