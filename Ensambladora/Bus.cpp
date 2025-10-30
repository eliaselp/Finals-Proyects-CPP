#include "Bus.h"
#include <iostream>
using namespace std;
Bus::Bus(Motor* motor,int Plazas,float VMax,string FechaSalida,int CantPuertas)
:Vehiculo(motor,Plazas,VMax,FechaSalida)
{
    this->CantPuertas=CantPuertas;
    this->setPrecioVenta();
}

Bus::~Bus()
{
    //dtor
}


/****** METODOS GETERS ******/
int Bus::getCantPuertas(){
    return this->CantPuertas;
}



/********* METODOS OVERRIDE ****/
string Bus::FichaTecnica(){
    string Data=Vehiculo::FichaTecnica();
    Data+="[#] Cantidad de Puertas: "+to_string(this->CantPuertas);
    Data+="\n";
    return Data;
}
void Bus::setPrecioVenta(){
    this->PrecioVenta=((this->CantPuertas*1.5)+this->getMotor()->getPrecioCosto())*3;
    return;
}
