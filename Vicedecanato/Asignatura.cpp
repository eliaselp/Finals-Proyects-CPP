#include "Asignatura.h"
#include <iostream>
using namespace std;
Asignatura::Asignatura(string Nombre,float NotaFinal,int Anio,int Semestre)
{
    this->Nombre=Nombre;
    this->NotaFinal=NotaFinal;
    this->Anio=Anio;
    this->Semestre=Semestre;
}

Asignatura::~Asignatura()
{
    //dtor
}


string Asignatura::getNombre(){
    return this->Nombre;
}
float Asignatura::getNotaFinal(){
    return this->NotaFinal;
}
int Asignatura::getAnio(){
    return this->Anio;
}
int Asignatura::getSemestre(){
    return this->Semestre;
}




void Asignatura::DataAsignatura(){
    cout<<"[#] Asignatura: "<<this->Nombre<<endl;
    cout<<"[#] Nota Final: "<<this->NotaFinal<<endl;
    cout<<"[#] Anio que se Imparte: "<<this->Anio<<endl;
    cout<<"[#] Semestre: "<<this->Semestre<<endl;
    return;
}
