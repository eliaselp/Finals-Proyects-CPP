#include "Ayudante.h"
#include <iostream>
using namespace std;
Ayudante::Ayudante(string Nombre,string Apellido,string CI,string Grupo,int Anio,bool Proyecto,
                       string NombreProyecto,int CantAsignaturas,bool AyudaFinanciera,int AniosImpartidos,int CantAsignaturasImpartidas)
:Estudiante(Nombre,Apellido,CI,Grupo,Anio,Proyecto,NombreProyecto,CantAsignaturas,AyudaFinanciera)
{
    this->AniosImpartidos=AniosImpartidos;
    this->CantAsignaturasImpartidas=CantAsignaturasImpartidas;
    for(int i=0;i<this->CantAsignaturasImpartidas;i++){
        system("cls");
        string Nombre;
        float NotaFinal;
        int Anio;
        int Semestre;
        fflush(stdin);cout<<"[+] Asignatura: ";getline(cin,Nombre);
        fflush(stdin);cout<<"[+] Nota Final: ";cin>>NotaFinal;
        cout<<"[+] Anio: ";cin>>Anio;
        cout<<"[+] Semestre: ";cin>>Semestre;
        Asignatura* nueva=new Asignatura(Nombre,NotaFinal,Anio,Semestre);
        this->AsignaturasImpartidas[i]=nueva;
    }
}

Ayudante::~Ayudante()
{
    //dtor
}



int Ayudante::getAniosImpartidos(){
    return this->AniosImpartidos;
}
Asignatura* Ayudante::getAsignaturasImpartidas(int n){
    return this->AsignaturasImpartidas[n-1];
}
int Ayudante::getCantAsignaturasImpartidas(){
    return this->CantAsignaturasImpartidas;
}
//----------------------------------------------
void Ayudante::DataEstudiante(){
    Estudiante::DataEstudiante();
    cout<<"[#] Anios Impartidos: "<<this->AniosImpartidos<<endl;
    cout<<"[#] Cantidad de Asignaturas Impartidas: "<<this->CantAsignaturasImpartidas<<endl;
    cout<<"[#] Asiganturas Impartidas: "<<endl;
    for(int i=0;i<this->CantAsignaturasImpartidas;i++){
        cout<<"["<<i+1<<"]: "<<this->AsignaturasImpartidas[i]->getNombre()<<endl;
    }
}
void Ayudante::setEstipendio(){
    this->Estipendio=100;
    if(this->getAyudaFinanciera()==true)this->Estipendio+=50;
    return;
}
