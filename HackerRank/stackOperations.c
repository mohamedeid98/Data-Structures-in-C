#include <stdio.h>
#define STACKMAX 100
typedef struct stack
{
    unsigned int top;
    int entry[STACKMAX];

}Stack;

void InitializeStack(Stack *ps);
int StackFull(Stack*ps);
void push(int e, Stack *ps);
int StackEmpty(Stack *ps);
void DeleteTop(Stack *ps);
int getmin(Stack *ps);
int main()
{
    int Q, i, E;
    Stack s;
    InitializeStack(&s);

    scanf("%d", &Q);

    while(Q)
    {
        scanf("%d", &i);

        switch (i)
        {
        case 1:
            scanf("%d", &E);
            if(! StackFull(&s))
                push(E, &s);
            break;

        case 2:
            if(!StackEmpty(&s))
                DeleteTop(&s);
            break;
        case 3:
            if(!StackEmpty(&s))
                printf("%d\n", getmin(&s));
            else
                printf("%s\n", "Empty");
                    
            break;
        }
        Q--;

    }





    return 0;
}
void InitializeStack(Stack *ps)
{
    ps->top = 0;
}

void push(int e, Stack *ps)
{
    ps->entry[ps->top++] = e;
}

void DeleteTop (Stack *ps)
{
    ps->top--;
}


int StackFull(Stack*ps)
{
    if(ps->top == STACKMAX)
        return 1;
    return 0;
}


int StackEmpty(Stack *ps)
{
    return !(ps->top);
}


int getmin(Stack *ps)
{
    int min=0 , i;
    min = ps->entry[ps->top-1];
    for(i = ps->top-2 ; i >= 0 ; i--)
    {
        if(min > ps->entry[i])
            min = ps->entry[i];
    }

    return min;
}









