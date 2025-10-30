#include "Carro.h"
#include <iostream>
Carro::Carro(string Matricula, int CantAsientos, string Chofer)
:Vehiculo(Matricula,CantAsientos,Chofer)
{
    //ctor
}

Carro::~Carro()
{
    //dtor
}

/******************/
void Carro::Imprimir(){
    cout<<"[#] Tipo: Carro."<<endl;
    Vehiculo::Imprimir();
    return;
}
