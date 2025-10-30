#include "Motor.h"
#include <iostream>
using namespace std;
Motor::Motor(string Codigo,string FechaSalida,string Especialista)
{
    this->Codigo=Codigo;
    this->FechaSalida=FechaSalida;
    this->Especialista=Especialista;
    this->Regreso=0;
    this->PrecioCosto=0;
}

Motor::~Motor()
{
    //dtor
}


/***********  METODOS GETERS **************/
string Motor::getCodigo(){
    return this->Codigo;
}
string Motor::getFechaSalida(){
    return this->FechaSalida;
}
string Motor::getEspecialista(){
    return this->Especialista;
}
int Motor::getRegreso(){
    return this->Regreso;
}
float Motor::getPrecioCosto(){
    return this->PrecioCosto;
}
void Motor::pushRegreso(){
    this->Regreso++;
    this->setPrecioCosto();
    return;
}

/********* METODOS VIRTUAL **********/
string Motor::FichaTecnica(){
    string Ficha="";
    Ficha+="[#] Codigo: "+this->Codigo+"\n";
    Ficha+="[#] Fecha de Salida del Taller: "+this->FechaSalida+"\n";
    Ficha+="[#] Especialista: "+this->Especialista+"\n";
    Ficha+="[#] Cantidad de Regresos: "+to_string(this->Regreso);
    Ficha+="\n";
    return Ficha;
}
