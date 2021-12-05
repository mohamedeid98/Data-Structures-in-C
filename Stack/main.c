/*
 * main.c
 *
 *  Created on: Dec 5, 2021
 *      Author: mohamed
 */


#include<stdio.h>
#include "stack.h"

int main()
{
	StackEntry item;
	Stack s;
	CreateStack(&s);
	push(51, &s);
	/*pop(&item, &s);*/
	printf("%d", StackSize(&s));

	return 0;
}

