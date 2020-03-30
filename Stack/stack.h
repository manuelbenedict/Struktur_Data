#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>

#define top(S) (S).top
#define info(S) (S).info

using namespace std ;

typedef int infotype ;
const int nMax = 10 ;
struct Stack
{
    infotype info[nMax] ;
    int top ;
};

void createStack(Stack &S) ;
bool isEmpty(Stack S) ;
bool isFull(Stack S) ;
void push(Stack &S, infotype x) ;
void pop(Stack &S) ;
void printInfo(Stack S) ;

#endif // STACK_H_INCLUDED
