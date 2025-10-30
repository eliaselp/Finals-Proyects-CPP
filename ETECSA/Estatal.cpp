#include "Estatal.h"
#include <iostream>
using namespace std;
Estatal::Estatal(string Nombre, string Direccion, int CodigoProvincia,int Numero,bool Arrendada):Cliente(Nombre,Direccion,CodigoProvincia,Numero)
{
    this->Arrendada=Arrendada;
}

Estatal::~Estatal()
{
    //dtor
}



/*****************************************************************/
/************* METODOS GETERS ***************************/
/**************************************************/
bool Estatal::getArrendada(){
    return this->Arrendada;
}





/*****************************************************************/
/************* METODOS SETERS ***************************/
/**************************************************/
void Estatal::setArrendada(bool Arrendada){
    this->Arrendada=Arrendada;
}


void Estatal::DataCliente(){
    Cliente::DataCliente();
    cout<<"[#] Servicio Arrendado de Datos: ";
    if(this->Arrendada==true){
        cout<<"Si."<<endl;
    }else{
        cout<<"No."<<endl;
    }
    return;
}





