#include "Producto.h"
#include <iostream>
using namespace std;
Producto::Producto(string Codigo,string Nombre, float PrecioCosto, int Cant)
{
    this->Codigo=Codigo;
    this->Nombre=Nombre;
    this->PrecioCosto=PrecioCosto;
    this->Cant=Cant;
    this->PrecioVenta=0;
    this->Venta=0;
}

Producto::~Producto()
{
    //dtor
}
//**************************************************************
//**************************************************************
string Producto::getCodigo(){
    return this->Codigo;
}
string Producto::getNombre(){
    return this->Nombre;
}
float Producto::getPrecioCosto(){
    return this->PrecioCosto;
}
int Producto::getCant(){
    return this->Cant;
}
int Producto::getVenta(){
    return this->Venta;
}
float Producto::getPrecioVenta(){
    return this->PrecioVenta;
}
//****************************************************************
//****************************************************************
void Producto::setNombre(string Nombre){
    this->Nombre=Nombre;
    return;
}
void Producto::setCodigo(string Codigo){
    this->Codigo=Codigo;
    return;
}
void Producto::setPrecioCosto(float PrecioCosto){
    this->PrecioCosto=PrecioCosto;
    this->setPrecioVenta();
    return;
}
void Producto::setCant(int Cant){
    this->Cant=Cant;
    return;
}
void Producto::setVenta(int Venta){
    this->Venta=Venta;
    return;
}
//*****************************************************************
//****************************************************************
void Producto::DataProducto(){
    cout<<"[+] Nombre: "<<this->Nombre<<endl;
    cout<<"[+] Codigo: "<<this->Codigo<<endl;
    cout<<"[+] Precio de Costo: "<<this->PrecioCosto<<endl;
    cout<<"[+] Cantidad de Inventario: "<<this->Cant<<endl;
    cout<<"[+] Precio de Venta: "<<this->getPrecioVenta()<<endl;
    return;
}
