#include "Alta.h"
#include<iostream>
using namespace std;
Alta::Alta(string Codigo, string FechaSalida, string Especialista,float MaxRevMin, float Consumo):Motor(Codigo, FechaSalida,Especialista)
{
    this->MaxRevMin=MaxRevMin;
    this->Consumo=Consumo;
}

Alta::~Alta(){

}

float Alta::getMaxRevMin(){
    return this->MaxRevMin;
}
float Alta::getConsumo(){
    return this->Consumo;
}
float Alta::Costo(){
    float C=(this->MaxRevMin*1.5)-(100*this->getCantRegreso());
    return C;
}
 void Alta::FichaTecnica(){
    Motor::FichaTecnica();
    cout<<"[+] Maxima Revoluciones por Minuto: "<<this->MaxRevMin<<endl;
    cout<<"[+] Consumo: "<<this->Consumo<<endl;
    return;
 }
