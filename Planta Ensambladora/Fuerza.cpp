#include "Fuerza.h"

Fuerza::Fuerza(string Codigo, string FechaSalida, string Especialista, int CaballosFuerza):Motor(Codigo, FechaSalida,Especialista)
{
    this->CaballosFuerza=CaballosFuerza;
    //ctor
}

Fuerza::~Fuerza()
{
    //dtor
}
int Fuerza::getCaballosFuerza(){
    return this->CaballosFuerza;
}
void Fuerza::FichaTecnica(){
    Motor::FichaTecnica();
    cout<<"[+] Caballos de Fuerza: "<<this->CaballosFuerza<<endl;
    return;
}
float Fuerza::Costo(){
    float C=(this->CaballosFuerza*5)-(100-this->getCantRegreso());
    return C;
}
