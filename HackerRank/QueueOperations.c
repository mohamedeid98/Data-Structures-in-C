/*
 * QueueOperations.c
 *
 *  Created on: Nov 14, 2021
 *      Author: mohamed
*/


#include <stdio.h>
#define MAXSIZE 100

typedef struct queue
{
	int front;
	int rear;
	int size;
	int entry[MAXSIZE];
}Queue;

void CreateQueue(Queue *pq)
{
	pq->front = 0;
	pq->rear = -1;
	pq->size = 0;
}

void Append(int E, Queue *pq)
{
	pq->rear = (pq->rear + 1) % MAXSIZE;
	pq->entry[pq->rear] = E;
	pq->size++;
}

void Remove(Queue *pq)
{
	pq->front = (pq->front + 1) % MAXSIZE;
	pq->size--;
}

int QueueEmpty(Queue *pq)
{
	return !(pq->size);
}

int QueueSize(Queue *pq)
{
	return pq->size;
}

void print(int e)
{
	printf("%d", e);
}

void TraverseQueue(Queue *pq , void(*pf)(int))
{
	int pos , s;
	pos = pq->front;
	for(s = 0 ; s < pq->size ; s++)
	{
		(*pf)(pq->entry[pos]);
		pos = (pos + 1) % MAXSIZE;
	}
}

int main()
{

	int Q, E , oper;
	Queue q;
	CreateQueue(&q);

	scanf("%d", &Q);
	while(Q)
	{
		scanf("%d", &oper);
		switch(oper)
		{
			case 1:
				scanf("%d", &E);
				Append(E, &q);
				break;
			case 2:
				if(!QueueEmpty(&q))
					Remove(&q);
				break;
			case 3:
				if(!QueueEmpty(&q))
					TraverseQueue(&q, &print);
		}
		Q--;
	}
	printf("%d", QueueSize(&q));
	return 0;
}
