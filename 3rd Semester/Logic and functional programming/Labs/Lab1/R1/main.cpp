#include "lista.h"
#include <iostream>

int main()
{
   // Lista l;
   // l=creare();
   // tipar(l);
   std::cout<<"List A:\n ";
   Lista a=creare();
   std::cout<<"List B:\n ";
   Lista b=creare();
   Lista sa=transformaListaInSet(a);
   Lista sb=transformaListaInSet(b);
   Lista u=reuniune(sa,sb);
   std::cout<<"List A transformed in Set: ";
   tipar(sa); std::cout<<'\n';
   std::cout<<"List B transformed in Set: ";
   tipar(sb); std::cout<<'\n';
   std::cout<<"Union of set A and set B: ";
   tipar(u); std::cout<<'\n';
   distruge(a);
   distruge(b);
   distruge(sa);
   distruge(sb);
   distruge(u);
   return 0;
}
