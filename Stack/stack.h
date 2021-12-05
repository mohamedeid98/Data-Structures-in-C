/*
 * stack.h
 *
 *  Created on: Dec 5, 2021
 *      Author: mohamed
 */

#ifndef STACK_H_
#define STACK_H_

#define LINKED_STACK
#define MAXSIZE 100
typedef int StackEntry;


#ifdef LINKED_STACK
typedef struct stacknode
{
	StackEntry entry;
	struct stacknode *next;
}StackNode;

typedef struct stack
{
	StackNode *top;
	int size;
}Stack;


#else
typedef struct stack
{
	int top;
	StackEntry entry[MAXSIZE];
}Stack;

#endif

void CreateStack(Stack *);
void push(StackEntry, Stack *);
void pop(StackEntry*, Stack*);
void ClearStack(Stack*);
int StackEmpty(Stack*);
int StackFull(Stack*);
void TraverseStack(Stack*, void(*)(StackEntry));
int StackSize(Stack*);
void StackTop(StackEntry* , Stack*);


#endif /* STACK_H_ */
