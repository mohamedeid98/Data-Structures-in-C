/*
 * stack.c
 *
 *  Created on: Dec 4, 2021
 *      Author: mohamed
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "stack.h"

#ifdef LINKED_STACK

void CreateStack(Stack *ps)
{
	ps->top = NULL;
	ps->size = 0;
}

void push(StackEntry item, Stack *ps)
{
	StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
	if(pn == NULL)
		exit(0);
	else
	{
		pn->entry = item;
		pn->next = ps->top;
		ps->top = pn;
		ps->size++;
	}
}

void pop(StackEntry *item , Stack *ps)
{
	StackNode *p = ps->top;
	*item = ps->top->entry;
	ps->top = ps->top->next;
	free(p);
	ps->size--;
}

int StackEmpty(Stack *ps)
{
	return !ps->top;
}

int StackFull(Stack *ps)
{
	return 0;
}

void ClearStack(Stack *ps)
{
	StackNode *pn = ps->top;
	while(ps->top)
	{
		ps->top = ps->top->next;
		free(pn);
		pn = ps->top;
	}
	ps->size = 0;
}
int StackSize(Stack *ps)
{
	return ps->size;
}
void StackTop(StackEntry *item , Stack *ps)
{
	*item = ps->top->entry;
}


void TraverseStack(Stack *ps , void(*pf)(StackEntry))
{
	StackNode *p = ps->top;
	while(p)
	{
		(*pf)(p->entry);
		p = p->next;
	}
}







#else

void CreateStack(Stack* ps)
{
	ps->top = 0;
}

void push(StackEntry item, Stack* ps)
{
	ps->entry[ps->top] = item;
	ps->top++;
}


void pop(StackEntry *item, Stack *ps)
{
	ps->top--;
	*item = ps->entry[ps->top];
}

int StackEmpty(Stack *ps)
{
	return !ps->top;
}

int StackFull(Stack *ps)
{
	return ps->top >= MAXSIZE;
}

void ClearStack(Stack *ps)
{
	ps->top = 0;
}

void TraverseStack(Stack *ps , void(*pf)(StackEntry))
{
	int i;
	for(i = ps->top ; i > 0 ; i--)
	{
		(*pf)(ps->entry[i-1]);
	}
}

int StackSize(Stack *ps)
{
	return ps->top;
}

void StackTop(StackEntry *pe, Stack *ps)
{
	*pe = ps->entry[ps->top - 1];
}



#endif

