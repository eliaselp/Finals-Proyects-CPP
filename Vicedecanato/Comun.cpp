#include "Comun.h"
#include <iostream>
Comun::Comun(string Nombre,string Apellido,string CI,string Grupo,int Anio,bool Proyecto,
                       string NombreProyecto,int CantAsignaturas,bool AyudaFinanciera)
:Estudiante(Nombre,Apellido,CI,Grupo,Anio,Proyecto,NombreProyecto,CantAsignaturas,AyudaFinanciera)
{
    this->setEstipendio();
}

Comun::~Comun()
{
    //dtor
}



void Comun::DataEstudiante(){
    Estudiante::DataEstudiante();
    return;
}
void Comun::setEstipendio(){
    this->Estipendio=50;
    if(this->getAyudaFinanciera()==true)this->Estipendio+=50;
    return;
}
