#include "Persona.h"
#include <iostream>
using namespace std;
Persona::Persona(string Nombre)
{
    this->Nombre=Nombre;
}

Persona::~Persona()
{
    //dtor
}

string Persona::getNombre(){
    return this->Nombre;
}


/***********/
void Persona::InfoPersonal(){
    cout<<"[#] Nombre: "<<this->Nombre<<endl;
    return;
}
