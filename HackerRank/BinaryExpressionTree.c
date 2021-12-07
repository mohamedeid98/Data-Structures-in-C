#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


/*********************************Char Stack**********************************/
struct CharStackNode
{
	char data;
	struct CharStackNode *next;
};

struct CharStack
{
	struct CharStackNode *top;
	int size;
}*CharStack;

void CreateCharStack()
{
	CharStack->top = NULL;
	CharStack->size = 0;
}

void PushChar(char value)
{

	struct CharStackNode *pn = (struct CharStackNode*)malloc(sizeof(struct CharStackNode));
	pn->data = value;
	pn->next = CharStack->top;
	CharStack->top = pn;
	CharStack->size++;
}

struct CharStackNode *PopChar()
{
	struct CharStackNode *pn = CharStack->top;
	CharStack->top = CharStack->top->next;
	CharStack->size--;
	return pn;
}

int CharStackEmpty()
{
	return !CharStack->size;
}

char PeekChar()
{
	return CharStack->top->data;
}

/******************************************Tree Stack****************************/

struct TreeNode
{
	char data;
	struct TreeNode *left, *right;
};

struct TreeStackNode
{
	struct TreeNode *data;
	struct TreeStackNode *next;
};

struct TreeStack
{
	struct TreeStackNode *top;
	int size;
}*TreeStack;

void CreateTreeStack()
{
	TreeStack->top = NULL;
	TreeStack->size = 0;
}

void PushTreeNode(struct TreeNode *pdata)
{
	struct TreeStackNode *pnode = (struct TreeStackNode*)malloc(sizeof(struct TreeStackNode));
	pnode->data = pdata;
	pnode->next = TreeStack->top;
	TreeStack->top = pnode;
	TreeStack->size++;
}

struct TreeStackNode* PopTreeNode()
{
	struct TreeStackNode *pn = TreeStack->top;
	TreeStack->top = TreeStack->top->next;
	TreeStack->size--;
	return pn;
}

int TreeStackEmpty()
{
	return !TreeStack->size;
}


/********************************* Tree Construction *******************************/
int IsOperand(char c)
{
	return c >= '0' && c <= '9' ;
}


int GetPrecedence(char c)
{
	switch(c)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
	case '%':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}


struct TreeNode *NewTreeNode(char c)
{
	struct TreeNode *pnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	pnode->data = c;
	pnode->left = pnode->right = NULL;
	return pnode;
}


void ConstructOperationNode()
{
	struct TreeNode *new = NewTreeNode(PopChar()->data);
	struct TreeStackNode *right = PopTreeNode();
	struct TreeStackNode *left = PopTreeNode();
	new->right = right->data;
	new->left = left->data;
	PushTreeNode(new);
}

struct TreeNode* ConstructTree(char *expression)
{
	for(int i = 0 ; i < strlen(expression) ; i++)
	{
		if(IsOperand(expression[i]))
		{
			PushTreeNode(NewTreeNode(expression[i]));
		}
		else if(expression[i] == '(')
		{
			PushChar(expression[i]);
		}
		else if(expression[i] == ')')
		{
			while(PeekChar() != '(' && !CharStackEmpty() && !TreeStackEmpty())
			{
				ConstructOperationNode();
			}
			PopChar();
		}
		else if(GetPrecedence(expression[i]))
		{
			while(!CharStackEmpty() && GetPrecedence(expression[i]) <= GetPrecedence(PeekChar()) && PeekChar() != '(' && !TreeStackEmpty())
			{
				ConstructOperationNode();
			}
			PushChar(expression[i]);
		}
	}
	return PopTreeNode()->data;
}


void printPostorder(struct TreeNode* node) {
    if(node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%c", node->data);
}








int main()
{
    char expression[10002];
    scanf("%s", expression);

    // Initialize stacks
    TreeStack = (struct TreeStack*) malloc(sizeof (struct TreeStack));
    TreeStack->size = 0;
    CharStack = (struct CharStack*) malloc(sizeof (struct CharStack));
    CharStack->size = 0;

    // Add parenthesis to the expression
    strcat(expression, ")");
    PushChar('(');

    // Construct expression tree
    struct TreeNode* root = ConstructTree(expression);
    printPostorder(root);

    return 0;
}
















