/*
 * PriorityQueue.c
 *
 *  Created on: Nov 20, 2021
 *      Author: mohamed


#include <stdio.h>
#include <stdlib.h>


typedef struct queuenode
{
	int data;
	int priority;
	struct queuenode *next;
}QueueNode;


typedef struct pqueue
{
	QueueNode *head;
	int size;
}PQueue;

void CreatePQueue(PQueue *ppq)
{
	ppq->head = NULL;
	ppq->size = 0;
}

void insert(int e , int p , PQueue *ppq)
{
	QueueNode *temp = ppq->head;
	QueueNode *pn = (QueueNode*)malloc(sizeof(QueueNode));
	pn->data = e;
	pn->priority = p;

	if (!ppq->head)
	{
		pn->next = ppq->head;
		ppq->head = pn;
	}
	else
	{
		if(ppq->head->priority > p)
		{
			pn->next = ppq->head;
			ppq->head = pn;
		}
		else
		{
			while (temp->next != NULL && temp->next->priority < p)
			{
				temp = temp->next;
			}
			pn->next = temp->next;
			temp->next = pn;
		}

	}
	ppq->size++;
}

void pop(int *pe , int *pp, PQueue *ppq)
{
	QueueNode *temp = ppq->head;
	*pe = ppq->head->data;
	*pp = ppq->head->priority;
	ppq->head = ppq->head->next;
	free(temp);
}

int QueueEmpty(PQueue *ppq)
{
	return !ppq->head;
}

int main()
{
	int n, d, i;
	int count=0, temp=0;
	PQueue pq;
	CreatePQueue(&pq);

	scanf("%d", &n);
	while(n)
	{
		scanf("%d%d", &d, &i);
		insert(d, i, &pq);
		n--;
	}

	while(!QueueEmpty(&pq))
	{
		pop(&d , &i, &pq);
		temp += d;
		if(temp <= i)
			count++;
		else
			temp -= d;
	}
	printf("%d" , count);
	return 0;
}
 */
