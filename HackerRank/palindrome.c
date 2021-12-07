/*
 * palindrome.c
 *
 *  Created on: Nov 7, 2021
 *      Author: mohamed
 */


#include <stdio.h>
#include <stdlib.h>



int num;
struct node
{
	int data;
	struct node * next;
}*header;

void check(struct node *header);
void reverseList();

int main()
{
     int data, num1;

     scanf("%d", &num);
     num1 = num;

     data = num1 % 10;
     num1 /= 10;

     struct node *newNode, *temp;


     newNode = (struct node *)malloc(sizeof(struct node));


     if(newNode == NULL)
     {
    	 printf("Unable to allocate memory.");
     }
     else
     {

    	 newNode->data = data;

    	 newNode->next = NULL;

    	 header = newNode;

    	 temp = newNode;
     }

     while(num1 != 0)
     {
    	 data = num1 % 10;
    	 num1 /= 10;

    	 newNode = (struct node *)malloc(sizeof(struct node));

    	 if(newNode == NULL)
    	 {
    		 printf("Unable to allocate memory.");
    		 break;
    	 }
    	 else
    	 {
    		 newNode->data = data;
    		 newNode->next = NULL;

    		 temp->next = newNode;
    		 temp = temp->next;
    	 }

     }
     reverseList();
     check(header);
	 return 0;
}


void check(struct node *header)
{
	struct node *temp;
	int dig;
	/* If the list is empty i.e. head = NULL */
	if(header == NULL)
	{
		printf("List is empty.");
	}
	else
	{
		temp = header;
		while(temp != NULL)
		{
			dig = num%10;
			if(temp->data != dig)
			{
				printf("NO");
				return;
			}
			temp = temp->next; 	//Advances the position of current node
			num /= 10;
		}
		printf("YES");
	}
}

void reverseList()
{
	struct node *prevNode, *curNode;
	if(header != NULL)
	{
		prevNode = header;
		curNode = header->next;
		header = header->next;

		prevNode->next = NULL; 	//Makes the first node as last node

		while(header != NULL)
		{
			header = header->next;
			curNode->next = prevNode;

			prevNode = curNode;
			curNode = header;
		}

		header = prevNode; 		//Makes the last node as head
	}
}
