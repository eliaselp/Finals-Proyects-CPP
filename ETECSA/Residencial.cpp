#include "Residencial.h"
#include <iostream>
using namespace std;
Residencial::Residencial(string Nombre, string Direccion, int CodigoProvincia,int Numero,int CI):Cliente(Nombre,Direccion,CodigoProvincia,Numero)
{
    this->Matutino=false;
    this->Rastreo=false;
    this->HoraMatutino="";
    this->CI=CI;
}

Residencial::~Residencial()
{
    //dtor
}





/*****************************************************************/
/************* METODOS GETERS ***************************/
/**************************************************/

bool Residencial::getMatutino(){
    return this->Matutino;
}
bool Residencial::getRastreo(){
    return this->Rastreo;
}
string Residencial::getHoraMatutino(){
    return this->HoraMatutino;
}
int Residencial::getCI(){
    return this->CI;
}






/*****************************************************************/
/************* METODOS SETERS ***************************/
/**************************************************/
void Residencial::setMatutino(bool Matutino){
    this->Matutino=Matutino;
}
void Residencial::setRastreo(bool Rastreo){
    this->Rastreo=Rastreo;
}
void Residencial::setHoraMatutino(string HoraMatutino){
    this->HoraMatutino=HoraMatutino;
}



void Residencial::DataCliente(){
    Cliente::DataCliente();
    if(this->Matutino==true){
        cout<<"Servicio Matutino: "<<this->HoraMatutino<<endl;
    }
    cout<<"Servicio de Rastreo de Llamadas: ";
    if(this->Rastreo==true){
        cout<<"Activado."<<endl;
    }else{
        cout<<"Desactivado."<<endl;
    }
    return;
}
