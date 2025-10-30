#include "Lider.h"
#include <iostream>
using namespace std;
Lider::Lider(string Nombre,int Edad,string Sexo,float SalarioBasico,string CI,int Anios,int CantProyectos)
:Empleado(Nombre,Edad,Sexo,SalarioBasico,CI)
{
    this->Anios=Anios;
    this->CantProyectos=CantProyectos;
    this->setSueldo(0);
}

Lider::~Lider()
{
    //dtor
}

/***** METODOS GETERS ****/
int Lider::getAnios(){
    return this->Anios;
}
int Lider::getCantProyectos(){
    return this->CantProyectos;
}
//--------------------------------------------------------
void Lider::setSueldo(long PrecioProyecto){
    this->Sueldo=this->getSalarioBasico()+((10*PrecioProyecto)/100)+5*this->Anios;
    return;
}
void Lider::DataEmpleado(){
    Empleado::DataEmpleado();
    cout<<"[#] Anios de Experiencia: "<<this->Anios<<endl;
    cout<<"[#] Cantidad de Proyectos dirigidos: "<<this->CantProyectos<<endl;
    return;
}
