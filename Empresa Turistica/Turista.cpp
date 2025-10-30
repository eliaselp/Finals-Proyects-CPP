#include "Turista.h"
#include <iostream>
using namespace std;
Turista::Turista(string Nombre,string Sexo, string Passport)
:Persona(Nombre)
{
    this->Sexo=Sexo;
    this->Passport=Passport;
}

Turista::~Turista()
{
    //dtor
}

/************/
string Turista::getSexo(){
    return this->Sexo;
}
string Turista::getPassport(){
    return this->Passport;
}
/************/
void Turista::InfoPersonal(){
    cout<<"[#] Tipo: Turista."<<endl;
    Persona::InfoPersonal();
    cout<<"[#] Sexo: "<<this->Sexo<<endl;
    cout<<"[#] Passport: "<<this->Passport<<endl;
    return;
}
