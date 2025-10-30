#include "Turbina.h"
#include <iostream>
using namespace std;
Turbina::Turbina(string Estado,float Regimen,float Fuerza)
:Equipo(Estado,Regimen)
{
    this->Fuerza=Fuerza;
}

Turbina::~Turbina()
{
    //dtor
}


float Turbina::getFuerza(){
    return this->Fuerza;
}
//----------------------------
string Turbina::DataEquipo(){
    string Data="[#] Tipo: Turbina.\n";
    Data+=Equipo::DataEquipo();
    Data+="[#] Fuerza: "+to_string(this->Fuerza)+"\n";
    return Data;
}
