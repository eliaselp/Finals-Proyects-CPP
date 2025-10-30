#include "Empleado.h"
#include <iostream>
using namespace std;
Empleado::Empleado(string Nombre,int Edad,string Sexo,float SalarioBasico,string CI)
{
    this->Nombre=Nombre;
    this->Edad=Edad;
    this->Sexo=Sexo;
    this->SalarioBasico=SalarioBasico;
    this->CI=CI;
    this->Asociado=false;
}

Empleado::~Empleado()
{
    //dtor
}

/**** METODOS GETERS ****/
string Empleado::getNombre(){
    return this->Nombre;
}
int Empleado::getEdad(){
    return this->Edad;
}
string Empleado::getSexo(){
    return this->Sexo;
}
float Empleado::getSalarioBasico(){
    return this->SalarioBasico;
}
bool Empleado::getAsociado(){
    return this->Asociado;
}
float Empleado::getSueldo(){
    return this->Sueldo;
}
string Empleado::getCI(){
    return this->CI;
}


/********* METODOS VIRTUAL  **********/
void Empleado::DataEmpleado(){
    cout<<"[#] Nombre: "<<this->Nombre<<endl;
    cout<<"[#] Edad: "<<this->Edad<<endl;
    cout<<"[#] Sexo: "<<this->Sexo<<endl;
    cout<<"[#] Asociado a un Proyecto: ";
    if(this->Asociado==true)cout<<"Si"<<endl;
    else cout<<"No"<<endl;
    return;
}
