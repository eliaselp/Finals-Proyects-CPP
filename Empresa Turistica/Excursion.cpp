#include "Excursion.h"
#include <iostream>
using namespace std;
Excursion::Excursion(int NumeroExc,string NombreExc,float PrecioxP, Guia* guia, Vehiculo* Trans)
{
    this->NumeroExc=NumeroExc;
    this->NombreExc=NombreExc;
    this->PrecioxP=PrecioxP;
    this->CantRealP=0;
    this->guia=guia;
    this->Trans=Trans;
    this->ListaPersonas=new Persona*[Trans->getCantAsientos()];
    if(guia!=NULL){
        guia->CantExc++;
        this->Guiada=true;
    }else Guiada=false;
}

Excursion::~Excursion()
{
    //dtor
}

int Excursion::getNumeroExc(){
    return this->NumeroExc;
}
string Excursion::getNombreExc(){
    return this->NombreExc;
}
float Excursion::getPrecioxP(){
    return this->PrecioxP;
}
int Excursion::getCantRealP(){
    return this->CantRealP;
}
Persona* Excursion::getListaPersonas(int n){
    return this->ListaPersonas[n-1];
}
bool Excursion::getGuiada(){
    return this->Guiada;
}
Guia* Excursion::getguia(){
    return this->guia;
}
Vehiculo* Excursion::getTrans(){
    return this->Trans;
}

void Excursion::AggTurista(Turista* nuevo){
    this->ListaPersonas[this->CantRealP]=nuevo;
    this->CantRealP++;
}


float Excursion::PrecioExc(){
    float Precio=this->PrecioxP*this->CantRealP;
    if(dynamic_cast<Carro*>(this->Trans)){
        Precio+=((20*Precio)/100);
    }else{
        Precio+=((50*Precio)/100);
    }
    if(this->Guiada==true)Precio+=100;
    return Precio;
}

void Excursion::INFO(){
    cout<<"[#] Numero de Excurcion: "<<this->NumeroExc<<endl;
    cout<<"[#] Nombre de Excurcion: "<<this->NombreExc<<endl;
    cout<<"[#] Precio por Persona: "<<this->PrecioxP<<endl;
    cout<<"[#] Capacidad Total: "<<this->Trans->getCantAsientos()<<endl;
    cout<<"[#] Capacidades Disponibles: "<<this->Trans->getCantAsientos()-this->CantRealP<<endl;
    return;
}

