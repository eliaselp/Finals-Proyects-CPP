#include "Trabajo.h"
#include <iostream>
using namespace std;
Trabajo::Trabajo(string Codigo, string FechaSalida, string Especialista, bool Artesanal):Motor(Codigo,FechaSalida,Especialista)
{
    this->Artesanal=Artesanal;
}

Trabajo::~Trabajo()
{
    //dtor
}

bool Trabajo::getArtesanal(){
    return this->Artesanal;
}
void Trabajo::setArtesanal(){
    this->Artesanal=false;
}
void Trabajo::FichaTecnica(){
    Motor::FichaTecnica();
    cout<<"[+] Artesanal: ";
    if(Artesanal==true)cout<<"Si."<<endl;
    else cout<<"No."<<endl;
    return;
}
float Trabajo::Costo(){
    float C=1000-(100*this->getCantRegreso());
    if(this->getArtesanal()==true){
        C=C*10;
    }
    return C;
}
