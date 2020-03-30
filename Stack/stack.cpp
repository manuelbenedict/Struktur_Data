#include"stack.h"

void createStack(Stack &S)
{
    top(S) = 0 ;
}

bool isEmpty(Stack S)
{
    return top(S) == 0 ;
}

bool isFull(Stack S)
{
    return top(S) == nMax ;
}

void push(Stack &S, infotype x)
{
    if (!isFull(S))
    {
        top(S)++ ;
        info(S)[top(S)] = x ;
    }
}

void pop(Stack &S)
{
    infotype x ;
    if (!isEmpty(S))
    {
        x = info(S)[top(S)] ;
        top(S)-- ;
    }
}

void printInfo(Stack S)
{
    int i ;
    for (i = top(S); i>=1; i--)
    {
        cout<<info(S)[i]<<" " ;
    }
    cout<<endl ;
}
