#include "Especial.h"
#include <iostream>
using namespace std;
Especial::Especial(string Nombre,string Apellido,string CI,string Grupo,int Anio,bool Proyecto,
                string NombreProyecto,int CantAsignaturas,bool AyudaFinanciera,int AnioRepetido,Asignatura* Desaprobada)
:Estudiante(Nombre,Apellido,CI,Grupo,Anio,Proyecto,NombreProyecto,CantAsignaturas,AyudaFinanciera)
{
    this->AnioRepetido=AnioRepetido;
    this->Desaprobada=Desaprobada;
    this->setEstipendio();
}

Especial::~Especial()
{
    //dtor
}




//-------------------------------------------------------
int Especial::getAnioRepetido(){
    return this->AnioRepetido;
}
Asignatura* Especial::getDesaprobada(){
    return Desaprobada;
}
//--------------------------------------------------
void Especial::DataEstudiante(){
    Estudiante::DataEstudiante();
    cout<<"[#] Asignatura Desaprobada: "<<this->Desaprobada->getNombre()<<endl;
    cout<<"[#] Anio Repetido: "<<this->AnioRepetido<<endl;
    return;
}
void Especial::setEstipendio(){
    this->Estipendio=50;
    if(this->getAyudaFinanciera()==true)this->Estipendio+=50;
    return;
}
