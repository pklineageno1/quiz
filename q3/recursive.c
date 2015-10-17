#include <stdio.h>
#include <stdlib.h>

int count = 0;

typedef struct TREENODE {
    int data;
    struct TREENODE *left;
    struct TREENODE *right;
} treenode;

treenode *Node[5];

treenode* createnode(treenode *node, int data)
{
    node = (treenode *)malloc(sizeof(treenode));
    node->data = data;
    node->right = NULL;
    node->left =NULL;
    return node;
}
treenode* add_leftnode(treenode *node, int data)
{
    treenode *tmp, *buf;
    tmp = createnode(tmp,data);
    buf = node;
    buf->left = tmp;
    return buf;
}

treenode* add_rightnode(treenode *node, int data)
{
    treenode *tmp, *buf;
    tmp = createnode(tmp,data);
    buf = node;
    buf->right = tmp;
    return buf;

}
treenode* build_tree(treenode *node)
{
    treenode *tmp_r4,*tmp_r5,*tmp_r6,*tmp_l2,*tmp_l3;
    if(node==NULL) {
        node = createnode(node,1);
    }
    tmp_l2 = node = createnode(tmp_l2,2);
    tmp_l3 = node = createnode(tmp_l3,3);
    tmp_r4 = node = createnode(tmp_r4,4);
    tmp_r5 = node = createnode(tmp_r5,5);
    tmp_r6 = node = createnode(tmp_r6,6);

    tmp_l2 = node->left;

    tmp_l3 = tmp_l2->left;

    tmp_r4 = tmp_l2->right;

    tmp_r5 = node->right;

    tmp_r6 =tmp_r5->right;


    return node;
}

treenode *_flatten(treenode *node)
{
    if(node == NULL) {
        return NULL;
    }
    if(node->right) {
        node->right = _flatten(node->right);
    }
    if(node->left) {
        treenode *tmp = node->right;
        node->right = _flatten(node->left);
        treenode *t = node->right;
        while(t->right) {
            t = t->right;
        }
        t->right = tmp;
        node->left = NULL;
    }
    return node;
}
void flatten(treenode *node)
{
    _flatten(node);
}

int main()
{
    treenode *node=NULL;
    // build tree
    node = build_tree(node);
    // binary tree to flat tree
    flatten(node);

    return 1;
}
