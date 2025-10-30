#include "Fuerza.h"
#include <iostream>
using namespace std;
Fuerza::Fuerza(string Codigo,string FechaSalida,string Especialista,float CaballosFuerza)
:Motor(Codigo,FechaSalida,Especialista)
{
    this->CaballosFuerza=CaballosFuerza;
    this->setPrecioCosto();
}

Fuerza::~Fuerza()
{
    //dtor
}


/******* METODOS GETERS  ******/
float Fuerza::getCaballosFuerza(){
    return this->CaballosFuerza;
}

/******* METODOS OVERRIDE  **********/
string Fuerza::FichaTecnica(){
    string Ficha="";
    Ficha+="[#] Tipo: Fuerza.\n";
    Ficha+=Motor::FichaTecnica();
    Ficha+="[#] Caballos de Fuerza: "+to_string(this->CaballosFuerza);
    Ficha+="\n";
    return Ficha;
}
void Fuerza::setPrecioCosto(){
    this->PrecioCosto=(this->CaballosFuerza*5)-100*this->getRegreso();
    return;
}
