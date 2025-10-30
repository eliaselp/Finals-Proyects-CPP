#include "Guagua.h"
#include <iostream>
using namespace std;
Guagua::Guagua(string Matricula, int CantAsientos, string Chofer,int CantPisos)
:Vehiculo(Matricula,CantAsientos,Chofer)
{
    this->CantPisos=CantPisos;
}

Guagua::~Guagua()
{
    //dtor
}


int Guagua::getCantPisos(){
    return this->CantPisos;
}

/*********************/
void Guagua::Imprimir(){
    cout<<"[#] Tipo: Omnibus."<<endl;
    Vehiculo::Imprimir();
    cout<<"[#] Cantidad de Pisos: "<<this->CantPisos<<endl;
}
