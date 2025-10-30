#include "Mobiliario.h"
#include <iostream>
using namespace std;
Mobiliario::Mobiliario(string Inventario,float CostoUnitario,string Estado,string Tipo,string Proveedor,int Explotacion,string Local)
:Medio(Inventario,CostoUnitario,Estado)
{
    this->Tipo=Tipo;
    this->Proveedor=Proveedor;
    this->Explotacion=Explotacion;
    this->Local=Local;
    this->setCostoReal();
}

Mobiliario::~Mobiliario()
{
    //dtor
}
string Mobiliario::getProveedor(){
    return this->Proveedor;
}
int Mobiliario::getExplotacion(){
    return this->Explotacion;
}
string Mobiliario::getLocal(){
    return this->Local;
}



void Mobiliario::setCostoReal(){
    this->CostoReal=(this->getCostoUnitario()*this->Explotacion);
    if(this->Local=="Aula")this->CostoReal+=20;
    if(this->Local=="Laboratorio")this->CostoReal+=30;
    if(this->Local=="Apartamento")this->CostoReal+=40;
    if(this->Local=="Oficina")this->CostoReal+=50;
    return;
}

void Mobiliario::INFO(){
    cout<<"[#] Medio: Mobiliario."<<endl;
    Medio::INFO();
    cout<<"[#] Tipo: "<<this->Tipo<<endl;
    cout<<"[#] Proveedor: "<<this->Proveedor<<endl;
    cout<<"[#] Anios de Explotacion: "<<this->Explotacion<<endl;
    cout<<"[#] Ubicacion: "<<this->Local<<endl;
    return;
}
