#include "Guia.h"
#include <iostream>
using namespace std;
Guia::Guia(string Nombre)
:Persona(Nombre)
{
    this->CantExc=0;
}

Guia::~Guia()
{
    //dtor
}


void Guia::InfoPersonal(){
    cout<<"[#] Tipo: Guia."<<endl;
    Persona::InfoPersonal();
    return;
}
