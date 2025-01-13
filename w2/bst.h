#ifndef BST_H
#define BST_H

// Basic node structure for a Binary Search Tree
struct node {
    int value;
    struct node *left;
    struct node *right;
};

// Insert a new value into the BST as a leaf node
// Returns the (possibly new) root of the BST
struct node *bstInsert(struct node *root, int value);

// Frees all nodes in the BST
void bstFree(struct node *root);

// Q3: Count the number of odd-valued nodes in the tree
int bstCountOdds(struct node *t);

// Q4: Count the number of internal nodes in the tree
//     (An internal node is a node with at least one child.)
int bstCountInternal(struct node *t);

// Q5: Return the level of the node containing 'key'. The root is at level 0.
//     If 'key' is not in the BST, return -1.
int bstNodeLevel(struct node *t, int key);

// Q6: Count the number of values in the BST that are greater than 'val'.
//     Avoid unnecessary visits (prune subtrees if possible).
int bstCountGreater(struct node *t, int val);

#endif