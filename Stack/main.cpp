#include "stack.h"

int main()
{
    Stack S;
    createStack(S) ;
    cout<<isEmpty(S)<<endl ;
    push(S,9) ;
    push(S,8) ;
    push(S,7) ;
    push(S,6) ;
    push(S,5) ;
    push(S,4) ;
    push(S,3) ;
    push(S,2) ;
    push(S,1) ;
    cout<<isFull(S)<<endl ;
    printInfo(S) ;
    pop(S) ;
    printInfo(S) ;
}
