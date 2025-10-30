#include "Medio.h"
#include <iostream>
using namespace std;
Medio::Medio(string Inventario,float CostoUnitario,string Estado)
{
    this->Inventario=Inventario;
    this->CostoUnitario=CostoUnitario;
    this->Estado=Estado;
}

Medio::~Medio()
{
    //dtor
}

/********/
string Medio::getInventario(){
    return this->Inventario;
}
float Medio::getCostoUnitario(){
    return this->CostoUnitario;
}
string Medio::getEstado(){
    return this->Estado;
}
float Medio::getCostoReal(){
    return this->CostoReal;
}
string Medio::getTipo(){
    return this->Tipo;
}


void Medio::INFO(){
    cout<<"[#] Inventario: "<<this->Inventario<<endl;
    cout<<"[#] Costo Unitario: "<<this->CostoUnitario<<endl;
    cout<<"[#] Costo Real: "<<this->CostoReal<<endl;
    cout<<"[#] Estado: "<<this->Estado<<endl;
    return;
}
