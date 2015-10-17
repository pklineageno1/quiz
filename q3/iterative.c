#include <stdio.h>
#include <stdlib.h>

int count = 0;

typedef struct TREENODE{
	int data;
	struct TREENODE *left;
	struct TREENODE *right;
}treenode;

treenode *Node[5];

treenode* createnode(treenode *node, int data){
	node = (treenode *)malloc(sizeof(treenode));
	node->data = data;
	node->right = NULL;
	node->left =NULL;
	return node;
}
treenode* add_leftnode(treenode *node, int data){
	treenode *tmp, *buf;
	tmp = createnode(tmp,data);
	buf = node;
	buf->left = tmp;
	return buf;
}

treenode* add_rightnode(treenode *node, int data){
	treenode *tmp, *buf;
	tmp = createnode(tmp,data);
	buf = node;
	buf->right = tmp;
	return buf;
	
}
treenode* build_tree(treenode *node){
	treenode *tmp_r, *tmp_l,*tmp;
	if(node==NULL){
		node = createnode(node,1);
	}
	tmp_l=add_leftnode(node,2);
	tmp_r=add_leftnode(tmp_l->left,3);
	tmp_r = add_rightnode(tmp_r->right,4);
	tmp_r = add_rightnode(node,5);
	tmp = add_rightnode(tmp_r->right,6);
	
	return node;
}

 treenode *_flatten(treenode *node)
 {
  if (node == NULL) {
    return NULL;
  }
  if (node->right) {
    node->right = _flatten(node->right);
  }
  if (node->left) {
    treenode *tmp = node->right;
    node->right = _flatten(node->left);
    treenode *t = node->right;
    while (t->right) {
      t = t->right;
    }
    t->right = tmp;
    node->left = NULL;
  }
  return node;
}
void flatten(treenode *node) {
    _flatten(node);
}

int main(){
	treenode *node=NULL,
	// build tree
	node = build_tree(node);
	// binary tree to flat tree
	flatten(node);
	
	return 1;
}
