/*
 * main.c
 *
 *  Created on: Dec 5, 2021
 *      Author: mohamed
 */


#include <stdio.h>
#include<stdlib.h>

#include "queue.h"

void print(QueueEntry e)
{
	printf("%d\n", e);
}

int main()
{
	int i;

	Queue q;
	CreateQueue(&q);
	for(i = 0 ; i < 10 ; i++)
		Append(i, &q);
	TraverseQueue(&q, &print);
	printf("%d", QueueSize(&q));

	return 0;
}
