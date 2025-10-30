#include "Deposito.h"
#include <iostream>
using namespace std;
Deposito::Deposito(float Capacidad,string Estado,string TipoAbasto)
{
    this->Capacidad=Capacidad;
    this->Estado=Estado;
    this->TipoAbasto=TipoAbasto;
}

Deposito::~Deposito()
{
    //dtor
}

float Deposito::getCapacidad(){
    return this->Capacidad;
}
string Deposito::getEstado(){
    return this->Estado;
}
string Deposito::getTipoAbasto(){
    return this->TipoAbasto;
}
//--------------------------------------
string Deposito::DataDeposito(){
    string Data="";
    Data+="[#] Capacidad: "+to_string(this->Capacidad)+="\n";
    Data+="[#] Estado: "+this->Estado+"\n";
    Data+="[#] Tipo de Abasto: "+this->TipoAbasto+"\n";
    return Data;
}
