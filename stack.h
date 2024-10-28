#ifndef STACK_H
#define STACK_H

struct Node_stack {

	int val;
	int size_of_stack;
	struct Node_stack *next;

};
typedef struct Node_stack *stack;



stack Create_stack();
stack push(int data,stack s);
stack pop(stack s);



#endif
