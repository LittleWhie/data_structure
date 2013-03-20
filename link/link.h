#ifndef _LINK_H
#define _LINK_H
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node {
	DataType data;
	struct node *next;
} Node;
typedef struct link {
	struct node *head;
} Link;

int init_link(Link *l);
Node *insert_link(Link *l, DataType data);
Node *delete_link(Link *l, DataType data);
void reverse_link(Link *l);
void print_link(Link *l);

#endif
