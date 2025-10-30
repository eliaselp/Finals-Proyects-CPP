#include "Tanque.h"
#include <iostream>
using namespace std;
Tanque::Tanque(float Capacidad,string Estado,string TipoAbasto,string Material)
:Deposito(Capacidad,Estado,TipoAbasto)
{
    this->Material=Material;
}

Tanque::~Tanque()
{
    //dtor
}


string Tanque::getMaterial(){
    return this->Material;
}
//-------------------------------
string Tanque::DataDeposito(){
    string Data="";
    Data+="[#] Tipo: Tanque.\n";
    Data+=Deposito::DataDeposito();
    Data+="[#] Material: "+this->Material+"\n";
    return Data;
}
