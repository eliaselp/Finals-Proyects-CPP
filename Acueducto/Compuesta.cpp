#include "Compuesta.h"
#include <iostream>
using namespace std;
Compuesta::Compuesta(float Capacidad,string Estado,string TipoAbasto,int CantCompartimientos)
:Cisterna(Capacidad,Estado,TipoAbasto)
{
    this->CantCompartimientos=CantCompartimientos;
}

Compuesta::~Compuesta()
{
    //dtor
}


int Compuesta::getCantCompartimientos(){
    return this->CantCompartimientos;
}
//---------------------------------
string Compuesta::DataDeposito(){
    string Data="[#] Tipo: Cisterna Compuesta.\n";
    Data+=Deposito::DataDeposito();
    Data+="[#] Cantidad de Compartimientos: "+to_string(this->CantCompartimientos)+"\n";
    return Data;
}
