/*
 * queue.h
 *
 *  Created on: Dec 5, 2021
 *      Author: mohamed
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#define LINKED_QUEUE
#define MAXQUEUE 100

typedef int QueueEntry;

#ifdef LINKED_QUEUE

typedef struct queuenode
{
	QueueEntry entry;
	struct queuenode *next;
}QueueNode;

typedef struct queue
{
	QueueNode *front;
	QueueNode *rear;
	int size;
}Queue;

#else

typedef struct queue
{
	int front;
	int rear;
	int size;
	QueueEntry entry[MAXQUEUE];
}Queue;


#endif

void CreateQueue(Queue*);
void Append(QueueEntry, Queue*);
void Serve(QueueEntry* , Queue*);
void ClearQueue(Queue*);
int QueueSize(Queue*);
int QueueEmpty(Queue*);
int QueueFull(Queue*);
void TraverseQueue(Queue* , void(*)(QueueEntry));


#endif /* QUEUE_H_ */
