#include "Correspondencia.h"
#include <iostream>
using namespace std;
Correspondencia::Correspondencia(string Nombre,string Direccion,string Remitente)
{
    this->Nombre=Nombre;
    this->Direccion=Direccion;
    this->Remitente=Remitente;
}

Correspondencia::~Correspondencia()
{
    //dtor
}







/******************************************************************/
/********** METODOS GETERS  **************************************/
/*********************************************************************/
string Correspondencia::getNombre(){
    return this->Nombre;
}
string  Correspondencia::getDireccion(){
    return this->Direccion;
}
string Correspondencia::getRemitente(){
    return this->Remitente;
}
float Correspondencia::getCosto(){
    return this->Costo;
}


/******************************************************************/
/********** METODOS DATA  **************************************/
/*********************************************************************/
void Correspondencia::DataCorrespondencia(){
    cout<<"[#] Nombre: "<<this->Nombre<<endl;
    cout<<"[#] Direccion: "<<this->Direccion<<endl;
    cout<<"[#] Nombre Remitente: "<<this->Remitente<<endl;
    return;
}
