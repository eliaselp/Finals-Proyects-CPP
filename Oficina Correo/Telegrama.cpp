#include "Telegrama.h"
#include <iostream>
using namespace std;
Telegrama::Telegrama(string Nombre,string Direccion,string Remitente,int CantPalabras,float Impuesto)
:Correspondencia(Nombre,Direccion,Remitente)
{
    this->CantPalabras=CantPalabras;
    this->Impuesto=Impuesto;
    this->setCosto();
}

Telegrama::~Telegrama()
{
    //dtor
}





/******************************************************************/
/********** METODOS GETERS  **************************************/
/*********************************************************************/
int Telegrama::getCantPalabras(){
    return this->CantPalabras;
}
float Telegrama::getImpuesto(){
    return this->Impuesto;
}





/******************************************************************/
/********** METODOS OVERRIDE  **************************************/
/*********************************************************************/
void Telegrama::DataCorrespondencia(){
    Correspondencia::DataCorrespondencia();
    cout<<"[#] Cantidad de Palabras: "<<this->CantPalabras<<endl;
    cout<<"[#] Impuesto: "<<this->Impuesto<<endl;
    cout<<"[#] Precio: "<<this->Costo<<endl;
    return;
}


void Telegrama::setCosto(){
    this->Costo=this->CantPalabras*0.10*this->Impuesto;
    return;
}
