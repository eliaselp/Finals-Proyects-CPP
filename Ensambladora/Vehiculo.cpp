#include "Vehiculo.h"
#include <iostream>
using namespace std;
Vehiculo::Vehiculo(Motor* motor,int Plazas,float VMax,string FechaSalida)
{
    this->motor=motor;
    this->Plazas=Plazas;
    this->VMax=VMax;
    this->FechaSalida=FechaSalida;
    this->PrecioVenta=0;
}

Vehiculo::~Vehiculo()
{
    //dtor
}




/************   METODOS GETERS ******/
Motor* Vehiculo::getMotor(){
    return this->motor;
}
int Vehiculo::getPlazas(){
    return this->Plazas;
}
float Vehiculo::getVMax(){
    return this->VMax;
}
string Vehiculo::getFechaSalida(){
    return this->FechaSalida;
}
float Vehiculo::getPrecioVenta(){
        return this->PrecioVenta;
}
/******** METODOS VIRTUAL **/
string Vehiculo::FichaTecnica(){
    string Data="";
    Data+="Ficha Tecnica Motor.\n";
    Data+=motor->FichaTecnica();
    Data+="------------------------\n";
    Data+="[#] Plazas: "+to_string(this->Plazas);
    Data+="\n";
    Data+="[#] Velocidad Maxima: "+to_string(this->VMax);
    Data+="\n";
    Data+="[#] Fecha de Salida: "+this->FechaSalida+"\n";
    return Data;
}
