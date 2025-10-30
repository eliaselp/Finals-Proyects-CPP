#include "Bomba.h"
#include <iostream>
using namespace std;
Bomba::Bomba(string Estado,float Regimen,float Tiempo)
:Equipo(Estado,Regimen)
{
    this->Tiempo=Tiempo;
}

Bomba::~Bomba()
{
    //dtor
}

float Bomba::getTiempo(){
    return this->Tiempo;
}


//-------------------------------
string Bomba::DataEquipo(){
    string Data="[#] Tipo: Bomba.\n";
    Data+=Equipo::DataEquipo();
    Data+="[#] Tiempo: "+to_string(this->Tiempo)+"\n";
    return Data;
}
