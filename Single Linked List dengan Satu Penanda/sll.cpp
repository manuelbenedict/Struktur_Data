#include "sll.h"

void createList(List &L)
{
    first(L) = NULL ;
}

address allocate (infotype x)
{
    address P ;
    P = new elmList ;
    next(P) = NULL;
    info(P) = x ;
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
    if ((first(L) != NULL) && (Prec != NULL))
    {
        next(P) = next(Prec) ;
        next(Prec) = P ;
    }
}

void deleteFirst(List &L, address &P)
{
    if (first(L) != NULL)
    {
        P = first(L) ;
        first(L) = next(P) ;
        next(P) = NULL ;
    }
}

void deleteLast(List &L, address &P)
{
    address Q ;
    if (first(L) != NULL)
    {
        Q = first(L) ;
        if (next(Q) == NULL)
        {
            first(L) = next(Q) ;
            next(Q) = NULL ;
        }
        else
        {
            while (next(next(Q)) != NULL)
            {
                Q = next(Q) ;
            }
            P = next(Q) ;
            next(Q) = NULL ;
            next(P) = NULL ;
        }
    }
}

void deleteAfter(List &L, address Prec, address &P)
{
    if ((first(L) != NULL) && (Prec != NULL))
    {
        P = next(Prec) ;
        next(Prec) = next(P) ;
        next(P) = NULL ;
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
