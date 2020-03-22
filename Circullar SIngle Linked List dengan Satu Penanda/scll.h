#ifndef SCLL_H_INCLUDED
#define SCLL_H_INCLUDED

#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
using namespace std;
typedef int infotype;
typedef struct elmList *address;

struct elmList
{
    infotype info;
    address next;
};

struct List
{
    address first;
};

void createList(List &L) ;
address allocate (infotype x) ;
void insertFirst(List &L, address P) ;
void insertLast(List &L, address P) ;
void insertAfter(List &L, address Prec, address P) ;
void deleteFirst(List &L, address &P) ;
void deleteLast(List &L, address &P) ;
void deleteAfter(List &L, address Prec, address &P) ;
address findElm(List L, infotype x);
void printInfo(List L);


#endif // SCLL_H_INCLUDED
