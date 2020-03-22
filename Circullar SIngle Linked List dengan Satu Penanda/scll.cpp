#include "scll.h"

void createList(List &L)
{
    first(L) = NULL ;
}

address allocate (infotype x)
{
    List L ;
    address P ;
    P = new elmList ;
    next(P) = NULL;
    info(P) = x ;
    return P ;
}

void insertFirst(List &L, address P)
{
    address Q ;
    if (first(L) == NULL)
    {
        first(L) = P ;
        next(P) = P ;
    }
    else
    {
        Q = first(L) ;
        while (next(Q) != first(L))
        {
            Q = next(Q) ;
        }
        next(Q) = P ;
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
        while (next(Q) != first(L))
        {
            Q = next(Q) ;
        }
        next(Q) = P ;
        next(P) = first(L) ;
    }
}

void insertAfter(List &L, address Prec, address P)
{
    if ((first(L) != NULL) && (Prec != NULL))
    {
        if (next(Prec) == first(L))
        {
            insertLast(L,P) ;
        }
        else
        {
            next(P) = next(Prec) ;
            next(Prec) = P ;
        }
    }
}

void deleteFirst(List &L, address &P)
{
    address Q ;
    if (first(L) != NULL)
    {
        P = first(L) ;
        if (next(P) == first(L))
        {
            next(P) = NULL ;
            first(L) = NULL ;
        }
        else
        {
            Q = first(L) ;
            while (next(Q) != first(L))
            {
                Q = next(Q) ;
            }
            first(L) = next(P) ;
            next(Q) = next(P) ;
            next(P) = NULL ;
        }
    }
}

void deleteLast(List &L, address &P)
{
    address Q ;
    if (first(L) != NULL)
    {
        P = first(L) ;
        if (next(P) == first(L))
        {
            deleteFirst(L,P) ;
        }
        else
        {
            Q = first(L) ;
            while (next(next(Q)) != first(L))
            {
                Q = next(Q) ;
            }
            P= next(Q) ;
            next(Q) = next(P) ;
            next(P) = NULL ;
        }
    }
}

void deleteAfter(List &L, address Prec, address &P)
{
    if ((first(L) != NULL) && (Prec != NULL))
    {
        if (next(Prec) == first(L))
        {
            deleteFirst(L,P) ;
        }
        else
        {
            P = next(Prec) ;
            next(Prec) = next(P) ;
            next(P) = NULL ;
        }
    }
}

address findElm(List L, infotype x)
{
    address P ;
    P = first(L) ;
    do
    {
        P = next(P) ;
    }
    while ((next(P) != first(L)) && (info(P) != x)) ;
    if (info(P) == x)
    {
        return P ;
    }
    else
    {
        return NULL ;
    }
}

void printInfo(List L)
{
    address P ;
    P = first(L) ;
    do
    {
        cout<<info(P)<<" " ;
        P = next(P) ;
    }
    while (P != first(L)) ;
    cout<<endl;
}
