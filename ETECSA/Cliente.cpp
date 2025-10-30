#include "Cliente.h"
#include <iostream>
using namespace std;
Cliente::Cliente(string Nombre, string Direccion, int CodigoProvincia,int Numero)
{
    this->Nombre=Nombre;
    this->Direccion=Direccion;
    this->CodigoProvincia=CodigoProvincia;
    this->Numero=Numero;
    this->Gasto=0;
    this->Estado="ACTIVO";
}

Cliente::~Cliente()
{
    //dtor
}


/*****************************************************************/
/************* METODOS GETERS ***************************/
/**************************************************/
string Cliente::getNombre(){
    return this->Nombre;
}
string Cliente::getDireccion(){
    return this->Direccion;
}
int Cliente::getCodigoProvincia(){
    return this->CodigoProvincia;
}
int Cliente::getNumero(){
    return this->Numero;
}
float Cliente::getGasto(){
    return this->Gasto;
}


/*****************************************************************/
/************* METODOS SETERS ***************************/
/**************************************************/
void Cliente::setGasto(float Gasto){
    this->Gasto=Gasto;
}



void Cliente::DataCliente(){
    cout<<"[#] Nombre: "<<this->Nombre<<endl;
    cout<<"[#] Direccion: "<<this->Direccion<<endl;
    cout<<"[#] Telefono: "<<this->CodigoProvincia<<"-"<<this->Numero<<endl;
    return;
}
