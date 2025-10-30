#include "Carta.h"
#include <iostream>
using namespace std;
Carta::Carta(string Nombre,string Direccion,string Remitente,string Fecha,bool Ext):Correspondencia(Nombre,Direccion,Remitente)
{
    this->Fecha=Fecha;
    this->Ext=Ext;
    this->CantDias=0;
    this->setCosto();
}

Carta::~Carta()
{
    //dtor
}




/******************************************************************/
/********** METODOS GETERS  **************************************/
/*********************************************************************/
string Carta::getFecha(){
    return this->Fecha;
}
bool Carta::getExt(){
    return this->Ext;
}







/******************************************************************/
/********** METODOS OVERRIDE  **************************************/
/*********************************************************************/
void Carta::DataCorrespondencia(){
    Correspondencia::DataCorrespondencia();
    cout<<"[#] Fecha: "<<this->Fecha;
    cout<<"[#] Exterior: ";
    if(this->Ext==true)cout<<"Si."<<endl;
    else cout<<"No."<<endl;
    cout<<"[#] Precio: "<<this->Costo<<endl;
}



void Carta::setCosto(){
    if(this->CantDias>10&&Ext==true)this->Costo=10;
    else if(this->CantDias>10&&Ext==false)this->Costo=5;
    if(this->CantDias<=10&&this->Ext==true)this->Costo==11;
    else if(this->CantDias<=10&&this->Ext==false)this->Costo=8;
    return;
}
