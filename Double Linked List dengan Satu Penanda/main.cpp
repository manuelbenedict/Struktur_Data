#include "dll.h"

using namespace std;

int main()
{
    List L;
    infotype x;
    address P, Prec;

    createList(L) ;
    P = allocate(3) ;
    insertFirst(L,P) ;
    P = allocate(2) ;
    insertFirst(L,P) ;
    P = allocate(1) ;
    insertFirst(L,P) ;
    printInfo(L) ;

    P = allocate(4) ;
    insertLast(L,P) ;
    P = allocate(6) ;
    insertLast(L,P) ;
    P = allocate(8) ;
    insertLast(L,P) ;
    printInfo(L) ;

    P = allocate(5) ;
    Prec = findElm(L,4) ;
    insertAfter(L,Prec,P);
    P = allocate(7) ;
    Prec = findElm(L,6) ;
    insertAfter(L,Prec,P) ;
    P = allocate(9) ;
    Prec = findElm(L,8) ;
    insertAfter(L,Prec,P) ;
    printInfo(L) ;

    deleteFirst(L,P) ;
    deleteLast(L,P) ;
    printInfo(L) ;

    P = findElm(L,3) ;
    Prec = findElm(L,2) ;
    deleteAfter(L,Prec,P) ;
    printInfo(L) ;
    P = findElm(L,5) ;
    Prec = findElm(L,4) ;
    deleteAfter(L,Prec,P) ;
    printInfo(L) ;
    P = findElm(L,7) ;
    Prec = findElm(L,6) ;
    deleteAfter(L,Prec,P) ;
    printInfo(L) ;
}
