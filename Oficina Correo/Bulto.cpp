#include "Bulto.h"
#include <iostream>
using namespace std;
Bulto::Bulto(string Nombre,string Direccion,string Remitente,float Peso,int Urgencia)
:Correspondencia(Nombre,Direccion,Remitente)
{
    this->Peso=Peso;
    this->Urgencia=Urgencia;
    this->setCosto();
}

Bulto::~Bulto()
{
    //dtor
}





/******************************************************************/
/********** METODOS GETERS  **************************************/
/*********************************************************************/
float Bulto::getPeso(){
    return this->Peso;
}
int Bulto::getUrgencia(){
    return this->Urgencia;
}





/******************************************************************/
/********** METODOS OVERRIDE  **************************************/
/*********************************************************************/
void Bulto::DataCorrespondencia(){
    Correspondencia::DataCorrespondencia();
    cout<<"[#] Peso: "<<this->Peso<<endl;
    cout<<"[#] Urgencia: ";
    if(this->Urgencia==1){
        cout<<"Urgente."<<endl;
    }else if(this->Urgencia==2){
        cout<<"Medio."<<endl;
    }else if(this->Urgencia==3){
        cout<<"Indiferente."<<endl;
    }
    cout<<"[#] Precio: "<<this->Costo<<endl;
}


void Bulto::setCosto(){
    this->Costo=this->Peso*4;
    if(this->Urgencia==1)this->Costo+=10;
    else if(this->Urgencia==2)this->Costo+=8;
    return;
}
