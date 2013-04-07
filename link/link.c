#include "link.h"

int init_link(Link *l)
{
	l->head = (Node *)malloc(sizeof(Node));
	if (!l->head)
	  return -1;
	l->head->data = 0;
	l->head->next = NULL;
	return 0;
}

Node *insert_link(Link *l, DataType data)
{
	Node *node = l->head;
	while (node->next != NULL)
	  node = node->next;
	Node *add = (Node *)malloc(sizeof(Node));
	if (!add)
	  return NULL;
	add->data = data;
	add->next = NULL;
	node->next = add;
	return add;
}

Node *delete_link(Link *l, DataType data)
{
	Node *prev = l->head;
	Node *curr = l->head->next;
	
	while (curr != NULL) {
		if (curr->data == data) {
			prev->next = curr->next;
			return curr;
		}
		prev = curr;
		curr = curr->next;
	}
	return NULL;
}

void reverse_link(Link *l)
{
	Node *prev, *curr, *next;

	prev = l->head->next;
	curr = l->head->next->next;

	if (curr == NULL || prev == NULL)
	  return;

	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	l->head->next->next = NULL;
	l->head->next = prev;
}

void recursive_reverse_link(Link *l)
{
	Node *p = recursive_reverse(l->head->next);
	l->head->next->next = NULL;
	l->head->next = p;
}

Node *recursive_reverse(Node *node)
{
	if (node == NULL || node->next == NULL)
		return node;
	
	Node *p = recursive_reverse(node->next);
	node->next->next = node;
	
	return p;
}

void print_link(Link *l)
{
	Node *node = l->head;
	while (node->next != NULL) {
		node = node->next;
		printf("%d\t", node->data);
	}
	printf("\n");
}

int main(void)
{
	Link link;

	init_link(&link);	
	insert_link(&link, 3);
	insert_link(&link, 4);
	delete_link(&link, 4);
	delete_link(&link, 3);
	insert_link(&link, 5);
	insert_link(&link, 6);
	insert_link(&link, 7);
	print_link(&link);      //打印链表
	reverse_link(&link);    //非递归转置链表
	print_link(&link);
	recursive_reverse_link(&link);   //递归转置链表
	print_link(&link);

	return 0;
}
