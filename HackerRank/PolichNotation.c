/*
 * PolichNotation.c
 *
 *  Created on: Nov 14, 2021
 *      Author: mohamed
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode
{
    int data;
    struct StackNode *next;
}stacknode;

typedef struct Stack
{
    stacknode *top;
}stack;

void CreateStack(stack *ps)
{
    ps->top = NULL;
}

void push(int c , stack *ps)
{
    stacknode *pn = (stacknode*)malloc(sizeof(stacknode));
    pn->data = c;
    pn->next = ps->top;
    ps->top = pn;
}

void pop(int *pe , stack *ps)
{
    stacknode *pn = ps->top;
    *pe = ps->top->data;
    ps->top = ps->top->next;
    free(pn);
}

int IsDig(char c)
{
    if(c >= '0' && c <= '9')
        return 1;
    return 0;
}

int Oper(char c , int op1 , int op2)
{
    switch(c)
    {
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
        case '%':
            return op1%op2;

    }

    exit(0);
}

int EvaluatePostFix(char expr[])
{
    int i , op1, op2, val;
    char c;

    stack s;
    CreateStack(&s);


    for (i = 0 ; (c=expr[i]) != '\0' ; i++)
    {
        if(IsDig(c))
            push((int)(c-'0') , &s);
        else
        {
            pop(&op2 , &s);
            pop(&op1 , &s);
            if((op2 == 0) && (c == '/' || c=='%'))
            {
            	printf("Not Valid");
                exit(1);
            }
            val = Oper(c , op1 , op2);
            push(val , &s);
        }
    }
    pop(&val , &s);
    return val;
}


int main()
{
    int i,k=0;
    char ex[10000];
    scanf("%s", ex);
    for(i = 0 ; ex[i]!='\0' ; i++)
    {
        if(IsDig(ex[i]))
            k++;
        else
        {
            k--;k--;
            if(k < 0)
            {
                printf("Not Valid");
                exit(0);
            }
            k++;
        }
    }


    if(k==1)
        printf("%d", EvaluatePostFix(ex));
    else
        printf("Not Valid");
    return 0;
}
