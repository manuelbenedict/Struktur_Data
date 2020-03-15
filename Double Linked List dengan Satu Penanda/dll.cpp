#include "dll.h"

void createList(List &L)
{
    first(L) = NULL ;
}

address allocate (infotype x)
{
    address P ;
    P = new elmList ;
    info(P) = x ;
    next(P) = NULL;
    prev(P) = NULL;
    return P ;
}

void insertFirst(List &L, address P)
{
    if (first(L) == NULL)
    {
        first(L) = P ;
    }
    else
    {
        next(P) = first(L) ;
        prev(first(L)) = P ;
        first(L) = P ;
    }
}

void insertLast(List &L, address P)
{
    address Q;
    if (first(L) == NULL)
    {
        insertFirst(L,P);
    } else
    {
        Q = first(L) ;
        while (next(Q) != NULL)
        {
            Q = next(Q) ;
        }
        next(Q) = P ;
    }
}

void insertAfter(List &L, address Prec, address P)
{
    if (next(Prec) != NULL)
    {
        next(P) = next(Prec) ;
        prev(next(Prec)) = P ;
    }
    next(Prec) = P ;
    prev(P) = Prec ;
}

void deleteFirst(List &L, address &P)
{
    if (first(L) != NULL)
    {
        P = first(L) ;
        first(L) = next(P) ;
        prev(first(L)) = NULL ;
    }
}

void deleteLast(List &L, address &P)
{
    address Q ;
    Q = first(L) ;
    if (next(first(L)) == NULL)
    {
        deleteFirst(L,P) ;
    }
    else
    {
        while (next(Q) != NULL)
        {
            Q = next(Q) ;
        }
        next(Q) = NULL ;
        next(prev(Q)) = NULL ;
    }
}

void deleteAfter(List &L, address Prec, address &P)
{
    P = next(Prec) ;
    if (next(P) != NULL)
    {
        next(Prec) = next(P) ;
        prev(next(Prec)) = Prec ;
    }
    else
    {
        next(Prec) = NULL ;
    }
}

address findElm(List L, infotype x)
{
    address P ;
    P = first(L) ;
    while ((P != NULL) && (info(P) != x))
    {
        P = next(P) ;
    }
    if (info(P) == x)
    {
        return P ;
    }
    else
    {
        return NULL ;
    }
}

int printInfo(List L)
{
    address P ;
    P = first(L) ;
    while (P != NULL)
    {
        cout<<info(P)<<" " ;
        P = next(P) ;
    }
    cout<<endl;
}
