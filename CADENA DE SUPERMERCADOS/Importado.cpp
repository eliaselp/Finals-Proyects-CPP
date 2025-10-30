#include "Importado.h"
#include <iostream>
using namespace std;
Importado::Importado(string Codigo,string Nombre, float PrecioCosto, int Cant, string Pais, float USD):Producto(Codigo,Nombre,PrecioCosto,Cant)
{
    this->Pais=Pais;
    this->USD=USD;
    this->setPrecioVenta();
}

Importado::~Importado()
{
    //dtor
}

//******************************************************
//******************************************************
string Importado::getPais(){
    return this->Pais;
}
float Importado::getUSD(){
    return this->USD;
}
//*****************************************************
//*****************************************************
void Importado::DataProducto(){
    Producto::DataProducto();
    cout<<"[+] Pais: "<<this->Pais<<endl;
    cout<<"[+] Inversion en USD: "<<this->USD<<endl;
    return;
}
void Importado::setPrecioVenta(){
    this->PrecioVenta=(this->getPrecioCosto())+((5*this->getPrecioCosto())/100)+(27*this->USD);
    return;
}
