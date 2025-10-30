#include "Nacional.h"

Nacional::Nacional(string Codigo,string Nombre, float PrecioCosto, int Cant, string Empresa):Producto(Codigo,Nombre,PrecioCosto,Cant)
{
    this->Empresa=Empresa;
    this->setPrecioVenta();
}

Nacional::~Nacional()
{
    //dtor
}
//*****************************************************************************************
//*****************************************************************************************
string Nacional::getEmpresa(){
    return this->Empresa;
}
string Nacional::getPais(){
    return "";
}
float Nacional::getUSD(){
    return 0;
}
//*****************************************************************
//****************************************************************
void Nacional::DataProducto(){
    Producto::DataProducto();
    return;
}

void Nacional::setPrecioVenta(){
    this->PrecioVenta=(this->getPrecioCosto())+((this->getPrecioCosto()*5)/100);
    return;
}

