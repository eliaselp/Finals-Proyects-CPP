#include "Lujo.h"
#include <iostream>
using namespace std;
Lujo::Lujo(Motor* motor,int Plazas,float VMax,string FechaSalida,float CostoTapiceria)
:Vehiculo(motor,Plazas,VMax,FechaSalida)
{
    this->CostoTapiceria=CostoTapiceria;
    this->setPrecioVenta();
}

Lujo::~Lujo()
{
    //dtor
}


/******* METODOS GETERS  ********/
float Lujo::getCostoTapiceria(){
    return this->CostoTapiceria;
}



/******** Metodos Override ********/
string Lujo::FichaTecnica(){
    string Data=Vehiculo::FichaTecnica();
    Data+="[#] Costo de Tapiceria: "+to_string(this->CostoTapiceria);
    Data+="\n";
    Data+="Precio: "+to_string(this->PrecioVenta)+"\n";
    return Data;
}
void Lujo::setPrecioVenta(){
    this->PrecioVenta=(this->CostoTapiceria+this->getMotor()->getPrecioCosto())*10;
    return;
}
