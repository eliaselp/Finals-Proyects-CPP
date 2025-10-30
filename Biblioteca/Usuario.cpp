#include "Usuario.h"
#include <iostream>
using namespace std;
Usuario::Usuario(string Nombre,string CI,string Direccion,string Tipo,string FechaVencimiento)
{
    this->Nombre=Nombre;
    this->CI=CI;
    this->Direccion=Direccion;
    this->Tipo=Tipo;
    this->FechaVencimiento=FechaVencimiento;
    this->PesoAcumulado=0;
}

Usuario::~Usuario()
{
    //dtor
}




/****************************************************/
/********   METODOS GETERS ***********************/
/*********************************************/
string Usuario::getNombre(){
    return this->Nombre;
}
string Usuario::getCI(){
    return this->CI;
}
string Usuario::getDireccion(){
    return this->Direccion;
}
string Usuario::getTipo(){
    return this->Tipo;
}
string Usuario::getFechaVencimiento(){
    return this->FechaVencimiento;
}



/****************************************************/
/********   METODOS DATA ***********************/
/*********************************************/
string Usuario::DataUsuario(){
    string Data="";
    Data+="[#] Nombre: "+this->Nombre+"\n";
    Data+="[#] Carnet de Identidad: "+this->CI+"\n";
    Data+="[#] Direccion: "+this->Direccion+"\n";
    Data+="[#] Tipo de Cliente: "+this->Tipo+"\n";
    if(this->Tipo=="EVENTUAL"){
        Data+="[#] Tipo: Eventual.\n";
        Data+="[#] Fecha de Vencimiento: "+this->FechaVencimiento+"\n";
    }else{
        Data+="[#] Tipo: Permanente.\n";
    }
    Data+="--------------------------------\n";
    return Data;
}
