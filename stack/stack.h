#ifndef _STACK_H
#define _STACK_H
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node {
	DataType data;
	struct node *next;
} Node;
typedef struct {
	Node *top;
} Stack;

int init_stack(Stack *);
Node *push(Stack *, DataType);
Node *pop(Stack *);
void print_stack();

#endif
