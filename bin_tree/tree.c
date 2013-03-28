#include "tree.h"

void init_tree(Tree *tree)
{
	tree->root = NULL;
}

Node *min_tree(Node *node)
{
	while (node->lchild != NULL)
		node = node->lchild;
	
	return node;
}

Node *successor_tree(Node *node)
{
	if (node->rchild != NULL)
		return min_tree(node->rchild);
	Node *parent = node->parent;
	while (parent != NULL && parent->rchild == node) {
		node = node->parent;
		parent = parent->parent;
	}

	return parent;
}

Node *insert_tree(Tree *tree, DataType data)
{
	Node *node = tree->root;
	Node *parent = NULL;
	while (node != NULL) {
		parent = node;
		if (data < node->data)
			node = node->lchild;
		else
			node = node->rchild;
	}

	Node *add = malloc(sizeof(Node));
	add->data = data;
	add->lchild = NULL;
	add->rchild = NULL;
	add->parent = parent;
	if (tree->root == NULL)
		tree->root = add;
	else if (data < parent->data)
		parent->lchild = add;
	else
		parent->rchild = add;

	return add;
}

Node *delete_tree(Tree *tree, DataType data)
{
	Node *node = tree->root;
	Node *to_delete = NULL;
	Node *child = NULL;

	while (node != NULL) {
		if (node->data == data)
			break;
		else if (data < node->data)
			node = node->lchild;
		else
			node = node->rchild;
	}
	if (node == NULL)
		return NULL;
	if (node->lchild == NULL || node->rchild == NULL)
		to_delete = node;
	else
		to_delete = successor_tree(node);
	if (to_delete->lchild != NULL)
		child = to_delete->lchild;
	else
		child = to_delete->rchild;
	if (child != NULL)
		child->parent = to_delete->parent;
	if (to_delete->parent == NULL)
		tree->root = child;
	else if (to_delete->parent->lchild == to_delete)
		to_delete->parent->lchild = child;
	else
		to_delete->parent->rchild = child;
	if (to_delete != node)
		node->data = to_delete->data;

	return to_delete;
}

void in_order_traverse_tree(Node *node)
{
	if (node == NULL)
		return;
	printf("%d\n", node->data);
	in_order_traverse_tree(node->lchild);
	in_order_traverse_tree(node->rchild);
}

int main(int argc, char *argv[])
{
	Tree tree;

	init_tree(&tree);
	insert_tree(&tree, 5);
	insert_tree(&tree, 2);
	insert_tree(&tree, 3);
	insert_tree(&tree, 6);
	insert_tree(&tree, 12);
	insert_tree(&tree, 9);
	insert_tree(&tree, 10);
	in_order_traverse_tree(tree.root);
	Node *node = successor_tree(tree.root);
	delete_tree(&tree, 6);
	delete_tree(&tree, 5);
	in_order_traverse_tree(tree.root);

	return 0;
}
