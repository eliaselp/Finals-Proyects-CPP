#include "Alta.h"
#include <iostream>
using namespace std;
Alta::Alta(string Codigo,string FechaSalida,string Especialista,float MaxRPM,float Consumo)
:Motor(Codigo,FechaSalida,Especialista)
{
    this->MaxRPM=MaxRPM;
    this->Consumo=Consumo;
    this->setPrecioCosto();
}

Alta::~Alta()
{
    //dtor
}


/******* METODOS GETERS ********/
float Alta::getMaxRPM(){
    return this->MaxRPM;
}
float Alta::getConsumo(){
    return this->Consumo;
}
//------------------------------------------
void Alta::setPrecioCosto(){
    this->PrecioCosto=(this->MaxRPM*1.5)+this->Consumo-(100*this->getRegreso());
    return;
}
string Alta::FichaTecnica(){
    string Ficha="";
    Ficha+="[#] Tipo: Alta.\n";
    Ficha+=Motor::FichaTecnica();
    Ficha+="[#] Maximas Revoluciones por Minuto: "+to_string(this->MaxRPM);
    Ficha+="\n";
    Ficha+="[#] Consumo: "+to_string(this->Consumo);
    Ficha+="\n";
    return Ficha;
}
