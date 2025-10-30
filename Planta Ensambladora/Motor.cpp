#include "Motor.h"
#include <iostream>
using namespace std;
Motor::Motor(string Codigo, string FechaSalida, string Especialista)
{
    this->Codigo=Codigo;
    this->FechaSalida=FechaSalida;
    this->Especialista=Especialista;
    this->CantRegreso=0;
    this->siguiente=NULL;
}

Motor::~Motor(){

}

string Motor::getCodigo(){
    return this->Codigo;
}
string Motor::getFechaSalida(){
    return this->FechaSalida;
}
string Motor::getEspecialista(){
    return this->Especialista;
}
int Motor::getCantRegreso(){
    return this->CantRegreso;
}
//*********************************************************************************
//*********************************************************************************
void Motor::setCantRegreso(){
    this->CantRegreso++;
}
//*********************************************************************************
//*********************************************************************************

void Motor::FichaTecnica(){
    cout<<"[+] Codigo: "<<this->Codigo<<endl;
    cout<<"[+] Fecha de Salida: "<<this->FechaSalida<<endl;
    cout<<"[+] Nombre del Especialista encargado: "<<this->Especialista<<endl;
    cout<<"[+] Cantidad de regresos a la Planta Ensambladora: "<<this->CantRegreso<<endl;
    return;
}
