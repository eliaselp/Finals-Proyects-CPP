#include "Llamada.h"
#include <iostream>
using namespace std;
Llamada::Llamada(int Duracion, Cliente* Emisor,int NumeroReceptor,int Hora,int Minuto,string Fecha)
{
    this->Fecha=Fecha;
    this->Duracion=Duracion;
    this->Emisor=Emisor;
    this->NumeroReceptor=NumeroReceptor;
    this->Hora=Hora;
    this->Minuto=Minuto;
}

Llamada::~Llamada()
{
    //dtor
}




/*****************************************************************************************/
/******* METODOS GETERS *********************************/
/***************************************************/
float Llamada::getPrecio(){
    return this->Precio;
}
int Llamada::getDuracion(){
    return this->Duracion;
}
Cliente* Llamada::getEmisor(){
    return this->Emisor;
}
int Llamada::getNumeroReceptor(){
    return this->NumeroReceptor;
}
int Llamada::getHora(){
    return this->Hora;
}
int Llamada::getMinuto(){
    return this->Minuto;
}


/*****************************************************************************************/
/******* METODOS SETERS *********************************/
/***************************************************/
void Llamada::setPrecio(){
    this->Precio=this->Duracion*this->ValorLlamada();
    return;
}






/*****************************************************************************************/
/******* METODOS DATA *********************************/
/***************************************************/
void Llamada::DataLlamada(){
    cout<<"[#] Fecha: "<<this->Fecha<<endl;
    cout<<"[#] Hora: "<<this->Hora<<":"<<this->Minuto<<endl;
    cout<<"[#] Duracion: "<<this->Duracion<<endl;
    cout<<"[#] Numero Emisor: "<<this->Emisor->getCodigoProvincia()<<"-"<<this->Emisor->getNumero()<<endl;
    return;
}
