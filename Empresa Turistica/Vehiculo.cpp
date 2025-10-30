#include "Vehiculo.h"
#include <iostream>
using namespace std;
Vehiculo::Vehiculo(string Matricula, int CantAsientos, string Chofer)
{
    this->Matricula=Matricula;
    this->CantAsientos=CantAsientos;
    this->Chofer=Chofer;
}

Vehiculo::~Vehiculo()
{
    //dtor
}

/***********************/
string Vehiculo::getMatricula(){
    return this->Matricula;
}
int Vehiculo::getCantAsientos(){
    return this->CantAsientos;
}
string Vehiculo::getChofer(){
    return this->Chofer;
}


/***********************/
void Vehiculo::Imprimir(){
    cout<<"[#] Matricula: "<<this->Matricula<<endl;
    cout<<"[#] Cantidad de Asientos: "<<this->CantAsientos<<endl;
    cout<<"[#] Chofer: "<<this->Chofer<<endl;
}
