#include "Deportivo.h"
#include <iostream>
using namespace std;
Deportivo::Deportivo(Motor* motor,int Plazas,float VMax,string FechaSalida,int CantVelocidades,bool CambioUniversal)
:Vehiculo(motor,Plazas,VMax,FechaSalida)
{
    this->CantVelocidades=CantVelocidades;
    this->CambioUniversal=CambioUniversal;
    this->setPrecioVenta();
}

Deportivo::~Deportivo()
{
    //dtor
}



/******* METODOS GETERS *************/
int Deportivo::getCantVelocidades(){
    return this->CantVelocidades;
}
bool Deportivo::getCambioUniversal(){
    return this->CambioUniversal;
}



/********METODOS OVERRIDE **********/
string Deportivo::FichaTecnica(){
    string Data=Vehiculo::FichaTecnica();
    Data+="[#] Cantidad de Velocidades: "+to_string(this->CantVelocidades);
    Data+="\n";
    Data+="[#] Cambio Universal: ";
    if(this->CambioUniversal==true)Data+="Si.\n";
    else if(this->CambioUniversal==false)Data+="No.\n";
    return Data;
}
void Deportivo::setPrecioVenta(){
    this->PrecioVenta=((this->CantVelocidades*2)+this->getMotor()->getPrecioCosto());
    if(this->CambioUniversal==true)this->PrecioVenta+=1000;
    return;
}
