#ifndef _TREE_H
#define _TREE_H
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node {
	DataType data;
	struct node *lchild;
	struct node *rchild;
	struct node *parent;
} Node;
typedef struct {
	Node *root;
} Tree;

void init_tree(Tree *);
void in_order_traverse_tree(Node *);
Node *insert_tree(Tree *, DataType);
Node *delete_tree(Tree *, DataType);
Node *min_tree(Node *);
Node *successor_tree(Node *);

#endif
