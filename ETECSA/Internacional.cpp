#include "Internacional.h"
#include <iostream>
using namespace std;
Internacional::Internacional(int Duracion, Cliente* Emisor,int NumeroReceptor,int Hora,int Minuto,string Fecha,float Tarifa,int CodigoTeleseleccionInternacional,int CodigoPais,int CodigoProvinciaReceptor)
:Llamada(Duracion,Emisor,NumeroReceptor,Hora,Minuto,Fecha)
{
    this->Tarifa=Tarifa;
    this->CodigoTeleseleccionInternacional=CodigoTeleseleccionInternacional;
    this->CodigoPais=CodigoPais;
    this->CodigoProvinciaReceptor=CodigoProvinciaReceptor;
    this->setPrecio();
}

Internacional::~Internacional()
{
    //dtor
}

/****************************************************************/
/********** METODOS GETERS   *********************/
/**************************************/
float Internacional::getTarifa(){
    return this->Tarifa;
}
int Internacional::getCodigoTeleseleccionInternacional(){
    return this->CodigoTeleseleccionInternacional;
}
int Internacional::getCodigoPais(){
    return this->CodigoPais;
}
int Internacional::getCodigoProvinciaReceptor(){
    return this->CodigoProvinciaReceptor;
}

/*******************************************************************/
/********** METODOS Override   *********************/
/**************************************/
float Internacional::ValorLlamada(){
    float C=this->Tarifa;
    if(this->getHora()<22&&this->getHora()>05)C+=0.50;
    return C;
}

void Internacional::DataLlamada(){
    Llamada::DataLlamada();
    cout<<"[#] Numero Receptor: "<<this->CodigoTeleseleccionInternacional<<"-"<<this->CodigoProvinciaReceptor<<"-"<<this->getNumeroReceptor()<<endl;
    cout<<"[#] Costo: "<<this->getPrecio();
    return;
}
