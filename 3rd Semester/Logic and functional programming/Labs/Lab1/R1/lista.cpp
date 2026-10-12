#include "lista.h"
#include <iostream>

using namespace std;


PNod creare_rec(){
  TElem x;
  cout<<"x=";
  cin>>x;
  if (x==0)
    return NULL;
  else{
    PNod p=new Nod();
    p->e=x;
    p->urm=creare_rec();
    return p;
  }
}

bool apare(TElem x, Lista l) {
    if (isEmpty(l))
        return false;
    if (x==l._prim->e)
        return true;
    Lista tail;
    tail._prim=l._prim->urm;
    return apare(x,tail);
}

Lista transformaListaInSet(Lista l) {
    // i can't really return NULL so i will build an empty list myself.
    // base case
    Lista emptyList;
    if (isEmpty(l)) {
        emptyList._prim=NULL;
        return emptyList;
    }
    // if we find it later on
    Lista rest;
    rest._prim=l._prim->urm;
    if (apare(l._prim->e,rest)) {
        return transformaListaInSet(rest);
    }
    // if we don't find it later on -> add it now
    Lista r=transformaListaInSet(rest);
    PNod l1=new Nod();
    l1->e=l._prim->e;
    l1->urm=r._prim;
    r._prim=l1;
    return r;

}

Lista reuniune(Lista a, Lista b) {
    if (isEmpty(a)) {
        return copie(b);
    }
    if (isEmpty(b)) {
        return copie(a);
    }
    Lista rest;
    rest._prim=a._prim->urm;
    if (apare(a._prim->e,b)) {
        return reuniune(rest,b);
    }
    Lista r=reuniune(rest,b);
    PNod q=new Nod();
    q->e=a._prim->e;
    q->urm=r._prim;
    r._prim=q;
    return r;
}

bool isEmpty(Lista l) {
    return l._prim == NULL;
}

Lista copie(Lista l) {
    Lista r;
    if (isEmpty(l)) {
        r._prim=NULL;
        return r;
    }
    Lista rest;
    rest._prim=l._prim->urm;
    r=copie(rest);
    PNod q=new Nod();
    q->e=l._prim->e; // we isolate the first node of l
    q->urm=r._prim;
    r._prim=q;
    return r;
}

Lista creare(){
    Lista l;
    l._prim=creare_rec();
    return l;
}

void tipar_rec(PNod p){
   if (p!=NULL){
     cout<<p->e<<" ";
     tipar_rec(p->urm);
   }
}

void tipar(Lista l){
   tipar_rec(l._prim);
}

void distrug_rec(PNod p){
   if (p!=NULL){
     distrug_rec(p->urm);
     delete p;
   }
}

void distruge(Lista l) {
	//se elibereaza memoria alocata nodurilor listei
    distrug_rec(l._prim);
}

