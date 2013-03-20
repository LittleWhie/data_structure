#include "stack.h"

int init_stack(Stack *s)
{
	s->top = malloc(sizeof(Node));
	if (!s->top)
	  return -1;
	s->top->data = 0;
	s->top->next = NULL;
	return 0;
}

Node *push(Stack *s, DataType data)
{
	Node *add = malloc(sizeof(Node));
	if (!add)
	  return NULL;
	add->data = data;
	add->next = s->top->next;
	s->top->next = add;
	return add;
}

Node *pop(Stack *s)
{
	Node *temp;
	if (s->top->next == NULL)
	  return NULL;
	temp = s->top->next;
	s->top->next = temp->next;
	return temp;
}

void print_stack(Stack *s)
{
	Node *node = s->top->next;

	while (node) {
	  printf("%d\t", node->data);
	  node = node->next;
	}
	printf("\n");
}

int main(void)
{
	Stack s;
	
	init_stack(&s);
	push(&s, 4);
	push(&s, 3);
	push(&s, 5);
	print_stack(&s);
	pop(&s);
	pop(&s);
	print_stack(&s);
	pop(&s);
	print_stack(&s);
	
	return 0;
}
