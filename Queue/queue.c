/*
 * queue.c
 *
 *  Created on: Dec 5, 2021
 *      Author: mohamed
 */
#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

#ifdef LINKED_QUEUE


void CreateQueue(Queue *pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->size = 0;
}

void Append(QueueEntry item, Queue *pq)
{
	QueueNode *pn = (QueueNode*)malloc(sizeof(QueueNode));
	if(pn == NULL)
		exit(0);
	else
	{
		pn->entry = item;
		pn->next = NULL;
		if(!pq->rear)
			pq->front = pn;
		else
			pq->rear->next = pn;
		pq->rear = pn;
		pq->size++;
	}
}

void Serve(QueueEntry *pe, Queue *pq)
{
	QueueNode *pn = pq->front;

	*pe = pq->front->entry;
	pq->front = pq->front->next;
	free(pn);
	if(!pq->front)
		pq->rear = NULL;
	pq->size--;
}

void ClearQueue(Queue *pq)
{
	while(pq->front)
	{
		pq->rear = pq->front->next;
		free(pq->front);
		pq->front = pq->rear;
	}
	pq->size = 0;
}

int QueueSize(Queue *pq)
{
	return pq->size;
}

int QueueEmpty(Queue *pq)
{
	return !pq->size;
}

int QeueuFull(Queue *pq)
{
	return 0;
}

void TraverseQueue(Queue *pq, void(*pf)(QueueEntry))
{
	while(pq->front)
	{
		(*pf)(pq->front->entry);
		pq->front = pq->front->next;
	}
}









#else


void CreateQueue(Queue *pq)
{
	pq->front = 0;
	pq->rear = -1;
	pq->size = 0;
}

void Append(QueueEntry item , Queue* pq)
{
	pq->rear = (pq->rear + 1) % MAXQUEUE;
	pq->entry[pq->rear] = item;
	pq->size++;
}

void Serve(QueueEntry *pe , Queue *pq)
{
	*pe = pq->entry[pq->front];
	pq->front = (pq->front + 1) % MAXQUEUE;
	pq->size--;
}

int QueueEmpty(Queue* pq)
{
	return pq->size;
}

int QueuFull(Queue *pq)
{
	return pq->size == MAXQUEUE;
}


void ClearQueue(Queue *pq)
{
	pq->front = 0;
	pq->rear = -1;
	pq->size = 0;
}
int QueueSize(Queue *pq)
{
	return pq->size;
}

void TraverseQueue(Queue *pq, void(*pf)(QueueEntry))
{
	int i, s;
	for(i = pq->front, s=0 ; s < pq->size ; s++)
	{
		(*pf)(pq->entry[i]);
		i = (i + 1) % MAXQUEUE;
	}

}





#endif
