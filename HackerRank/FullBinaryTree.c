/*
 * FullBinaryTree.c
 *
 *  Created on: Dec 10, 2021
 *      Author: mohamed
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
	int key;
	struct treenode *left, *right;
}TreeNode;

typedef struct queuenode
{
	TreeNode *data;
	struct queuenode *next;
}QueueNode;

typedef struct queue
{
	QueueNode *front;
	QueueNode *rear;
	int size;
}Queue;

void CreateQueue(Queue *pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->size = 0;
}

void EnQueue(Queue *pq , TreeNode *data)
{
	QueueNode *pn = (QueueNode*)malloc(sizeof(QueueNode));
	pn->data = data;
	pn->next = NULL;
	if(!pq->rear)
		pq->front = pn;
	else
		pq->rear->next = pn;
	pq->rear = pn;
	pq->size++;
}


void DeQueue(Queue *pq)
{
	QueueNode *pn = pq->front;
	pq->front = pq->front->next;
	free(pn);
	if(!pq->front)
		pq->rear = NULL;
	pq->size--;
}


TreeNode* new(int value)
{
	TreeNode *n = (TreeNode*)malloc(sizeof(TreeNode));
	n->key = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}

TreeNode *InsertValue(TreeNode *root, int value, Queue *pq)
{
	TreeNode *pn;
	if(value != -1)
		pn = new(value);
	if (root == NULL)
		root = pn;
	else if(pq->front->data->left == NULL && value != -1)
		pq->front->data->left = pn;
	else
	{
		if(value != -1)
			pq->front->data->right = pn;
		DeQueue(&(*pq));
	}

	if(value != -1)
		EnQueue(&(*pq) , pn);
	return root;
}

/*********************************** validate the construction of the tree *************************/
void printInorder(TreeNode *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    printf("%d ", node->key);

    /* now recur on right child */
    printInorder(node->right);
}

/******************************* Check if the Tree is full ******************************/
int isFullTree (TreeNode* root)
{
    // If empty tree
    if (root == NULL)
        return 1;

    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // If both left and right are not NULL, and left & right subtrees
    // are full
    if ((root->left) && (root->right))
        return (isFullTree(root->left) && isFullTree(root->right));

    // We reach here when none of the above if conditions work
    return 0;
}


/********************************** Driver Code ***********************************/

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 9, 8, 9, 8, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	Queue q;
	CreateQueue(&q);
	TreeNode *root = NULL;
	for(int i = 0 ; i < n ; i++)
		root = InsertValue(root, arr[i], &q);

	printInorder(root);
	printf("\n%d",isFullTree(root));
	return 0;
}






































