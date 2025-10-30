#include "Equipo.h"
#include <iostream>
using namespace std;
Equipo::Equipo(string Estado,float Regimen)
{
    this->Estado=Estado;
    this->Regimen=Regimen;
}

Equipo::~Equipo()
{
    //dtor
}



string Equipo::getEstado(){
    return this->Estado;
}
float Equipo::getRegimen(){
    return this->Regimen;
}
//------------------------------
string Equipo::DataEquipo(){
    string Data="";
    Data+="[#] Estado: "+this->Estado+"\n";
    Data+="[#] Regimen: "+to_string(this->Regimen)+"\n";
    return Data;
}
