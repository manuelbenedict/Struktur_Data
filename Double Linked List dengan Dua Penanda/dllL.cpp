#include "dllL.h"

void createList(List &L)
{
    first(L) = NULL ;
    last(L) = NULL ;
}

address allocate (infotype x)
{
    address P ;
    P = new elmList ;
    next(P) = NULL ;
    prev(P) = NULL ;
    info(P) = x ;
    return P ;
}

void insertFirst(List &L, address P)
{
    if (first(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
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
    if (first(L) == NULL)
    {
        insertFirst(L,P) ;
    }
    else
    {
        prev(P) = last(L) ;
        next(last(L)) = P ;
        last(L) = P ;
    }
}

void insertAfter(List &L, address Prec, address P)
{
    if ((first(L) != NULL) && (Prec != NULL))
    {
        if (next(Prec) == NULL)
        {
            insertLast(L,P) ;
        }
        else
        {
            next(P) = next(Prec) ;
            prev(P) = Prec ;
            prev(next(Prec)) = P ;
            next(Prec) = P ;
        }
    }
}

void deleteFirst(List &L, address &P)
{
    if (first(L) != NULL)
    {
        P = first(L) ;
        if (P == last(L))
        {
            first(L) = NULL ;
            last(L) = NULL ;
        }
        else
        {
            first(L) = next(P) ;
            next(P) = NULL ;
            prev(first(L)) = NULL ;
        }
    }
}

void deleteLast(List &L, address &P)
{
    P = last(L) ;
    if (last(L) != NULL)
    {
        last(L) = prev(P) ;
        prev(P) = NULL ;
        next(last(L)) = NULL ;
    }
    else if (last(L) == first(L))
    {
        first(L) = NULL ;
        last(L) = NULL ;
    }
}

void deleteAfter(List &L, address Prec, address &P)
{
    if ((first(L) != NULL) && (Prec != NULL))
    {
        if (Prec != last(L))
        {
            if (next(Prec) == last(L))
            {
                deleteLast(L,P) ;
            }
            else
            {
                P = next(Prec) ;
                next(Prec) = next(P) ;
                prev(next(P)) = Prec ;
                next(P) = NULL ;
                prev(P) = NULL ;
            }
        }
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

void printInfo(List L)
{
    address P ;
    P = first(L) ;
    while (P != NULL)
    {
        cout<<info(P)<<" " ;
        P = next(P) ;
    }
    cout<<endl ;
}
