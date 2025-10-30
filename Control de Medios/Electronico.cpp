#include "Electronico.h"
#include <iostream>
using namespace std;
Electronico::Electronico(string Inventario,float CostoUnitario,string Estado,string Tipo,string Marca,string Proveedor,int Garantia)
:Medio(Inventario,CostoUnitario,Estado)
{
    this->Tipo=Tipo;
    this->Marca=Marca;
    this->Proveedor=Proveedor;
    this->Garantia=Garantia;
    this->setCostoReal();
}

Electronico::~Electronico()
{
    //dtor
}


/******/
string Electronico::getMarca(){
    return this->Marca;
}
string Electronico::getProveedor(){
    return this->Proveedor;
}
int Electronico::getGarantia(){
    return this->Garantia;
}


void Electronico::setCostoReal(){
    this->CostoReal=this->getCostoUnitario()*this->Garantia;
    return;
}
void Electronico::INFO(){
    cout<<"[#] Medio: Electronico."<<endl;
    Medio::INFO();
    cout<<"[#] Tipo: "<<this->Tipo<<endl;
    cout<<"[#] Marca: "<<this->Marca<<endl;
    cout<<"[#] Proveedor: "<<this->Proveedor<<endl;
    cout<<"[#] Garantia: "<<this->Garantia<<" Anios."<<endl;
    return;
}
